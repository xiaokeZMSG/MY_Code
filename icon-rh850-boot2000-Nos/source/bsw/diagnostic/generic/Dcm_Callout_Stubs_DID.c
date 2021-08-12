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

/* Ecum Callout Stubs - generic version */
//#include "standard.h"

#include "Dcm.h"
#if defined(USE_MCU)
#include "Mcu.h"
#endif
#include <stdlib.h>
#include <string.h>
#include "r_adc.h"
#include "Std_Types.h"

#include "Dcm_Internal.h"
//#include "RTC.h"
#include "osal_nv.h"
#include "datacenter.h"
/*F110*/ECUNetworkConfigDIDType ECUNetworkConfigDID ={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
/*F112*/ECUVecleNameType		ECUVecleName = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};//{'F','E','_','7',' ',' ',' ',' '};
/*F18B*/ECUMadeDateType 		ECUMadeDate = {0x20,0x15,0x01,0x01};

/*F19D*/ECUInstallDateType		ECUInstallDate = {0xFF,0xFF,0xFF,0xFF};//{0x20,0x13,0x05,0x10};

//for f192 
//static const uint8_t readonlysyssupplierECU_HW_NUM[16] ={'H','W',':','V','2','.','0',' ',' ',' ',' ',' ',' ',' ',' ',' '};
//for f194
//static const uint8_t readonlysyssupplierECU_SW_NUM[16] ={'S','W',':','V','0','0','.','0','2','.','0','0',' ',' ',' ',' '};

#if 1


/* F184,  7 bytes, R/W, ApplicationDataFingerprintDataIdentifier */
ECULicationDataType ECULicationDataId = {0xff,0xff,0xff,'a','a','a','a'};


/* F187, 10 bytes, R, Product Part Number */   /*8892379060*/
const EcuOEMPartNumberType 	EcuOEMPartNumber = {'8','8','9','2','3','7','9','0','6','0'};
//const EcuOEMPartNumberType 	EcuOEMPartNumber = {'7','9','0','0','S','1','1','0','0','1','A',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};

/* F189,  8 bytes, R, ECU Software Version Number(OEM) */
const ECUSoftIdType ECUSoftId = {'S','W',':','A','.','0','.','1'};

/* F18A,  6 bytes, R, System Supplier Identifier */
static const EcuVendorIDType EcuVendorID = {'H','P','0','2','1','0'};//{0xff,0xff,0xff,0xff,0xff,0xff,0xff,0XFF};

/* F18C, 24 bytes, R/W, ECU Serial Number */
ECUSerialNumType EcuSerialNum = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};

/* F190, 17 bytes, RW */
ECUVinType ECUVin = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

/* F191,  16 bytes, R, ECU HardWare Version Number(OEM) */
const uint8_t ECUHardVer[] = {'H','P','A','I','D','2','1','0','7','0','8','-','H','2','0'};

/* F193,  16 bytes, R, ECU Software Version Number(OEM) */
const uint8_t ECUSoftware[] = {'H','P','A','I','D','2','1','0','7','0','8','-','S','1','1'};


/* F1A2,  4 bytes, R,W Vehicle Manufacturing Date */
ECUManufacturingDateType EcuManufacturingDate = {0xFF,0xFF,0xFF,0xFF};


/* F1FA,  6 bytes, R,W System Function Configuration */
ECUFunctionConfigType	ECUFunctionConfig ={0x00,0x00,0x00,0x00,0X00,0X00};

/* F1FB,  2 bytes, R,W ECU Function Configuration ECU */
ECUFunctionConfig_ECU_Type	ECUFunction_ECUConfig ={0x00,0x00};


/* F120,  4 bytes, R,  NetworkInformationDataIdentifier  */
const EcuVersionsType EcuNetworkVersion = {'0','0','.','1'};

/* F121  4 bytes, R, FunctionSpecificationDataIdentifier  */
const EcuVersionsType EcuFunctionVersion = {'0','0','.','1'};

/* F122,  4 bytes, R, DiagnosticDefinitionDataIdentifier  */
const EcuVersionsType EcuDiagnosticVersion = {'0','0','.','1'};







