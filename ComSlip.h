/*********************************************************************************************************
 * File             : ComSlip.h
 * State            : OK
 * Description      : Implementation of SLIP layer
 * Author           : TOLA
 *
 * Created on 03 July 2014, 10:43
 *
 * Disclaimer:	This code is provide by IMST GmbH on an "As IS" basis without any warranties.
 *
 *********************************************************************************************************/

#ifndef COMSLIP_H
#define	COMSLIP_H

#include <stdbool.h>
#include <GenericTypeDefs.h>

#ifdef	__cplusplus
extern "C" {
#endif

void SendMessage(UINT8* msg, UINT8 msgLength);


#ifdef	__cplusplus
}
#endif

#endif	/* COMSLIP_H */

