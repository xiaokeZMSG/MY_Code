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


//lint -esym(960,8.7)	PC-Lint misunderstanding of Misra 8.7 for Com_SystenEndianness and endianess_test



//#include "standard.h"
#include <stdlib.h>
#include <string.h>
#include "Com_Arc_Types.h"
#include "Com.h"
#include "Com_Internal.h"
#include "Com_misc.h"
#include "debug.h"
//#include "PduR.h"
#include "CanIf.h"
#include "Det.h"
#include "generic/Cpu.h"

//#include "apc_can.h"

#include "CanApp.h"

#include "Dcm_Internal.h"
#include "m_gpio.h"

/* Declared in Com_Cfg.c */
extern const ComRxIPduCalloutType ComRxIPduCallouts[];
extern const ComTxIPduCalloutType ComTxIPduCallouts[];
extern const ComNotificationCalloutType ComNotificationCallouts[];
//extern bool IsFirstSendEpsMode;

Com_BufferPduStateType Com_BufferPduState[COM_MAX_N_IPDUS];

//add by mgd on 20210714

void Com_GetPduBufferBysignalId(const Com_SignalIdType signalId,const char **PduData) 
{
	const ComSignal_type *Signal     = GET_Signal(signalId);
	const Com_Arc_IPdu_type   *Arc_IPdu       = GET_ArcIPdu(Signal->ComIPduHandleId);
	//memcpy((char*)PduData,(char*)Arc_IPdu->ComIPduDataPtr,8);
	*PduData = (char*)Arc_IPdu->ComIPduDataPtr;		
}

uint8_t Com_SendSignal(Com_SignalIdType SignalId, const void *SignalDataPtr) {
	/* @req COM334 */ /* Shall update buffer if pdu stopped, should not store trigger */
	/* !req COM055 */
	uint8_t ret = E_OK;
	boolean dataChanged = FALSE;
	const ComSignal_type * Signal;
    const ComIPdu_type *IPdu ;
    Com_Arc_IPdu_type *Arc_IPdu ;
    imask_t irq_state;
    
	if( COM_INIT != Com_GetStatus() ) {
		DET_REPORTERROR(COM_SENDSIGNAL_ID, COM_E_UNINIT);
		return COM_SERVICE_NOT_AVAILABLE;
	}

	if(SignalId >= ComConfig->ComNofSignals) {
		DET_REPORTERROR(COM_SENDSIGNAL_ID, COM_E_PARAM);
		return COM_SERVICE_NOT_AVAILABLE;
	}

	// Store pointer to signal for easier coding.
	Signal = GET_Signal(SignalId);

    if (Signal->ComIPduHandleId == NO_PDU_REFERENCE) {
        /* Return error if signal is not connected to an IPdu*/
        return COM_SERVICE_NOT_AVAILABLE;
    }

    IPdu = GET_IPdu(Signal->ComIPduHandleId);
    Arc_IPdu = GET_ArcIPdu(Signal->ComIPduHandleId);

    if (isPduBufferLocked(getPduId(IPdu))) {
        return COM_BUSY;
    }
	//DEBUG(DEBUG_LOW, "Com_SendSignal: id %d, nBytes %d, BitPosition %d, intVal %d\n", SignalId, nBytes, signal->ComBitPosition, (uint32)*(uint8 *)SignalDataPtr);

    

    Irq_Save(irq_state);
    /* @req COM624 */
    Com_WriteSignalDataToPdu(Signal->ComHandleId, SignalDataPtr, &dataChanged);

    // If the signal has an update bit. Set it!
    /* @req COM061 */
    if (Signal->ComSignalArcUseUpdateBit) {
        SETBIT(Arc_IPdu->ComIPduDataPtr, Signal->ComUpdateBitPosition);
    }

//    if( Arc_IPdu->Com_Arc_IpduStarted ) {
    if( 1 ) {//Just for test
        /*
         * If signal has triggered transmit property, trigger a transmission!
         */
        /* @req COM767 */
        /* @req COM734 */
        /* @req COM768 */
        /* @req COM762 *//* Signal with ComBitSize 0 should never be detected as changed */
        if ( (TRIGGERED == Signal->ComTransferProperty) || ( TRIGGERED_WITHOUT_REPETITION == Signal->ComTransferProperty ) ||
                ( ((TRIGGERED_ON_CHANGE == Signal->ComTransferProperty) || ( TRIGGERED_ON_CHANGE_WITHOUT_REPETITION == Signal->ComTransferProperty )) && dataChanged)) {
            /* !req COM625 */
            /* @req COM279 */
            /* @req COM330 */
            /* @req COM467 */ /* Though RetryFailedTransmitRequests not supported. */
            /* @req COM305.1 */

            uint8_t nofReps = 0;
            switch(Signal->ComTransferProperty) {
                case TRIGGERED:
                case TRIGGERED_ON_CHANGE:
                    if( 0 == IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeNumberOfRepetitions ) {
                        nofReps = 1;
                    } else {
                        nofReps = IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeNumberOfRepetitions;
                    }
                    break;
                case TRIGGERED_WITHOUT_REPETITION:
                case TRIGGERED_ON_CHANGE_WITHOUT_REPETITION:
                    nofReps = 1;
                    break;
                default:
                    break;
            }
            /* Do not cancel outstanding repetitions triggered by other signals  */
            if( Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduNumberOfRepetitionsLeft < nofReps ) {
                Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduNumberOfRepetitionsLeft = nofReps;
            }
        }
    } else {
        ret = COM_SERVICE_NOT_AVAILABLE;
    }
    Irq_Restore(irq_state);

    return ret;
}

