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

/** @tagSettings DEFAULT_ARCHITECTURE=PPC */
/** @reqSettings DEFAULT_SPECIFICATION_REVISION=4.1.2 */

/** @addtogroup Adc ADC Driver
 *  @{ */

/** @file Adc.h
 * API and type definitions for ADC Driver.
 */

#ifndef ADC_H_
#define ADC_H_

#include "Std_Types.h"


#define ADC_VENDOR_ID			    60
#define ADC_MODULE_ID			    123
#define ADC_AR_RELEASE_MAJOR_VERSION  		4
#define ADC_AR_RELEASE_MINOR_VERSION 		1
#define ADC_AR_RELEASE_PATCH_VERSION		2

#define ADC_SW_MAJOR_VERSION  		2
#define ADC_SW_MINOR_VERSION 		0
#define ADC_SW_PATCH_VERSION		0

/** General requirements tagging */
/* @req SWS_Adc_00267  */
/* @req SWS_Adc_00363  */
/* @req SWS_Adc_00364  */
/* @req SWS_Adc_00505  */
/* @req SWS_Adc_00506  */
/* @req SWS_Adc_00507  */
/* @req SWS_Adc_00508  */
/* @req SWS_Adc_00509  */
/* @req SWS_Adc_00510  */
/* @req SWS_Adc_00512  */
/* @req SWS_Adc_00513  */
/* @req SWS_Adc_00515  */
/* @req SWS_Adc_00517  */
/* @req SWS_Adc_00518  */
/* @req SWS_Adc_00098  */
/* @req SWS_Adc_00099  */

/** Group status. */
typedef enum
{
  ADC_IDLE,
  ADC_BUSY,
  ADC_COMPLETED,
  ADC_STREAM_COMPLETED,
}Adc_StatusType;


/* DET errors that the ADC can produce. */

#define  ADC_E_UNINIT              (uint8_t) 0x0A
#define  ADC_E_BUSY                (uint8_t) 0x0B
#define  ADC_E_IDLE                (uint8_t) 0x0C
#define  ADC_E_ALREADY_INITIALIZED (uint8_t) 0x0D
#define  ADC_E_PARAM_CONFIG        (uint8_t) 0x0E
#define  ADC_E_PARAM_POINTER       (uint8_t) 0x14
#define  ADC_E_PARAM_GROUP         (uint8_t) 0x15
#define  ADC_E_WRONG_CONV_MODE     (uint8_t) 0x16
#define  ADC_E_WRONG_TRIGG_SRC     (uint8_t) 0x17
#define  ADC_E_NOTIF_CAPABILITY    (uint8_t) 0x18
#define  ADC_E_BUFFER_UNINIT       (uint8_t) 0x19


/** API service ID's */

#define   ADC_INIT_ID 						 (uint8_t)0x00
#define   ADC_DEINIT_ID 					 (uint8_t)0x01
#define   ADC_STARTGROUPCONVERSION_ID 		 (uint8_t)0x02
#define   ADC_STOPGROUPCONVERSION_ID 		 (uint8_t)0x03
#define   ADC_READGROUP_ID 					 (uint8_t)0x04
#define   ADC_ENABLEHARDWARETRIGGER_ID 		 (uint8_t)0x05
#define   ADC_DISBALEHARDWARETRIGGER_ID		 (uint8_t)0x06
#define   ADC_ENABLEGROUPNOTIFICATION_ID 	 (uint8_t)0x07
#define   ADC_DISABLEGROUPNOTIFICATION_ID	 (uint8_t)0x08
#define   ADC_GETGROUPSTATUS_ID 			 (uint8_t)0x09
#define   ADC_GETVERSIONINFO_ID 			 (uint8_t)0x0A
#define   ADC_GETSTREAMLASTPOINTER_ID 		 (uint8_t)0x0B
#define   ADC_SETUPRESULTBUFFER_ID 			 (uint8_t)0x0C




/*
 * Std-types
 *
 */
