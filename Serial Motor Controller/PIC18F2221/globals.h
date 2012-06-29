#include <htc.h>

#define _XTAL_FREQ 32000000
#define SFLAG RB7
#define ENABLE RC5

/** Define Globals for main */
char potEnabled = 0;
char down = 0;
char stressTest = 1;
char counter = 0;