uint8_t Com_ReceiveSignal(Com_SignalIdType SignalId,Com_SignalGroupIdType GroupSignalId,const boolean isGroupSignal, void* SignalDataPtr) {
	const ComSignal_type * Signal;
	uint8_t                size;
    const ComIPdu_type    *IPdu ;
    Com_Arc_IPdu_type     *Arc_IPdu ;

    uint8_t                 ret = E_OK;
    const void*           pduDataPtr = 0;
	
	if( COM_INIT != Com_GetStatus() ) {
		DET_REPORTERROR(COM_RECEIVESIGNAL_ID, COM_E_UNINIT);
		return COM_SERVICE_NOT_AVAILABLE;
	}
	if(SignalId >= ComConfig->ComNofSignals) {
		DET_REPORTERROR(COM_RECEIVESIGNAL_ID, COM_E_PARAM);
		return COM_SERVICE_NOT_AVAILABLE;
	}
	DEBUG(DEBUG_LOW, "Com_ReceiveSignal: SignalId %d\n", SignalId);
	Signal = GET_Signal(SignalId);

    if (Signal->ComIPduHandleId == NO_PDU_REFERENCE) {
        /* Return error init value signal if signal is not connected to an IPdu*/
    	size = SignalTypeToSize(Signal->ComSignalType, Signal->ComBitSize/8);
        memcpy(SignalDataPtr, Signal->ComSignalInitValue, size );
        return E_OK;
    }

    IPdu     = GET_IPdu(Signal->ComIPduHandleId);
    Arc_IPdu = GET_ArcIPdu(Signal->ComIPduHandleId);


    if (IPdu->ComIPduSignalProcessing == DEFERRED && IPdu->ComIPduDirection == RECEIVE) {
        pduDataPtr = Arc_IPdu->ComIPduDeferredDataPtr;
    } else {
        if (isPduBufferLocked(getPduId(IPdu))) {
            ret = COM_BUSY;
        }
        pduDataPtr = Arc_IPdu->ComIPduDataPtr;
    }
    /* @req COM631 */
    Com_ReadSignalDataFromPduBuffer(
            SignalId,
            GroupSignalId,
            isGroupSignal,
            SignalDataPtr,
            pduDataPtr);
    if( !GET_ArcIPdu(Signal->ComIPduHandleId)->Com_Arc_IpduStarted && (E_OK == ret) ) {
        ret = COM_SERVICE_NOT_AVAILABLE;
    }
    return ret;
}

