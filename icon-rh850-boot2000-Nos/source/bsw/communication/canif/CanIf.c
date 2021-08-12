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

/*----------------------------[information]----------------------------------
 * Author: mahi/hebe
 *
 * Part of Release:
 *   4.0.3
 *
 * Description:
 *   Implements the Can Interface
 *
 * Support:
 *   Private                  Have Support
 *   ---------------------------------------------------------------
 *   CANIF_[PRIVATE_]DLC_CHECK 					Y		4.0.3
 *   CANIF_[PRIVATE_]SOFTWARE_FILTER_TYPE 		N		4.0.3
 *   CANIF_NUMBER_OF_TXBUFFERS  				N		3.1.5
 *   CANIF_PRIVATE_SUPPORT_TTCAN				N       4.0.3
 *
 *
 *   Public                  Have Support
 *   ----------------------------------------------------------------
 *   CANIF_[PUBLIC_]DEV_ERROR_DETECT			Y		4.0.3
 *   CANIF_[PUBLIC_]MULTIPLE_DRIVER_SUPPORT		N		4.0.3
 *   CANIF_[PUBLIC_]NUMBER_OF_CAN_HW_UNITS		N		3.1.5
 *   CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT		N		4.0.3
 *   CANIF_[PUBLIC_]READRXPDU_DATA_API			N		4.0.3
 *   CANIF_[PUBLIC_]READRXPDU_NOTIF_STATUS_API	N		4.0.3
 *   CANIF_[PUBLIC_]READTXPDU_NOTIF_STATUS_API	N		4.0.3
 *   CANIF_[PUBLIC_]SETDYNAMICTXID_API			N		4.0.3
 *   CANIF_[PUBLIC_]VERSION_INFO_API			Y		4.0.3
 *
 *   CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT		N		4.0.3
 *   CANIF_PUBLIC_CDD_HEADERFILE				N		4.0.3
 *   CANIF_PUBLIC_HANDLE_TYPE_ENUM				N 		4.0.3
 *   CANIF_PUBLIC_TX_BUFFERING					Y 		4.0.3
 *   CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API   N 		4.0.3
 *   CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM	    N 		4.0.3
 *
 * Implementation Notes:
 *   Channels:
 *      The specification speaks a lot of channels and it's sometimes confusing
 *      This implementations interpretation is:
 *      - Physical Channel
 *        One physical channel is connected to one CAN controller and one CAN
 *        transceiver. One or more physical channels may be connected to a single
 *        network (the physical CAN network)
 *
 *                physical channel      physical channel
 *                       |                     |
 *                     CAN_B                  CAN_D
 *                       |                     |
 *                       +       NETWORK       +
 *
 *
 *       Since the CAN controller Id is logical controller Id (e.g. id=0 is CAN_C) channel
 *       is equal to controllerId in the implementation.
 *
 *    Drivers:
 *      There is only support for one driver and that is the on-chip CAN.
 *
 *    Configuration:
 *      3.1.5 CANIF_NUMBER_OF_TXBUFFERS is defined to be the same as for 4.x, ie
 *      only have 1 buffer for each L-PDU. In 3.1.5 this was setable.
 *
 *
 *
 */
/* ----------------------------[includes]------------------------------------*/
#include "Std_Types.h"
#include "CanIf.h"
#include "..\include\generic\Cpu.h"
#include <string.h>
#include <assert.h>
#if  ( CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif
#if defined(USE_DEM)
/* @req 4.0.3/CANIF150 */
#include "Dem.h"
#endif


/* ----------------------------[Version check]------------------------------*/
#if !(((CANIF_SW_MAJOR_VERSION == 4) && (CANIF_SW_MINOR_VERSION == 0)) )
#error CanIf: Expected BSW module version to be 4.0.*
#endif

/* @req 4.0.3/CANIF021 */
#if !(((CANIF_AR_RELEASE_MAJOR_VERSION == 4) && (CANIF_AR_RELEASE_MINOR_VERSION == 0)) )
#error CanIf: Expected AUTOSAR version to be 4.0.*
#endif
/* ----------------------------[Config check]------------------------------*/
#if (CANIF_CTRLDRV_TX_CANCELLATION == STD_ON) && (CANIF_PUBLIC_TX_BUFFERING == STD_OFF)
#error CanIf: Tx cancellation cannot be enabled without enabling tx buffering
#endif
/* ----------------------------[private define]------------------------------*/

/* IMPROVMENT: Move to config */

#define EXTENDED_CANID_MAX 0x1FFFFFFF
#define STANDARD_CANID_MAX 0x7FF
#define EXT_ID_BIT_POS 31
#define EXT_ID_STD_ID_START_BIT 18
#define INVALID_CANID 0xFFFFFFFF

#define FEATURE_NOT_SUPPORTED 0
/* ----------------------------[private macro]-------------------------------*/
#if  ( CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON )
/* @req 4.0.3/CANIF018 */
/* @req 4.0.3/CANIF019 */
/* @req 4.0.3/CANIF156 */
#define DET_REPORT_ERROR(_api, _error)                   \
    do {                                                  \
        (void)Det_ReportError(MODULE_ID_CANIF, 0, _api, _error); \
    } while(0)


#else
#define DET_REPORT_ERROR(_api,_err)
#endif

/* @req 4.0.3/CANIF155 */
#if  defined( USE_DEM )
/* @req 4.0.3/CANIF020*/
#define DEM_REPORT_ERROR_STATUS(_event,_eventstatus) Dem_ReportErrorStatus(_event,_eventstatus);
#else
#define DEM_REPORT_ERROR_STATUS(_event,_eventstatus)
#endif
#define IS_EXTENDED_CAN_ID(_x) (0 != (_x & (1ul<<EXT_ID_BIT_POS)))

#define VALIDATE_NO_RV(_exp,_api,_err ) \
  if( !(_exp) ) { \
      DET_REPORT_ERROR(_api, _err); \
      return; \
  }

#define VALIDATE_RV(_exp,_api,_err,_ret ) \
  if( !(_exp) ) { \
      DET_REPORT_ERROR(_api, _err); \
      return (_ret); \
  }

#define IS_VALID_CONTROLLER_MODE(_x) \
        ((CANIF_CS_STARTED == (_x)) || \
        (CANIF_CS_SLEEP == (_x)) || \
        (CANIF_CS_STOPPED == (_x)))

// Helper to get the Can Controller refered to by a CanIf Channel
/* IMPROVMENT: Could we handle this in another way?
 *  */
#define ARC_GET_CHANNEL_CONTROLLER(_channel) \
	CanIf_ConfigPtr->Arc_ChannelConfig[_channel].CanControllerId
/* ----------------------------[private typedef]-----------------------------*/

typedef void (*RxIndicationCbType)(PduIdType , const PduInfoType*);





 


typedef struct  {
	PduIdType pduId;
	Can_IdType canId;
	uint8_t	  data[8];
	uint8_t 	  dlc;
} CanIf_LPduType;

#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
typedef struct {
	/**/
    CanIf_LPduType lPdu;
	boolean inUse;
}CanIf_Arc_BufferEntryType;

static CanIf_Arc_BufferEntryType TxPduBuffer[CANIF_ARC_MAX_NUM_LPDU_TX_BUF];
#endif

/* ----------------------------[private function prototypes]-----------------*/
/* ----------------------------[private variables]---------------------------*/
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
/* Mapping from buffer index to start index in the L-PDU buffer */
static uint16_t BufferStartIndex[CANIF_ARC_MAX_NOF_TX_BUFFERS];
#endif

//boolean CanIf_Global;
CanIf_GlobalType CanIf_Global;

/* Global configure */
//static 
const CanIf_ConfigType *CanIf_ConfigPtr;

