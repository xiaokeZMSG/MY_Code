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



/* General requirements on Com module */
/* @req COM584 */
/* !req COM220 */ /* Include file structure */
/* !req COM673 */ /* Version check */
/* !req COM010 */ /* IMPROVEMENT: OSEK-COM, what is implemented? */
/* !req COM011 */ /* IMPROVEMENT: OSEK-COM, what is implemented? */
/* !req COM012 */ /* IMPROVEMENT: OSEK-COM, what is implemented? */
/* !req COM013 */ /* IMPROVEMENT: OSEK-COM, what is implemented? */
/* COM759, COM760: ComIPduType not used */
/* !req COM759 */
/* !req COM760 */
/* @req COM059 */ /* Interpretation of update-bit */
/* !req COM320 */ /* !req COM321 */ /* Reentrant/Non-reentrant functions */
#include "r_typedefs.h"
#include <assert.h>
#include <stdlib.h>

//#include <stdio.h>
#include <string.h>
#include "Com.h"
#include "Com_Arc_Types.h"
#include "Com_Internal.h"
#include "Com_misc.h"
#include "debug.h"
#include "generic\Cpu.h"
//#include "standard.h"//add

static const uint32_t endianness_test = 0xdeadbeefU;
ComSignalEndianess_type Com_SystemEndianness;

static Com_StatusType initStatus = COM_UNINIT;

const Com_ConfigType * ComConfig;

/* Data, deferred data and shadow buffer */
static uint8_t Com_Arc_Buffer[COM_MAX_BUFFER_SIZE];

static Com_Arc_IPdu_type Com_Arc_IPdu[COM_MAX_N_IPDUS];
static Com_Arc_Signal_type Com_Arc_Signal[COM_MAX_N_SIGNALS];

#if (COM_MAX_N_GROUP_SIGNALS != 0)
static Com_Arc_GroupSignal_type Com_Arc_GroupSignal[COM_MAX_N_GROUP_SIGNALS];
#endif

Com_Arc_Config_type Com_Arc_Config = {
    Com_Arc_IPdu,
    Com_Arc_Signal,
#if (COM_MAX_N_GROUP_SIGNALS != 0)
    Com_Arc_GroupSignal
#else
    NULL
#endif
};

