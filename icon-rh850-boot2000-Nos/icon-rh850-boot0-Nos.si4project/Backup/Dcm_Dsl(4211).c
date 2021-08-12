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

/*
 *  General requirements
 */
/** @req DCM030 */


#include <string.h>
#include "osal.h"
#include "Dcm.h"
#include "Dcm_Internal.h"
#include "Dem.h"
//#include "MemMap.h"
#if defined(USE_COMM) || (DCM_UNIT_TEST == STD_ON)
#include "ComM_Dcm.h"
#endif
#include "PduR_Dcm.h"
#include "PduR_Types.h" // OBD: for preemption cancel PDUR tx
#include "CanTp.h"       // OBD: for cancel
#include "ComStack_Types.h"
#include "Cpu.h"
//#define USE_DEBUG_PRINTF
#include "debug.h"

//#include "standard.h"

#define DECREMENT(timer) { if (timer > 0){timer--;} }
#define DCM_CONVERT_MS_TO_MAIN_CYCLES(x)  ((x)/DCM_MAIN_FUNCTION_PERIOD_TIME_MS)
#define TO_INTERNAL_PERIODIC_PDU(_x) ((_x) - DCM_FIRST_PERIODIC_TX_PDU)


#if (DCM_PAGEDBUFFER_ENABLED)
#error "DCM_PAGEDBUFFER_ENABLED is set to STD_ON, this is not supported by the code."
#endif

#define DCM_TYPE2_TX_ROUTED_TO_IF
#if DCM_NOF_PERIODIC_TX_PDU > 0
#define DCM_USE_TYPE2_PERIODIC_TRANSMISSION
#endif
/*
 * Type definitions.
 */
// #define MAX_PARALLEL_PROTOCOLS_ALLOWED		1

typedef struct {
	boolean initRun;
	//boolean diagnosticRequestPending; // This is a "semaphore" because DSD and DCM can handle multiple/parallel request at the moment.
	const Dcm_DslProtocolRowType *activeProtocol; // Points to the currently active protocol.
	const Dcm_DslProtocolRowType *preemptedProtocol; // Points to the currently active protocol - reserved for future use
//	Dcm_DslRunTimeProtocolParametersType protocolList[MAX_PARALLEL_PROTOCOLS_ALLOWED];	// Reserved for future use
} DcmDsl_RunTimeDataType;

static DcmDsl_RunTimeDataType DcmDslRunTimeData = {
		/*.initRun =*/      FALSE,
		/*.activeProtocol =*/NULL,//&DslProtocolRowTypeList,
//		.preemptedProtocol = NULL,
//		.protocolList = {}
};

#ifdef DCM_USE_TYPE2_PERIODIC_TRANSMISSION
typedef struct {
    PduIdType diagReqRxPduId;
    boolean pduInUse;
}PeriodicPduStatusType;
static PeriodicPduStatusType PeriodicPduStatus[DCM_NOF_PERIODIC_TX_PDU];
#endif


static void DslReleaseType2TxPdu(PduIdType txPduId);
static void DslReleaseAllType2TxPdus(void);
// ################# HELPER FUNCTIONS START #################

//
// This function reset/stars the session (S3) timer. See requirement
// DCM141 when that action should be taken.
//
static inline void startS3SessionTimer(Dcm_DslRunTimeProtocolParametersType *runtime, const Dcm_DslProtocolRowType *protocolRow) {
	const Dcm_DslProtocolTimingRowType *timeParams;
	timeParams = protocolRow->DslProtocolTimeLimit;
	runtime->S3ServerTimeoutCount = DCM_CONVERT_MS_TO_MAIN_CYCLES(timeParams->TimStrS3Server);
	runtime->S3ServerStarted = TRUE;
}

// - - - - - - - - - - -

//
// This function reset/stars the session (S3) timer. See requirement
// DCM141 when that action should be taken.
//
static inline void stopS3SessionTimer(Dcm_DslRunTimeProtocolParametersType *runtime) {
	runtime->S3ServerStarted = FALSE;
}

#if defined(USE_COMM) || (DCM_UNIT_TEST == STD_ON)
static boolean findProtocolRx(PduIdType dcmRxPduId, const Dcm_DslProtocolRxType **protocolRx)
{
    boolean ret = FALSE;
    if (dcmRxPduId < DCM_DSL_RX_PDU_ID_LIST_LENGTH) {
        *protocolRx = &Dcm_ConfigPtr->Dsl->DslProtocol->DslProtocolRxGlobalList[dcmRxPduId];
        ret = TRUE;
    }
    return ret;
}
#endif
// - - - - - - - - - - -
//
//	This function implements the requirement DCM139 when
// 	transition from one session to another.
//
static void changeDiagnosticSession(Dcm_DslRunTimeProtocolParametersType *runtime, Dcm_SesCtrlType newSession) {

    /** @req DCM139 */
#if defined(USE_COMM) || (DCM_UNIT_TEST == STD_ON)
    const Dcm_DslProtocolRxType *protocolRx = NULL;
#endif

    switch (runtime->sessionControl) {
    case DCM_DEFAULT_SESSION: // "default".
        /* to set the dsp buffer to default*/
        DspInit(FALSE);
        break;

    case DCM_PROGRAMMING_SESSION:
    case DCM_EXTENDED_DIAGNOSTIC_SESSION:
    case DCM_SAFTEY_SYSTEM_DIAGNOSTIC_SESSION:
    case DCM_ALL_SESSION_LEVEL:
        runtime->securityLevel = DCM_SEC_LEV_LOCKED; // "0x00".
        break;

    default:
        DCM_DET_REPORTERROR(DCM_CHANGE_DIAGNOSTIC_SESSION_ID, DCM_E_PARAM);
        break;
    }

    switch (newSession) {
    case DCM_DEFAULT_SESSION: // "default".
#if defined(USE_COMM) || (DCM_UNIT_TEST == STD_ON)
        if( (DCM_DEFAULT_SESSION != runtime->sessionControl) && findProtocolRx(runtime->diagReqestRxPduId, &protocolRx) ) {
            /* Changing from non-default session to default session */
            if( runtime->diagnosticActiveComM ) {
                ComM_DCM_InactiveDiagnostic(protocolRx->DcmDslProtocolRxComMChannel); /** @req DCM168 */
                runtime->diagnosticActiveComM = FALSE;
            }
        }
#endif
		Communication_Control_Disabled=0;//added 20160617,enable communication when session timeout,change to default session
		Dem_EnableDTCSetting(DEM_DTC_GROUP_ALL_DTCS, DEM_DTC_KIND_ALL_DTCS);//added 20160617,enable DTC setting 
        runtime->sessionControl = newSession;
        break;
    case DCM_PROGRAMMING_SESSION:
    case DCM_EXTENDED_DIAGNOSTIC_SESSION:
    case DCM_SAFTEY_SYSTEM_DIAGNOSTIC_SESSION:
    case DCM_ALL_SESSION_LEVEL:
#if defined(USE_COMM) || (DCM_UNIT_TEST == STD_ON)
        if( (newSession != runtime->sessionControl) && findProtocolRx(runtime->diagReqestRxPduId, &protocolRx) ) {
            /* Changing session */
            if( !runtime->diagnosticActiveComM ) {
                ComM_DCM_ActiveDiagnostic(protocolRx->DcmDslProtocolRxComMChannel); /** @req DCM167 */
                runtime->diagnosticActiveComM = TRUE;
            }
        }
#endif
        runtime->sessionControl = newSession;
        break;

    default:
        DCM_DET_REPORTERROR(DCM_CHANGE_DIAGNOSTIC_SESSION_ID, DCM_E_PARAM);
        break;
    }
    /* @req DCM628 */
    DspResetDiagnosticActivityOnSessionChange(newSession);
}

// - - - - - - - - - - -

void DslResetSessionTimeoutTimer(void) {
	const Dcm_DslProtocolRowType *activeProtocol;
	Dcm_DslRunTimeProtocolParametersType *runtime;

	activeProtocol = DcmDslRunTimeData.activeProtocol;
	if( NULL != activeProtocol ) {
		runtime = activeProtocol->DslRunTimeProtocolParameters;
		startS3SessionTimer(runtime, activeProtocol); /** @req DCM141 */
	}
}

// - - - - - - - - - - -

void DslGetCurrentServiceTable(const Dcm_DsdServiceTableType **currentServiceTable) { /** @req DCM195 */
	const Dcm_DslProtocolRowType *activeProtocol;

	activeProtocol = DcmDslRunTimeData.activeProtocol;
	if (activeProtocol != NULL) {
		*currentServiceTable = activeProtocol->DslProtocolSIDTable;
	}
}

// - - - - - - - - - - -

Std_ReturnType DslGetActiveProtocol(Dcm_ProtocolType *protocolId) { /** @req DCM340 */
	Std_ReturnType ret = E_NOT_OK;
	const Dcm_DslProtocolRowType *activeProtocol;

	activeProtocol = DcmDslRunTimeData.activeProtocol;
	if (activeProtocol != NULL) {
		*protocolId = activeProtocol->DslProtocolID;
		ret = E_OK;
	}
	return ret;
}

