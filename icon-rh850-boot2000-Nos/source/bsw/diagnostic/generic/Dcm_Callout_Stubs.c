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
//#include "HalDriver.h"
#include "Com.h"
#include "datacenter.h"
#include "dcm_internal.h"
#include "r_system.h"
extern Com_IpduGroupVector BswM_COMGoupVector; 
extern unsigned char  Vehicle_at_standstill_flag;

Std_ReturnType Dcm_CallbackStartProtocolFnc(Dcm_ProtocolType protocolID)
{
    return E_OK;
}

Dcm_ReturnWriteMemoryType Dcm_WriteMemory(Dcm_OpStatusType OpStatus,
					   uint8_t MemoryIdentifier,
					   uint32_t MemoryAddress,
					   uint32_t MemorySize,
					   uint8_t* MemoryData)
{
    (void)OpStatus;
    (void)MemoryIdentifier;
    (void)MemoryAddress;
    (void)MemorySize;
    (void)MemoryData;
	return DCM_WRITE_FAILED;
}

/*@req Dcm495*/
Dcm_ReturnReadMemoryType Dcm_ReadMemory(Dcm_OpStatusType OpStatus,
					   uint8_t MemoryIdentifier,
					   uint32_t MemoryAddress,
					   uint32_t MemorySize,
					   uint8_t* MemoryData)
{

    (void)OpStatus;
    (void)MemoryIdentifier;
    (void)MemoryAddress;
    (void)MemorySize;
    (void)MemoryData;
	return DCM_READ_FAILED;
}

void Dcm_DiagnosticSessionControl(Dcm_SesCtrlType session)
{
    (void)session;
}


Std_ReturnType DcmE_EcuReset(Dcm_EcuResetType resetType)
{
    Std_ReturnType ret = E_NOT_OK;
	if(Vehicle_at_standstill_flag == FALSE){
		return E_NOT_OK;
	}

	switch (resetType) {
		case DCM_HARD_RESET:
			ret = E_OK;
			break;
		case DCM_SOFT_RESET:
			ret = E_OK;
			break;
		default :
			break;
    }
	if(ret == E_OK)//recover communication
	{
		Communication_Control_TX_Disabled = 0;
		Communication_Control_RX_Disabled = 0;
	}
	return ret;
}

void DcmE_EcuPerformReset(Dcm_EcuResetType resetType)
{
    
	switch (resetType) {
		case DCM_HARD_RESET:
			 R_SYSTEM_HardReset();
			break;
		case DCM_SOFT_RESET:
			R_SYSTEM_SoftReset();
			break;
		default :
			break;
    }
}
void Mcu_PerformReset()
{
  
}


void Dcm_E_CommunicationControl(uint8_t subFunction, uint8_t communicationType, Dcm_NegativeResponseCodeType *responseCode )
{
#if 0
	switch(subFunction){
		case 0x00:
			if((communicationType==DCM_NORMAL_MESSAGE)||(communicationType==DCM_NORMAL_NETWORK_MESSAGE)){	
				if(Vehicle_at_standstill_flag == TRUE){
					Com_IpduGroupControl(BswM_COMGoupVector, TRUE);
					//Communication_Control_Disabled &=(~communicationType);
					Communication_Control_Disabled =0;
					*responseCode = DCM_E_POSITIVERESPONSE;
				}else{
					*responseCode = DCM_E_CONDITIONSNOTCORRECT;
				}
			}else{
				*responseCode = DCM_E_REQUESTOUTOFRANGE;
			}
			break;
			
		case 0x03:
			if((communicationType==DCM_NORMAL_MESSAGE)||(communicationType==DCM_NORMAL_NETWORK_MESSAGE)){
				if(Vehicle_at_standstill_flag == TRUE){
					Com_IpduGroupControl(BswM_COMGoupVector, FALSE);
					Communication_Control_Disabled=communicationType;
					*responseCode = DCM_E_POSITIVERESPONSE;
				}else{
					*responseCode = DCM_E_CONDITIONSNOTCORRECT;
				}
			}else{
				*responseCode = DCM_E_REQUESTOUTOFRANGE;
			}
			break;
			
		default:
			*responseCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
			break;
	}
#endif
    
#if 1 //From BAIC_C40_C53, 2017-11-25 21:22:11
    switch(subFunction){
		case 0x00:
			if((0x01 == communicationType)||(03 == communicationType))
			{	
					if(Vehicle_at_standstill_flag == TRUE)
					{
						Com_IpduGroupControl(BswM_COMGoupVector, TRUE);
						Communication_Control_TX_Disabled = 0;
					    Communication_Control_RX_Disabled = 0;
						*responseCode = DCM_E_POSITIVERESPONSE;
					}
					else
					{
					    *responseCode = DCM_E_CONDITIONSNOTCORRECT;
					}
			}else if(0x02 == communicationType){
				   if(Vehicle_at_standstill_flag == TRUE)
					{
					  *responseCode = DCM_E_POSITIVERESPONSE;
				   	}
				   else
				   	{
				   	 *responseCode = DCM_E_CONDITIONSNOTCORRECT;
				   	}				
			}else{
				*responseCode = DCM_E_REQUESTOUTOFRANGE;
			}
			break;
		case 0x01:
			if((0x01 == communicationType)||(03 == communicationType)){	
				     if(Vehicle_at_standstill_flag == TRUE)
					 {
						//Com_IpduGroupControl(BswM_COMGoupVector, FALSE);
						Communication_Control_TX_Disabled = 1;
						Communication_Control_RX_Disabled = 0;
						*responseCode = DCM_E_POSITIVERESPONSE;

					}
					else
					{
					    *responseCode = DCM_E_CONDITIONSNOTCORRECT;
					}
				}else if(0x02 == communicationType){
					if(Vehicle_at_standstill_flag == TRUE)
					{
					  *responseCode = DCM_E_POSITIVERESPONSE;
				   	}
				   else
				   	{
				   	 *responseCode = DCM_E_CONDITIONSNOTCORRECT;
				   	}
				
			}else{
				*responseCode = DCM_E_REQUESTOUTOFRANGE;
			}
			break;	
		case 0x03:
			if((0x01 == communicationType)||(03 == communicationType)){
					if(Vehicle_at_standstill_flag == TRUE)
					{
						Com_IpduGroupControl(BswM_COMGoupVector, FALSE);
						Communication_Control_TX_Disabled = 1;
					    Communication_Control_RX_Disabled = 1;
						*responseCode = DCM_E_POSITIVERESPONSE;
					}
					else
					{
					    *responseCode = DCM_E_CONDITIONSNOTCORRECT;
					}
				}else if(0x02 == communicationType){
					if(Vehicle_at_standstill_flag == TRUE)
					{
					  *responseCode = DCM_E_POSITIVERESPONSE;
				   	}
				   else
				   	{
				   	 *responseCode = DCM_E_CONDITIONSNOTCORRECT;
				   	}
				
			}else{
				*responseCode = DCM_E_REQUESTOUTOFRANGE;
			}
			break;
			
		default:
			*responseCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
			break;
	}
#endif
}










