/****************************************************************
 * File             : PIC24FConfig.c
 * State            : OK
 * Description      : Configuration for PIC24F16KA102
 * Author           : TOLA
 *
 * Created on 03 July 2014, 10:43
 *
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "uart.h"
#include "adc.h"
#include "PIC24FConfig.h"
#include "AllParameters.h"


float volatile gl_pr2;          // Global variable for PWM Module

/**************************************************************************************************************
 * Setup PWM and Timer 2 : Initializes the PWM as a function of parameters fosc, fpwm and dutyCycleIni
 *                         returns OK (1) if everything went well, return ERROR (0) if problem acquired
 * Input parameters      : fosc,float, frequency oscillator in mega hertz (MHZ)
 *                         fpwm,float, frequency required for PWM period in hertz (Hz)
 *                         dytyCycleIni,float between 0 and 1, value required to initialize PWM pulse width
 *************************************************************************************************************/
char PWMSetup(float fosc, float fpwm, float dutyCycleIni)
{

    UINT16 prescal[4] = {1,8,64,256};
    int i =0;

    gl_pr2 = fosc*1E6*4.0/(2.0*fpwm*((float) prescal[i]));      // Choosing automatic prescal

    while (((gl_pr2-1) > 65535.0) && (i<3))
    {
        gl_pr2 = gl_pr2*prescal[i]/prescal[i+1];
        i = i+1;
    }

    if((gl_pr2-1) > 65535.0)
    {
        return ERROR;
    }
    else
    {
        gl_pr2 = gl_pr2 - 1;
        
        // PWM Configuration
        OC1CON = 0x0000;                            // Turn off Output Compare 1 Module
        OC1R   = (UINT16) (dutyCycleIni*gl_pr2);    // Initialize Compare Register1
        OC1RS  = (UINT16) (dutyCycleIni*gl_pr2);    // Initialize Secondary Compare Register1 ( Set duty cycle)
        OC1CONbits.OCSIDL = 0;                      // Output Compare 1 will continue to operate in CPU Idle mode;
        OC1CONbits.OCTSEL = 0;                      // Timer2 is the clock source for Output Compare 1
        OC1CONbits.OCM    = 0x06;                   // PWM mode on OC1, Fault pin; OCF1 disabled
        PR2               = (UINT16) gl_pr2;
    
        // Timer2 Configuration
        T2CONbits.TCS     = 0;                      // Using internal Clock source (Fosc/2)
        T2CONbits.T32     = 0;                      // Timer2 and Timer3 act as two 16-bit timers
        T2CONbits.TCKPS   = i;                      // Set prescale
        T2CONbits.TSIDL   = 0;                      // Continue module operation in Idle mode
        T2CONbits.TON     = 1;                      // Start Timer2
        
        return OK;
    }
}


/**********************************************************************************************************
 * Calculate the value of 16 bits to be transmitted to the PWM duty cycle as a function of the parameter
 * valDutyCycle (float between 0 and 1) and the global variable gl_pr2 which corresponds to the frequency
 * which is updated by PWMSetup
 **********************************************************************************************************/
void setDutyCycle(float valDutyCycle)
{
    OC1RS = (UINT16) (valDutyCycle*gl_pr2);       // Value of duty cycle are in interval R[0:1]
}


/**************************************************************************************************************
 * UART1Setup : Configuration of uart1 and calculate the value of 16 bits BRG(Baud Rate Generator) as a
 *              function of parameters baudrate and fosc
 * Parameters : baudrate,float, desired speed
 *              fosc,float, frequency oscillator in mega hertz (MHZ)
 *************************************************************************************************************/
void UART1Setup(float baudrate, float fosc)
{

    U1MODE = 0xA808;             // Turn on module
    U1STA  = 0x8400;             // Set interrupts
    U1MODEbits.BRGH = 1;         // Disable the divider
    U1BRG = ((fosc*1E6*4.0/2.0)/(4.0*baudrate))/2-1.0;   //set baud speed
   /* Calculating the baudrate value of UART
    * UxBRG = (Fcy/(4*baud rate))-1 ;
    * Fcy = Fosc/2
    * Example: we use UART1 with baud rate 115200 and oscillator 8MHz
    * Fosc = 8MHz ; If you are using PLL, the oscillator will multiple with 4: 8MHz * 4 = 32MHz
    * So UxBRG = 34
    */

   AD1PCFG = AD1PCFG | 0x10;    //  Obligatoire car positionne entree Rx qui est aussi RB2 comme une entree numerique et non pas analogique
   IFS0bits.U1RXIF = 0;         // Reset RX interrupt flag
   U1STAbits.UTXEN = 1;         // Transmit enabled, U1TX pin controlled by UART1
   IEC0bits.U1RXIE = 1;         // enable UART1 Received intrrupt
   IPC2bits.U1RXIP = 4;         // UART1 Received interrupt priority level 4
   INTCON1bits.NSTDIS = 1;      // Interrupt nesting is disabled
   SRbits.IPL = 3;              //Prority level 3
}


