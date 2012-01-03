#include <htc.h>
#include <stdlib.h>

#define BLUE	RB0
#define RED		RB1
#define GREEN	RB2
#define ON		1
#define OFF		0
#define _XTAL_FREQ 20000000

unsigned char pwmCounter = 0;
unsigned char redActual, redTarget, greenActual, greenTarget, blueActual, blueTarget;
unsigned char fade = 0;

__CONFIG(HS & WDTDIS & UNPROTECT);

void main(void) {
//Set up I/O
	TRISB = 0b00000000;
	PORTB = 0b00000000;

//Set 1:16 prescaler for TMR0
	OPTION = (OPTION & 0b11111000) | 0b001;
	PSA = 0;
	T0CS = 0;

//Set up timer interrupts
	GIE = 1;
	T0IE = 1;
	PEIE = 1;

//Set up initial LEDs off
	redActual = greenActual = blueActual = 0;
	redTarget = greenTarget = blueTarget = 0;

	while (1) {
		redTarget = rand() % 50;
		greenTarget = rand() % 50;
		blueTarget = rand() % 50;
		
//Can't do delay higher than 99ms, so chain multiple together
		for (int delay=0;delay<100;delay++) {
			__delay_ms(10);
		}
	}
}

void interrupt timer0(void) {
	if (T0IF == 1) {
		fade++;
		
		if (fade == 24) {
			if (redTarget > redActual)
				redActual++;
			else if (redTarget < redActual)
				redActual--;

			if (greenTarget > greenActual)
				greenActual++;
			else if (greenTarget < greenActual)
				greenActual--;

			if (blueTarget > blueActual)
				blueActual++;
			else if (blueTarget < blueActual)
				blueActual--;
		}

		if (redActual > pwmCounter) {
			RED = ON;
		} else {
			RED = OFF;
		}

		if (greenActual > pwmCounter) {
			GREEN = ON;
		} else {
			GREEN = OFF;
		}

		if (blueActual > pwmCounter) {
			BLUE = ON;
		} else {
			BLUE = OFF;
		}

		pwmCounter++;
		if (pwmCounter > 50) {
			pwmCounter = 0;
		}
		
		T0IF = 0;
	}
}