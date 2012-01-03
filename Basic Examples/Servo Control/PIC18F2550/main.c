#ifndef MAIN_C
#define MAIN_C

#define SERVO RB0
#define ON 1
#define OFF 0

#include <htc.h>

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

char timer2Counter = 0;
char servoThresh = 5;

interrupt isr(void) {
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
	}
}

void main(void) {
	TRISA = 0b00000000;
	TRISB = 0b00000000;
	TRISC = 0b00000000;
	
	PORTA = 0b00000000;
	PORTB = 0b00000000;
	TRISC = 0b00000000;

	//PR2: Timer2 Period
	PR2 = 74;

	//T2CKPS1:T2CKPS0 = Timer2 Prescalers (1x = 1:16)
	T2CKPS1 = 1;
	T2CKPS0 = 1;

	//Turn Timer2 on
	TMR2ON = 1;

	//TMR2IE: Timer2 Interrupt Enable
	TMR2IE = 1;

	PEIE = 1;

	GIE = 1;
	
	while (1);
}

#endif