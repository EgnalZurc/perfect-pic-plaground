/************************************************************************
	main.c

    usbGenericHidCommunication reference firmware 1_0_0_0
    Copyright (C) 2010 Simon Inns

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	Email: simon.inns@gmail.com

************************************************************************/

#ifndef MAIN_C
#define MAIN_C

// Global includes
#include <htc.h>

// Local includes
#include "usb.h"
#include "HardwareProfile.h"
#include "usb_function_hid.h"
#include "genericHID.h"

#define BRIGHTNESS_LEVELS 80

// PIC 18F4550 fuse configuration:
// Config word 1 (Oscillator configuration)
// 20Mhz crystal input scaled to 48Mhz and configured for USB operation
__CONFIG(1, USBPLL & IESODIS & FCMDIS & HSPLL & CPUDIV1 & PLLDIV5);
// Config word 2
__CONFIG(2, VREGEN & PWRTDIS & BOREN & BORV20 & WDTDIS & WDTPS32K);
// Config word 3
__CONFIG(3, PBDIGITAL & LPT1DIS & MCLREN);
// Config word 4
__CONFIG(4, XINSTDIS & STVREN & LVPDIS & ICPORTDIS & DEBUGDIS);
// Config word 5, 6 and 7 (protection configuration)
__CONFIG(5, UNPROTECT);
__CONFIG(6, UNPROTECT);
__CONFIG(7, UNPROTECT);

// Globals
unsigned char pwmCounter = 0;
int redActual, redTarget, redFade, greenActual, greenTarget, greenFade, blueActual, blueTarget, blueFade;
unsigned char redNext, greenNext, blueNext;
unsigned char redSet, blueSet, greenSet;
unsigned char fade = 0;
signed char decayRate = 2;
signed char fadeThresh = 100;
signed char brightnessThresh = 100;
unsigned char colorFade = 0;
unsigned char brightnessFade = 0;
unsigned char beat = 0;
unsigned char autoColor = 1;

signed char baseColors[3] = { 0, BRIGHTNESS_LEVELS, 0 }; //green, red, blue
unsigned char changingIndex = 0;
unsigned char up = 1;
unsigned char limit = 0;
signed char brightness = BRIGHTNESS_LEVELS;
unsigned char time = 0;

// Success indication globals (used to keep the success LED on so you can see it)
long int successIndicatorCounter = 0;
unsigned char successIndicatorFlag = FALSE;

// Failure indication globals (used to keep the failure LED on so you can see it)
long int failureIndicatorCounter = 0;
unsigned char failureIndicatorFlag = FALSE;

// Variables required for keeping track of a bulk receive command
unsigned char bulkReceiveFlag = FALSE;
int bulkReceivePacketCounter = 0;
int bulkReceiveExpectedPackets = 0;

// Variables required for keeping track of a bulk send command
unsigned char bulkSendFlag = FALSE;
int bulkSendPacketCounter = 0;
int bulkSendExpectedPackets = 0;

// Initialise system
static void InitialiseSystem(void)
{
	// PIC port set up --------------------------------------------------------

	// Default all pins to digital
    ADCON1 = 0x0F;

	// Note: To complile this code for the PIC18F2550 remove the TRISD, TRISE,
	// PORTD and PORTE commands below.  Then edit HardwareProfile.h to match
	// your target device (only the LED ports are really important).

	// Configure ports as inputs (1) or outputs(0)
	TRISA = 0b00000010;
	TRISB = 0b00000000;
	TRISC = 0b00000000;
	TRISD = 0b00000000;
	TRISE = 0b00000000;

	// Clear all ports
	PORTA = 0b00000000;
	PORTB = 0b00000000;
	PORTC = 0b00000000;
	PORTD = 0b00000000;
	PORTE = 0b00000000;

	IPEN = 1;

	TMR0IP = 0;
	TMR0IF = 0;

	//Sets when the timer will overflow
	TMR0L = 255 - 187;
	
	T0CON = 0b11000011;

	//Start the timer
	TMR0IE = 1;

	//Enable all high and low priority interrupts
	GIEH = 1;
	GIEL = 1;

	// USB set up -------------------------------------------------------------

	// USB stack and parameter initialisation
    #if defined(USE_SELF_POWER_SENSE_IO)
    tris_self_power = INPUT_PIN;
    #endif
    
    // Initialize the variable holding the handle for the last
    // transmission
    USBOutHandle = 0;
    USBInHandle = 0;
    
	// Call the stack initialisation functions
    USBDeviceInit();
}

