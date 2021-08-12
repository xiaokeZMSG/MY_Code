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








#ifndef DCM_H_
#define DCM_H_

#include "Modules.h"




#define DCM_AR_RELEASE_MAJOR_VERSION   		4
#define DCM_AR_RELEASE_MINOR_VERSION   		0
#define DCM_AR_RELEASE_REVISION_VERSION		3


#define DCM_MODULE_ID			MODULE_ID_DCM /** @req DCM052 */
#define DCM_VENDOR_ID			VENDOR_ID_ARCCORE

#define DCM_SW_MAJOR_VERSION    3
#define DCM_SW_MINOR_VERSION   	0
#define DCM_SW_PATCH_VERSION    0
#define DCM_AR_MAJOR_VERSION    DCM_AR_RELEASE_MAJOR_VERSION
#define DCM_AR_MINOR_VERSION    DCM_AR_RELEASE_MINOR_VERSION
#define DCM_AR_PATCH_VERSION    DCM_AR_RELEASE_REVISION_VERSION

#include "Dcm_Types.h"
#include "Dcm_Cfg.h"
#include "Dcm_Lcfg.h"
#include "ComStack_Types.h"
#include "Dcm_Cbk.h"
#include "Dem_Types.h"

#if (DCM_DEV_ERROR_DETECT == STD_ON)
// Error codes produced by this module defined by Autosar
#define DCM_E_INTERFACE_TIMEOUT				0x01
#define DCM_E_INTERFACE_VALUE_OUT_OF_RANGE	0x02
#define DCM_E_INTERFACE_BUFFER_OVERFLOW		0x03
#define DCM_E_INTERFACE_PROTOCOL_MISMATCH	0x04
#define DCM_E_UNINIT						0x05
#define DCM_E_PARAM							0x06

// Other error codes reported by this module
#define DCM_E_CONFIG_INVALID				0x40
#define DCM_E_TP_LENGTH_MISMATCH			0x50
#define DCM_E_UNEXPECTED_RESPONSE           0x60
#define DCM_E_UNEXPECTED_EXECUTION          0x61
#define DCM_E_NOT_SUPPORTED					0xfe
#define DCM_E_NOT_IMPLEMENTED_YET			0xff

// Service IDs in this module defined by Autosar
#define DCM_START_OF_RECEPTION_ID			0x00
#define DCM_INIT_ID							0x01
#define DCM_COPY_RX_DATA_ID					0x02
#define DCM_TP_RX_INDICATION_ID				0x03
#define DCM_COPY_TX_DATA_ID					0x04
#define DCM_TP_TX_CONFIRMATION_ID			0x05
#define DCM_GET_SES_CTRL_TYPE_ID			0x06
#define DCM_GET_SECURITY_LEVEL_ID			0x0d
#define DCM_GET_ACTIVE_PROTOCOL_ID			0x0f
#define DCM_COMM_NO_COM_MODE_ENTERED_ID		0x21
#define DCM_COMM_SILENT_COM_MODE_ENTERED_ID	0x22
#define DCM_COMM_FULL_COM_MODE_ENTERED_ID	0x23
#define DCM_MAIN_ID							0x25

// Other service IDs reported by this module
#define DCM_HANDLE_RESPONSE_TRANSMISSION_ID	0x80
#define DCM_UDS_READ_DTC_INFO_ID			0x81
#define DCM_UDS_RESET_ID					0x82
#define DCM_UDS_COMMUNICATION_CONTROL_ID    0x83
#define DCM_CHANGE_DIAGNOSTIC_SESSION_ID	0x88
#define DCM_GLOBAL_ID						0xff

#endif


/*
 * Interfaces for BSW components (8.3.1)
 */
#if ( DCM_VERSION_INFO_API == STD_ON ) /** @req DCM337 */
#define Dcm_GetVersionInfo(_vi) STD_GET_VERSION_INFO(_vi,DCM) /** @req DCM065 */ /** @req DCM335 */ /** @req DCM336 */
#endif /* DCM_VERSION_INFO_API */

void Dcm_Init( const Dcm_ConfigType *ConfigPtr ); /** @req DCM037 */


/*
 * Interfaces for BSW modules and to SW-Cs (8.3.2)
 */
Std_ReturnType Dcm_GetSecurityLevel(Dcm_SecLevelType *secLevel); /** @req DCM338 */
Std_ReturnType Dcm_GetSesCtrlType(Dcm_SesCtrlType *sesCtrlType); /** @req DCM339 */
//Std_ReturnType Dcm_GetActiveProtocol(Dcm_ProtocolType *activeProtocol); /** @req DCM340 */
Std_ReturnType Dcm_UdsRequestDTC(uint8_t ecu_id,uint8_t subfunc,uint8_t *pDTC,uint8_t mask);

/*
 * Interface for basic software scheduler (8.5)
 */
void Dcm_MainFunction( void ); /** @req DCM053 */
Std_ReturnType Dcm_CallbackStartProtocolFnc(Dcm_ProtocolType protocolID);

/*
 * Dcm callouts.
 */
