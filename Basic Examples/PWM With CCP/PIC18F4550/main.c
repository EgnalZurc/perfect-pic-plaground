#ifndef MAIN_C
#define MAIN_C

#include <htc.h>

#define _XTAL_FREQ 48000000

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

//interrupt isr(void) {
//	if (TMR2IF) {
//		TMR2IF = 0;
//	}
//}

void main(void) {
	TRISA = 0b00000000;
	TRISB = 0b00000000;
	TRISC = 0b00000000;

	PORTA = 0b00000000;
	PORTB = 0b00000000;
	PORTC = 0b00000000;

	//Timer2 Period
	PR2 = 255;

	//Timer2 Prescalers (1:16)
	T2CKPS0 = 1;
	T2CKPS1 = 1;

	CCP1CON = 0b00001100;
	CCP2CON = 0b00001100;

	DC1B0 = 1;
	DC1B1 = 1;
	CCPR1L = 0x0F;

	DC2B0 = 1;
	DC2B1 = 1;
	CCPR2L = 0x0F;
	

	TMR2IE = 1;
	TMR2ON = 1;

	//PEIE = 1;

	//GIE = 1;

	while (1) {
		for (int delay=0;delay<100;delay++) {
			__delay_ms(11);
			CCPR1L++;
			CCPR2L += 2;
		}
	}
}

#endif