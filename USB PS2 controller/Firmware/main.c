/********************************************************************
 FileName:		main.c
 Dependencies:	See INCLUDES section
 Processor:		PIC18, PIC24, and PIC32 USB Microcontrollers
 Hardware:		This demo is natively intended to be used on Microchip USB demo
 				boards supported by the MCHPFSUSB stack.  See release notes for
 				support matrix.  This demo can be modified for use on other hardware
 				platforms.
 Complier:  	Microchip C18 (for PIC18), C30 (for PIC24), C32 (for PIC32)
 Company:		Microchip Technology, Inc.

 Software License Agreement:

 The software supplied herewith by Microchip Technology Incorporated
 (the “Company”) for its PIC® Microcontroller is intended and
 supplied to you, the Company’s customer, for use solely and
 exclusively on Microchip PIC Microcontroller products. The
 software is owned by the Company and/or its supplier, and is
 protected under applicable copyright laws. All rights are reserved.
 Any use in violation of the foregoing restrictions may subject the
 user to criminal sanctions under applicable laws, as well as to
 civil liability for the breach of the terms and conditions of this
 license.

 THIS SOFTWARE IS PROVIDED IN AN “AS IS” CONDITION. NO WARRANTIES,
 WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.

********************************************************************
********************************************************************/

#ifndef JOYSTICKMAIN_C
#define JOYSTICKMAIN_C

/** INCLUDES *******************************************************/
#include "./USB/usb.h"
#include "HardwareProfile.h"
#include "./USB/usb_function_hid.h"

// load macros and functions for 18 family
#include <p18cxxx.h>
// load macros and functions specific to 2550
#include <p18f2550.h>
#include <delays.h>
//#include "sw_uart.h"
#include <spi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** CONFIGURATION **************************************************/
#if defined(TOOTHPIC_FS_USB)      // Configuration bits for PICDEM FS USB Demo Board (based on PIC18F2550)
        #pragma config PLLDIV   = 4         // (16 MHz crystal on PICDEM FS USB board)
        #pragma config CPUDIV   = OSC4_PLL6   
        #pragma config USBDIV   = 2         // Clock source from 96MHz PLL/2
        #pragma config FOSC     = HSPLL_HS
        #pragma config FCMEN    = OFF
        #pragma config IESO     = OFF
        #pragma config PWRT     = OFF
        #pragma config BOR      = ON
        #pragma config BORV     = 3
        #pragma config VREGEN   = ON      //USB Voltage Regulator
        #pragma config WDT      = OFF
        #pragma config WDTPS    = 32768
        #pragma config MCLRE    = ON
        #pragma config LPT1OSC  = OFF
        #pragma config PBADEN   = OFF
        #pragma config STVREN   = ON
        #pragma config LVP      = OFF
        #pragma config XINST    = OFF       // Extended Instruction Set
        #pragma config CP0      = OFF
        #pragma config CP1      = OFF
        #pragma config CPB      = OFF
        #pragma config WRT0     = OFF
        #pragma config WRT1     = OFF
        #pragma config WRTB     = OFF       // Boot Block Write Protection
        #pragma config WRTC     = OFF
        #pragma config EBTR0    = OFF
        #pragma config EBTR1    = OFF
        #pragma config EBTRB    = OFF

#else
    #error No hardware board defined, see "HardwareProfile.h" and __FILE__
#endif

/** PRIVATE PROTOTYPES *********************************************/
void BlinkUSBStatus(void);
BOOL Switch2IsPressed(void);
BOOL Switch3IsPressed(void);
static void InitializeSystem(void);
void ProcessIO(void);
void UserInit(void);
void YourHighPriorityISRCode();
void YourLowPriorityISRCode();
void USBCBSendResume(void);
void Joystick(void);

void print_ascii( unsigned char);
void print_ascii_r(unsigned char t, unsigned char t2);
void read_spi_to_buf(char*, unsigned char);
void write_buf_to_usart(char*, unsigned char);
void continuously_read_spi_and_dump_to_usart(void);
void send_commands_to_controller(void);
void print_buffer(void);
// send and receive a byte from the controller via SPI
void ps2_txrx(unsigned char data_out,unsigned char *reg_in);

/** DECLARATIONS ***************************************************/


// this is a macro shortcut (this code will replace bitrev(c) at compile time)
// for reversing the bit order
#define bitrev(c)	c = (c & 0x0F) << 4 | (c & 0xF0) >> 4; \
					c = (c & 0x33) << 2 | (c & 0xCC) >> 2; \
					c = (c & 0x55) << 1 | (c & 0xAA) >> 1;

//http://www.microsoft.com/whdc/archive/hidgame.mspx
#define HAT_SWITCH_NORTH            0x0
#define HAT_SWITCH_NORTH_EAST       0x1
#define HAT_SWITCH_EAST             0x2
#define HAT_SWITCH_SOUTH_EAST       0x3
#define HAT_SWITCH_SOUTH            0x4
#define HAT_SWITCH_SOUTH_WEST       0x5
#define HAT_SWITCH_WEST             0x6
#define HAT_SWITCH_NORTH_WEST       0x7
#define HAT_SWITCH_NULL             0x8

typedef union _INTPUT_CONTROLS_TYPEDEF
{
    struct
    {
        struct
        {
            BYTE square:1;
            BYTE x:1;
            BYTE o:1;
            BYTE triangle:1;
            BYTE L1:1;
            BYTE R1:1;
            BYTE L2:1;
            BYTE R2:1;//
            BYTE select:1;
            BYTE start:1;
            BYTE left_stick:1;
            BYTE right_stick:1;
            BYTE home:1;
            BYTE :3;    //filler
        } buttons;
        struct
        {
            BYTE hat_switch:4;
            BYTE :4;//filler
        } hat_switch;
        struct
        {
            BYTE X;
            BYTE Y;
            BYTE Z;
            BYTE Rz;
        } analog_stick;
    } members;
    BYTE val[7];
} INPUT_CONTROLS;

