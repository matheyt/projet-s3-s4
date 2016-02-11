/**********************************************************************************************************
 * File             : SendUartMessage.c
 * State            : OK
 * Description      : Sending radio messages with WiMOD LR Host Controller Interface (WiMOD SK-IM880A)
 * Author           : TOLA
 *
 * Created on 03 July 2014, 10:43
 *
 **********************************************************************************************************/

#define DstID                               0x03    // Identifies a radio link service access point
#define MsgID                               0x01    // Identifies the type of message
#define WIMODLR_HCI_MSG_MAX_PAYLOAD_SIZE    247     // Maximum size of payload size

#include "SendUartMessage.h"


// Send message without acknowlegement (unrelibale)
void SendUMessage(Addr adresse, char* payload, UINT8 sizePayload)
{
    int i;
    UINT16 crc16;
    
    // Size User Payload + (1) DstID + (1) MsgID + (1) destgroupAddr + (2) destdevAddr + (2) CRC16
    UINT8 sizeHCI = sizePayload + 7;      
    UINT8 msgHCI[sizeHCI];


    if (sizePayload > WIMODLR_HCI_MSG_MAX_PAYLOAD_SIZE)
    {
        printf("Payload is oversize\n");
    }
    else
    {
/**************** Create HCI Message *******************/
// The Radio Ctrl, Radio Stack Field and Source Address Fields are automatically added by the firmware itself.
// Ref. WiMODLR_HCI_Spec_V1.3 page 31.
        
        msgHCI[0] = DstID;
        msgHCI[1] = MsgID;
        msgHCI[2] = adresse.destgroupAddr;
        msgHCI[3] = adresse.destdevAddr;
        msgHCI[4] = adresse.destdevAddr >> 8;
        for (i=5 ; i<(sizeHCI) ; i++)
        {
            msgHCI[i] = payload[i-5];
        }
        crc16 = CRC16_Calc(msgHCI,sizeHCI-2, CRC16_INIT_VALUE);    // calulate CRC16
        msgHCI[sizeHCI-2] = crc16;                                 // append CRC16
        msgHCI[sizeHCI-1] = crc16 >> 8;
        SendMessage(msgHCI,sizeHCI);                               // forward message to SLIP Layer
    }
}