void Com_Init(const Com_ConfigType *config ) {
	uint8_t failure = 0;
	uint32_t firstTimeout;
	boolean dataChanged = FALSE;
	const ComSignal_type *Signal;
	const ComGroupSignal_type *GroupSignal;
	uint16_t bufferIndex = 0;
	//lint --e(928)	PC-Lint exception Misra 11.4, Must be like this. /tojo
	uint8_t endiannessByte = *(const uint8_t *)&endianness_test;
	uint16_t i,j,h;
	Com_Arc_Signal_type      *Arc_Signal;
	Com_Arc_GroupSignal_type *Arc_GroupSignal;
	const ComIPdu_type *IPdu ;
    Com_Arc_IPdu_type *Arc_IPdu ;

	
	DEBUG(DEBUG_LOW, "--Initialization of COM--\n");
	/* !req COM328 */ /* Shall not enable inter-ECU communication */
	/* !req COM483 */

	/* @req COM128 */
	/* @req COM217 */
	/* @req COM444 */
	/* @req COM772 */ // If timeout set to 0


	/* @req COM433 */
	if( NULL == config ) {
		DET_REPORTERROR(COM_INIT_ID, COM_E_PARAM_POINTER);
		return;
	}
	ComConfig = config;


	if( endiannessByte == 0xef ) { 
		Com_SystemEndianness = COM_LITTLE_ENDIAN; 
	}else if ( endiannessByte == 0xde ) {
		Com_SystemEndianness = COM_BIG_ENDIAN; 
	}else {
	// No other endianness supported
	//assert(0);
	}

	// Initialize each IPdu
	//ComIPdu_type *IPdu;
	//Com_Arc_IPdu_type *Arc_IPdu;

	for (i = 0; i<COM_NOF_IPDU; i++) {
	    boolean pduHasGroupSignal = FALSE;
		IPdu = GET_IPdu(i);
		Arc_IPdu = GET_ArcIPdu(i);
		Arc_IPdu->Com_Arc_DynSignalLength = 0;

		if (i >= ComConfig->ComNofIPdus) {
			DET_REPORTERROR(COM_INIT_ID ,COM_E_TOO_MANY_IPDU);
			failure = 1;
			break;
		}
		/* Set the data ptr for this Pdu */
		Arc_IPdu->ComIPduDataPtr = (void *)&Com_Arc_Buffer[bufferIndex];
		bufferIndex += IPdu->ComIPduSize;
		// If this is a TX and cyclic IPdu, configure the first deadline.
		if ( (IPdu->ComIPduDirection == SEND) &&
				( (IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeMode == PERIODIC) || (IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeMode == MIXED) )) {
			//IPdu->Com_Arc_TxIPduTimers.ComTxModeTimePeriodTimer = IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeTimeOffsetFactor;
			Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeTimePeriodTimer = IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeTimeOffsetFactor;
		}


		// Reset firstTimeout.
		firstTimeout = 0xffffffffu;

		// Initialize the memory with the default value.
		/* @req COM015 */
		if (IPdu->ComIPduDirection == SEND) {	
			memset((void *)Arc_IPdu->ComIPduDataPtr, IPdu->ComTxIPdu.ComTxIPduUnusedAreasDefault, IPdu->ComIPduSize);
		}

		// For each signal in this PDU.
		//Arc_IPdu->NComIPduSignalRef = 0;
		for (j = 0; (IPdu->ComIPduSignalRef != NULL) && (IPdu->ComIPduSignalRef[j] != NULL) ; j++) {
			Signal = IPdu->ComIPduSignalRef[j];
			Arc_Signal = GET_ArcSignal(Signal->ComHandleId);
            Arc_Signal->received = false;
			Arc_Signal->timeout_cnt = 0;
			// Configure signal deadline monitoring if used.
			/* @req COM333 */ // If timeout set to 0
			if (Signal->ComTimeoutFactor > 0) {
				if (Signal->ComSignalArcUseUpdateBit) {
					// This signal uses an update bit, and hence has its own deadline monitoring.
					/* @req COM292 */
					Arc_Signal->Com_Arc_DeadlineCounter = Signal->ComFirstTimeoutFactor; // Configure the deadline counter
				} else {
					// This signal does not use an update bit, and should therefore use per I-PDU deadline monitoring.
					if (firstTimeout > Signal->ComFirstTimeoutFactor) {
						firstTimeout = Signal->ComFirstTimeoutFactor;
					}
				}
			}

			// Clear update bits
			/* @req COM117 */
			if (Signal->ComSignalArcUseUpdateBit) {
				CLEARBIT(Arc_IPdu->ComIPduDataPtr, Signal->ComUpdateBitPosition);
			}

			// If this signal is a signal group
			if (Signal->Com_Arc_IsSignalGroup) {
			    pduHasGroupSignal = TRUE;
			 //   Arc_Signal->Com_Arc_ShadowBuffer = (void *)&Com_Arc_Buffer[bufferIndex];
				// For each group signal of this signal group
#if 0
				for(h = 0; Signal->ComGroupSignal[h] != NULL; h++) {
					GroupSignal = Signal->ComGroupSignal[h];
					Arc_GroupSignal = GET_ArcGroupSignal(GroupSignal->ComHandleId);
					// Set pointer to shadow buffer
					Arc_GroupSignal->Com_Arc_ShadowBuffer = (void *)Arc_Signal->Com_Arc_ShadowBuffer;

					// Initialize shadowbuffer.
					/* @req COM484 */
					Com_Internal_UpdateShadowSignal(GroupSignal->ComHandleId, GroupSignal->ComSignalInitValue);
				}
				// Initialize group signal data from shadowbuffer.
				/* @req COM098 */
				Com_CopySignalGroupDataFromShadowBufferToPdu(Signal->ComHandleId, false, &dataChanged);
#endif
			} else {
				// Initialize signal data.
				/* @req COM098 */
				Com_WriteSignalDataToPdu(Signal->ComHandleId, Signal->ComSignalInitValue, &dataChanged);
			}
		}

		if (IPdu->ComIPduDirection == RECEIVE && IPdu->ComIPduSignalProcessing == DEFERRED) {
		    /* Set pointer to the deferred buffer */
		    Arc_IPdu->ComIPduDeferredDataPtr = (void *)&Com_Arc_Buffer[bufferIndex];
	        bufferIndex += IPdu->ComIPduSize;
			// Copy the initialized pdu to deferred buffer
			memcpy(Arc_IPdu->ComIPduDeferredDataPtr,Arc_IPdu->ComIPduDataPtr,IPdu->ComIPduSize);
		}
		// Configure per I-PDU based deadline monitoring.
		for (j = 0; (IPdu->ComIPduSignalRef != NULL) && (IPdu->ComIPduSignalRef[j] != NULL); j++) {
			Signal = IPdu->ComIPduSignalRef[j];
			Arc_Signal = GET_ArcSignal(Signal->ComHandleId);

			/* @req COM333 */ // If timeout set to 0
			if ( (Signal->ComTimeoutFactor > 0) && (!Signal->ComSignalArcUseUpdateBit) ) {
				/* @req COM290 */
				Arc_Signal->Com_Arc_DeadlineCounter = firstTimeout;
			}
		}
	}
	for (i = 0; i < ComConfig->ComNofIPdus; i++) {
		Com_BufferPduState[i].currentPosition = 0;
		Com_BufferPduState[i].locked = false;
	}

	// An error occurred.
	if (failure) {
		DEBUG(DEBUG_LOW, "--Initialization of COM failed--\n");
		//DET_REPORTERROR(COM_MODULE_ID, COM_INSTANCE_ID, 0x01, COM_E_INVALID_FILTER_CONFIGURATION);
	} else {
		initStatus = COM_INIT;
		DEBUG(DEBUG_LOW, "--Initialization of COM completed--\n");
	}
}