#if ( CANIF_PUBLIC_READRXPDU_DATA_API == STD_ON ) && FEATURE_NOT_SUPPORTED
static CanIf_LPduType RxBuffer[CANIF_NUM_RX_LPDU];
#endif
#if ( CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API == STD_ON ) && FEATURE_NOT_SUPPORTED
/* !req:READTXNOTIFSTATUS 4.0.3/CANIF472 */
CanIf_NotifStatusType TxNotifStatusBuffer[CANIF_NUM_RX_LPDU];
#endif

#if ( CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API == STD_ON ) && FEATURE_NOT_SUPPORTED
/* !req:READRXNOTIFSTATUS 4.0.3/CANIF473 */
CanIf_NotifStatusType RxNotifStatusBuffer[CANIF_NUM_TX_LPDU];
#endif


/* Declared in Can_Cfg.c */
extern const CanIfUserRxIndicationType CanIfUserRxIndications[];
extern const CanIfUserTxConfirmationType CanIfUserTxConfirmations[];
extern const CanIf_DispatchConfigType CanIfDispatchConfig;


/* ----------------------------[private functions]---------------------------*/
/* ----------------------------[public functions]----------------------------*/

/* IMPROVMENT: Generator changes
 *
 * - CanIfUserRxIndication should be set according to it's type, e.g
 *    CanNm_RxIndication, PduR_CanIfRxIndication, CanTp_RxIndication, J1939Tp_RxIndication
 *    What to do with "special"?
 * -  The number of PDU's should be generated to CANIF_NUM_TX_LPDU
 *
 *
 *
 * */


#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
static Std_ReturnType qReplaceOrAdd(const CanIf_TxBufferConfigType *bufferPtr, Can_PduType *canPduPtr, boolean replaceAllowed)
{
    /* !req CANIF033 */

    boolean found = FALSE;
    Std_ReturnType ret = E_NOT_OK;
    CanIf_Arc_BufferEntryType *buffPtr = NULL;
    uint16_t startIndex;
    imask_t state;
    uint16_t i;
    
    Irq_Save(state);
    startIndex = BufferStartIndex[bufferPtr->CanIf_Arc_BufferId];
    for( i = startIndex; (i < (startIndex + bufferPtr->CanIfBufferSize)) && (!found); i++) {

        if( TxPduBuffer[i].inUse && (TxPduBuffer[i].lPdu.pduId == canPduPtr->swPduHandle) ) {
            /* This pdu was already stored. Replace if allowed. */
            /* @req CANIF068 */
            if( replaceAllowed ) {
                buffPtr = &TxPduBuffer[i];
            } else {
                buffPtr = NULL;
            }
            found = TRUE;
        } else if( !TxPduBuffer[i].inUse && (NULL == buffPtr)) {
            /* Not used. */
            /* @req CANIF836 */
            buffPtr = &TxPduBuffer[i];
        }
    }

    if( NULL != buffPtr ) {
        /* Found an entry to use */
        buffPtr->inUse = TRUE;
        buffPtr->lPdu.dlc = canPduPtr->length;
        buffPtr->lPdu.canId = canPduPtr->id;
        buffPtr->lPdu.pduId = canPduPtr->swPduHandle;
        memcpy(buffPtr->lPdu.data, canPduPtr->sdu, canPduPtr->length);
        ret = E_OK;
    } else {
        /* @req CANIF837 */
    }

    Irq_Restore(state);
    return ret;
}

static void qRemove(const CanIf_TxBufferConfigType *bufferPtr, Can_IdType canId) {
	/* Remove entry matching canId from buffer corresponding to bufferPtr */
	boolean found = FALSE;
	uint16_t startIndex;
	imask_t state;
	uint16_t i;
	
	Irq_Save(state);
	startIndex = BufferStartIndex[bufferPtr->CanIf_Arc_BufferId];
	for( i = startIndex; (i < (startIndex + bufferPtr->CanIfBufferSize)) && (!found); i++) {
		if( TxPduBuffer[i].inUse && (TxPduBuffer[i].lPdu.canId == canId)) {
			TxPduBuffer[i].inUse = FALSE;
			found = TRUE;
		}
	}
	Irq_Restore(state);
}

static Std_ReturnType qGetBufferedPdu(const CanIf_TxBufferConfigType *bufferPtr, Can_PduType *canPduPtr)
{
    /* Search through the buffer and find the highest prioritized entry */
    boolean found = FALSE;
    uint16_t startIndex;
    Can_IdType highestPrioCanId = INVALID_CANID;
    boolean highestPrioIsExt = TRUE;
    Can_IdType canId = 0;
    imask_t state;
    //int i;
    uint16_t i;
    
    Irq_Save(state);
    startIndex = BufferStartIndex[bufferPtr->CanIf_Arc_BufferId];
    for( i = startIndex; i < (startIndex + bufferPtr->CanIfBufferSize); i++) {
        if( TxPduBuffer[i].inUse) {
            canId = TxPduBuffer[i].lPdu.canId;
            if( (canId & (1ul<<EXT_ID_BIT_POS)) != (highestPrioCanId & (1ul<<EXT_ID_BIT_POS))) {
                /* One id is extended and the other standard */
                if( highestPrioIsExt ) {
                    /* The currently highest prioritized canid is extended. Modify the
                     * standard id to a corresponding extended */
                    canId = ((canId<<EXT_ID_STD_ID_START_BIT) & EXTENDED_CANID_MAX) | (1ul<<EXT_ID_BIT_POS);
                } else {
                    /* The currently highest prioritized canid is standard. Modify the
                     * extended id to a corresponding standard */
                    canId = (canId>>EXT_ID_STD_ID_START_BIT) & STANDARD_CANID_MAX;
                }
            }
            if( (highestPrioCanId > canId) || (highestPrioIsExt && (highestPrioCanId == canId)) ) {
                /* Priority higher. */
                canPduPtr->id = TxPduBuffer[i].lPdu.canId;
                canPduPtr->length = TxPduBuffer[i].lPdu.dlc;
                canPduPtr->swPduHandle = TxPduBuffer[i].lPdu.pduId;
                canPduPtr->sdu = TxPduBuffer[i].lPdu.data;
                highestPrioCanId = TxPduBuffer[i].lPdu.canId;
                highestPrioIsExt = (0 != (TxPduBuffer[i].lPdu.canId & (1ul<<EXT_ID_BIT_POS)));
                found = TRUE;
            }
        }
    }
    Irq_Restore(state);
    if( found ) {
        return E_OK;
    } else {
        return E_NOT_OK;
    }
}
static void qClear(const CanIf_TxBufferConfigType *bufferPtr) {
    uint16_t startIndex;
	imask_t state;
	uint16_t i;
	
	Irq_Save(state);
	startIndex = BufferStartIndex[bufferPtr->CanIf_Arc_BufferId];
	for( i = startIndex; i < (startIndex + bufferPtr->CanIfBufferSize); i++ ) {
        TxPduBuffer[i].inUse = FALSE;
	}
	Irq_Restore(state);
}
#endif

#if !defined(CFG_CAN_USE_SYMBOLIC_CANIF_CONTROLLER_ID)
static Std_ReturnType ControllerToChannel( uint8_t controllerId, CanIf_Arc_ChannelIdType *channel )
{
	Std_ReturnType ret = E_NOT_OK;
	int i;
	
	if( NULL != channel ) {
		for(i = 0; i < CANIF_CHANNEL_CNT; i++) {
			if(CanIf_ConfigPtr->Arc_ChannelConfig[i].CanControllerId == controllerId) {
				*channel = (CanIf_Arc_ChannelIdType)i;
				ret = E_OK;
			}
		}
	}
	return ret;
}
#endif
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
static void ClearTxBuffers( uint8_t channelId )
{
	uint8_t i ;
	const CanIf_Arc_ChannelConfigType channelConfigPtr = CanIf_ConfigPtr->Arc_ChannelConfig[channelId];
    for( i = 0; i < channelConfigPtr.NofTxBuffers; i++ ) {
        qClear(channelConfigPtr.TxBufferRefList[i]);
    }
}
#endif

