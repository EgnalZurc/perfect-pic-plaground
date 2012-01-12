#include <htc.h>
#include "softPWM.h"

volatile int i2c_buff_index = 0;
volatile unsigned char i2c_rx_buff[2];
unsigned char i2c_tx_buff[2] = 0x22;

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
// Handle I2C serial - TODO: need to comment the shit out of this and move it to its own file
	if (SSPIF) { 
		SSPIF = 0; 
		v_sspstat = SSPSTAT & 0b00101101; 
		
		if (v_sspstat == 0b00001001) //State 1: Master Write, Last Byte was an Address 
		{ 
			i2c_buff_index = 0; 
			RB4 = !RB4;
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
			i2c_tx_buff[i2c_buff_index] = i2c_rx_buff[i2c_buff_index];
			CKP = 1;
			//Checks if buffer is full, and if so reset the index 
			if (++i2c_buff_index == sizeof(i2c_rx_buff)) { 
			i2c_buff_index = 0; 
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