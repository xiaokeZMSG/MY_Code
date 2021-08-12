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

#ifndef DCM_LCFG_H_
#define DCM_LCFG_H_

/*
 *  General requirements
 */
/** @req 3.1.5/DCM075 */ /** @req 3.1.5/DCM076 */


#include "ComStack_Types.h"
#include "Dcm_Types.h"
#include "Dem_Types.h"

typedef uint8_t Dcm_ProtocolTransTypeType;
#define DCM_PROTOCOL_TRANS_TYPE_1		1
#define DCM_PROTOCOL_TRANS_TYPE_2		2

typedef uint8_t Dcm_ProtocolAddrTypeType;
#define DCM_PROTOCOL_FUNCTIONAL_ADDR_TYPE	1
#define DCM_PROTOCOL_PHYSICAL_ADDR_TYPE		2

#define DCM_PROTOCAL_TP_MAX_LENGTH 0x1000
#define DCM_INVALID_PDU_ID 0xFFFF


#define DTC_LOST_FRS 0xC14687
#define DTC_LOST_FCS 0xC14587

#define DCM_BUFFER_TX_SIZE       (210)

/*
 * Callback function prototypes
 */

// SessionControl
typedef Std_ReturnType (*Dcm_CallbackGetSesChgPermissionFncType)(Dcm_SesCtrlType sesCtrlTypeActive, Dcm_SesCtrlType sesCtrlTypeNew);
typedef Std_ReturnType (*Dcm_CallbackChangeIndicationFncType)(Dcm_SesCtrlType sesCtrlTypeOld, Dcm_SesCtrlType sesCtrlTypeNew);
typedef Std_ReturnType (*Dcm_CallbackConfirmationRespPendFncType)(Dcm_ConfirmationStatusType status);

// SecurityAccess_<LEVEL>
typedef Std_ReturnType (*Dcm_CallbackGetSeedFncTypeWithRecord)(uint8_t *securityAccessDataRecord, Dcm_OpStatusType OpStatus, uint8_t *seed, Dcm_NegativeResponseCodeType *errorCode);
typedef Std_ReturnType (*Dcm_CallbackGetSeedFncTypeWithoutRecord)(Dcm_OpStatusType OpStatus, uint8_t *seed, Dcm_NegativeResponseCodeType *errorCode);
typedef union {
	Dcm_CallbackGetSeedFncTypeWithoutRecord getSeedWithoutRecord;
	Dcm_CallbackGetSeedFncTypeWithRecord getSeedWithRecord;
}Dcm_CallbackGetSeedFncType;
typedef Std_ReturnType (*Dcm_CallbackCompareKeyFncType)(const uint8_t *key);

// PidServices_<PID>
typedef Std_ReturnType (*Dcm_CallbackGetPIDValueFncType)(uint8_t *dataValueBuffer);

// DidServices_<DID>
typedef Std_ReturnType (*Dcm_SynchCallbackReadDataFncType)(uint8_t *data);
typedef Std_ReturnType (*Dcm_AsynchCallbackReadDataFncType)(Dcm_OpStatusType OpStatus, uint8_t *data);
typedef Std_ReturnType (*Dcm_FixLenCallbackWriteDataFncType)(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode);
typedef Std_ReturnType (*Dcm_DynLenCallbackWriteDataFncType)(uint8_t *data, uint16_t dataLength, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode);
typedef Std_ReturnType (*Dcm_CallbackReadDataLengthFncType)(uint16_t *didLength);
typedef Std_ReturnType (*Dcm_CallbackConditionCheckReadFncType)(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *errorCode);
typedef Std_ReturnType (*Dcm_CallbackConditionCheckWriteFncType)(Dcm_NegativeResponseCodeType *errorCode);
typedef Std_ReturnType (*Dcm_FuncCallbackReturnControlToECUFncType)(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *errorCode);
typedef Std_ReturnType (*Dcm_FuncCallbackResetToDefaultFncType)(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *errorCode);
typedef Std_ReturnType (*Dcm_FuncCallbackFreezeCurrentStateFncType)(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *errorCode);
typedef Std_ReturnType (*Dcm_FuncCallbackShortTermAdjustmentFncType)(uint8_t *controlOptionRecord, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *errorCode);

typedef Std_ReturnType (*Dcm_EcuSignalCallbackReturnControlToECUFncType)(uint8_t action, uint8_t *controlOptionRecord);
typedef Std_ReturnType (*Dcm_EcuSignalCallbackResetToDefaultFncType)(uint8_t action, uint8_t *controlOptionRecord);
typedef Std_ReturnType (*Dcm_EcuSignalCallbackFreezeCurrentStateFncType)(uint8_t action, uint8_t *controlOptionRecord);
typedef Std_ReturnType (*Dcm_EcuSignalCallbackShortTermAdjustmentFncType)(uint8_t action, uint8_t *controlOptionRecord);


