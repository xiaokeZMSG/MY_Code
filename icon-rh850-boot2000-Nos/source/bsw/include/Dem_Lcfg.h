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
/** @req DEM128 */



#ifndef DEM_LCFG_H_
#define DEM_LCFG_H_
#include "Dem_Types.h"
#if defined(USE_DCM)
#include "Dcm_Types.h"	 /** @req DEM176.Dcm */
#include "Dcm_Lcfg.h"    	 /** @req DEM136.Dcm */
#endif

#if defined(USE_NVM)
#include "NvM_ConfigTypes.h"	 /** @req Dem147.Nvm */
#endif

#define 	DEM_MAX_RECORD_NUMBERS_IN_FF_REC_NUM_CLASS 	4
#if 1
#define 	DEM_MAX_SIZE_FF_DATA				5//NO Did 
#else
#define  	DEM_MAX_SIZE_FF_DATA 						12//with did data
#endif
#define 	DEM_DID_IDENTIFIER_SIZE_OF_BYTES 			2
#define  	DEM_FREEZEFRAME_DEFAULT_VALUE 				0
#define   	DEM_MAX_NR_OF_DIDS_IN_FREEZEFRAME_DATA 		1// 3

#define 	DEM_FREEZEFRAM_MAX_DATA 		(DEM_MAX_SIZE_FF_DATA+DEM_MAX_NR_OF_DIDS_IN_FREEZEFRAME_DATA*2)

#define 	DEM_HIGHEST_FF_REC_NUM 						2
#define 	DEM_HIGHEST_EXT_DATA_REC_NUM 				8
#define 	DEM_MAX_NR_OF_PIDS_IN_FREEZEFRAME_DATA 		8
#define     DEM_FREEZE_FRAME_CAPTURE_TESTFAILED
#define     DEM_EXTENDED_DATA_CAPTURE_TESTFAILED

#define     DEM_ENABLE_CONDITION_SUPPORT STD_ON  /*STD_ON*/
#define     DEM_FLASH_STORE_ON_END STD_ON

#define    DEM_HEALING_CYCLE_COUNTER 100

/*
 * Callback function prototypes
 */

// ClearEventAllowed
typedef Std_ReturnType (*Dem_CallbackClearEventAllowedFncType)(boolean *Allowed); /* @req DEM563 */

// EventDataChanged
typedef void (*Dem_CallbackEventDataChangedFncTypeWithId)(Dem_EventIdType EventId);/* @req DEM562 */
typedef void (*Dem_CallbackEventDataChangedFncTypeWithoutId)(void);

typedef union {
    Dem_CallbackEventDataChangedFncTypeWithId 	eventDataChangedWithId;
    Dem_CallbackEventDataChangedFncTypeWithoutId eventDataChangedWithoutId;
}Dem_CallbackEventDataChangedFncType;

typedef struct {
    boolean UsePort;
    Dem_CallbackEventDataChangedFncType CallbackEventDataChangedFnc;
}Dem_CallbackEventDataChangedType;

// InitMonitorForEvent
typedef Std_ReturnType (*Dem_CallbackInitMonitorForEventFncType)(Dem_InitMonitorReasonType InitMonitorReason); /** @req DEM256 */

// InitMonitorForFunction
typedef Std_ReturnType (*Dem_CallbackInitMonitorForFunctionFncType)(void); /** @req DEM258 */

// EventStatusChanged
typedef void (*Dem_CallbackEventStatusChangedFncTypeWithId)(Dem_EventIdType EventId, Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew); /** @req DEM259 */
typedef void (*Dem_CallbackEventStatusChangedFncTypeWithoutId)(Dem_EventStatusExtendedType EventStatusOld, Dem_EventStatusExtendedType EventStatusNew); /** @req DEM259 */

typedef union {
    Dem_CallbackEventStatusChangedFncTypeWithId eventStatusChangedWithId;
    Dem_CallbackEventStatusChangedFncTypeWithoutId eventStatusChangedWithoutId;
}Dem_CallbackEventStatusChangedFncType;

// DTCStatusChanged
typedef Std_ReturnType (*Dem_CallbackDTCStatusChangedFncType)(uint8_t DTCStatusOld, uint8_t DTCStatusNew); /** @req DEM260 */

