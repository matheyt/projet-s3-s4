/***********************************************************************************************************************
 * File             : newmain.c
 * Version          : 1.0
 * State            : Under development
 *                    Testing with XLP 16-BIT BOARD and SK-iM880A, Long Range Radio Starter Kit
 * Description      : Communication over UART1 between PIC24F16KA102 and long range radio module LoRa (WiMOD SK-IM880A),
 *                    10-bits ADC conversion
 *                    16-bits PWM control with timer2
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
#include "uart.h"
#include "adc.h"
#include <math.h>
#include "CRC16.h"
#include "SendUartMessage.h"
#include "ComSlip.h"

extern UINT8 volatile gl_synchro, gl_trame[2][40];
extern float volatile gl_pr2;

int main() {

    UINT8 static s_framNum = 0;
    float pwm_val;
    float r5, ADCValue5, y5, x5; // Variable measurement by ADC for AN5
    float r11, ADCValue11, y11, x11; // Variable measurement by ADC for AN11
    char Message[80]; // Payload size 100
    char pwm[10];
    unsigned int numTram = 0;

    /**************** Initialisation of destination address *****************/
    Addr ad;
    ad.destgroupAddr = DEST_GROUP_ADDR;
    ad.destdevAddr = DEST_DEVICE_ADDR;


   
    /********** Setup UART *********/
    UART1Setup(BAUDRATE, FOSC);

    /* Setup I/O port (For testing LED) */
    TRISBbits.TRISB8 = 0;           // Set port B8 as output
    TRISBbits.TRISB15 = 0;          // Set port B15 as output
    gl_synchro = 0;
    
    //printf("Sampling:.....\n\r");

    while (1) {

     
        /************************** Send Message ********************************/
        // Convert float->dexibel->string and insert string to array string using sprintf
        LATBbits.LATB8 = 0;
       sprintf(Message, "bonjour");
       // sprintf(Message, "%d",numTram++);
        SendUMessage(ad, Message, strlen(Message));
        __delay_ms(100);            // Without delay 500ms for each sending, WiMOD module will block for receiver part

       
    }
}