typedef Std_ReturnType (*Dcm_CallbackGetScalingInformationFncType)(Dcm_OpStatusType OpStatus, uint8_t *scalingInfo, Dcm_NegativeResponseCodeType *errorCode);

// InfoTypeServices_<INFOTYPENUMBER>
typedef Std_ReturnType (*Dcm_CallbackGetInfoTypeValueFncType)(uint8_t *dataValueBuffer);

// DTRServices
typedef Std_ReturnType (*Dcm_CallbackGgetDTRValueFncType)(uint16_t *testval, uint16_t *minlimit, uint16_t *maxlimit, uint8_t *status);

// RoutineServices_<ROUTINENAME>
typedef Std_ReturnType (*Dcm_CallbackStartRoutineFncType)(uint8_t *indata, Dcm_OpStatusType OpStatus, uint8_t *outdata,
			uint16_t* currentDataLength, Dcm_NegativeResponseCodeType *errorCode, boolean changeEndianess);
typedef Std_ReturnType (*Dcm_CallbackStopRoutineFncType)(uint8_t *indata, Dcm_OpStatusType OpStatus, uint8_t *outdata,
			uint16_t* currentDataLength, Dcm_NegativeResponseCodeType *errorCode, boolean changeEndianess);
typedef Std_ReturnType (*Dcm_CallbackRequestResultRoutineFncType)(Dcm_OpStatusType OpStatus, uint8_t *outdata,
			uint16_t* currentDataLength, Dcm_NegativeResponseCodeType *errorCode, boolean changeEndianess);

// RequestControlServices_<TID>
typedef Std_ReturnType (*Dcm_CallbackRequestControlType)(uint8_t *outBuffer, uint8_t *inBuffer);

// CallBackDCMRequestServices
typedef Std_ReturnType (*Dcm_CallbackStartProtocolFncType)(Dcm_ProtocolType protocolID);
typedef Std_ReturnType (*Dcm_CallbackStopProtocolFncType)(Dcm_ProtocolType protocolID);

// ServiceRequestIndication
typedef Std_ReturnType (*Dcm_CallbackNotificationIndicationFncType)(uint8_t SID, uint8_t* requestData, uint16_t dataSize, uint8_t reqType, uint16_t soruceAddress, Dcm_NegativeResponseCodeType* ErrorCode);
typedef Std_ReturnType (*Dcm_CallbackNotificationConfirmationFncType)(uint8_t SID, uint8_t reqType, uint16_t sourceAddress, Dcm_ConfirmationStatusType status);

// ResetService
typedef Std_ReturnType (*Dcm_CallbackEcuResetType)(uint8_t resetType,	Dcm_NegativeResponseCodeType *errorCode);

//OBD service 0x04 condition check callback
typedef Std_ReturnType (*Dcm_DsdConditionGetFncType)(void);
typedef Std_ReturnType (*Dcm_DsdResetPidsFncType)(void);

typedef enum {
    DATA_PORT_NO_PORT,
    DATA_PORT_BLOCK_ID,
    DATA_PORT_ASYNCH,
    DATA_PORT_SYNCH,
    DATA_PORT_ECU_SIGNAL
}Dcm_DataPortType;

typedef union {
    Dcm_SynchCallbackReadDataFncType  SynchDataReadFnc;    // (0..1)
    Dcm_AsynchCallbackReadDataFncType AsynchDataReadFnc;    // (0..1)
} Dcm_CallbackReadDataFncType;
typedef union {
	Dcm_FixLenCallbackWriteDataFncType  FixLenDataWriteFnc;    // (0..1)
	Dcm_DynLenCallbackWriteDataFncType DynLenDataWriteFnc;    // (0..1)
	
	
} Dcm_CallbackWriteDataFncType;
typedef union {
    Dcm_FuncCallbackResetToDefaultFncType  FuncResetToDefaultFnc;    // (0..1)
    Dcm_EcuSignalCallbackResetToDefaultFncType EcuSignalResetToDefaultFnc;    // (0..1)
} Dcm_CallbackResetToDefaultFncType;
typedef union {
    Dcm_FuncCallbackReturnControlToECUFncType  FuncReturnControlToECUFnc;    // (0..1)
    Dcm_EcuSignalCallbackReturnControlToECUFncType EcuSignalReturnControlToECUFnc;    // (0..1)
} Dcm_CallbackReturnControlToECUFncType;
typedef union {
    Dcm_FuncCallbackShortTermAdjustmentFncType  FuncShortTermAdjustmentFnc;    // (0..1)
    Dcm_EcuSignalCallbackShortTermAdjustmentFncType EcuSignalShortTermAdjustmentFnc;    // (0..1)
} Dcm_CallbackShortTermAdjustmentFncType;
typedef union {
    Dcm_FuncCallbackFreezeCurrentStateFncType  FuncFreezeCurrentStateFnc;    // (0..1)
    Dcm_EcuSignalCallbackFreezeCurrentStateFncType EcuSignalFreezeCurrentStateFnc;    // (0..1)
} Dcm_CallbackFreezeCurrentStateFncType;



