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
#include "datacenter.h"
#include "Rte_Dcm_Type.h"
#include "Std_Types.h"


extern unsigned char  Vehicle_at_standstill_flag;

//(uint8_t action, uint8_t *controlOptionRecord)

Std_ReturnType  Ctrl_DidReturnControlToEcuFnc_7960(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *errorCode)
{
    Std_ReturnType stat = E_OK;
	//if(true == Vehicle_at_standstill_flag)
	{		
       veh_data.IO_SetBacklightLevel = 0xff;
       *errorCode= DCM_E_POSITIVERESPONSE;
	   stat = E_OK;
	}
	//else
	{
	   
	}
	return stat;
}

Std_ReturnType Ctrl_DidShortTermAdjustmentFnc_7960(uint8_t *controlOptionRecord, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *errorCode)
{
    Std_ReturnType stat;
    uint8_t temp;
	temp=*controlOptionRecord;
    if(true == Vehicle_at_standstill_flag)
	{		
		if(temp<=10)
		{
			veh_data.IO_SetBacklightLevel = temp;
			*errorCode= DCM_E_POSITIVERESPONSE;
			stat = E_OK;
		}
		else
		{
			*errorCode= DCM_E_REQUESTOUTOFRANGE;
			stat = E_NOT_OK;
		}
    }
	else
	{
	       *errorCode= DCM_E_CONDITIONSNOTCORRECT;
			stat = E_NOT_OK;
	}
	return stat;
}
