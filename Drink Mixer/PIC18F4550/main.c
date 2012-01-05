//IN THIS VERSION, I AM USING POINTERS INSTEAD OF highInt, highByte, etc

/************************************************************************
	main.c

    Drink Mixer

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

#define highInt(x) ((x) >> 16)
#define lowInt(x) ((x) & 0xFFFF)
#define highByte(x) ((x) >> 8)
#define lowByte(x) ((x) & 0xFF)
//#define frequencyToPeriod(x) (1048576 / ((unsigned long)(x)))

#define CLOSE 21
#define HALF 14
#define OPEN 7

#define SAMPLES 500

// Global includes
#include <htc.h>

// Local includes
#include "usb.h"
#include "HardwareProfile.h"
#include "usb_function_hid.h"
#include "genericHID.h"

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

//ints are 16 bit, longs are 32 bits
unsigned int interruptCounter = 0;
unsigned int measureDuration = 300;
unsigned int timerCounter = 0;
unsigned int servoThresh = CLOSE;
unsigned int timer2Counter = 0;

int currentCapacitance = 0;
int morePastTimerCounter = 0;
int pastTimerCounter = 0;
int pastCapacitance = 0;
int wantedChange = 31;
int lastChange = 0;

unsigned char capacitanceIndex = 0;

bit dispensing = 0;
bit overflowed = 0;

bit on = 0;

int *sendIntPointer; //Allows me to send ints without converting them to bytes

interrupt isr(void) {
//This interrupt is for calculating the period of the RC circuit
	if (TMR0IF) {
		timerCounter++;
		if (overflowed) {
//			currentCapacitance = (timerCounter+pastTimerCounter+morePastTimerCounter)/3;
//			currentCapacitance /= 2;
//
//			morePastTimerCounter = pastTimerCounter;
//			pastTimerCounter = timerCounter;
			currentCapacitance = timerCounter/2;
			timerCounter = 0;

			interruptCounter = 0;
			overflowed = 0;

			if (dispensing && ((pastCapacitance - currentCapacitance) > wantedChange)) {
				lastChange = pastCapacitance - currentCapacitance;
				servoThresh = CLOSE;
				dispensing = 0;
			}
		}

		TMR0IF = 0;
	} else
//This interrupt controls the servo by changing the PWM duty cycle
	if (TMR2IF) {
		if (timer2Counter < servoThresh) {
			SERVO = ON;
		} else {
			SERVO = OFF;
		}
		timer2Counter++;
		if (timer2Counter == 200)
			timer2Counter = 0;

		TMR2IF = 0;
	} else
//This interrupt is called when the RC circuit goes high. Once it is called 500 times, it signals the TMR0 interrupt to calculate the period
	if (RBIF) {
		if (RB4 == 1) {
			LED1 = on;
			on = !on;
			interruptCounter++;
			overflowed = interruptCounter > SAMPLES;
		}

		RBIF = 0;
	}
}

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
	TRISB = 0b00010000;	//RB4 is an input for the RC circuit
	TRISC = 0b00000000;
	TRISD = 0b00000000;
	TRISE = 0b00000000;

	// Clear all ports
	PORTA = 0b00000000;
	PORTB = 0b00000000;
	PORTC = 0b00000000;
	PORTD = 0b00000000;
	PORTE = 0b00000000;

	//T0PS2:T0PS0 = Timer 0 Prescaler
	T0PS0 = 1;
	T0PS1 = 0;
	T0PS2 = 0;

	//PSA = Timer 0 Prescaler Assignment. 0 for use prescaler, 1 for bypass prescaler
	PSA = 1;

	//T0CS = Timer 0 Clock Source. 0 for internal clock, 1 for external clock on T0CKI
	T0CS = 0;

	//T08BIT = Timer 0 8-Bit. 1 for 8-Bit (Overflows at 256), 0 for 16-Bit (Overflows at 65535)
	T08BIT = 1;

	//TMR0IE = Timer 0 Interrupt Enable. Enable the interrupt to be triggered on overflow
	TMR0IE = 1;

	//TMR0ON = Timer 0 On
	TMR0ON = 1;

	//PR2 = Timer 2 Period. Once the Timer 2 counter reaches this value, it triggers the TMR2IF interrupt
	PR2 = 74;

	//T2CON = Timer2 Configuration bus
	T2CON = 0b00000111;

	//TMR2IE = Timer 2 Interrupt Enable
	TMR2IE = 1;
	
//	//INT0 External Interrupt Enable. 
//	INT0IE = 1;

	//RBIE = Port B Interrupt Enable. Enables interrupt to be triggered when PORTB changes state
	RBIE = 1;

	//PEIE = Peripheral Interrupt Enable. Enables all interrupts from pins?
	PEIE = 1;

	//Global Interrupt Enable. Enables or disables all interrupts
	GIE = 1;

	sendIntPointer = (int*)&ToSendDataBuffer[0];

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
//	LED0 = ON;
    // If we are not in the configured state just return
    if((USBDeviceState < CONFIGURED_STATE)||(USBSuspendControl==1))
    {
	    // We are not configured, set LED1 to off to show status
	    //LED1 = OFF;
	    return;
	}
	
	// We are configured, show state in LED1
	//LED1 = ON;
	
	// Check to see if the success indicator is on and update the delay counter
	if (successIndicatorFlag == TRUE)
	{
		//LED2 = ON;
		successIndicatorCounter++;
		
		if (successIndicatorCounter == 20000)
		{
			//LED2 = OFF;
			successIndicatorCounter = 0;
			successIndicatorFlag = FALSE;
		}
	}
    
    // Check to see if the failure indicator is on and update the delay counter
    if (failureIndicatorFlag == TRUE)
	{
		//LED3 = ON;
		failureIndicatorCounter++;
		
		if (failureIndicatorCounter == 80000)
		{
			//LED3 = OFF;
			failureIndicatorCounter = 0;
			failureIndicatorFlag = FALSE;
		}
	}
	
	// Note: For all tests we expect to receive a 64 byte packet containing
	// the command in byte[0] and then the numbers 0-62 in bytes 1-63.

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
				case 'D':	//Dispense Liquid
					dataReceivedOk = TRUE;
					pastCapacitance = currentCapacitance;
					servoThresh = OPEN;
					dispensing = 1;
					break;

				case 'C':	//Close Servo
					dataReceivedOk = TRUE;
					servoThresh = CLOSE;
					//LED0 = ON;
					break;

				case 'O':	//Open Servo
					dataReceivedOk = TRUE;
					servoThresh = OPEN;
					//LED0 = OFF;
					break;

				case 'H':	//Open Servo Halfway
					dataReceivedOk = TRUE;
					servoThresh = HALF;
					break;

				case 'M':	//Measure Capacitance
					dataReceivedOk = TRUE;
/*
					ToSendDataBuffer[0] = highByte(currentCapacitance);
					ToSendDataBuffer[1] = lowByte(currentCapacitance);
*/

					*sendIntPointer = currentCapacitance;
					
					if (!HIDTxHandleBusy(USBInHandle)) {
						USBInHandle = HIDTxPacket(HID_EP, (BYTE*)&ToSendDataBuffer[0], 64);
					}
					break;

				case 'G':	//Get Last Change in Capacitance
					dataReceivedOk = TRUE;