/*
 * DCM configurations
 */

/*******
 * DSP *
 *******/

// 10.2.44
typedef struct {
	Dcm_SesCtrlType	DspSessionLevel;			// (1)
	uint16_t			DspSessionP2ServerMax;		// (1)
	uint16_t			DspSessionP2StarServerMax;	// (1)
	boolean			Arc_EOL;
} Dcm_DspSessionRowType; /** @req DCM072 */

// 10.2.42
typedef struct {
	uint32_t							DspSecurityADRSize;			// (0..1)
	uint32_t							DspSecurityDelayTimeOnBoot;	// (1)
	uint32_t							DspSecurityDelayTime;		// (1)
	Dcm_SecLevelType				DspSecurityLevel;			// (1)
	uint8_t							DspSecurityNumAttDelay;		// (1)
	uint8_t							DspSecurityNumAttLock;		// (1)
	uint8_t							DspSecuritySeedSize;		// (1)
	uint8_t							DspSecurityKeySize;			// (1)
	Dcm_CallbackGetSeedFncType		GetSeed;
	Dcm_CallbackCompareKeyFncType	CompareKey;
	boolean							Arc_EOL;
} Dcm_DspSecurityRowType; /** @req DCM073 */

// 10.2.23
typedef struct {
	uint8_t DspDidControlEnableMaskRecordSize;			// (1)
	uint8_t DspDidControlOptionRecordSize;	// (1)
	uint8_t DspDidControlStatusRecordSize;	// (1)
} Dcm_DspDidControlRecordSizesType;

// 10.2.26
typedef struct {
	const Dcm_DspSessionRowType				* const *DspDidControlSessionRef;		// (1..*)	/** @req DCM621 */
	const Dcm_DspSecurityRowType			* const *DspDidControlSecurityLevelRef;	// (1..*)	/** @req DCM620 */
	const Dcm_DspDidControlRecordSizesType	*DspDidFreezeCurrentState;			// (0..1)	/** @req DCM624 */
	const Dcm_DspDidControlRecordSizesType	*DspDidResetToDefault;				// (0..1)	/** @req DCM623 */
	const Dcm_DspDidControlRecordSizesType	*DspDidReturnControlToEcu;			// (0..1)	/** @req DCM622 */
	const Dcm_DspDidControlRecordSizesType	*DspDidShortTermAdjustment;			// (0..1)	/** @req DCM625 */
} Dcm_DspDidControlType; /** @req DCM619 */

// 10.2.27
typedef struct {
	const Dcm_DspSessionRowType		* const *DspDidReadSessionRef;			// (1..*)	/** @req DCM615 */
	const Dcm_DspSecurityRowType	* const *DspDidReadSecurityLevelRef;	// (1..*)	/** @req DCM614 */
} Dcm_DspDidReadType; /** @req DCM613 */

// 10.2.28
typedef struct {
	const Dcm_DspSessionRowType		* const *DspDidWriteSessionRef;		// (1..*)	/** @req DCM618 */
	const Dcm_DspSecurityRowType	* const *DspDidWriteSecurityLevelRef;	// (1..*)	/** @req DCM617 */
} Dcm_DspDidWriteType; /** @req DCM616 */

// 10.2.25
typedef struct {
	// Containers
	const Dcm_DspDidReadType		*DspDidRead;	// (0..1)
	const Dcm_DspDidWriteType		*DspDidWrite;	// (0..1)
	const Dcm_DspDidControlType		*DspDidControl;	// (0..1)
} Dcm_DspDidAccessType; /** @req DCM609 */

// 10.2.24
typedef struct {
	boolean					DspDidDynamicllyDefined;	// (1)		/** @req DCM612 */
	boolean					DspDidFixedLength;			// (1)		/** @req DCM608 */
	uint8_t					DspDidScalingInfoSize;		// (0..1)	/** @req DCM611 */
	// Containers
	Dcm_DspDidAccessType	DspDidAccess;				// (1)
} Dcm_DspDidInfoType; /** @req DCM607 */

