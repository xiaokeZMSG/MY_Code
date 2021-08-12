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


#ifndef NMSTACK_TYPES_H_
#define NMSTACK_TYPES_H_

/** Return type for NM functions. Derived from Std_ReturnType. */
typedef enum {
	NM_E_OK,
	NM_E_NOT_OK,
	NM_E_NOT_EXECUTED
} Nm_ReturnType;

/** Operational modes of the network management */
typedef enum {
	NO_ACTION							=0x00,
	NM_ACTION_START					=0x01, // NMreset
	NM_ACTION_WAIT_SENDTOKEN		=0x02, // NM normal mode (start Ttyp,wait to send ring msg)
	NM_ACTION_WAIT_RINGMSG			=0x03, // NM normal mode (start Tmax,wait to receive a ring msg)
	NM_ACTION_LH_WAIT_LIMPHOME_TX	=0x04, // limo home 
	NM_ACTION_LH_PREPARE_SLEEP		=0x05, // limp home prepare sleep
	NM_ACTION_GO_BUSSLEEP			=0x06, // wait to bus sleep mode (limphome)
	NM_ACTION_BUS_SLEEP				=0x07, // bus sleep mode
	NM_ACTION_REPEAT					=0x80,
} NmActionType;

typedef enum {
	CANNM_DEFAULT				=0x00,
	CANNM_RESERVED			=0x01,
	CANNM_CAN					=0X02,
	CANNM_KL15				=0X05,  // ACC high
} CanNm_Internal_WakeUpSouresType;

typedef enum {
	CANNM_ACITVE_CAN						=0X04,  // CAN working
	CANNM_ACITVE_KL15_LOW_APP_ALVIE	=0X08,  // acc low but App working
	CANNM_ACITVE_KL15						=0X10,  // ACC high
} CanNm_Internal_NmActiveSouresType;
 


typedef enum {
	NM_MODE_BUS_SLEEP,
	NM_MODE_PREPARE_BUS_SLEEP,
	NM_MODE_SYNCHRONIZE,
	NM_MODE_NETWORK
} Nm_ModeType;

/** States of the network management state machine */
typedef enum {
	NM_STATE_UNINIT,
	NM_STATE_BUS_SLEEP,
	NM_STATE_PREPARE_BUS_SLEEP,
	NM_STATE_READY_SLEEP,
	NM_STATE_NORMAL_OPERATION,
	NM_STATE_REPEAT_MESSAGE,
	NM_STATE_SYNCHRONIZE
} Nm_StateType;

/** BusNm Type */
typedef enum {
	NM_BUSNM_CANNM	= 0,
	NM_BUSNM_FRNM	= 1,
	NM_BUSNM_LINNM	= 2,
	NM_BUSNM_UNDEF	= 0xFF
} Nm_BusNmType;


#endif /* NMSTACK_TYPES_H_ */