/** VARIABLES ******************************************************/
#pragma udata
BYTE old_sw2,old_sw3;
char buffer[8];
USB_HANDLE lastTransmission;
BOOL Keyboard_out;

#if defined(__18F14K50) || defined(__18F13K50) || defined(__18LF14K50) || defined(__18LF13K50) 
    #pragma udata usbram2
#elif defined(__18F2455) || defined(__18F2550) || defined(__18F4455) || defined(__18F4550)\
    || defined(__18F2458) || defined(__18F2453) || defined(__18F4558) || defined(__18F4553)
    #pragma udata USB_VARIABLES=0x500
#elif defined(__18F4450) || defined(__18F2450)
    #pragma udata USB_VARIABLES=0x480
#else
    #pragma udata
#endif
INPUT_CONTROLS joystick_input;
BYTE hid_report[8];
#pragma udata

//------------ Global Variables ------------------------------- //

int read_buf_index =0;
unsigned char print_buf[80];
unsigned char print_buf_index = 0;

uint8 PS2_ID, MSG;
uint8 PS2_byte1, PS2_byte2, PS2_byte3, PS2_byte4, PS2_byte5, PS2_byte6;
uint8 PS2_prev_byte1, PS2_prev_byte2, PS2_prev_byte3, PS2_prev_byte4, PS2_prev_byte5, PS2_prev_byte6;
unsigned char PS2_pressure[12];


/** VECTOR REMAPPING ***********************************************/
#if defined(__18CXX)
	//On PIC18 devices, addresses 0x00, 0x08, and 0x18 are used for
	//the reset, high priority interrupt, and low priority interrupt
	//vectors.  However, the current Microchip USB bootloader 
	//examples are intended to occupy addresses 0x00-0x7FF or
	//0x00-0xFFF depending on which bootloader is used.  Therefore,
	//the bootloader code remaps these vectors to new locations
	//as indicated below.  This remapping is only necessary if you
	//wish to program the hex file generated from this project with
	//the USB bootloader.  If no bootloader is used, edit the
	//usb_config.h file and comment out the following defines:
	//#define PROGRAMMABLE_WITH_USB_HID_BOOTLOADER
	//#define PROGRAMMABLE_WITH_USB_LEGACY_CUSTOM_CLASS_BOOTLOADER
	
	#if defined(PROGRAMMABLE_WITH_USB_HID_BOOTLOADER)
		#define REMAPPED_RESET_VECTOR_ADDRESS			0x1000
		#define REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS	0x1008
		#define REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS	0x1018
	#elif defined(PROGRAMMABLE_WITH_USB_MCHPUSB_BOOTLOADER)	
		#define REMAPPED_RESET_VECTOR_ADDRESS			0x800
		#define REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS	0x808
		#define REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS	0x818
	#else	
		#define REMAPPED_RESET_VECTOR_ADDRESS			0x00
		#define REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS	0x08
		#define REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS	0x18
	#endif
	
	#pragma code REMAPPED_HIGH_INTERRUPT_VECTOR = REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS
	void Remapped_High_ISR (void)
	{
	     _asm goto YourHighPriorityISRCode _endasm
	}
	#pragma code REMAPPED_LOW_INTERRUPT_VECTOR = REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS
	void Remapped_Low_ISR (void)
	{
	     _asm goto YourLowPriorityISRCode _endasm
	}
	
	#pragma code
	
	
	//These are your actual interrupt handling routines.
	#pragma interrupt YourHighPriorityISRCode
	void YourHighPriorityISRCode()
	{
		//Check which interrupt flag caused the interrupt.
		//Service the interrupt
		//Clear the interrupt flag
		//Etc.
        #if defined(USB_INTERRUPT)
	        USBDeviceTasks();
        #endif
	
	}	//This return will be a "retfie fast", since this is in a #pragma interrupt section 
	#pragma interruptlow YourLowPriorityISRCode
	void YourLowPriorityISRCode()
	{
		//Check which interrupt flag caused the interrupt.
		//Service the interrupt
		//Clear the interrupt flag
		//Etc.
	
	}	//This return will be a "retfie", since this is in a #pragma interruptlow section 
#endif

#pragma code


// ---------------  utility functions ---------------- //

void ps2_txrx(unsigned char data_out,unsigned char *reg_in){
	char send = data_out;
        char ssp = 0;
	bitrev(data_out);
	SSPBUF = data_out;
	while(!SSPSTATbits.BF);
        ssp = SSPBUF;
	*reg_in = ssp;
	bitrev(*reg_in);
	print_ascii_r(send, *reg_in);
}


void print_ascii_r(unsigned char t, unsigned char t2) {
	// there's not enough time to send out serial RS-232 back to the computer
	// in between every byte, so output is stored in a buffer until the end
	// of a packet.
	print_buf[2*print_buf_index] = t;
	print_buf[2*print_buf_index+1] = t2;
	if (print_buf_index < 38)
		print_buf_index++;
}

void print_buffer() {
	char t = 0;
	print_buf_index = print_buf_index *2;
	while (t<print_buf_index) {
		print_ascii(print_buf[t++]);
		//print_ascii(0x7A);
		WriteUART('_');
		print_ascii(print_buf[t++]);
		WriteUART(0x20);
	}
	print_buf_index = 0;
}

void print_ascii( unsigned char t) {
	char buf[20];
	sprintf((char *)buf, "%02X", t); // the (char *) is there to suppress a type error having to do with the (near / small pointer) memory model used in the compiler...
	putsUART(buf);
}

