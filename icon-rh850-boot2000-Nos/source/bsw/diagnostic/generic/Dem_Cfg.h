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
//#warning "This default file may only be used as an example!"

#ifndef DEM_CFG_H_
#define DEM_CFG_H_
/*
 * DEM General
 */
#define DEM_USE_PRIMARY_MEMORY_SUPPORT STD_ON

#define DEM_VERSION_INFO_API    			STD_ON		// Activate/Deactivate ver info API.
//#define DEM_DEV_ERROR_DETECT				STD_ON		// Activate/Deactivate Dev Error Detection and Notification.
#define DEM_OBD_SUPPORT						STD_OFF
#define DEM_PTO_SUPPORT						STD_OFF
#define DEM_TYPE_OF_DTC_SUPPORTED			DEM_DTC_TRANSLATION_ISO15031_6  //STD_ON		// ISO14229-1
#define DEM_DTC_STATUS_AVAILABILITY_MASK	0x3B//0x79//0xFF
#define DEM_CLEAR_ALL_EVENTS				STD_ON		// All event or only events with DTC is cleared with Dem_ClearDTC


#define DEM_BSW_ERROR_BUFFER_SIZE			20	// Max nr of elements in BSW error buffer (0..255)
#define DEM_FF_DID_LENGTH					TBD	// Length of DID & PID of FreezeFrames in Bytes.
#define DEM_MAX_NUMBER_EVENT_ENTRY_MIR		0	// Max nr of events stored in mirror memory.
#define DEM_MAX_NUMBER_EVENT_ENTRY_PER		0	// Max nr of events stored in permanent memory.
#define DEM_MAX_NUMBER_EVENT_ENTRY_PRI		13	// Max nr of events stored in primary memory.
#define DEM_MAX_NUMBER_EVENT_ENTRY_SEC		0	// Max nr of events stored in secondary memory.
#define DEM_MAX_NUMBER_PRESTORED_FF			0	// Max nr of prestored FreezeFrames. 0=Not supported.

/*
 * Size limitations of the types derived from DemGeneral
 */
#define DEM_MAX_NR_OF_RECORDS_IN_EXTENDED_DATA	2///4	// 0..253 according to Autosar
#define DEM_MAX_NR_OF_EVENT_DESTINATION			 2///4	// 0..4 according to Autosar

/*
 * Size limitations of storage area
 */
#define DEM_MAX_NUMBER_EVENT_ENTRY              0x6//48

#define DEM_MAX_SIZE_EXT_DATA					4	// Max number of bytes in one extended data record
#define DEM_MAX_NUMBER_EVENT					0x6//48// Max number of events to keep status on


#define DEM_MAX_NUMBER_EVENT_PRI_MEM			(DEM_MAX_NUMBER_EVENT_ENTRY_PRI)	// Max number of events status to store in primary memory
#define DEM_MAX_NUMBER_FF_DATA_PRI_MEM			0x6//48									// Max number of freeze frames to store in primary memory
#define DEM_MAX_NUMBER_EXT_DATA_PRI_MEM			0x6//48									// Max number of extended data to store in primary memory
#define DEM_MAX_NUMBER_AGING_PRI_MEM            0x6//48

#define DEM_EVENT_PRIMARY_NVM_BLOCK_HANDLE      	0
#define DEM_FREEZE_FRAME_PRIMARY_NVM_BLOCK_HANDLE  1
#define DEM_AGING_PRIMARY_NVM_BLOCK_HANDLE 			2
#define DEM_EXTENDED_DATA_PRIMARY_NVM_BLOCK_HANDLE  3


//====================================================================
#define DEM_EVENT_VOLTAGE_HIGH					(0x0001)
#define DEM_EVENT_VOLTAGE_LOW					(0x0002)
#define DEM_EVENT_CAN_BUSOFF					(0x0003)
#define DEM_EVENT_BK_TEMP_HIGH            		(0x0004)
#define DEM_EVENT_LCD_TEMP_HIGH 				(0x0005)
#define DEM_EVENT_DESER_ERR 					(0x0006)
#define DEM_EVENT_MMI_2A2_LOST 					(0x0007)
#define DEM_EVENT_GW_287_LOST 					(0x0008)
#define DEM_EVENT_END                           (0x0009)


//=====================================================================



#define   	CONDITION_LOC_VOL			0x01	// Optional
#define    	CONDITION_PHY_BUS			0x02	// Optional
#define 	CONDITION_T_STARTUP_ACC     0x03
//#define	 	CONDITION_T_CRANK			0x04
#define	 	CONDITION_DEBUG_AMP         0x04
#define	 	CONDITION_DEBUG_USB			0x05
#define	 	CONDITION_DEBUG_MIC			0x06
#define	 	CONDITION_DEBUG_TUNER		0x07
#define	 	CONDITION_DEBUG_SWC			0x08
#define	 	CONDITION_DEBUG_CAN			0x09
#define 	CONDITION_T_ENGINE_ON       0x0A
#define 	CONDITION_T_IGN_ON       	0x0B
#define    	CONDITION_COM_ST_1s         0x0C  //1s after comminucation modern  starting   
#define 	DEM_ENABLE_CONDITION_EOL 	0xff
#define 	DEM_NUM_ENABLECONDITIONS 	13



#endif /*DEM_CFG_H_*/