#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
static void ChannelOnEnterPDUMode( uint8_t channelId, CanIf_PduSetModeType pduMode )
{
    switch(pduMode) {
        case CANIF_SET_OFFLINE:/* @req CANIF073 */
        case CANIF_SET_TX_OFFLINE:/* @req CANIF489 */
            ClearTxBuffers(channelId);
            break;
        default:
            break;

    }

}

static void ChannelOnEnterControllerMode( CanIf_Arc_ChannelIdType channelId, CanIf_ControllerModeType controllerMode )
{

    if(CANIF_CS_STOPPED == controllerMode) {
        /* @req CANIF485 */
        ClearTxBuffers((uint8_t)channelId);

    }
}
#endif
/**
 *
 * @param ConfigPtr
 */
/* @req 4.0.3/CANIF001 */
void CanIf_Init(const CanIf_ConfigType *configPtr) {

    /* @req 4.0.3/CANIF085 */ //buffers and flags must be cleared when support is added
    /* !req:WAKEUP 4.0.3/CANIF479 */ //CCMSM enters CANIF_CS_INIT -> clear stored wakeup events
    /* !req 4.0.3/CANIF301 */

    /* @req 4.0.3/CANIF302 */
    // Only PostBuild case supported
	uint8_t channel ;
	uint8_t i;
	uint16_t indx;
	uint16_t bufIndex;
	
    VALIDATE_NO_RV((NULL != configPtr),CANIF_INIT_ID, CANIF_E_PARAM_POINTER);

    CanIf_ConfigPtr = configPtr;

    /* @req 4.0.3/CANIF476 */
    /* @req 4.0.3/CANIF477 */
    /* @req 4.0.3/CANIF478 */
    /* These all cooks down to controller mode CANIF_CS_STOPPED */
    for (channel = 0; channel < CANIF_CHANNEL_CNT; channel++) {
        CanIf_Global.channelData[channel].ControllerMode = CANIF_CS_STOPPED;
//      ControllerOnEnterMode(channel, CANIF_CS_STOPPED);
        /* No req but still.. : PDU mode to OFFLINE */
        CanIf_Global.channelData[channel].can_err = false;
        CanIf_Global.channelData[channel].PduMode = CANIF_GET_OFFLINE;

#if (CANIF_PUBLIC_PN_SUPPORT == STD_ON) && FEATURE_NOT_SUPPORTED
        CanIf_Global.channelData[channel].PnTxFilterEnabled = FALSE; // IMPROVEMENT: Add requirement tag
#endif

    }

#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
    /* Clear tx buffer */
    /* @req CANIF387 */
    for(  i = 0; (i < CANIF_ARC_MAX_NUM_LPDU_TX_BUF); i++) {
        TxPduBuffer[i].inUse = FALSE;
    }
    /* Setup mapping from buffer index to start index in L_PDU buffer */
    indx = 0;
    for( bufIndex = 0; bufIndex < CanIf_ConfigPtr->InitConfig->CanIfNumberOfTxBuffers; bufIndex++ ) {
        BufferStartIndex[CanIf_ConfigPtr->InitConfig->CanIfBufferCfgPtr[bufIndex].CanIf_Arc_BufferId] = indx;
        indx += CanIf_ConfigPtr->InitConfig->CanIfBufferCfgPtr[bufIndex].CanIfBufferSize;//+=2
    }
#endif

    CanIf_Global.initRun = TRUE;
}

/* @req 4.0.3/CANIF699 */
void CanIf_ControllerModeIndication(uint8_t ControllerId,
		   CanIf_ControllerModeType ControllerMode)
{
	/* !req:WAKEUP 4.0.3/CANIF479 */

	/* @req 4.0.3/CANIF702 */
    /* @req 4.0.3/CANIF661 */
	CanIf_Arc_ChannelIdType channel;
	
    VALIDATE_NO_RV((TRUE == CanIf_Global.initRun), CANIF_CONTROLLER_MODE_INDICATION_ID, CANIF_E_UNINIT);

	/* NOTE: Should we have this check? */
    VALIDATE_NO_RV(IS_VALID_CONTROLLER_MODE(ControllerMode), CANIF_CONTROLLER_MODE_INDICATION_ID, CANIF_E_PARAM_CTRLMODE);

	
#if defined(CFG_CAN_USE_SYMBOLIC_CANIF_CONTROLLER_ID)
	VALIDATE_NO_RV((ControllerId < CANIF_CHANNEL_CNT), CANIF_CONTROLLER_MODE_INDICATION_ID, CANIF_E_PARAM_CONTROLLER);
	channel = (CanIf_Arc_ChannelIdType)ControllerId;
#else
	if(E_OK != ControllerToChannel(ControllerId, &channel)) {
	    /* @req 4.0.3/CANIF700 */
		DET_REPORT_ERROR(CANIF_CONTROLLER_MODE_INDICATION_ID, CANIF_E_PARAM_CONTROLLER);
		return;
	}
#endif
	/* In AUTOSAR 4.0.3 CanIf specification, all mode transitions between the states
	 * CANIF_CS_STARTED, CANIF_CS_SLEEP and CANIF_CS_STOPPED have requirements
	 * except between CANIF_CS_STARTED and CANIF_CS_SLEEP. These are invalid transitions.
	 * CANIF474 says "The CAN Interface module shall not contain any complete controller
	 * state machine. Therefore we leave it up to the CAN driver not to command these
	 * transitions. We just set the controller mode to the mode indicated by the CAN driver. */
	/* @req 4.0.3/CANIF713 */
	/* @req 4.0.3/CANIF714 */
	/* @req 4.0.3/CANIF715 */
	/* @req 4.0.3/CANIF716 */
	/* @req 4.0.3/CANIF717 */
	/* @req 4.0.3/CANIF718 */
	/* @req 4.0.3/CANIF719 */
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
	/* @req CANIF485 */
	ChannelOnEnterControllerMode(channel, ControllerMode);
#endif
	if( NULL != CanIfDispatchConfig.CanIfControllerModeIndication ) {
		/* @req 4.0.3/CANIF687 */
		/* @req 4.0.3/CANIF711 */
		CanIfDispatchConfig.CanIfControllerModeIndication(channel, ControllerMode);
	}

	CanIf_Global.channelData[channel].ControllerMode = ControllerMode;

}

