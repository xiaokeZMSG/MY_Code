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


#ifndef CANSM_CONFIGTYPES_H_
#define CANSM_CONFIGTYPES_H_

#include "Dcm_Cfg.h"
/** @req CANSM010.bswbuilder */
#if defined(USE_DEM)
#include "Dem.h"
#endif
typedef struct {
	const uint8_t						CanIfControllerId;
} CanSM_ControllerType;

typedef struct {
	const CanSM_ControllerType*		Controllers;
	const uint8_t						ControllerCount;
	const uint8_t						ComMNetworkHandle;
	const uint32_t                    CanSMBorTimeTxEnsured;
	const uint32_t                    CanSMBorTimeL1;
	const uint32_t                    CanSMBorTimeL2;
	const uint8_t                     CanSMBorCounterL1ToL2;
	const boolean                   CanSMBorTxConfirmationPolling;
#if defined(USE_DEM)
	Dem_EventIdType					CanSMDemEventId;
#endif
#if (CANSM_CAN_TRCV_SUPPORT == STD_ON)
	const uint8						CanIfTransceiverId;
#endif
} CanSM_NetworkType;

typedef struct {
	const uint8_t						CanSMModeRequestRepetitionMax;
	const uint32_t					CanSMModeRequestRepetitionTime;
	const CanSM_NetworkType*		Networks;
} CanSM_ConfigType;

#endif /* CANSM_CONFIGTYPES_H_ */
