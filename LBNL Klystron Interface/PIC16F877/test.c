#case

#include <16F877.h>
#include <defs_877.h>
#include <lcd_out.h>
#include <stdlib.h>

#use delay(clock=20000000)
#use rs232(uart1, baud=9600, restart_wdt, parity=E, bits=8, timeout=200)
#fuses lp,wdt,put,noprotect
//LP: Low-Power crystal (In the datasheet, the highest LP crystal they used was 200kHz, so can we use 20MHz in this circuit?)
//WDT: Turn on Watchdog Timer
//PUT: Power-Up-Timer
//NOPROTECT: Don't use codeProtect

//PRINTF IS SOOOOO SLOW! DON'T USE IT IF YOU ARE WAITING FOR SOME SERIAL THAT WILL COME SOON!

void main(void) {
	lcd_init();																// initialize the LCD. It should be done before the ADC initialization
	lcd_clr_line(0);       													// clear line 0
	lcd_clr_line(1);       													// clear line 1
    lcd_clr_line(2);														// clear line 2
	setup_wdt(WDT_576MS);													// watchdog timer is 576 ms
    setup_adc_ports(AN0_AN1_VREF_VREF);     							    // RA0 and RA1 are ADC input, RA3 and RA2 set the limits 
	setup_adc(ADC_CLOCK_INTERNAL);											// internal clock for ADC
	set_adc_channel(1);														// RA1 enabled

	set_tris_c(0b10110110);
	set_tris_d(0b10000000);
	output_c(0x00);
	output_d(0x00);
	
	lcd_cursor_pos(3, 1);													// place cursor in line 3, position 1
	printf(lcd_char, "No Problems");

	while (1) {
		restart_wdt();
		delay_ms(20);
		restart_wdt();
	}
}

#include <lcd_out.c>