/* @req 4.0.3/CANIF003 */
Std_ReturnType CanIf_SetControllerMode(uint8_t ControllerId, CanIf_ControllerModeType ControllerMode)
{
	/* !req 4.0.3/CANIF312 */

	CanIf_ControllerModeType currMode;
	CanControllerIdType canControllerId = ARC_GET_CHANNEL_CONTROLLER(ControllerId);
	Can_StateTransitionType canTransition = CAN_T_START;
	Std_ReturnType ret = E_OK;

	/* @req 4.0.3/CANIF661 */
	VALIDATE_RV((TRUE == CanIf_Global.initRun), CANIF_SET_CONTROLLER_MODE_ID, CANIF_E_UNINIT, E_NOT_OK);
	/* @req 4.0.3/CANIF311 */
	VALIDATE_RV((ControllerId < CANIF_CHANNEL_CNT), CANIF_SET_CONTROLLER_MODE_ID, CANIF_E_PARAM_CONTROLLERID, E_NOT_OK);
	/* @req 4.0.3/CANIF774 */
	VALIDATE_RV(IS_VALID_CONTROLLER_MODE(ControllerMode), CANIF_SET_CONTROLLER_MODE_ID, CANIF_E_PARAM_CTRLMODE, E_NOT_OK);

	
	currMode = CanIf_Global.channelData[ControllerId].ControllerMode;
	/* @req 4.0.3/CANIF474 */


	switch(ControllerMode) {
	case CANIF_CS_STOPPED:
		if(CANIF_CS_SLEEP == currMode) {
			/* @req 4.0.3/CANIF487 */
			canTransition = CAN_T_WAKEUP;
		} else {
			/* @req 4.0.3/CANIF480 */
			/* @req 4.0.3/CANIF585 */
			canTransition = CAN_T_STOP;
		}
		break;
	case CANIF_CS_STARTED:
		/* @req 4.0.3/CANIF481 */
		/* @req 4.0.3/CANIF584 */
		/* Invalid transition if current mode is CANIF_CS_SLEEP.
		 * CAN411 in CanDrv spec. says that "when the function Can_SetControllerMode( CAN_T_SLEEP )
		 * is entered and the CAN controller is neither in state STOPPED nor in state SLEEP,
		 * it shall detect an invalid state transition".
		 * Let CAN driver detect invalid state transition. */
		canTransition = CAN_T_START;
		break;
	case CANIF_CS_SLEEP:
		/* @req 4.0.3/CANIF482 */
		/* @req 4.0.3/CANIF486 */
		/* Invalid transition if current mode is CANIF_CS_STARTED.
		 * CAN411 in CanDrv spec. says that "when the function Can_SetControllerMode( CAN_T_SLEEP )
		 * is entered and the CAN controller is neither in state STOPPED nor in state SLEEP,
		 * it shall detect an invalid state transition".
		 * Let CAN driver detect invalid state transition. */
		canTransition = CAN_T_SLEEP;
		break;
	default:
		ret = E_NOT_OK;
		break;
	}
	if(E_OK == ret) {
		/* Forward transition and let the CAN driver detect invalid transition. */
		/* @req 4.0.3/CANIF308 */
		if(CAN_NOT_OK == Can_SetControllerMode( canControllerId, canTransition )) {
			/* @req 4.0.3/CANIF475 */
			ret = E_NOT_OK;
		}
	}

	return ret;
}

/* @req 4.0.3/CANIF229 */
Std_ReturnType CanIf_GetControllerMode(uint8_t ControllerId,
		CanIf_ControllerModeType *ControllerModePtr) {

	/* !req 4.0.3/CANIF316 */

	/* @req 4.0.3/CANIF661 */
    VALIDATE_RV((TRUE == CanIf_Global.initRun), CANIF_GET_CONTROLLER_MODE_ID, CANIF_E_UNINIT, E_NOT_OK);
	/* @req 4.0.3/CANIF313 */
    VALIDATE_RV((ControllerId < CANIF_CHANNEL_CNT), CANIF_GET_CONTROLLER_MODE_ID, CANIF_E_PARAM_CONTROLLERID, E_NOT_OK);
	/* @req 4.0.3/CANIF656 */
    VALIDATE_RV((NULL != ControllerModePtr), CANIF_GET_CONTROLLER_MODE_ID, CANIF_E_PARAM_POINTER, E_NOT_OK);

	/* @req 4.0.3/CANIF541 */
	*ControllerModePtr = CanIf_Global.channelData[ControllerId].ControllerMode;

	return E_OK;
}
/**
 *
 * @param canTxPduId
 * @param pduInfoPtr
 * @return
 */
/* @req 4.0.3/CANIF005 */
Std_ReturnType CanIf_Transmit(PduIdType CanTxPduId,
        const PduInfoType *PduInfoPtr) {

    Can_PduType canPdu;
    Can_ReturnType writeRet;
    Std_ReturnType ret = E_OK;
    const CanIf_TxPduConfigType *txPduPtr;
    uint8_t controller;


    VALIDATE_RV((TRUE == CanIf_Global.initRun), CANIF_TRANSMIT_ID, CANIF_E_UNINIT, E_NOT_OK);
    VALIDATE_RV((NULL != PduInfoPtr), CANIF_TRANSMIT_ID, CANIF_E_PARAM_POINTER, E_NOT_OK);
    VALIDATE_RV((CanTxPduId < CanIf_ConfigPtr->InitConfig->CanIfNumberOfCanTXPduIds), CANIF_TRANSMIT_ID, CANIF_E_INVALID_TXPDUID, E_NOT_OK);

    txPduPtr = &CanIf_ConfigPtr->InitConfig->CanIfTxPduConfigPtr[CanTxPduId];

    controller = (uint8_t)txPduPtr->CanIfTxPduBufferRef->CanIfBufferHthRef->CanIfCanControllerIdRef;
#if 0 //Just for test
    if (CanIf_Global.channelData[controller].can_err)
		return E_NOT_OK;
    if( CANIF_GET_OFFLINE == CanIf_Global.channelData[controller].PduMode || CANIF_GET_RX_ONLINE == CanIf_Global.channelData[controller].PduMode ) {
        DET_REPORT_ERROR(CANIF_TRANSMIT_ID, CANIF_E_STOPPED);
        return E_NOT_OK;
    }

    if( CANIF_CS_STOPPED == CanIf_Global.channelData[controller].ControllerMode ) {
        DET_REPORT_ERROR(CANIF_TRANSMIT_ID, CANIF_E_STOPPED);
        return E_NOT_OK;
    }

    if( (CANIF_CS_STARTED != CanIf_Global.channelData[controller].ControllerMode) ||
        (CANIF_GET_RX_ONLINE == CanIf_Global.channelData[controller].PduMode) ||
            (CANIF_GET_OFFLINE == CanIf_Global.channelData[controller].PduMode) ) {
        return E_NOT_OK;
    }
#endif
#if (CANIF_PUBLIC_PN_SUPPORT == STD_ON) && FEATURE_NOT_SUPPORTED
    if( CanIf_Global.channelData[controller].PnTxFilterEnabled && !txPduPtr->IsPnFilterPdu) {
        return E_NOT_OK;
    }
#endif

    if( (CANIF_GET_OFFLINE_ACTIVE == CanIf_Global.channelData[controller].PduMode) ||
            (CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE == CanIf_Global.channelData[controller].PduMode) ) {
        if((NO_FUNCTION_CALLOUT != txPduPtr->CanIfUserTxConfirmation) &&
            (CanIfUserTxConfirmations[txPduPtr->CanIfUserTxConfirmation] != NULL)){
            CanIfUserTxConfirmations[txPduPtr->CanIfUserTxConfirmation](txPduPtr->CanIfTxPduId);
        }
        return E_OK;
    }

    canPdu.id = txPduPtr->CanIfCanTxPduIdCanId; /* @req 4.0.3/CANIF243 */
    if( CANIF_CAN_ID_TYPE_29 == txPduPtr->CanIfTxPduIdCanIdType ) {
        canPdu.id |= (1ul << EXT_ID_BIT_POS);
    }
    canPdu.length = txPduPtr->CanIfCanTxPduIdDlc;
    canPdu.sdu = PduInfoPtr->SduDataPtr;
    canPdu.swPduHandle = CanTxPduId;

    writeRet = Can_Write(txPduPtr->CanIfTxPduBufferRef->CanIfBufferHthRef->CanIfHthIdSymRef, &canPdu);
    if( CAN_BUSY == writeRet ) {
        ret = E_NOT_OK;

#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
        if( (0 != txPduPtr->CanIfTxPduBufferRef->CanIfBufferSize) &&
            (CAN_ARC_HANDLE_TYPE_BASIC == txPduPtr->CanIfTxPduBufferRef->CanIfBufferHthRef->CanIfHthType) ) {
            ret = qReplaceOrAdd(txPduPtr->CanIfTxPduBufferRef, &canPdu, TRUE);
        }
#endif

    } else if( CAN_NOT_OK == writeRet ) {
        ret = E_NOT_OK;/* Nothing to do. Throw message */
    }else if( CAN_OK == writeRet ) {
        ret = E_OK; /* @req 4.0.3/CANIF162 */
    }
    return ret;
}