// - - - - - - - - - - -

void DslSetSecurityLevel(Dcm_SecLevelType secLevel) { /** @req DCM020 */
	const Dcm_DslProtocolRowType *activeProtocol;
	Dcm_DslRunTimeProtocolParametersType *runtime;

	activeProtocol = DcmDslRunTimeData.activeProtocol;
	runtime = activeProtocol->DslRunTimeProtocolParameters;
	runtime->securityLevel = secLevel;
}

// - - - - - - - - - - -

Std_ReturnType DslGetSecurityLevel(Dcm_SecLevelType *secLevel) {  /** @req DCM020 *//** @req DCM338 */
	Std_ReturnType ret = E_NOT_OK;
	const Dcm_DslProtocolRowType *activeProtocol;
	Dcm_DslRunTimeProtocolParametersType *runtime = NULL;

	activeProtocol = DcmDslRunTimeData.activeProtocol;
	if (activeProtocol != NULL) {
		runtime = activeProtocol->DslRunTimeProtocolParameters;
		*secLevel = runtime->securityLevel;
		ret = E_OK;
	}
	return ret;
}

// - - - - - - - - - - -

void DslSetSesCtrlType(Dcm_SesCtrlType sesCtrl) {  /** @req DCM022 */
	const Dcm_DslProtocolRowType *activeProtocol;
	Dcm_DslRunTimeProtocolParametersType *runtime = NULL;

	activeProtocol = DcmDslRunTimeData.activeProtocol;
	if (activeProtocol != NULL) {
		runtime = activeProtocol->DslRunTimeProtocolParameters;
        changeDiagnosticSession(runtime, sesCtrl);
        DslResetSessionTimeoutTimer();

	}
}

// - - - - - - - - - - -

Std_ReturnType DslGetSesCtrlType(Dcm_SesCtrlType *sesCtrlType) { /** @req DCM022 *//** @req DCM339 */
	Std_ReturnType 							ret = E_NOT_OK;
	const Dcm_DslProtocolRowType 			*activeProtocol;
	Dcm_DslRunTimeProtocolParametersType 	*runtime = NULL;

	activeProtocol = DcmDslRunTimeData.activeProtocol;
	if (activeProtocol != NULL) {
		runtime 	 = activeProtocol->DslRunTimeProtocolParameters;
		*sesCtrlType = runtime->sessionControl;
		ret = E_OK;
	}
	return ret;
}

const Dcm_DspSessionRowType *getActiveSessionRow(Dcm_DslRunTimeProtocolParametersType *runtime) {
	 const Dcm_DspSessionRowType *sessionRow = Dcm_ConfigPtr->Dsp->DspSession->DspSessionRow;

	while ((sessionRow->DspSessionLevel != runtime->sessionControl) && (!sessionRow->Arc_EOL) ) {
		sessionRow++;
	}
	if( TRUE == sessionRow->Arc_EOL ) {
		/* Since we are in a session with no configuration - take any session configuration and report error */
	    DCM_DET_REPORTERROR(DCM_CHANGE_DIAGNOSTIC_SESSION_ID, DCM_E_CONFIG_INVALID);
		sessionRow = Dcm_ConfigPtr->Dsp->DspSession->DspSessionRow;
	}

	return sessionRow;
}

// - - - - - - - - - - -

static boolean findRxPduIdParentConfigurationLeafs(PduIdType dcmRxPduId,
		const Dcm_DslProtocolRxType **protocolRx,
		const Dcm_DslMainConnectionType **mainConnection,
		const Dcm_DslConnectionType **connection,
		const Dcm_DslProtocolRowType **protocolRow,
		Dcm_DslRunTimeProtocolParametersType **runtime) {

	boolean ret = FALSE;
	if (dcmRxPduId < DCM_DSL_RX_PDU_ID_LIST_LENGTH) {
		*protocolRx = &Dcm_ConfigPtr->Dsl->DslProtocol->DslProtocolRxGlobalList[dcmRxPduId];
		*mainConnection = (*protocolRx)->DslMainConnectionParent;
		*connection = (*mainConnection)->DslConnectionParent;
		*protocolRow = (*connection)->DslProtocolRow;
		*runtime = (*protocolRow)->DslRunTimeProtocolParameters;
		ret = TRUE;
	}
	return ret;
}

// - - - - - - - - - - -

static boolean findTxPduIdParentConfigurationLeafs(PduIdType dcmTxPduId,
		const Dcm_DslProtocolRowType **protocolRow,
		Dcm_DslRunTimeProtocolParametersType **runtime) {

	boolean ret = FALSE;
	if (dcmTxPduId < DCM_DSL_TX_PDU_ID_LIST_LENGTH) {
	    const Dcm_DslMainConnectionType *mainConnection;
	    mainConnection = Dcm_ConfigPtr->Dsl->DslProtocol->DslProtocolTxGlobalList[dcmTxPduId].DslMainConnectionParent;
	    *protocolRow = mainConnection->DslConnectionParent->DslProtocolRow;
		*runtime = (*protocolRow)->DslRunTimeProtocolParameters;
		ret = TRUE;
	} 
#if 0
	else if(IS_PERIODIC_TX_PDU(dcmTxPduId)) {
	    *protocolRow = Dcm_ConfigPtr->Dsl->DslProtocol->DslProtocolPeriodicTxGlobalList[TO_INTERNAL_PERIODIC_PDU(dcmTxPduId)].DslProtocolRow;
	    *runtime = (*protocolRow)->DslRunTimeProtocolParameters;
	    ret = TRUE;
	}
#endif
	return ret;
}

// - - - - - - - - - - -

static inline void releaseExternalRxTxBuffers(const Dcm_DslProtocolRowType *protocolRow,
		Dcm_DslRunTimeProtocolParametersType *runtime) {

	protocolRow->DslProtocolTxBufferID->externalBufferRuntimeData->status = BUFFER_AVAILABLE;
	if(NULL != protocolRow->DslProtocolRxBufferID) {
	    protocolRow->DslProtocolRxBufferID->externalBufferRuntimeData->status = BUFFER_AVAILABLE;
	}
	runtime->externalTxBufferStatus = NOT_IN_USE; // We are waiting for DSD to return the buffer. qqq.
	runtime->externalRxBufferStatus = NOT_IN_USE; // We are waiting for DSD to return the buffer. qqq.
	protocolRow->DslProtocolTxBufferID->externalBufferRuntimeData->DcmRxPduId = DCM_INVALID_PDU_ID;
	if(runtime->isType2Tx) {
	    /* Release xx buffer for the periodic protocol */
	    const Dcm_DslProtocolRxType *protocolRx = NULL;
	    const Dcm_DslMainConnectionType *mainConnection = NULL;
	    const Dcm_DslConnectionType *connection = NULL;
	    const Dcm_DslProtocolRowType *rxProtocolRow = NULL;
	    Dcm_DslRunTimeProtocolParametersType *rxRuntime = NULL;
	    if(findRxPduIdParentConfigurationLeafs(runtime->diagReqestRxPduId, &protocolRx, &mainConnection, &connection, &rxProtocolRow, &rxRuntime)) {
	        mainConnection->DslPeriodicTransmissionConRef->DslProtocolRow->DslProtocolTxBufferID->externalBufferRuntimeData->status = BUFFER_AVAILABLE;
	        mainConnection->DslPeriodicTransmissionConRef->DslProtocolRow->DslRunTimeProtocolParameters->externalTxBufferStatus = NOT_IN_USE;
	    }
	}
	runtime->isType2Tx = FALSE;
}

// - - - - - - - - - - -


static inline void releaseExternalRxTxBuffersHelper(PduIdType rxPduIdRef) {
	const Dcm_DslProtocolRxType *protocolRx = NULL;
	const Dcm_DslMainConnectionType *mainConnection = NULL;
	const Dcm_DslConnectionType *connection = NULL;
	const Dcm_DslProtocolRowType *protocolRow = NULL;
	Dcm_DslRunTimeProtocolParametersType *runtime = NULL;

	if (findRxPduIdParentConfigurationLeafs(rxPduIdRef, &protocolRx, &mainConnection, &connection, &protocolRow, &runtime)) {
		releaseExternalRxTxBuffers(protocolRow, runtime);
	}
}

// - - - - - - - - - - -

/*
 *  This function is called from the DSD module to the DSL when
 *  a response to a diagnostic request has been copied into the
 *  given TX-buffer and is ready for transmission.
 */
