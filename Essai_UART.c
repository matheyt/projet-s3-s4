/***********************************************************************************************************************
 * File             : Essai_UART.c
 * Version          : 1.0
 * State            : Under development
 *                    Testing with XLP 16-BIT BOARD and SK-iM880A, Long Range Radio Starter Kit
 * Description      : Envoi un seul caractére sur UART
 * Author           : TOLA
 * Microcontroller  : PIC24F16KA102
 * Compiler         : MPLAB XC16 v1.21
 * IDE              : Microchip MPLAB X v2.10
 * Programmer       : PICKit3
 * Header Files     : AllParameters.h ; ComSlip.h ; ConfigurationBits.h ; CRC16.h ; PIC24FConfig.h ; SendUartMessage.h
 * Source Files     : ComSlip.c ; CRC16.c ; PIC24FConfig.c ; SendUartMessage.c ; Service.c
 * Reference        : http://www.wireless-solutions.de/products/radiomodules/im880a
 *                    PIC24F16KA102 datasheet
 *                    XLP 16-bit board User's Guide   
 *
 * Created on 03 July 2014, 10:43
 *
 ***********************************************************************************************************************/


/************ Global Variable *******/
#define FCY              16000000UL      // Declare FCY for a 8 MHz instruction rate
#define USE_AND_OR                       // To enable AND_OR mask setting


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <p24F16KA102.h>
#include "AllParameters.h"
#include "ConfigurationBits.h"
#include "PIC24FConfig.h"
#include <libpic30.h>
#include <uart.h>
#include <adc.h>
#include <math.h>
#include "CRC16.h"
#include "SendUartMessage.h"
#include "ComSlip.h"

#define MASK_PORTB 0x00FF

int main() {
    // Configure PORTB <15:8> as inputs and PORTB <7:0> as outputs
    TRISB = MASK_PORTB;
    // Set RB8 to 1 ~ 3.3V
    //PORTBbits.RB8 = 1;
    while (1) {
        LATBbits.LATB8 = 1;
    }
}
