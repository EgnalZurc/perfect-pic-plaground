#include <htc.h>
#include <stdlib.h>

#include "softPWM.h"




#define _XTAL_FREQ 48000000

// PIC 18F4550 fuse configuration Updated to use non-deprecated macro
// Constants can be found in %HTCROOT%/docs/%PICMODEL% on computer
// Oscillator Block
#pragma config CPUDIV = OSC1_PLL2, PLLDIV = 5, USBDIV = 2, IESO = OFF, FOSC = HSPLL_HS, FCMEN = OFF
// Core Peripheral Block
#pragma config VREGEN = OFF, BOR = OFF, PWRT = OFF, WDT = OFF
// Peripheral Block
#pragma config PBADEN = OFF, LPT1OSC = OFF, MCLRE = ON
#pragma config DEBUG = OFF, STVREN = ON, LVP = OFF, XINST = OFF
// Config word 5, 6 and 7 (protection configuration)
__CONFIG(5, UNPROTECT);
__CONFIG(6, UNPROTECT);
__CONFIG(7, UNPROTECT);
//#define _XTAL_FREQ	8000000

//// PIC 18F2550 fuse configuration:
//// Config word 1 (Oscillator configuration)
//// 8MHz internal clock
//__CONFIG(1, USBPLL & IESODIS & FCMDIS & HSPLL_HS & CPUDIV1 & PLLDIV2);
//// Config word 2
//__CONFIG(2, VREGEN & PWRTDIS & BOREN & BORV20 & WDTDIS & WDTPS32K);
//// Config word 3
//__CONFIG(3, PBDIGITAL & LPT1DIS & MCLREN);
//// Config word 4
//__CONFIG(4, XINSTDIS & STVREN & LVPDIS & ICPORTDIS & DEBUGDIS);
//// Config word 5, 6 and 7 (protection configuration)
//__CONFIG(5, UNPROTECT);
//__CONFIG(6, UNPROTECT);
//__CONFIG(7, UNPROTECT);


/** Define Globals for main */
char potEnabled = 0;
char down = 0;
char stressTest = 1;
char counter = 0;

void configSystem(void){
	//IRCF2:IRFC0: Internal Oscillator Frequency select bits
	//111 => 8MHz
	IRCF0 = 1;
	IRCF1 = 1;
	IRCF2 = 1;
	
	//SCS1:SCS0: System Clock bits
	//1x => Internal oscillator
	SCS0 = 0;
	SCS1 = 0;
	
	//Set all pins to output and clear them
	TRISA = 0x00;
	TRISB = 0x00;
	TRISC = 0x00;
	TRISD = 0x00;
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
	
	//Enable digital outputs for PORTA
	ADCON1 = 0x0F;	
}

void configI2C(void){
	//Config Inputs
	TRISB |= 1 << 0;
	TRISB |= 1 << 1;

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

void configADC(void){
	//==CONFIGURE A/D==
	ADCON1 = 0b00001110; //configure AN0 and AN1 as analog inputs; rest are digital I/O
	ADCON2 = 0b10010101; //Set acquisition timer to Fosc/16 and Tacq to Tad*4
	TRISA |= 0 << 0;
	RA0 = 1; //set AN1:0 as inputs
	ADCON0 = 0b00000001; //turn A/D on, set to AN0 [5:2 = 0000] (AN1: [5:2 = 0001]
	
	//GO_nDONE = 1; //start A/D conversion
	//DelayUs(36);        // acquisition delay for chips that do not have it built in 
	//while(GO_nDONE == 10); //wait for A/D cycle to complete (in C a comparison is "==" a single = is an assignment)
	
	
	//PORTB = ADRESL;
	//RD0 = (ADRESH & 0b00000001);
	//RD1 = (ADRESH & 0b00000010)>>1;
		
}

void runADC(void){
	GO_nDONE = 1;
	while(GO_nDONE == 1);
	
	unsigned int result = ADRESH;
	result = result << 8;
	result += ADRESL;
	result = result/4;
	result++;
	result = result >> 2;
	dutyCycle1 = result;
}

char readADC(void){
	GO_nDONE = 1;
	while(GO_nDONE == 1);
	
	unsigned int result = ADRESH;
	result = result << 8;
	result += ADRESL;
	result = result/4;
	result++;
	//result = result >> 3;
	return result;
}

void runStressTest(void){
	while (!down){
			dutyCycle1++;
			dutyCycle2--;
			for(counter=0;counter<readADC();counter++){
				__delay_ms(1);
			}
			if (dutyCycle1 > 62) down = 1;
		}
		while (down){
			dutyCycle1--;
			dutyCycle2++;
			for(counter=0;counter<readADC();counter++){
				__delay_ms(1);
			}
			if (dutyCycle1 < 1) down = 0;
		}
}

void main(void) {
	RD2 = 1;
	configSystem();
	configSoftPWM();
	configI2C();
	configADC();
	
	while (1) {
		if(potEnabled) runADC();
		else if(stressTest) runStressTest();
#ifdef debug
		while (!down){
			dutyCycle1++;
			dutyCycle2--;
			__delay_ms(1);
			if (dutyCycle1 > 62) down = 1;
		}
		while (down){
			dutyCycle1--;
			dutyCycle2++;
			__delay_ms(1);
			if (dutyCycle1 < 1) down = 0;
		}
#endif
		
		//If command is supported
		if(newData){
			switch(i2c_rx_buff[0]){
				/****** Set Motor 1 Speed ********/
				case 0x00:
					dutyCycle1 = i2c_rx_buff[1];
					newData = 0;
				break;
				/****** Set Motor 2 Speed ********/
				case 0x01:
					dutyCycle2 = i2c_rx_buff[1];
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
				/****** Enable ADC ****************/
				case 0x99:
					potEnabled = i2c_rx_buff[1];
				break;
				default:
					RB4 = 1;
					newData = 0;
				break;
			}

		}
		//Unsupported command
		else RB4 = 1;
		//dutyCycle1 = i2c_rx_buff[0];
	}
}	