
// Define oscillator frequency
#define _XTAL_FREQ 8000000

// Hardware mapping definitions
#define pwm1	RA0
#define pwm2	RA1
#define PWMMAX	63

// Globals for PWM
unsigned char pwmCounter = 0;

int dutyCycle1 = 32;
int dutyCycle2 = 32;

volatile int i2c_buff_index = 0;
volatile unsigned char i2c_rx_buff[2];
unsigned char i2c_tx_buff[2] = 0;
bit newData = 0;

unsigned char v_sspstat;

void configSoftPWM(void);