#case

#include <16F877.h>
#include <defs_877.h>
#include <lcd_out.h>

//PORTB
#define FAULT_LED 0
#define EXT_INTLK_LED 1
#define RF_INHIBIT_LED 2
#define LO_RF_LED 3
#define HI_RF_LED 4
#define FIL_TD_LED 5
#define LOCAL_LED 6
#define MANUAL_LED 7

//PORTD
#define HV_ON_LED 0
#define BEAM_REQST_LED 1
#define STANDBY_LED 2
#define COMM_PROBLEM PIN_D6

#define LAMP_TEST_SWTICH PIN_C5
#define KHPA_RESET_SWITCH PIN_C1
#define HV_ON_SWITCH PIN_C4
#define HV_OFF_SWITCH PIN_C2

#define KHPA_OLD_NEW_SWITCH PIN_D7

#define STX 0x02
#define ETX 0x03
#define ADDRESS 0x31
#define ACK 0x06
#define NAK 0x15

#use delay(clock=20000000)
#use rs232(uart1, baud=9600, restart_wdt, parity=E, bits=8, timeout=300)
#fuses lp,wdt,put,noprotect
//LP: Low-Power crystal (In the datasheet, the highest LP crystal they used was 200kHz, so can we use 20MHz in this circuit?)
//WDT: Turn on Watchdog Timer
//PUT: Power-Up-Timer
//NOPROTECT: Don't use codeProtect

//LCD LINE 0: SIGNAL START OF PROGRAM (IF THIS IS BLINKING, WATCHDOG TIMER IS RESETTING)
//LCD LINE 1: LOW/HIGH LEVEL COMMUNICATION ERROR/SUCCESS WITH HIGH LEVEL (IF IT WAS A HIGH LEVEL ERROR) DETAIL
//LCD LINE 2: LOW LEVEL COMMUNICATION ERROR (NOT ALL BITS RECEIVED CORRECTLY) DETAIL
//LCD LINE 3: DIGITAL KHPA STATUS

//Different errors while receiving a command
enum RECV_ERRORS {
	NO_ERROR=0,
	ACK_MISMATCH,
	NO_ETX,
	GETC_TIMEOUT,
	ADDRESS_MISMATCH,
	COMMAND_MISMATCH,
	CHECKSUM_MISMATCH,
	COMMAND_NOT_RECOGNIZED,
	ILLEGAL_PARAM,
	CIF_DISABLED,
	SYSTEM_ERROR,
	CANNOT_EXECUTE
};