uint8_t Com_ReceiveDynSignal(Com_SignalIdType SignalId, void* SignalDataPtr, uint16_t* Length) {
    /* IMPROVEMENT: Validate signal id?*/
    const ComSignal_type * Signal = GET_Signal(SignalId);
    Com_Arc_IPdu_type    *Arc_IPdu   = GET_ArcIPdu(Signal->ComIPduHandleId);
    const ComIPdu_type   *IPdu       = GET_IPdu(Signal->ComIPduHandleId);
    imask_t state;
    uint8_t ret = E_OK;

    Com_SignalType signalType = Signal->ComSignalType;
    if( COM_INIT != Com_GetStatus() ) {
        DET_REPORTERROR(COM_RECEIVEDYNSIGNAL_ID, COM_E_UNINIT);
        return COM_SERVICE_NOT_AVAILABLE;
    }

    /* @req COM753 */
    if (signalType != SIGNAL_UINT8_DYN) {
        return COM_SERVICE_NOT_AVAILABLE;
    }

    Irq_Save(state);
    /* @req COM712 */
    if( *Length >= Arc_IPdu->Com_Arc_DynSignalLength ) {
    	uint8_t startFromPduByte = (Signal->ComBitPosition) / 8;
    	const void* pduDataPtr = 0;
        if (*Length > Arc_IPdu->Com_Arc_DynSignalLength) {
            *Length = Arc_IPdu->Com_Arc_DynSignalLength;
        }
        
        if (IPdu->ComIPduSignalProcessing == DEFERRED && IPdu->ComIPduDirection == RECEIVE) {
            pduDataPtr = Arc_IPdu->ComIPduDeferredDataPtr;
        } else {
            if (isPduBufferLocked(getPduId(IPdu))) {
                ret = COM_BUSY;
            }
            pduDataPtr = Arc_IPdu->ComIPduDataPtr;
        }
        /* @req COM711 */
        memcpy(SignalDataPtr, (uint8_t *)pduDataPtr + startFromPduByte, *Length);

        Irq_Restore(state);
    } else {
        /* @req COM724 */
        *Length = Arc_IPdu->Com_Arc_DynSignalLength;
        ret = E_NOT_OK;
    }
    if( !Arc_IPdu->Com_Arc_IpduStarted && (E_OK == ret) ) {
        ret = COM_SERVICE_NOT_AVAILABLE;
    }
    return ret;
}

uint8_t Com_SendDynSignal(Com_SignalIdType SignalId, const void* SignalDataPtr, uint16_t Length) {
    /* IMPROVEMENT: validate SignalId */
    /* !req COM629 */
    /* @req COM630 */
    const ComSignal_type * Signal = GET_Signal(SignalId);
    Com_Arc_IPdu_type    *Arc_IPdu   = GET_ArcIPdu(Signal->ComIPduHandleId);
    const ComIPdu_type   *IPdu       = GET_IPdu(Signal->ComIPduHandleId);
    imask_t state;
    uint8_t ret = E_OK;
    Com_SignalType signalType = Signal->ComSignalType;
    boolean dataChanged = FALSE;
    uint8_t startFromPduByte;
    uint8_t signalLength = Signal->ComBitSize / 8;
    Com_BitPositionType bitPosition = Signal->ComBitPosition;
    
    if( COM_INIT != Com_GetStatus() ) {
        DET_REPORTERROR(COM_SENDDYNSIGNAL_ID, COM_E_UNINIT);
        return COM_SERVICE_NOT_AVAILABLE;
    }


    /* @req COM753 */
    if (signalType != SIGNAL_UINT8_DYN) {
        return COM_SERVICE_NOT_AVAILABLE;
    }
    if (isPduBufferLocked(getPduId(IPdu))) {
        return COM_BUSY;
    }

    if (signalLength < Length) {
        return E_NOT_OK;
    }
    startFromPduByte = bitPosition / 8;

    Irq_Save(state);
    if( (Arc_IPdu->Com_Arc_DynSignalLength != Length) ||
            (0 != memcmp((void *)((uint8_t *)Arc_IPdu->ComIPduDataPtr + startFromPduByte), SignalDataPtr, Length)) ) {
        dataChanged = TRUE;
    }
    /* @req COM628 */
    memcpy((void *)((uint8_t *)Arc_IPdu->ComIPduDataPtr + startFromPduByte), SignalDataPtr, Length);
    /* !req COM757 */ //Length of I-PDU?
    Arc_IPdu->Com_Arc_DynSignalLength = Length;
    // If the signal has an update bit. Set it!
    if (Signal->ComSignalArcUseUpdateBit) {
        SETBIT(Arc_IPdu->ComIPduDataPtr, Signal->ComUpdateBitPosition);
    }
    if( Arc_IPdu->Com_Arc_IpduStarted ) {
         // If signal has triggered transmit property, trigger a transmission!
        /* @req COM767 */
        /* @req COM734 */ /* NOTE: The actual sending is done in the main function */
        /* @req COM768 */
        /* @req COM762 *//* Signal with ComBitSize 0 should never be detected as changed */
        if ( (TRIGGERED == Signal->ComTransferProperty) || ( TRIGGERED_WITHOUT_REPETITION == Signal->ComTransferProperty ) ||
                ( ((TRIGGERED_ON_CHANGE == Signal->ComTransferProperty) || ( TRIGGERED_ON_CHANGE_WITHOUT_REPETITION == Signal->ComTransferProperty )) && dataChanged)) {
            /* !req COM625 */
            /* @req COM279 */
            /* @req COM330 */
            /* @req COM467 */ /* Though RetryFailedTransmitRequests not supported. */
            /* @req COM305.1 */
            uint8_t nofReps = 0;
            switch(Signal->ComTransferProperty) {
                case TRIGGERED:
                case TRIGGERED_ON_CHANGE:
                    if( 0 == IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeNumberOfRepetitions ) {
                        nofReps = 1;
                    } else {
                        nofReps = IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeNumberOfRepetitions;
                    }
                    break;
                case TRIGGERED_WITHOUT_REPETITION:
                case TRIGGERED_ON_CHANGE_WITHOUT_REPETITION:
                    nofReps = 1;
                    break;
                default:
                    break;
            }
            /* Do not cancel outstanding repetitions triggered by other signals  */
            if( Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduNumberOfRepetitionsLeft < nofReps ) {
                Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduNumberOfRepetitionsLeft = nofReps;
            }
        }
    } else {
        ret = COM_SERVICE_NOT_AVAILABLE;
    }
    Irq_Restore(state);

    return ret;
}