// Process input and output
void ProcessIO(void)
{   
    // If we are not in the configured state just return
    if((USBDeviceState < CONFIGURED_STATE)||(USBSuspendControl==1))
    {
	    // We are not configured, set LED1 to off to show status
	    //LED1 = ON;
	    return;
	}
	
	// Note: For all tests we expect to receive a 64 byte packet containing
	// the command in byte[0] and then the numbers 0-62 in bytes 1-63.

	//LED0 = ON;

	unsigned char bufferPointer;
    unsigned char expectedData;
    unsigned char dataReceivedOk;
    unsigned char dataSentOk;

	// Check if data was received from the host.
    if(!HIDRxHandleBusy(USBOutHandle))
    {   
	    // Test to see if we are in bulk send/receieve mode, or if we are waiting for a command
	    if (bulkSendFlag == TRUE || bulkReceiveFlag == TRUE)
	    {
		    // We are either bulk sending or receieving
		    
		    // If we are bulk sending, check that we are not busy and send the next packet
		    if (bulkSendFlag == TRUE && !HIDTxHandleBusy(USBInHandle))
		    {
				// Send the next packet
				expectedData = bulkSendPacketCounter;
	            
	            for (bufferPointer = 0; bufferPointer < 64; bufferPointer++)
	            {
		            	ToSendDataBuffer[bufferPointer] = expectedData;
		        }
		        
		        // Transmit the response to the host
                USBInHandle = HIDTxPacket(HID_EP,(BYTE*)&ToSendDataBuffer[0],64);
                
                // Add this following delay in if you want to simulate a slow transfer
                // from a busy PIC when testing bulk sends:
                
                // for (long int counter = 0; counter < 1000; counter++) __delay_us(100); 
				
				bulkSendPacketCounter++; // Next packet
				
				// Are we done yet?
				if (bulkSendPacketCounter == bulkSendExpectedPackets)
				{
					// All done, indicate success and go back to command mode
					bulkSendFlag = FALSE;
					successIndicatorFlag = TRUE;
				}	
			}
			
			// If we are bulk receiving get the next packet
			if (bulkReceiveFlag == TRUE)
			{
				// The received data buffer is already filled by the USB stack
				// we just have to confirm the data integrity
				
				expectedData = bulkReceivePacketCounter;
				
				for (bufferPointer = 0; bufferPointer < 64; bufferPointer++)
				{
					// If the data isn't what we expected, turn on the failure light
					if (ReceivedDataBuffer[bufferPointer] != expectedData)
						failureIndicatorFlag = TRUE;
				}
				
				bulkReceivePacketCounter++;
				
				// Are we done yet?
				if (bulkReceivePacketCounter == bulkReceiveExpectedPackets)
				{
					// All done, indicate success and go back to command mode
					bulkReceiveFlag = FALSE;
					successIndicatorFlag = TRUE;
				}
			}
		}
		else
		{
			// Command mode    
	        switch(ReceivedDataBuffer[0])
			{
				case 0x01:
					if (autoColor) {
/*
						redActual = redNext;
						greenActual = greenNext;
						blueActual = blueNext;
*/
						brightness = 50;
						//redActual = greenActual = blueActual = 50;
					} else {
						redActual = redSet;
						greenActual = greenSet;
						blueActual = blueSet;
					}

					redTarget = 0;
					greenTarget = 0;
					blueTarget = 0;
					break;
				case 0x02:
					redActual = ReceivedDataBuffer[1];
					greenActual = ReceivedDataBuffer[2];
					blueActual = ReceivedDataBuffer[3];
					break;
				case 'S'://Settings Change
					brightnessThresh = ReceivedDataBuffer[1];
					fadeThresh = ReceivedDataBuffer[2];
					break;
	            case 0x04:
					autoColor = !autoColor;
					break;
				case 'O':
					LED1 = ON;
					break;
				case 'U':
					decayRate++;
					if (decayRate > 10)
						decayRate = 10;
					break;
				case 'D':
					decayRate--;
					if (decayRate < 0)
						decayRate = 0;
					break;
				case 'F':
					fadeThresh += 5;
					if (fadeThresh > 300)
						fadeThresh = 300;
					break;
				case 'f':
					fadeThresh -= 5;
					if (fadeThresh < 30)
						fadeThresh = 30;
					break;
	            default:	// Unknown command received
	           		break;
			}
		}
		
		// Only rearm the OUT endpoint if we are not bulk sending
		if (bulkSendFlag == FALSE)
		{      
	        // Re-arm the OUT endpoint for the next packet
	        USBOutHandle = HIDRxPacket(HID_EP,(BYTE*)&ReceivedDataBuffer,64);
  		}      
    }  
}

