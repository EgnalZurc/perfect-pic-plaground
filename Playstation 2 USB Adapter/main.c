#include <htc.h>

#define ATT RC7
#define CLK RB0

#define _XTAL_FREQ 48000000

#define ON 1
#define OFF 0

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

bit on;

interrupt isr(void) {
	if (TMR2IF) {
		CLK = on;
		on = !on;
		TMR2 = 0;
		TMR2IF = 0;
	}
}	

void main(void) {
	TRISA = 0x00;
	TRISB = 0x00;
	TRISC = 0x00;
	
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	
	on = ON;
	
	//250KHz clock signal=>500KHz timer to switch high and low
	//fosc/4=12MHz, so scale clock by 24
	
//	T0CON = 0b11001000;
//
//	TMR0L = 255-1;
//	TMR0IE = 1;
//	TMR0ON = 1;

//	T2CON = 0b00000100;
//	PR2 = 2;
//	TMR2IE = 1;
	
	GIE = 1;
	PEIE = 1;
	
	while (1){
		CLK = on;
		on = !on;
		__delay_us(1);
		on = !on;
		on = !on;
	}	
}