void headerPS2(unsigned char command) {
    ps2_txrx(0x01, &PS2_ID.byte);
    ps2_txrx(command, &PS2_ID.byte);
    ps2_txrx(0x00, &MSG.byte);
}

void initPS2(void) {
    unsigned char response;
    char buf[20];
    char t;

    //LATAbits.LATA0 = 1;
    // 0x42: general purpose poll and command for vibration motors, number of bytes depends on configuration
    pin_ATT = 0;					// pull ATT low to signal gamepad
    headerPS2(0x42);
    ps2_txrx(0x00, &PS2_byte1.byte);			// receive:	1st byte of button states
    ps2_txrx(0x00, &PS2_byte2.byte);			// receive:	2nd byte of button states
    ps2_txrx(0x00, &PS2_byte3.byte);			// receive:	3rd byte of button states
    ps2_txrx(0x00, &PS2_byte4.byte);			// receive:	4th byte of button states
    ps2_txrx(0x00, &PS2_byte5.byte);			// receive:	5th byte of button states
    ps2_txrx(0x00, &PS2_byte6.byte);			// receive:	6th byte of button states
    pin_ATT = 1; // reset the ATTention line... can't just leave it low
    Delay100TCYx(255); // not sure how much delay is necessary after each packet, but it seems to work inconsistently without these
    WriteUART(0x30);
    WriteUART(0x0A);
    WriteUART(0x0D);

    //LATAbits.LATA0 = 0;
    // 0x43: go in 'escape mode' or 'config mode'
    //01/ff 43/41 00/5a | 01/ff 00/ff
    pin_ATT = 0;
    headerPS2(0x43);
    ps2_txrx(0x01,&PS2_byte1.byte);
    ps2_txrx(0x00,&PS2_byte2.byte);
    pin_ATT = 1;
    Delay100TCYx(255);
    WriteUART(0x31);
    WriteUART(0x0A);
    WriteUART(0x0D);

    // turn dual shock mode, or 'analog' mode on
    //	01/ff 44/f3 00/5a | 01/00 03/00 00/00 00/00 00/00 00/00
    //LATAbits.LATA0 = 1;
    pin_ATT = 0;
    headerPS2(0x44);
    ps2_txrx(0x01,&PS2_byte1.byte);
    ps2_txrx(0x03,&PS2_byte2.byte);
    ps2_txrx(0x00,&PS2_byte3.byte);
    ps2_txrx(0x00,&PS2_byte4.byte);
    ps2_txrx(0x00,&PS2_byte5.byte);
    ps2_txrx(0x00,&PS2_byte6.byte);
    pin_ATT = 1;
    Delay100TCYx(255); // this delay was necessary for a Sony brand controller... delays may be necessary after
    // other commands, also,... not sure.
    WriteUART(0x32);
    WriteUART(0x0A);
    WriteUART(0x0D);


    // setup motor mapping
    // 01/ff 4d/f3 00/5a | 00/00 01/01 ff/ff ff/ff ff/ff ff/ff
    //LATAbits.LATA0 = 0;
    pin_ATT = 0;
    headerPS2(0x4d);
    ps2_txrx(0x00,&PS2_byte1.byte); // whichever command byte has 00 will be the stop in the 0x42 poll cammand that triggers the smaller motor
    ps2_txrx(0x01,&PS2_byte2.byte);	// applied to larger motor, which can be controlled with an 8 bit speed. smaller motor is just 0xFF for on, otherwise off.
    ps2_txrx(0xff,&PS2_byte3.byte);
    ps2_txrx(0xff,&PS2_byte4.byte);
    ps2_txrx(0xff,&PS2_byte5.byte);
    ps2_txrx(0xff,&PS2_byte6.byte);
    pin_ATT = 1;
    WriteUART(0x33);
    WriteUART(0x0A);
    WriteUART(0x0D);


    // request pressure sensing data
    // 01/ff 4f/f3 00/5a | ff/00 ff/00 03/00 00/00 00/00 00/5a
    //LATAbits.LATA0 = 1;
    pin_ATT = 0;
    headerPS2(0x4f);
    ps2_txrx(0xff,&PS2_byte1.byte);
    ps2_txrx(0xff,&PS2_byte2.byte);
    ps2_txrx(0x03,&PS2_byte3.byte);
    ps2_txrx(0x00,&PS2_byte4.byte);
    ps2_txrx(0x00,&PS2_byte5.byte);
    ps2_txrx(0x00,&PS2_byte6.byte);
    pin_ATT = 1;
    Delay100TCYx(255); // requires large delay here? maybe
    WriteUART(0x34);
    WriteUART(0x0A);
    WriteUART(0x0D);


    // 0x41 get a bit map that shows which buttons are being returned in 0x42 calls.
    //LATAbits.LATA0 = 0;
    pin_ATT = 0;					// pull ATT low to signal gamepad
    headerPS2(0x41);
    ps2_txrx(0x00, &PS2_byte1.byte);			// receive:	1st byte of button states
    ps2_txrx(0x00, &PS2_byte2.byte);			// receive:	2nd byte of button states
    ps2_txrx(0x00, &PS2_byte3.byte);			// receive:	3rd byte of button states
    ps2_txrx(0x00, &PS2_byte4.byte);			// receive:	4th byte of button states
    ps2_txrx(0x00, &PS2_byte5.byte);			// receive:	5th byte of button states
    ps2_txrx(0x00, &PS2_byte6.byte);			// receive:	6th byte of button states
    pin_ATT = 1;
    Delay100TCYx(255);
    WriteUART(0x35);
    WriteUART(0x0A);
    WriteUART(0x0D);



    // exit escape mode 2nd method by lynxmotion: "CONFIG_MODE_EXIT_DS2_NATIVE" ... using only the first 2 bytes with 0's doesn't work on China knockoffs
    //CMD=01,43,00,00,5A (5A,5A,5A,5A)
    // on the guitar hero controller, the 5A's seemed to be necessary (as oppsed to 0x00's).  not lots of testing on this
    //LATAbits.LATA0 = 1;
    pin_ATT = 0;
    headerPS2(0x43);
    ps2_txrx(0x00,&PS2_byte1.byte);
    ps2_txrx(0x5A,&PS2_byte2.byte);
    ps2_txrx(0x5A,&PS2_byte3.byte);
    ps2_txrx(0x5A,&PS2_byte4.byte);
    ps2_txrx(0x5A,&PS2_byte5.byte);
    ps2_txrx(0x5A,&PS2_byte6.byte);
    pin_ATT = 1;
    Delay100TCYx(255);
    WriteUART(0x36);
    WriteUART(0x0A);
    WriteUART(0x0D);

    print_buffer();

}

