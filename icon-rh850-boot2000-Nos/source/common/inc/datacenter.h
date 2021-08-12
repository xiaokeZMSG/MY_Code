/*
 * Copyright (c) 20109-2020, Team
 * file: datacenter.h
 *  Description:  This file contains sip channel be setting
 *
 * Change Logs:
 * Date           Author         VER   Notes
 * 2020-03-11    maguangdong     0.1   First edition
 */
#ifndef __DATACENTER_H__
#define __DATACENTER_H__
#include <r_device.h>

#define DATAVALID  (1)
#define ACCON      (1)
#define ACCOFF     (0)
/********************CAN ÐéÄâ¼ü ***********************************************************************************/
typedef struct veh_data_tag
{	
	uint8_t  MMI_HPBacklightModeReq;
	uint8_t  MMI_HPAciveReq;
	uint8_t  MMI_HPBacklightLevelReq;
	uint8_t  MMI_BacklightValidflag;
	
	uint32_t IPKTotalOdometer;
	uint8_t  IPKOdometerValidflag;
	uint8_t  VehicleSpeedValidflag;
	uint16_t VehicleSpeed;
	uint8_t  Light_HudBrightnessValue;	
	uint8_t  Light_HudBrightnessUnit;
	uint8_t  Light_BrightnessValidflag;
	uint16_t KL30_Vol;

	uint8_t IO_SetBacklightLevel;


}veh_data_T;

extern veh_data_T veh_data;


#endif /*__DATACENTER_H__*/

    
