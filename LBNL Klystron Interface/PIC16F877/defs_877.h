// DEFS_877
//
// Standard definitions for PIC16F877
//
// Copyright, Peter H. Anderson, Baltimore, MD, June, '99

#define byte int

#nolist

//#define FALSE 0
//#define TRUE !FALSE

#byte TMR0 = 0x01
#byte PCL = 0x02
#byte STATUS = 0x03
#byte FSR = 0x04
#byte PORTA = 0x05
#byte PORTB = 0x06
#byte PORTC = 0x07

#byte PORTD   = 0x08
#byte PORTE   = 0x09
#byte PCLATH = 0x0a
#byte INTCON = 0x0b

#byte PIR1    = 0x0c
#byte PIR2    = 0x0d
#byte TMR1L   = 0x0e
#byte TMR1H   = 0x0f

#byte T1CON   = 0x10
#byte TMR2    = 0x11
#byte T2CON   = 0x12
#byte SSPBUF  = 0x13
#byte SSPCON  = 0x14
#byte CCPR1L  = 0x15
#byte CCPR1H  = 0x16
#byte CCP1CON = 0x17
#byte RCSTA   = 0x18
#byte TXREG   = 0x19
#byte  RCREG   = 0x1a
#byte CCPR2L  = 0x1b
#byte CCPR2H  = 0x1c
#byte CCP2CON = 0x1d
#byte ADRESH  = 0x1e
#byte ADCON0  = 0x1f

#byte OPTION_REG = 0x81
#byte TRISA = 0x85
#byte TRISB = 0x86

#byte TRISC   = 0x87
#byte TRISD   = 0x88
#byte TRISE   = 0x89

#byte PIE1    = 0x8c
#byte PIE2    = 0x8d
#byte PCON    = 0x8e

#byte SSPCON2 = 0x91
#byte PR2     = 0x92
#byte SSPADD  = 0x93
#byte SSPSTAT = 0x94

#byte TXSTA   = 0x98
#byte SPBRG   = 0x99

#byte ADRESL  = 0x9e
#byte ADCON1  = 0x9f

#byte EEDATA  = 0x10c
#byte EEADR   = 0x10d
#byte EEDATH  = 0x10e
#byte EEADRH  = 0x10f

#byte EECON1  = 0x18c
#byte EECON2  = 0x18d

// STATUS bits
#define IRP 8
#define RP1 6
#define RP0     5
#define TO 4
#define PD 3
#define ZERO    2
#define DC      1
#define C   0

//      PORTA bits

#bit porta5 = PORTA.5
#bit porta4 = PORTA.4
#bit porta3 = PORTA.3
#bit porta2 = PORTA.2
#bit porta1 = PORTA.1
#bit porta0 = PORTA.0

#define RA5     5
#define RA4     4
#define RA3     3
#define RA2     2
#define RA1     1
#define RA0     0

//      PORTB bits

#bit rb7 = PORTB.7
#bit rb6 = PORTB.6
#bit rb5 = PORTB.5
#bit rb4 = PORTB.4
#bit rb3 = PORTB.3
#bit rb2 = PORTB.2
#bit rb1 = PORTB.1
#bit rb0 = PORTB.0

#define RB7     7
#define RB6     6
#define RB5     5
#define RB4     4
#define RB3     3
#define RB2     2
#define RB1     1
#define RB0     0

//      PORTC bits
#bit portc7 = PORTC.7
#bit portc6 = PORTC.6
#bit portc5 = PORTC.5
#bit portc4 = PORTC.4
#bit portc3 = PORTC.3
#bit portc2 = PORTC.2
#bit portc1 = PORTC.1
#bit portc0 = PORTC.0

#define RC7     7
#define RC6     6
#define RC5     5
#define RC4     4
#define RC3     3
#define RC2     2
#define RC1     1
#define RC0     0

