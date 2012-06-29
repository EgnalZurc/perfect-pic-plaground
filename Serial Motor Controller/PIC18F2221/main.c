#include <htc.h>
#include <stdlib.h>
#include "globals.h"

#include "init.h"
#include "softPWM.h"
#include "ADC.h"

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
		
		//**PID Current control**
		// Read current on channel
		//		1. Read ADC value
		//		2. Scale to voltage
		// 		3. V*100=I
		// Calculate Error between current I(current) and setpoint
		//		1. Scale setpoint to 0 - Max current
		//			1. Get Max Current (This needs to be done on init)
		//		2. Err = Setpoint - Current Current
		//		3. Err * Pi = Pterm
		// dutyCycle += Pterm
		
		//Operate on received command
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