/* F197,  3 bytes, R,  System Name  */
const EcuOEMSysNameType EcuOEMSystemName = {'M','P','5'};

/* F193,  3 bytes, R, ECU Hardware Version Number(SYS), eg.  0x300001 V3.0.0001 */
EcuHardwareVersionType EcuHardwareVersion = {'0','0','3'};

/* F179,  2 bytes, R, ECU Hardware Version Number(OEM) */

/* F195,  3 bytes, R, ECU Software Version Number(SYS) */
EcuSoftVersionType EcuSoftVersion = {'0','2','5'};

///* F199,  4 bytes, R, Programming Date */
//ECUProgramDateType EcuProgramDate = {'1', '7', '1', '1'};



/* F010, 16 bytes, RW, Vehicle configuration */
//ECUFunctionConfigType	ECUFunctionConfig ={0x0A,0x09,0x00,0x07};
#endif



unsigned char readonlyRadioMode[1];
unsigned char readonlyRadioFrequency[3];
unsigned char CurrentRadioVOL[1];
//unsigned char HU_BT_Name[10];
//unsigned char HU_BT_MAC_ADDR[6];
//unsigned char TotalTracksincurrentselecteddev[2];
//unsigned char Veh_ODO[3];
ECUPdsnType Mb_Pdsn;
ECUVehType  Veh_Type={0x00,0x00};//factory diag write program NL-3+/ NL-3 /NL-3 oversea 	

//Diag_Read_flag Diag_Read_Data_flag;//   0:null  1:reading    2:read complete
//extern unsigned char PEPS_EngStartInfo;
/*------------------function define-----------------*/
void DFlash_backup_check();
/*------------------extern funtion-----------------*/
extern uint16_t Pwr_Fail_AD_get_Voltage(void);
extern unsigned char  Vehicle_at_standstill_flag;
//extern uint32 Dtc_clear_ID;
extern unsigned char  Dataflash_Init_Flag[16];
extern void osal_nv_clear_flash_page(unsigned char pag_no);

#if 0
unsigned char return_body_style_cfg(unsigned char cfg)
{
	return (ECUFunctionConfig.resv[0]&cfg);
}
#endif

void Save_system_config_data(unsigned short Diag_id,unsigned long len,void *data)
{
#if 0
	if(0 == osal_nv_item_init( Diag_id, len, data))
		osal_nv_write( Diag_id, len, data);
	DFlash_backup_check();//20160217
#endif
}

void Dcm_AppInit(unsigned char offset)
{
#if 0
	//SysNvItemInitType SysNvItemInit;

	if (0 == osal_nv_item_init( (SYS_NV_FUNC_CONFIG+offset),sizeof(ECUFunctionConfigType), 	&ECUFunctionConfig )) {
		osal_nv_read( (SYS_NV_FUNC_CONFIG+offset),  sizeof(ECUFunctionConfigType), &ECUFunctionConfig);
	}
		
	if (0 == osal_nv_item_init( (SYS_NV_FUNC_ID+offset), sizeof(ECUNetworkConfigDIDType),&ECUNetworkConfigDID)) {
		osal_nv_read( (SYS_NV_FUNC_ID+offset),  sizeof(ECUNetworkConfigDIDType), &ECUNetworkConfigDID);
	}
	if (0 == osal_nv_item_init( (SYS_NV_VEHICLE_NAME+offset), sizeof(ECUVecleNameType), 		&ECUVecleName)) {
		osal_nv_read( (SYS_NV_VEHICLE_NAME+offset),  sizeof(ECUVecleNameType), &ECUVecleName);
	}
	if (0 == osal_nv_item_init( (SYS_NV_MADE_DATE+offset), sizeof(ECUMadeDateType), &ECUMadeDate)) {
		osal_nv_read((SYS_NV_MADE_DATE+offset),  sizeof(ECUMadeDateType), &ECUMadeDate);
	}
	if (0 == osal_nv_item_init( (SYS_NV_VIN+offset), sizeof(ECUVinType), &ECUVin)) {
		osal_nv_read((SYS_NV_VIN+offset),  sizeof(ECUVinType), &ECUVin);
	}
	
	if (0 == osal_nv_item_init( (SYS_NV_INSTALL_DATE+offset), sizeof(ECUInstallDateType), &ECUInstallDate)) {
		osal_nv_read( (SYS_NV_INSTALL_DATE+offset), sizeof(ECUInstallDateType), &ECUInstallDate);
	}
	
	if (0 == osal_nv_item_init( (SYS_NV_PDSN+offset), sizeof(ECUPdsnType), &Mb_Pdsn)) {
		osal_nv_read((SYS_NV_PDSN+offset),  sizeof(ECUPdsnType), &Mb_Pdsn);
	}

	if (0 == osal_nv_item_init( (SYS_DFLASH_INIT_FLAG+offset), sizeof(Dataflash_Init_Flag), 	&Dataflash_Init_Flag)) {
		//osal_nv_read(SYS_NV_INSTALL_DATE,  sizeof(ECUInstallDateType), &SysNvItemInit.ECUInstallDate);
	}
#endif
}

