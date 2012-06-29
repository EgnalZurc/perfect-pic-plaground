
// Define oscillator frequency
#define _XTAL_FREQ 32000000

// Hardware mapping definitions
#define pwm1	RA0
#define pwm2	RA1
#define pwm4	RA2
#define pwm3	RA3
#define pwm5	RA7
#define pwm6	RA6
#define PWMMAX	31

// Globals for PWM
unsigned char pwmCounter = 0;

int dutyCycle1 = 0;
int dutyCycle2 = 0;
int dutyCycle3 = 0;
int dutyCycle4 = 0;
int dutyCycle5 = 0;
int dutyCycle6 = 0;
int maxDuty = 100;

struct motor {
	char dutyCycle1;
 	char dutyCycle2;
};

volatile int i2c_buff_index = 0;
volatile unsigned char i2c_rx_buff[2];
unsigned char i2c_tx_buff[2] = 0;
bit newData = 0;

unsigned char v_sspstat;

void configSoftPWM(void);
void configTimer(void);
void configI2C(void);