/** Access mode to group conversion results. */
/* @req SWS_Adc_00528 */
typedef enum
{
  ADC_ACCESS_MODE_SINGLE,
  ADC_ACCESS_MODE_STREAMING
}Adc_GroupAccessModeType;

/** Group trigger source (Not supported). */
/* @req SWS_Adc_00514 */
typedef enum
{
  ADC_TRIGG_SRC_HW,
  ADC_TRIGG_SRC_SW,
}Adc_TriggerSourceType;

/** HW trigger edge (Not supported). */
/* @!req SWS_Adc_00520 */
typedef enum
{
  ADC_HW_TRIG_FALLING_EDGE,
  ADC_HW_TRIG_RISING_EDGE,
  ADC_HW_TRIG_BOTH_EDGES,
}Adc_HwTriggerSignalType;

/** Stream buffer type. */
/* @req SWS_Adc_00519 */
typedef enum
{
  ADC_STREAM_BUFFER_CIRCULAR,
  ADC_STREAM_BUFFER_LINEAR,
}Adc_StreamBufferModeType;

#include "Adc_Cfg.h"

/* Function interface. */
/** Initializes the ADC hardware units and driver. */
/* @req SWS_Adc_00365 */
void Adc_Init(const Adc_ConfigType *ConfigPtr);
#if (ADC_DEINIT_API == STD_ON)
/** Returns all ADC HW Units to a state comparable to their power on reset state. */
/* @req SWS_Adc_00366 */
/* @req SWS_Adc_00228 */
void Adc_DeInit(void);

#endif

/* @req SWS_Adc_00419 */
/** Sets up the result buffer for a group. */
Std_ReturnType Adc_SetupResultBuffer (Adc_GroupType group, Adc_ValueGroupType *bufferPtr);

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/** Starts the conversion of all channels of the requested ADC Channel group. */
/* @req SWS_Adc_00367 */
/* @req SWS_Adc_00259 */
void           Adc_StartGroupConversion (Adc_GroupType group);
/* @req SWS_Adc_00368 */
/* @req SWS_Adc_00260 */
void           Adc_StopGroupConversion (Adc_GroupType group);
#endif
#if (ADC_READ_GROUP_API == STD_ON)
/* @req SWS_Adc_00369 */
/* @req SWS_Adc_00359*/
/** Reads results from last conversion into buffer */
Std_ReturnType Adc_ReadGroup (Adc_GroupType group, Adc_ValueGroupType *dataBufferPtr);
#endif

#if !defined(CFG_HC1X)
/** Reads results from last streaming conversion into buffer */
/* @req SWS_Adc_00375 */
Adc_StreamNumSampleType Adc_GetStreamLastPointer(Adc_GroupType group, Adc_ValueGroupType** PtrToSamplePtr);
#endif

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/** Enables the notification mechanism for the requested ADC Channel group. */
/* @req SWS_Adc_00372 */
/* @req SWS_Adc_00100 */
void           Adc_EnableGroupNotification (Adc_GroupType group);
/** Disables the notification mechanism for the requested ADC Channel group. */
/* @req SWS_Adc_00373 */
/* @req SWS_Adc_00101*/
void           Adc_DisableGroupNotification (Adc_GroupType group);
#endif

/** Returns the conversion status of the requested ADC Channel group. */
/* @req SWS_Adc_00374 */
Adc_StatusType Adc_GetGroupStatus (Adc_GroupType group);

#if (STD_ON == ADC_VERSION_INFO_API)
/* @req SWS_Adc_00376 */
void Adc_GetVersionInfo (Std_VersionInfoType* versioninfo);
#endif

#if (STD_ON == ADC_HW_TRIGGER_API)
/* @!req SWS_Adc_00370 */
/* @!req SWS_Adc_00265*/
void Adc_EnableHardwareTrigger(Adc_GroupType Group);
/* @!req SWS_Adc_00371 */
/* @!req SWS_Adc_00266 */
void Adc_DisableHardwareTrigger(Adc_GroupType Group);
#endif

#endif /*ADC_H_*/

/** @} */

