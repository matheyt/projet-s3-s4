/*********************************************************************************************************
 * File             : ComSlip.c
 * State            : OK
 * Description      : Implementation of SLIP layer
 * Author           : TOLA
 *
 * Created on 03 July 2014, 10:43
 *
 * Disclaimer:	This code is provide by IMST GmbH on an "As IS" basis without any warranties.
 *
 *********************************************************************************************************/

#include "ComSlip.h"
#include "PIC24FConfig.h"

//------------------------------------------------------------------------------
//
//  Protocol Definitions
//
//------------------------------------------------------------------------------

// SLIP Protocol Characters
#define SLIP_END	0xC0
#define	SLIP_ESC        0xDB
#define	SLIP_ESC_END	0xDC
#define	SLIP_ESC_ESC	0xDD

// call UART to transmit one single character
#define SendByte(txByte)            UART1PutChar(txByte)

//------------------------------------------------------------------------------
//
//	SLIP_SendMsg:		send packet 
//	
//-----------------------------------------------------------------------
void SendMessage(UINT8* msg, UINT8 msgLength)
{
    // send start of SLIP message
    SendByte(SLIP_END);

    // iterate over all message bytes
    while(msgLength--)
    {
        switch (*msg)
        {
                case SLIP_END:
                    SendByte(SLIP_ESC);
                    SendByte(SLIP_ESC_END);
                    break;

                case SLIP_ESC:
                    SendByte(SLIP_ESC);
                    SendByte(SLIP_ESC_ESC);
                    break;

                default:
                    SendByte(*msg);
                    break;
        }
        // next byte
        msg++;
    }

    // send end of SLIP message
    SendByte(SLIP_END);

}