Dcm_ReturnWriteMemoryType 	Dcm_WriteMemory(Dcm_OpStatusType OpStatus, uint8_t MemoryIdentifier, uint32_t MemoryAddress, uint32_t MemorySize, uint8_t* MemoryData);
Dcm_ReturnReadMemoryType 	Dcm_ReadMemory(Dcm_OpStatusType OpStatus, uint8_t MemoryIdentifier, uint32_t MemoryAddress, uint32_t MemorySize, uint8_t* MemoryData);
void 						Dcm_DiagnosticSessionControl(Dcm_SesCtrlType session);
Std_ReturnType 				DcmE_EcuReset(Dcm_EcuResetType resetType);
void 						DcmE_EcuPerformReset(Dcm_EcuResetType resetType);
void 						Dcm_E_CommunicationControl(uint8_t subFunction, uint8_t communicationType, Dcm_NegativeResponseCodeType *responseCode );
void Mcu_PerformReset();


void DFlash_default_check();
void DFlash_backup_check();


void Dcm_AppInit(unsigned char offset);
uint8_t Write_IHU_Made_date();
uint8_t Write_Factory_Diag_Veh_Type(void);

Std_ReturnType Read_DidConditionCheckReadFnc(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *errorCode);

Std_ReturnType Read_DidReadDataFnc_0200(uint8_t *data);
Std_ReturnType Write_DidWriteDataFnc_0200(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode);

Std_ReturnType Read_DidReadDataFnc_0201(uint8_t *data);
Std_ReturnType Write_DidWriteDataFnc_0201(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode);

Std_ReturnType Read_DidReadDataFnc_DF00(uint8_t *data);
Std_ReturnType Write_DidWriteDataFnc_DF00(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode);

Std_ReturnType Read_DidReadDataFnc_DF01(uint8_t *data);
Std_ReturnType Write_DidWriteDataFnc_DF01(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode);

Std_ReturnType Read_DidReadDataFnc_F101(uint8_t *data);
Std_ReturnType Write_DidWriteDataFnc_F101(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode);

Std_ReturnType Read_DidReadDataFnc_F110(uint8_t *data);
Std_ReturnType Write_DidWriteDataFnc_F110(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode);

Std_ReturnType Read_DidReadDataFnc_F112(uint8_t *data);
Std_ReturnType Write_DidWriteDataFnc_F112(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode);



Std_ReturnType Read_DidReadDataFnc_F187(uint8_t *data);
Std_ReturnType Read_DidReadDataFnc_F189(uint8_t *data);
Std_ReturnType Read_DidReadDataFnc_F18A(uint8_t *data);
Std_ReturnType Read_DidReadDataFnc_F18C(uint8_t *data);
Std_ReturnType Write_DidWriteDataFnc_F18C(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode);
Std_ReturnType Read_DidReadDataFnc_F190(uint8_t *data);
Std_ReturnType Write_DidWriteDataFnc_F190(uint8_t *data,   Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode);
Std_ReturnType Read_DidReadDataFnc_F191(uint8_t *data);
Std_ReturnType Write_DidWriteDataFnc_F191(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode);
Std_ReturnType Read_DidReadDataFnc_F193(uint8_t *data);
Std_ReturnType Read_DidReadDataFnc_F195(uint8_t *data);
Std_ReturnType Read_DidReadDataFnc_F19D(uint8_t *data);
Std_ReturnType Write_DidWriteDataFnc_F19D(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode);



Std_ReturnType Read_DidReadDataFnc_F1FA(uint8_t *data);
Std_ReturnType Read_DidReadDataFnc_F1FB(uint8_t *data);
Std_ReturnType Read_DidReadDataFnc_F120(uint8_t *data);
Std_ReturnType Read_DidReadDataFnc_F121(uint8_t *data);
Std_ReturnType Read_DidReadDataFnc_F122(uint8_t *data);


Std_ReturnType Read_DidReadDataFnc_F010(uint8_t *data);


Std_ReturnType Write_DidConditionCheckWriteFnc(Dcm_NegativeResponseCodeType *errorCode);




Std_ReturnType Write_DidWriteDataFnc_F1FA(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode);
Std_ReturnType Write_DidWriteDataFnc_F1FB(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode);


Std_ReturnType Write_DidWriteDataFnc_F010(uint8_t *data,   Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode);

Std_ReturnType Read_DidReadDataFnc_DF00(uint8_t *data);
Std_ReturnType Read_DidReadDataFnc_DF01(uint8_t *data);
Std_ReturnType Read_DidReadDataFnc_DF02(uint8_t *data);
Std_ReturnType Read_DidReadDataFnc_DF03(uint8_t *data);
Std_ReturnType Read_DidReadDataFnc_DF04(uint8_t *data);

Std_ReturnType Read_DidReadDataFnc_7960(uint8_t *data);


Std_ReturnType Ctrl_DidReturnControlToEcuFnc_7960(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *errorCode);
Std_ReturnType Ctrl_DidShortTermAdjustmentFnc_7960(uint8_t *controlOptionRecord, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *errorCode);



Std_ReturnType SecurityAccessGetSeed(Dcm_OpStatusType OpStatus, unsigned char *seed, unsigned char *errorCode);
Std_ReturnType SecurityAccessCompareKey(const uint8_t *key);

#endif /*DCM_H_*/
