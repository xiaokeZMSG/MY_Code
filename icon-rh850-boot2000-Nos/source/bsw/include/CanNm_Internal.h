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


#ifndef CANNM_INTERNAL_H_
#define CANNM_INTERNAL_H_

/** @req CANNM188  @req CANNM196  @req CANNM199    */
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
#define CANNM_DET_REPORTERROR(serviceId, errorId, instanceId)			\
	(void)Det_ReportError(MODULE_ID_CANNM, (uint8)instanceId, serviceId, errorId)

#define CANNM_VALIDATE(expression, serviceId, errorId, instanceId, ...)	\
	if (!(expression)) {									\
		CANNM_DET_REPORTERROR(serviceId, errorId, instanceId);			\
		return __VA_ARGS__;									\
	}

#define CANNM_VALIDATE_NORV(expression, serviceId, errorId, instanceId)	\
	if (!(expression)) {									\
		CANNM_DET_REPORTERROR(serviceId, errorId, instanceId);			\
		return;									\
	}

#else
#define CANNM_DET_REPORTERROR(...)
#define CANNM_VALIDATE(...)
#define CANNM_VALIDATE_NORV(...)
#endif

#define CANNM_VALIDATE_INIT(serviceID)					\
		CANNM_VALIDATE((CanNm_Internal.InitStatus == CANNM_INIT), serviceID, CANNM_E_NO_INIT, 0, E_NOT_OK)

#define CANNM_VALIDATE_INIT_NORV(serviceID, instanceID)					\
		CANNM_VALIDATE_NORV((CanNm_Internal.InitStatus == CANNM_INIT), serviceID, CANNM_E_NO_INIT, instanceID)

/** @req CANNM192 */
#define CANNM_VALIDATE_CHANNEL(nmHandle, serviceID)					\
		CANNM_VALIDATE( ((nmHandle < CANNM_NM_CHANNELS_COUNT) && (CanNm_ConfigPtr->ChannelLookups[nmHandle] != CANNM_UNUSED_CHANNEL)), serviceID, CANNM_E_INVALID_CHANNEL, nmHandle, E_NOT_OK)

#define CANNM_VALIDATE_NOTNULL(ptr, serviceID, instanceID)	\
		CANNM_VALIDATE((ptr != NULL), serviceID, NM_E_NULL_POINTER, instanceID, E_NOT_OK)

#define CANNM_VALIDATE_NOTNULL_NORV(ptr, serviceID, instanceID)	\
		CANNM_VALIDATE_NORV( (ptr != NULL), serviceID, NM_E_NULL_POINTER, instanceID)

#define CANNM_VALIDATE_NOTNULL_INIT(ptr, serviceID, instanceID)	\
		CANNM_VALIDATE_NORV( (ptr != NULL), serviceID, CANNM_E_INIT_FAILED, instanceID)

#define CANNM_VALIDATE_PDUID_NORV(pduID, serviceID) \
		CANNM_VALIDATE_NORV( (pduID < CANNM_CHANNEL_COUNT), serviceID, CANNM_E_INVALID_PDUID, pduID)

#if (CANNM_COM_USER_DATA_SUPPORT == STD_ON)
#define CANNM_SPONTANEOUS_TRANSMISSION 3
#define CANNM_ONGOING_TRANSMISSION 1
#define CANNM_NO_TRANSMISSION 0
#endif

typedef enum {
	CANNM_INIT,
	CANNM_UNINIT
} CanNm_InitStatusType;

typedef struct {
	Nm_ModeType					Mode;				/**< @req CANNM092 */
	Nm_StateType				State;				/**< @req CANNM094 */
	boolean						Requested;
	uint32_t						TimeoutTimeLeft;
	uint32_t						RepeatMessageTimeLeft;
	uint32_t						WaitBusSleepTimeLeft;
	uint32_t						MessageCycleTimeLeft;
	uint32_t						MessageCycleOffsetTimeLeft;
	uint32_t                      MessageTimeoutTimeLeft;
	uint8_t						TxMessageSdu[8];
	uint8_t						RxMessageSdu[8];
	uint8_t						immediateNmTransmissionsSent;
	boolean						immediateModeActive;
#if (CANNM_USER_DATA_ENABLED == STD_ON) /* and com_user_data... == OFF */
	boolean						IsUserDataSet;
#endif
	boolean 	                CommunicationEnabled;
} CanNm_Internal_ChannelType;

