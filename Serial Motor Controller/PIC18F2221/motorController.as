opt subtitle "HI-TECH Software Omniscient Code Generator (Lite mode) build 11162"

opt pagewidth 120

	opt lm

	processor	18F2221
porta	equ	0F80h
portb	equ	0F81h
portc	equ	0F82h
portd	equ	0F83h
porte	equ	0F84h
lata	equ	0F89h
latb	equ	0F8Ah
latc	equ	0F8Bh
latd	equ	0F8Ch
late	equ	0F8Dh
trisa	equ	0F92h
trisb	equ	0F93h
trisc	equ	0F94h
trisd	equ	0F95h
trise	equ	0F96h
pie1	equ	0F9Dh
pir1	equ	0F9Eh
ipr1	equ	0F9Fh
pie2	equ	0FA0h
pir2	equ	0FA1h
ipr2	equ	0FA2h
t3con	equ	0FB1h
tmr3l	equ	0FB2h
tmr3h	equ	0FB3h
ccp1con	equ	0FBDh
ccpr1l	equ	0FBEh
ccpr1h	equ	0FBFh
adcon1	equ	0FC1h
adcon0	equ	0FC2h
adresl	equ	0FC3h
adresh	equ	0FC4h
sspcon2	equ	0FC5h
sspcon1	equ	0FC6h
sspstat	equ	0FC7h
sspadd	equ	0FC8h
sspbuf	equ	0FC9h
t2con	equ	0FCAh
pr2	equ	0FCBh
tmr2	equ	0FCCh
t1con	equ	0FCDh
tmr1l	equ	0FCEh
tmr1h	equ	0FCFh
rcon	equ	0FD0h
wdtcon	equ	0FD1h
lvdcon	equ	0FD2h
osccon	equ	0FD3h
t0con	equ	0FD5h
tmr0l	equ	0FD6h
tmr0h	equ	0FD7h
status	equ	0FD8h
fsr2	equ	0FD9h
fsr2l	equ	0FD9h
fsr2h	equ	0FDAh
plusw2	equ	0FDBh
preinc2	equ	0FDCh
postdec2	equ	0FDDh
postinc2	equ	0FDEh
indf2	equ	0FDFh
bsr	equ	0FE0h
fsr1	equ	0FE1h
fsr1l	equ	0FE1h
fsr1h	equ	0FE2h
plusw1	equ	0FE3h
preinc1	equ	0FE4h
postdec1	equ	0FE5h
postinc1	equ	0FE6h
indf1	equ	0FE7h
wreg	equ	0FE8h
fsr0	equ	0FE9h
fsr0l	equ	0FE9h
fsr0h	equ	0FEAh
plusw0	equ	0FEBh
preinc0	equ	0FECh
postdec0	equ	0FEDh
postinc0	equ	0FEEh
indf0	equ	0FEFh
intcon3	equ	0FF0h
intcon2	equ	0FF1h
intcon	equ	0FF2h
prod	equ	0FF3h
prodl	equ	0FF3h
prodh	equ	0FF4h
tablat	equ	0FF5h
tblptr	equ	0FF6h
tblptrl	equ	0FF6h
tblptrh	equ	0FF7h
tblptru	equ	0FF8h
pcl	equ	0FF9h
pclat	equ	0FFAh
pclath	equ	0FFAh
pclatu	equ	0FFBh
stkptr	equ	0FFCh
tosl	equ	0FFDh
tosh	equ	0FFEh
tosu	equ	0FFFh
skipnz macro
	btfsc	status,2
	endm
	global	__ramtop
	global	__accesstop