Std_ReturnType Com_TriggerTransmit(PduIdType TxPduId, PduInfoType *PduInfoPtr) {
	/* @req COM475 */
	/* !req COM578 */
	/* !req COM766 */
	/* !req COM395 */
	const ComIPdu_type *IPdu = GET_IPdu(TxPduId);
	Com_Arc_IPdu_type    *Arc_IPdu   = GET_ArcIPdu(TxPduId);
    imask_t state;
	
	if( COM_INIT != Com_GetStatus() ) {
		DET_REPORTERROR(COM_TRIGGERTRANSMIT_ID, COM_E_UNINIT);
		return E_NOT_OK;
	}
	if( TxPduId >= ComConfig->ComNofIPdus ) {
		DET_REPORTERROR(COM_TRIGGERTRANSMIT_ID, COM_E_PARAM);
		return E_NOT_OK;
	}
	/*
	 * !req COM260: This function must not check the transmission mode of the I-PDU
	 * since it should be possible to use it regardless of the transmission mode.
	 * Only for ComIPduType = NORMAL.
	 */

	/*
	 * !req COM395: This function must override the IPdu callouts used in Com_TriggerIPduTransmit();
	 */

    Irq_Save(state);
    /* @req COM647 */
    /* @req COM648 */ /* Interrups disabled */
    memcpy(PduInfoPtr->SduDataPtr, Arc_IPdu->ComIPduDataPtr, IPdu->ComIPduSize);

    Irq_Restore(state);

	PduInfoPtr->SduLength = IPdu->ComIPduSize;
	if( !Arc_IPdu->Com_Arc_IpduStarted ) {
		return E_NOT_OK;
	} else {
		return E_OK;
	}
}