/* @req 4.0.3/CANIF007 */
void CanIf_TxConfirmation(PduIdType canTxPduId) {
    const CanIf_TxPduConfigType *txPduPtr;
    CanIf_PduGetModeType mode;

    /* !req 4.0.3/CANIF413 */
    /* !req 4.0.3/CANIF414 */
    /* !req CANIF058 */

    /* @req 4.0.3/CANIF412 */
    /* @req 4.0.3/CANIF661 */
    VALIDATE_NO_RV((TRUE == CanIf_Global.initRun), CANIF_TXCONFIRMATION_ID, CANIF_E_UNINIT);
    /* @req 4.0.3/CANIF410 */
    VALIDATE_NO_RV((canTxPduId < CanIf_ConfigPtr->InitConfig->CanIfNumberOfCanTXPduIds), CANIF_TXCONFIRMATION_ID, CANIF_E_PARAM_LPDU);

    txPduPtr = &CanIf_ConfigPtr->InitConfig->CanIfTxPduConfigPtr[canTxPduId];

#if (CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT == STD_ON)
    /* !req:TXCONFPOLL 4.0.3/CANIF740 */
#endif

#if (CANIF_PUBLIC_PN_SUPPORT == STD_ON) && FEATURE_NOT_SUPPORTED
    /* !req:PN 4.0.3/CANIF751*/
    CanIf_Global.channelData[ControllerId].PnTxFilterEnabled = FALSE;
#endif

    
    if( E_OK != CanIf_GetPduMode(txPduPtr->CanIfTxPduBufferRef->CanIfBufferHthRef->CanIfCanControllerIdRef, &mode) ) {
        /* No pdu mode. return */
        return;
    }
    /* @req 4.0.3/CANIF489*/
    /* @req 4.0.3/CANIF491 Part of */
    /* @req 4.0.3/CANIF075 */
    if ((mode == CANIF_GET_TX_ONLINE) || (mode == CANIF_GET_ONLINE) ||
            (mode == CANIF_GET_OFFLINE_ACTIVE) || (mode == CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE) )
    {

#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
        if((mode == CANIF_GET_TX_ONLINE) || (mode == CANIF_GET_ONLINE) ) {
            Can_PduType canPdu;
            /* @req CANIF386 */ //Evaluate if there are pending pdus in buffers, assigned to the new free hth
            if(E_OK == qGetBufferedPdu(txPduPtr->CanIfTxPduBufferRef, &canPdu)) {
                /* Was something in queue. Assume that qGetBufferedPdu returned the pdu
                * with the highest priority */
                /* @req CANIF668 */ //Initiate transmit of the highest prio pdu
                /* @req CANIF070 */ //transmit highest prio pdu
                /* NOTE: Foreach hth referenced? */
                if( E_OK == Can_Write(txPduPtr->CanIfTxPduBufferRef->CanIfBufferHthRef->CanIfHthIdSymRef, &canPdu) ) {
                    /* @req CANIF183 */ //Remove from buffer if E_OK == Can_Write
                    qRemove(txPduPtr->CanIfTxPduBufferRef, canPdu.id);
                }
            }
        }
#endif
#if (CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API == STD_ON) && FEATURE_NOT_SUPPORTED
        /* !req:READTXNOTIFSTATUS 4.0.3/CANIF391 */
#endif

        /* @req 4.0.3/CANIF383 */
        if( (NO_FUNCTION_CALLOUT != txPduPtr->CanIfUserTxConfirmation ) &&
            (CanIfUserTxConfirmations[txPduPtr->CanIfUserTxConfirmation]) != NULL){
            /* @req 4.0.3/CANIF011 */
            CanIfUserTxConfirmations[txPduPtr->CanIfUserTxConfirmation](txPduPtr->CanIfTxPduId);
        }
    }
}

/**
 *
 * @param hrh
 * @param canId
 * @param canDlc
 * @param canSduPtr
 */
/* @req 4.0.3/CANIF006 */
void CanIf_RxIndication(Can_HwHandleType hrh, Can_IdType canId, uint8_t canDlc, const uint8_t *canSduPtr)             
{
	//CanIf_PduGetModeType mode;
	//boolean pduMatch = FALSE;
	//CanIf_Arc_ChannelIdType controllerId ;
      const CanIf_HrhConfigType *hrhConfig;
	//boolean controllerFound = FALSE;
	const CanIf_RxPduConfigType *rxPduCfgPtr;
	//uint16 i;
//	uint8_t CanDummyRead[8];

   // controllerId = CANIF_CHANNEL_CNT;
    hrhConfig = CanIf_ConfigPtr->InitConfig->CanIfHohConfigPtr->CanIfHrhConfig + hrh;
   // controllerId = hrhConfig->CanIfCanControllerHrhIdRef;
   // controllerFound = TRUE;

#if 0 //2017-9-6 20:35:48
	if ( (E_OK != CanIf_GetPduMode(controllerId, &mode)) || (CANIF_GET_OFFLINE == mode) || 
		 (CANIF_GET_TX_ONLINE == mode)|| (CANIF_GET_OFFLINE_ACTIVE == mode) ) 
	{
		// Receiver path is disabled so just drop it
		return;
	}
#endif

	rxPduCfgPtr =  CanIf_ConfigPtr->InitConfig->CanIfRxPduConfigPtr + hrh;

#if (CANIF_PRIVATE_DLC_CHECK == STD_ON)
	if( canDlc < rxPduCfgPtr->CanIfCanRxPduDlc ) 
	{
	//	memcpy(CanDummyRead, canSduPtr, canDlc);
		return;
	}
#endif

	if (( rxPduCfgPtr->CanIfUserRxIndication != NO_FUNCTION_CALLOUT ) &&
		(CanIfUserRxIndications[rxPduCfgPtr->CanIfUserRxIndication] != NULL))
	{
		PduInfoType pduInfo;
		pduInfo.SduLength = canDlc;
		pduInfo.SduDataPtr = (uint8_t *)canSduPtr;  /* throw away const for some reason */
		if( rxPduCfgPtr->CanIfUserRxIndication==0) //nm pdu
		{
			CanIfUserRxIndications[rxPduCfgPtr->CanIfUserRxIndication]((PduIdType)canId, &pduInfo);
		}
		else
		{
			CanIfUserRxIndications[rxPduCfgPtr->CanIfUserRxIndication](rxPduCfgPtr->CanIfCanRxPduId, &pduInfo);
		}
	} 
}


/* !req:CANCELTRANSMIT 4.0.3/CANIF521 */
#if (CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT == STD_ON) && FEATURE_NOT_SUPPORTED
/* !req:CANCELTRANSMIT 4.0.3/CANIF520 */
Std_ReturnType CanIf_CancelTransmit(PduIdType CanTxPduId)
{
    /* !req:CANCELTRANSMIT 4.0.3/CANIF652 */
    return E_OK;
}

#endif