# 19 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PORTA equ 0F80h ;# 
# 90 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PORTB equ 0F81h ;# 
# 139 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PORTC equ 0F82h ;# 
# 192 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PORTE equ 0F84h ;# 
# 317 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
LATA equ 0F89h ;# 
# 370 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
LATB equ 0F8Ah ;# 
# 423 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
LATC equ 0F8Bh ;# 
# 476 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TRISA equ 0F92h ;# 
# 481 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
DDRA equ 0F92h ;# 
# 539 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TRISB equ 0F93h ;# 
# 544 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
DDRB equ 0F93h ;# 
# 602 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TRISC equ 0F94h ;# 
# 607 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
DDRC equ 0F94h ;# 
# 665 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
OSCTUNE equ 0F9Bh ;# 
# 687 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PIE1 equ 0F9Dh ;# 
# 713 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PIR1 equ 0F9Eh ;# 
# 747 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
IPR1 equ 0F9Fh ;# 
# 773 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PIE2 equ 0FA0h ;# 
# 796 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PIR2 equ 0FA1h ;# 
# 819 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
IPR2 equ 0FA2h ;# 
# 842 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
EECON1 equ 0FA6h ;# 
# 865 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
EECON2 equ 0FA7h ;# 
# 877 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
EEDATA equ 0FA8h ;# 
# 889 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
EEADR equ 0FA9h ;# 
# 901 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
RCSTA equ 0FABh ;# 
# 906 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
RCSTA1 equ 0FABh ;# 
# 954 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TXSTA equ 0FACh ;# 
# 959 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TXSTA1 equ 0FACh ;# 
# 1053 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TXREG equ 0FADh ;# 
# 1058 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TXREG1 equ 0FADh ;# 
# 1076 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
RCREG equ 0FAEh ;# 
# 1081 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
RCREG1 equ 0FAEh ;# 
# 1099 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SPBRG equ 0FAFh ;# 
# 1104 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SPBRG1 equ 0FAFh ;# 
# 1122 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SPBRGH equ 0FB0h ;# 
# 1134 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
T3CON equ 0FB1h ;# 
# 1175 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR3 equ 0FB2h ;# 
# 1187 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR3L equ 0FB2h ;# 
# 1199 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR3H equ 0FB3h ;# 
# 1211 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CMCON equ 0FB4h ;# 
# 1244 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CVRCON equ 0FB5h ;# 
# 1270 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ECCP1AS equ 0FB6h ;# 
# 1293 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ECCP1DEL equ 0FB7h ;# 
# 1298 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PWM1CON equ 0FB7h ;# 
# 1318 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
BAUDCON equ 0FB8h ;# 
# 1323 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
BAUDCTL equ 0FB8h ;# 
# 1383 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCP2CON equ 0FBAh ;# 
# 1409 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR2 equ 0FBBh ;# 
# 1421 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR2L equ 0FBBh ;# 
# 1433 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR2H equ 0FBCh ;# 
# 1445 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCP1CON equ 0FBDh ;# 
# 1450 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ECCP1CON equ 0FBDh ;# 
# 1496 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR1 equ 0FBEh ;# 
# 1508 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR1L equ 0FBEh ;# 
# 1520 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR1H equ 0FBFh ;# 
# 1532 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADCON2 equ 0FC0h ;# 
# 1555 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADCON1 equ 0FC1h ;# 
# 1588 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADCON0 equ 0FC2h ;# 
# 1643 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADRES equ 0FC3h ;# 
# 1655 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADRESL equ 0FC3h ;# 
# 1667 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADRESH equ 0FC4h ;# 
# 1679 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SSPCON2 equ 0FC5h ;# 
# 1706 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SSPCON1 equ 0FC6h ;# 
# 1728 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SSPSTAT equ 0FC7h ;# 
# 1835 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SSPADD equ 0FC8h ;# 
# 1847 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SSPBUF equ 0FC9h ;# 
# 1859 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
T2CON equ 0FCAh ;# 
# 1889 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PR2 equ 0FCBh ;# 
# 1894 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
MEMCON equ 0FCBh ;# 
# 1912 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR2 equ 0FCCh ;# 
# 1924 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
T1CON equ 0FCDh ;# 
# 1961 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR1 equ 0FCEh ;# 
# 1973 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR1L equ 0FCEh ;# 
# 1985 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR1H equ 0FCFh ;# 
# 1997 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
RCON equ 0FD0h ;# 
# 2043 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
WDTCON equ 0FD1h ;# 
# 2058 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
HLVDCON equ 0FD2h ;# 
# 2063 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
LVDCON equ 0FD2h ;# 
# 2131 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
OSCCON equ 0FD3h ;# 
# 2156 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
T0CON equ 0FD5h ;# 
# 2180 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR0 equ 0FD6h ;# 
# 2192 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR0L equ 0FD6h ;# 
# 2204 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR0H equ 0FD7h ;# 
# 2216 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
STATUS equ 0FD8h ;# 
# 2247 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR2 equ 0FD9h ;# 
# 2259 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR2L equ 0FD9h ;# 
# 2271 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR2H equ 0FDAh ;# 
# 2283 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PLUSW2 equ 0FDBh ;# 
# 2295 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PREINC2 equ 0FDCh ;# 
# 2307 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTDEC2 equ 0FDDh ;# 
# 2319 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTINC2 equ 0FDEh ;# 
# 2331 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INDF2 equ 0FDFh ;# 
# 2343 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
BSR equ 0FE0h ;# 
# 2355 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR1 equ 0FE1h ;# 
# 2367 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR1L equ 0FE1h ;# 
# 2379 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR1H equ 0FE2h ;# 
# 2391 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PLUSW1 equ 0FE3h ;# 
# 2403 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PREINC1 equ 0FE4h ;# 
# 2415 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTDEC1 equ 0FE5h ;# 
# 2427 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTINC1 equ 0FE6h ;# 
# 2439 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INDF1 equ 0FE7h ;# 
# 2451 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
WREG equ 0FE8h ;# 
# 2474 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR0 equ 0FE9h ;# 
# 2486 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR0L equ 0FE9h ;# 
# 2498 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR0H equ 0FEAh ;# 
# 2510 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PLUSW0 equ 0FEBh ;# 
# 2522 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PREINC0 equ 0FECh ;# 
# 2534 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTDEC0 equ 0FEDh ;# 
# 2546 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTINC0 equ 0FEEh ;# 
# 2558 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INDF0 equ 0FEFh ;# 
# 2570 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INTCON3 equ 0FF0h ;# 
# 2599 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INTCON2 equ 0FF1h ;# 
# 2626 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INTCON equ 0FF2h ;# 
# 2690 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PROD equ 0FF3h ;# 
# 2702 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PRODL equ 0FF3h ;# 
# 2714 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PRODH equ 0FF4h ;# 
# 2726 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TABLAT equ 0FF5h ;# 
# 2738 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TBLPTR equ 0FF6h ;# 
# 2751 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TBLPTRL equ 0FF6h ;# 
# 2763 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TBLPTRH equ 0FF7h ;# 
# 2775 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TBLPTRU equ 0FF8h ;# 
# 2788 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PCLAT equ 0FF9h ;# 
# 2793 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PC equ 0FF9h ;# 
# 2811 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PCL equ 0FF9h ;# 
# 2823 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PCLATH equ 0FFAh ;# 
# 2835 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PCLATU equ 0FFBh ;# 
# 2847 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
STKPTR equ 0FFCh ;# 
# 2871 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TOS equ 0FFDh ;# 
# 2883 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TOSL equ 0FFDh ;# 
# 2895 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TOSH equ 0FFEh ;# 
# 2907 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TOSU equ 0FFFh ;# 
# 19 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PORTA equ 0F80h ;# 
# 90 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PORTB equ 0F81h ;# 
# 139 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PORTC equ 0F82h ;# 
# 192 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PORTE equ 0F84h ;# 
# 317 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
LATA equ 0F89h ;# 
# 370 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
LATB equ 0F8Ah ;# 
# 423 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
LATC equ 0F8Bh ;# 
# 476 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TRISA equ 0F92h ;# 
# 481 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
DDRA equ 0F92h ;# 
# 539 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TRISB equ 0F93h ;# 
# 544 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
DDRB equ 0F93h ;# 
# 602 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TRISC equ 0F94h ;# 
# 607 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
DDRC equ 0F94h ;# 
# 665 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
OSCTUNE equ 0F9Bh ;# 
# 687 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PIE1 equ 0F9Dh ;# 
# 713 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PIR1 equ 0F9Eh ;# 
# 747 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
IPR1 equ 0F9Fh ;# 
# 773 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PIE2 equ 0FA0h ;# 
# 796 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PIR2 equ 0FA1h ;# 
# 819 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
IPR2 equ 0FA2h ;# 
# 842 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
EECON1 equ 0FA6h ;# 
# 865 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
EECON2 equ 0FA7h ;# 
# 877 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
EEDATA equ 0FA8h ;# 
# 889 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
EEADR equ 0FA9h ;# 
# 901 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
RCSTA equ 0FABh ;# 
# 906 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
RCSTA1 equ 0FABh ;# 
# 954 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TXSTA equ 0FACh ;# 
# 959 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TXSTA1 equ 0FACh ;# 
# 1053 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TXREG equ 0FADh ;# 
# 1058 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TXREG1 equ 0FADh ;# 
# 1076 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
RCREG equ 0FAEh ;# 
# 1081 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
RCREG1 equ 0FAEh ;# 
# 1099 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SPBRG equ 0FAFh ;# 
# 1104 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SPBRG1 equ 0FAFh ;# 
# 1122 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SPBRGH equ 0FB0h ;# 
# 1134 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
T3CON equ 0FB1h ;# 
# 1175 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR3 equ 0FB2h ;# 
# 1187 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR3L equ 0FB2h ;# 
# 1199 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR3H equ 0FB3h ;# 
# 1211 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CMCON equ 0FB4h ;# 
# 1244 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CVRCON equ 0FB5h ;# 
# 1270 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ECCP1AS equ 0FB6h ;# 
# 1293 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ECCP1DEL equ 0FB7h ;# 
# 1298 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PWM1CON equ 0FB7h ;# 
# 1318 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
BAUDCON equ 0FB8h ;# 
# 1323 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
BAUDCTL equ 0FB8h ;# 
# 1383 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCP2CON equ 0FBAh ;# 
# 1409 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR2 equ 0FBBh ;# 
# 1421 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR2L equ 0FBBh ;# 
# 1433 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR2H equ 0FBCh ;# 
# 1445 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCP1CON equ 0FBDh ;# 
# 1450 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ECCP1CON equ 0FBDh ;# 
# 1496 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR1 equ 0FBEh ;# 
# 1508 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR1L equ 0FBEh ;# 
# 1520 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR1H equ 0FBFh ;# 
# 1532 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADCON2 equ 0FC0h ;# 
# 1555 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADCON1 equ 0FC1h ;# 
# 1588 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADCON0 equ 0FC2h ;# 
# 1643 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADRES equ 0FC3h ;# 
# 1655 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADRESL equ 0FC3h ;# 
# 1667 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADRESH equ 0FC4h ;# 
# 1679 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SSPCON2 equ 0FC5h ;# 
# 1706 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SSPCON1 equ 0FC6h ;# 
# 1728 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SSPSTAT equ 0FC7h ;# 
# 1835 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SSPADD equ 0FC8h ;# 
# 1847 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SSPBUF equ 0FC9h ;# 
# 1859 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
T2CON equ 0FCAh ;# 
# 1889 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PR2 equ 0FCBh ;# 
# 1894 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
MEMCON equ 0FCBh ;# 
# 1912 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR2 equ 0FCCh ;# 
# 1924 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
T1CON equ 0FCDh ;# 
# 1961 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR1 equ 0FCEh ;# 
# 1973 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR1L equ 0FCEh ;# 
# 1985 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR1H equ 0FCFh ;# 
# 1997 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
RCON equ 0FD0h ;# 
# 2043 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
WDTCON equ 0FD1h ;# 
# 2058 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
HLVDCON equ 0FD2h ;# 
# 2063 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
LVDCON equ 0FD2h ;# 
# 2131 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
OSCCON equ 0FD3h ;# 
# 2156 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
T0CON equ 0FD5h ;# 
# 2180 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR0 equ 0FD6h ;# 
# 2192 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR0L equ 0FD6h ;# 
# 2204 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR0H equ 0FD7h ;# 
# 2216 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
STATUS equ 0FD8h ;# 
# 2247 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR2 equ 0FD9h ;# 
# 2259 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR2L equ 0FD9h ;# 
# 2271 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR2H equ 0FDAh ;# 
# 2283 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PLUSW2 equ 0FDBh ;# 
# 2295 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PREINC2 equ 0FDCh ;# 
# 2307 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTDEC2 equ 0FDDh ;# 
# 2319 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTINC2 equ 0FDEh ;# 
# 2331 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INDF2 equ 0FDFh ;# 
# 2343 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
BSR equ 0FE0h ;# 
# 2355 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR1 equ 0FE1h ;# 
# 2367 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR1L equ 0FE1h ;# 
# 2379 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR1H equ 0FE2h ;# 
# 2391 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PLUSW1 equ 0FE3h ;# 
# 2403 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PREINC1 equ 0FE4h ;# 
# 2415 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTDEC1 equ 0FE5h ;# 
# 2427 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTINC1 equ 0FE6h ;# 
# 2439 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INDF1 equ 0FE7h ;# 
# 2451 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
WREG equ 0FE8h ;# 
# 2474 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR0 equ 0FE9h ;# 
# 2486 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR0L equ 0FE9h ;# 
# 2498 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR0H equ 0FEAh ;# 
# 2510 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PLUSW0 equ 0FEBh ;# 
# 2522 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PREINC0 equ 0FECh ;# 
# 2534 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTDEC0 equ 0FEDh ;# 
# 2546 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTINC0 equ 0FEEh ;# 
# 2558 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INDF0 equ 0FEFh ;# 
# 2570 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INTCON3 equ 0FF0h ;# 
# 2599 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INTCON2 equ 0FF1h ;# 
# 2626 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INTCON equ 0FF2h ;# 
# 2690 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PROD equ 0FF3h ;# 
# 2702 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PRODL equ 0FF3h ;# 
# 2714 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PRODH equ 0FF4h ;# 
# 2726 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TABLAT equ 0FF5h ;# 
# 2738 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TBLPTR equ 0FF6h ;# 
# 2751 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TBLPTRL equ 0FF6h ;# 
# 2763 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TBLPTRH equ 0FF7h ;# 
# 2775 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TBLPTRU equ 0FF8h ;# 
# 2788 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PCLAT equ 0FF9h ;# 
# 2793 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PC equ 0FF9h ;# 
# 2811 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PCL equ 0FF9h ;# 
# 2823 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PCLATH equ 0FFAh ;# 
# 2835 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PCLATU equ 0FFBh ;# 
# 2847 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
STKPTR equ 0FFCh ;# 
# 2871 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TOS equ 0FFDh ;# 
# 2883 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TOSL equ 0FFDh ;# 
# 2895 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TOSH equ 0FFEh ;# 
# 2907 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TOSU equ 0FFFh ;# 
# 19 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PORTA equ 0F80h ;# 
# 90 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PORTB equ 0F81h ;# 
# 139 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PORTC equ 0F82h ;# 
# 192 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PORTE equ 0F84h ;# 
# 317 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
LATA equ 0F89h ;# 
# 370 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
LATB equ 0F8Ah ;# 
# 423 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
LATC equ 0F8Bh ;# 
# 476 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TRISA equ 0F92h ;# 
# 481 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
DDRA equ 0F92h ;# 
# 539 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TRISB equ 0F93h ;# 
# 544 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
DDRB equ 0F93h ;# 
# 602 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TRISC equ 0F94h ;# 
# 607 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
DDRC equ 0F94h ;# 
# 665 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
OSCTUNE equ 0F9Bh ;# 
# 687 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PIE1 equ 0F9Dh ;# 
# 713 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PIR1 equ 0F9Eh ;# 
# 747 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
IPR1 equ 0F9Fh ;# 
# 773 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PIE2 equ 0FA0h ;# 
# 796 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PIR2 equ 0FA1h ;# 
# 819 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
IPR2 equ 0FA2h ;# 
# 842 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
EECON1 equ 0FA6h ;# 
# 865 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
EECON2 equ 0FA7h ;# 
# 877 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
EEDATA equ 0FA8h ;# 
# 889 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
EEADR equ 0FA9h ;# 
# 901 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
RCSTA equ 0FABh ;# 
# 906 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
RCSTA1 equ 0FABh ;# 
# 954 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TXSTA equ 0FACh ;# 
# 959 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TXSTA1 equ 0FACh ;# 
# 1053 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TXREG equ 0FADh ;# 
# 1058 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TXREG1 equ 0FADh ;# 
# 1076 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
RCREG equ 0FAEh ;# 
# 1081 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
RCREG1 equ 0FAEh ;# 
# 1099 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SPBRG equ 0FAFh ;# 
# 1104 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SPBRG1 equ 0FAFh ;# 
# 1122 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SPBRGH equ 0FB0h ;# 
# 1134 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
T3CON equ 0FB1h ;# 
# 1175 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR3 equ 0FB2h ;# 
# 1187 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR3L equ 0FB2h ;# 
# 1199 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR3H equ 0FB3h ;# 
# 1211 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CMCON equ 0FB4h ;# 
# 1244 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CVRCON equ 0FB5h ;# 
# 1270 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ECCP1AS equ 0FB6h ;# 
# 1293 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ECCP1DEL equ 0FB7h ;# 
# 1298 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PWM1CON equ 0FB7h ;# 
# 1318 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
BAUDCON equ 0FB8h ;# 
# 1323 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
BAUDCTL equ 0FB8h ;# 
# 1383 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCP2CON equ 0FBAh ;# 
# 1409 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR2 equ 0FBBh ;# 
# 1421 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR2L equ 0FBBh ;# 
# 1433 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR2H equ 0FBCh ;# 
# 1445 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCP1CON equ 0FBDh ;# 
# 1450 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ECCP1CON equ 0FBDh ;# 
# 1496 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR1 equ 0FBEh ;# 
# 1508 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR1L equ 0FBEh ;# 
# 1520 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
CCPR1H equ 0FBFh ;# 
# 1532 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADCON2 equ 0FC0h ;# 
# 1555 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADCON1 equ 0FC1h ;# 
# 1588 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADCON0 equ 0FC2h ;# 
# 1643 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADRES equ 0FC3h ;# 
# 1655 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADRESL equ 0FC3h ;# 
# 1667 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
ADRESH equ 0FC4h ;# 
# 1679 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SSPCON2 equ 0FC5h ;# 
# 1706 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SSPCON1 equ 0FC6h ;# 
# 1728 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SSPSTAT equ 0FC7h ;# 
# 1835 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SSPADD equ 0FC8h ;# 
# 1847 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
SSPBUF equ 0FC9h ;# 
# 1859 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
T2CON equ 0FCAh ;# 
# 1889 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PR2 equ 0FCBh ;# 
# 1894 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
MEMCON equ 0FCBh ;# 
# 1912 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR2 equ 0FCCh ;# 
# 1924 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
T1CON equ 0FCDh ;# 
# 1961 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR1 equ 0FCEh ;# 
# 1973 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR1L equ 0FCEh ;# 
# 1985 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR1H equ 0FCFh ;# 
# 1997 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
RCON equ 0FD0h ;# 
# 2043 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
WDTCON equ 0FD1h ;# 
# 2058 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
HLVDCON equ 0FD2h ;# 
# 2063 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
LVDCON equ 0FD2h ;# 
# 2131 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
OSCCON equ 0FD3h ;# 
# 2156 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
T0CON equ 0FD5h ;# 
# 2180 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR0 equ 0FD6h ;# 
# 2192 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR0L equ 0FD6h ;# 
# 2204 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TMR0H equ 0FD7h ;# 
# 2216 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
STATUS equ 0FD8h ;# 
# 2247 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR2 equ 0FD9h ;# 
# 2259 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR2L equ 0FD9h ;# 
# 2271 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR2H equ 0FDAh ;# 
# 2283 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PLUSW2 equ 0FDBh ;# 
# 2295 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PREINC2 equ 0FDCh ;# 
# 2307 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTDEC2 equ 0FDDh ;# 
# 2319 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTINC2 equ 0FDEh ;# 
# 2331 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INDF2 equ 0FDFh ;# 
# 2343 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
BSR equ 0FE0h ;# 
# 2355 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR1 equ 0FE1h ;# 
# 2367 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR1L equ 0FE1h ;# 
# 2379 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR1H equ 0FE2h ;# 
# 2391 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PLUSW1 equ 0FE3h ;# 
# 2403 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PREINC1 equ 0FE4h ;# 
# 2415 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTDEC1 equ 0FE5h ;# 
# 2427 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTINC1 equ 0FE6h ;# 
# 2439 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INDF1 equ 0FE7h ;# 
# 2451 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
WREG equ 0FE8h ;# 
# 2474 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR0 equ 0FE9h ;# 
# 2486 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR0L equ 0FE9h ;# 
# 2498 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
FSR0H equ 0FEAh ;# 
# 2510 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PLUSW0 equ 0FEBh ;# 
# 2522 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PREINC0 equ 0FECh ;# 
# 2534 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTDEC0 equ 0FEDh ;# 
# 2546 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
POSTINC0 equ 0FEEh ;# 
# 2558 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INDF0 equ 0FEFh ;# 
# 2570 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INTCON3 equ 0FF0h ;# 
# 2599 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INTCON2 equ 0FF1h ;# 
# 2626 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
INTCON equ 0FF2h ;# 
# 2690 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PROD equ 0FF3h ;# 
# 2702 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PRODL equ 0FF3h ;# 
# 2714 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PRODH equ 0FF4h ;# 
# 2726 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TABLAT equ 0FF5h ;# 
# 2738 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TBLPTR equ 0FF6h ;# 
# 2751 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TBLPTRL equ 0FF6h ;# 
# 2763 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TBLPTRH equ 0FF7h ;# 
# 2775 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TBLPTRU equ 0FF8h ;# 
# 2788 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PCLAT equ 0FF9h ;# 
# 2793 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PC equ 0FF9h ;# 
# 2811 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PCL equ 0FF9h ;# 
# 2823 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PCLATH equ 0FFAh ;# 
# 2835 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
PCLATU equ 0FFBh ;# 
# 2847 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
STKPTR equ 0FFCh ;# 
# 2871 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TOS equ 0FFDh ;# 
# 2883 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TOSL equ 0FFDh ;# 
# 2895 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TOSH equ 0FFEh ;# 
# 2907 "C:\Program Files (x86)\HI-TECH Software\PICC-18\9.80\include\pic18f2221.h"
TOSU equ 0FFFh ;# 
	FNCALL	_main,_configSystem
	FNCALL	_main,_configSoftPWM
	FNCALL	_main,_configTimer
	FNCALL	_main,_configI2C
	FNCALL	_main,_adcOff
	FNCALL	_configSystem,_setupOsc
	FNROOT	_main
	FNCALL	intlevel2,_isr
	global	intlevel2
	FNROOT	intlevel2
	global	_dutyCycle1
	global	_dutyCycle2
	global	_dutyCycle3
	global	_dutyCycle4
	global	_dutyCycle5
	global	_dutyCycle6
	global	_maxDuty
	global	_stressTest
