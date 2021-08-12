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
 * NB! This file is for DCM internal use only and may only be included from DCM C-files!
 */



#ifndef DCM_INTERNAL_H_
#define DCM_INTERNAL_H_

#include "Dcm.h"
#include "CanTp.h"

#if defined(DCM_USE_SERVICE_INPUTOUTPUTCONTROLBYIDENTIFIER) && (0 < DCM_NOF_IOCONTROL_DIDS)
#define DCM_USE_CONTROL_DIDS
#endif

#if  ( DCM_DEV_ERROR_DETECT == STD_ON )
#if defined(USE_DET)
#include "Det.h"
#endif


#define DCM_DET_REPORTERROR(_api,_err)                              \
    do {                                                            \
        (void)Det_ReportError(MODULE_ID_DCM, 0, _api, _err);    \
    } while(0)

#else

#define DCM_DET_REPORTERROR(_api,_err)

#endif

#define VALIDATE(_exp,_api,_err ) \
        if( !(_exp) ) { \
          DCM_DET_REPORTERROR(_api, _err); \
          return E_NOT_OK; \
        }

#define VALIDATE_RV(_exp,_api,_err,_rv ) \
        if( !(_exp) ) { \
          DCM_DET_REPORTERROR(_api, _err); \
          return _rv; \
        }

#define VALIDATE_NO_RV(_exp,_api,_err ) \
  if( !(_exp) ) { \
          DCM_DET_REPORTERROR(_api, _err); \
          return; \
        }
        
#define IS_PERIODIC_TX_PDU(_x) (((_x) >= DCM_FIRST_PERIODIC_TX_PDU) && ((_x) < (DCM_FIRST_PERIODIC_TX_PDU + DCM_NOF_PERIODIC_TX_PDU)))
#define TO_INTERNAL_PERIODIC_PDU(_x) ((_x) - DCM_FIRST_PERIODIC_TX_PDU)

// SID table
#define SID_DIAGNOSTIC_SESSION_CONTROL			0x10
#define SID_ECU_RESET							0x11
#define SID_CLEAR_DIAGNOSTIC_INFORMATION		0x14
#define SID_READ_DTC_INFORMATION				0x19
#define SID_READ_DATA_BY_IDENTIFIER				0x22
#define SID_READ_MEMORY_BY_ADDRESS				0x23
#define SID_READ_SCALING_DATA_BY_IDENTIFIER		0x24
#define SID_SECURITY_ACCESS						0x27
#define SID_COMMUNICATION_CONTROL               0x28
#define SID_READ_DATA_BY_PERIODIC_IDENTIFIER	0x2A
#define SID_DYNAMICALLY_DEFINE_DATA_IDENTIFIER	0x2C
#define SID_WRITE_DATA_BY_IDENTIFIER			0x2E
#define SID_INPUT_OUTPUT_CONTROL_BY_IDENTIFIER	0x2F
#define SID_ROUTINE_CONTROL						0x31
#define SID_WRITE_MEMORY_BY_ADDRESS				0x3D
#define SID_TESTER_PRESENT						0x3E
#define SID_NEGATIVE_RESPONSE					0x7F
#define SID_CONTROL_DTC_SETTING					0x85

#define SID_REQUEST_DOWNLOAD					0x34
#define SID_REQUEST_UPLOAD						0x35
#define SID_TRANSFER_DATA						0x36
#define SID_REQUEST_TRANSFER_EXIT				0x37

//#define SID_OBD_RESP_CURRENT_POWERTRAIN_DIAGNOSTIC_DATA				0x41
//#define SID_OBD_RESP_POWERTRAIN_FREEZE_FRAME_DATA				    0x42
//#define SID_OBD_RESP_EMISSION_RELATED_DIAGNOSTIC_TROUBLE_CODES	    0x43
//#define SID_OBD_RESP_CLEAR_EMISSION_RELATED_DIAGNOSTIC_INFORMATION	    0x44
//#define SID_OBD_RESP_EMISSION_RELATED_DIAGNOSTIC_TROUBLE_CODES_DETECTED_DURING_CURRENT_OR_LAST_COMPLETED_DRIVING_CYCLE	    0x47
//#define SID_OBD_RESP_VEHICLE_INFORMATION	    0x49
//#define SID_UDS_RESP_READ_DTC	    0x59