// warning, don't connect to play station as the two clocks will fight each other.
void send_commands_to_controller() {
	unsigned char response;
	char buf[20];
	char t;
        unsigned char i = 0;

        unsigned char buttonsPressed[12];
        unsigned char analogJoys[4];

//        while (1) {
//            LATAbits.LATA0 = 1;
//            Delay10KTCYx(200);
//            Delay10KTCYx(200);
//            LATAbits.LATA0 = 0;
//            Delay10KTCYx(200);
//            Delay10KTCYx(200);
//            WriteUART(0x36);
//        }

        initPS2();

	while(1) {
            //poll and command
            pin_ATT = 0;					// pull ATT low to signal gamepad
            headerPS2(0x42);
            ps2_txrx(0x00, &PS2_byte1.byte);			// receive:	1st byte of button states and set big (left) motor to Left arrow pressure
            ps2_txrx(0x00, &PS2_byte2.byte);			// receive:	2nd byte of button states and turn on small (right) motor if Right arrow pressure = 0xFF

            for (i=0;i<4;i++) {
                ps2_txrx(0x00, &analogJoys[i]);

            }

            for (i=0;i<12;i++) {
                ps2_txrx(0x00, &PS2_pressure[i]);
                buttonsPressed[i] = !!PS2_pressure[i];
            }
            pin_ATT = 1;

            print_buffer();
            WriteUART(0x0A);
            WriteUART(0x0D);
            Delay1KTCYx(20);
            Delay1KTCYx(255);
            Delay1KTCYx(255);
            Delay1KTCYx(255);

	}
}

/********************************************************************
 * Function:        void main(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Main program entry point.
 *
 * Note:            None
 *******************************************************************/

void main(void){   
    InitializeSystem();

    #if defined(USB_INTERRUPT)
        USBDeviceAttach();
    #endif

    while(1)
    {
        #if defined(USB_POLLING)
		// Check bus status and service USB interrupts.
        USBDeviceTasks(); // Interrupt or polling method.  If using polling, must call
        				  // this function periodically.  This function will take care
        				  // of processing and responding to SETUP transactions 
        				  // (such as during the enumeration process when you first
        				  // plug in).  USB hosts require that USB devices should accept
        				  // and process SETUP packets in a timely fashion.  Therefore,
        				  // when using polling, this function should be called 
        				  // regularly (such as once every 1.8ms or faster** [see 
        				  // inline code comments in usb_device.c for explanation when
        				  // "or faster" applies])  In most cases, the USBDeviceTasks() 
        				  // function does not take very long to execute (ex: <100 
        				  // instruction cycles) before it returns.
        #endif
    				  

		// Application-specific tasks.
		// Application related code may be added here, or in the ProcessIO() function.
        ProcessIO();        
    }//end while
}//end main


/********************************************************************
 * Function:        static void InitializeSystem(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        InitializeSystem is a centralize initialization
 *                  routine. All required USB initialization routines
 *                  are called from here.
 *
 *                  User application initialization routine should
 *                  also be called from here.                  
 *
 * Note:            None
 *******************************************************************/
static void InitializeSystem(void)
{
    #if (defined(__18CXX) & !defined(PIC18F87J50_PIM))
        ADCON1 |= 0x0F;                 // Default all pins to digital
    #elif defined(__C30__)
        #if defined(__PIC24FJ256GB110__) || defined(__PIC24FJ256GB106__)
            AD1PCFGL = 0xFFFF;
     #elif defined(__dsPIC33EP512MU810__)||defined(__PIC24EP512GU810__)
        	ANSELA = 0x0000;
    		ANSELB = 0x0000;
    		ANSELC = 0x0000;
    		ANSELD = 0x0000;
    		ANSELE = 0x0000;
    		ANSELG = 0x0000;
            
            // The dsPIC33EP512MU810 features Peripheral Pin
            // select. The following statements map UART2 to 
            // device pins which would connect to the the 
            // RX232 transciever on the Explorer 16 board.

             RPINR19 = 0;
             RPINR19 = 0x64;
             RPOR9bits.RP101R = 0x3;

        #endif
    #elif defined(__C32__)
        AD1PCFG = 0xFFFF;
    #endif
    
    UserInit();

    USBDeviceInit();	//usb_device.c.  Initializes USB module SFRs and firmware
    					//variables to known states.
}//end InitializeSystem



/******************************************************************************
 * Function:        void UserInit(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This routine should take care of all of the demo code
 *                  initialization that is required.
 *
 * Note:            
 *
 *****************************************************************************/
