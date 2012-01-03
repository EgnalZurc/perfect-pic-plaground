#include <htc.h>
#include <stdlib.h>

#define LATCH RB0
#define DATA RB1
#define ON		1
#define OFF		0
#define _XTAL_FREQ 20000000

char pattern = 0x05;
char bitCount = 0;

__CONFIG(HS & WDTDIS & UNPROTECT);

void main(void) {
//Set up I/O
	TRISB = 0b00000000;
	PORTB = 0b00000000;

//Set 1:16 prescaler for TMR0
	PS0 = 1;
	PS1 = 1;
	PS2 = 1;
	PSA = 0;
	T0CS = 0;

//Set up timer interrupts
	GIE = 1;
	T0IE = 1;
	PEIE = 1;

	while (1) {
		for (int delay=0;delay<100;delay++) {
			__delay_ms(100);
			pattern++;
		}
	}
}

void interrupt timer0(void) {
	if (T0IF == 1) {
		if (bitCount < 8) {
			DATA = pattern & 1;
			pattern >> 1;
			bitCount++;
		} else {
			LATCH = ON;
			bitCount = 0;
		}	
		T0IF = 0;
	}
}