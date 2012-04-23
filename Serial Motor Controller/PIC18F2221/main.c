#include <htc.h>
#include <stdlib.h>
#include "globals.h"

#include "softPWM.h"
#include "ADC.h"


/** Define Globals for main */
char potEnabled = 0;
char down = 0;
char stressTest = 1;
char counter = 0;

// 8Mhz Clk, PLL on, 
void setupOsc(void){
//	//IRCF2:IRFC0: Internal Oscillator Frequency select bits
//	//111 => 8MHz
//	IRCF0 = 1;
//	IRCF1 = 1;
//	IRCF2 = 1;
//	
//	//SCS1:SCS0: System Clock bits
//	//1x => Internal oscillator
//	SCS0 = 1;
//	SCS1 = 1;

	OSCCON = 0b11110000;
	while(!IOFS);
	__delay_ms(10);
	PLLEN = 1;
	WDTCON = 0x00;
}

void configSystem(void){
	setupOsc();
	//Set all pins to output and clear them
	TRISA = 0x00;
	TRISB = 0x00;
	TRISC = 0x00;
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	
	//Enable digital outputs for PORTA
	ADCON1 = 0x0F;	
	
	//Clear the status flag
	SFLAG = 0;
	RA4 = 1;
	ENABLE = 1;
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


void runStressTest(void){
	while (!down){
			dutyCycle1++;
			dutyCycle2--;
			for(counter=0;counter<10;counter++){
				__delay_ms(1);
			}
			if (dutyCycle1 > 62) down = 1;
		}
		while (down){
			dutyCycle1--;
			dutyCycle2++;
			for(counter=0;counter<10;counter++){
				__delay_ms(1);
			}
			if (dutyCycle1 < 1) down = 0;
		}
}

void runTest(void){
	dutyCycle1 = 32;
	dutyCycle2 = 32;
}

void main(void) {
	//setupOsc();
	//RD2 = 1;
	configSystem();
	configSoftPWM();
	configTimer();
	configI2C();
//	configADC();
	//adcOff();
	
	while (1) {
		//if(potEnabled) runADC();
		//else runStressTest();
		//else while(1);
		
		//If command is supported
		if(newData){
			switch(i2c_rx_buff[0]){
				/****** Set Motor 1 Speed ********/
				case 0x00:
					if (i2c_rx_buff[1] > 32) {
						dutyCycle2 = i2c_rx_buff[1] - 32;
						dutyCycle1 = 0;
					}
					else{
						dutyCycle1 = 32 - i2c_rx_buff[1];
						dutyCycle2 = 0;
					}
					newData = 0;
				break;
				/****** Set Motor 2 Speed ********/
				case 0x01:
					if (i2c_rx_buff[1] > 32) {
						dutyCycle4 = i2c_rx_buff[1] - 32;
						dutyCycle3 = 0;
					}
					else{
						dutyCycle3 = 32 - i2c_rx_buff[1];
						dutyCycle4 = 0;
					}
					newData = 0;
				break;
				/****** Read Motor 1 Speed ********/
				case 0x10:
					i2c_tx_buff[0] = dutyCycle1;
				break;
				/****** Read Motor 2 Speed ********/
				case 0x20:
					i2c_tx_buff[0] = dutyCycle2;
				break;
				/********* Read ADC ***************/
				case 100:
					i2c_tx_buff[0] = readADC();
				break;
				/****** Enable ADC ****************/
				case 0x99:
					potEnabled = i2c_rx_buff[1];
				break;
				default:
					//RB4 = 1;
					newData = 0;
				break;
			}

		}
		//Unsupported command
		//else RB4 = 1;
		//dutyCycle1 = i2c_rx_buff[0];
	}
}	