void UserInit(void)
{
    //Initialize all of the LED pins
    mInitAllLEDs();
    
    //Initialize all of the push buttons
    mInitAllSwitches();
    old_sw2 = sw2;
    old_sw3 = sw3;

    //initialize the variable holding the handle for the last
    // transmission

    lastTransmission = 0;

	OpenSPI(SPI_FOSC_64, MODE_11, SMPMID);
    OpenUART();

    TRISAbits.TRISA0 = 0;
    TRISCbits.TRISC7 = 0;	// SDO (SPI Output)
    LATBbits.LATB2 = 1;  //ATT for SPI)
    TRISB = 0b11111001;
    TRISCbits.TRISC6 = 0; // makes TX an output
    TRISAbits.TRISA0 = 0;

	initPS2();
	//send_commands_to_controller();

	//WriteUART(0x30);

}//end UserInit


/********************************************************************
 * Function:        void ProcessIO(void)
 *	
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function is a place holder for other user
 *                  routines. It is a mixture of both USB and
 *                  non-USB tasks.
 *
 * Note:            None
 *******************************************************************/
void ProcessIO(void)
{   
    //Blink the LEDs according to the USB device status
    BlinkUSBStatus();

    // User Application USB tasks
    if((USBDeviceState < CONFIGURED_STATE)||(USBSuspendControl==1)) return;

   Joystick();        
    //Call the function that behaves like a keyboard   
}//end ProcessIO


/******************************************************************************
 * Function:        void Joystick(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function will send the joystick data to the PC.  If
 *                  sw2 is pressed then it will simulate pressing a button,
 *                  moving the hat switch position, and moving two of the
 *                  analog stick postion variables.  Releasing sw2 will send
 *                  the info to the computer that indicates that nothing is
 *                  pressed on the joystick.
 *
 * Note:            None
 *****************************************************************************/
void Joystick(void)
{
	unsigned char response;
	char buf[20];
	char t;
	unsigned char i = 0;

	unsigned char buttonsPressed[12];
	unsigned char analJoys[4];
	unsigned char digital1 = 0;
	unsigned char digital2 = 0;
	unsigned char deadZone = 10;
	unsigned char hatEnum = 0;
    //If the last transmision is complete
    if(!HIDTxHandleBusy(lastTransmission))
    {
		   pin_ATT = 0;					// pull ATT low to signal gamepad
           headerPS2(0x42);
           ps2_txrx(0x00, &digital1);			// receive:	1st byte of button states and set big (left) motor to Left arrow pressure
           ps2_txrx(0x00, &digital2);			// receive:	2nd byte of button states and turn on small (right) motor if Right arrow pressure = 0xFF

           for (i=0;i<4;i++) {
               ps2_txrx(0x00, &analJoys[i]);
				if ((analJoys[i] > (0x80-deadZone)) && (analJoys[i] < (0x80+deadZone)))
					analJoys[i] = 0x80;
           }

           for (i=0;i<12;i++) {
               ps2_txrx(0x00, &PS2_pressure[i]);
               buttonsPressed[i] = !!PS2_pressure[i];
           }
           pin_ATT = 1;

           print_buffer();
           WriteUART(0x0A);
           WriteUART(0x0D);
			
          //Indicate that the "x" button is pressed, but none others
          joystick_input.members.buttons.x = buttonsPressed[6];
          joystick_input.members.buttons.square = buttonsPressed[7];
          joystick_input.members.buttons.o = buttonsPressed[5];
          joystick_input.members.buttons.triangle = buttonsPressed[4];
          joystick_input.members.buttons.L1 = buttonsPressed[8];
          joystick_input.members.buttons.R1 = buttonsPressed[9];
          joystick_input.members.buttons.L2 = buttonsPressed[10];
          joystick_input.members.buttons.R2 = buttonsPressed[11];
          joystick_input.members.buttons.select = !(digital1 & 0x01);
          joystick_input.members.buttons.start = !(digital1 & 0x08);
          joystick_input.members.buttons.left_stick = !(digital1 & 0x02);
          joystick_input.members.buttons.right_stick = !(digital1 & 0x04);
          joystick_input.members.buttons.home = 0;

				  
		switch ((digital1&0xf0)>>4) {
			case 15:
				hatEnum = HAT_SWITCH_NULL;
				break;
			case 14:
				hatEnum = HAT_SWITCH_NORTH;
				break;
			case 13:
				hatEnum = HAT_SWITCH_EAST;
				break;
			case 12:
				hatEnum = HAT_SWITCH_NORTH_EAST;
				break;
			case 11:
				hatEnum = HAT_SWITCH_SOUTH;
				break;
			case 9:
				hatEnum = HAT_SWITCH_SOUTH_EAST;
				break;
			case 3:
				hatEnum = HAT_SWITCH_SOUTH_WEST;
				break;
			case 7:
				hatEnum = HAT_SWITCH_WEST;
				break;
			case 6:
				hatEnum = HAT_SWITCH_NORTH_WEST;
				break;
		}

          //Move the hat switch to the "east" position
          joystick_input.members.hat_switch.hat_switch = hatEnum;

          //Move the X and Y coordinates to the their extreme values (0x80 is
          //  in the middle - no value).
          joystick_input.members.analog_stick.X = analJoys[2];
          joystick_input.members.analog_stick.Y = analJoys[3];

		  joystick_input.members.analog_stick.Z = analJoys[0];
		  joystick_input.members.analog_stick.Rz = analJoys[1];

          //Send the packet over USB to the host.
       	  lastTransmission = HIDTxPacket(HID_EP, (BYTE*)&joystick_input, sizeof(joystick_input));
  
    }
    return;		
}//end joystick()



/********************************************************************
 * Function:        void BlinkUSBStatus(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        BlinkUSBStatus turns on and off LEDs 
 *                  corresponding to the USB device state.
 *
 * Note:            mLED macros can be found in HardwareProfile.h
 *                  USBDeviceState is declared and updated in
 *                  usb_device.c.
 *******************************************************************/
