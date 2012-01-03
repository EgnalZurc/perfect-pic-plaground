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

#define DOING_RISING_EDGE 1

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
bit on;
bit secondPart;
bit savedPart;
bit mightBeDone;
bit actuallyDone;
unsigned char error = 0;
unsigned int code = 0;
volatile unsigned int t1 = 0, pulseWidth=0;
//volatile unsigned int info[36];
volatile unsigned int address = 0,
					unaddress = 0,
					command = 0,
					uncommand = 0;
volatile unsigned char infoIndex = 0;

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

unsigned int *sendIntPointer;

void interrupt iHandler(void) {
	if (CCP1IF) {
		CCP1IF = 0;
		//LED0 = ON;
		
		if (t1 != 0) {
			pulseWidth = (CCPR1H<<8) + CCPR1L - t1;
			if (infoIndex < 10) {
				if (infoIndex > 1) {
					address <<= 1;
					address |= (pulseWidth > 3000);
				}
			} else if (infoIndex < 18) {
				unaddress <<= 1;
				unaddress |= (pulseWidth > 3000);
			} else if (infoIndex < 26) {
				command <<= 1;
				command |= (pulseWidth > 3000);
			} else if (infoIndex < 34) {
				uncommand <<= 1;
				uncommand |= (pulseWidth > 3000);
			}
			infoIndex++;
			if (infoIndex == 36) CCP1IE = 0;
			on = !on;
			LED0 = on;
			CCP1M0 = 1; //Capture next rising edge
			t1 = 0;
			//CCP1IE = 0;
		} else {
			//LED0 = ON;
			CCP1M0 = 0;	//1 is for rising edges, 0 is for falling edges
			t1 = (CCPR1H<<8) + CCPR1L;
		}
	}/* else if (TMR1IF) {
		if (t1 == 0 && mightBeDone) {
			CCP1IE = 0;
			actuallyDone = 1;
		} else if (t1 == 0)
			mightBeDone = 1;
	}*/		
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
	TRISA = 0b00000000;
	TRISB = 0b00000000;
	TRISC = 0b00000100;

	// Clear all ports
	PORTA = 0b00000000;
	PORTB = 0b00000000;
	PORTC = 0b00000000;
	
	
	CCP1M3 = 0;
	CCP1M2 = 1;
	CCP1M1 = 0;
	CCP1M0 = 1;
	
	CCP1IE = 1;
	
	/////////////////////////////
	//Timer1 configuration (CCP module uses Timer1 in Capture Mode)
	/////////////////////////////
	
	//T1CKPS1:T1CKPS0 = Timer 1 Prescaler
	T1CKPS1 = 1;
	T1CKPS0 = 0;

	//TMR1IE = Timer 1 Interrupt Enable. Enable the interrupt to be triggered on overflow
	//TMR1IE = 1;

	//T1RD16 = Use 16-Bit assignment for Timer1 (Still not entirely sure what this means...)
	T1RD16 = 1;

	//T1RUN: 1 = Use Timer1 Oscillator as clock, 0 = Don't (Unsure if the Timer1 Oscillator means the external oscillator or works with internal...)
	T1RUN = 1;

	//T1OCEN = Enable/Disable Timer1 Oscillator
	T1OSCEN = 0;

	//TMR1CS = Timer1 Clock Source. 0 for internal (Fosc/4), 1 for external
	TMR1CS = 0;

	//TMR1ON = Turn Timer1 On
	TMR1ON = 1;
	
	PEIE = 1;

	GIE = 1;
	
	sendIntPointer = (unsigned int*)&ToSendDataBuffer[0];
	
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
	    LED1 = OFF;
	    return;
	}
	
	// We are configured, show state in LED1
	//LED1 = ON;
	
	// Check to see if the success indicator is on and update the delay counter
	if (successIndicatorFlag == TRUE)
	{
		LED2 = ON;
		successIndicatorCounter++;
		
		if (successIndicatorCounter == 20000)
		{
			LED2 = OFF;
			successIndicatorCounter = 0;
			successIndicatorFlag = FALSE;
		}
	}
    
    // Check to see if the failure indicator is on and update the delay counter
    if (failureIndicatorFlag == TRUE)
	{
		LED3 = ON;
		failureIndicatorCounter++;
		
		if (failureIndicatorCounter == 80000)
		{
			LED3 = OFF;
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
				case 0x02: //Toggle LED
					on = !on;
					LED0 = on;
					break;
					
				case 0x05: //Toggle LED and send back data
					on = !on;
					LED0 = on;
						
		            expectedData = 0;
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
	            	break;
					
				case 'T': //Toggle LED and send back data
					//if (!actuallyDone) break;
					if (infoIndex < 36)
						ToSendDataBuffer[0] = ToSendDataBuffer[1] = ToSendDataBuffer[2] = ToSendDataBuffer[3] = 0;
					else {
						ToSendDataBuffer[0] = address;
						ToSendDataBuffer[1] = unaddress;
						ToSendDataBuffer[2] = command;
						ToSendDataBuffer[3] = uncommand;
	//					for (int i=0;i<36;i++) {
	//						if (info[i] < 1700)
	//							ToSendDataBuffer[i] = 0;
	//						else if (info[i] > 3000)
	//							ToSendDataBuffer[i] = 1;		
	//						//*(sendIntPointer+i) = info[i];
	//					}
						
						//*(sendIntPointer + 30) = infoIndex;
						CCP1IE = 1;
						infoIndex = 0;
						address = unaddress = command = uncommand = 0;
					}	
				 
			        // Transmit the response to the host
	                if(!HIDTxHandleBusy(USBInHandle))
					{
						USBInHandle = HIDTxPacket(HID_EP,(BYTE*)&ToSendDataBuffer[0],64);
					}
	            	break;
	            	
	            case 'R':
	            	t1 = 0;
	            	pulseWidth = 0;
	            	CCP1M0 = 1;
	            	CCP1IF = 0;
	            	CCP1IE = 1;
	            	break;

//	            case 0x80:  // Test 1 - Single packet write to device
//	            	// Test the receieved data
//	            	expectedData = 0;
//	            	dataReceivedOk = TRUE;
//	            	for (bufferPointer = 1; bufferPointer < 64; bufferPointer++)
//	            	{
//		            	if (ReceivedDataBuffer[bufferPointer] != expectedData)
//		            		dataReceivedOk = FALSE;
//		            	
//		            	expectedData++;
//		            }
//		            
//		            // Display the test result
//		            if (dataReceivedOk == TRUE) successIndicatorFlag = TRUE;
//		            	else failureIndicatorFlag = TRUE;
//	            	break;
//	            	
//	            case 0x81:	// Test 2 - Single packet read/write
//	            	// Test the receieved data
//	            	expectedData = 0;
//	            	dataReceivedOk = TRUE;
//	            	for (bufferPointer = 1; bufferPointer < 64; bufferPointer++)
//	            	{
//		            	if (ReceivedDataBuffer[bufferPointer] != expectedData)
//		            		dataReceivedOk = FALSE;
//		            	
//		            	expectedData++;
//		            }
//		            
//		            // If we got the data correctly, send the response packet
//		            if (dataReceivedOk == TRUE)
//		            {
//			            expectedData = 0;
//			            dataSentOk = TRUE;
//			            
//			            for (bufferPointer = 0; bufferPointer < 64; bufferPointer++)
//			            {
//				            ToSendDataBuffer[bufferPointer] = expectedData;
//				            expectedData++;
//				        }
//				        
//				        // Transmit the response to the host
//		                if(!HIDTxHandleBusy(USBInHandle))
//						{
//							USBInHandle = HIDTxPacket(HID_EP,(BYTE*)&ToSendDataBuffer[0],64);
//						}
//						
//						// Show our success
//						successIndicatorFlag = TRUE;
//			        }
//			        else failureIndicatorFlag = TRUE;
//	            	break;
//	            	
//	            case 0x82:	// Test 3 - Single packet write, 128 packets read
//	                // Test the receieved data
//	            	expectedData = 0;
//	            	dataReceivedOk = TRUE;
//	            	for (bufferPointer = 1; bufferPointer < 64; bufferPointer++)
//	            	{
//		            	if (ReceivedDataBuffer[bufferPointer] != expectedData)
//		            		dataReceivedOk = FALSE;
//		            	
//		            	expectedData++;
//		            }
//		            
//		            // If the receive was ok, go into bulk sending mode
//		            if (dataReceivedOk == TRUE)
//		            {
//			            // Go into bulk sending mode...
//			            bulkSendExpectedPackets = 128;
//			            bulkSendFlag = TRUE;
//			            bulkSendPacketCounter = 0;
//			        }
//		            else failureIndicatorFlag = TRUE;
//	            	break;
//	            	
//	            case 0x83:	// Test 4 - 128 packets write, single packet read
//	            	// Test the receieved data
//	            	expectedData = 0;
//	            	dataReceivedOk = TRUE;
//	            	for (bufferPointer = 1; bufferPointer < 64; bufferPointer++)
//	            	{
//		            	if (ReceivedDataBuffer[bufferPointer] != expectedData)
//		            		dataReceivedOk = FALSE;
//		            	
//		            	expectedData++;
//		            }
//		            
//		            // If the receive was ok, go into bulk receiving mode
//		            if (dataReceivedOk == TRUE)
//		            {
//			            // Go into bulk sending mode...
//			            bulkReceiveExpectedPackets = 127;
//			            bulkReceiveFlag = TRUE;
//			            bulkReceivePacketCounter = 0;
//			        }
//		            else failureIndicatorFlag = TRUE;
//	            	break;
//	            	
//	            case 0x84:	// Test 5 - Single Packet write, timeout on read
//	            	// Here we receive a command which expects a reply, but we
//	            	// deliberately don't send one to test the timeout mechanisms
//	            	// in the communication class
//	            	
//	            	// Test the receieved data
//	            	expectedData = 0;
//	            	dataReceivedOk = TRUE;
//	            	for (bufferPointer = 1; bufferPointer < 64; bufferPointer++)
//	            	{
//		            	if (ReceivedDataBuffer[bufferPointer] != expectedData)
//		            		dataReceivedOk = FALSE;
//		            	
//		            	expectedData++;
//		            }
//		            
//		            // Display the test result
//		            if (dataReceivedOk == TRUE) successIndicatorFlag = TRUE;
//		            	else failureIndicatorFlag = TRUE;
//		            	
//		            // Now we quit without replying
//	            	break;
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
	LED0 = OFF;
	on = 0;
	
//	for (int i=0;i<8;i++) {
//		info[i] = 0;
//	}	

    while(1)
    {
		// Check bus status and service USB interrupts.
        USBDeviceTasks();

		// Application-specific tasks.
        ProcessIO();        
    }
}

#endif