void DFlash_default_check()
{
#if 0
	unsigned char init_flag_data[16]={0,0,0,0,0,0,0,0};
	//osal_nv_clear_all_flash();

	/**/
	if(0 == osal_nv_item_init( SYS_DFLASH_INIT_FLAG, sizeof(Dataflash_Init_Flag), &Dataflash_Init_Flag))
		osal_nv_read( SYS_DFLASH_INIT_FLAG, sizeof(init_flag_data), &init_flag_data);

	if(memcmp(init_flag_data,Dataflash_Init_Flag,sizeof(Dataflash_Init_Flag)))
	{
		if (0 == osal_nv_item_init( SYS_NV_FUNC_CONFIG,sizeof(ECUFunctionConfigType), 	&ECUFunctionConfig )) {
			if(Dataflash_Init_Flag[SYS_NV_FUNC_CONFIG-1] == init_flag_data[SYS_NV_FUNC_CONFIG-1])
			{
				osal_nv_read( SYS_NV_FUNC_CONFIG, sizeof(ECUFunctionConfigType), &ECUFunctionConfig);
			}
			else
			{
				osal_nv_write( SYS_NV_FUNC_CONFIG, sizeof(ECUFunctionConfigType), &ECUFunctionConfig);
			}
		}
		
		if (0 == osal_nv_item_init( SYS_NV_FUNC_ID, sizeof(ECUNetworkConfigDIDType),&ECUNetworkConfigDID)) {
			if(Dataflash_Init_Flag[SYS_NV_FUNC_ID-1] == init_flag_data[SYS_NV_FUNC_ID-1])
			{
				osal_nv_read( SYS_NV_FUNC_ID, sizeof(ECUNetworkConfigDIDType), &ECUNetworkConfigDID);
			}
			else
			{
				osal_nv_write( SYS_NV_FUNC_ID, sizeof(ECUNetworkConfigDIDType), &ECUNetworkConfigDID);
			}
		}
		if (0 == osal_nv_item_init( SYS_NV_VEHICLE_NAME, sizeof(ECUVecleNameType),		&ECUVecleName)) {
			
			if(Dataflash_Init_Flag[SYS_NV_VEHICLE_NAME-1] == init_flag_data[SYS_NV_VEHICLE_NAME-1])
			{
				osal_nv_read( SYS_NV_VEHICLE_NAME, sizeof(ECUVecleNameType), &ECUVecleName);
			}
			else
			{
				osal_nv_write( SYS_NV_VEHICLE_NAME, sizeof(ECUVecleNameType), &ECUVecleName);
			}
		}
		
		if (0 == osal_nv_item_init( SYS_NV_MADE_DATE, sizeof(ECUMadeDateType), &ECUMadeDate)) {
			if(Dataflash_Init_Flag[SYS_NV_MADE_DATE-1] == init_flag_data[SYS_NV_MADE_DATE-1])
			{
				osal_nv_read( SYS_NV_MADE_DATE, sizeof(ECUMadeDateType), &ECUMadeDate);
			}
			else
			{
				osal_nv_write( SYS_NV_MADE_DATE, sizeof(ECUMadeDateType), &ECUMadeDate);
			}
		}
		if (0 == osal_nv_item_init( SYS_NV_VIN, sizeof(ECUVinType), &ECUVin)) {
			if(Dataflash_Init_Flag[SYS_NV_VIN-1] == init_flag_data[SYS_NV_VIN-1])
			{
				osal_nv_read( SYS_NV_VIN, sizeof(ECUVinType), &ECUVin);
			}
			else
			{
				osal_nv_write( SYS_NV_VIN, sizeof(ECUVinType), &ECUVin);
			}
		}
		if (0 == osal_nv_item_init( SYS_NV_INSTALL_DATE, sizeof(ECUInstallDateType), &ECUInstallDate)) {
			if(Dataflash_Init_Flag[SYS_NV_INSTALL_DATE-1] == init_flag_data[SYS_NV_INSTALL_DATE-1])
			{
				osal_nv_read( SYS_NV_INSTALL_DATE, sizeof(ECUInstallDateType), &ECUInstallDate);
			}
			else
			{
				osal_nv_write( SYS_NV_INSTALL_DATE, sizeof(ECUInstallDateType), &ECUInstallDate);
			}
		}
		if (0 == osal_nv_item_init( SYS_NV_PDSN, sizeof(ECUPdsnType), &Mb_Pdsn)) {
			
			if(Dataflash_Init_Flag[SYS_NV_PDSN-1] == init_flag_data[SYS_NV_PDSN-1])
			{
				osal_nv_read( SYS_NV_PDSN, sizeof(ECUPdsnType), &Mb_Pdsn);
			}
			else
			{
				osal_nv_write( SYS_NV_PDSN, sizeof(ECUPdsnType), &Mb_Pdsn);
			}
		}
		osal_nv_write( SYS_DFLASH_INIT_FLAG, sizeof(Dataflash_Init_Flag), &Dataflash_Init_Flag);
	}
	else
	{
		Dcm_AppInit(0);
	}
#endif		

#if 0
	
	/* F1FA,  6 bytes, R,W System Function Configuration */
	ECUFunctionConfigType	ECUFunctionConfig_check ={0x00,0x00,0x00,0x00,0X00,0X00};	
	/* F1FB,  2 bytes, R,W ECU Function Configuration ECU */
	ECUFunctionConfig_ECU_Type	ECUFunction_ECUConfig_check ={0x00,0x00};
	const unsigned char check_buff_ecu_config[6]= {0xff,0xff,0xff,0xff,0xff,0xff};
	const unsigned char check_buff_ecu_config_1 [2]= {0xff,0xff};

	osal_nv_read(ECU_SYS_CONFIG, sizeof(ECUFunctionConfigType), &ECUFunctionConfig_check);	
	osal_nv_read(ECU_FUNC_CONFIG, sizeof(ECUFunctionConfig_ECU_Type), &ECUFunction_ECUConfig_check);
	
	if(memcmp(check_buff_ecu_config,&ECUFunctionConfig_check.Program_Date[0],6)&&(memcmp(check_buff_ecu_config_1,&ECUFunction_ECUConfig_check,2)))
	{
		osal_nv_read(ECU_SYS_CONFIG, sizeof(ECUFunctionConfigType), &ECUFunctionConfig);	
		osal_nv_read(ECU_FUNC_CONFIG, sizeof(ECUFunctionConfig_ECU_Type), &ECUFunction_ECUConfig);
		osal_nv_read(ECU_SERIAL_NUMBER, sizeof(ECUSerialNumType), &EcuSerialNum);
		osal_nv_read(ECU_PROGRAM_DATA, sizeof(ECUManufacturingDateType), &EcuManufacturingDate);
		osal_nv_read(ECU_VIN, sizeof(ECUVinType), &ECUVin); 		
	}
	else
	{
		osal_nv_write(ECU_SYS_CONFIG,  sizeof(ECUFunctionConfigType), &ECUFunctionConfig );
		osal_nv_write(ECU_FUNC_CONFIG,  sizeof(ECUFunctionConfig_ECU_Type), &ECUFunction_ECUConfig );
		osal_nv_write(ECU_SERIAL_NUMBER,  sizeof(ECUSerialNumType), &EcuSerialNum );
		osal_nv_write(ECU_PROGRAM_DATA,  sizeof(ECUManufacturingDateType), &EcuManufacturingDate );	
		osal_nv_write(ECU_VIN,  sizeof(ECUVinType), &ECUVin );
	}
	#endif
//	osal_nv_read(ECU_FUNCTION_CONFIG, sizeof(ECUFunctionConfigType), &ECUFunctionConfig);
}