void BlinkUSBStatus(void)
{
    static WORD led_count=0;
    
    if(led_count == 0)led_count = 10000U;
    led_count--;

    #define mLED_Both_Off()         {mLED_1_Off();mLED_2_Off();}
    #define mLED_Both_On()          {mLED_1_On();mLED_2_On();}
    #define mLED_Only_1_On()        {mLED_1_On();mLED_2_Off();}
    #define mLED_Only_2_On()        {mLED_1_Off();mLED_2_On();}

    if(USBSuspendControl == 1)
    {
        if(led_count==0)
        {
            mLED_1_Toggle();
            if(mGetLED_1())
            {
                mLED_2_On();
            }
            else
            {
                mLED_2_Off();
            }
        }//end if
    }
    else
    {
        if(USBDeviceState == DETACHED_STATE)
        {
            mLED_Both_Off();
        }
        else if(USBDeviceState == ATTACHED_STATE)
        {
            mLED_Both_On();
        }
        else if(USBDeviceState == POWERED_STATE)
        {
            mLED_Only_1_On();
        }
        else if(USBDeviceState == DEFAULT_STATE)
        {
            mLED_Only_2_On();
        }
        else if(USBDeviceState == ADDRESS_STATE)
        {
            if(led_count == 0)
            {
                mLED_1_Toggle();
                mLED_2_Off();
            }//end if
        }
        else if(USBDeviceState == CONFIGURED_STATE)
        {
            if(led_count==0)
            {
                mLED_1_Toggle();
                if(mGetLED_1())
                {
                    mLED_2_Off();
                }
                else
                {
                    mLED_2_On();
                }
            }//end if
        }//end if(...)
    }//end if(UCONbits.SUSPND...)

}//end BlinkUSBStatus



// ******************************************************************************************************
// ************** USB Callback Functions ****************************************************************
// ******************************************************************************************************
// The USB firmware stack will call the callback functions USBCBxxx() in response to certain USB related
// events.  For example, if the host PC is powering down, it will stop sending out Start of Frame (SOF)
// packets to your device.  In response to this, all USB devices are supposed to decrease their power
// consumption from the USB Vbus to <2.5mA each.  The USB module detects this condition (which according
// to the USB specifications is 3+ms of no bus activity/SOF packets) and then calls the USBCBSuspend()
// function.  You should modify these callback functions to take appropriate actions for each of these
// conditions.  For example, in the USBCBSuspend(), you may wish to add code that will decrease power
// consumption from Vbus to <2.5mA (such as by clock switching, turning off LEDs, putting the
// microcontroller to sleep, etc.).  Then, in the USBCBWakeFromSuspend() function, you may then wish to
// add code that undoes the power saving things done in the USBCBSuspend() function.

// The USBCBSendResume() function is special, in that the USB stack will not automatically call this
// function.  This function is meant to be called from the application firmware instead.  See the
// additional comments near the function.

/******************************************************************************
 * Function:        void USBCBSuspend(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Call back that is invoked when a USB suspend is detected
 *
 * Note:            None
 *****************************************************************************/
void USBCBSuspend(void)
{
	//Example power saving code.  Insert appropriate code here for the desired
	//application behavior.  If the microcontroller will be put to sleep, a
	//process similar to that shown below may be used:
	
	//ConfigureIOPinsForLowPower();
	//SaveStateOfAllInterruptEnableBits();
	//DisableAllInterruptEnableBits();
	//EnableOnlyTheInterruptsWhichWillBeUsedToWakeTheMicro();	//should enable at least USBActivityIF as a wake source
	//Sleep();
	//RestoreStateOfAllPreviouslySavedInterruptEnableBits();	//Preferrably, this should be done in the USBCBWakeFromSuspend() function instead.
	//RestoreIOPinsToNormal();									//Preferrably, this should be done in the USBCBWakeFromSuspend() function instead.

	//IMPORTANT NOTE: Do not clear the USBActivityIF (ACTVIF) bit here.  This bit is 
	//cleared inside the usb_device.c file.  Clearing USBActivityIF here will cause 
	//things to not work as intended.	
	

    #if defined(__C30__)
    #if 0
        U1EIR = 0xFFFF;
        U1IR = 0xFFFF;
        U1OTGIR = 0xFFFF;
        IFS5bits.USB1IF = 0;
        IEC5bits.USB1IE = 1;
        U1OTGIEbits.ACTVIE = 1;
        U1OTGIRbits.ACTVIF = 1;
        Sleep();
    #endif
    #endif
}


/******************************************************************************
 * Function:        void _USB1Interrupt(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function is called when the USB interrupt bit is set
 *					In this example the interrupt is only used when the device
 *					goes to sleep when it receives a USB suspend command
 *
 * Note:            None
 *****************************************************************************/
#if 0
void __attribute__ ((interrupt)) _USB1Interrupt(void)
{
    #if !defined(self_powered)
        if(U1OTGIRbits.ACTVIF)
        {       
            IEC5bits.USB1IE = 0;
            U1OTGIEbits.ACTVIE = 0;
            IFS5bits.USB1IF = 0;
        
            //USBClearInterruptFlag(USBActivityIFReg,USBActivityIFBitNum);
            USBClearInterruptFlag(USBIdleIFReg,USBIdleIFBitNum);
            //USBSuspendControl = 0;
        }
    #endif
}
#endif

/******************************************************************************
 * Function:        void USBCBWakeFromSuspend(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The host may put USB peripheral devices in low power
 *					suspend mode (by "sending" 3+ms of idle).  Once in suspend
 *					mode, the host may wake the device back up by sending non-
 *					idle state signalling.
 *					
 *					This call back is invoked when a wakeup from USB suspend 
 *					is detected.
 *
 * Note:            None
 *****************************************************************************/