// 10.2.22
typedef struct Dcm_DspDidType {
    Dcm_DataPortType							DspDidUsePort;					// (1)
	uint16_t										DspDidIdentifier;				// (1)		/** @req DCM602 */
	const Dcm_DspDidInfoType					*DspDidInfoRef;					// (1)		/** @req DCM604 */
	const struct Dcm_DspDidType					* const *DspDidRef;				// (0..*)	/** @req DCM606 */
	uint16_t										DspDidSize;						// (1)		/** @req DCM605 */
	Dcm_CallbackReadDataLengthFncType			DspDidReadDataLengthFnc;		// (0..1)	/** @req DCM671 */
	Dcm_CallbackConditionCheckReadFncType		DspDidConditionCheckReadFnc;	// (0..1)	/** @req DCM677 */
	Dcm_CallbackReadDataFncType					DspDidReadDataFnc;				// (0..1)	/** @req DCM669 */
	Dcm_CallbackWriteDataFncType				DspDidWriteDataFnc;				// (0..1)	/** @req DCM670 */
	Dcm_CallbackGetScalingInformationFncType	DspDidGetScalingInfoFnc;		// (0..1)	/** @req DCM676 */
	Dcm_CallbackFreezeCurrentStateFncType		DspDidFreezeCurrentStateFnc;	// (0..1)	/** @req DCM674 */
	Dcm_CallbackResetToDefaultFncType			DspDidResetToDefaultFnc;			// (0..1)	/** @req DCM673 */
	Dcm_CallbackReturnControlToECUFncType		DspDidReturnControlToEcuFnc;	// (0..1)	/** @req DCM672 */
	Dcm_CallbackShortTermAdjustmentFncType		DspDidShortTermAdjustmentFnc;	// (0..1)	/** @req DCM675 */
	// Containers
	const Dcm_DspDidControlRecordSizesType		*DspDidControlRecordSize;		// (0..*)
	boolean                                     DspDidHasData;
	boolean										Arc_EOL;
} Dcm_DspDidType; /** @req DCM601 */

// 10.2.30
typedef struct {
	const Dcm_DspSessionRowType		* const *DspEcuResetSessionRef;			// (1..*)
	const Dcm_DspSecurityRowType	* const *DspEcuResetSecurityLevelRef;	// (1..*)
} Dcm_DspEcuResetType; /** @req DCM657 */

// 10.2.31
typedef struct {
	boolean							DspPidUsePort;		// (1)
	uint8_t							DspPidIdentifier;	// (1)	/** @req DCM627 */
	uint8_t							DspPidSize; 		// (1)	/** @req DCM628 */
	Dcm_PidServiceType				DspPidService;
	Dcm_CallbackGetPIDValueFncType	DspGetPidValFnc;	// (1)	/** @req DCM629 */
	boolean							Arc_EOL;
} Dcm_DspPidType; /** @req DCM626 */

// 10.2.33
typedef struct {
	boolean							DspDTCInfoSubFuncSupp;		// (1)
	uint8_t							DspDTCInfoSubFuncLevel;		// (1)
	const Dcm_DspSecurityRowType	* const *DspDTCInfoSecLevelRef;	// (1..*)
} Dcm_DspReadDTCRowType; /** @req DCM073 */

// 10.2.32
typedef struct {
	// Containers
	Dcm_DspReadDTCRowType *DspReadDTCRow; // (0..*)
} Dcm_DspReadDTCType; /** @req DCM074 */

// 10.2.34
typedef struct {
	uint8_t DspRequestControl;				// (1)
	uint8_t DspRequestControlOutBufferSize;	// (1)
	uint8_t DspRequestControlTestId;			// (1)	/** @req DCM656 */
} Dcm_DspRequestControlType; /** @req DCM637 */

// 10.2.37
typedef struct {
	const Dcm_DspSessionRowType		* const *DspRoutineSessionRef;			// (1..*)	/** @req DCM649 */
	const Dcm_DspSecurityRowType	* const *DspRoutineSecurityLevelRef;	// (1..*)	/** @req DCM648 */
} Dcm_DspRoutineAuthorizationType; /** @req DCM644 */

// 10.2.38
typedef struct {
	uint8_t DspReqResRtnCtrlOptRecSize; // (1)	/** @req DCM652 */
} Dcm_DspRoutineRequestResType; /** @req DCM646 */

// 10.2.39
typedef struct {
	uint8_t DspStopRoutineCtrlOptRecSize;	// (1)	/** @req DCM650 */
	uint8_t DspStopRoutineStsOptRecSize;	// (1)	/** @req DCM651 */
} Dcm_DspRoutineStopType; /** @req DCM645 */

// 10.2.40
typedef struct {
	uint8_t DspStartRoutineCtrlOptRecSize;	// (1)	/** @req DCM654 */
	uint8_t DspStartRoutineStsOptRecSize;		// (1)	/** @req DCM655 */
} Dcm_DspStartRoutineType; /** @req DCM647 */

