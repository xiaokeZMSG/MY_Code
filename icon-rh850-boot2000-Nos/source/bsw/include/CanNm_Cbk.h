/*-------------------------------- Arctic Core ------------------------------
 * Copyright (C) 2013, ArcCore AB, Sweden, www.arccore.com.
 * Contact: <contact@arccore.com>
 * 
 * You may ONLY use this file:
 * 1)if you have a valid commercial ArcCore license and then in accordance with  
 * the terms contained in the written license agreement between you and ArcCore, 
 * or alternatively
 * 2)if you follow the terms found in GNU General Public License version 2 as 
 * published by the Free Software Foundation and appearing in the file 
 * LICENSE.GPL included in the packaging of this file or here 
 * <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>
 *-------------------------------- Arctic Core -----------------------------*/


#ifndef CANNM_CBK_H_
#define CANNM_CBK_H_

/* We need this to export pdu id's */
#include "CanNm.h"

void CanNm_TxConfirmation( PduIdType canNmTxPduId );
void CanNm_RxIndication( PduIdType RxPduId, PduInfoType *PduInfoPtr );
void CanNm_BusOff_SendCtrl( void) ;


#endif /* CANNM_CBK_H_ */
