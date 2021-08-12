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

#ifndef RTE_DEM_TYPE_H_
#define RTE_DEM_TYPE_H_

#define DEM_NOT_SERVICE_COMPONENT
#ifdef USE_RTE
#warning This file should only be used when not using an RTE with Dem service component.
#include "Rte_Type.h"
#else

typedef uint32_t Dem_DTCType;
typedef uint16_t Dem_EventIdType;
typedef int8_t Dem_FaultDetectionCounterType;
typedef uint8_t Dem_IndicatorStatusType;
typedef uint8_t Dem_InitMonitorReasonType;
typedef uint8_t Dem_OperationCycleIdType;

typedef uint8_t Dem_OperationCycleStateType;

typedef uint8_t Dem_EventStatusType;

typedef uint8_t Dem_EventStatusExtendedType;

typedef uint8_t Dem_DTCFormatType;

typedef uint8_t Dem_DTCOriginType;

typedef uint8_t Dem_ReturnClearDTCType;

Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);
#endif

#endif /* RTE_DEM_TYPE_H_ */