//OBD SID TABLE
#define SID_REQUEST_CURRENT_POWERTRAIN_DIAGNOSTIC_DATA		0x01
#define SID_REQUEST_POWERTRAIN_FREEZE_FRAME_DATA			0x02
#define SID_CLEAR_EMISSION_RELATED_DIAGNOSTIC_INFORMATION	0x04
#define SID_REQUEST_EMISSION_RELATED_DIAGNOSTIC_TROUBLE_CODES		0x03
#define SID_REQUEST_EMISSION_RELATED_DIAGNOSTIC_TROUBLE_CODES_DETECTED_DURING_CURRENT_OR_LAST_COMPLETED_DRIVING_CYCLE	0x07
#define SID_REQUEST_VEHICLE_INFORMATION		0x09
#define SID_REQUEST_VEHICLE_DTC		0x19

// Misc definitions
#define SUPPRESS_POS_RESP_BIT		(uint8_t)0x80
#define SID_RESPONSE_BIT			(uint8_t)0x40
#define VALUE_IS_NOT_USED			(uint8_t)0x00

// This diag request error code is not an error and is therefore not allowed to be used by SWCs, only used internally in DCM.
// It is therefore not defined in Rte_Dcm.h
#define DCM_E_RESPONSEPENDING       ((Dcm_NegativeResponseCodeType)0x78)

typedef enum {
	DSD_TX_RESPONSE_READY,
	DSD_TX_RESPONSE_SUPPRESSED
} DsdProcessingDoneResultType;


//extern unsigned long g_randomData;

//extern unsigned char readonlyRadioMode;

//extern unsigned char IOcontrolandreaddata_E001[2];
extern unsigned char IOcontrolandreaddata_E002[2];


extern unsigned char  Communication_Control_TX_Disabled, Communication_Control_RX_Disabled;
extern unsigned char  Vehicle_at_standstill_flag;
//extern MsgDataType msgData;

/*
 * DSP
 */
void DspInit(boolean firstCall);
void DspMain(void);
void DspPreDsdMain(void);
void DspUdsDiagnosticSessionControl(const PduInfoType *pduRxData, PduIdType txPduId, PduInfoType *pduTxData);
void DspUdsEcuReset(const PduInfoType *pduRxData, PduIdType txPduId, PduInfoType *pduTxData);
void DspUdsClearDiagnosticInformation(const PduInfoType *pduRxData, PduInfoType *pduTxData);
void DspUdsSecurityAccess(const PduInfoType *pduRxData, PduInfoType *pduTxData);
void DspUdsTesterPresent(const PduInfoType *pduRxData, PduInfoType *pduTxData);
void DspUdsReadDtcInformation(const PduInfoType *pduRxData, PduInfoType *pduTxData);
void DspUdsReadDataByIdentifier(const PduInfoType *pduRxData, PduInfoType *pduTxData);
void DspUdsReadScalingDataByIdentifier(const PduInfoType *pduRxData, PduInfoType *pduTxData);
void DspUdsWriteDataByIdentifier(const PduInfoType *pduRxData, PduInfoType *pduTxData);
void DspUdsControlDtcSetting(const PduInfoType *pduRxData, PduInfoType *pduTxData);
void DspUdsRoutineControl(const PduInfoType *pduRxData, PduInfoType *pduTxData);
void DspDcmConfirmation(PduIdType confirmPduId);
void DspUdsReadMemoryByAddress(const PduInfoType *pduRxData, PduInfoType *pduTxData);
void DspUdsWriteMemoryByAddress(const PduInfoType *pduRxData, PduInfoType *pduTxData);
void DspReadDataByPeriodicIdentifier(const PduInfoType *pduRxData,PduInfoType *pduTxData, PduIdType rxPduId, Dcm_ProtocolTransTypeType txType, boolean internalRequest);
void DspDynamicallyDefineDataIdentifier(const PduInfoType *pduRxData,PduInfoType *pduTxData);
void DspIOControlByDataIdentifier(const PduInfoType *pduRxData,PduInfoType *pduTxData);
void DcmDspResetDiagnosticActivity(void);
void DspResetDiagnosticActivityOnSessionChange(Dcm_SesCtrlType newSession);
void DspCommunicationControl(const PduInfoType *pduRxData,PduInfoType *pduTxData);

