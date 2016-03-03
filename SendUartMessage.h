/**********************************************************************************************************
 * File             : SendUartMessage.h
 * State            : OK
 * Description      : Sending radio messages with WiMOD LR Host Controller Interface (WiMOD SK-IM880A)
 * Author           : TOLA
 *
 * Created on 03 July 2014, 10:43
 *
 **********************************************************************************************************/

#ifndef SENDUARTMESSAGE_H
#define	SENDUARTMESSAGE_H

#include <GenericTypeDefs.h>
#include <stdbool.h>
#include <stdio.h>
#include "CRC16.h"
#include "comSlip.h"

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct
{
    UINT8  destgroupAddr;
    UINT16 destdevAddr;
    UINT8  sourcegroupAddr;
    UINT16 sourcedevAddr;
}Addr ;

void SendUMessage(Addr adresse, char* payload, UINT8 sizePayload);


#ifdef	__cplusplus
}
#endif

#endif	/* SENDUARTMESSAGE_H */