void Com_DeInit( void ) {
	uint16_t i;
	
	if(COM_INIT != initStatus) {
		DET_REPORTERROR(COM_DEINIT_ID, COM_E_UNINIT);
		return;
	}
	/* @req COM129 */
	for ( i = 0; !ComConfig->ComIPdu[i].Com_Arc_EOL; i++) {
		Com_Arc_Config.ComIPdu[i].Com_Arc_IpduStarted = 0;
	}
	initStatus = COM_UNINIT;
}

Com_StatusType Com_GetStatus( void )
{
	return initStatus;
}

void Com_IpduGroupControl(Com_IpduGroupVector ipduGroupVector, boolean Initialize)
{
	/* !req COM614 */
	/* Starting groups */
	/* @req COM114 */
	/* !req COM787 */
	/* !req COM222 */
	/* !req COM733 */
	/* !req COM740 */

	/* Stopping groups */
	/* !req COM479 */
	/* !req COM713 */
	/* !req COM714 */
	uint16_t i;
	uint32_t gri;

	(void)Initialize; // Nothing to be done. This is just to avoid Lint warning.

	if(COM_INIT != initStatus) {
		DET_REPORTERROR(COM_IPDUGROUPCONTROL_ID, COM_E_UNINIT);
		return;
	}
    //for (i = 0; !ComConfig->ComIPdu[i].Com_Arc_EOL; i++) {
    for (i = 0; i<COM_NOF_IPDU; i++) {
        const ComIPduGroup_type *const groupRefs = ComConfig->ComIPdu[i].ComIPduGroupRefs;
        uint8_t started = FALSE;
        for(gri=0; (!groupRefs[gri].Com_Arc_EOL && !started); gri++)
        {
            uint8_t byteIndex;
            uint8_t bitIndex;
            byteIndex = groupRefs[gri].ComIPduGroupHandleId / 8;
            bitIndex = groupRefs[gri].ComIPduGroupHandleId % 8;

            /* @req COM771 */
            started |= ((ipduGroupVector[byteIndex] >> bitIndex) & 1u);
        }
        /* @req COM612 */
        /* @req COM613 */
        /* @req COM615 */
        Com_Arc_Config.ComIPdu[i].Com_Arc_IpduStarted = started;
    }
}