typedef struct {
	CanNm_InitStatusType 		InitStatus;
	CanNm_Internal_ChannelType	Channels[CANNM_CHANNEL_COUNT];
} CanNm_InternalType;



/**********************************************************************************************************************
  Local data types and structures
**********************************************************************************************************************/

/****************************************
 * Name:        tNmTimeCnt
 * Description: This type is used for the NM task counter.
 * Note       : The value range of the counter may depend on the used features.
 */
typedef uint16_t tNmTimeCnt;

/****************************************
 * Name:        tNmStateType
 * Description: This type represents the various status flags.
 */
typedef union
{ /* PRQA S 0750 */ /* union used for optimization reason */
  uint8_t c[2];
  struct 
  {
  	UINT8    b_RingStable      :1;     /* byte0 bit0 */
	UINT8    b_BusError        :1;     /* byte0 bit1 */
	UINT8    b_Active          :1;     /* byte0 bit2 */
	UINT8    b_LimpHome        :1;     /* byte0 bit3 */
	UINT8    b_BusSleep        :1;     /* byte0 bit4 */
	UINT8    b_WaitBusSleep    :1;     /* byte0 bit5 */
	UINT8    b_TxRingDataAllow :1;     /* byte0 bit6 */
    UINT8    b_BusSleepInd     :1;     /* byte0 bit7 */

	UINT8    b_NmMsgRecv       :1;     /* byte1 bit0 */
	UINT8    b_RingMsgRecv     :1;     /* byte1 bit1 */
	UINT8    b_ImAddressed     :1;     /* byte1 bit2 */
	UINT8    b_ImSkippedOver   :1;     /* byte1 bit3 */
	UINT8    b_NmMsgRecvRemind :1;     /* byte1 bit4 */
	UINT8    b_RxTxLockUd      :1;     /* byte1 bit5 */
	UINT8    b_RingPreStable   :1;     /* byte1 bit6 */
    UINT8    b_PrepSleep       :1;     /* byte1 bit7 */
  }b;
} tNmStateType;


/****************************************
 * Name:        tNmTxMsgTypeUnion
 * Description: This type represents the message layout of the NM TX message.
 */
typedef union
{ /* union used for optimization reason */
  uint8_t c[8];
  struct
  {
    UINT8 cDest          :8;   /* byte0 bit07..00 */
	UINT8 cCmd           :4;   /* byte1 bit11..08 */
	UINT8 bSleepInd      :1;   /* byte1 bit12 */
	UINT8 bSleepAck      :1;   /* byte1 bit13 */
	UINT8 bConfig        :1;   /* byte1 bit14 */
    UINT8 bReserved0     :1;   /* byte1 bit15 */
                               /* byte2..7 are accessed by byte element of union */                                  
  }b;
} tNmTxMsgTypeUnion;

#define RX_CNT_MASK		((uint8_t)0x0F)
#define RX_CNT_STEP			((uint8_t)0x01)
#define TX_CNT_MASK			((uint8_t)0xF0)
#define TX_CNT_STEP			((uint8_t)0x10)
#define RX_CNT_MAX			((uint8_t)4)
#define TX_CNT_MAX			((uint8_t)8)
#define BYTE_OFFSET_MASK	((uint8_t)0x07)

/* Defines for NM message bits */
  #define ALIVE		((uint8_t)0x01)
  #define RING		((uint8_t)0x02)
  #define LIMPHOME	((uint8_t)0x04)
  #define SLEEP_IND	((uint8_t)0x10)
  #define SLEEP_ACK	((uint8_t)0x20)
  #define DATA_INIT	((uint8_t)0x00)

/* Timer helpers */
#endif /* CANNM_INTERNAL_H_ */