psect	idataCOMRAM,class=CODE,space=0,delta=1
global __pidataCOMRAM
__pidataCOMRAM:
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\softPWM.h"
	line	17

;initializer for _dutyCycle1
	dw	(020h)&0ffffh
	line	18

;initializer for _dutyCycle2
	dw	(020h)&0ffffh
	line	19

;initializer for _dutyCycle3
	dw	(020h)&0ffffh
	line	20

;initializer for _dutyCycle4
	dw	(020h)&0ffffh
	line	21

;initializer for _dutyCycle5
	dw	(020h)&0ffffh
	line	22

;initializer for _dutyCycle6
	dw	(020h)&0ffffh
	line	23

;initializer for _maxDuty
	dw	(064h)&0ffffh
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\main.c"
	line	14

;initializer for _stressTest
	db	low(01h)
	global	_i2c_buff_index
	global	_i2c_rx_buff
	global	_i2c_tx_buff
	global	_counter
	global	_down
	global	_potEnabled
	global	_pwmCounter
	global	_v_sspstat
	global	_newData
	global	_ADCON0
_ADCON0	set	0xFC2
	global	_ADCON1
_ADCON1	set	0xFC1
	global	_ADCON2
_ADCON2	set	0xFC0
	global	_ADRESH
_ADRESH	set	0xFC4
	global	_ADRESL
_ADRESL	set	0xFC3
	global	_INTCONbits
_INTCONbits	set	0xFF2
	global	_OSCCON
_OSCCON	set	0xFD3
	global	_PORTA
_PORTA	set	0xF80
	global	_PORTB
_PORTB	set	0xF81
	global	_PORTC