//colorActual is what the pwm duty cycle actually is, colorTarget is what it will fade to.
//Fade speed is determined by decayRate; the smaller decayRate is, the faster the fade

void interrupt low_priority lpHandler(void) {
	if (TMR0IF == 1) {
		colorFade++;
		brightnessFade++;
		
//		if (colorFade == 200) {
//			if (redTarget > redActual)
//				redActual++;
//			else if (redTarget < redActual) {
//				redActual--;
//			}
//
//			if (greenTarget > greenActual)
//				greenActual++;
//			else if (greenTarget < greenActual) {
//				greenActual--;
//			}
//
//			if (blueTarget > blueActual)
//				blueActual++;
//			else if (blueTarget < blueActual) {
//				blueActual--;
//			}
//		}

//Cycle through colors instead of staying on one.
		
		if (autoColor == 1) {
			if (brightnessFade == brightnessThresh) {
				brightness = (brightness>0) ? (brightness-1) : 0;

				redActual = (baseColors[1] * brightness) / BRIGHTNESS_LEVELS;
				greenActual = (baseColors[0] * brightness) / BRIGHTNESS_LEVELS;
				blueActual = (baseColors[2] * brightness) / BRIGHTNESS_LEVELS;

				brightnessFade = 0;
			}

			if (colorFade == fadeThresh) {
				if (limit) {
					changingIndex = (changingIndex+1)%3;
					up = 1 - up;
					limit = 0;
				}

				if (up) {
					baseColors[changingIndex]++;
					if (baseColors[changingIndex] > BRIGHTNESS_LEVELS)
						limit = 1;
				} else {
					baseColors[changingIndex]--;
					if (baseColors[changingIndex] < 0)
						limit = 1;
				}

				redActual = (baseColors[1] * brightness) / BRIGHTNESS_LEVELS;
				greenActual = (baseColors[0] * brightness) / BRIGHTNESS_LEVELS;
				blueActual = (baseColors[2] * brightness) / BRIGHTNESS_LEVELS;

				colorFade = 0;
			}
		}

		//redActual/BRIGHTNESS_LEVLS is the fraction of the time each color is on
		if (redActual > pwmCounter) {
			RED = ON;
		} else {
			RED = OFF;
		}

		if (greenActual > pwmCounter) {
			GREEN = ON;
		} else {
			GREEN = OFF;
		}

		if (blueActual > pwmCounter) {
			BLUE = ON;
		} else {
			BLUE = OFF;
		}

		pwmCounter++;
		if (pwmCounter > BRIGHTNESS_LEVELS) {
			pwmCounter = 0;
		}

		//Reset the timer interrupt		
		//TMR0L = 255 - 187;
		TMR0L = 255-100;
		TMR0IF = 0;
	}
}

// Main function
void main(void)
{
	LED0 = ON;
    InitialiseSystem();

	// We are up and running, show 'ready' status in LED0
	LED0 = ON;

    while(1)
    {
		// Check bus status and service USB interrupts.
        USBDeviceTasks();

		// Application-specific tasks.
        ProcessIO();        
    }
}

#endif
