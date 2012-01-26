#include <htc.h>

#define _XTAL_FREQ 48000000

// PIC 18F4550 fuse configuration Updated to use non-deprecated macro
// Constants can be found in %HTCROOT%/docs/%PICMODEL% on computer
// Oscillator Block
#pragma config CPUDIV = OSC1_PLL2, PLLDIV = 5, USBDIV = 2, IESO = OFF, FOSC = HSPLL_HS, FCMEN = OFF
// Core Peripheral Block
#pragma config VREGEN = OFF, BOR = OFF, PWRT = OFF, WDT = OFF
// Peripheral Block
#pragma config PBADEN = OFF, LPT1OSC = OFF, MCLRE = ON
#pragma config DEBUG = OFF, STVREN = ON, LVP = OFF, XINST = OFF
// Config word 5, 6 and 7 (protection configuration)
__CONFIG(5, UNPROTECT);
__CONFIG(6, UNPROTECT);
__CONFIG(7, UNPROTECT);

/** DO NOT FUCK WITH THIS STUFF YET!!! **/
//I tried to disable code protection and I ended up write-protecting one of my PICs
//If you can figure this out please let me know
//// Code Protection
//#pragma config CP0 = OFF, CP1 = OFF, CP2 = OFF, CP3 = OFF, CPD = OFF, CPB = OFF
//// Write Protection
//#pragma config WRT0 = OFF, WRT1 = OFF, WRT2 = OFF, WRT3 = OFF, WRTB = OFF, WRTC = OFF, WRTD = OFF
//// Table Read Protection
//#pragma config EBTR0 = OFF, EBTR1 = OFF, EBTR2 = OFF, EBTR3 = OFF, EBTRB = OFF

// Initialize PWM @ 12MHz (fastest possible - PWMduty = [PR2 + 1]*4*Fosc*TMR2prescale)
void initPWM(void){
	PR2 = 0x00;
    T2CON = 0b00000100;
	CCPR1L = 0x00;
	//Enable PWM
	CCP1CON = 0b00111100;
}

void init(void){
	TRISA = 0x00;
	TRISB = 0x00;
	TRISC = 0x00;
	
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;

	ADCON1 = 0x0f;
	initPWM();
}

void main(void) {
	init();
	while (1){
		// The core should be running @ 48MHz but this one instruction cycle seems to indicate 
		// it is running at 4MHz (2MHz frequency on pin) but this can't be the case as the PWM
		// cannot be running any faster than Fosc/4, in this case 12MHz.
		#asm
			BTG PORTB, 0
		#endasm
	}	
}