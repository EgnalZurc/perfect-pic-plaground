#include <delays.h>  


extern void delay_uS(char);

	
// Delay for: ((((2*FOSC) / (8*baud)) + 1) / 2) - 9 cycles  		
void DelayRXHalfBitUART(void) {
	 // we're not using the receiver...
}


//Delay for:  ((((2*FOSC) / (4*baud)) + 1) / 2) - 14 cycles      
void DelayRXBitUART(void) {
	// we're not using the receiver...
}

// Delay for: ((((2*FOSC) / (4*baud)) + 1) / 2) - 12 cycles
// not sure if a cycle is a clock cycle or instruction cycle (= 4 clocks)
void DelayTXBitUART(void) {
	// for 57600 baud, main clock running at 4 MIPs (million INSTRUCTIONS / sec), ~56 Nops
	// seems to work.  each bit should be 1/57600 = 1.73e-5, and 56 Nops is .25uS*56 = 
	// 14uS, or 1.4e-5... the rest of the delay is from the mechanics of calling a function
	// and other delays within the UART code.
	Delay10TCYx(5);	
	Delay1TCY(); // equiv to Nop()
	Delay1TCY();
	Delay1TCY();
	Delay1TCY();
	Delay1TCY();
	Delay1TCY();
	
}