#if (CANIF_CTRLDRV_TX_CANCELLATION == STD_ON)
/* @req CANIF428 */
/* @req CANIF101 */
void CanIf_CancelTxConfirmation(PduIdType canTxPduId,  const PduInfoType *pduInfoPtr)
{
    /* !req CANIF427 */
    /* !req CANIF058 */
    /* @req CANIF426 */
	const CanIf_TxPduConfigType *txPduPtr;
	 CanIf_PduGetModeType mode;
	
    VALIDATE_NO_RV((TRUE == CanIf_Global.initRun), CANIF_CANCELTXCONFIRMATION_ID, CANIF_E_UNINIT);
    /* @req CANIF424 */
    VALIDATE_NO_RV((canTxPduId < CanIf_ConfigPtr->InitConfig->CanIfNumberOfCanTXPduIds), CANIF_CANCELTXCONFIRMATION_ID, CANIF_E_PARAM_LPDU);
    /* @req CANIF828 */
    VALIDATE_NO_RV((NULL != pduInfoPtr), CANIF_CANCELTXCONFIRMATION_ID, CANIF_E_PARAM_POINTER);

#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
    
    txPduPtr = &CanIf_ConfigPtr->InitConfig->CanIfTxPduConfigPtr[canTxPduId];
    mode = CanIf_Global.channelData[txPduPtr->CanIfTxPduBufferRef->CanIfBufferHthRef->CanIfCanControllerIdRef].PduMode;

    if( ((CANIF_GET_TX_ONLINE == mode) || (CANIF_GET_ONLINE == mode)) &&
            (CANIF_CS_STARTED == CanIf_Global.channelData[txPduPtr->CanIfTxPduBufferRef->CanIfBufferHthRef->CanIfCanControllerIdRef].ControllerMode )) {
        Can_PduType canPdu;
        canPdu.length = pduInfoPtr->SduLength;
        canPdu.id = txPduPtr->CanIfCanTxPduIdCanId;
        if( CANIF_CAN_ID_TYPE_29 == txPduPtr->CanIfTxPduIdCanIdType ) {
            canPdu.id |= (1ul << EXT_ID_BIT_POS);
        }
        canPdu.sdu = pduInfoPtr->SduDataPtr;
        canPdu.swPduHandle = canTxPduId;
        /* @req CANIF054 */
        /* @req CANIF176 */
        (void)qReplaceOrAdd( txPduPtr->CanIfTxPduBufferRef, &canPdu, FALSE);
        /* @req CANIF386 */ //Evaluate if there are pending pdus in buffers, assigned to the new free hth
        if(E_OK == qGetBufferedPdu(txPduPtr->CanIfTxPduBufferRef, &canPdu)) {
            /* Was something in queue. Assume that qGetBufferedPdu returned the pdu
             * with the highest priority */
            /* @req CANIF668 */ //Initiate transmit of the highest prio pdu
            /* @req CANIF070 */ //transmit highest prio pdu
            if( E_OK == Can_Write(txPduPtr->CanIfTxPduBufferRef->CanIfBufferHthRef->CanIfHthIdSymRef, &canPdu) ) {
                /* @req CANIF183 */ //Remove from buffer if E_OK == Can_Write
                qRemove(txPduPtr->CanIfTxPduBufferRef, canPdu.id);
                /* IMPROVEMENT: Should we try to insert the cancelled pdu into the buffer if
                 * the attempt above failed due to lack of space? */
            }
        }
    }
#else
    (void)canTxPduId;
    (void)pduInfoPtr;
#endif

}

#endif


/* !req:RXREADDATA 4.0.3/CANIF330 */
#if ( CANIF_PUBLIC_READRXPDU_DATA_API == STD_ON ) && FEATURE_NOT_SUPPORTED

/**
 *
 *
 * @param canRxPduId
 * @param pduInfoPtr
 * @return
 */
/* !req:RXREADDATA 4.0.3/CANIF194*/
Std_ReturnType CanIf_ReadRxPduData(PduIdType canRxPduId,  PduInfoType *pduInfoPtr)
{
	/* !req:RXREADDATA 4.0.3/CANIF324*/
	/* !req:RXREADDATA 4.0.3/CANIF325 */
	/* !req:RXREADDATA 4.0.3/CANIF329 */
	/* !req CANIF058 */

	VALIDATE(FALSE, CANIF_READTXPDUDATA_ID, CANIF_E_NOK_NOSUPPORT);
	//Requirement 661
	VALIDATE(CanIf_Global.initRun == STD_ON, CANIF_READTXPDUDATA_ID, CANIF_E_UNINIT );
	/* !req:RXREADDATA 4.0.3/CANIF326 */
	VALIDATE(pduInfoPtr != 0, CANIF_READTXPDUDATA_ID, CANIF_E_PARAM_POINTER );

	/* IMPROVMENT: Do it?
	 * This API is actually not used by any upper layers
	 */


  return E_NOT_OK;
}
#endif


/* !req:READTXNOTIFSTATUS 4.0.3/CANIF335 */
#if ( CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API == STD_ON ) && FEATURE_NOT_SUPPORTED
/* !req:READTXNOTIFSTATUS 4.0.3/CANIF202 */
CanIf_NotifStatusType CanIf_ReadTxNotifStatus(PduIdType CanTxPduId)
{
	/* !req:READTXNOTIFSTATUS 4.0.3/CANIF331 */
	/* !req:READTXNOTIFSTATUS 4.0.3/CANIF334 */
	/* !req:READTXNOTIFSTATUS 4.0.3/CANIF393 */
	return CANIF_NO_NOTIFICATION;
}
#endif
/* !req:READRXNOTIFSTATUS 4.0.3/CANIF340 */
#if ( CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API == STD_ON ) && FEATURE_NOT_SUPPORTED
/* !req:READRXNOTIFSTATUS 4.0.3/CANIF230 */
CanIf_NotifStatusType CanIf_ReadRxNotifStatus(PduIdType CanRxPduId)
{
	/* !req:READRXNOTIFSTATUS 4.0.3/CANIF336 */
	/* !req:READRXNOTIFSTATUS 4.0.3/CANIF339 */
	/* !req:READRXNOTIFSTATUS 4.0.3/CANIF394 */
	return CANIF_NO_NOTIFICATION;
}
#endif