void Com_TriggerIPDUSend(PduIdType PduId) {
	/* !req	COM789 */
	/* !req	COM662 */ /* May be supported, but when is buffer locked?*/
	const ComIPdu_type *IPdu = GET_IPdu(PduId);
	Com_Arc_IPdu_type *Arc_IPdu = GET_ArcIPdu(PduId);
	imask_t state;
	PduInfoType PduInfoPackage;

	if( COM_INIT != Com_GetStatus() ) {
		DET_REPORTERROR(COM_TRIGGERIPDUSEND_ID, COM_E_UNINIT);
		return;
	}
	if( PduId >= ComConfig->ComNofIPdus ) {
		DET_REPORTERROR(COM_TRIGGERIPDUSEND_ID, COM_E_PARAM);
		return;
	}


    Irq_Save(state);

	// Is the IPdu ready for transmission?
    /* @req COM388 */
	if (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduMinimumDelayTimer == 0) {
//    if(1){//Just for test, 2017-9-8 19:43:00

		// Check callout status
		/* @req COM492 */
		/* @req COM346 */
		/* !req COM381 */
		/* IMPROVEMENT: No other COM API than Com_TriggerIPDUSend, Com_SendSignal or Com_SendSignalGroup
		 * can be called from an an I-PDU callout.*/
		/* !req COM780 */
		/* !req COM781 */
		/* @req COM719 */
		if ((IPdu->ComTxIPduCallout != COM_NO_FUNCTION_CALLOUT) && (ComTxIPduCallouts[IPdu->ComTxIPduCallout] != NULL) ) {
			if (!ComTxIPduCallouts[IPdu->ComTxIPduCallout](PduId, Arc_IPdu->ComIPduDataPtr)) {
				// IMPROVEMENT: Report error to DET.
				// Det_ReportError();
			    Irq_Restore(state);
				return;
			}
		}
		
		PduInfoPackage.SduDataPtr = (uint8_t *)Arc_IPdu->ComIPduDataPtr;
		if (IPdu->ComIPduDynSignalRef != 0) {
			/* !req COM757 */ //Length of I-PDU?
			uint16_t sizeWithoutDynSignal = IPdu->ComIPduSize - (IPdu->ComIPduDynSignalRef->ComBitSize/8);
			PduInfoPackage.SduLength = sizeWithoutDynSignal + Arc_IPdu->Com_Arc_DynSignalLength;
		} else {
			PduInfoPackage.SduLength = IPdu->ComIPduSize;
		}
		// Send IPdu!
		/* @req COM138 */
		//if (PduR_ComTransmit(IPdu->ArcIPduOutgoingId, &PduInfoPackage) == E_OK) {
		if (CanIf_Transmit(IPdu->ArcIPduOutgoingId+COM_PDUID_CANIF_TX_START, &PduInfoPackage) == E_OK) {
			uint8_t i;
			// Clear all update bits for the contained signals
			/* @req COM062 */
			/* !req COM577 */
			for (i = 0; (IPdu->ComIPduSignalRef != NULL) && (IPdu->ComIPduSignalRef[i] != NULL); i++) {
				if (IPdu->ComIPduSignalRef[i]->ComSignalArcUseUpdateBit) {
					CLEARBIT(Arc_IPdu->ComIPduDataPtr, IPdu->ComIPduSignalRef[i]->ComUpdateBitPosition);
				}
			}
		} else {
			UnlockTpBuffer(getPduId(IPdu));
		}

		// Reset miminum delay timer.
		/* @req	COM471 */
		/* @req	COM698 */
		Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduMinimumDelayTimer = IPdu->ComTxIPdu.ComTxIPduMinimumDelayFactor;
	} else {
		//DEBUG(DEBUG_MEDIUM, "failed (MDT)!\n", ComTxPduId);
	}
    Irq_Restore(state);
}