// DIDServices /** @req DEM261 */
#if defined(USE_DCM)
typedef Std_ReturnType (*Dem_CallbackConditionCheckReadFncType)(Dcm_NegativeResponseCodeType *Nrc);
typedef Std_ReturnType (*Dem_CallbackReadDataFncType)(uint8 *Data);
typedef Std_ReturnType (*Dem_CallbackReadDataLength)(uint16 *DidLength);
#else
typedef Std_ReturnType (*Dem_CallbackConditionCheckReadFncType)(uint8_t *Nrc);
typedef Std_ReturnType (*Dem_CallbackReadDataFncType)(uint8_t *Data);
typedef Std_ReturnType (*Dem_CallbackReadDataLength)(uint16_t *DidLength);
#endif

// GetExtendedDataRecord
typedef Std_ReturnType (*Dem_CallbackGetExtDataRecordFncType)(uint8_t *ExtendedDataRecord); /** @req DEM262 */

// GetFaultDetectionCounter
typedef Std_ReturnType (*Dem_CallbackGetFaultDetectionCounterFncType)(int8_t *EventIdFaultDetectionCounter); /** @req DEM263 */

// GetPIDValue
typedef Std_ReturnType (*Dem_CallbackGetPIDValueFncType)(uint8_t *DataValueBuffer); /** @req DEM326 */

typedef enum {
	DEM_NO_ELEMENT,
	DEM_OCCCTR,
	DEM_PENDINGCNT,
	DEM_FAULTDETCTR,
	DEM_MAXFAULTDETCTR,
	DEM_CONFIRMATIONCNTR,
	DEM_AGED,
	DEM_AGING,
} Dem_InternalDataElementType;

typedef enum {
	DEM_UPDATE_RECORD_NO,
	DEM_UPDATE_RECORD_YES,
	DEM_UPDATE_RECORD_VOLATILE,
} Dem_UpdateRuleType;
/*
 * DemGeneral types
 */
/** @req DEM128 */

// 10.2.25 DemEnableCondition
typedef struct {
	boolean EnableConditionStatus;		//
	uint8_t	EnableConditionID;		// Optional
} Dem_EnableConditionType;

typedef struct {
    uint8_t nofEnableConditions;
    const Dem_EnableConditionType **EnableCondition;
}Dem_EnableConditionGroupType;

// 10.2.30 DemExtendedDataRecordClass
typedef struct {
	uint16_t				RecordNumber;						// (1)
	uint16_t				DataSize;							// (1)
	Dem_UpdateRuleType 	UpdateRule;
	Dem_CallbackGetExtDataRecordFncType	CallbackGetExtDataRecord;// (1)  /** @req DEM139 */
	Dem_InternalDataElementType InternalDataElement;
} Dem_ExtendedDataRecordClassType; /** @req DEM135 */

// 10.2.13 DemExtendedDataClass
typedef struct {
	const Dem_ExtendedDataRecordClassType *const ExtendedDataRecordClassRef[DEM_MAX_NR_OF_RECORDS_IN_EXTENDED_DATA+1]; // (1..253)
} Dem_ExtendedDataClassType; /** @req DEM135 */

// 10.2.8 DemPidOrDid
typedef struct {
	Dem_CallbackConditionCheckReadFncType		DidConditionCheckReadFnc;	// (0..1)
	const uint16_t								DidIdentifier;				// (0..1)
	Dem_CallbackReadDataLength				DidReadDataLengthFnc;		// (0..1)
	Dem_CallbackReadDataFncType				DidReadFnc;					// (0..1)
	const uint8_t								PidIdentifier;				// (0..1)
	uint8_t									PidOrDidSize;				// (1)
	boolean									PidOrDidUsePort;			// (1) Not used in current implementation	
	Dem_CallbackGetPIDValueFncType			PidReadFnc;					// (0..1)
	boolean									Arc_EOL;
} Dem_PidOrDidType; /** @req DEM136 */

// 10.2.18 DemFreezeFrameClass
typedef struct {
	Dem_FreezeFrameKindType FFKind;			// (1)
	const Dem_PidOrDidType 	**FFIdClassRef; 	// (1..255)/** @req DEM039 */
} Dem_FreezeFrameClassType; /** @req DEM136 */


// 10.2.4 DemIndicator
typedef struct {
	uint16_t	Indicator;		// (1)
} Dem_IndicatorType; /** @req DEM129 */


/*
 * DemConfigSetType types
 */

