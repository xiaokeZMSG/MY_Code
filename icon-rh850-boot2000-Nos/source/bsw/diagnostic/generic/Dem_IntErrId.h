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

#ifndef DEM_INTERRID_H_
#define DEM_INTERRID_H_

#endif /*DEM_INTERRID_H_*/
/*
 * Definition of event IDs used by BSW
 * NB! Must be unique for each event!
 */

enum {
	// Event IDs from DEM module
	DEM_EVENT_ID_NULL = 0,			// Do not change this entry!!!

	// Event IDs from MCU
	MCU_E_CLOCK_FAILURE,

	// Event IDs from CAN
	CANTRCV_E_NO_TRCV_CONTROL,
	//CANTP_E_OPER_NOT_SUPPORTED,
	CANTP_E_COMM =4,
	CANNM_E_CANIF_TRANSMIT_ERROR,
	
	CANIF_TRCV_E_TRANSCEIVER,
	
	CANIF_STOPPED,
	CANIF_E_FULL_TX_BUFFER,
	CAN_E_TIMEOUT,

	// Event IDs from EEPROM
	

	// Event IDs from flash


	// Event IDs from LIN
	

	// Event IDs from ECU


	// Event IDs from COM
//	COMM_E_NET_START_IND_CHANNEL_<X>,

	// Event IDs from PDUR


	// Event IDs from WDGM
	WDGM_E_ALIVE_SUPERVISION,
	WDGM_E_SET_MODE,

	// DEM last event id for BSW
	DEM_EVENT_ID_LAST_FOR_BSW
};