/* @req 4.0.3/CANIF008 */
Std_ReturnType CanIf_SetPduMode( uint8_t ControllerId, CanIf_PduSetModeType PduModeRequest )
{
	/* !req 4.0.3/CANIF344*/

	/* NOTE: The channel id is used and not the controller */
	Std_ReturnType ret = E_OK;
	CanIf_PduGetModeType currMode;
	CanIf_PduGetModeType newMode;

	/* @req 4.0.3/CANIF661 */
	VALIDATE_RV((TRUE == CanIf_Global.initRun), CANIF_SETPDUMODE_ID, CANIF_E_UNINIT, E_NOT_OK);
	/* @req 4.0.3/CANIF341*/
	VALIDATE_RV((ControllerId < CANIF_CHANNEL_CNT), CANIF_SETPDUMODE_ID, CANIF_E_PARAM_CONTROLLERID, E_NOT_OK);

	currMode = CanIf_Global.channelData[ControllerId].PduMode;
	newMode = currMode;

	switch(PduModeRequest) {
	case CANIF_SET_OFFLINE:
		newMode = CANIF_GET_OFFLINE;
		break;
	case CANIF_SET_ONLINE:
#if (CANIF_PUBLIC_PN_SUPPORT == STD_ON) && FEATURE_NOT_SUPPORTED
		/* !req:PN 4.0.3/CANIF748*/
		/* !req:PN 4.0.3/CANIF749*/
		if( ControllerHasPnFilterPdus(ControllerId) ) {
			CanIf_Global.channelData[ControllerId].PnTxFilterEnabled = TRUE;
		}
#endif

	    newMode = CANIF_GET_ONLINE;
	    break;
	case CANIF_SET_RX_OFFLINE:
		if( CANIF_GET_ONLINE == currMode ) {
			newMode = CANIF_GET_TX_ONLINE;
		} else if( CANIF_GET_RX_ONLINE == currMode ) {
			newMode = CANIF_GET_OFFLINE;
		} else if( CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE == currMode ) {
			newMode = CANIF_GET_OFFLINE_ACTIVE;
		}
		break;
	case CANIF_SET_RX_ONLINE:
		if(CANIF_GET_TX_ONLINE == currMode ) {
			newMode = CANIF_GET_ONLINE;
		} else if( CANIF_GET_OFFLINE == currMode ) {
			newMode = CANIF_GET_RX_ONLINE;
		} else if( CANIF_GET_OFFLINE_ACTIVE == currMode ) {
			newMode = CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE;
		}
		break;
	case CANIF_SET_TX_OFFLINE:
		if( (CANIF_GET_ONLINE == currMode) || (CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE == currMode) ) {
			newMode = CANIF_GET_RX_ONLINE;
		} else if( (CANIF_GET_TX_ONLINE == currMode) || (CANIF_GET_OFFLINE_ACTIVE == currMode) ) {
			newMode = CANIF_GET_OFFLINE;
		}
		break;
	case CANIF_SET_TX_OFFLINE_ACTIVE:
		if( CANIF_GET_OFFLINE == currMode || CANIF_GET_TX_ONLINE == currMode) {
			newMode = CANIF_GET_OFFLINE_ACTIVE;
		} else if( (CANIF_GET_ONLINE == currMode) || (CANIF_GET_RX_ONLINE == currMode) ) {
			newMode = CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE;
		}
		break;
	case CANIF_SET_TX_ONLINE:
#if (CANIF_PUBLIC_PN_SUPPORT == STD_ON) && FEATURE_NOT_SUPPORTED
		/* !req:PN 4.0.3/CANIF748*/
		/* !req:PN 4.0.3/CANIF749*/
		if( ControllerHasPnFilterPdus(ControllerId) ) {
			CanIf_Global.channelData[ControllerId].PnTxFilterEnabled = TRUE;
		}
#endif

		if( CANIF_GET_OFFLINE == currMode ) {
			newMode = CANIF_GET_TX_ONLINE;
		} else if( (CANIF_GET_RX_ONLINE == currMode) || (CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE == currMode) ) {
			newMode = CANIF_GET_ONLINE;
		} else if (CANIF_GET_OFFLINE_ACTIVE == currMode ) {
			newMode = CANIF_GET_TX_ONLINE;
		}
		break;
	default:
//		DET_REPORT_ERROR(CANIF_SETPDUMODE_ID, CANIF_E_PARAM_PDUMODE);
		ret = E_NOT_OK;
		break;
	}
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
	if(E_OK == ret) {
	    /* ChannelOnEnterPDUMode will tx buffers for this channel and thus obey
	     * parts of the following requirements */
	    /* CANIF073 */
	    /* CANIF489 */
	    ChannelOnEnterPDUMode(ControllerId, PduModeRequest);
	}
#endif
	CanIf_Global.channelData[ControllerId].PduMode = newMode;

	return ret;
}

/* @req 4.0.3/CANIF009 */
Std_ReturnType CanIf_GetPduMode( uint8_t ControllerId, CanIf_PduGetModeType *PduModePtr )
{
	/* !req 4.0.3/CANIF349 */

	/* @req 4.0.3/CANIF661 */
    VALIDATE_RV((TRUE == CanIf_Global.initRun), CANIF_GETPDUMODE_ID, CANIF_E_UNINIT, E_NOT_OK);
	/* @req 4.0.3/CANIF346 */
    VALIDATE_RV((ControllerId < CANIF_CHANNEL_CNT), CANIF_GETPDUMODE_ID, CANIF_E_PARAM_CONTROLLERID, E_NOT_OK);
	/* @req 4.0.3/CANIF657 */
    VALIDATE_RV((NULL != PduModePtr), CANIF_GETPDUMODE_ID, CANIF_E_PARAM_POINTER, E_NOT_OK);

	*PduModePtr = CanIf_Global.channelData[ControllerId].PduMode;

	return E_OK;
}



void CanIf_ControllerError(uint8_t controllerId,Can_Arc_ErrorType err)
{
    if (err.B.TXWRN) {
        CanIf_Global.channelData[controllerId].can_err = true;
        if(NULL != CanIfDispatchConfig.CanIfBusOffNotification) {
            /* @req 4.0.3/CANIF014 */
            CanIfDispatchConfig.CanIfBusOffNotification(controllerId);
        }
    }else {
        CanIf_Global.channelData[controllerId].can_err = false;
    }
}


/* @req 4.0.3/CANIF218 */
void CanIf_ControllerBusOff( uint8_t ControllerId )
{
    CanIf_Arc_ChannelIdType channel;

    /* !req 4.0.3/CANIF432 */
    /* !req 4.0.3/CANIF433 */
    /* @req 4.0.3/CANIF118 */

    /* @req 4.0.3/CANIF661 */
    /* @req 4.0.3/CANIF431 */
    VALIDATE_NO_RV((TRUE == CanIf_Global.initRun), CANIF_CONTROLLER_BUSOFF_ID, CANIF_E_UNINIT);

#if defined(CFG_CAN_USE_SYMBOLIC_CANIF_CONTROLLER_ID)
    VALIDATE_NO_RV((ControllerId < CANIF_CHANNEL_CNT), CANIF_CONTROLLER_BUSOFF_ID, CANIF_E_PARAM_CONTROLLER);
    channel = (CanIf_Arc_ChannelIdType)ControllerId;
#else
    if(E_OK != ControllerToChannel(ControllerId, &channel)) {
        /* @req 4.0.3/CANIF429 */
        DET_REPORT_ERROR(CANIF_CONTROLLER_BUSOFF_ID, CANIF_E_PARAM_CONTROLLER);
        return;
    }
#endif
    /* @req 4.0.3/CANIF298 */
    /* @req 4.0.3/CANIF488 */
    if( CANIF_CS_UNINIT != CanIf_Global.channelData[channel].ControllerMode ) {
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
        ChannelOnEnterControllerMode(channel, CANIF_CS_STOPPED);
#endif
        CanIf_Global.channelData[channel].ControllerMode = CANIF_CS_STOPPED;
    }
#if (CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT == STD_ON) && FEATURE_NOT_SUPPORTED
    /* !req:TXCONFPOLL 4.0.3/CANIF739 */
#endif
    /* @req 4.0.3/CANIF724 */
    if(NULL != CanIfDispatchConfig.CanIfBusOffNotification) {
        /* @req 4.0.3/CANIF014 */
        CanIfDispatchConfig.CanIfBusOffNotification(channel);
    }
}

/* !req:CHANGEBAUD 4.0.3/CANIF780 */
/* !req:CHANGEBAUD 4.0.3/CANIF784 */
#if ( CANIF_PUBLIC_CHANGE_BAUDRATE_SUPPORT == STD_ON ) && FEATURE_NOT_SUPPORTED
/* !req:CHANGEBAUD 4.0.3/CANIF775 */
Std_ReturnType CanIf_CheckBaudrate(uint8 ControllerId, const uint16 Baudrate)
{
	/* !req:CHANGEBAUD 4.0.3/CANIF778 */
	/* !req:CHANGEBAUD 4.0.3/CANIF779 */
	return E_NOT_OK;
}
/* !req:CHANGEBAUD 4.0.3/CANIF776 */
Std_ReturnType CanIf_ChangeBaudrate(uint8 ControllerId, const uint16 Baudrate)
{
	/* !req:CHANGEBAUD 4.0.3/CANIF782 */
	/* !req:CHANGEBAUD 4.0.3/CANIF783 */
	/* !req:CHANGEBAUD 4.0.3/CANIF787 */
	return E_NOT_OK;
}
#endif