_PORTC	set	0xF82
	global	_PR2
_PR2	set	0xFCB
	global	_SSPADD
_SSPADD	set	0xFC8
	global	_SSPBUF
_SSPBUF	set	0xFC9
	global	_SSPCON1
_SSPCON1	set	0xFC6
	global	_SSPCON2
_SSPCON2	set	0xFC5
	global	_SSPSTAT
_SSPSTAT	set	0xFC7
	global	_T0CONbits
_T0CONbits	set	0xFD5
	global	_T2CONbits
_T2CONbits	set	0xFCA
	global	_TRISA
_TRISA	set	0xF92
	global	_TRISB
_TRISB	set	0xF93
	global	_TRISC
_TRISC	set	0xF94
	global	_WDTCON
_WDTCON	set	0xFD1
	global	_ACKSTAT
_ACKSTAT	set	0x7E2E
	global	_CKP
_CKP	set	0x7E34
	global	_GO_nDONE
_GO_nDONE	set	0x7E11
	global	_IOFS
_IOFS	set	0x7E9A
	global	_PEIE
_PEIE	set	0x7F96
	global	_PLLEN
_PLLEN	set	0x7CDE
	global	_RA0
_RA0	set	0x7C00
	global	_RA1
_RA1	set	0x7C01
	global	_RA2
_RA2	set	0x7C02
	global	_RA3
_RA3	set	0x7C03
	global	_RA4
_RA4	set	0x7C04
	global	_RA6
_RA6	set	0x7C06
	global	_RA7
_RA7	set	0x7C07
	global	_RB5
_RB5	set	0x7C0D
	global	_RB7
_RB7	set	0x7C0F
	global	_RC5
_RC5	set	0x7C15
	global	_SSPIF
_SSPIF	set	0x7CF3
	global	_SSPOV
_SSPOV	set	0x7E36
	global	_TMR0IE
_TMR0IE	set	0x7F95
	global	_TMR0IF
_TMR0IF	set	0x7F92
	global	_TMR2IE
_TMR2IE	set	0x7CE9
	global	_TMR2IF
_TMR2IF	set	0x7CF1
; #config settings
	file	"motorController.as"
	line	#
psect	cinit,class=CODE,delta=1,reloc=2
global __pcinit
__pcinit:
global start_initialization
start_initialization:

psect	bitbssCOMRAM,class=COMRAM,bit,space=1
global __pbitbssCOMRAM
__pbitbssCOMRAM:
	global	_newData
_newData:
       ds      1
psect	bssCOMRAM,class=COMRAM,space=1
global __pbssCOMRAM
__pbssCOMRAM:
	global	_i2c_buff_index
_i2c_buff_index:
       ds      2
	global	_i2c_rx_buff
_i2c_rx_buff:
       ds      2
	global	_i2c_tx_buff
_i2c_tx_buff:
       ds      2
	global	_counter
_counter:
       ds      1
	global	_down
_down:
       ds      1
	global	_potEnabled
_potEnabled:
       ds      1
	global	_pwmCounter
_pwmCounter:
       ds      1
	global	_v_sspstat
_v_sspstat:
       ds      1
psect	dataCOMRAM,class=COMRAM,space=1
global __pdataCOMRAM
__pdataCOMRAM:
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\softPWM.h"
	line	17
	global	_dutyCycle1
_dutyCycle1:
       ds      2
psect	dataCOMRAM
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\softPWM.h"
	line	18
	global	_dutyCycle2
_dutyCycle2:
       ds      2
psect	dataCOMRAM
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\softPWM.h"
	line	19
	global	_dutyCycle3
_dutyCycle3:
       ds      2
psect	dataCOMRAM
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\softPWM.h"
	line	20
	global	_dutyCycle4
_dutyCycle4:
       ds      2
psect	dataCOMRAM
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\softPWM.h"
	line	21
	global	_dutyCycle5
_dutyCycle5:
       ds      2
psect	dataCOMRAM
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\softPWM.h"
	line	22
	global	_dutyCycle6
_dutyCycle6:
       ds      2
psect	dataCOMRAM
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\softPWM.h"
	line	23
	global	_maxDuty
	global	_maxDuty
_maxDuty:
       ds      2
psect	dataCOMRAM
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\main.c"
	line	14
	global	_stressTest
	global	_stressTest
_stressTest:
       ds      1
psect	cinit
; Clear objects allocated to BITCOMRAM (1 bytes)
	global __pbitbssCOMRAM
clrf	(__pbitbssCOMRAM/8+0)&0xffh,c
; Clear objects allocated to COMRAM (11 bytes)
	global __pbssCOMRAM
lfsr	0,__pbssCOMRAM
movlw	11
clear_0:
clrf	postinc0,c
decf	wreg
bnz	clear_0
; Initialize objects allocated to COMRAM (15 bytes)
	global __pidataCOMRAM
	; load TBLPTR registers with __pidataCOMRAM
	movlw	low (__pidataCOMRAM)
	movwf	tblptrl
	movlw	high(__pidataCOMRAM)
	movwf	tblptrh
	movlw	low highword(__pidataCOMRAM)
	movwf	tblptru
	lfsr	0,__pdataCOMRAM
	lfsr	1,15
	copy_data0:
	tblrd	*+
	movff	tablat, postinc0
	movf	postdec1,w
	movf	fsr1l,w
	bnz	copy_data0
psect cinit,class=CODE,delta=1
global end_of_initialization

;End of C runtime variable initialization code

end_of_initialization:
movlb 0
goto _main	;jump to C main() function
psect	cstackCOMRAM,class=COMRAM,space=1
global __pcstackCOMRAM
__pcstackCOMRAM:
	global	?_configSoftPWM
?_configSoftPWM:	; 0 bytes @ 0x0
	global	?_configTimer
?_configTimer:	; 0 bytes @ 0x0
	global	?_setupOsc
?_setupOsc:	; 0 bytes @ 0x0
	global	?_configSystem
?_configSystem:	; 0 bytes @ 0x0
	global	?_configI2C
?_configI2C:	; 0 bytes @ 0x0
	global	?_adcOff
?_adcOff:	; 0 bytes @ 0x0
	global	?_main
?_main:	; 0 bytes @ 0x0
	global	?_isr
?_isr:	; 0 bytes @ 0x0
	global	??_isr
??_isr:	; 0 bytes @ 0x0
	ds   17
	global	isr@size
isr@size:	; 1 bytes @ 0x11
	ds   1
	global	??_configSoftPWM
??_configSoftPWM:	; 0 bytes @ 0x12
	global	??_configTimer
??_configTimer:	; 0 bytes @ 0x12
	global	??_setupOsc
??_setupOsc:	; 0 bytes @ 0x12
	global	??_configI2C
??_configI2C:	; 0 bytes @ 0x12
	global	??_adcOff
??_adcOff:	; 0 bytes @ 0x12
	ds   1
	global	??_configSystem
??_configSystem:	; 0 bytes @ 0x13
	global	??_main
??_main:	; 0 bytes @ 0x13
	ds   2
;!
;!Data Sizes:
;!    Strings     0
;!    Constant    0
;!    Data        15
;!    BSS         11
;!    Persistent  0
;!    Stack       0
;!
;!Auto Spaces:
;!    Space          Size  Autos    Used
;!    COMRAM          127     21      48
;!    BANK0           128      0       0
;!    BANK1           256      0       0

;!
;!Pointer List with Targets:
;!
;!    None.


;!
;!Critical Paths under _main in COMRAM
;!
;!    _configSystem->_setupOsc
;!
;!Critical Paths under _isr in COMRAM
;!
;!    None.
;!
;!Critical Paths under _main in BANK0
;!
;!    None.
;!
;!Critical Paths under _isr in BANK0
;!
;!    None.
;!
;!Critical Paths under _main in BANK1
;!
;!    None.
;!
;!Critical Paths under _isr in BANK1
;!
;!    None.

;;
;;Main: autosize = 0, tempsize = 2, incstack = 0, save=0
;;

;!
;!Call Graph Tables:
;!
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (0) _main                                                 2     2      0       0
;!                                             19 COMRAM     2     2      0
;!                       _configSystem
;!                      _configSoftPWM
;!                        _configTimer
;!                          _configI2C
;!                             _adcOff
;! ---------------------------------------------------------------------------------
;! (1) _configSystem                                         0     0      0       0
;!                           _setupOsc
;! ---------------------------------------------------------------------------------
;! (2) _setupOsc                                             1     1      0       0
;!                                             18 COMRAM     1     1      0
;! ---------------------------------------------------------------------------------
;! (1) _configI2C                                            0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _adcOff                                               0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _configSoftPWM                                        0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _configTimer                                          0     0      0       0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 2
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (3) _isr                                                 18    18      0       0
;!                                              0 COMRAM    18    18      0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 3
;! ---------------------------------------------------------------------------------
;!
;! Call Graph Graphs:
;!
;! _main (ROOT)
;!   _configSystem
;!     _setupOsc
;!   _configSoftPWM
;!   _configTimer
;!   _configI2C
;!   _adcOff
;!
;! _isr (ROOT)
;!

;! Address spaces:

;!Name               Size   Autos  Total    Cost      Usage
;!BIGRAM             1FF      0       0       8        0.0%
;!EEDATA             100      0       0       0        0.0%
;!BITBANK1           100      0       0       5        0.0%
;!BANK1              100      0       0       6        0.0%
;!BITBANK0            80      0       0       3        0.0%
;!BANK0               80      0       0       4        0.0%
;!BITCOMRAM           7F      0       1       0        0.8%
;!COMRAM              7F     15      30       1       37.8%
;!BITSFR               0      0       0      40        0.0%
;!SFR                  0      0       0      40        0.0%
;!STACK                0      0       2       2        0.0%
;!NULL                 0      0       0       0        0.0%
;!ABS                  0      0      30       7        0.0%
;!DATA                 0      0      32       9        0.0%
;!CODE                 0      0       0       0        0.0%

	global	_main