void DslDsdProcessingDone(PduIdType rxPduIdRef, DsdProcessingDoneResultType responseResult) {
    const Dcm_DslProtocolRxType *protocolRx = NULL;
    const Dcm_DslMainConnectionType *mainConnection = NULL;
    const Dcm_DslConnectionType *connection = NULL;
    const Dcm_DslProtocolRowType *protocolRow = NULL;
    Dcm_DslRunTimeProtocolParametersType *runtime = NULL;
    Dcm_DslBufferUserType *bufferStatus = NULL;

    
    if (findRxPduIdParentConfigurationLeafs(rxPduIdRef, &protocolRx, &mainConnection, &connection, &protocolRow, &runtime)) {
        switch (responseResult) {
        case DSD_TX_RESPONSE_READY:
            if(runtime->isType2Tx) {
                bufferStatus = &mainConnection->DslPeriodicTransmissionConRef->DslProtocolRow->DslRunTimeProtocolParameters->externalTxBufferStatus;
            } else {
                bufferStatus = &runtime->externalTxBufferStatus;
            }
            *bufferStatus = DSD_PENDING_RESPONSE_SIGNALED; /** @req DCM114 */
            break;
        case DSD_TX_RESPONSE_SUPPRESSED: /** @req DCM238 */
            if(runtime->isType2Tx) {
                /* Release the tx pdu */
                PduIdType dcmTxPduId = 0xffff;
                if(DslPduRPduUsedForType2Tx(runtime->diagResponseTxPduId, &dcmTxPduId)) {
                    /* Release the tx pdu */
                    DslReleaseType2TxPdu(dcmTxPduId);
                }
            }
            releaseExternalRxTxBuffersHelper(rxPduIdRef);
            break;
        default:
            break;
        }
    }
}

// - - - - - - - - - - -

/*
 *	This function preparing transmission of response
 *	pending message to tester.
 */
static void sendResponse(const Dcm_DslProtocolRowType *protocol,
		Dcm_NegativeResponseCodeType responseCode) {
	const Dcm_DslProtocolRxType *protocolRx = NULL;
	const Dcm_DslMainConnectionType *mainConnection = NULL;
	const Dcm_DslConnectionType *connection = NULL;
	const Dcm_DslProtocolRowType *protocolRow = NULL;
	Dcm_DslRunTimeProtocolParametersType *runtime = NULL;
	Std_ReturnType transmitResult;
//    imask_t state;
    
//    Irq_Save(state);
    Disable_Interrupts();
	/** @req DCM119 */
	if (findRxPduIdParentConfigurationLeafs(protocol->DslRunTimeProtocolParameters->diagReqestRxPduId, &protocolRx,	&mainConnection, &connection, &protocolRow, &runtime)) {
		if (runtime->localTxBuffer.status == NOT_IN_USE) {
		    runtime->localTxBuffer.responseCode = responseCode;
			runtime->localTxBuffer.status = PROVIDED_TO_DSD;
			runtime->localTxBuffer.buffer[0] = SID_NEGATIVE_RESPONSE;
			runtime->localTxBuffer.buffer[1] = protocol->DslProtocolRxBufferID->pduInfo.SduDataPtr[0];
			runtime->localTxBuffer.buffer[2] = responseCode;
			runtime->localTxBuffer.PduInfo.SduDataPtr = runtime->localTxBuffer.buffer;
			runtime->localTxBuffer.PduInfo.SduLength = 3;
			runtime->localTxBuffer.status = DCM_TRANSMIT_SIGNALED; // In the DslProvideTxBuffer 'callback' this state signals it is the local buffer we are interested in sending.
			transmitResult = CanTp_Transmit(mainConnection->DslProtocolTx->DcmDslProtocolTxPduId, &(runtime->localTxBuffer.PduInfo));/** @req DCM115.Partially */ /* The P2ServerMin has not been implemented. */
			if (transmitResult != E_OK) {
				// IMPROVEMENT: What to do here?
			}
		}
	}
//    Irq_Restore(state);
    Enable_Interrupts();
}

// - - - - - - - - - - -

static Std_ReturnType StartProtocolHelper(Dcm_ProtocolType protocolId) {
	Std_ReturnType ret = E_NOT_OK;
	uint16_t i;

	for (i = 0; !Dcm_ConfigPtr->Dsl->DslCallbackDCMRequestService[i].Arc_EOL; i++) {
		if (Dcm_ConfigPtr->Dsl->DslCallbackDCMRequestService[i].StartProtocol != NULL) {
			ret = Dcm_ConfigPtr->Dsl->DslCallbackDCMRequestService[i]. StartProtocol(protocolId);
			if (ret != E_OK) {
				break;
			}
		}
	}
	return ret;
}

static boolean isTesterPresentCommand(const PduInfoType *rxPdu) {
	boolean ret = FALSE;
	if ((rxPdu->SduDataPtr[0] == SID_TESTER_PRESENT) && (rxPdu->SduDataPtr[1] == SUPPRESS_POS_RESP_BIT)) {
		ret = TRUE;
	}
	return ret;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	Implements 'void Dcm
//_Init(void)' for DSL.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void DslInit(void) {
	const Dcm_DslProtocolRowType *listEntry;
	Dcm_DslRunTimeProtocolParametersType *runtime = NULL;

	listEntry = Dcm_ConfigPtr->Dsl->DslProtocol->DslProtocolRowList;

	while (listEntry->Arc_EOL == FALSE) {
		runtime = listEntry->DslRunTimeProtocolParameters;
		runtime->externalRxBufferStatus = NOT_IN_USE;
		runtime->externalTxBufferStatus = NOT_IN_USE;
		runtime->localRxBuffer.status 	= NOT_IN_USE;
		runtime->localTxBuffer.status 	= NOT_IN_USE;
		runtime->securityLevel 			= DCM_SEC_LEV_LOCKED; /** @req DCM033 */
		runtime->sessionControl 		= DCM_DEFAULT_SESSION; /** @req DCM034 */
		runtime->diagnosticActiveComM 	= FALSE;
		runtime->protocolStarted 		= FALSE;// OBD: close the protocol
		/* Check that there is an rx buffer.
		 * Will not be in case of periodic transmission protocol */
		if(NULL != listEntry->DslProtocolRxBufferID) {
		    listEntry->DslProtocolRxBufferID->externalBufferRuntimeData->status = BUFFER_AVAILABLE;
		}
		listEntry->DslProtocolTxBufferID->externalBufferRuntimeData->status = BUFFER_AVAILABLE;
		listEntry->DslProtocolTxBufferID->externalBufferRuntimeData->DcmRxPduId = DCM_INVALID_PDU_ID;
		runtime->localRxBuffer.DcmRxPduId = DCM_INVALID_PDU_ID;
		runtime->isType2Tx = FALSE;
		listEntry++;
	};

	//DcmDslRunTimeData.diagnosticRequestPending = FALSE;
	DcmDslRunTimeData.initRun = TRUE;
	// NOTE: Why?
	DcmDslRunTimeData.activeProtocol = NULL;// OBD: close the current active protocol

	DslReleaseAllType2TxPdus();

}

boolean DslCheckType2TxPduAvailable(const Dcm_DslMainConnectionType *mainConnection)
{
#ifdef DCM_USE_TYPE2_PERIODIC_TRANSMISSION
    boolean ret = false;
    const Dcm_DslPeriodicTransmissionType *periodicTrans = mainConnection->DslPeriodicTransmissionConRef;
    /* Find a pdu to use */
    uint8 i = 0;
    while(!periodicTrans->TxPduList[i].Arc_EOL && !ret) {
        if(!PeriodicPduStatus[TO_INTERNAL_PERIODIC_PDU(periodicTrans->TxPduList[i].DcmTxPduId)].pduInUse) {
            /* Pdu available */
            ret = TRUE;
        }
        i++;
    }
    return ret;
#else
    (void)mainConnection;
    return FALSE;
#endif
}

static void DslReleaseAllType2TxPdus(void) {
#ifdef DCM_USE_TYPE2_PERIODIC_TRANSMISSION
    for(uint16 i = 0; i < DCM_NOF_PERIODIC_TX_PDU; i++) {
        PeriodicPduStatus[i].diagReqRxPduId = 0xFFFF;
        PeriodicPduStatus[i].pduInUse = FALSE;
    }
#endif
}
static void DslReleaseType2TxPdu(PduIdType txPduId) {
#ifdef DCM_USE_TYPE2_PERIODIC_TRANSMISSION
    if(IS_PERIODIC_TX_PDU(txPduId)) {
        PeriodicPduStatus[TO_INTERNAL_PERIODIC_PDU(txPduId)].pduInUse = FALSE;
        PeriodicPduStatus[TO_INTERNAL_PERIODIC_PDU(txPduId)].diagReqRxPduId = 0xffff;
    }
#else
    (void)txPduId;
#endif
}