void Com_RxIndication(PduIdType RxPduId, PduInfoType* PduInfoPtr) {
    PduIdType ComRxPduId = RxPduId - COM_PDUID_CANIF_RX_START + COM_PDUID_COM_RX_START;
	const ComIPdu_type *IPdu = GET_IPdu(ComRxPduId);
	Com_Arc_IPdu_type *Arc_IPdu = GET_ArcIPdu(ComRxPduId);
	//imask_t state;
	const ComSignal_type *signal;
	Com_Arc_Signal_type *Arc_Signal;
	
	if( COM_INIT != Com_GetStatus() ) {
		DET_REPORTERROR(COM_RXINDICATION_ID, COM_E_UNINIT);
		return;
	}
	if( ComRxPduId >= ComConfig->ComNofIPdus ) {
		DET_REPORTERROR(COM_RXINDICATION_ID, COM_E_PARAM);
		return;
	}

   
	//Irq_Save(state);
	signal 		= IPdu->ComIPduSignalRef[0];

	Arc_Signal 	= GET_ArcSignal(signal->ComHandleId);

	Arc_Signal->received = true;
#if 0	
	if(ComRxPduId == SIGNAL_RX_FACTORY_0x77A_HANDLE)// acc off    factory mode 0x77B
	{

		if(CanIdDataRecv[RxPduId].ComIPduDataPtr != NULL)
		{
			memcpy(CanIdDataRecv[RxPduId].ComIPduDataPtr, PduInfoPtr->SduDataPtr, IPdu->ComIPduSize);
			CanDataIsNeedUpdate[RxPduId]=true;
		}

		return;
	}
#endif
	
#if 0
	/* @req COM649 */ /* Interrups disabled */
	// If Ipdu is stopped
	/* @req COM684 */
	if (!Arc_IPdu->Com_Arc_IpduStarted) {
		//Irq_Restore(state);
		return;
	}
#endif

#if 0
	if(DemEnableConditions[CONDITION_T_IGN_ON])
	{
	    if (Arc_Signal->timeout_cnt < COM_RX_TIMEOUT_CNT) {
			Arc_Signal->timeout_cnt ++;
	    }
	}
#endif
    
	// Check callout status
	/* @req COM555 */
	/* @req COM700 */
	/* @req COM381 */
	/* @req COM780 */
	/* @req COM781 */

	/* !req COM574 */
	/* !req COM575 */
	
if( (memcmp(Arc_IPdu->ComIPduDataPtr,PduInfoPtr->SduDataPtr,IPdu->ComIPduSize))||
	(ComRxPduId == SIGNAL_RX_MMI_LIGHT_0x2A2_HANDLE)||
	(ComRxPduId == SIGNAL_RX_GW_IPK_0x3F1_HANDLE)||
	(ComRxPduId == SIGNAL_RX_GW_ESC_0x125_HANDLE)||
	(ComRxPduId == SIGNAL_RX_GW_BCM_0x287_HANDLE)
	 )
{
	memcpy(Arc_IPdu->ComIPduDataPtr, PduInfoPtr->SduDataPtr, IPdu->ComIPduSize);

	if(CanIdDataRecv[RxPduId].ComIPduDataPtr != NULL){
	 	memcpy(CanIdDataRecv[RxPduId].ComIPduDataPtr, PduInfoPtr->SduDataPtr, IPdu->ComIPduSize);
		CanDataIsNeedUpdate[RxPduId]=true;
      }
	if(CanIdDataRecv[RxPduId].IsNeedParse== true){
	   CanDataParse[RxPduId]=Arc_IPdu->ComIPduDataPtr;
	   CanDataIsNeedUpdate[RxPduId]=true;
	}

	
}
	Com_RxProcessSignals(IPdu,Arc_IPdu);

	//Irq_Restore(state);

	return;
}

void Com_TpRxIndication(PduIdType PduId, NotifResultType Result) {
	/* @req COM720 */
	const ComIPdu_type *IPdu = GET_IPdu(PduId);
	Com_Arc_IPdu_type *Arc_IPdu = GET_ArcIPdu(PduId);
	imask_t state;
	if( COM_INIT != Com_GetStatus() ) {
		DET_REPORTERROR(COM_TPRXINDICATION_ID, COM_E_UNINIT);
		return;
	}
	if( PduId >= ComConfig->ComNofIPdus ) {
		DET_REPORTERROR(COM_RXINDICATION_ID, COM_E_PARAM);
		return;
	}


	/* @req COM651 */ /* Interrups disabled */
	Irq_Save(state);

	// If Ipdu is stopped
	/* @req COM684 */
	if (!Arc_IPdu->Com_Arc_IpduStarted) {
		UnlockTpBuffer(getPduId(IPdu));
		Irq_Restore(state);
		return;
	}
	if (Result == NTFRSLT_OK) {
		if (IPdu->ComIPduSignalProcessing == IMMEDIATE) {
			// irqs needs to be disabled until signal notifications have been called
			// Otherwise a new Tp session can start and fill up pdus
			UnlockTpBuffer(getPduId(IPdu));
		}
		// In deferred mode, buffers are unlocked in mainfunction
		Com_RxProcessSignals(IPdu,Arc_IPdu);
	} else {
		UnlockTpBuffer(getPduId(IPdu));
	}
	Irq_Restore(state);

}



void Com_TpTxConfirmation(PduIdType PduId, NotifResultType Result) {
	/* !req COM713 */
	/* @req COM662 */ /* Tp buffer unlocked */
	imask_t state;
	
	if( COM_INIT != Com_GetStatus() ) {
		DET_REPORTERROR(COM_TPTXCONFIRMATION_ID, COM_E_UNINIT);
		return;
	}
	if( PduId >= ComConfig->ComNofIPdus ) {
		DET_REPORTERROR(COM_RXINDICATION_ID, COM_E_PARAM);
		return;
	}
	(void)Result; // touch

	
	Irq_Save(state);
	UnlockTpBuffer(PduId);
	Irq_Restore(state);
}