void USBCBWakeFromSuspend(void)
{
	// If clock switching or other power savings measures were taken when
	// executing the USBCBSuspend() function, now would be a good time to
	// switch back to normal full power run mode conditions.  The host allows
	// a few milliseconds of wakeup time, after which the device must be 
	// fully back to normal, and capable of receiving and processing USB
	// packets.  In order to do this, the USB module must receive proper
	// clocking (IE: 48MHz clock must be available to SIE for full speed USB
	// operation).
}

/********************************************************************
 * Function:        void USBCB_SOF_Handler(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The USB host sends out a SOF packet to full-speed
 *                  devices every 1 ms. This interrupt may be useful
 *                  for isochronous pipes. End designers should
 *                  implement callback routine as necessary.
 *
 * Note:            None
 *******************************************************************/
void USBCB_SOF_Handler(void)
{
    // No need to clear UIRbits.SOFIF to 0 here.
    // Callback caller is already doing that.
}

/*******************************************************************
 * Function:        void USBCBErrorHandler(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The purpose of this callback is mainly for
 *                  debugging during development. Check UEIR to see
 *                  which error causes the interrupt.
 *
 * Note:            None
 *******************************************************************/
void USBCBErrorHandler(void)
{
    // No need to clear UEIR to 0 here.
    // Callback caller is already doing that.

	// Typically, user firmware does not need to do anything special
	// if a USB error occurs.  For example, if the host sends an OUT
	// packet to your device, but the packet gets corrupted (ex:
	// because of a bad connection, or the user unplugs the
	// USB cable during the transmission) this will typically set
	// one or more USB error interrupt flags.  Nothing specific
	// needs to be done however, since the SIE will automatically
	// send a "NAK" packet to the host.  In response to this, the
	// host will normally retry to send the packet again, and no
	// data loss occurs.  The system will typically recover
	// automatically, without the need for application firmware
	// intervention.
	
	// Nevertheless, this callback function is provided, such as
	// for debugging purposes.
}


/*******************************************************************
 * Function:        void USBCBCheckOtherReq(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        When SETUP packets arrive from the host, some
 * 					firmware must process the request and respond
 *					appropriately to fulfill the request.  Some of
 *					the SETUP packets will be for standard
 *					USB "chapter 9" (as in, fulfilling chapter 9 of
 *					the official USB specifications) requests, while
 *					others may be specific to the USB device class
 *					that is being implemented.  For example, a HID
 *					class device needs to be able to respond to
 *					"GET REPORT" type of requests.  This
 *					is not a standard USB chapter 9 request, and 
 *					therefore not handled by usb_device.c.  Instead
 *					this request should be handled by class specific 
 *					firmware, such as that contained in usb_function_hid.c.
 *
 * Note:            None
 *******************************************************************/
void USBCBCheckOtherReq(void)
{
    USBCheckHIDRequest();
}//end


/*******************************************************************
 * Function:        void USBCBStdSetDscHandler(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The USBCBStdSetDscHandler() callback function is
 *					called when a SETUP, bRequest: SET_DESCRIPTOR request
 *					arrives.  Typically SET_DESCRIPTOR requests are
 *					not used in most applications, and it is
 *					optional to support this type of request.
 *
 * Note:            None
 *******************************************************************/
void USBCBStdSetDscHandler(void)
{
    // Must claim session ownership if supporting this request
}//end


/*******************************************************************
 * Function:        void USBCBInitEP(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function is called when the device becomes
 *                  initialized, which occurs after the host sends a
 * 					SET_CONFIGURATION (wValue not = 0) request.  This 
 *					callback function should initialize the endpoints 
 *					for the device's usage according to the current 
 *					configuration.
 *
 * Note:            None
 *******************************************************************/
void USBCBInitEP(void)
{
    //enable the HID endpoint
    USBEnableEndpoint(HID_EP,USB_OUT_ENABLED|USB_IN_ENABLED|USB_HANDSHAKE_ENABLED|USB_DISALLOW_SETUP);
}

/********************************************************************
 * Function:        void USBCBSendResume(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        The USB specifications allow some types of USB
 * 					peripheral devices to wake up a host PC (such
 *					as if it is in a low power suspend to RAM state).
 *					This can be a very useful feature in some
 *					USB applications, such as an Infrared remote
 *					control	receiver.  If a user presses the "power"
 *					button on a remote control, it is nice that the
 *					IR receiver can detect this signalling, and then
 *					send a USB "command" to the PC to wake up.
 *					
 *					The USBCBSendResume() "callback" function is used
 *					to send this special USB signalling which wakes 
 *					up the PC.  This function may be called by
 *					application firmware to wake up the PC.  This
 *					function will only be able to wake up the host if
 *                  all of the below are true:
 *					
 *					1.  The USB driver used on the host PC supports
 *						the remote wakeup capability.
 *					2.  The USB configuration descriptor indicates
 *						the device is remote wakeup capable in the
 *						bmAttributes field.
 *					3.  The USB host PC is currently sleeping,
 *						and has previously sent your device a SET 
 *						FEATURE setup packet which "armed" the
 *						remote wakeup capability.   
 *
 *                  If the host has not armed the device to perform remote wakeup,
 *                  then this function will return without actually performing a
 *                  remote wakeup sequence.  This is the required behavior, 
 *                  as a USB device that has not been armed to perform remote 
 *                  wakeup must not drive remote wakeup signalling onto the bus;
 *                  doing so will cause USB compliance testing failure.
 *                  
 *					This callback should send a RESUME signal that
 *                  has the period of 1-15ms.
 *
 * Note:            This function does nothing and returns quickly, if the USB
 *                  bus and host are not in a suspended condition, or are 
 *                  otherwise not in a remote wakeup ready state.  Therefore, it
 *                  is safe to optionally call this function regularly, ex: 
 *                  anytime application stimulus occurs, as the function will
 *                  have no effect, until the bus really is in a state ready
 *                  to accept remote wakeup. 
 *
 *                  When this function executes, it may perform clock switching,
 *                  depending upon the application specific code in 
 *                  USBCBWakeFromSuspend().  This is needed, since the USB
 *                  bus will no longer be suspended by the time this function
 *                  returns.  Therefore, the USB module will need to be ready
 *                  to receive traffic from the host.
 *
 *                  The modifiable section in this routine may be changed
 *                  to meet the application needs. Current implementation
 *                  temporary blocks other functions from executing for a
 *                  period of ~3-15 ms depending on the core frequency.
 *
 *                  According to USB 2.0 specification section 7.1.7.7,
 *                  "The remote wakeup device must hold the resume signaling
 *                  for at least 1 ms but for no more than 15 ms."
 *                  The idea here is to use a delay counter loop, using a
 *                  common value that would work over a wide range of core
 *                  frequencies.
 *                  That value selected is 1800. See table below:
 *                  ==========================================================
 *                  Core Freq(MHz)      MIP         RESUME Signal Period (ms)
 *                  ==========================================================
 *                      48              12          1.05
 *                       4              1           12.6
 *                  ==========================================================
 *                  * These timing could be incorrect when using code
 *                    optimization or extended instruction mode,
 *                    or when having other interrupts enabled.
 *                    Make sure to verify using the MPLAB SIM's Stopwatch
 *                    and verify the actual signal on an oscilloscope.
 *******************************************************************/