Std_ReturnType Read_DidConditionCheckReadFnc(Dcm_OpStatusType OpStatus,Dcm_NegativeResponseCodeType *errorCode)
{
 	Std_ReturnType state=E_OK;
	if(true == Vehicle_at_standstill_flag )//vehiclespeed < 3mil
    {
	   *errorCode= DCM_E_POSITIVERESPONSE;
	   state = E_OK;
	}
	else
	{
	   *errorCode= DCM_E_CONDITIONSNOTCORRECT;
	   state = E_NOT_OK;
	}
	
	return state;
}

Std_ReturnType Read_DidReadDataFnc_0200(uint8_t *data)
{
        osal_nv_read(DID_NV_0200_ID, DID_NV_0200_SIZE, data);
	return E_OK;
}
Std_ReturnType Write_DidWriteDataFnc_0200(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode)
{     
    Std_ReturnType ret = E_NOT_OK;
	if(true == Vehicle_at_standstill_flag )//vehiclespeed < 3mil
    {
		
		if (!osal_nv_write(DID_NV_0200_ID,  DID_NV_0200_SIZE, data ))
		{
			ret = E_OK;
		}
		else
		{
			ret = E_NOT_OK;
			*errorCode = DCM_E_GENERALPROGRAMMINGFAILURE;	
		}
	}
	else
	{
		     ret = E_NOT_OK;
			*errorCode = DCM_E_CONDITIONSNOTCORRECT;	
	}
    return ret;
}