unsigned char receive_response(unsigned char *response, unsigned char *responseSize, unsigned char lastCommand) {
	unsigned char i;
	unsigned char recvString[16], *recvPtr = &recvString[0];
	unsigned char check, computedCheck;
	unsigned char rejectCode = 0;
	
	for (i=0;(recvString[i]=getc());i++) {
		if (recvString[i] == ETX) {
			recvString[++i] = getc();//Checksum
			break;
		}
		restart_wdt();
	}
	
	restart_wdt();
	lcd_cursor_pos(1, 6);
	printf("               ");	//Clear the details of the last error, but keep the fact that there was an error/success
	lcd_clr_line(2);		//Clear messy low-level comm errors from the screen
	lcd_cursor_pos(2, 0);	//Besides the NAK error, all are low-level
	
	if (!recvString[i] && recvString[i-1]!=ETX) {	//If the last character received is 0 and it is not a checksum (checksums can be zero)	
		printf(lcd_char, "TOUT %d", i);				//getc() returns 0 when it times out waiting for more data
		return GETC_TIMEOUT;
	}

	if (*recvPtr != ACK) {
		if (*recvPtr == NAK) {						//If there is an error in processing the command, the KHPA will send a NAK
			rejectCode = recvString[3];
			lcd_cursor_pos(1, 6);			//Place cursor in line 2, position 6
			switch (rejectCode) {
				case 'a':
					printf(lcd_char, "COMMAND !REC");
					return COMMAND_NOT_RECOGNIZED;
				case 'b':
					printf(lcd_char, "ILLEGAL PARAM");
					return ILLEGAL_PARAM;
				case 'c':
					printf(lcd_char, "CIF DISABLED");
					return CIF_DISABLED;
				case 'e':
					printf(lcd_char, "SYSTEM ERROR");
					return SYSTEM_ERROR;
				case 'h':
					printf(lcd_char, "CANNOT EXE");
					return CANNOT_EXECUTE;
				default:
					printf(lcd_char, "UNKNOWN ERROR");
					break;
			}
			return rejectCode;
		}
		
		printf(lcd_char, "ACK:%d, rec:%d", ACK, *recvPtr);		//If the KHPA returns something besides ACK or NAK, there is an error
		return ACK_MISMATCH;
	}

	recvPtr++;

	if (*recvPtr != ADDRESS) {
		printf(lcd_char, "ADD:%d, rec:%d", ADDRESS, *recvPtr);	//The KHPA must return the same address that we designated

		return ADDRESS_MISMATCH;
	}

	recvPtr++;

	if (*recvPtr != lastCommand) {
		printf(lcd_char, "com:%d, rec:%d", lastCommand, *recvPtr);	//The KHPA must return the same command we sent

		return COMMAND_MISMATCH;
	}
	//Now that we got all the correct starting bits, we must get the data
	
	recvPtr++;
	for (i=0;*recvPtr!=ETX;i++)
		response[i] = *(recvPtr++);
	*responseSize = i;
	recvPtr++;
	
	//After we received the data, we will get a checkbyte which is either Longitudinal or Checksum

	check = *recvPtr;

	//We assume it is Longitudinal
	
	computedCheck = 0;
	computedCheck ^= ACK;
	computedCheck ^= ADDRESS;
	computedCheck ^= lastCommand;
	for (i=0;i<*responseSize;i++)
		computedCheck ^= response[i];
	computedCheck ^= ETX;

	if (check != computedCheck) {
		printf(lcd_char, "check:%u, rec:%u", computedCheck, check);		//If the checkbyte is not the same as the calculated one, there must have been an error
		return CHECKSUM_MISMATCH;
	}

	restart_wdt();

	//All the errors that could have happened have already happened, so the communication must be valid
	return NO_ERROR;
}

void send_command(char command) {
	unsigned char message[5];			//The max size of our messages is 5 bytes
	unsigned char check;				//Holds the checksum
	const unsigned char size = 5;		//There are 5 bytes in our commands
	unsigned char i;
	
	//The message must have this format {STX, ADDRESS, COMMAND, ETX, CHECK}
	message[0] = STX;
	message[1] = ADDRESS;
	message[2] = command;
	message[3] = ETX;
	
	check = 0;
	for (i=0;i<4;i++) {
		check ^= message[i];
	}
	message[4] = check;
	
	//Send the message byte by byte
	for (i=0;i<size;i++) {
		putc(message[i]);
		restart_wdt();
	}
}

void lampTest(void) {
	int16 ledPin;

	//PORTB and PORTD control the status LEDs, so we toggle each pin
	output_b(0b00000000);
	output_d(0b00000000);

	for (ledPin=FAULT_LED;ledPin<=MANUAL_LED;ledPin++) {
		output_b(1<<ledPin);
		delay_ms(200);
		restart_wdt();
	}
	
	output_b(0b00000000);

	for (ledPin=HV_ON_LED;ledPin<=STANDBY_LED;ledPin++) {
		output_d(1<<ledPin);
		delay_ms(50);
		restart_wdt();
	}
	
	output_b(0b00000000);
	output_d(0b00000000);
}