;; *************** function _main *****************
;; Defined at:
;;		line 152 in file "C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, fsr2l, fsr2h, status,2, status,0, pclat, tosl, structret, tblptrl, tblptrh, tblptru, prodl, prodh, bsr, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          2       0       0
;;      Totals:         2       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels required when called:    3
;; This function calls:
;;		_configSystem
;;		_configSoftPWM
;;		_configTimer
;;		_configI2C
;;		_adcOff
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	text0,class=CODE,space=0,reloc=2
global __ptext0
__ptext0:
psect	text0
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\main.c"
	line	152
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:
	opt	stack 28
	line	155
	
l964:
;main.c: 155: configSystem();
	call	_configSystem	;wreg free
	line	156
	
l966:
;main.c: 156: configSoftPWM();
	call	_configSoftPWM	;wreg free
	line	157
	
l968:
;main.c: 157: configTimer();
	call	_configTimer	;wreg free
	line	158
	
l970:
;main.c: 158: configI2C();
	call	_configI2C	;wreg free
	line	160
	
l972:
;main.c: 160: adcOff();
	call	_adcOff	;wreg free
	goto	l974
	line	162
;main.c: 162: while (1) {
	
l139:
	line	168
	
l974:
;main.c: 168: if(newData){
	movlb	(_newData/8) >> 8
	btfss	(_newData/8),c,(_newData)&7
	goto	u121
	goto	u120
u121:
	goto	l974
u120:
	goto	l988
	line	169
	
l976:
;main.c: 169: switch(i2c_rx_buff[0]){
	goto	l988
	line	171
;main.c: 171: case 0x00:
	
l142:
	line	172
;main.c: 172: dutyCycle1 = i2c_rx_buff[1];
	movff	0+((c:_i2c_rx_buff)+01h),(c:_dutyCycle1)	;volatile
	clrf	((c:_dutyCycle1+1)),c
	line	173
	
l978:
;main.c: 173: dutyCycle2 = 64 - dutyCycle1;
	movff	(c:_dutyCycle1),??_main+0+0
	movff	(c:_dutyCycle1+1),??_main+0+0+1
	comf	(??_main+0+0),c
	comf	(??_main+0+1),c
	infsnz	(??_main+0+0),c
	incf	(??_main+0+1),c
	movlw	low(040h)
	addwf	(??_main+0+0),c,w
	
	movwf	((c:_dutyCycle2)),c
	movlw	high(040h)
	addwfc	(??_main+0+1),c,w
	movwf	1+((c:_dutyCycle2)),c
	line	174
	
l980:
;main.c: 174: newData = 0;
	movlb	(_newData/8) >> 8
	bcf	(_newData/8),c,(_newData)&7
	line	175
;main.c: 175: break;
	goto	l974
	line	177
;main.c: 177: case 0x01:
	
l144:
	line	178
;main.c: 178: dutyCycle3 = i2c_rx_buff[1];
	movff	0+((c:_i2c_rx_buff)+01h),(c:_dutyCycle3)	;volatile
	clrf	((c:_dutyCycle3+1)),c
	line	179
	
l982:
;main.c: 179: dutyCycle4 = 64 - dutyCycle3;
	movff	(c:_dutyCycle3),??_main+0+0
	movff	(c:_dutyCycle3+1),??_main+0+0+1
	comf	(??_main+0+0),c
	comf	(??_main+0+1),c
	infsnz	(??_main+0+0),c
	incf	(??_main+0+1),c
	movlw	low(040h)
	addwf	(??_main+0+0),c,w
	
	movwf	((c:_dutyCycle4)),c
	movlw	high(040h)
	addwfc	(??_main+0+1),c,w
	movwf	1+((c:_dutyCycle4)),c
	line	180
	
l984:
;main.c: 180: newData = 0;
	movlb	(_newData/8) >> 8
	bcf	(_newData/8),c,(_newData)&7
	line	181
;main.c: 181: break;
	goto	l974
	line	184
;main.c: 184: case 0x02:
	
l145:
	line	185
;main.c: 185: dutyCycle5 = i2c_rx_buff[1];
	movff	0+((c:_i2c_rx_buff)+01h),(c:_dutyCycle5)	;volatile
	clrf	((c:_dutyCycle5+1)),c
	line	186
;main.c: 186: newData = 0;
	movlb	(_newData/8) >> 8
	bcf	(_newData/8),c,(_newData)&7
	line	187
;main.c: 187: break;
	goto	l974
	line	199
;main.c: 199: case 0x10:
	
l146:
	line	200
;main.c: 200: i2c_tx_buff[0] = dutyCycle1;
	movff	(c:_dutyCycle1),(c:_i2c_tx_buff)
	line	201
;main.c: 201: break;
	goto	l974
	line	203
;main.c: 203: case 0x20:
	
l147:
	line	204
;main.c: 204: i2c_tx_buff[0] = dutyCycle2;
	movff	(c:_dutyCycle2),(c:_i2c_tx_buff)
	line	205
;main.c: 205: break;
	goto	l974
	line	207
;main.c: 207: case 0x99:
	
l148:
	line	208
;main.c: 208: potEnabled = i2c_rx_buff[1];
	movff	0+((c:_i2c_rx_buff)+01h),(c:_potEnabled)	;volatile
	line	209
;main.c: 209: break;
	goto	l974
	line	210
;main.c: 210: default:
	
l149:
	line	212
;main.c: 212: newData = 0;
	movlb	(_newData/8) >> 8
	bcf	(_newData/8),c,(_newData)&7
	line	213
;main.c: 213: break;
	goto	l974
	line	214
	
l986:
;main.c: 214: }
	goto	l974
	line	169
	
l141:
	
l988:
	movf	((c:_i2c_rx_buff)),c,w	;volatile
	; Switch size 1, requested type "space"
; Number of cases is 6, Range of values is 0 to 153
; switch strategies available:
; Name         Instructions Cycles
; simple_byte           19    10 (average)
;	Chosen strategy is simple_byte

	xorlw	0^0	; case 0
	skipnz
	goto	l142
	xorlw	1^0	; case 1
	skipnz
	goto	l144
	xorlw	2^1	; case 2
	skipnz
	goto	l145
	xorlw	16^2	; case 16
	skipnz
	goto	l146
	xorlw	32^16	; case 32
	skipnz
	goto	l147
	xorlw	153^32	; case 153
	skipnz
	goto	l148
	goto	l149

	line	214
	
l143:
	goto	l974
	line	216
	
l140:
	goto	l974
	line	220
	
l150:
	line	162
	goto	l974
	
l151:
	line	221
	
l152:
	global	start
	goto	start
	opt stack 0
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,88
	global	_configSystem

;; *************** function _configSystem *****************
;; Defined at:
;;		line 37 in file "C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          0       0       0
;;      Totals:         0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		_setupOsc
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text1,class=CODE,space=0,reloc=2
global __ptext1
__ptext1:
psect	text1
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\main.c"
	line	37
	global	__size_of_configSystem
	__size_of_configSystem	equ	__end_of_configSystem-_configSystem
	
_configSystem:
	opt	stack 28
	line	38
	
l852:
;main.c: 38: setupOsc();
	call	_setupOsc	;wreg free
	line	40
	
l854:
;main.c: 40: TRISA = 0x00;
	movlw	low(0)
	movwf	((c:3986)),c	;volatile
	line	41
	
l856:
;main.c: 41: TRISB = 0x00;
	movlw	low(0)
	movwf	((c:3987)),c	;volatile
	line	42
	
l858:
;main.c: 42: TRISC = 0x00;
	movlw	low(0)
	movwf	((c:3988)),c	;volatile
	line	43
	
l860:
;main.c: 43: PORTA = 0x00;
	movlw	low(0)
	movwf	((c:3968)),c	;volatile
	line	44
	
l862:
;main.c: 44: PORTB = 0x00;
	movlw	low(0)
	movwf	((c:3969)),c	;volatile
	line	45
	
l864:
;main.c: 45: PORTC = 0x00;
	movlw	low(0)
	movwf	((c:3970)),c	;volatile
	line	48
	
l866:
;main.c: 48: ADCON1 = 0x0F;
	movlw	low(0Fh)
	movwf	((c:4033)),c	;volatile
	line	51
	
l868:
;main.c: 51: RB7 = 0;
	bcf	c:(31759/8),(31759)&7	;volatile
	line	52
	
l870:
;main.c: 52: RA4 = 1;
	bsf	c:(31748/8),(31748)&7	;volatile
	line	53
	
l872:
;main.c: 53: RC5 = 1;
	bsf	c:(31765/8),(31765)&7	;volatile
	line	54
	
l97:
	return
	opt stack 0
GLOBAL	__end_of_configSystem
	__end_of_configSystem:
	signat	_configSystem,88
	global	_setupOsc

;; *************** function _setupOsc *****************
;; Defined at:
;;		line 18 in file "C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          1       0       0
;;      Totals:         1       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_configSystem
;; This function uses a non-reentrant model
;;
psect	text2,class=CODE,space=0,reloc=2
global __ptext2
__ptext2:
psect	text2
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\main.c"
	line	18
	global	__size_of_setupOsc
	__size_of_setupOsc	equ	__end_of_setupOsc-_setupOsc
	
_setupOsc:
	opt	stack 28
	line	30
	
l844:
;main.c: 30: OSCCON = 0b11110000;
	movlw	low(0F0h)
	movwf	((c:4051)),c	;volatile
	line	31
;main.c: 31: while(!IOFS);
	goto	l91
	
l92:
	
l91:
	btfss	c:(32410/8),(32410)&7	;volatile
	goto	u11
	goto	u10
u11:
	goto	l91
u10:
	goto	l846
	
l93:
	line	32
	
l846:
;main.c: 32: _delay((unsigned long)((10)*(32000000/4000.0)));
	movlw	104
movwf	(??_setupOsc+0+0)&0ffh,c,f
	movlw	228
u2137:
	decfsz	wreg,f
	goto	u2137
	decfsz	(??_setupOsc+0+0)&0ffh,c,f
	goto	u2137
	nop

	line	33
	
l848:
;main.c: 33: PLLEN = 1;
	bsf	c:(31966/8),(31966)&7	;volatile
	line	34
	
l850:
;main.c: 34: WDTCON = 0x00;
	movlw	low(0)
	movwf	((c:4049)),c	;volatile
	line	35
	
l94:
	return
	opt stack 0
GLOBAL	__end_of_setupOsc
	__end_of_setupOsc:
	signat	_setupOsc,88
	global	_configI2C

;; *************** function _configI2C *****************
;; Defined at:
;;		line 56 in file "C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          0       0       0
;;      Totals:         0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text3,class=CODE,space=0,reloc=2
global __ptext3
__ptext3:
psect	text3
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\main.c"
	line	56
	global	__size_of_configI2C
	__size_of_configI2C	equ	__end_of_configI2C-_configI2C
	
_configI2C:
	opt	stack 29
	line	59
	
l874:
;main.c: 59: TRISC |= 1 << 3;
	bsf	(0+(3/8)+(c:3988)),c,(3)&7	;volatile
	line	60
;main.c: 60: TRISC |= 1 << 4;
	bsf	(0+(4/8)+(c:3988)),c,(4)&7	;volatile
	line	63
;main.c: 63: SSPSTAT |= 1 << 7;
	bsf	(0+(7/8)+(c:4039)),c,(7)&7	;volatile
	line	66
	
l876:
;main.c: 66: SSPCON1 = 0b00111110;
	movlw	low(03Eh)
	movwf	((c:4038)),c	;volatile
	line	68
	
l878:
;main.c: 68: SSPCON2 |= 1 << 7;
	bsf	(0+(7/8)+(c:4037)),c,(7)&7	;volatile
	line	69
	
l880:
;main.c: 69: SSPCON2 |= 1 << 0;
	bsf	(0+(0/8)+(c:4037)),c,(0)&7	;volatile
	line	70
	
l882:
;main.c: 70: SSPADD = 0x10;
	movlw	low(010h)
	movwf	((c:4040)),c	;volatile
	line	74
	
l100:
	return
	opt stack 0
GLOBAL	__end_of_configI2C
	__end_of_configI2C:
	signat	_configI2C,88
	global	_adcOff

;; *************** function _adcOff *****************
;; Defined at:
;;		line 94 in file "C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          0       0       0
;;      Totals:         0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text4,class=CODE,space=0,reloc=2
global __ptext4
__ptext4:
psect	text4
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\main.c"
	line	94
	global	__size_of_adcOff
	__size_of_adcOff	equ	__end_of_adcOff-_adcOff
	
_adcOff:
	opt	stack 29
	line	96
	
l892:
;main.c: 96: ADCON0 = 0b00111100;
	movlw	low(03Ch)
	movwf	((c:4034)),c	;volatile
	line	98
;main.c: 98: ADCON1 = 0b00001111;
	movlw	low(0Fh)
	movwf	((c:4033)),c	;volatile
	line	99
	
l106:
	return
	opt stack 0
GLOBAL	__end_of_adcOff
	__end_of_adcOff:
	signat	_adcOff,88
	global	_configSoftPWM

;; *************** function _configSoftPWM *****************
;; Defined at:
;;		line 118 in file "C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\softPWM.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          0       0       0
;;      Totals:         0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text5,class=CODE,space=0,reloc=2
global __ptext5
__ptext5:
psect	text5
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\softPWM.c"
	line	118
	global	__size_of_configSoftPWM
	__size_of_configSoftPWM	equ	__end_of_configSoftPWM-_configSoftPWM
	
_configSoftPWM:
	opt	stack 29
	line	120
	
l990:
;softPWM.c: 120: T2CONbits.T2CKPS = 0;
	movlw	((0 & ((1<<2)-1))<<0)|not (((1<<2)-1)<<0)
	andwf	((c:4042)),c	;volatile
	line	122
	
l992:
;softPWM.c: 122: T2CONbits.TOUTPS = 0;
		bcf	((c:4042)),c, 3+0	;volatile
	bcf	((c:4042)),c, 3+1	;volatile
	bcf	((c:4042)),c, 3+2	;volatile
	bcf	((c:4042)),c, 3+3	;volatile

	line	124
	
l994:
;softPWM.c: 124: TMR2IE = 1;
	bsf	c:(31977/8),(31977)&7	;volatile
	line	127
	
l996:
;softPWM.c: 127: PEIE = 1;
	bsf	c:(32662/8),(32662)&7	;volatile
	line	129
	
l998:
;softPWM.c: 129: PR2 = 255;
	setf	((c:4043)),c	;volatile
	line	132
	
l1000:
;softPWM.c: 132: T2CONbits.TMR2ON = 1;
	bsf	((c:4042)),c,2	;volatile
	line	134
	
l1002:
;softPWM.c: 134: (INTCONbits.GIE = 1);
	bsf	((c:4082)),c,7	;volatile
	line	135
	
l262:
	return
	opt stack 0
GLOBAL	__end_of_configSoftPWM
	__end_of_configSoftPWM:
	signat	_configSoftPWM,88
	global	_configTimer

;; *************** function _configTimer *****************
;; Defined at:
;;		line 137 in file "C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\softPWM.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          0       0       0
;;      Totals:         0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text6,class=CODE,space=0,reloc=2
global __ptext6
__ptext6:
psect	text6
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\softPWM.c"
	line	137
	global	__size_of_configTimer
	__size_of_configTimer	equ	__end_of_configTimer-_configTimer
	
_configTimer:
	opt	stack 29
	line	139
	
l1004:
;softPWM.c: 139: T0CONbits.T08BIT = 1;
	bsf	((c:4053)),c,6	;volatile
	line	140
;softPWM.c: 140: T0CONbits.T0CS = 0;
	bcf	((c:4053)),c,5	;volatile
	line	142
;softPWM.c: 142: T0CONbits.PSA = 1;
	bsf	((c:4053)),c,3	;volatile
	line	145
;softPWM.c: 145: T0CONbits.T0PS = 111;
		bsf	((c:4053)),c, 0+0	;volatile
	bsf	((c:4053)),c, 0+1	;volatile
	bsf	((c:4053)),c, 0+2	;volatile

	line	146
;softPWM.c: 146: TMR0IE = 0;
	bcf	c:(32661/8),(32661)&7	;volatile
	line	149
;softPWM.c: 149: T0CONbits.TMR0ON = 0;
	bcf	((c:4053)),c,7	;volatile
	line	151
;softPWM.c: 151: (INTCONbits.GIE = 1);
	bsf	((c:4082)),c,7	;volatile
	line	152
	
l265:
	return
	opt stack 0
GLOBAL	__end_of_configTimer
	__end_of_configTimer:
	signat	_configTimer,88
	global	_isr

;; *************** function _isr *****************
;; Defined at:
;;		line 7 in file "C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\softPWM.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  size            1   17[COMRAM] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr2l, fsr2h, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         1       0       0
;;      Temps:         17       0       0
;;      Totals:        18       0       0
;;Total ram usage:       18 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Interrupt level 2
;; This function uses a non-reentrant model
;;
psect	intcode,class=CODE,space=0,reloc=2
global __pintcode
__pintcode:
psect	intcode
	file	"C:\Users\Mike\Desktop\SVN\Serial Motor Controller\PIC18F2221\softPWM.c"
	line	7
	global	__size_of_isr
	__size_of_isr	equ	__end_of_isr-_isr
	
_isr:
	opt	stack 28
	movff	pclat+0,??_isr+3
	movff	pclat+1,??_isr+4
	movff	fsr0l+0,??_isr+5
	movff	fsr0h+0,??_isr+6
	movff	fsr1l+0,??_isr+7
	movff	fsr1h+0,??_isr+8
	movff	fsr2l+0,??_isr+9
	movff	fsr2h+0,??_isr+10
	movff	prodl+0,??_isr+11
	movff	prodh+0,??_isr+12
	movff	tblptrl+0,??_isr+13
	movff	tblptrh+0,??_isr+14
	movff	tblptru+0,??_isr+15
	movff	tablat+0,??_isr+16
	line	9
	
i2l1006:
;softPWM.c: 9: if (TMR2IF){
	btfss	c:(31985/8),(31985)&7	;volatile
	goto	i2u13_41
	goto	i2u13_40
i2u13_41:
	goto	i2l1042
i2u13_40:
	line	10
	
i2l1008:
;softPWM.c: 10: RB7 = 1;
	bsf	c:(31759/8),(31759)&7	;volatile
	line	14
	
i2l1010:
;softPWM.c: 14: if (dutyCycle1 > pwmCounter)
	movf	((c:_pwmCounter)),c,w
	movwf	(??_isr+0+0)&0ffh,c
	clrf	(??_isr+0+0+1)&0ffh,c

	movf	(??_isr+0+1),c,w
	xorlw	80h
	movwf	(??_isr+2+0)&0ffh,c
	movf	((c:_dutyCycle1)),c,w
	subwf	(??_isr+0+0),c,w
	movf	((c:_dutyCycle1+1)),c,w
	xorlw	80h
	subwfb	(??_isr+2+0)&0ffh,c,w
	btfsc	status,0
	goto	i2u14_41
	goto	i2u14_40
i2u14_41:
	goto	i2l230
i2u14_40:
	line	15
	
i2l1012:
;softPWM.c: 15: RA0 = 1; else RA0 = 0;
	bsf	c:(31744/8),(31744)&7	;volatile
	goto	i2l1014
	
i2l230:
	bcf	c:(31744/8),(31744)&7	;volatile
	goto	i2l1014
	
i2l231:
	line	19
	
i2l1014:
;softPWM.c: 19: if (dutyCycle2 > pwmCounter)
	movf	((c:_pwmCounter)),c,w
	movwf	(??_isr+0+0)&0ffh,c
	clrf	(??_isr+0+0+1)&0ffh,c

	movf	(??_isr+0+1),c,w
	xorlw	80h
	movwf	(??_isr+2+0)&0ffh,c
	movf	((c:_dutyCycle2)),c,w
	subwf	(??_isr+0+0),c,w
	movf	((c:_dutyCycle2+1)),c,w
	xorlw	80h
	subwfb	(??_isr+2+0)&0ffh,c,w
	btfsc	status,0
	goto	i2u15_41
	goto	i2u15_40
i2u15_41:
	goto	i2l232
i2u15_40:
	line	20
	
i2l1016:
;softPWM.c: 20: RA1 = 1; else RA1 = 0;
	bsf	c:(31745/8),(31745)&7	;volatile
	goto	i2l1018
	
i2l232:
	bcf	c:(31745/8),(31745)&7	;volatile
	goto	i2l1018
	
i2l233:
	line	24
	
i2l1018:
;softPWM.c: 24: if (dutyCycle3 > pwmCounter)
	movf	((c:_pwmCounter)),c,w
	movwf	(??_isr+0+0)&0ffh,c
	clrf	(??_isr+0+0+1)&0ffh,c

	movf	(??_isr+0+1),c,w
	xorlw	80h
	movwf	(??_isr+2+0)&0ffh,c
	movf	((c:_dutyCycle3)),c,w
	subwf	(??_isr+0+0),c,w
	movf	((c:_dutyCycle3+1)),c,w
	xorlw	80h
	subwfb	(??_isr+2+0)&0ffh,c,w
	btfsc	status,0
	goto	i2u16_41
	goto	i2u16_40
i2u16_41:
	goto	i2l234
i2u16_40:
	line	25
	
i2l1020:
;softPWM.c: 25: RA3 = 1; else RA3 = 0;
	bsf	c:(31747/8),(31747)&7	;volatile
	goto	i2l1022
	
i2l234:
	bcf	c:(31747/8),(31747)&7	;volatile
	goto	i2l1022
	
i2l235:
	line	29
	
i2l1022:
;softPWM.c: 29: if (dutyCycle4 > pwmCounter)
	movf	((c:_pwmCounter)),c,w
	movwf	(??_isr+0+0)&0ffh,c
	clrf	(??_isr+0+0+1)&0ffh,c

	movf	(??_isr+0+1),c,w
	xorlw	80h
	movwf	(??_isr+2+0)&0ffh,c
	movf	((c:_dutyCycle4)),c,w
	subwf	(??_isr+0+0),c,w
	movf	((c:_dutyCycle4+1)),c,w
	xorlw	80h
	subwfb	(??_isr+2+0)&0ffh,c,w
	btfsc	status,0
	goto	i2u17_41
	goto	i2u17_40
i2u17_41:
	goto	i2l236
i2u17_40:
	line	30
	
i2l1024:
;softPWM.c: 30: RA2 = 1; else RA2 = 0;
	bsf	c:(31746/8),(31746)&7	;volatile
	goto	i2l1026
	
i2l236:
	bcf	c:(31746/8),(31746)&7	;volatile
	goto	i2l1026
	
i2l237:
	line	34
	
i2l1026:
;softPWM.c: 34: if (dutyCycle5 > pwmCounter)
	movf	((c:_pwmCounter)),c,w
	movwf	(??_isr+0+0)&0ffh,c
	clrf	(??_isr+0+0+1)&0ffh,c

	movf	(??_isr+0+1),c,w
	xorlw	80h
	movwf	(??_isr+2+0)&0ffh,c
	movf	((c:_dutyCycle5)),c,w
	subwf	(??_isr+0+0),c,w
	movf	((c:_dutyCycle5+1)),c,w
	xorlw	80h
	subwfb	(??_isr+2+0)&0ffh,c,w
	btfsc	status,0
	goto	i2u18_41
	goto	i2u18_40
i2u18_41:
	goto	i2l238
i2u18_40:
	line	35
	
i2l1028:
;softPWM.c: 35: RA7 = 1; else RA7 = 0;
	bsf	c:(31751/8),(31751)&7	;volatile
	goto	i2l1030
	
i2l238:
	bcf	c:(31751/8),(31751)&7	;volatile
	goto	i2l1030
	
i2l239:
	line	39
	
i2l1030:
;softPWM.c: 39: if (dutyCycle6 > pwmCounter)
	movf	((c:_pwmCounter)),c,w
	movwf	(??_isr+0+0)&0ffh,c
	clrf	(??_isr+0+0+1)&0ffh,c

	movf	(??_isr+0+1),c,w
	xorlw	80h
	movwf	(??_isr+2+0)&0ffh,c
	movf	((c:_dutyCycle6)),c,w
	subwf	(??_isr+0+0),c,w
	movf	((c:_dutyCycle6+1)),c,w
	xorlw	80h
	subwfb	(??_isr+2+0)&0ffh,c,w
	btfsc	status,0
	goto	i2u19_41
	goto	i2u19_40
i2u19_41:
	goto	i2l240
i2u19_40:
	line	40
	
i2l1032:
;softPWM.c: 40: RA6 = 1; else RA6 = 0;
	bsf	c:(31750/8),(31750)&7	;volatile
	goto	i2l1034
	
i2l240:
	bcf	c:(31750/8),(31750)&7	;volatile
	goto	i2l1034
	
i2l241:
	line	43
	
i2l1034:
;softPWM.c: 43: pwmCounter++;
	incf	((c:_pwmCounter)),c
	line	44
	
i2l1036:
;softPWM.c: 44: if (pwmCounter > 64) pwmCounter = 0;
	movlw	(041h-1)
	cpfsgt	((c:_pwmCounter)),c
	goto	i2u20_41
	goto	i2u20_40
i2u20_41:
	goto	i2l1040
i2u20_40:
	
i2l1038:
	movwf	(??_isr+0+0)&0ffh,c
	movlw	low(0)
	movwf	((c:_pwmCounter)),c
	movf	(??_isr+0+0)&0ffh,c,w
	goto	i2l1040
	
i2l242:
	line	47
	
i2l1040:
;softPWM.c: 47: TMR2IF = 0;
	bcf	c:(31985/8),(31985)&7	;volatile
	goto	i2l1042
	line	49
	
i2l229:
	line	51
	
i2l1042:
;softPWM.c: 49: }
;softPWM.c: 51: if (TMR0IF){
	line	53
	
i2l243:
	line	55
;softPWM.c: 53: }
;softPWM.c: 55: if (SSPIF) {
	btfss	c:(31987/8),(31987)&7	;volatile
	goto	i2u21_41
	goto	i2u21_40
i2u21_41:
	goto	i2l259
i2u21_40:
	line	56
	
i2l1044:
;softPWM.c: 56: RB7 = 1;
	bsf	c:(31759/8),(31759)&7	;volatile
	line	57
;softPWM.c: 57: SSPIF = 0;
	bcf	c:(31987/8),(31987)&7	;volatile
	line	58
	
i2l1046:
;softPWM.c: 58: v_sspstat = SSPSTAT & 0b00101101;
	movf	((c:4039)),c,w	;volatile
	andlw	low(02Dh)
	movwf	((c:_v_sspstat)),c
	line	60
;softPWM.c: 60: if (v_sspstat == 0b00001001)
	movf	((c:_v_sspstat)),c,w
	xorlw	9

	btfss	status,2
	goto	i2u22_41
	goto	i2u22_40
i2u22_41:
	goto	i2l1062
i2u22_40:
	line	62
	
i2l1048:
;softPWM.c: 61: {
;softPWM.c: 62: i2c_buff_index = 0;
	movlw	high(0)
	movwf	((c:_i2c_buff_index+1)),c	;volatile
	movlw	low(0)
	movwf	((c:_i2c_buff_index)),c	;volatile
	line	64
	
i2l1050:
;softPWM.c: 64: SSPBUF;
	movf	((c:4041)),c,w	;volatile
	line	65
	
i2l1052:
;softPWM.c: 65: if (SSPOV){
	btfss	c:(32310/8),(32310)&7	;volatile
	goto	i2u23_41
	goto	i2u23_40
i2u23_41:
	goto	i2l1060
i2u23_40:
	line	66
	
i2l1054:
;softPWM.c: 66: SSPOV = 0;
	bcf	c:(32310/8),(32310)&7	;volatile
	line	67
	
i2l1056:
;softPWM.c: 67: SSPBUF;
	movf	((c:4041)),c,w	;volatile
	line	68
	
i2l1058:
;softPWM.c: 68: RB5 = 1;
	bsf	c:(31757/8),(31757)&7	;volatile
	goto	i2l1060
	line	69
	
i2l246:
	line	70
	
i2l1060:
;softPWM.c: 69: }
;softPWM.c: 70: CKP = 1;
	bsf	c:(32308/8),(32308)&7	;volatile
	line	71
;softPWM.c: 71: }
	goto	i2l259
	line	72
	
i2l245:
	
i2l1062:
;softPWM.c: 72: else if ( v_sspstat == 0b00101001 )
	movf	((c:_v_sspstat)),c,w
	xorlw	41

	btfss	status,2
	goto	i2u24_41
	goto	i2u24_40
i2u24_41:
	goto	i2l1082
i2u24_40:
	line	74
	
i2l1064:
;softPWM.c: 73: {
;softPWM.c: 74: i2c_rx_buff[i2c_buff_index] = SSPBUF;
	movlw	low((c:_i2c_rx_buff))	;volatile
	addwf	((c:_i2c_buff_index)),c,w	;volatile
	movwf	c:fsr2l
	clrf	1+c:fsr2l
	movlw	high((c:_i2c_rx_buff))	;volatile
	addwfc	1+c:fsr2l
	movff	(c:4041),indf2	;volatile

	line	75
	
i2l1066:
;softPWM.c: 75: if (SSPOV){
	btfss	c:(32310/8),(32310)&7	;volatile
	goto	i2u25_41
	goto	i2u25_40
i2u25_41:
	goto	i2l1074
i2u25_40:
	line	76
	
i2l1068:
;softPWM.c: 76: SSPOV = 0;
	bcf	c:(32310/8),(32310)&7	;volatile
	line	77
	
i2l1070:
;softPWM.c: 77: SSPBUF;
	movf	((c:4041)),c,w	;volatile
	line	78
	
i2l1072:
;softPWM.c: 78: RB5 = 1;
	bsf	c:(31757/8),(31757)&7	;volatile
	goto	i2l1074
	line	79
	
i2l249:
	line	81
	
i2l1074:
;softPWM.c: 79: }
;softPWM.c: 81: CKP = 1;
	bsf	c:(32308/8),(32308)&7	;volatile
	line	83
	
i2l1076:
;softPWM.c: 83: if (++i2c_buff_index == sizeof(i2c_rx_buff)) {
	lfsr	2,(c:_i2c_buff_index)	;volatile
	incf	postinc2
	movlw	0
	addwfc	postdec2
	movf	postinc2,w
	xorlw	02h
	iorwf	postdec2,w
	btfss	status,2
	goto	i2u26_41
	goto	i2u26_40
i2u26_41:
	goto	i2l259
i2u26_40:
	line	84
	
i2l1078:
;softPWM.c: 84: i2c_buff_index = 0;
	movlw	high(0)
	movwf	((c:_i2c_buff_index+1)),c	;volatile
	movlw	low(0)
	movwf	((c:_i2c_buff_index)),c	;volatile
	line	85
	
i2l1080:
;softPWM.c: 85: newData = 1;
	movlb	(_newData/8) >> 8
	bsf	(_newData/8),c,(_newData)&7
	goto	i2l259
	line	86
	
i2l250:
	line	87
;softPWM.c: 86: }
;softPWM.c: 87: }
	goto	i2l259
	line	88
	
i2l248:
	
i2l1082:
;softPWM.c: 88: else if ( v_sspstat == 0b00001101 )
	movf	((c:_v_sspstat)),c,w
	xorlw	13

	btfss	status,2
	goto	i2u27_41
	goto	i2u27_40
i2u27_41:
	goto	i2l1092
i2u27_40:
	line	90
	
i2l1084:
;softPWM.c: 89: {
;softPWM.c: 90: if (SSPBUF == SSPADD + 1){
	movf	((c:4040)),c,w	;volatile
	movwf	(??_isr+0+0)&0ffh,c
	clrf	(??_isr+0+0+1)&0ffh,c

	movlw	01h
	addwf	(??_isr+0+0),c
	movlw	0
	addwfc	(??_isr+0+1),c
	movf	((c:4041)),c,w	;volatile
	xorwf	(??_isr+0+0),c,w
	iorwf	(??_isr+0+1),c,w

	btfss	status,2
	goto	i2u28_41
	goto	i2u28_40
i2u28_41:
	goto	i2l253
i2u28_40:
	line	91
	
i2l1086:
;softPWM.c: 91: SSPBUF = i2c_tx_buff[0];
	movff	(c:_i2c_tx_buff),(c:4041)	;volatile
	line	92
;softPWM.c: 92: CKP=1;
	bsf	c:(32308/8),(32308)&7	;volatile
	line	93
	
i2l1088:
;softPWM.c: 93: i2c_buff_index = 1;
	movlw	high(01h)
	movwf	((c:_i2c_buff_index+1)),c	;volatile
	movlw	low(01h)
	movwf	((c:_i2c_buff_index)),c	;volatile
	line	94
	
i2l1090:
;softPWM.c: 94: SSPIF = 0;
	bcf	c:(31987/8),(31987)&7	;volatile
	line	95
;softPWM.c: 95: }
	goto	i2l259
	line	97
	
i2l253:
;softPWM.c: 97: else RB5 = 1;
	bsf	c:(31757/8),(31757)&7	;volatile
	goto	i2l259
	
i2l254:
	line	98
;softPWM.c: 98: }
	goto	i2l259
	line	99
	
i2l252:
	
i2l1092:
;softPWM.c: 99: else if (( v_sspstat == 0b00101100 )&&(!ACKSTAT))
	movf	((c:_v_sspstat)),c,w
	xorlw	44

	btfss	status,2
	goto	i2u29_41
	goto	i2u29_40
i2u29_41:
	goto	i2l256
i2u29_40:
	
i2l1094:
	btfsc	c:(32302/8),(32302)&7	;volatile
	goto	i2u30_41
	goto	i2u30_40
i2u30_41:
	goto	i2l256
i2u30_40:
	line	101
	
i2l1096:
;softPWM.c: 100: {
;softPWM.c: 101: SSPBUF = i2c_tx_buff[i2c_buff_index];
	movlw	low((c:_i2c_tx_buff))
	addwf	((c:_i2c_buff_index)),c,w	;volatile
	movwf	c:fsr2l
	clrf	1+c:fsr2l
	movlw	high((c:_i2c_tx_buff))
	addwfc	1+c:fsr2l
	movf	indf2,w
	movwf	((c:4041)),c	;volatile
	line	103
	
i2l1098:
;softPWM.c: 103: unsigned char size = sizeof(i2c_tx_buff);
	movwf	(??_isr+0+0)&0ffh,c
	movlw	low(02h)
	movwf	((c:isr@size)),c
	movf	(??_isr+0+0)&0ffh,c,w
	line	104
	
i2l1100:
;softPWM.c: 104: if (++i2c_buff_index == sizeof(i2c_tx_buff)) {
	lfsr	2,(c:_i2c_buff_index)	;volatile
	incf	postinc2
	movlw	0
	addwfc	postdec2
	movf	postinc2,w
	xorlw	02h
	iorwf	postdec2,w
	btfss	status,2
	goto	i2u31_41
	goto	i2u31_40
i2u31_41:
	goto	i2l259
i2u31_40:
	line	105
	
i2l1102:
;softPWM.c: 105: i2c_buff_index = 0;
	movlw	high(0)
	movwf	((c:_i2c_buff_index+1)),c	;volatile
	movlw	low(0)
	movwf	((c:_i2c_buff_index)),c	;volatile
	line	106
;softPWM.c: 106: SSPBUF = 0;
	movlw	low(0)
	movwf	((c:4041)),c	;volatile
	line	107
	
i2l1104:
;softPWM.c: 107: CKP = 1;
	bsf	c:(32308/8),(32308)&7	;volatile
	line	108
	
i2l1106:
;softPWM.c: 108: SSPIF = 0;
	bcf	c:(31987/8),(31987)&7	;volatile
	goto	i2l259
	line	109
	
i2l257:
	line	110
;softPWM.c: 109: }
;softPWM.c: 110: }
	goto	i2l259
	line	111
	
i2l256:
	line	113
;softPWM.c: 111: else
;softPWM.c: 112: {
;softPWM.c: 113: CKP=1;
	bsf	c:(32308/8),(32308)&7	;volatile
	goto	i2l259
	line	114
	
i2l258:
	goto	i2l259
	
i2l255:
	goto	i2l259
	
i2l251:
	goto	i2l259
	
i2l247:
	goto	i2l259
	line	115
	
i2l244:
	line	116
	
i2l259:
	movff	??_isr+16,tablat+0
	movff	??_isr+15,tblptru+0
	movff	??_isr+14,tblptrh+0
	movff	??_isr+13,tblptrl+0
	movff	??_isr+12,prodh+0
	movff	??_isr+11,prodl+0
	movff	??_isr+10,fsr2h+0
	movff	??_isr+9,fsr2l+0
	movff	??_isr+8,fsr1h+0
	movff	??_isr+7,fsr1l+0
	movff	??_isr+6,fsr0h+0
	movff	??_isr+5,fsr0l+0
	movff	??_isr+4,pclat+1
	movff	??_isr+3,pclat+0
	retfie f
	opt stack 0
GLOBAL	__end_of_isr
	__end_of_isr:
	signat	_isr,88
	GLOBAL	__activetblptr
__activetblptr	EQU	0
	psect	intsave_regs,class=BIGRAM,space=1
psect	intcode
	PSECT	rparam,class=COMRAM,space=1
	GLOBAL	__Lrparam
	FNCONF	rparam,??,?
GLOBAL	__Lparam, __Hparam
GLOBAL	__Lrparam, __Hrparam
__Lparam	EQU	__Lrparam
__Hparam	EQU	__Hrparam
	end