Std_ReturnType Read_DidReadDataFnc_0201(uint8_t *data)
{
        osal_nv_read(DID_NV_0201_ID, DID_NV_0201_SIZE, data);
	return E_OK;
}

Std_ReturnType Write_DidWriteDataFnc_0201(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode)
{
	Std_ReturnType ret = E_NOT_OK;
	if(true == Vehicle_at_standstill_flag)//vehiclespeed < 3mil
    {
			
		if (!osal_nv_write(DID_NV_0201_ID,  DID_NV_0201_SIZE, data ))
		{
			ret = E_OK;
		}
		else
		{
			ret = E_NOT_OK;
			*errorCode = DCM_E_GENERALPROGRAMMINGFAILURE;	
		}
    }
	else
	{
		     ret = E_NOT_OK;
			*errorCode = DCM_E_CONDITIONSNOTCORRECT;	
	}
	return ret;
}



Std_ReturnType Read_DidReadDataFnc_F101(uint8_t *data)
{
    osal_nv_read(DID_NV_F101_ID, 16, data);
	return E_OK;
}

Std_ReturnType Write_DidWriteDataFnc_F101(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode)
{
	Std_ReturnType ret = E_NOT_OK;
	if(true == Vehicle_at_standstill_flag)//vehiclespeed < 3mil
    {
		
		if (!osal_nv_write(DID_NV_F101_ID,  16, data ))
		{
			ret = E_OK;
		}
		else
		{
			ret = E_NOT_OK;
			*errorCode = DCM_E_GENERALPROGRAMMINGFAILURE;	
		}
     }
	else
	{
		     ret = E_NOT_OK;
			*errorCode = DCM_E_CONDITIONSNOTCORRECT;	
	}
	return ret;
}

Std_ReturnType Read_DidReadDataFnc_F110(uint8_t *data)
{
    osal_nv_read(DID_NV_F110_ID, 8, data);
	return E_OK;
}

Std_ReturnType Write_DidWriteDataFnc_F110(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode)
{
	Std_ReturnType ret = E_NOT_OK;
	if(true == Vehicle_at_standstill_flag)//vehiclespeed < 3mil
    {
		if (!osal_nv_write(DID_NV_F110_ID,  8, data ))
		{
			ret = E_OK;
		}
		else
		{
			ret = E_NOT_OK;
			*errorCode = DCM_E_GENERALPROGRAMMINGFAILURE;	
		}
     }
	else
	{
		     ret = E_NOT_OK;
			*errorCode = DCM_E_CONDITIONSNOTCORRECT;	
	}
	return ret;
}