/* !req:SETDYNTXID 4.0.3/CANIF357 */
#if ( CANIF_PUBLIC_SETDYNAMICTXID_API == STD_ON ) && FEATURE_NOT_SUPPORTED
/* !req:SETDYNTXID 4.0.3/CANIF189 */
void CanIf_SetDynamicTxId( PduIdType CanTxPduId, Can_IdType CanId )
{
	/* !req:SETDYNTXID 4.0.3/CANIF188 */ //Maybe this req. should be elsewhere
	/* !req:SETDYNTXID 4.0.3/CANIF352 */
	/* !req:SETDYNTXID 4.0.3/CANIF353 */
	/* !req:SETDYNTXID 4.0.3/CANIF355 */
	/* !req:SETDYNTXID 4.0.3/CANIF356 */
	/* !req:SETDYNTXID 4.0.3/CANIF673 */
}
#endif
/* !req:CANTRCV 4.0.3/CANIF362 */
/* !req:CANTRCV 4.0.3/CANIF367 */
/* !req:CANTRCV 4.0.3/CANIF371 */
/* !req:CANTRCV 4.0.3/CANIF373 */
#if ( CANIF_ARC_TRANSCEIVER_API == STD_ON ) && FEATURE_NOT_SUPPORTED
/* !req:CANTRCV 4.0.3/CANIF287 */
Std_ReturnType CanIf_SetTrcvMode( uint8 TransceiverId, CanIf_TrcvModeType TransceiverMode )
{
	/* !req:CANTRCV 4.0.3/CANIF358 */
	/* !req:CANTRCV 4.0.3/CANIF538 */
	/* !req:CANTRCV 4.0.3/CANIF648 */
	return E_NOT_OK;
}
/* !req:CANTRCV 4.0.3/CANIF288 */
Std_ReturnType CanIf_GetTrcvMode( CanIf_TrcvModeType *TransceiverModePtr, uint8 TransceiverId)
{
	/* !req:CANTRCV 4.0.3/CANIF363 */
	/* !req:CANTRCV 4.0.3/CANIF364 */
	/* !req:CANTRCV 4.0.3/CANIF650 */
	return E_NOT_OK;
}
/* !req:CANTRCV 4.0.3/CANIF289 */
Std_ReturnType CanIf_GetTrcvWakeupReason( uint8 TransceiverId, CanIf_TrcvWakeupReasonType *TrcvWuReasonPtr );
{
	/* !req:CANTRCV 4.0.3/CANIF537 */
	/* !req:CANTRCV 4.0.3/CANIF649 */
	return E_NOT_OK;
}
/* !req:CANTRCV 4.0.3/CANIF290 */
Std_ReturnType CanIf_SetTrcvWakeupMode( uint8 TransceiverId, CanIf_TrcvWakeupModeType *TrcvWakeupMode )
{
	/* !req:CANTRCV 4.0.3/CANIF372 */
	/* !req:CANTRCV 4.0.3/CANIF535 */
	/* !req:CANTRCV 4.0.3/CANIF536 */
	return E_NOT_OK;
}
/* !req:CANTRCV 4.0.3/CANIF764 */
void CanIf_TrcvModeIndication( uint8 TransceiverId, CanIf_TrcvModeType TransceiverMode )
{
	/* !req:CANTRCV 4.0.3/CANIF706 */
	/* !req:CANTRCV 4.0.3/CANIF708 */
	/* !req:CANTRCV 4.0.3/CANIF709 */
	/* !req:CANTRCV 4.0.3/CANIF712 */
}
#endif

/* !req:WAKEUP 4.0.3/CANIF402 */
/* !req:WAKEUP 4.0.3/CANIF180 */
#if (( CANIF_CTRL_WAKEUP_SUPPORT == STD_ON ) || (CANIF_TRCV_WAKEUP_SUPPORT == STD_ON)) && FEATURE_NOT_SUPPORTED
/* !req:WAKEUP 4.0.3/CANIF219 */
Std_ReturnType CanIf_CheckWakeup( EcuM_WakeupSourceType WakeupSource )
{
	/* !req:WAKEUP 4.0.3/CANIF395 */
	/* !req:WAKEUP 4.0.3/CANIF398 */
	/* !req:WAKEUP 4.0.3/CANIF401 */
	/* !req:WAKEUP 4.0.3/CANIF678 */
	return E_NOT_OK;
}

/* !req:WAKEUP 4.0.3/CANIF226 */
/* !req:WAKEUP 4.0.3/CANIF408 */
#if (IF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT = STD_ON) && FEATURE_NOT_SUPPORTED
/* !req:WAKEUP 4.0.3/CANIF178 */
Std_ReturnType CanIf_CheckValidation( EcuM_WakeupSourceType WakeupSource )
{
	/* !req:WAKEUP 4.0.3/CANIF179 */
	/* !req:WAKEUP 4.0.3/CANIF404 */
	/* !req:WAKEUP 4.0.3/CANIF407 */
	/* !req:WAKEUP 4.0.3/CANIF681 */
	return E_NOT_OK;
}
#endif
#endif

/* !req:TXCONFPOLL 4.0.3/CANIF738 */
#if ( CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT == STD_ON ) && FEATURE_NOT_SUPPORTED
/* !req:TXCONFPOLL 4.0.3/CANIF734 */
CanIf_NotifStatusType CanIf_GetTxConfirmationState( uint8 ControllerId )
{
	/* !req:TXCONFPOLL 4.0.3/CANIF736 */
	/* !req:TXCONFPOLL 4.0.3/CANIF737 */
	return CANIF_NO_NOTIFICATION;
}
#endif

/* !req:PN 4.0.3/CANIF754 */
/* !req:PN 4.0.3/CANIF771 */
/* !req:PN 4.0.3/CANIF808 */
/* !req:PN 4.0.3/CANIF812 */
/* !req:PN 4.0.3/CANIF813 */
#if ( CANIF_PUBLIC_PN_SUPPORT == STD_ON ) && FEATURE_NOT_SUPPORTED
/* !req:PN 4.0.3/CANIF760 */
Std_ReturnType CanIf_ClearTrcvWufFlag( uint8 TransceiverId )
{
	/* !req:PN 4.0.3/CANIF766 */
	/* !req:PN 4.0.3/CANIF769 */
}
/* !req:PN 4.0.3/CANIF761 */
Std_ReturnType CanIf_CheckTrcvWakeFlag( uint8 TransceiverId )
{
	/* !req:PN 4.0.3/CANIF765 */
	/* !req:PN 4.0.3/CANIF770 */
	return E_NOT_OK;
}
/* !req:PN 4.0.3/CANIF815 */
void CanIf_ConfirmPnAvailability( uint8 TransceiverId )
{
    /* !req:PN 4.0.3/CANIF753 */
	/* !req:PN 4.0.3/CANIF816 */
	/* !req:PN 4.0.3/CANIF817 */
	/* !req:PN 4.0.3/CANIF818 */
}
/* !req:PN 4.0.3/CANIF762 */
void CanIf_ClearTrcvWufFlagIndication( uint8 TransceiverId )
{
	/* !req:PN 4.0.3/CANIF757 */
	/* !req:PN 4.0.3/CANIF805 */
	/* !req:PN 4.0.3/CANIF806 */
	/* !req:PN 4.0.3/CANIF807 */
}
/* !req:PN 4.0.3/CANIF763 */
void CanIf_CheckTrcvWakeFlagIndication( uint8 TransceiverId )
{
	/* !req:PN 4.0.3/CANIF759 */
	/* !req:PN 4.0.3/CANIF809 */
	/* !req:PN 4.0.3/CANIF810 */
	/* !req:PN 4.0.3/CANIF811 */
}
#endif