// 10.2.6 DemCallbackDTCStatusChanged
typedef struct {
	Dem_CallbackDTCStatusChangedFncType CallbackDTCStatusChangedFnc;	// (0..1)
} Dem_CallbackDTCStatusChangedType; /** @req DEM140 */

// 10.2.26 DemCallbackInitMForF
typedef struct {
	Dem_CallbackInitMonitorForFunctionFncType	CallbackInitMForF;		// (0..1)
} Dem_CallbackInitMForFType;

// 10.2.17 DemDTCClass
typedef struct {
	uint32_t									DTC;						// (1)
	uint8_t									DTCFunctionalUnit;			// (1)
	Dem_DTCKindType							DTCKind;					// (1)
	const Dem_CallbackDTCStatusChangedType	*CallbackDTCStatusChanged;	// (0..*)
	const Dem_CallbackInitMForFType			*CallbackInitMForF;			// (0..*)
	// Dem_DTCSeverityType					DTCSeverity					// (0..1)  Optional
	boolean									Arc_EOL;
} Dem_DTCClassType; /** @req DEM132 */

// 10.2.5 DemCallbackEventStatusChanged
typedef struct {
	Dem_CallbackEventStatusChangedFncType	CallbackEventStatusChangedFnc;	// (0..1)
	boolean UsePort;
	boolean Arc_EOL;
} Dem_CallbackEventStatusChangedType; /** @req DEM140 */

// 10.2.27 DemCallbackInitMForE
//typedef struct {
//	Dem_CallbackInitMonitorForEventFncType	CallbackInitMForEFnc;	// (0..1)
//} Dem_CallbackInitMforEType; /** @req DEM130 */

// 10.2.15
typedef struct {
	Dem_IndicatorStatusType	IndicatorBehaviour;			// (1)
	Dem_IndicatorType		*LinkedIndicator;			// (1)
} Dem_IndicatorAttributeType; /** @req DEM133 */

// 10.2.23 DemPreDebounceMonitorInternal
typedef struct {
	Dem_CallbackGetFaultDetectionCounterFncType	CallbackGetFDCntFnc;	// (1)
} Dem_PreDebounceMonitorInternalType; /** @req DEM146 */

// 10.2.21 DemPreDebounceCounterBased
typedef struct {
	boolean	JumpUp;
	boolean	JumpDown;
	uint16_t	IncrementStepSize;
	uint16_t	DecrementStepSize;
    int16_t  JumpDownValue;
    int16_t  JumpUpValue;
    int16_t  FailedThreshold;
    int16_t  PassedThreshold;

} Dem_PreDebounceCounterBasedType; /** @req DEM144 */

// 10.2.22 DemPreDebounceFrequencyBased
typedef uint8_t Dem_PreDebounceFrequencyBasedType;

// 10.2.24 DemPreDebounceTimeBased
typedef uint8_t Dem_PreDebounceTimeBasedType;

// 10.2.20
typedef struct {
	Dem_PreDebounceNameType						PreDebounceName;				// (1)
	union {
	const Dem_PreDebounceMonitorInternalType	*PreDebounceMonitorInternal;	// (0..1)
	const Dem_PreDebounceCounterBasedType		*PreDebounceCounterBased;		// (0..1)
	const Dem_PreDebounceFrequencyBasedType		*PreDebounceFrequencyBased;		// (0..1)
	const Dem_PreDebounceTimeBasedType			*PreDebounceTimeBased;			// (0..1)
	} PreDebounceAlgorithm;
} Dem_PreDebounceAlgorithmClassType;

// 10.2.14 DemEventClass
typedef struct {
	boolean						ConsiderPtoStatus;									// (1)
	Dem_DTCOriginType 		    EventDestination;                                   // (1 Arcore specific)
	uint8_t						EventPriority;										// (1)
	boolean						FFPrestorageSupported;								// (1)
	boolean						HealingAllowed;										// (1)
	Dem_OperationCycleIdType	OperationCycleRef;									// (1)
	Dem_OperationCycleIdType	HealingCycleRef;									// (1)
	Dem_OperationCycleIdType    ConfirmationCycleRef;                               // (1)
	uint8_t                       ConfirmationCycleCounterThreshold;                  // (1)
	uint8_t						HealingCycleCounter;									// (0..1) Optional
	const Dem_EnableConditionGroupType	*EnableConditionGroupRef;							// (0..*) Optional
	const Dem_PreDebounceAlgorithmClassType	*PreDebounceAlgorithmClass;				// (0..255) (Only 0..1 supported)
	const Dem_IndicatorAttributeType		*IndicatorAttribute;					// (0..255)
//	Dem_OEMSPecific
} Dem_EventClassType; /** @req DEM131 */