void USBCBSendResume(void)
{
    static WORD delay_count;
    
    //First verify that the host has armed us to perform remote wakeup.
    //It does this by sending a SET_FEATURE request to enable remote wakeup,
    //usually just before the host goes to standby mode (note: it will only
    //send this SET_FEATURE request if the configuration descriptor declares
    //the device as remote wakeup capable, AND, if the feature is enabled
    //on the host (ex: on Windows based hosts, in the device manager 
    //properties page for the USB device, power management tab, the 
    //"Allow this device to bring the computer out of standby." checkbox 
    //should be checked).
    if(USBGetRemoteWakeupStatus() == TRUE) 
    {
        //Verify that the USB bus is in fact suspended, before we send
        //remote wakeup signalling.
        if(USBIsBusSuspended() == TRUE)
        {
            USBMaskInterrupts();
            
            //Clock switch to settings consistent with normal USB operation.
            USBCBWakeFromSuspend();
            USBSuspendControl = 0; 
            USBBusIsSuspended = FALSE;  //So we don't execute this code again, 
                                        //until a new suspend condition is detected.

            //Section 7.1.7.7 of the USB 2.0 specifications indicates a USB
            //device must continuously see 5ms+ of idle on the bus, before it sends
            //remote wakeup signalling.  One way to be certain that this parameter
            //gets met, is to add a 2ms+ blocking delay here (2ms plus at 
            //least 3ms from bus idle to USBIsBusSuspended() == TRUE, yeilds
            //5ms+ total delay since start of idle).
            delay_count = 3600U;        
            do
            {
                delay_count--;
            }while(delay_count);
            
            //Now drive the resume K-state signalling onto the USB bus.
            USBResumeControl = 1;       // Start RESUME signaling
            delay_count = 1800U;        // Set RESUME line for 1-13 ms
            do
            {
                delay_count--;
            }while(delay_count);
            USBResumeControl = 0;       //Finished driving resume signalling

            USBUnmaskInterrupts();
        }
    }
}


/*******************************************************************
 * Function:        BOOL USER_USB_CALLBACK_EVENT_HANDLER(
 *                        USB_EVENT event, void *pdata, WORD size)
 *
 * PreCondition:    None
 *
 * Input:           USB_EVENT event - the type of event
 *                  void *pdata - pointer to the event data
 *                  WORD size - size of the event data
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function is called from the USB stack to
 *                  notify a user application that a USB event
 *                  occured.  This callback is in interrupt context
 *                  when the USB_INTERRUPT option is selected.
 *
 * Note:            None
 *******************************************************************/
BOOL USER_USB_CALLBACK_EVENT_HANDLER(USB_EVENT event, void *pdata, WORD size)
{
    switch(event)
    {
        case EVENT_TRANSFER:
            //Add application specific callback task or callback function here if desired.
            break;
        case EVENT_SOF:
            USBCB_SOF_Handler();
            break;
        case EVENT_SUSPEND:
            USBCBSuspend();
            break;
        case EVENT_RESUME:
            USBCBWakeFromSuspend();
            break;
        case EVENT_CONFIGURED: 
            USBCBInitEP();
            break;
        case EVENT_SET_DESCRIPTOR:
            USBCBStdSetDscHandler();
            break;
        case EVENT_EP0_REQUEST:
            USBCBCheckOtherReq();
            break;
        case EVENT_BUS_ERROR:
            USBCBErrorHandler();
            break;
        case EVENT_TRANSFER_TERMINATED:
            //Add application specific callback task or callback function here if desired.
            //The EVENT_TRANSFER_TERMINATED event occurs when the host performs a CLEAR
            //FEATURE (endpoint halt) request on an application endpoint which was 
            //previously armed (UOWN was = 1).  Here would be a good place to:
            //1.  Determine which endpoint the transaction that just got terminated was 
            //      on, by checking the handle value in the *pdata.
            //2.  Re-arm the endpoint if desired (typically would be the case for OUT 
            //      endpoints).
            break;
        default:
            break;
    }      
    return TRUE; 
}

/** EOF main.c *************************************************/
#endif
