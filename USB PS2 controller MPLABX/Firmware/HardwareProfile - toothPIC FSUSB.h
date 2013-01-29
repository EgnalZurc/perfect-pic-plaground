/********************************************************************
 FileName:     	HardwareProfile - PICDEM FSUSB.h
 Dependencies:  See INCLUDES section
 Processor:     PIC18 USB Microcontrollers
 Hardware:      PICDEM FSUSB
 Compiler:      Microchip C18
 Company:       Microchip Technology, Inc.

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
 File Description:

 Change History:
  Rev   Date         Description
  1.0   11/19/2004   Initial release
  2.1   02/26/2007   Updated for simplicity and to use common
                     coding style
  2.3   09/15/2008   Broke out each hardware platform into its own
                     "HardwareProfile - xxx.h" file
********************************************************************/

#ifndef HARDWARE_PROFILE_PICDEM_FSUSB_H
#define HARDWARE_PROFILE_PICDEM_FSUSB_H

    /*******************************************************************/
    /******** USB stack hardware selection options *********************/
    /*******************************************************************/
    //This section is the set of definitions required by the MCHPFSUSB
    //  framework.  These definitions tell the firmware what mode it is
    //  running in, and where it can find the results to some information
    //  that the stack needs.
    //These definitions are required by every application developed with
    //  this revision of the MCHPFSUSB framework.  Please review each
    //  option carefully and determine which options are desired/required
    //  for your application.

    //The PICDEM FS USB Demo Board platform supports the USE_SELF_POWER_SENSE_IO
    //and USE_USB_BUS_SENSE_IO features.  Uncomment the below line(s) if
    //it is desireable to use one or both of the features.
    //#define USE_SELF_POWER_SENSE_IO
    #define tris_self_power     TRISAbits.TRISA2    // Input
    #if defined(USE_SELF_POWER_SENSE_IO)
    #define self_power          PORTAbits.RA2
    #else
    #define self_power          1
    #endif

    //#define USE_USB_BUS_SENSE_IO
    #define tris_usb_bus_sense  TRISAbits.TRISA1    // Input
    #if defined(USE_USB_BUS_SENSE_IO)
    #define USB_BUS_SENSE       PORTAbits.RA1
    #else
    #define USB_BUS_SENSE       1
    #endif


    //Uncomment the following line to make the output HEX of this  
    //  project work with the MCHPUSB Bootloader    
    //#define PROGRAMMABLE_WITH_USB_MCHPUSB_BOOTLOADER
	
    //Uncomment the following line to make the output HEX of this 
    //  project work with the HID Bootloader
    #define PROGRAMMABLE_WITH_USB_HID_BOOTLOADER		

    /*******************************************************************/
    /*******************************************************************/
    /*******************************************************************/
    /******** Application specific definitions *************************/
    /*******************************************************************/
    /*******************************************************************/
    /*******************************************************************/

    /** Board definition ***********************************************/
    //These defintions will tell the main() function which board is
    //  currently selected.  This will allow the application to add
    //  the correct configuration bits as wells use the correct
    //  initialization functions for the board.  These defitions are only
    //  required in the stack provided demos.  They are not required in
    //  final application design.
    #define DEMO_BOARD TOOTHPIC_FS_USB
    #define TOOTHPIC_FS_USB
    #define CLOCK_FREQ 16000000


    /** LED ************************************************************/
    #define mInitAllLEDs()      LATA &= 0xF0; TRISA &= 0xF0;
    
    #define mLED_1              LATAbits.LATA0
    #define mLED_2              LATAbits.LATA1
    #define mLED_3              LATAbits.LATA2
    #define mLED_4              LATAbits.LATA3
    
    #define mGetLED_1()         mLED_1
    #define mGetLED_2()         mLED_2
    #define mGetLED_3()         mLED_3
    #define mGetLED_4()         mLED_4

    #define mLED_1_On()         mLED_1 = 1;
    #define mLED_2_On()         mLED_2 = 1;
    #define mLED_3_On()         mLED_3 = 1;
    #define mLED_4_On()         mLED_4 = 1;
    
    #define mLED_1_Off()        mLED_1 = 0;
    #define mLED_2_Off()        mLED_2 = 0;
    #define mLED_3_Off()        mLED_3 = 0;
    #define mLED_4_Off()        mLED_4 = 0;
    
    #define mLED_1_Toggle()     mLED_1 = !mLED_1;
    #define mLED_2_Toggle()     mLED_2 = !mLED_2;
    #define mLED_3_Toggle()     mLED_3 = !mLED_3;
    #define mLED_4_Toggle()     mLED_4 = !mLED_4;
    
    /** SWITCH *********************************************************/
    #define mInitAllSwitches()  TRISBbits.TRISB4=1;TRISBbits.TRISB5=1;
    #define mInitSwitch2()      TRISBbits.TRISB4=1;
    #define mInitSwitch3()      TRISBbits.TRISB5=1;
    #define sw2                 PORTBbits.RB4
    #define sw3                 PORTBbits.RB5
    
    /** I/O pin definitions ********************************************/
    #define INPUT_PIN 1
    #define OUTPUT_PIN 0

	#define Delay(x) DELAY = x; while(--DELAY){ Nop(); Nop(); }
	
	
	
	
	/***** Ports *****/
	// attention line for the PS2 controller
	#define pin_ATT	 		LATBbits.LATB2
										
	/***** Buttons *****/
	// these macros can be used as meaningful shortcuts into
	// the response bytes in a PS2's return packet.
	#define PS2_Select		PS2_byte1.bit0
	#define PS2_Start		PS2_byte1.bit3
	#define PS2_R1			PS2_byte2.bit3
	#define PS2_R2			PS2_byte2.bit1
	#define PS2_R3			PS2_byte1.bit2
	#define PS2_L1			PS2_byte2.bit2
	#define PS2_L2			PS2_byte2.bit0
	#define PS2_L3			PS2_byte1.bit1
	#define PS2_Up			PS2_byte1.bit4
	#define PS2_Down		PS2_byte1.bit6
	#define PS2_Left		PS2_byte1.bit7
	#define PS2_Right		PS2_byte1.bit5
	#define PS2_Circle		PS2_byte2.bit5
	#define PS2_Square		PS2_byte2.bit7
	#define PS2_X			PS2_byte2.bit6
	#define PS2_Triangle            PS2_byte2.bit4
	#define PS2_RJX			PS2_byte3.byte
	#define PS2_RJY			PS2_byte4.byte
	#define PS2_LJX			PS2_byte5.byte
	#define PS2_LJY			PS2_byte6.byte
		
	
	/***** Types *****/
	// the union lets us access the bytes coming back from a PS2
	// either bit by bit or by a whole byte.  same memory location,
	// just two different names.
	typedef union {
	  struct {
	    unsigned bit7:1;
	    unsigned bit6:1;
	    unsigned bit5:1;
	    unsigned bit4:1;
	    unsigned bit3:1;
	    unsigned bit2:1;
	    unsigned bit1:1;
	    unsigned bit0:1;
	  };
	  struct {
	    unsigned char byte;
	  };
	} uint8; 



#endif  //HARDWARE_PROFILE_PICDEM_FSUSB_H