// 10.2.36
typedef struct {
	// Containers
	const Dcm_DspRoutineAuthorizationType	DspRoutineAuthorization;	// (1)
	const Dcm_DspStartRoutineType			*DspStartRoutine;			// (1)
	const Dcm_DspRoutineStopType			*DspRoutineStop;			// (0..1)
	const Dcm_DspRoutineRequestResType		*DspRoutineRequestRes;		// (0..1)
} Dcm_DspRoutineInfoType; /** @req DCM643 */

// 10.2.35
typedef struct {
	boolean									DspRoutineUsePort;			// (1)
	uint16_t									DspRoutineIdentifier;		// (1)		/** @req DCM641 */
	const Dcm_DspRoutineInfoType			*DspRoutineInfoRef;			// (1)		/** @req DCM642 */
	Dcm_CallbackStartRoutineFncType			DspStartRoutineFnc;			// (0..1)	/** @req DCM664 */
	Dcm_CallbackStopRoutineFncType			DspStopRoutineFnc;			// (0..1)	/** @req DCM665 */
	Dcm_CallbackRequestResultRoutineFncType	DspRequestResultRoutineFnc;	// (0..1)	/** @req DCM665 */
	boolean									Arc_EOL;
} Dcm_DspRoutineType; /** @req ConfDCM640 */

// 10.2.41
typedef struct {
	// Containers
	const Dcm_DspSecurityRowType *DspSecurityRow; // (0..31)
} Dcm_DspSecurityType; /** @req DCM073 */

// 10.2.43
typedef struct {
	// Containers
	const Dcm_DspSessionRowType *DspSessionRow; // (0..31)
} Dcm_DspSessionType; /** @req DCM072 */

// 10.2.47
typedef struct {
	uint8_t DspTestResultTestId;	// (1)	/** @req DCM635 */
	uint8_t DspTestResultUaSid;	// (1)	/** @req DCM686 */
} Dcm_DspTestResultTidType; /** @req DCM634 */

// 10.2.46
typedef struct {
	uint8_t							DspTestResultObdmid;			// (1)		/** @req DCM684 */
	const Dcm_DspTestResultTidType	**DspTestResultObdmidTidRef;	// (1..*)	/** @req DCM685 */
} Dcm_DspTestResultObdmidTidType; /** @req DCM683 */

// 10.2.45
typedef struct {
	// Containers
	const Dcm_DspTestResultObdmidTidType	*DspTestResultObdmidTid;	// (0..*)
	const Dcm_DspTestResultTidType			*DspTestResultTid;			// (0..*)
} Dcm_DspTestResultByObdmidType; /** @req DCM682 */

// 10.2.48
typedef struct {
	boolean								DspVehInfoUsePort;		// (1)
	uint8_t								DspVehInfoType;			// (1)	/** @req DCM631 */
	uint8_t								DspVehInfoSize;			// (1)	/** @req DCM632 */
	uint8_t								DspVehInfoNumberOfDataItems;
	Dcm_CallbackGetInfoTypeValueFncType	DspGetVehInfoTypeFnc;	// (1)	/** @req DCM633 */
	boolean Arc_EOL;
} Dcm_DspVehInfoType; /** @req DCM630 */

// 10.2.21
typedef struct {
	uint32_t MemoryAddressHigh;
	uint32_t MemoryAddressLow;
	/*DcmDspMemoryRangeRuleRef * pRule;*/
	const Dcm_DspSecurityRowType * const *pSecurityLevel;
	boolean Arc_EOL;
} Dcm_DspMemoryRangeInfo;

typedef struct {
      uint8_t MemoryIdValue;
     const Dcm_DspMemoryRangeInfo *pReadMemoryInfo;
     const Dcm_DspMemoryRangeInfo *pWriteMemoryInfo;
     boolean										Arc_EOL;
} Dcm_DspMemoryIdInfo;


typedef struct {
	boolean								DcmDspUseMemoryId;
	const Dcm_DspMemoryIdInfo			*DspMemoryIdInfo;
	
}Dcm_DspMemoryType;

// 10.2.21
typedef struct {
	uint8_t								DspMaxDidToRead; // (0..1)	/** @req DCM638 */
	// Containers
	const Dcm_DspDidType				*DspDid;	// (0..*)
	const Dcm_DspDidInfoType			*DspDidInfo;			// (0..*)
	const Dcm_DspEcuResetType			*DspEcuReset;			// (0..*)
	const Dcm_DspPidType				*DspPid;				// (0..*)
	const Dcm_DspReadDTCType			*DspReadDTC;			// (1)
	const Dcm_DspRequestControlType		*DspRequestControl;		// (0..*)
	const Dcm_DspRoutineType			*DspRoutine;			// (0..*)
	const Dcm_DspRoutineInfoType		*DspRoutineInfo;		// (0..*)
	const Dcm_DspSecurityType			*DspSecurity;			// (0..*)
	const Dcm_DspSessionType			*DspSession;			// (1)
	const Dcm_DspTestResultByObdmidType	*DspTestResultByObdmid;	// (0..*)
	const Dcm_DspVehInfoType			*DspVehInfo;
	const Dcm_DspMemoryType             *DspMemory;
} Dcm_DspType;