void Com_TxConfirmation(PduIdType TxPduId) {
	/* !req COM469 */
	/* !req COM053 */
	/* !req COM577 */
	/* !req COM305 */
	/* @req COM652 */ /* Function does nothing.. */ 
	uint8_t i;
	PduIdType  ComTxPduId=TxPduId-COM_PDUID_CANIF_TX_START;
	const ComIPdu_type *IPdu = GET_IPdu(ComTxPduId);
	if( COM_INIT != Com_GetStatus() ) {
		DET_REPORTERROR(COM_TXCONFIRMATION_ID, COM_E_UNINIT);
		return;
	}
	//if( TxPduId >= ComConfig->ComNofIPdus ) {
		//DET_REPORTERROR(COM_RXINDICATION_ID, COM_E_PARAM);
		//return;
	//}

    /* @req COM468 */
    /* Call all notifications for the PDU */


    if (IPdu->ComIPduDirection == RECEIVE) {
        DET_REPORTERROR(COM_TXCONFIRMATION_ID, COM_INVALID_PDU_ID);
    }
    else if (IPdu->ComIPduSignalProcessing == IMMEDIATE) {
        /* If immediate, call the notification functions  */
        for (i = 0; IPdu->ComIPduSignalRef[i] != NULL; i++) {
            const ComSignal_type *signal = IPdu->ComIPduSignalRef[i];
            if ((signal->ComNotification != COM_NO_FUNCTION_CALLOUT) &&
                (ComNotificationCallouts[signal->ComNotification] != NULL) ) {
                //ComNotificationCallouts[signal->ComNotification](signal->ComHandleId,0,FALSE);
            }
        }
    }
    else {
        /* If deferred, set status and let the main function call the notification function */
        SetTxConfirmationStatus(IPdu, TRUE);
    }
}


uint8_t Com_SendSignalGroup(Com_SignalGroupIdType SignalGroupId) {
	/* Validate signalgroupid?*/
	/* @req COM334 */
	/* !req COM055 */
//#warning Com_SendSignalGroup should be performed atomically. Should we disable interrupts here?
	/* @req COM050 */
	uint8_t ret = E_OK;
	boolean dataChanged = FALSE;
	const ComSignal_type * Signal = GET_Signal(SignalGroupId);
	Com_Arc_IPdu_type *Arc_IPdu = GET_ArcIPdu(Signal->ComIPduHandleId);
	const ComIPdu_type *IPdu = GET_IPdu(Signal->ComIPduHandleId);
	imask_t irq_state;
	
	if( COM_INIT != Com_GetStatus() ) {
		DET_REPORTERROR(COM_SENDSIGNALGROUP_ID, COM_E_UNINIT);
		return COM_SERVICE_NOT_AVAILABLE;
	}
	

    if (Signal->ComIPduHandleId == NO_PDU_REFERENCE) {
        return COM_SERVICE_NOT_AVAILABLE;
    }

    

    if (isPduBufferLocked(getPduId(IPdu))) {
        return COM_BUSY;
    }

    // Copy shadow buffer to Ipdu data space
    

    Irq_Save(irq_state);
    /* @req COM635 */

    Com_CopySignalGroupDataFromShadowBufferToPdu(SignalGroupId,
                                                 (IPdu->ComIPduSignalProcessing == DEFERRED) &&
                                                 (IPdu->ComIPduDirection == RECEIVE),
                                                 &dataChanged);

    // If the signal has an update bit. Set it!
    /* @req COM061 */
    if (Signal->ComSignalArcUseUpdateBit) {
        SETBIT(Arc_IPdu->ComIPduDataPtr, Signal->ComUpdateBitPosition);
    }

    if( Arc_IPdu->Com_Arc_IpduStarted ) {
        // If signal has triggered transmit property, trigger a transmission!
        /* @req COM769 */
        /* @req COM742 */ /* NOTE: Check this */
        /* !req COM743 */
        /* @req COM770 */
        if ( (TRIGGERED == Signal->ComTransferProperty) || ( TRIGGERED_WITHOUT_REPETITION == Signal->ComTransferProperty ) ||
                ( ((TRIGGERED_ON_CHANGE == Signal->ComTransferProperty) || ( TRIGGERED_ON_CHANGE_WITHOUT_REPETITION == Signal->ComTransferProperty )) && dataChanged)) {
            /* @req COM279 */
            /* @req COM741 */

            uint8_t nofReps = 0;
            switch(Signal->ComTransferProperty) {
                case TRIGGERED:
                case TRIGGERED_ON_CHANGE:
                    if( 0 == IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeNumberOfRepetitions ) {
                        nofReps = 1;
                    } else {
                        nofReps = IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeNumberOfRepetitions;
                    }
                    break;
                case TRIGGERED_WITHOUT_REPETITION:
                case TRIGGERED_ON_CHANGE_WITHOUT_REPETITION:
                    nofReps = 1;
                    break;
                default:
                    break;
            }
            /* Do not cancel outstanding repetitions triggered by other signalss */
            if( Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduNumberOfRepetitionsLeft < nofReps ) {
                Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduNumberOfRepetitionsLeft = nofReps;
            }
        }
    } else {
        ret = COM_SERVICE_NOT_AVAILABLE;
    }
    Irq_Restore(irq_state);

    return ret;
}


