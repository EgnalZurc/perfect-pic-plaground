#include <htc.h>
#include "softPWM.h"

void interrupt isr()
{
	// Timer 2 Interupt
	if (TMR2IF){
		// Channel 1
		// Perform the PWM duty cycle switching
		if (dutyCycle1 > pwmCounter)
			pwm1 = 1; else pwm1 = 0;
		
		// Channel 2
		// Perform the PWM duty cycle switching
		if (dutyCycle2 > pwmCounter)
			pwm2 = 1; else pwm2 = 0;

		// Update the PWM counter
		pwmCounter++;
		if (pwmCounter > 63) pwmCounter = 0;
		
		// Reset the timer2 interrupt flag
		TMR2IF = 0;
	}
}

void configSoftPWM(){
	//Postscaler - T2CON<6:3> - 0000 = Postscale off | 1111 = 1:16 Postscale
	T2CONbits.T2CKPS = 0;
	//Prescaler - T2CON<1:0> - 00 = Prescale off | 01 = 1:4 | 1x = 1:16
	T2CONbits.TOUTPS = 0;
	T2CONbits.TMR2ON = 1;
	//Enable TMR2 Interupt
	TMR2IE = 1;
	
	//Enable peripheral interupts
	PEIE = 1;
	//TMR2 Period
	PR2 = 255;
	//Enable all Interupts
	ei();	
}