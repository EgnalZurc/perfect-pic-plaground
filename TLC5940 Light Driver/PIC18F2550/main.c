#include <htc.h>
#include <stdlib.h>

#include "tlc5940.h"

#define LED1	RC7
#define ON		1
#define OFF		0
#define UP		1
#define DOWN	0
#define _XTAL_FREQ	8000000

// PIC 18F4550 fuse configuration:
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

unsigned int brightness = 0;

bit fade;

void main(void) {
	//Determines whether LED increases or decreases brightness
	fade = UP;
	
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

	//Set up interrupts and SPI
    initialiseTlc5940();
    
    //Set initial brightness
	//setGrayScaleValue(1, 10);
	//updateTlc5940();
	
	while (1) {
		__delay_ms(1);
		
		//For initial testing
		//setGrayScaleValue(1, 100);
		
		setGrayScaleValue(1, brightness);
		
		//setGrayScaleValue puts the new brightness values into an buffer array,
		//but updateTlc5940 is required to change the LEDs
		//updateTlc5940 returns 0 when update complete
		
		while (updateTlc5940() == 1);
		
		//Smoothly increase brightness to maximum and then dim to minimum
		if (fade)
			brightness++;
		else
			brightness--;

		if (brightness > 4094 || brightness < 1)
			fade = !fade;
	}
}