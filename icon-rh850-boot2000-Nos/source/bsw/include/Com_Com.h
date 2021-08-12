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








#ifndef COM_COM_H_
#define COM_COM_H_

#include <Com.h>
#include <PduR.h>
void Com_GetPduBufferBysignalId(			const Com_SignalIdType signalId,const void *PduData);//add by mgd on 20210714

/* @req COM197 */
uint8_t Com_SendSignal(Com_SignalIdType SignalId, const void *SignalDataPtr);
/* @req COM198 */
uint8_t Com_ReceiveSignal(Com_SignalIdType SignalId,Com_SignalGroupIdType GroupSignalId,const boolean isGroupSignal, void* SignalDataPtr);

/* @req COM690 */
uint8_t Com_ReceiveDynSignal(Com_SignalIdType SignalId, void* SignalDataPtr, uint16_t* Length);
/* @req COM627 */
uint8_t Com_SendDynSignal(Com_SignalIdType SignalId, const void* SignalDataPtr, uint16_t Length);
/* @req COM001 */
Std_ReturnType Com_TriggerTransmit(PduIdType TxPduId, PduInfoType *PduInfoPtr);
/* @req COM348 */
void Com_TriggerIPDUSend(PduIdType PduId);
/* @req COM123 */
void Com_RxIndication(PduIdType RxPduId, PduInfoType* PduInfoPtr);
/* @req COM124 */
void Com_TxConfirmation(PduIdType TxPduId);


/* Signal Groups */
/* @req COM200 */
uint8_t Com_SendSignalGroup(Com_SignalGroupIdType SignalGroupId);
/* @req COM201 */
uint8_t Com_ReceiveSignalGroup(Com_SignalGroupIdType SignalGroupId);
/* @req COM199 */
void Com_UpdateShadowSignal(Com_SignalIdType SignalId, const void *SignalDataPtr);
/* @req COM202 */
void Com_ReceiveShadowSignal(Com_SignalIdType SignalId, void *SignalDataPtr);


#endif /* COM_COM_H_ */