typedef struct
{
	uint8_t	FreezeFrameRecordNumber[DEM_MAX_RECORD_NUMBERS_IN_FF_REC_NUM_CLASS + 1];
}Dem_FreezeFrameRecNumClass;

// 10.2.12 DemEventParameter
typedef struct {
	uint16_t										EventID;					// (1)
	Dem_EventKindType							EventKind;					// (1)
	uint8_t										MaxNumberFreezeFrameRecords;// (1)
	const Dem_EventClassType					*EventClass;				// (1)
	const Dem_ExtendedDataClassType				*ExtendedDataClassRef;		// (0..1)
	const Dem_FreezeFrameClassType				*FreezeFrameClassRef; 		// (0..1) (Only 0..1 supported)/** @req DEM021 */
	const Dem_CallbackInitMonitorForEventFncType CallbackInitMforE;			// (0..1)
	const Dem_CallbackEventStatusChangedType	*CallbackEventStatusChanged;// (0..)
	const Dem_CallbackClearEventAllowedFncType  CallbackClearEventAllowed; // (0..1)
	const Dem_CallbackEventDataChangedType      *CallbackEventDataChanged;  // (0..1)
	const Dem_DTCClassType						*DTCClassRef;				// (0..1)
	const Dem_FreezeFrameRecNumClass			*FreezeFrameRecNumClassRef; // (1)
	boolean										Arc_EOL;
} Dem_EventParameterType; /** @req DEM130 */



// 10.2.19 DemGroupOfDTC
typedef uint8_t Dem_GroupOfDtcType;

// 10.2.10 DemOemIdClass
typedef struct {
	uint8_t	OemID;
} Dem_OemIdClassType; /** @req DEM141 */

// 10.2.9 DemConfigSet
typedef struct {
	const Dem_EventParameterType	*EventParameter;	// (0..65535)
	const Dem_DTCClassType 			*DTCClass;			// (1..16777214)
	const Dem_GroupOfDtcType		*GroupOfDtc;		// (1.16777214)
	const Dem_OemIdClassType		*OemIdClass;		// (0..*)
	const Dem_EnableConditionType   *EnableCondition;
	const Dem_FreezeFrameClassType  *GlobalOBDFreezeFrameClassRef;
} Dem_ConfigSetType; /** @req DEM130 */

// 10.2.2 Dem
typedef struct {
	const Dem_ConfigSetType *ConfigSet;	//	(1)
} Dem_ConfigType;

typedef struct {/*add by mgd on 20210715*/
	uint8_t        ECUVoltage;
	uint8_t        VehicleSpeed[2];
	uint8_t        OccurrenceCounter ; 
	uint8_t        TheOdometerOfFirstMalfunction[3];
	uint8_t        TheOdometerOfLastMalfunction[3];
} FreezeFrameRecSnapshot;

typedef struct {
	Dem_EventIdType         eventId;
	Dem_FreezeFrameKindType kind;
	uint8_t                  dataSize;//max 5byte
	uint8_t                   recordNumber;
#if (DEM_EVENT_DISPLACEMENT_SUPPORT == STD_ON) && !defined(DEM_EVENT_DISPLACEMENT_STRATEGY_EXTENSION)
    uint32_t                  timeStamp;
#endif
  union{/*modify by mgd on 20210715*/
	uint8_t                data[DEM_MAX_SIZE_FF_DATA];
	FreezeFrameRecSnapshot Snapshot;/*modify by mgd on 20210715*/
  	}data;
} FreezeFrameRecType;

typedef struct
{
	uint16_t DID;
	uint8_t	length;
}Snapshot_Type;
// Types for storing different event aging counter
typedef struct {
	Dem_EventIdType		eventId;
	uint8_t				agingCounter;/** @req Dem019 */
#if 1
	uint8_t				agedCounter;/** @req Dem019 *///max = 40 in NL-3
#else
	uint32_t				agedCounter;/** @req Dem019 */
#endif
} HealingRecType;

/*
 * Make the DEM_Config visible for others.
 */
//extern const Dem_ConfigType DEM_Config;

#endif /*DEM_LCFG_H_*/