//UART1 transmit function, parameter Ch is the character to be sended
void UART1PutChar(char Ch)
{
   //transmit ONLY if TX buffer is full
   while(U1STAbits.UTXBF == 1);
       U1TXREG = Ch;
}

//UART1 receive function, returns the value received.
char UART1GetChar()
{
    char Rxdata;
    //wait for buffer to fill up, wait for interrupt
    while(IFS0bits.U1RXIF == 0);
    Rxdata = U1RXREG;
    IFS0bits.U1RXIF = 0;        //reset interrupt

    return Rxdata;
}

/**************************************************************************************************************
 * UART2Setup : Configuration of uart2 and calculate the value of 16 bits BRG(Baud Rate Generator) as a
 *              function of parameters baudrate and fosc
 * Parameters : baudrate,float, desired speed
 *              fosc,float, frequency oscillator in mega hertz (MHZ)
 *************************************************************************************************************/
void UART2Setup(float baudrate, float fosc)
{
    U2MODE = ENABLE_BIT | IRDA_ENABLE_BIT | WAKE_ENABLE | LOOPBACK_MODE | ENABLE_AUTO_MODE |  PARITY_DATA_SELECT | STOP_BIT_SELECT;
    U2MODEbits.BRGH = 1;         // Disable the divider
    U2BRG = ((fosc*1E6*4.0/2.0)/(4.0*baudrate))/2-1.0;   //set baud speed

    IFS1bits.U2RXIF = 0;
    
    //TODO Terminer le setup possible demande au professeur pour choisir les registres a initilisé


}
//UART2 receive function, returns the value received.
char UART2GetChar()
{
    char car;
    while(IFS1bits.U2RXIF == 0);
    car = U1RXREG;
    IFS1bits.U2RXIF = 0;

    return car;
}



/*******************************************************************************************************
 * Setup 10 bits ADC converter using channel 5 and 11 whose alternates between multiplexer A and B
 *******************************************************************************************************/
void ADCSetup()
{
AD1CON1 = 0x80E4;       // SSRC conversion trigger source select bits: auto-converted
                        // Data output format bits : integer
                        // ASAM A/D Sample Auto-Start bit:  auto-set
                        // A/D sample/hold amplifier is holding

AD1CON2 = 0x003D;       // Choosing Vdd and Vss as Vr+ and Vr-
                        // SMPI<3:0> = 1111: Interrupts at the completion of conversion for each 16th sample/convert sequence
                        // BUFS = 0:A/D is currently filling buffer, 00-07;
                        // BUFM = 0:Buffer is configured as one 16-word buffer
                        // ALTS = 1:Uses MUX A input multiplexer settings for first sample,
                        // then alternates between MUX B and MUX A input multiplexer settings for all subsequent samples

AD1CON3 = 0x1F02;       // For correct A/D conversions, the A/D conversion clock (TAD) must be selected to ensure a minimum TAD time of 75 ns.
                        // Choose 31 TAD and 4*Tcy
/*
 * The A/D conversion clock period
 * TAD = Tcy(ADCS + 1) ; Tcy = 2/Fosc
 * Example: choosing ADCS(bits): 0001 so ADCS + 1(bit) = 0001 + 1 = 0010 correpsond to 4 ; Fosc = 4 * 8MHz
 * => TAD = (2/4*8E6)*4 = 250 ns > 75ns.
 */

AD1PCFG = 0xF7DF;       // RB13/AN11 and RB3/AN5 configure as analog in put
AD1CSSL = 0xFFFF;	// Corresponding analog channel, ANxx, is selected for sequential scanning on MUX A; for using multiple ADC channel
AD1CHS  = 0x050B;       // Connect RB3/AN5 for MUXB and RB13/AN11 for MUXA as channel 0 input
AD1CON1bits.ADON = 1;   // Turn ADC on

}