/*
					ToSendDataBuffer[0] = highByte(lastChange);
					ToSendDataBuffer[1] = lowByte(lastChange);
*/

					*sendIntPointer = lastChange;

					if (!HIDTxHandleBusy(USBInHandle)) {
						USBInHandle = HIDTxPacket(HID_EP, (BYTE*)&ToSendDataBuffer[0], 64);
					}
					break;

				case 'S':	//Start to Measure Change of Capacitance
					dataReceivedOk = TRUE;
					pastCapacitance = currentCapacitance;
					break;

				case 'E':	//End Measure Change of Capacitance
					dataReceivedOk = TRUE;

					int capacitanceChange = pastCapacitance - currentCapacitance;
/*
					ToSendDataBuffer[0] = highByte(capacitanceChange);
					ToSendDataBuffer[1] = lowByte(capacitanceChange);
*/

					*sendIntPointer = capacitanceChange;
					if (!HIDTxHandleBusy(USBInHandle)) {
						USBInHandle = HIDTxPacket(HID_EP, (BYTE*)&ToSendDataBuffer[0], 64);
					}

					wantedChange = capacitanceChange - 1;
					break;

	            case 0x80:  // Test 1 - Single packet write to device
	            	// Test the receieved data
	            	expectedData = 0;
	            	dataReceivedOk = TRUE;
	            	for (bufferPointer = 1; bufferPointer < 64; bufferPointer++)
	            	{
		            	if (ReceivedDataBuffer[bufferPointer] != expectedData)
		            		dataReceivedOk = FALSE;
		            	
		            	expectedData++;
		            }
		            
		            // Display the test result
		            if (dataReceivedOk == TRUE) successIndicatorFlag = TRUE;
		            	else failureIndicatorFlag = TRUE;
	            	break;
	            	
	            case 0x81:	// Test 2 - Single packet read/write
	            	// Test the receieved data
	            	expectedData = 0;
	            	dataReceivedOk = TRUE;
	            	for (bufferPointer = 1; bufferPointer < 64; bufferPointer++)
	            	{
		            	if (ReceivedDataBuffer[bufferPointer] != expectedData)
		            		dataReceivedOk = FALSE;
		            	
		            	expectedData++;
		            }
		            
		            // If we got the data correctly, send the response packet
		            if (dataReceivedOk == TRUE)
		            {
			            expectedData = 0;
			            dataSentOk = TRUE;
			            
			            for (bufferPointer = 0; bufferPointer < 64; bufferPointer++)
			            {
				            ToSendDataBuffer[bufferPointer] = expectedData;
				            expectedData++;
				        }
				        
				        // Transmit the response to the host
		                if(!HIDTxHandleBusy(USBInHandle))
						{
							USBInHandle = HIDTxPacket(HID_EP,(BYTE*)&ToSendDataBuffer[0],64);
						}
						
						// Show our success
						successIndicatorFlag = TRUE;
			        }
			        else failureIndicatorFlag = TRUE;
	            	break;
	            	
	            case 0x82:	// Test 3 - Single packet write, 128 packets read
	                // Test the receieved data
	            	expectedData = 0;
	            	dataReceivedOk = TRUE;
	            	for (bufferPointer = 1; bufferPointer < 64; bufferPointer++)
	            	{
		            	if (ReceivedDataBuffer[bufferPointer] != expectedData)
		            		dataReceivedOk = FALSE;
		            	
		            	expectedData++;
		            }
		            
		            // If the receive was ok, go into bulk sending mode
		            if (dataReceivedOk == TRUE)
		            {
			            // Go into bulk sending mode...
			            bulkSendExpectedPackets = 128;
			            bulkSendFlag = TRUE;
			            bulkSendPacketCounter = 0;
			        }
		            else failureIndicatorFlag = TRUE;
	            	break;
	            	
	            case 0x83:	// Test 4 - 128 packets write, single packet read
	            	// Test the receieved data
	            	expectedData = 0;
	            	dataReceivedOk = TRUE;
	            	for (bufferPointer = 1; bufferPointer < 64; bufferPointer++)
	            	{
		            	if (ReceivedDataBuffer[bufferPointer] != expectedData)
		            		dataReceivedOk = FALSE;
		            	
		            	expectedData++;
		            }
		            
		            // If the receive was ok, go into bulk receiving mode
		            if (dataReceivedOk == TRUE)
		            {
			            // Go into bulk sending mode...
			            bulkReceiveExpectedPackets = 127;
			            bulkReceiveFlag = TRUE;
			            bulkReceivePacketCounter = 0;
			        }
		            else failureIndicatorFlag = TRUE;
	            	break;
	            	
	            case 0x84:	// Test 5 - Single Packet write, timeout on read
	            	// Here we receive a command which expects a reply, but we
	            	// deliberately don't send one to test the timeout mechanisms
	            	// in the communication class
	            	
	            	// Test the receieved data
	            	expectedData = 0;
	            	dataReceivedOk = TRUE;
	            	for (bufferPointer = 1; bufferPointer < 64; bufferPointer++)
	            	{
		            	if (ReceivedDataBuffer[bufferPointer] != expectedData)
		            		dataReceivedOk = FALSE;
		            	
		            	expectedData++;
		            }
		            
		            // Display the test result
		            if (dataReceivedOk == TRUE) successIndicatorFlag = TRUE;
		            	else failureIndicatorFlag = TRUE;
		            	
		            // Now we quit without replying
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

// Main function
void main(void)
{
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