void Com_ClearIpduGroupVector(Com_IpduGroupVector ipduGroupVector)
{
	if(COM_INIT != initStatus) {
		DET_REPORTERROR(COM_CLEARIPDUGROUPVECTOR_ID, COM_E_UNINIT);
		return;
	}
	memset(ipduGroupVector, 0, sizeof(Com_IpduGroupVector));
}

void Com_SetIpduGroup(Com_IpduGroupVector ipduGroupVector, Com_IpduGroupIdType ipduGroupId, boolean bitval)
{
	uint8_t byteIndex;
	uint8_t bitIndex;
	
	if(COM_INIT != initStatus) {
		DET_REPORTERROR(COM_SETIPDUGROUP_ID, COM_E_UNINIT);
		return;
	}

	byteIndex = ipduGroupId / 8;
	bitIndex = ipduGroupId % 8;
	/* @req COM623 */
	if( bitval ) {
		ipduGroupVector[byteIndex] |= (1u<<bitIndex);
	} else {
		ipduGroupVector[byteIndex] &= ~(1u<<bitIndex);
	}
}
/**
 *
 * @param PduId
 * @param PduInfoPtr
 * @param RetryInfoPtr not supported
 * @param TxDataCntPtr
 * @return
 */
BufReq_ReturnType Com_CopyTxData(PduIdType PduId, PduInfoType* PduInfoPtr, RetryInfoType* RetryInfoPtr, PduLengthType* TxDataCntPtr) {
	/* IMPROVEMENT: Validate PduId, etc? */
	/* !req COM663*/
	/* !req COM783*/ /* Do not copy any data and return BUFREQ_E_NOT_OK if pdu group stopped */
	imask_t state;
	BufReq_ReturnType r = BUFREQ_OK;
	const ComIPdu_type *IPdu = GET_IPdu(PduId);
	boolean dirOk = ComConfig->ComIPdu[PduId].ComIPduDirection == SEND;
	boolean sizeOk;

	if(COM_INIT != initStatus) {
		DET_REPORTERROR(COM_COPYTXDATA_ID, COM_E_UNINIT);
		return BUFREQ_NOT_OK;
	}


	//lint -estring(920,pointer)  /* cast to void */
	(void)RetryInfoPtr; // get rid of compiler warning
	//lint +estring(920,pointer)  /* cast to void */

	Irq_Save(state);
	sizeOk = IPdu->ComIPduSize >= Com_BufferPduState[PduId].currentPosition + PduInfoPtr->SduLength;
	Com_BufferPduState[PduId].locked = true;
	if (dirOk && sizeOk) {
		void* source = (void *)GET_ArcIPdu(PduId)->ComIPduDataPtr;
		memcpy(PduInfoPtr->SduDataPtr,(uint8_t *)source + Com_BufferPduState[PduId].currentPosition, PduInfoPtr->SduLength);
		Com_BufferPduState[PduId].currentPosition += PduInfoPtr->SduLength;
		*TxDataCntPtr = IPdu->ComIPduSize - Com_BufferPduState[PduId].currentPosition;
	} else {
		r = BUFREQ_NOT_OK;
	}
	Irq_Restore(state);
	return r;
}
BufReq_ReturnType Com_CopyRxData(PduIdType PduId, const PduInfoType* PduInfoPtr, PduLengthType* RxBufferSizePtr) {
	/* !req COM782 */ /* If pdu group stopped -> return BUFREQ_E_NOT_OK */
	imask_t state;
	BufReq_ReturnType r = BUFREQ_OK;
	uint8_t remainingBytes;
	boolean sizeOk;
	boolean dirOk;
	boolean lockOk;
	if(COM_INIT != initStatus) {
		DET_REPORTERROR(COM_COPYRXDATA_ID, COM_E_UNINIT);
		return BUFREQ_NOT_OK;
	}
	Irq_Save(state);
	/* @req COM658 */ /* Interrupts disabled */
	remainingBytes = GET_IPdu(PduId)->ComIPduSize - Com_BufferPduState[PduId].currentPosition;
	sizeOk = remainingBytes >= PduInfoPtr->SduLength;
    dirOk = GET_IPdu(PduId)->ComIPduDirection == RECEIVE;
	lockOk = isPduBufferLocked(PduId);
	if (dirOk && lockOk && sizeOk) {
		memcpy((void *)((uint8_t *)GET_ArcIPdu(PduId)->ComIPduDataPtr+Com_BufferPduState[PduId].currentPosition), PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);
		Com_BufferPduState[PduId].currentPosition += PduInfoPtr->SduLength;
		*RxBufferSizePtr = GET_IPdu(PduId)->ComIPduSize - Com_BufferPduState[PduId].currentPosition;
	} else {
		r = BUFREQ_NOT_OK;
	}
	Irq_Restore(state);
	return r;
}