void checkKlystronStatus(void) {
	//d: filament time-delay	0
	//f: fault summary			1
	//i: rf inhibit				2
	//u: beam request			3
	//l: low rf					4
	//h: high rf				5
	//c: local					6
	//m: manual					7
	//o: hv on					8
	//k: external interlock		9
	//s: standby				10
	
	char klystron_status_string[16][2] = { "d", "f", "i", "u", "l", "h", "c", "m", "o", "k", "s" };
	unsigned char command;
	unsigned char response[16], response_size;
	unsigned char newPortD = 0, newPortB = 0;		//We use these variables so that we only update PORTB and PORTD once, eliminating read-modify-write errors
	
	restart_wdt();
	lcd_cursor_pos(3, 0);													// place cursor in line 3, position 0
	for (command='1';command<='3';command++) {
		send_command(command);
		if (!receive_response(response, &response_size, command)) {
			output_low(COMM_PROBLEM);		//If there is no communication problem, the LED should not be on
			restart_wdt();
			if (command == '1') {
				newPortD |= ((response[1] & 0b00000001)!=0) << HV_ON_LED;
				newPortD |= ((response[1] & 0b00000010)!=0) << STANDBY_LED;
				newPortD |= ((response[1] & 0b00000100)!=0) << BEAM_REQST_LED;
				
				newPortB |= ((response[1] & 0b00001000)!=0) << FAULT_LED;
				newPortB |= ((response[1] & 0b00100000)!=0) << RF_INHIBIT_LED;
				
				//Multiply the beginning of the string by 1 (doesn't affect the output), or by 0 (turns the first character into a NULL, which terminates the string)
				klystron_status_string[8][0] *= ((response[1] & 0b00000001)!=0);
				klystron_status_string[10][0] *= ((response[1] & 0b00000010)!=0);
				klystron_status_string[3][0] *= ((response[1] & 0b00000100)!=0);
				klystron_status_string[1][0] *= ((response[1] & 0b00001000)!=0);
				klystron_status_string[2][0] *= ((response[1] & 0b00100000)!=0);
			} else if (command == '2') {
				newPortB |= ((response[0] & 0b00000001)!=0) << LO_RF_LED;
				newPortB |= ((response[0] & 0b00000010)!=0) << HI_RF_LED;
				newPortB |= ((response[0] & 0b00000100)!=0) << FIL_TD_LED;
				newPortB |= ((response[0] & 0b00010000)==0) << LOCAL_LED;
				newPortB |= ((response[0] & 0b00010000)!=0) << MANUAL_LED;
				
				//Multiply the beginning of the string by 1 (doesn't affect the output), or by 0 (turns the first character into a NULL, which terminates the string)
				klystron_status_string[4][0] *= ((response[0] & 0b00000001)!=0);
				klystron_status_string[5][0] *= ((response[0] & 0b00000010)!=0);
				klystron_status_string[0][0] *= ((response[0] & 0b00000100)!=0);
				klystron_status_string[6][0] *= ((response[0] & 0b00010000)==0);
				klystron_status_string[7][0] *= ((response[0] & 0b00010000)!=0);
			} else if (command == '3') {
				newPortB |= ((response[0] & 0b00000010)!=0) << EXT_INTLK_LED;
				
				//Multiply the beginning of the string by 1 (doesn't affect the output), or by 0 (turns the first character into a NULL, which terminates the string)
				klystron_status_string[9][0] *= ((response[0] & 0b00000010)!=0);
			}
		} else {
			newPortB = 0;
			output_high(COMM_PROBLEM);		//Let the user know about a communication problem
			restart_wdt();
			lcd_clr_line(1);				//Just in case any old errors wrote something to line 1 (the high-level communication error detail)
			lcd_cursor_pos(1, 0);
			printf(lcd_char, "'%c' U ", command);
			return;
		}
	}

	//Write the state of the KHPA on the back LCD
	restart_wdt();
	lcd_cursor_pos(3, 0);
	printf(lcd_char, "%s%s%s%s%s%s%s%s%s%s%s         ", klystron_status_string[0], klystron_status_string[1], klystron_status_string[2], 
										   	klystron_status_string[3], klystron_status_string[4], klystron_status_string[5], 
											klystron_status_string[6], klystron_status_string[7], klystron_status_string[8],
											klystron_status_string[9], klystron_status_string[10]);
										
	//Only modify PORTB and PORTD once, eliminating read-modify-write errors
	output_b(newPortB);
	output_d(newPortD);
}