boolean DspCheckSessionLevel(Dcm_DspSessionRowType const* const* sessionLevelRefTable);
boolean DspCheckSecurityLevel(Dcm_DspSecurityRowType const* const* securityLevelRefTable);
void DspCancelPendingRequests(void);

/*
 * DSD
 */
void DsdInit(void);
void DsdMain(void);
void DsdHandleRequest(void);
void DsdDspProcessingDone(Dcm_NegativeResponseCodeType responseCode);
void DsdDspProcessingDone_ReadDataByPeriodicIdentifier(Dcm_NegativeResponseCodeType responseCode, boolean supressNRC);
void DsdDataConfirmation(PduIdType confirmPduId, NotifResultType result);
void DsdDslDataIndication(const PduInfoType *pduRxData, const Dcm_DsdServiceTableType *protocolSIDTable, Dcm_ProtocolAddrTypeType addrType, PduIdType txPduId, PduInfoType *pduTxData, PduIdType rxContextPduId, Dcm_ProtocolTransTypeType txType, boolean internalRequest);
#ifdef DCM_USE_SERVICE_READDATABYPERIODICIDENTIFIER
boolean DsdDspCheckServiceSupportedInActiveSessionAndSecurity(uint8_t sid);
#endif

/*
 * DSL
 */
void              DslInit(void);
void              DslMain(void);
void              DslHandleResponseTransmission(void);
void              DslDsdProcessingDone(PduIdType rxPduIdRef, DsdProcessingDoneResultType responseResult);
void              DslGetCurrentServiceTable(const Dcm_DsdServiceTableType **currentServiceTable);

void              DslTpRxIndicationFromPduR(PduIdType dcmRxPduId, NotifResultType result, boolean internalRequest);
Std_ReturnType    DslGetActiveProtocol(Dcm_ProtocolType *protocolId);
void              DslSetSecurityLevel(Dcm_SecLevelType secLevel);
Std_ReturnType    DslGetSecurityLevel(Dcm_SecLevelType *secLevel);
void              DslSetSesCtrlType(Dcm_SesCtrlType sesCtrl);
Std_ReturnType    DslGetSesCtrlType(Dcm_SesCtrlType *sesCtrlType);
void              DslTpTxConfirmation(PduIdType dcmTxPduId, NotifResultType result);
Std_ReturnType    DslInternal_ResponseOnOneDataByPeriodicId(uint8_t PericodID, PduIdType rxPduId);
void              DslResetSessionTimeoutTimer(void);
boolean           DslPduRPduUsedForType2Tx(PduIdType pdurTxPduId, PduIdType *dcmTxPduId);

BufReq_ReturnType DslCopyDataToRxBuffer(PduIdType dcmRxPduId, PduInfoType *pduInfoPtr, PduLengthType *rxBufferSizePtr);
BufReq_ReturnType DslStartOfReception(PduIdType dcmRxPduId, PduLengthType tpSduLength, PduLengthType *rxBufferSizePtr, boolean internalRequest);
BufReq_ReturnType DslCopyTxData(PduIdType dcmTxPduId, PduInfoType *pduInfoPtr, RetryInfoType *periodData, PduLengthType *txDataCntPtr);
Std_ReturnType DspTesterRequestDTC(uint8_t ecu_id,uint8_t subfunc,uint8_t *pDTC,uint8_t mask);



#if (DCM_MANUFACTURER_NOTIFICATION == STD_ON)
void Arc_DslGetRxConnectionParams(PduIdType rxPduId, uint16* sourceAddress, Dcm_ProtocolAddrTypeType* reqType);
#endif

#endif /* DCM_INTERNAL_H_ */