static void Com_SetDynSignalLength(PduIdType ComRxPduId,PduLengthType TpSduLength) {
	const ComIPdu_type *IPdu = GET_IPdu(ComRxPduId);
	const ComSignal_type * const dynSignal = IPdu->ComIPduDynSignalRef;
	Com_Arc_IPdu_type *Arc_IPdu = GET_ArcIPdu(ComRxPduId);
	if (IPdu->ComIPduDynSignalRef == 0) {
		return;
	}

	/* @req COM758 */
	if( TpSduLength > (dynSignal->ComBitPosition/8) ) {
	Arc_IPdu->Com_Arc_DynSignalLength = TpSduLength - (dynSignal->ComBitPosition/8);
	} else {
		Arc_IPdu->Com_Arc_DynSignalLength = 0;
	}
	return;
}

BufReq_ReturnType Com_StartOfReception(PduIdType ComRxPduId, PduLengthType TpSduLength, PduLengthType* RxBufferSizePtr) {
	/* IMPROVEMENT: Validate ComRxPduId? */
	PduLengthType ComIPduSize;
	imask_t state;
	BufReq_ReturnType r = BUFREQ_OK;
	Com_Arc_IPdu_type *Arc_IPdu = GET_ArcIPdu(ComRxPduId);
	
	if(COM_INIT != initStatus) {
		DET_REPORTERROR(COM_STARTOFRECEPTION_ID, COM_E_UNINIT);
		return BUFREQ_NOT_OK;
	}



	Irq_Save(state);
	if (Arc_IPdu->Com_Arc_IpduStarted) {
		if (GET_IPdu(ComRxPduId)->ComIPduDirection == RECEIVE) {
			/* !req COM657 */
			if (!Com_BufferPduState[ComRxPduId].locked) {
				ComIPduSize = GET_IPdu(ComRxPduId)->ComIPduSize;
				if (ComIPduSize >= TpSduLength) {
					Com_BufferPduState[ComRxPduId].locked = true;
					*RxBufferSizePtr = ComIPduSize;
					/* @req COM656 */
					Com_SetDynSignalLength(ComRxPduId,TpSduLength);
				} else {
					/* @req COM654 */
					/* @req COM655 */
					r = BUFREQ_OVFL;
				}
			} else {
				r = BUFREQ_BUSY;
			}
		}
	} else {
		/* @req COM721 */
		r = BUFREQ_NOT_OK;
	}
	Irq_Restore(state);
	return r;
}