Std_ReturnType Read_DidReadDataFnc_F112(uint8_t *data)
{
    osal_nv_read(DID_NV_F112_ID, 8, data);
	return E_OK;
}

Std_ReturnType Write_DidWriteDataFnc_F112(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode)
{
	Std_ReturnType ret = E_NOT_OK;
	if(true == Vehicle_at_standstill_flag)//vehiclespeed < 3mil
    {
		
		if (!osal_nv_write(DID_NV_F112_ID,  8, data ))
		{
			ret = E_OK;
		}
		else
		{
			ret = E_NOT_OK;
			*errorCode = DCM_E_GENERALPROGRAMMINGFAILURE;	
		}
     }
	else
	{
		     ret = E_NOT_OK;
			*errorCode = DCM_E_CONDITIONSNOTCORRECT;	
	}
	return ret;
}




Std_ReturnType Read_DidReadDataFnc_F187(uint8_t *data)
{
	memcpy(data,&EcuOEMPartNumber,sizeof(EcuOEMPartNumberType));
	return E_OK;
}

Std_ReturnType Read_DidReadDataFnc_F189(uint8_t *data)
{
	memcpy(data,&ECUSoftId,sizeof(ECUSoftIdType));
	return E_OK;
}

Std_ReturnType Read_DidReadDataFnc_F18A(uint8_t *data)
{
	memcpy(data,&EcuVendorID,sizeof(EcuVendorIDType));
	return E_OK;

}

Std_ReturnType Read_DidReadDataFnc_F18C(uint8_t *data)
{
 
	memcpy(data,&EcuSerialNum,sizeof(ECUSerialNumType));
	return E_OK;
}
Std_ReturnType Write_DidWriteDataFnc_F18C(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode)
{
	Std_ReturnType ret = E_NOT_OK;
	if(true == Vehicle_at_standstill_flag)//vehiclespeed < 3mil
    {
		memcpy(&EcuSerialNum, data, sizeof(ECUSerialNumType));
		if (!osal_nv_write(DID_NV_F18C_ID,  sizeof(ECUSerialNumType), &EcuSerialNum ))
		{
			ret = E_OK;
		}
		else
		{
			ret = E_NOT_OK;
			*errorCode = DCM_E_GENERALPROGRAMMINGFAILURE;	
		}
	 }
	else
	{
		     ret = E_NOT_OK;
			*errorCode = DCM_E_CONDITIONSNOTCORRECT;	
	}

	return ret;
}

Std_ReturnType Read_DidReadDataFnc_F190(uint8_t *data)
{

	ECUVinType ECUVin;
	
	osal_nv_read(DID_NV_F112_ID, sizeof(ECUVinType), &ECUVin );
	memcpy(data, &ECUVin, sizeof(ECUVinType));

	return E_OK;
}
Std_ReturnType Write_DidWriteDataFnc_F190(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode)
{
	
	Std_ReturnType ret = E_NOT_OK;
	ECUVinType ECUVin;

	if(true == Vehicle_at_standstill_flag)//vehiclespeed < 3mil
    {
		memcpy(&ECUVin, data, sizeof(ECUVinType));
		if (!osal_nv_write(DID_NV_F190_ID,  sizeof(ECUVinType), &ECUVin ))
		{
			ret = E_OK;
		}
		else
		{
			ret = E_NOT_OK;
			*errorCode = DCM_E_GENERALPROGRAMMINGFAILURE;	
		}
	
    }
	else
	{
		     ret = E_NOT_OK;
			*errorCode = DCM_E_CONDITIONSNOTCORRECT;	
	}

	return ret;
}

Std_ReturnType Read_DidReadDataFnc_F191(uint8_t *data)
{	
	memcpy(data, &ECUHardVer, sizeof(ECUHardVer));
	return E_OK;
}

Std_ReturnType Read_DidReadDataFnc_F193(uint8_t *data)
{	
	memcpy(data, &ECUHardVer, sizeof(ECUHardVer));
	return E_OK;
}
Std_ReturnType Read_DidReadDataFnc_F195(uint8_t *data)
{	
	memcpy(data, &ECUSoftware, sizeof(ECUSoftware));
	return E_OK;
}

