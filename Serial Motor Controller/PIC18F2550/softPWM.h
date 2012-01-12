
// Define oscillator frequency
#define _XTAL_FREQ 8000000

// Hardware mapping definitions
#define pwm1	RB2
#define pwm2	RB3
#define PWMMAX	63

// Globals for PWM
unsigned char pwmCounter = 0;

int dutyCycle1 = 0;
int dutyCycle2 = 0;

unsigned char v_sspstat;

void configSoftPWM(void);