#if defined(DCM_USE_TYPE2_PERIODIC_TRANSMISSION) && defined(DCM_TYPE2_TX_ROUTED_TO_IF)
static Std_ReturnType DslGetType2TxUserRxPdu(PduIdType type2TxPduId, PduIdType *rxPduId)
{
    Std_ReturnType ret = E_NOT_OK;
    if(IS_PERIODIC_TX_PDU(type2TxPduId) && PeriodicPduStatus[TO_INTERNAL_PERIODIC_PDU(type2TxPduId)].pduInUse) {
        *rxPduId = PeriodicPduStatus[TO_INTERNAL_PERIODIC_PDU(type2TxPduId)].diagReqRxPduId;
        ret = E_OK;
    }
    return ret;
}
#endif
static Std_ReturnType DslLockType2TxPdu(const Dcm_DslMainConnectionType *mainConnection, PduIdType requestRxPDuId, PduIdType *txPduId) {
#if defined(DCM_USE_TYPE2_PERIODIC_TRANSMISSION)
    Std_ReturnType ret = E_NOT_OK;
    const Dcm_DslPeriodicTransmissionType *periodicTrans = mainConnection->DslPeriodicTransmissionConRef;
    /* Find a pdu to use */
    uint8 i = 0;
    while(!periodicTrans->TxPduList[i].Arc_EOL && (E_OK != ret)) {
        if(!PeriodicPduStatus[TO_INTERNAL_PERIODIC_PDU(periodicTrans->TxPduList[i].DcmTxPduId)].pduInUse) {
            /* Pdu available */
            PeriodicPduStatus[TO_INTERNAL_PERIODIC_PDU(periodicTrans->TxPduList[i].DcmTxPduId)].pduInUse = TRUE;
            PeriodicPduStatus[TO_INTERNAL_PERIODIC_PDU(periodicTrans->TxPduList[i].DcmTxPduId)].diagReqRxPduId = requestRxPDuId;
            *txPduId = periodicTrans->TxPduList[i].PduRTxPduId;
            ret = E_OK;
        }
        i++;
    }
    return ret;
#else
    (void)mainConnection;
    (void)requestRxPDuId;
    (void)txPduId;
    return E_NOT_OK;
#endif
}