uint8_t Com_ReceiveSignalGroup(Com_SignalGroupIdType SignalGroupId) {
	const ComSignal_type * Signal = GET_Signal(SignalGroupId);
	const ComIPdu_type *IPdu = GET_IPdu(Signal->ComIPduHandleId);
	
	if( COM_INIT != Com_GetStatus() ) {
		DET_REPORTERROR(COM_RECEIVESIGNALGROUP_ID, COM_E_UNINIT);
		return COM_SERVICE_NOT_AVAILABLE;
	}

	

    if (Signal->ComIPduHandleId == NO_PDU_REFERENCE) {
        return COM_SERVICE_NOT_AVAILABLE;
    }

    

    if (isPduBufferLocked(getPduId(IPdu))) {
        return COM_BUSY;
    }
    // Copy Ipdu data buffer to shadow buffer.
    /* @req COM638 */
    /* @req COM461 */
    Com_CopySignalGroupDataFromPduToShadowBuffer(SignalGroupId);

    if( !GET_ArcIPdu(Signal->ComIPduHandleId)->Com_Arc_IpduStarted ) {
        return COM_SERVICE_NOT_AVAILABLE;
    } else {
        return E_OK;
    }
}

void Com_UpdateShadowSignal(Com_SignalIdType SignalId, const void *SignalDataPtr) {
	Com_Arc_GroupSignal_type *Arc_GroupSignal = GET_ArcGroupSignal(SignalId);
	
	if( COM_INIT != Com_GetStatus() ) {
		DET_REPORTERROR(COM_UPDATESHADOWSIGNAL_ID, COM_E_UNINIT);
		return;
	}

    if( SignalId >= ComConfig->ComNofGroupSignals ) {
        DET_REPORTERROR(COM_UPDATESHADOWSIGNAL_ID, COM_E_PARAM);
        return;
    }

    

    if (Arc_GroupSignal->Com_Arc_ShadowBuffer != NULL) {
        Com_Internal_UpdateShadowSignal(SignalId, SignalDataPtr);
    }
}

void Com_ReceiveShadowSignal(Com_SignalIdType SignalId, void *SignalDataPtr) {
	const ComGroupSignal_type *GroupSignal = GET_GroupSignal(SignalId);
	Com_Arc_GroupSignal_type *Arc_GroupSignal = GET_ArcGroupSignal(SignalId);
	
	if( COM_INIT != Com_GetStatus() ) {
		DET_REPORTERROR(COM_RECEIVESHADOWSIGNAL_ID, COM_E_UNINIT);
		return;
	}

    if( SignalId >= ComConfig->ComNofGroupSignals ) {
        DET_REPORTERROR(COM_RECEIVESHADOWSIGNAL_ID, COM_E_PARAM);
        return;
    }

    
	

    /* Get default value if unconnected */
    if (Arc_GroupSignal->Com_Arc_ShadowBuffer == NULL) {
        memcpy(SignalDataPtr, GroupSignal->ComSignalInitValue, SignalTypeToSize(GroupSignal->ComSignalType, GroupSignal->ComBitSize/8));
    }
    else {
	/* @req COM640 */
	Com_ReadSignalDataFromPduBuffer(SignalId, 0,TRUE, SignalDataPtr, (void *)Arc_GroupSignal->Com_Arc_ShadowBuffer);
    }

}

