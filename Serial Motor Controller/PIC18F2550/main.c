#include <htc.h>
#include <stdlib.h>

#include "softPWM.h"

#define _XTAL_FREQ	8000000

// PIC 18F2550 fuse configuration:
// Config word 1 (Oscillator configuration)
// 8MHz internal clock
__CONFIG(1, USBPLL & IESODIS & FCMDIS & INTCLKO & CPUDIV1 & PLLDIV2);
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


void configSystem(void){
	//IRCF2:IRFC0: Internal Oscillator Frequency select bits
	//111 => 8MHz
	IRCF0 = 1;
	IRCF1 = 1;
	IRCF2 = 1;
	
	//SCS1:SCS0: System Clock bits
	//1x => Internal oscillator
	SCS0 = 1;
	SCS1 = 1;
	
	//Set all pins to output and clear them
	TRISA = 0x00;
	TRISB = 0x00;
	TRISC = 0x00;
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	
	//Enable digital outputs for PORTA
	ADCON1 = 0x0F;	
}


void main(void) {
	char down = 0;
	configSystem();
	configSoftPWM();
	
	while (1) {
		while (!down){
			dutyCycle1++;
			dutyCycle2--;
			__delay_ms(30);
			if (dutyCycle1 > 62) down = 1;
		}
		while (down){
			dutyCycle1--;
			dutyCycle2++;
			__delay_ms(30);
			if (dutyCycle1 < 1) down = 0;
		}
	}
}	