//      PORTD bits
#bit portd7 = PORTD.7
#bit portd6 = PORTD.6
#bit portd5 = PORTD.5
#bit portd4 = PORTD.4
#bit portd3 = PORTD.3
#bit portd2 = PORTD.2
#bit portd1 = PORTD.1
#bit portd0 = PORTD.0

#define RD7     7
#define RD6     6
#define RD5     5
#define RD4     4
#define RD3     3
#define RD2     2
#define RD1     1
#define RD0     0

// PORTE bits
#bit porte2 = PORTE.2
#bit porte1 = PORTE.1
#bit porte0 = PORTE.0

#define RE2     2
#define RE1     1
#define RE0     0

// INTCON bits

#bit gie  = INTCON.7
#bit peie  = INTCON.6
#bit  t0ie = INTCON.5
#bit inte = INTCON.4
#bit rbie = INTCON.3
#bit t0if = INTCON.2
#bit intf = INTCON.1
#bit  rbif = INTCON.0


// PIR1 bits
#bit pspif = PIR1.7
#bit adif = PIR1.6
#bit rcif = PIR1.5
#bit txif = PIR1.4
#bit sspif = PIR1.3
#bit ccp1if = PIR1.2
#bit tmr2if = PIR1.1
#bit tmr1if = PIR1.0

// PIR2 bits
#bit eeif = PIR2.4
#bit bclif = PIR2.3
#bit ccp2if = PIR2.0

// T1CON bits
#bit t1ckps1 = T1CON.5
#bit t1ckps0 = T1CON.4
#bit t1oscen = T1CON.3
#bit t1sync  = T1CON.2
#bit tmr1cs  = T1CON.1
#bit tmr1on  = T1CON.0

// T2CON bits
#bit toutps3 = T2CON.6
#bit toutps2 = T2CON.5
#bit toutps1 = T2CON.4
#bit toutps0 = T2CON.3
#bit tmr2on  = T2CON.2
#bit t2ckps1 = T2CON.1
#bit t2ckps0 = T2CON.0

// SSPCON bits
#bit wcol = SSPCON.7
#bit sspov = SSPCON.6
#bit sspen = SSPCON.5
#bit ckp = SSPCON.4
#bit sspm3 = SSPCON.3
#bit sspm2 = SSPCON.2
#bit sspm1 = SSPCON.1
#bit sspm0 = SSPCON.0

// CCP1CON bits
#bit ccp1x = CCP1CON.5
#bit ccp1y = CCP1CON.4
#bit ccp1m3 = CCP1CON.3
#bit ccp1m2 = CCP1CON.2
#bit ccp1m1 = CCP1CON.1
#bit ccp1m0 = CCP1CON.0

// RCSTA bits
#bit spen = RCSTA.7
#bit rx9  = RCSTA.6
#bit sren = RCSTA.5
#bit cren = RCSTA.4
#bit adden = RCSTA.3
#bit ferr = RCSTA.2
#bit oerr = RCSTA.1
#bit rx9d = RCSTA.0

// CCP2CON bits
#bit ccp2x  = CCP2CON.5
#bit ccp2y  = CCP2CON.4
#bit ccp2m3 = CCP2CON.3
#bit ccp2m2 = CCP2CON.2
#bit ccp2m1 = CCP2CON.1
#bit ccp2m0 = CCP2CON.0


//  ADCON0 bits
#bit adcs1 = ADCON0.7
#bit adcs0 = ADCON0.6
#bit chs2  = ADCON0.5
#bit chs1  = ADCON0.4
#bit chs0  = ADCON0.3
#bit adgo  = ADCON0.2

#bit adon  = ADCON0.0

//  OPTION bits
#bit not_rbpu = OPTION_REG.7
#bit intedg = OPTION_REG.6
#bit t0cs = OPTION_REG.5
#bit t0se = OPTION_REG.4
#bit psa = OPTION_REG.3
#bit ps2 = OPTION_REG.2
#bit ps1 = OPTION_REG.1
#bit ps0 = OPTION_REG.0


