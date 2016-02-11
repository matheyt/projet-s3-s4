/*************************************************************************************************************
 * File             : Service.c
 * State            : OK
 * Description      : Display the character received on interruption with speed 115200 (baudrate 115200)
 * Author           : TOLA
 *
 * Created on 24 July 2014, 15:33
 *
 ************************************************************************************************************/

#include "xc.h"
#include "uart.h"
#include "AllParameters.h"
#include <string.h>

UINT8 volatile gl_synchro,gl_trame[2][40];
UINT8 volatile gl_nbovr=0;

void __attribute__((__interrupt__, no_auto_psv)) _U1RXInterrupt(void)
{
    UINT16 static s_state = 0;
    UINT16 static s_i = 0;
    UINT8 static s_framNum = 0;
    UINT8 charRec;

    if(U1STAbits.OERR)
    {
        gl_nbovr++;
    }
    charRec = U1RXREG;
    switch (s_state)
    {
            case 0:
            {
                if(charRec == SLIP_END)
                    s_state = 1;
            }
                break;
            case 1:
            {
                if(charRec == SLIP_END)
                    s_state = 2;
                else
                    s_state = 0;
            }
                break;
           case 2:
           {
                if(charRec == SLIP_END)
                {
                    s_state = 1;
                    s_i = 0;                   
                    s_framNum = (s_framNum+1)%2;
                    if(strchr(gl_trame[s_framNum],SEPARATOR))
                        gl_synchro = 1;
                }
                else
                {
                    gl_trame[s_framNum][s_i++] = charRec;
                }
                break;
           }
    }
    IFS0bits.U1RXIF = 0;        // Reset interrupt flag
}