/*******
 * DSD *
 *******/
// 10.2.4 DcmDsdService
typedef struct {
	uint8_t							DsdSidTabServiceId;				// (1)
	boolean							DsdSidTabSubfuncAvail;			// (1)
	const Dcm_DspSecurityRowType	* const *DsdSidTabSecurityLevelRef;	// (1..*)
	const Dcm_DspSessionRowType		* const *DsdSidTabSessionLevelRef;		// (1..*)
	// Containers
	Dcm_DsdConditionGetFncType 		ArcDcmDsdSidConditionCheckFnc;	//non-Autosar
	Dcm_DsdResetPidsFncType			resetPids;
	boolean							Arc_EOL;
} Dcm_DsdServiceType;

// 10.2.3 DcmDsdServiceTable
typedef struct {
	uint8_t						DsdSidTabId; // (1)
	// Containers
	const Dcm_DsdServiceType	*DsdService; // (1..*)
	boolean						Arc_EOL;
} Dcm_DsdServiceTableType; /** @req DCM071 */

// 10.2.2 DcmDsd
typedef struct {
	// Containers
	const Dcm_DsdServiceTableType *DsdServiceTable; // (1..256)
} Dcm_DsdType;

/*******
 * DSL *
 *******/

typedef enum
{
	BUFFER_AVAILABLE,
	BUFFER_BUSY
}Dcm_DslBufferStatusType;


typedef enum
{
	NOT_IN_USE,	                   // The buffer is not used (it is available).
	IN_USE,
	PROVIDED_TO_PDUR,              // The buffer is currently in use by PDUR.
	DSD_PENDING_RESPONSE_SIGNALED, // Signals have been received saying the buffer contain valid data.
	DCM_TRANSMIT_SIGNALED,         // The DCM has been asked to transfer the response, system is now waiting for TP layer to reqest Tx buffer.
	PROVIDED_TO_DSD,	           // The buffer is currently in use by DSD.
	PREEMPT_TRANSMIT_NRC,          //when preemption happens,then sent NRC 0x21 to OBD tester
	UNDEFINED_USAGE
}Dcm_DslBufferUserType;

typedef struct {
	Dcm_DslBufferStatusType status; // Flag for buffer in use.
	PduLengthType nofBytesHandled;
	PduIdType DcmRxPduId; //The external buffer is locked to this PDU id
} Dcm_DslBufferRuntimeType;

// 10.2.6
typedef struct {
	uint8_t						DslBufferID;	// (1) // Kept for reference, will be removed (polite calls will be made).
	uint16_t						DslBufferSize;	// (1)
	PduInfoType					pduInfo;
	Dcm_DslBufferRuntimeType	*externalBufferRuntimeData;
} Dcm_DslBufferType; /** @req DCM032 */

// 10.2.7
typedef struct {
	Dcm_CallbackStartProtocolFncType	StartProtocol;
	Dcm_CallbackStopProtocolFncType		StopProtocol;
	boolean								Arc_EOL;
} Dcm_DslCallbackDCMRequestServiceType; /** @req DCM679 */

// 10.2.8
typedef struct {
	boolean	DslDiagRespForceRespPendEn;	// (1)
	uint8_t	DslDiagRespMaxNumRespPend;	// (1)
} Dcm_DslDiagRespType;

// 10.2.18
typedef struct {
	uint16_t			TimStrP2ServerMax;		// (1)
	uint16_t			TimStrP2ServerMin;		// (1)
	uint16_t			TimStrP2StarServerMax;	// (1)
	uint16_t			TimStrP2StarServerMin;	// (1)
	uint16_t 			TimStrS3Server;			// (1)
	const boolean	Arc_EOL;
} Dcm_DslProtocolTimingRowType;

// 10.2.17
typedef struct {
	const Dcm_DslProtocolTimingRowType *DslProtocolTimingRow; // (0..*)
} Dcm_DslProtocolTimingType; /** @req DCM031 */

// 10.2.16
typedef uint8_t Dcm_DslResponseOnEventType;

/* Makes it possible to cross-reference structures. */
typedef struct Dcm_DslMainConnectionType_t Dcm_DslMainConnectionType;
typedef struct Dcm_DslProtocolRxType_t Dcm_DslProtocolRxType;

