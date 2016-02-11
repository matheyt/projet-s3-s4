/****************************************************************
 * File             : PIC24FConfig.h
 * State            : OK
 * Description      : Configuration for PIC24F16KA102
 * Author           : TOLA
 *
 * Created on 03 July 2014, 10:43
 *
 ***************************************************************/

#ifndef PIC24FCONFIG_H
#define	PIC24FCONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include "uart.h"
#include "adc.h"

#ifdef	__cplusplus
extern "C" {
#endif


/**************************************************************************************************************
 * Setup PWM and Timer 2 : Initializes the PWM as a function of parameters fosc, fpwm and dutyCycleIni
 *                         returns OK (1) if everything went well, return ERROR (0) if problem acquired
 * Input parameters      : fosc,float, frequency oscillator in mega hertz (MHZ)
 *                         fpwm,float, frequency required for PWM period in hertz (Hz)
 *                         dytyCycleIni,float between 0 and 1, value required to initialize PWM pulse width
 *************************************************************************************************************/
char PWMSetup(float fosc, float fpwm, float dutyCycleIni);

/**********************************************************************************************************
 * Calculate the value of 16 bits to be transmitted to the PWM duty cycle as a function of the parameter
 * valDutyCycle (float between 0 and 1) and the global variable gl_pr2 which corresponds to the frequency
 * which is updated by PWMSetup
 **********************************************************************************************************/
void setDutyCycle(float valDutyCycle);

/**************************************************************************************************************
 * UART1Setup : Configuration of uart1 and calculate the value of 16 bits BRG(Baud Rate Generator) as a
 *              function of parameters baudrate and fosc
 * Parameters : baudrate,float, desired speed
 *              fosc,float, frequency oscillator in mega hertz (MHZ)
 *************************************************************************************************************/
void UART1Setup(float baudrate, float fosc);

//UART transmit function, parameter Ch is the character to be sended
void UART1PutChar(char Ch);

//UART receive function, returns the value received.
char UART1GetChar();

/*******************************************************************************************************
 * Setup 10 bits ADC converter using channel 5 and 11 whose alternates between multiplexer A and B
 *******************************************************************************************************/
void ADCSetup();


#ifdef	__cplusplus
}
#endif

#endif	/* PIC24CONFIG_H */

