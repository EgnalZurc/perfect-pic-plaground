
// Define oscillator frequency
#define _XTAL_FREQ 8000000

// Hardware mapping definitions
#define pwm1	RB0
#define pwm2	RB2
#define PWMMAX	63

// Globals for PWM
unsigned char pwmCounter = 0;

int dutyCycle1 = 0;
int dutyCycle2 = PWMMAX;