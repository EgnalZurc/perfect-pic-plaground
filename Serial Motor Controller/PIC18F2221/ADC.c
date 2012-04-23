#include <htc.h>
	
#include "ADC.h"
#include "softPWM.h"

void configADC(void){
	//==CONFIGURE A/D==
	ADCON1 = 0b00000100; //configure AN10 as analog inputs;
	ADCON2 = 0b10010101; //Set acquisition timer to Fosc/16 and Tacq to Tad*4
	TRISB |= 0 << 1;
	RB1 = 1; //set AN1:0 as inputs
	ADCON0 = 0b00101000; //turn A/D on, set to AN10
	
	//GO_nDONE = 1; //start A/D conversion
	//DelayUs(36);        // acquisition delay for chips that do not have it built in 
	//while(GO_nDONE == 10); //wait for A/D cycle to complete (in C a comparison is "==" a single = is an assignment)
	
	
	//PORTB = ADRESL;
	//RD0 = (ADRESH & 0b00000001);
	//RD1 = (ADRESH & 0b00000010)>>1;		
}

void adcOff(void){
	//ADC Off
	ADCON0 = 0b00111100;
	//ADC to Digital
	ADCON1 = 0b00001111;
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