Std_ReturnType Read_DidReadDataFnc_F19D(uint8_t *data)
{	
	osal_nv_read(DID_NV_F19D_ID, 4, &data );
	return E_OK;
}
Std_ReturnType Write_DidWriteDataFnc_F19D(uint8_t *data, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode)
{
	
	Std_ReturnType ret = E_NOT_OK;
    if(true == Vehicle_at_standstill_flag)//vehiclespeed < 3mil
    {
		if (!osal_nv_write(DID_NV_F19D_ID,  4, data ))
		{
			ret = E_OK;
		}
		else
		{
			ret = E_NOT_OK;
			*errorCode = DCM_E_GENERALPROGRAMMINGFAILURE;	
		}
    }
	else
	{
		     ret = E_NOT_OK;
			*errorCode = DCM_E_CONDITIONSNOTCORRECT;	
	}

	return ret;
}


extern void Clear_Diag_read_state(short pending_did)
{
	switch(pending_did)
	{
		case 0xB001://sim iccid
//			Diag_Read_Data_flag.AntennaSignalStrength = State_Null;
			break;
		case 0xB002://sim imisi
//			Diag_Read_Data_flag.SourceMode = State_Null;
			break;
		case 0xB008://BT MAC adderss
//			Diag_Read_Data_flag.BT_MAC_ADDR = State_Null;
			break;
		case 0xB082: // SYSTEM TIME
			break;
		case 0xB101: // GPS basic
			break;
		case 0xB102: // GPS ext
			break;
		case 0xC001: //tps apn Address
			break;
		case 0xC002: //tsp APN User
			break;
		case 0xC003: // tsp APN password
			break;
		case 0xC004: //tps apn Address 2
			break;
		case 0xC005: //tsp APN User 2
			break;
		case 0xC006: // tsp APN password 2
			break;
		case 0xC007: //tps ip
			break;
		case 0xC008: //tsp sms
			break;
		case 0xC009: // tsp ip port number
			break;
			
		case 0xF1B5: // MPU soft version
			break;
		case 0xF18C: // pdsn  
//			Diag_Read_Data_flag.MB_PDSN = State_Null;
			break;
		default:
			break;
	}
}



Std_ReturnType Dem_ConditionCheckReadFnc(uint8_t *Nrc)
{
	*Nrc = DCM_E_POSITIVERESPONSE;
	return E_OK;
}


		
Std_ReturnType Read_DidReadDataFnc_DF00(uint8_t *data)
{
    data[0] = veh_data.KL30_Vol;
	return E_OK;
}

Std_ReturnType Read_DidReadDataFnc_DF01(uint8_t *data)
{   
  if(veh_data.VehicleSpeedValidflag)
  {
    data[0] = veh_data.VehicleSpeed>>8;
    data[1] = veh_data.VehicleSpeed;
  }
  return E_OK;
}

Std_ReturnType Read_DidReadDataFnc_DF02(uint8_t *data)
{
    data[0] = 125;//12.5V
	return E_OK;
}

Std_ReturnType Read_DidReadDataFnc_DF03(uint8_t *data)
{   
    data[0]=(uint8_t)(veh_data.IPKTotalOdometer>>16);
    data[1]=(uint8_t)(veh_data.IPKTotalOdometer>>8);
    data[1]=(uint8_t)(veh_data.IPKTotalOdometer);
	return E_OK;
}
Std_ReturnType Read_DidReadDataFnc_DF04(uint8_t *data)
{   
    data[0]=(uint8_t)(veh_data.IPKTotalOdometer>>16);
    data[1]=(uint8_t)(veh_data.IPKTotalOdometer>>8);
    data[1]=(uint8_t)(veh_data.IPKTotalOdometer);
	return E_OK;
}


Std_ReturnType Read_DidReadDataFnc_7960(uint8_t *data)
{
   if(veh_data.IO_SetBacklightLevel == 0xff)
   {
	//*(data) 	= getBackLight();
   }
   else
   {
   	 *(data) 	= veh_data.IO_SetBacklightLevel;
   }
	return E_OK;
}