void checkButtons(void) {
	unsigned char response[16], response_size, command = 0;
	
	//Check each switch and execute those commands
	if (input(KHPA_RESET_SWITCH))
		command = 'B';
	else if (input(HV_ON_SWITCH))
		command = '@';
	else if (input(HV_OFF_SWITCH))
		command = 'A';
	else if (input(LAMP_TEST_SWTICH))
		lampTest();
	
	output_low(PIN_C3);	//End latch on buttons
	if (command) {
		send_command(command);
	
		if (!receive_response(response, &response_size, command)) {
			if (!response_size) {
				output_low(COMM_PROBLEM);	//If there is no communication problem, the LED should not be on
				restart_wdt();
				lcd_clr_line(2);	//Just in case any old errors wrote something to line 1 (the high-level communication error detail)
				lcd_cursor_pos(1, 0);
				printf(lcd_char, "'%c' s ", command);
			}
		} else {
			output_high(COMM_PROBLEM);		//Let the user know about a communication problem
			restart_wdt();
			lcd_cursor_pos(1, 0);
			printf(lcd_char, "'%c' U ", command);
		}	
	}
	restart_wdt();
	delay_ms(10);
	output_high(PIN_C3);	//Start latch on Buttons
}

void main(void) {
	set_tris_c(0b10110110);
	set_tris_d(0b10000000);
	output_c(0x00);
	output_d(0x00);
	
	lcd_init();																// initialize the LCD. It should be done before the ADC initialization
	lcd_clr_line(0);       													// clear line 0
	lcd_clr_line(1);       													// clear line 1
    lcd_clr_line(2);														// clear line 2
    lcd_cursor_pos(0, 0);													// place cursor in line 3, position 0
	printf(lcd_char, "OLD KHPA");											// waiting for the new KHPA to be used
	
	setup_wdt(WDT_576MS);													// watchdog timer is 576 ms
    setup_adc_ports(AN0_AN1_VREF_VREF);     							    // RA0 and RA1 are ADC input, RA3 and RA2 set the limits 
	setup_adc(ADC_CLOCK_INTERNAL);											// internal clock for ADC
	set_adc_channel(1);	
	
	restart_wdt();
	delay_ms(200);
	restart_wdt();
	delay_ms(500);
	restart_wdt();
	
	while (!input(PIN_D7)) {												// waiting until the new KHPA is being used
		delay_ms(1);
		restart_wdt();
	}

	restart_wdt();
	
	lcd_clr_line(0);       													// clear line 0
	lcd_clr_line(1);       													// clear line 1
    lcd_clr_line(2);														// clear line 2
    lcd_cursor_pos(0, 0);													// place cursor in line 3, position 0
	printf(lcd_char, "NEW KHPA");

	output_c(0x00);
	output_d(0x00);
	
	restart_wdt();
	delay_ms(477);
	restart_wdt();
	
	output_c(0b00001000);

	//Make sure the switches are inputs
	input(LAMP_TEST_SWTICH);
	input(KHPA_RESET_SWITCH);
	input(HV_ON_SWITCH);
	input(HV_OFF_SWITCH);

	input(PIN_C7);															// serial receive pin must be set to input
	
	restart_wdt();

	while (input(PIN_D7)) {
		checkKlystronStatus();												// update LEDs
		checkButtons();														// see if any commands need to be issued

		delay_ms(1);
		restart_wdt();
	}
}

#include <lcd_out.c>