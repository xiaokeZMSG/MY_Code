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

#ifndef RTE_DCM_TYPE_H_
#define RTE_DCM_TYPE_H_

#if !defined(DCM_UNIT_TEST) || (DCM_UNIT_TEST == STD_OFF)
#define DCM_NOT_SERVICE_COMPONENT
#endif

#ifdef USE_RTE
#warning This file should only be used when not using an RTE with Dcm service component.
#include "Rte_Type.h"
#else

typedef uint8_t Dcm_ConfirmationStatusType;
#define DCM_RES_POS_OK                          ((Dcm_ConfirmationStatusType)0x00)
#define DCM_RES_POS_NOT_OK                      ((Dcm_ConfirmationStatusType)0x01)
#define DCM_RES_NEG_OK                          ((Dcm_ConfirmationStatusType)0x02)
#define DCM_RES_NEG_NOT_OK                      ((Dcm_ConfirmationStatusType)0x03)

//typedef uint8 Dcm_NegativeResponseCodeType;

//typedef uint8 Dcm_OpStatusType;

//typedef uint8 Dcm_ProtocolType;

#endif
#endif /*RTE_DCM_TYPE_H_*/