// 10.2.13
struct Dcm_DslProtocolRxType_t {
	const Dcm_DslMainConnectionType	*DslMainConnectionParent;				// (1) /* Cross reference. */
	const Dcm_ProtocolAddrTypeType	DslProtocolAddrType;					// (1)
	const PduIdType					DcmDslProtocolRxPduId;					// (1)
	const uint8_t						DcmDslProtocolRxChannelId_v4;			// (1)
	const NetworkHandleType         DcmDslProtocolRxComMChannel;            // (1)
	const boolean					Arc_EOL;
};

/* Makes it possible to cross-reference structures. */
//typedef struct Dcm_DslMainConnectionType_t Dcm_DslMainConnectionType;
typedef struct Dcm_DslProtocolTxType_t Dcm_DslProtocolTxType;

// 10.2.14
struct Dcm_DslProtocolTxType_t {
	const Dcm_DslMainConnectionType	*DslMainConnectionParent;	// (1) /* Cross reference. */
	const PduIdType					DcmDslProtocolTxPduId;		// (1) /* Will be removed (polite), kept for reference. */
	const boolean					Arc_EOL;
};


/* Make it possible to cross reference. */
typedef struct Dcm_DslConnectionType_t Dcm_DslConnectionType;
/* Make it possible to cross reference. */
typedef struct Dcm_DslProtocolRowType_t Dcm_DslProtocolRowType;

typedef struct {
    const Dcm_DslProtocolRowType *DslProtocolRow;
    const PduIdType PduRTxPduId;
    const PduIdType DcmTxPduId;
    const boolean Arc_EOL;
}Dcm_DslPeriodicTxType;
// 10.2.15
typedef struct {
    const Dcm_DslProtocolRowType *DslProtocolRow;
    const Dcm_DslPeriodicTxType *TxPduList;
    const boolean Arc_EOL;
} Dcm_DslPeriodicTransmissionType;
// 10.2.12
struct Dcm_DslMainConnectionType_t { // Cross referenced from Dcm_DslProtocolRxType_t.
	const Dcm_DslConnectionType				*DslConnectionParent; // Cross reference.
	const Dcm_DslPeriodicTransmissionType	*DslPeriodicTransmissionConRef;	// (0..1)
	const Dcm_DslResponseOnEventType		*DslROEConnectionRef;			// (0..*)
	// Containers
	const Dcm_DslProtocolRxType				*DslProtocolRx;					// (1..*) Remove?
	const Dcm_DslProtocolTxType				*DslProtocolTx;					// (1)
	uint16_t                                  DslRxTesterSourceAddress;       // (1)
};

// 10.2.11
struct Dcm_DslConnectionType_t {
	// Containers
	const Dcm_DslProtocolRowType			*DslProtocolRow;			// Cross reference.
	const Dcm_DslMainConnectionType			*DslMainConnection;			// (1)
	const Dcm_DslPeriodicTransmissionType	*DslPeriodicTransmission;	// (0..1)
	const Dcm_DslResponseOnEventType		*DslResponseOnEvent;		// (0..1)
	boolean 								Arc_EOL;
};

typedef enum {
	DCM_IDLE = 0, /* Not in use. */
	DCM_WAITING_DIAGNOSTIC_RESPONSE, /* A diagnostic request has been forwarded to the DSD, and DSL is waiting for response. */
	DCM_DIAGNOSTIC_RESPONSE_PENDING, /* A diagnostic response has been deployed to the external buffer and is waiting to be transmitted. */
	DCM_TRANSMITTING_EXTERNAL_BUFFER_DATA_TO_PDUR, /* We are in the process of transmitting a diagnostic response most likely that reside in the external buffer, from DSD to PDUR. */
	DCM_TRANSMITTING_LOCAL_BUFFER_DATA_TO_PDUR /*  */
} Dcm_DslProtocolStateType;

typedef enum {
	DCM_DSL_PDUR_DCM_IDLE = 0,

	DCM_DSL_PDUR_TRANSMIT_INDICATED = 1,
	DCM_DSL_PDUR_TRANSMIT_TX_BUFFER_PROVIDED = 2,

	DCM_DSL_RECEPTION_INDICATED = 3,
	DCM_DSL_RX_BUFFER_PROVIDED = 4
} Dcm_DslPdurCommuncationState;


// This buffer is used for implement 7.2.4.3 (Concurrent "tester present").

#define DCM_DSL_LOCAL_BUFFER_LENGTH 8

typedef struct {
	Dcm_DslBufferUserType	status;
	uint8_t					buffer[DCM_DSL_LOCAL_BUFFER_LENGTH];
	PduLengthType			messageLenght;
	PduInfoType				PduInfo;
	PduLengthType			nofBytesHandled;
	Dcm_NegativeResponseCodeType responseCode;
	PduIdType 				DcmRxPduId; //The local buffer is locked to this PDU id
} Dcm_DslLocalBufferType;