//      TRISA bits
#bit trisa5 = TRISA.5
#bit  trisa4 = TRISA.4
#bit trisa3 = TRISA.3
#bit  trisa2 = TRISA.2
#bit trisa1 = TRISA.1
#bit trisa0 = TRISA.0

//      TRISB bits
#bit trisb7 = TRISB.7
#bit trisb6 = TRISB.6
#bit trisb5 = TRISB.5
#bit trisb4 = TRISB.4
#bit trisb3 = TRISB.3
#bit trisb2 = TRISB.2
#bit trisb1 = TRISB.1
#bit trisb0 = TRISB.0

//      TRISC bits
#bit trisc7 = TRISC.7
#bit trisc6 = TRISC.6
#bit trisc5 = TRISC.5
#bit trisc4 = TRISC.4
#bit trisc3 = TRISC.3
#bit trisc2 = TRISC.2
#bit trisc1 = TRISC.1
#bit trisc0 = TRISC.0

//      TRISD bits
#bit trisd7 = TRISD.7
#bit trisd6 = TRISD.6
#bit trisd5 = TRISD.5
#bit trisd4 = TRISD.4
#bit trisd3 = TRISD.3
#bit trisd2 = TRISD.2
#bit trisd1 = TRISD.1
#bit trisd0 = TRISD.0

// TRISE bits
#bit ibf    = TRISE.7
#bit obf    = TRISE.6
#bit ibov   = TRISE.5
#bit pspmode = TRISE.4

#bit trise2 = TRISE.2
#bit trise1 = TRISE.1
#bit trise0 = TRISE.0

// PIE1 bits
#bit pspie = PIE1.7
#bit adie  = PIE1.6
#bit rcie  = PIE1.5
#bit txie  = PIE1.4
#bit sspie  = PIE1.3
#bit ccp1ie  = PIE1.2
#bit tmr2ie  = PIE1.1
#bit tmr1ie  = PIE1.0

// PIE2 bits
#bit eeie = PIE2.4
#bit bclie = PIE2.3
#bit ccp2ie  = PIE2.0

// PCON bits
#bit por  = PCON.1
#bit bor = PCON.0

// SSPCON2
#bit gcen = SSPCON2.7
#bit ackstat = SSPCON2.6
#bit ackdt = SSPCON2.5
#bit acken = SSPCON2.4
#bit rcen = SSPCON2.3
#bit pen = SSPCON2.2
#bit rsen = SSPCON2.1
#bit sen = SSPCON2.0

//      SSPSTAT bits
#bit stat_smp = SSPSTAT.7
#bit stat_cke = SSPSTAT.6
#bit stat_da = SSPSTAT.5
#bit stat_p  = SSPSTAT.4
#bit stat_s  = SSPSTAT.3
#bit stat_rw = SSPSTAT.2
#bit stat_ua = SSPSTAT.1
#bit stat_bf = SSPSTAT.0

// TXSTA bits
#bit csrc  = TXSTA.7
#bit tx9  = TXSTA.6
#bit txen  = TXSTA.5
#bit sync  = TXSTA.4

#bit brgh  = TXSTA.2
#bit trmt  = TXSTA.1
#bit tx9d  = TXSTA.0

// ADCON1 bits
#bit adfm = ADCON1.7
#bit pcfg3 = ADCON1.3
#bit pcfg2  = ADCON1.2
#bit pcfg1  = ADCON1.1
#bit pcfg0 = ADCON1.0

//  EECON1
#bit eepgd = EECON1.7
#bit wrerr = EECON1.3
#bit wren = EECON1.2
#bit wr = EECON1.1
#bit rd = EECON1.0

#define CONFIG_ADDR 0x2007
#define FOSC0  0x01
#define FOSC1  0x02
#define WDTE  0x04
#define PWRTE  0x08
#define CP0  0x10
#define CP1  0x20

#list
