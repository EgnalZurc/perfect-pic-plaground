#include <htc.h>
#include <stdlib.h>

#include "tlc5940.h"

#define LED1	RC7
#define ON		1
#define OFF		0
#define _XTAL_FREQ	8000000

//// PIC 18F4550 fuse configuration:
//// Config word 1 (Oscillator configuration)
//// 20Mhz crystal input scaled to 48Mhz and configured for USB operation
//__CONFIG(1, USBPLL & IESODIS & FCMDIS & HSPLL & CPUDIV1 & PLLDIV5);
//// Config word 2
//__CONFIG(2, VREGEN & PWRTDIS & BOREN & BORV20 & WDTDIS & WDTPS32K);
//// Config word 3
//__CONFIG(3, PBDIGITAL & LPT1DIS & MCLREN);
//// Config word 4
//__CONFIG(4, XINSTDIS & STVREN & LVPDIS & ICPORTDIS & DEBUGDIS);
//// Config word 5, 6 and 7 (protection configuration)
//__CONFIG(5, UNPROTECT);
//__CONFIG(6, UNPROTECT);
//__CONFIG(7, UNPROTECT);

unsigned int brightness = 0;

bit on;

void main(void) {
	on = ON;
	IRCF0 = 1;
	IRCF1 = 1;
	IRCF2 = 1;
	
	SCS0 = 1;
	SCS1 = 1;
	
	INTSRC = 1;

	TRISA = 0x00;
	TRISB = 0x00;
	TRISC = 0x00;
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	
	ADCON1 = 0x0F;

    //__delay_ms(10);
    initialiseTlc5940();
//	setGrayScaleValue(1, 10);
//	updateTlc5940();
	
	while (1) {
		__delay_ms(1);
		setGrayScaleValue(1, brightness++);
		updateTlc5940();
		if (brightness > 4094)
			brightness = 0;
	}
}