typedef struct {
	PduIdType				diagReqestRxPduId;  // Tester request PduId.
	uint32_t					stateTimeoutCount; // Counter for timeout.
	Dcm_DslBufferUserType	externalRxBufferStatus;
	PduInfoType				diagnosticRequestFromTester;
	PduInfoType				diagnosticResponseFromDsd;
	Dcm_DslBufferUserType	externalTxBufferStatus;
	boolean					protocolStarted; // Has the protocol been started?
	Dcm_DslLocalBufferType	localRxBuffer;
	Dcm_DslLocalBufferType	localTxBuffer;
	boolean					diagnosticActiveComM; //
	uint16_t					S3ServerTimeoutCount;
	boolean					S3ServerStarted;
	uint8_t					responsePendingCount;
	Dcm_SecLevelType		securityLevel;
	Dcm_SesCtrlType			sessionControl;
	//Dcm_DslLocalBufferType  PeriodicTxBuffer;
	//uint16_t					preemptTimeoutCount;
	PduIdType               diagResponseTxPduId;
	boolean                 isType2Tx;
} Dcm_DslRunTimeProtocolParametersType;

// 10.2.10
struct Dcm_DslProtocolRowType_t { // Cross referenced from Dcm_DslConnectionType_t.
	Dcm_ProtocolType						DslProtocolID; // (1)
	boolean									DslProtocolIsParallelExecutab; // (1)
	uint16_t									DslProtocolPreemptTimeout; // (1)
	uint8_t									DslProtocolPriority; // (1)
	Dcm_ProtocolTransTypeType				DslProtocolTransType; // (1)
	const Dcm_DslBufferType					*DslProtocolRxBufferID; // (1)
	const Dcm_DslBufferType					*DslProtocolTxBufferID; // (1)
	const Dcm_DsdServiceTableType			*DslProtocolSIDTable; // (1)
	const Dcm_DslProtocolTimingRowType		*DslProtocolTimeLimit; // (0..1)
	// Containers
	const Dcm_DslConnectionType				*DslConnection; // (1..*)
	// Reference to runtime parameters to this protocol.
	Dcm_DslRunTimeProtocolParametersType	*DslRunTimeProtocolParameters; // Maybe this needs to change to index.
	boolean									Arc_EOL;
};

// 10.2.9
typedef struct {
	// Containers
	const Dcm_DslProtocolRxType		*DslProtocolRxGlobalList;	// (1..*)  A polite list for all RX protocol configurations.
	const Dcm_DslProtocolTxType		*DslProtocolTxGlobalList;	// (1..*)  A polite list for all TX protocol configurations.
	const Dcm_DslPeriodicTxType     *DslProtocolPeriodicTxGlobalList;
	const Dcm_DslProtocolRowType	*DslProtocolRowList;		// (1..*)
} Dcm_DslProtocolType;

// 10.2.19
typedef struct {
	Dcm_CallbackNotificationIndicationFncType	Indication;
	Dcm_CallbackNotificationConfirmationFncType Confirmation;
	boolean							Arc_EOL;
} Dcm_DslServiceRequestNotificationType; /** @req DCM681 */

// 10.2.20
typedef struct {
	Dcm_CallbackGetSesChgPermissionFncType	GetSesChgPermission;
	Dcm_CallbackChangeIndicationFncType		ChangeIndication;
	Dcm_CallbackConfirmationRespPendFncType	ConfirmationRespPend;
	boolean									Arc_EOL;
} Dcm_DslSessionControlType; /** @req DCM680 */

// 10.2.5
typedef struct {
	// Containers
	const Dcm_DslBufferType						*DslBuffer;						// (1..256)
	const Dcm_DslCallbackDCMRequestServiceType	*DslCallbackDCMRequestService;	// (1..*)
	const Dcm_DslDiagRespType					*DslDiagResp;					// (1)
	const Dcm_DslProtocolType					*DslProtocol;					// (1)
	const Dcm_DslProtocolTimingType				*DslProtocolTiming;				// (1)
	//const Dcm_DslServiceRequestNotificationType	*DslServiceRequestNotification;	// (0..*)
	const Dcm_DslSessionControlType				*DslSessionControl;				// (1..*)
} Dcm_DslType;

// 10.2.1 Dcm
typedef struct {
	// Containers
	const Dcm_DspType *Dsp; //	(1)
	const Dcm_DsdType *Dsd; //	(1)
	const Dcm_DslType *Dsl; //	(1)
} Dcm_ConfigType;

/*
 * Make the Dcm_ConfigPtr visible for others.
 */


extern const Dcm_ConfigType *Dcm_ConfigPtr;


#endif /*DCM_LCFG_H_*/