boolean DslPduRPduUsedForType2Tx(PduIdType pdurTxPduId, PduIdType *dcmTxPduId)
{
#if defined(DCM_USE_TYPE2_PERIODIC_TRANSMISSION)
    boolean isUsed = FALSE;
    const Dcm_DslPeriodicTxType *periodicTx = Dcm_ConfigPtr->Dsl->DslProtocol->DslProtocolPeriodicTxGlobalList;

    while(!periodicTx->Arc_EOL && !isUsed) {
        isUsed = (pdurTxPduId == periodicTx->PduRTxPduId);
        *dcmTxPduId = periodicTx->DcmTxPduId;
        periodicTx++;
    }
    return isUsed;
#else
    (void)pdurTxPduId;
	(void)dcmTxPduId;
    return FALSE;
#endif
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	Implements 'void DslInternal_ResponseOnOneDataByPeriodicId(uint8 PericodID)' for simulator a periodic did data.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

Std_ReturnType DslInternal_ResponseOnOneDataByPeriodicId(uint8_t PericodID, PduIdType rxPduId)
{
	Std_ReturnType ret = E_NOT_OK;
	Dcm_DslRunTimeProtocolParametersType *runtime = NULL;


	if( NULL != DcmDslRunTimeData.activeProtocol ) {
		runtime =  DcmDslRunTimeData.activeProtocol->DslRunTimeProtocolParameters;
		if(runtime != NULL)	// find the runtime
		{
			PduLengthType rxBufferSize;
			if( BUFREQ_OK == DslStartOfReception(rxPduId, 3, &rxBufferSize, TRUE)){
				PduInfoType  periodData;
				uint8_t data[3];
				periodData.SduDataPtr = data;
				periodData.SduDataPtr[0] = SID_READ_DATA_BY_PERIODIC_IDENTIFIER;
				periodData.SduDataPtr[1] = DCM_PERIODICTRANSMIT_DEFAULT_MODE;
				periodData.SduDataPtr[2] = PericodID;
				periodData.SduLength = 3;
				if( BUFREQ_OK == DslCopyDataToRxBuffer(rxPduId, &periodData, &rxBufferSize) ) {
					DslTpRxIndicationFromPduR(rxPduId, NTFRSLT_OK, TRUE );
				} else {
					/* Something went wrong. Indicate that the reception was
					 * not ok. */
					DslTpRxIndicationFromPduR(rxPduId, NTFRSLT_E_NOT_OK, TRUE);
				}
				ret = E_OK;
			}
		}
	}

	return ret;
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	Implements 'void Dcm_MainFunction(void)' for DSL.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void DslMain(void) {
	PduIdType                             dcmType2TxPduId ;
    const Dcm_DslProtocolRowType         *protocolRowEntry;
    const Dcm_DspSessionRowType          *sessionRow = NULL;
    Dcm_DslRunTimeProtocolParametersType *runtime = NULL;
    PduIdType                             txPduId;
    Dcm_DslRunTimeProtocolParametersType *txRuntime;
    PduIdType                             dcmTxPduId;

    protocolRowEntry = Dcm_ConfigPtr->Dsl->DslProtocol->DslProtocolRowList;
    //while (protocolRowEntry->Arc_EOL == FALSE) {
        runtime = protocolRowEntry->DslRunTimeProtocolParameters;
        if (runtime != NULL) {// #### HANDLE THE TESTER PRESENT PRESENCE ####
            if (runtime->sessionControl != DCM_DEFAULT_SESSION) { // Timeout if tester present is lost.
                if( TRUE == runtime->S3ServerStarted ) {
                    DECREMENT(runtime->S3ServerTimeoutCount);
                }
                if (runtime->S3ServerTimeoutCount == 0) {
                    DslReleaseAllType2TxPdus();
                    /* @req DCM626 *//* Changing session to default will stop control */
                    changeDiagnosticSession(runtime, DCM_DEFAULT_SESSION); /** @req DCM140 */
                }
            }
            switch (runtime->externalTxBufferStatus) { // #### TX buffer state. ####
                case NOT_IN_USE:
                    break;
                case PROVIDED_TO_DSD: {
                    DECREMENT(runtime->stateTimeoutCount);
                    if (runtime->stateTimeoutCount == 0) {
                        sessionRow = getActiveSessionRow(runtime);
                        runtime->stateTimeoutCount = DCM_CONVERT_MS_TO_MAIN_CYCLES(sessionRow->DspSessionP2StarServerMax); /* Reinitiate timer, see 9.2.2. */
                        if (Dcm_ConfigPtr->Dsl->DslDiagResp != NULL) {
                            if (Dcm_ConfigPtr->Dsl->DslDiagResp->DslDiagRespForceRespPendEn == TRUE) {
                                if (runtime->responsePendingCount != 0) {
                                /** !req DCM203 suppressPosRspBit should be cleared */
                                    sendResponse(protocolRowEntry, DCM_E_RESPONSEPENDING);  /** @req DCM024 */
                                    DECREMENT( runtime->responsePendingCount );
                                } else {
                                    DspCancelPendingRequests();
                                    sendResponse(protocolRowEntry, DCM_E_GENERALREJECT); /** @req DCM120 */
                                    releaseExternalRxTxBuffers(protocolRowEntry, runtime);
                                }
                            } else {
                                DspCancelPendingRequests();
                                sendResponse(protocolRowEntry, DCM_E_GENERALREJECT);
                                releaseExternalRxTxBuffers(protocolRowEntry, runtime);
                            }
                        }
                    }
                    break;
                }
            case DSD_PENDING_RESPONSE_SIGNALED:
                // The DSD has signaled to DSL that the diagnostic response is available in the Tx buffer.
                // Make sure that response pending or general reject have not been issued,
                // if so we can not transmit to PduR because we would not know from where
                // the Tx confirmation resides later.
                if (runtime->localTxBuffer.status == NOT_IN_USE) { // Make sure that no TxConfirm could be sent by the local buffer and mixed up with this transmission.
                    const Dcm_DslProtocolRxType *protocolRx = NULL;
                    const Dcm_DslMainConnectionType *mainConnection = NULL;
                    const Dcm_DslConnectionType *connection = NULL;
                    const Dcm_DslProtocolRowType *protocolRow = NULL;
                    Dcm_DslRunTimeProtocolParametersType *rxRuntime = NULL;
                    Std_ReturnType transmitResult;
                    if(findRxPduIdParentConfigurationLeafs(runtime->diagReqestRxPduId, &protocolRx, &mainConnection, &connection, &protocolRow, &rxRuntime)) {
                        
                        if(rxRuntime->isType2Tx) {
                            txRuntime = mainConnection->DslPeriodicTransmissionConRef->DslProtocolRow->DslRunTimeProtocolParameters;
                        } else {
                            txRuntime = rxRuntime;
                        }
                        txPduId = txRuntime->diagResponseTxPduId;
                        txRuntime->externalTxBufferStatus = DCM_TRANSMIT_SIGNALED;
                        transmitResult = CanTp_Transmit(txPduId, &txRuntime->diagnosticResponseFromDsd); /** @req DCM237 *//* Will trigger PduR (CanTP) to call DslProvideTxBuffer(). */
                        dcmType2TxPduId = 0xffff;
                        if( E_OK != transmitResult ) {
                            /* Transmit failed.
                             * If it is a type2 transmit, release the pdu. */
                            if(DslPduRPduUsedForType2Tx(txPduId, &dcmType2TxPduId)) {
                                DslReleaseType2TxPdu(dcmType2TxPduId);
                            } else {
                                /* Not a periodic pdu. Start s3 timer since there will be
                                 * no tx confirmation of this transmit request */
                                startS3SessionTimer(rxRuntime, protocolRow);
                            }
                            /* Release buffers */
                            releaseExternalRxTxBuffers(protocolRow, rxRuntime);
                        }
#if defined(DCM_TYPE2_TX_ROUTED_TO_IF)
                        /* Assuming that the transmit was routed directly to lower If.
                         * This means that data is copied directly on transmit request
                         * and we can drop the buffers. */
                        else if( DslPduRPduUsedForType2Tx(txPduId, &dcmType2TxPduId) ) {
                            /* It is a type2 transmit. Release buffers. */
                            releaseExternalRxTxBuffers(protocolRow, rxRuntime);
                        }
#endif
                    } else {
                        txPduId = protocolRowEntry->DslConnection->DslMainConnection->DslProtocolTx->DcmDslProtocolTxPduId;
                        runtime->externalTxBufferStatus = DCM_TRANSMIT_SIGNALED;
                        transmitResult = CanTp_Transmit(txPduId, &runtime->diagnosticResponseFromDsd); /** @req DCM237 *//* Will trigger PduR (CanTP) to call DslProvideTxBuffer(). */
                        if (transmitResult != E_OK) {
                            /* Transmit request failed, release the buffers */
                            releaseExternalRxTxBuffers(protocolRow, runtime);
                            dcmTxPduId = 0xffff;
                            if(DslPduRPduUsedForType2Tx(txPduId, &dcmTxPduId)) {
                                DslReleaseType2TxPdu(dcmTxPduId);
                            }
                            /* Start s3 timer since there will be no tx confirmation of this transmit request */
                            startS3SessionTimer(rxRuntime, protocolRow);
                        }
                    }
                }
                break;
            case DCM_TRANSMIT_SIGNALED:
                break;
            case PROVIDED_TO_PDUR: // The valid data is being transmitted by TP-layer.
                break;
                
            case PREEMPT_TRANSMIT_NRC: /* preemption has happened,send NRC 0x21 to OBD tester */
                break;
            default:
                break;
            }
        }
        //protocolRowEntry++;
    //}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	Implements 'BufReq_ReturnType Dcm_StartOfReception(PduIdType dcmRxPduId,
//	PduLengthType tpSduLength, PduLengthType *rxBufferSizePtr)'.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  This function is called called by the PduR typically when CanTp has
//  received a FF or a single frame and needs to obtain a buffer from the
//  receiver so that received data can be forwarded.
BufReq_ReturnType DslStartOfReception(PduIdType dcmRxPduId, PduLengthType tpSduLength, PduLengthType *rxBufferSizePtr, boolean internalRequest)
{
    BufReq_ReturnType                    ret = BUFREQ_NOT_OK;
    const Dcm_DslProtocolRxType          *protocolRx = NULL;
    const Dcm_DslMainConnectionType      *mainConnection = NULL;
    const Dcm_DslConnectionType          *connection = NULL;
    const Dcm_DslProtocolRowType         *protocolRow = NULL;
    Dcm_DslRunTimeProtocolParametersType *runtime = NULL;
    boolean                               intType2Request = FALSE; 
//    imask_t                               state;

//    Irq_Save(state);


  //  Disable_Interrupts();
   
#if 1

    if (findRxPduIdParentConfigurationLeafs(dcmRxPduId, &protocolRx, &mainConnection, &connection, &protocolRow, &runtime)) {
#if 0
        const Dcm_DslBufferType *externalRxBuffer = protocolRow->DslProtocolRxBufferID;
        intType2Request = internalRequest && (DCM_PROTOCOL_TRANS_TYPE_2 == protocolRow->DslProtocolTransType);
	
        if( !(internalRequest && (DCM_PROTOCOL_TRANS_TYPE_2 == protocolRow->DslProtocolTransType)) || DslCheckType2TxPduAvailable(mainConnection) ) {
            if (externalRxBuffer->pduInfo.SduLength >= tpSduLength) { /** @req DCM443 */
                if((runtime->externalRxBufferStatus == NOT_IN_USE) && (externalRxBuffer->externalBufferRuntimeData->status == BUFFER_AVAILABLE)) {
                    // ### EXTERNAL BUFFER IS AVAILABLE; GRAB IT AND REMEBER THAT WE OWN IT! ###
                    externalRxBuffer->externalBufferRuntimeData->status = BUFFER_BUSY;
                    runtime->diagnosticRequestFromTester.SduDataPtr = externalRxBuffer->pduInfo.SduDataPtr;
                    runtime->diagnosticRequestFromTester.SduLength = tpSduLength;
                    externalRxBuffer->externalBufferRuntimeData->nofBytesHandled = 0;
                    runtime->externalRxBufferStatus = PROVIDED_TO_PDUR; /** @req DCM342 */
                    //If external buffer is provided memorize DcmPduId
                    externalRxBuffer->externalBufferRuntimeData->DcmRxPduId = dcmRxPduId;
                    *rxBufferSizePtr = externalRxBuffer->pduInfo.SduLength;
                    ret = BUFREQ_OK;
                } else {
                    if ((NOT_IN_USE == runtime->localRxBuffer.status) && (!internalRequest)) {
                        /* ### EXTERNAL BUFFER IS IN USE BY THE DSD OR PDUR, TRY TO USE LOCAL BUFFER ONLY FOR FUNCTIONAL REQUEST ( ONLY FOR TESTER PRESENT)! ###
                         * Note: There is no way to predict that request is Tester present because pduInfoPtr->SduDataPtr not available.
                         * This is handled in DslTpRxIndicationFromPduR().
                         * But if it is an internal request we now that it is not Tester present.
                         */
                        if (tpSduLength <= DCM_DSL_LOCAL_BUFFER_LENGTH) {
                            runtime->localRxBuffer.status = PROVIDED_TO_PDUR;
                            runtime->localRxBuffer.PduInfo.SduDataPtr = runtime->localRxBuffer.buffer;
                            runtime->localRxBuffer.PduInfo.SduLength = tpSduLength;
                            runtime->localRxBuffer.nofBytesHandled = 0;
                            //If local buffer is provided memorize DcmPduId
                            runtime->localRxBuffer.DcmRxPduId = dcmRxPduId;
                            *rxBufferSizePtr = DCM_DSL_LOCAL_BUFFER_LENGTH;
                            ret = BUFREQ_OK;
                        }
                        else if (externalRxBuffer->externalBufferRuntimeData->DcmRxPduId == dcmRxPduId) {
                            /* This case avoids receiving a new FF is received while MF transmission is ongoing as a response to previous SF request.
                             * Half Duplex case - runtime->externalRxBufferStatus == PROVIDED_TO_DSD
                             */
                            ret = BUFREQ_E_NOT_OK;
                        }
                        else {
                            /* Half duplex - This case avoids a condition where External buffer is locked by a
                             * Functional request and we receive a FF as a physical request */
                            ret = BUFREQ_E_NOT_OK; /** This is a multi-frame reception and discard request. */
                        }
                    }
                    else {
                        /* Internal request or there is no buffer available, wait until it is free. */
                        ret = BUFREQ_BUSY;
                    }
                }
            } else {
                ret = BUFREQ_OVFL; /** @req DCM444 */
            }
        } else {
            /* Internal request for type2 transmission and no pdu available right now */
            ret = BUFREQ_BUSY;
        }
        /* Do not stop s3 timer on internal type2 request. */
        if (!intType2Request && (ret == BUFREQ_OK)) {
            stopS3SessionTimer(runtime); /** @req DCM141 */
        }
#endif
    }
//    Irq_Restore(state);
#endif
  

 //  Enable_Interrupts();


    return ret;
}
const Dcm_DslBufferType *externalRxBuffer;
 uint8_t *destPtr;
BufReq_ReturnType DslCopyDataToRxBuffer(PduIdType dcmRxPduId, PduInfoType *pduInfoPtr, PduLengthType *rxBufferSizePtr)
{
    BufReq_ReturnType returnCode = BUFREQ_NOT_OK;
    const Dcm_DslProtocolRxType *protocolRx = NULL;
    const Dcm_DslMainConnectionType *mainConnection = NULL;
    const Dcm_DslConnectionType *connection = NULL;
    const Dcm_DslProtocolRowType *protocolRow = NULL;
    Dcm_DslRunTimeProtocolParametersType *runtime = NULL;
//    imask_t state;
//    Irq_Save(state);
    Disable_Interrupts();
    if (findRxPduIdParentConfigurationLeafs(dcmRxPduId, &protocolRx, &mainConnection, &connection, &protocolRow, &runtime)) {
        /*const Dcm_DslBufferType **/externalRxBuffer = protocolRow->DslProtocolRxBufferID;
        if ((PROVIDED_TO_PDUR == runtime->externalRxBufferStatus ) && (externalRxBuffer->externalBufferRuntimeData->DcmRxPduId == dcmRxPduId)){
            /* Buffer is provided to PDUR. Copy data to buffer */
            /*uint8 **/destPtr = &(runtime->diagnosticRequestFromTester.SduDataPtr[externalRxBuffer->externalBufferRuntimeData->nofBytesHandled]);
            if( 0 == pduInfoPtr->SduLength ) {
                /* Just polling remaining buffer size */
                returnCode = BUFREQ_OK;
            //} else if( pduInfoPtr->SduLength <= (externalRxBuffer->pduInfo.SduLength - externalRxBuffer->externalBufferRuntimeData->nofBytesHandled) ) {
	    } else if( (pduInfoPtr->SduLength + externalRxBuffer->externalBufferRuntimeData->nofBytesHandled) <= externalRxBuffer->pduInfo.SduLength  ) {
                /* Enough room in buffer. Copy data. */
                /** @req DCM443 */
                memcpy(destPtr, pduInfoPtr->SduDataPtr, pduInfoPtr->SduLength);
                /* Inc nof bytes handled byte */
                externalRxBuffer->externalBufferRuntimeData->nofBytesHandled += pduInfoPtr->SduLength;
                returnCode = BUFREQ_OK;
            } else {
                /* Length exceeds number of bytes left in buffer */
                DCM_DET_REPORTERROR(DCM_COPY_RX_DATA_ID, DCM_E_INTERFACE_BUFFER_OVERFLOW);
                returnCode = BUFREQ_NOT_OK;
            }
                *rxBufferSizePtr =
                            externalRxBuffer->pduInfo.SduLength - externalRxBuffer->externalBufferRuntimeData->nofBytesHandled;
        } else if ((runtime->localRxBuffer.status == PROVIDED_TO_PDUR) && (runtime->localRxBuffer.DcmRxPduId == dcmRxPduId)){
            /* Local buffer provided to pdur */
            if(0 == pduInfoPtr->SduLength) {
                /* Just polling remaining buffer size */
                returnCode = BUFREQ_OK;
            } else if(pduInfoPtr->SduLength <= (DCM_DSL_LOCAL_BUFFER_LENGTH - runtime->localRxBuffer.nofBytesHandled)) {
                uint8_t *destPtr = &(runtime->localRxBuffer.PduInfo.SduDataPtr[runtime->localRxBuffer.nofBytesHandled]);
                memcpy(destPtr, pduInfoPtr->SduDataPtr, pduInfoPtr->SduLength);
                runtime->localRxBuffer.nofBytesHandled += pduInfoPtr->SduLength;
                returnCode = BUFREQ_OK;
            } else {
                /* Length exceeds buffer size */
                DCM_DET_REPORTERROR(DCM_COPY_RX_DATA_ID, DCM_E_INTERFACE_BUFFER_OVERFLOW);
                returnCode = BUFREQ_NOT_OK;
            }
            *rxBufferSizePtr = DCM_DSL_LOCAL_BUFFER_LENGTH - runtime->localRxBuffer.nofBytesHandled;
        }
    }
//    Irq_Restore(state);
    Enable_Interrupts();
    return returnCode;

}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	Implements 'void Dcm_TpRxIndication(PduIdType dcmRxPduId, NotifResultType result)'.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// 	This function is called called by the PduR typically when CanTp has
//	received the diagnostic request, copied it to the provided buffer and need to indicate
//	this to the DCM (DSL) module via proprietary API.

void DslTpRxIndicationFromPduR(PduIdType dcmRxPduId, NotifResultType result, boolean internalRequest) {
    const Dcm_DslProtocolRxType          *protocolRx = NULL;
    const Dcm_DslMainConnectionType      *mainConnection = NULL;
    const Dcm_DslConnectionType          *connection = NULL;
    const Dcm_DslProtocolRowType         *protocolRow = NULL;
    const Dcm_DspSessionRowType          *sessionRow = NULL;
    Dcm_DslRunTimeProtocolParametersType *rxRuntime = NULL;
    Std_ReturnType                       higherLayerResp;
//    imask_t                              state;
    const Dcm_DslBufferType              *txBuffer = NULL;
    Dcm_DslRunTimeProtocolParametersType *txRuntime;
	boolean                              type2Tx;
	PduIdType                            type2TxPduId = 0xffff;

    /** @req DCM345, this needs to be verified when connection to CanIf works. */

    if (findRxPduIdParentConfigurationLeafs(dcmRxPduId, &protocolRx, &mainConnection, &connection, &protocolRow, &rxRuntime)) {
        // We need to find out in what buffer we can find our Rx data (it can
        // be either in the normal RX-buffer or the 'extra' buffer for implementing
        // the Concurrent "Test Present" functionality.
        const Dcm_DslBufferType *externalRxBuffer = protocolRow->DslProtocolRxBufferID;
//        Irq_Save(state);
        Disable_Interrupts();
        if ((rxRuntime->externalRxBufferStatus == PROVIDED_TO_PDUR) && (externalRxBuffer->externalBufferRuntimeData->DcmRxPduId == dcmRxPduId)) {
            boolean receivedLenOK =
                    (externalRxBuffer->externalBufferRuntimeData->nofBytesHandled == rxRuntime->diagnosticRequestFromTester.SduLength) ||
                    (0 == rxRuntime->diagnosticRequestFromTester.SduLength);
            
            type2Tx = (DCM_PROTOCOL_TRANS_TYPE_2 == protocolRow->DslProtocolTransType) && internalRequest;
            if ( (result == NTFRSLT_OK) && receivedLenOK &&(!type2Tx || (E_OK == DslLockType2TxPdu(mainConnection, dcmRxPduId, &type2TxPduId))) ) { /** @req DCM111 */
                if ((isTesterPresentCommand(&(protocolRow->DslProtocolRxBufferID->pduInfo)))&&((rxRuntime->diagnosticRequestFromTester.SduLength == 2))) {//modified by xy,20160413
                    startS3SessionTimer(rxRuntime, protocolRow); /** @req DCM141 *//** @req DCM112 *//** @req DCM113 */
                    rxRuntime->externalRxBufferStatus = NOT_IN_USE;
                    externalRxBuffer->externalBufferRuntimeData->DcmRxPduId = DCM_INVALID_PDU_ID;
                    protocolRow->DslProtocolRxBufferID->externalBufferRuntimeData->status = BUFFER_AVAILABLE;
#if defined(USE_COMM) || (DCM_UNIT_TEST == STD_ON)
                    if( DCM_DEFAULT_SESSION == rxRuntime->sessionControl ) {
                        if( !rxRuntime->diagnosticActiveComM  ) {
                            ComM_DCM_ActiveDiagnostic(protocolRx->DcmDslProtocolRxComMChannel); /** @req DCM163 */
                            ComM_DCM_InactiveDiagnostic(protocolRx->DcmDslProtocolRxComMChannel); /** @req DCM166 */
                            rxRuntime->diagnosticActiveComM = FALSE;
                        }
                    }
#endif
				}else {
                    if (rxRuntime->protocolStarted == FALSE) {
                        //if there is no active protocol,then start the current protocol
                        if(DcmDslRunTimeData.activeProtocol == NULL){
                            higherLayerResp = StartProtocolHelper(protocolRow->DslProtocolID); /** @req DCM036 */
                            if (higherLayerResp == E_OK) {
                                /** !req146 Should reset security state */
                                /** !req147 Should reset to default session and switch mode */
                                rxRuntime->protocolStarted = TRUE;
                                DcmDslRunTimeData.activeProtocol = protocolRow;
                            }
                        }
                    }
                    if (rxRuntime->protocolStarted == TRUE) {
#if defined(USE_COMM) || (DCM_UNIT_TEST == STD_ON)
                        if( DCM_DEFAULT_SESSION == rxRuntime->sessionControl ) {
                            if( !rxRuntime->diagnosticActiveComM ) {
                                ComM_DCM_ActiveDiagnostic(protocolRx->DcmDslProtocolRxComMChannel); /** @req DCM163 */
                                rxRuntime->diagnosticActiveComM = TRUE;
                            }
                        }
#endif
                        sessionRow = getActiveSessionRow(rxRuntime);
                        rxRuntime->externalRxBufferStatus = PROVIDED_TO_DSD; /** @req DCM241 */
                        
                        rxRuntime->isType2Tx = type2Tx;
                        
                        if( type2Tx ) {
                            /* @req DCM122 */
                            txRuntime = mainConnection->DslPeriodicTransmissionConRef->DslProtocolRow->DslRunTimeProtocolParameters;
                            txBuffer = mainConnection->DslPeriodicTransmissionConRef->DslProtocolRow->DslProtocolTxBufferID;
                            txRuntime->diagResponseTxPduId = type2TxPduId;
                            txRuntime->diagReqestRxPduId = dcmRxPduId;

                        } else {
                            txRuntime = rxRuntime;
                            txRuntime->diagResponseTxPduId = mainConnection->DslProtocolTx->DcmDslProtocolTxPduId;
                            txBuffer = protocolRow->DslProtocolTxBufferID;
                        }
                        rxRuntime->diagResponseTxPduId = txRuntime->diagResponseTxPduId;
                        txRuntime->stateTimeoutCount = DCM_CONVERT_MS_TO_MAIN_CYCLES(sessionRow->DspSessionP2ServerMax); /* See 9.2.2. */
                        if (txRuntime->externalTxBufferStatus == NOT_IN_USE) {
                        }
                        if( 0 == rxRuntime->diagnosticRequestFromTester.SduLength ) {
                            /* The original transfer request on call of Dcm_StartOfReception was 0. Set length
                            * of diagnostic request to the number of bytes received. */
                            rxRuntime->diagnosticRequestFromTester.SduLength = externalRxBuffer->externalBufferRuntimeData->nofBytesHandled;
                        }
                        txRuntime->externalTxBufferStatus = PROVIDED_TO_DSD; /** @req DCM241 */
                        txRuntime->responsePendingCount = Dcm_ConfigPtr->Dsl->DslDiagResp->DslDiagRespMaxNumRespPend;
                        txRuntime->diagnosticResponseFromDsd.SduDataPtr = txBuffer->pduInfo.SduDataPtr;
                        txRuntime->diagnosticResponseFromDsd.SduLength = txBuffer->pduInfo.SduLength;
                        rxRuntime->diagReqestRxPduId = dcmRxPduId;
                        DsdDslDataIndication(  // qqq: We are inside a critical section.
                            &(rxRuntime->diagnosticRequestFromTester),
                            protocolRow->DslProtocolSIDTable,	/** @req DCM035 */
                            protocolRx->DslProtocolAddrType,
                            txRuntime->diagResponseTxPduId,
                            &(txRuntime->diagnosticResponseFromDsd),
                            dcmRxPduId,
                            protocolRow->DslProtocolTransType,
                            internalRequest);
                    }
                }
            } else { /** @req DCM344 */
                /* The indication was not equal to NTFRSLT_OK, the length did not match or no type2 pdu was available,
                 * release the resources and no forward to DSD.*/
                if(!receivedLenOK) {
                    /* Number of bytes received does not match the original request */
                    DCM_DET_REPORTERROR(DCM_TP_RX_INDICATION_ID, DCM_E_TP_LENGTH_MISMATCH);
                }
                DslResetSessionTimeoutTimer(); /** @req DCM141 */
                rxRuntime->externalRxBufferStatus = NOT_IN_USE;
                externalRxBuffer->externalBufferRuntimeData->DcmRxPduId = DCM_INVALID_PDU_ID;
                protocolRow->DslProtocolRxBufferID->externalBufferRuntimeData->status = BUFFER_AVAILABLE;
            }
        } else {
            // It is the local buffer that was provided to the PduR, that buffer
            // is only used for tester present reception in parallel to diagnostic
            // requests.
            if ((rxRuntime->localRxBuffer.status == PROVIDED_TO_PDUR) && (rxRuntime->localRxBuffer.DcmRxPduId == dcmRxPduId)) {
                boolean receivedLenOK = ((0 == rxRuntime->localRxBuffer.PduInfo.SduLength) ||
                        (rxRuntime->localRxBuffer.PduInfo.SduLength == rxRuntime->localRxBuffer.nofBytesHandled));
                if ( (result == NTFRSLT_OK) && receivedLenOK ) { // Make sure that the data in buffer is valid.
                    if (isTesterPresentCommand(&(rxRuntime->localRxBuffer.PduInfo))) {
                        startS3SessionTimer(rxRuntime, protocolRow); /** @req DCM141 *//** @req DCM112 *//** @req DCM113 */
                    }
                } else {
                    if(!receivedLenOK) {
                        /* Number of bytes received does not match the original request */
                        DCM_DET_REPORTERROR(DCM_TP_RX_INDICATION_ID, DCM_E_TP_LENGTH_MISMATCH);
                    }
                    DslResetSessionTimeoutTimer(); /** @req DCM141 */
                }
                rxRuntime->localRxBuffer.status = NOT_IN_USE;
                rxRuntime->localRxBuffer.DcmRxPduId = DCM_INVALID_PDU_ID;
            }
        }
//        Irq_Restore(state);
        Enable_Interrupts();
    }
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	Implements 'BufReq_ReturnType Dcm_CopyTxData(PduIdType dcmTxPduId,
//		PduInfoType *pduInfoPtr, RetryInfoType *retryInfoPtr, PduLengthType *txDataCntPtr)'.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  This TX-buffer request is likely triggered by the transport layer (i.e. CanTp)
//  after PduR_DcmTransmit() has been called (via PduR to CanTp) indicating that something
//  is to be sent. The PduR_DcmTransmit() call is done from the DSL main function when
//  it has detected that the pending request has been answered by DSD
//  (or any other module?).

BufReq_ReturnType DslCopyTxData(PduIdType dcmTxPduId, PduInfoType *pduInfoPtr, RetryInfoType *periodData, PduLengthType *txDataCntPtr)
{
	BufReq_ReturnType ret = BUFREQ_NOT_OK;
	const Dcm_DslProtocolRowType *protocolRow = NULL;
	Dcm_DslRunTimeProtocolParametersType *runtime = NULL;
	//lint -estring(920,pointer)  /* cast to void */
	(void) periodData;//Not used
	//lint +estring(920,pointer)  /* cast to void */

	if (findTxPduIdParentConfigurationLeafs(dcmTxPduId, &protocolRow, &runtime)) {
		const Dcm_DslBufferType *externalTxBuffer = protocolRow->DslProtocolTxBufferID;
		ret = BUFREQ_OK;
		switch (runtime->externalTxBufferStatus) { // ### EXTERNAL TX BUFFER ###
		case DCM_TRANSMIT_SIGNALED:
			externalTxBuffer->externalBufferRuntimeData->nofBytesHandled = 0;
			runtime->externalTxBufferStatus = PROVIDED_TO_PDUR; /** @req DCM349 */
			break;
		case PROVIDED_TO_PDUR:
			break;
		default:
			ret = BUFREQ_NOT_OK;
			break;
		}
		if( BUFREQ_OK == ret ) {
			if( 0 == pduInfoPtr->SduLength ) {
				/* Just polling size of data left to send */
			} else if( pduInfoPtr->SduLength > (runtime->diagnosticResponseFromDsd.SduLength - externalTxBuffer->externalBufferRuntimeData->nofBytesHandled) ) {
				/* Length exceeds the number of bytes still to be sent. */
				ret = BUFREQ_NOT_OK;
			} else {
				/** @req DCM346 */ /* Length verification is already done if this state is reached. */
				memcpy(pduInfoPtr->SduDataPtr, &runtime->diagnosticResponseFromDsd.SduDataPtr[externalTxBuffer->externalBufferRuntimeData->nofBytesHandled], pduInfoPtr->SduLength);
				externalTxBuffer->externalBufferRuntimeData->nofBytesHandled += pduInfoPtr->SduLength;
			}
			*txDataCntPtr = runtime->diagnosticResponseFromDsd.SduLength - externalTxBuffer->externalBufferRuntimeData->nofBytesHandled;
		} else if (ret == BUFREQ_NOT_OK) {
			ret = BUFREQ_OK;
			switch (runtime->localTxBuffer.status) { // ### LOCAL TX BUFFER ###
			case DCM_TRANSMIT_SIGNALED: {
				runtime->localTxBuffer.PduInfo.SduDataPtr = runtime->localTxBuffer.buffer;
				runtime->localTxBuffer.nofBytesHandled = 0;
				runtime->localTxBuffer.status = PROVIDED_TO_PDUR; // Now the DSL should not touch this Tx-buffer anymore.
				break;
			}
			case PROVIDED_TO_PDUR:
				break;
			default:
				ret = BUFREQ_NOT_OK;
				break;
			}
			if( BUFREQ_OK == ret ) {
				if( 0 == pduInfoPtr->SduLength ) {
					/* Just polling size of data left to send */
				} else if( pduInfoPtr->SduLength > (runtime->localTxBuffer.PduInfo.SduLength - runtime->localTxBuffer.nofBytesHandled) ) {
					/* Length exceeds the number of bytes still to be sent. */
					ret = BUFREQ_NOT_OK;
				} else {
					memcpy(pduInfoPtr->SduDataPtr, &runtime->localTxBuffer.PduInfo.SduDataPtr[runtime->localTxBuffer.nofBytesHandled], pduInfoPtr->SduLength);
					runtime->localTxBuffer.nofBytesHandled += pduInfoPtr->SduLength;
				}
				*txDataCntPtr = runtime->localTxBuffer.PduInfo.SduLength - runtime->localTxBuffer.nofBytesHandled;
			}
		}
	}
	return ret;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//	Implements 'void Dcm_TpTxConfirmation(PduIdType dcmTxPduId, NotifResultType result))'.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// 	This function is called by the PduR (which has been trigged by i.e. CanTp)
// 	when a transmission has been successfully finished, have had errors or
// 	is even stopped.

void DslTpTxConfirmation(PduIdType dcmTxPduId, NotifResultType result) {
    const Dcm_DslProtocolRxType *protocolRx = NULL;
    const Dcm_DslMainConnectionType *rxMainConnection = NULL;
    const Dcm_DslConnectionType *rxConnection = NULL;
    const Dcm_DslProtocolRowType *txProtocolRow = NULL;
    const Dcm_DslProtocolRowType *rxProtocolRow = NULL;
    Dcm_DslRunTimeProtocolParametersType *txRuntime = NULL;
    Dcm_DslRunTimeProtocolParametersType *rxRuntime = NULL;
//    imask_t state;

   
        if (findTxPduIdParentConfigurationLeafs(dcmTxPduId, &txProtocolRow, &txRuntime) &&
                findRxPduIdParentConfigurationLeafs(txRuntime->diagReqestRxPduId, &protocolRx, &rxMainConnection, &rxConnection, &rxProtocolRow, &rxRuntime)) {
            boolean externalBufferReleased = FALSE;
            const Dcm_DslBufferType *externalTxBuffer = txProtocolRow->DslProtocolTxBufferID;
            // Free the buffer and free the Pdu runtime data buffer.
//            Irq_Save(state);
            Disable_Interrupts();
            switch (txRuntime->externalTxBufferStatus) { // ### EXTERNAL TX BUFFER ###
            case PROVIDED_TO_PDUR: {
                if( txRuntime->diagnosticResponseFromDsd.SduLength != externalTxBuffer->externalBufferRuntimeData->nofBytesHandled ) {
                    DCM_DET_REPORTERROR(DCM_TP_TX_CONFIRMATION_ID, DCM_E_TP_LENGTH_MISMATCH);
                }
#if defined(USE_COMM) || (DCM_UNIT_TEST == STD_ON)
                if(  DCM_DEFAULT_SESSION == rxRuntime->sessionControl ) {
                    if( findProtocolRx(rxRuntime->diagReqestRxPduId, &protocolRx) ) {
                        if( rxRuntime->diagnosticActiveComM ) {
                            ComM_DCM_InactiveDiagnostic(protocolRx->DcmDslProtocolRxComMChannel); /** @req DCM164 */
                            rxRuntime->diagnosticActiveComM = FALSE;
                        }
                    }
                }
#endif
                releaseExternalRxTxBuffers(rxProtocolRow, rxRuntime); /** @req DCM118 *//** @req DCM352 *//** @req DCM353 *//** @req DCM354 */
                externalBufferReleased = TRUE;
                {
                    /* Only start s3 timer if non-periodic */
                    startS3SessionTimer(rxRuntime, rxProtocolRow); /** @req DCM141 */
                    DsdDataConfirmation(rxMainConnection->DslProtocolTx->DcmDslProtocolTxPduId, result); /** @req DCM117 *//** @req DCM235 */
                }
                break;
            }
            default:
                break;
            }
            if (!externalBufferReleased) {
                switch (txRuntime->localTxBuffer.status) { // ### LOCAL TX BUFFER ###
                case PROVIDED_TO_PDUR:
                    if( txRuntime->localTxBuffer.PduInfo.SduLength != txRuntime->localTxBuffer.nofBytesHandled ) {
                        DCM_DET_REPORTERROR(DCM_TP_TX_CONFIRMATION_ID, DCM_E_TP_LENGTH_MISMATCH);
                    }
#if defined(USE_COMM) || (DCM_UNIT_TEST == STD_ON)
                    if( DCM_E_RESPONSEPENDING != txRuntime->localTxBuffer.responseCode ) {
                        if( DCM_DEFAULT_SESSION == rxRuntime->sessionControl ) {
                            if( findProtocolRx(rxRuntime->diagReqestRxPduId, &protocolRx) ) {
                                if( rxRuntime->diagnosticActiveComM ) {
                                    ComM_DCM_InactiveDiagnostic(protocolRx->DcmDslProtocolRxComMChannel); /** @req DCM165 */
                                    rxRuntime->diagnosticActiveComM = FALSE;
                                }
                            }
                        }
                    }
#endif
                    txRuntime->localTxBuffer.status = NOT_IN_USE;
                    break;
                default:
                    break;
                }
            }
//            Irq_Restore(state);
            Enable_Interrupts();
        }
    

}


#if (DCM_MANUFACTURER_NOTIFICATION == STD_ON)
void Arc_DslGetRxConnectionParams(PduIdType rxPduId, uint16* sourceAddress, Dcm_ProtocolAddrTypeType* reqType) {
    const Dcm_DslProtocolRxType *protocolRx = NULL;
    const Dcm_DslMainConnectionType *mainConnection = NULL;
    const Dcm_DslConnectionType *connection = NULL;
    const Dcm_DslProtocolRowType *protocolRow = NULL;
    Dcm_DslRunTimeProtocolParametersType *runtime = NULL;

    if (findRxPduIdParentConfigurationLeafs(rxPduId, &protocolRx, &mainConnection, &connection, &protocolRow, &runtime)) {
        *sourceAddress = mainConnection->DslRxTesterSourceAddress;
        *reqType = protocolRx->DslProtocolAddrType;
    }
    else {
        DCM_DET_REPORTERROR(DCM_GLOBAL_ID, DCM_E_UNEXPECTED_EXECUTION);
    }
}

#endif


Std_ReturnType DspTesterRequestDTC(uint8_t ecu_id,uint8_t subfunc,uint8_t *pDTC,uint8_t mask)
{
//	const Dcm_DslProtocolTxType          *protocolTx = NULL;
	const Dcm_DslConnectionType          *connection = NULL;
	const Dcm_DslProtocolRowType         *protocolRow = NULL;
	Dcm_DslRunTimeProtocolParametersType *runtime = NULL;
	Std_ReturnType transmitResult = E_NOT_OK;
	
	if (!((subfunc == 1) || (subfunc == 2) || (subfunc == 4) || (subfunc == 6)))
		return E_NOT_OK;
	
	if (findTxPduIdParentConfigurationLeafs(ecu_id, &protocolRow, &runtime)) {
		connection = protocolRow->DslConnection;
		if (runtime->localTxBuffer.status == NOT_IN_USE) {
			runtime->localTxBuffer.buffer[0] = SID_REQUEST_VEHICLE_DTC;
			runtime->localTxBuffer.buffer[1] = (uint8_t)(subfunc)&0xFFU;
			if ((subfunc == 1) || (subfunc == 2)) {
				runtime->localTxBuffer.buffer[2] = (uint8_t)(mask)&0xFFU;
				runtime->localTxBuffer.PduInfo.SduLength = 3;
			}else {
				runtime->localTxBuffer.buffer[2] = *pDTC++;
				runtime->localTxBuffer.buffer[3] = *pDTC++;
				runtime->localTxBuffer.buffer[4] = *pDTC;
				runtime->localTxBuffer.buffer[5] = 0xff;
				runtime->localTxBuffer.PduInfo.SduLength = 6;
			}
			runtime->localTxBuffer.PduInfo.SduDataPtr = runtime->localTxBuffer.buffer;
			
			runtime->localTxBuffer.status = DCM_TRANSMIT_SIGNALED; // In the DslProvideTxBuffer 'callback' this state signals it is the local buffer we are interested in sending.
			transmitResult = CanTp_Transmit(connection->DslMainConnection->DslProtocolTx->DcmDslProtocolTxPduId, &(runtime->localTxBuffer.PduInfo));/** @req DCM115.Partially */ 
            //if (transmitResult != E_OK) {
            	OS_Sleep(40);
			    releaseExternalRxTxBuffersHelper(ecu_id);
			    runtime->localRxBuffer.status = NOT_IN_USE;
			    runtime->localTxBuffer.status = NOT_IN_USE;
			    
				//return transmitResult;
            //}
		}
	}
	return transmitResult;
}


void extern_releaseExternalRxTxBuffers()
{
    const Dcm_DslProtocolRowType         *protocolRowEntry;
    Dcm_DslRunTimeProtocolParametersType *runtime = NULL;
	//Can_UnitType *uPtr = CTRL_TO_UNIT_PTR(1);

    protocolRowEntry = Dcm_ConfigPtr->Dsl->DslProtocol->DslProtocolRowList;
    runtime = protocolRowEntry->DslRunTimeProtocolParameters;
	
	releaseExternalRxTxBuffers(protocolRowEntry, runtime);
	//DslInit();
}

