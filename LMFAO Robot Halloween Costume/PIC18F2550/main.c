#ifndef MAIN_C
#define MAIN_C

#include <htc.h>

#define _XTAL_FREQ 48000000
#define ON 1
#define OFF 0
#define OTHER RB1
#define CLK RB0

// PIC 18F2550 fuse configuration:
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

bit on = 0;
bit onOther = 0;

void main(void) {
	TRISA = 0b00000000;
	TRISB = 0b00000000;
	TRISC = 0b00000000;

	PORTA = 0b00000000;
	PORTB = 0b00000000;
	PORTC = 0b00000000;

//	//Timer2 Period
//	PR2 = 255;
//
//	//Timer2 Prescalers (1:16)
//	T2CKPS0 = 1;
//	T2CKPS1 = 1;
//
//	TMR2IE = 1;
//	TMR2ON = 1;
//	
//	NCLR = OFF;
//
//	PEIE = 1;
//
//	GIE = 1;
	
	__delay_ms(10);

	while (1) {
		for (int delay=0;delay<500;delay++) {
			__delay_ms(8);
			if (!(delay % 8	)) {
				OTHER = onOther;
				onOther = !onOther;
			}
			if (!(delay % 10)) {
				CLK = on;
				on = !on;
			}
		}
	}
}

#endif