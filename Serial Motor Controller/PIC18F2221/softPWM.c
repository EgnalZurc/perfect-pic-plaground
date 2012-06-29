#include <htc.h>

#include "globals.h"
#include "softPWM.h"


void interrupt isr(){
	// Timer 2 Interupt
	if (TMR2IF){
		SFLAG = 1;
		ENABLE = 0;
		NOP();
		ENABLE = 1;
		
		// Channel 1
		// Perform the PWM duty cycle switching
		if (dutyCycle1 > pwmCounter)
			pwm1 = 1; else pwm1 = 0;
		
		// Channel 2
		// Perform the PWM duty cycle switching
		if (dutyCycle2 > pwmCounter)
			pwm2 = 1; else pwm2 = 0;
	
		// Channel 3
		// Perform the PWM duty cycle switching
		if (dutyCycle3 > pwmCounter)
			pwm3 = 1; else pwm3 = 0;

		// Channel 4
		// Perform the PWM duty cycle switching
		if (dutyCycle4 > pwmCounter)
			pwm4 = 1; else pwm4 = 0;

		// Channel 5
		// Perform the PWM duty cycle switching
		if (dutyCycle5 > pwmCounter)
			pwm5 = 1; else pwm5 = 0;

		// Channel 6
		// Perform the PWM duty cycle switching
		if (dutyCycle6 > pwmCounter)
			pwm6 = 1; else pwm6 = 0;

		// Update the PWM counter
		pwmCounter++;
		if (pwmCounter > PWMMAX) pwmCounter = 0;
		
		// Reset the timer2 interrupt flag
		TMR2IF = 0;
	//RA0 = ~RA0;
	}
// Handle I2C serial - TODO: need to comment the shit out of this and move it to its own file
	if (SSPIF) { 
		SFLAG = 1;
		SSPIF = 0; 
		v_sspstat = SSPSTAT & 0b00101101; 
		
		if (v_sspstat == 0b00001001) //State 1: Master Write, Last Byte was an Address 
		{ 
			i2c_buff_index = 0; 
			//RB4 = !RB4;
			SSPBUF;
			if (SSPOV){
				SSPOV = 0;
				SSPBUF;
				RB5 = 1;
			} 
			CKP = 1;	 //FROM SSPCON1               
		}  
		else if ( v_sspstat == 0b00101001 ) //State 2: Master Write, Last Byte was Data     
		{ 
			i2c_rx_buff[i2c_buff_index] = SSPBUF; 
			if (SSPOV){
				SSPOV = 0;
				SSPBUF;
				RB5 = 1;
			} 
			//i2c_tx_buff[i2c_buff_index] = i2c_rx_buff[i2c_buff_index];
			CKP = 1;
			//Checks if buffer is full, and if so reset the index 
			if (++i2c_buff_index == sizeof(i2c_rx_buff)) { 
			i2c_buff_index = 0; 
			newData = 1;
			} 
		} 
		else if ( v_sspstat == 0b00001101 ) //State 3: Master Read, Last Byte was an Address 
		{ 
			if (SSPBUF == SSPADD + 1){ 
				SSPBUF = i2c_tx_buff[0];
				CKP=1; 
				i2c_buff_index = 1;
				SSPIF = 0;
			}
			//An error occured
			else RB5 = 1;
		} 
		else if (( v_sspstat == 0b00101100 )&&(!ACKSTAT)) //State 4: Master Read, Last Byte was Data     
		{ 
			SSPBUF = i2c_tx_buff[i2c_buff_index]; 
			
			unsigned char size = sizeof(i2c_tx_buff);
			if (++i2c_buff_index == sizeof(i2c_tx_buff)) { 
				i2c_buff_index = 0;
				SSPBUF = 0;
				CKP = 1;
				SSPIF = 0;
			} 
		} 
		else 
		{ 
			CKP=1; 
		}             
	} 
}

void configSoftPWM(void){
	//Postscaler - T2CON<6:3> - 0000 = Postscale off | 1111 = 1:16 Postscale
	T2CONbits.T2CKPS = 0;
	//Prescaler - T2CON<1:0> - 00 = Prescale off | 01 = 1:4 | 1x = 1:16
	T2CONbits.TOUTPS = 0;
	//Enable TMR2 Interupt
	TMR2IE = 1;
	
	//Enable peripheral interupts
	PEIE = 1;
	//TMR2 Period
	PR2 = 255;
	//TMR2 Enable

	T2CONbits.TMR2ON = 1;
	//Enable all Interupts
	ei();	
}

void configTimer(void){
	//Timer 0 
	T0CONbits.T08BIT = 1;
	T0CONbits.T0CS = 0;
	//Disable prescaler
	T0CONbits.PSA = 1;
	
	// 1:2 Prescale
	T0CONbits.T0PS = 111;
	TMR0IE = 0;

	// Enable Timer
	T0CONbits.TMR0ON = 0;
	
	ei();	
}

void configI2C(void){
	//Config Inputs
	//CLK input, SDA Output
	TRISC |= 1 << 3;
	TRISC |= 1 << 4;

	//SSPSTAT - Disable Slew Rate Control
	SSPSTAT |= 1 << 7;
	//SSPCON
		//Enable Serial port/relase clock/ enable 7bit i2c with start/stop interupts
	SSPCON1 = 0b00111110;
		//Enable general call response and enable clock stretching
	SSPCON2 |= 1 << 7;
	SSPCON2 |= 1 << 0;
	SSPADD = 0x10;
	//PIR1
	//PIE1

}
