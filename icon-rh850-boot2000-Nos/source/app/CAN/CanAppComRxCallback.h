#ifndef __CAN_SWC_TEST_H_
#define __CAN_SWC_TEST_H_

#include "com.h"


typedef struct
{
	//unsigned char rcv_data[8];
	unsigned char checksum_err_count;
	unsigned char rllcnt_err_count;
	unsigned char rolling_count;
}Data_chksum_rllcnt_type;


/********SEND************/
#define SGWM_TX_TBOX_Rm_CMD1_0x103						0
#define SGWM_TX_TBOX_Rm_CMD2_0x105						1
#define SGWM_TX_AC_Control_CMD_0x433						2
#define SGWM_TX_BCM_SET_CMD1_0x435						3
#define SGWM_TX_BCM_SET_CMD2_0x431						4
#define SGWM_TX_SMM_SET_CMD1_0x434						5
#define SGWM_TX_Platform_ICE_DATA_0x532						6
#define SGWM_TX_VT_Send_time_0x53D						7
#define SGWM_TX_EPS_SET_CMD_0x421						8
#define SGWM_TX_NAV_STATUS_0x41D						9
#define SGWM_TX_Vehicle_Set_Ctl_CMD_0x430						10
#define SGWM_TX_FACTORY_0x77B						11

#define LAST_SEND			11


/*******RECV************/
#define SGWM_RX_BCM_RM_CMD_1_0x10B				 	(LAST_SEND+1)
#define SGWM_RX_BCM_RM_CMD_2_0x102				 	(LAST_SEND+2)
#define SGWM_RX_Vehicle_odo_0x120				 	(LAST_SEND+3)
#define SGWM_RX_IC_Indication_Data_0x53A				 	(LAST_SEND+4)
#define SGWM_RX_IC_Indication_Data_1_0x471				 	(LAST_SEND+5)
#define SGWM_RX_IC_Indication_Data_2_0x473				 	(LAST_SEND+6)
#define SGWM_RX_IC_Indication_Data_3_0x475				 	(LAST_SEND+7)
#define SGWM_RX_IC_Indication_Data_4_0x477				 	(LAST_SEND+8)
#define SGWM_RX_Vehicle_Info_Data_1_0x111				 	(LAST_SEND+9)
#define SGWM_RX_Vehicle_Info_Data_2_0x113				 	(LAST_SEND+10)
#define SGWM_RX_Vehicle_Info_Data_3_0x115				 	(LAST_SEND+11)
#define SGWM_RX_Vehicle_Info_Data_4_0x119				 	(LAST_SEND+12)
#define SGWM_RX_Vehicle_Info_Data_5_0x11d				 	(LAST_SEND+13)
#define SGWM_RX_AC_STATUS_0x43B				 	(LAST_SEND+14)
#define SGWM_RX_BCM_Set_Status_1_0x43D				 	(LAST_SEND+15)
#define SGWM_RX_BCM_Set_Status_2_0x439				 	(LAST_SEND+16)
#define SGWM_RX_SMM_SET_1_0x43C				 	(LAST_SEND+17)
#define SGWM_RX_PPEI_General_Status_0x1F1				 	(LAST_SEND+18)
#define SGWM_RX_PPEI_Wheel_Angle_0x1E5				 	(LAST_SEND+19)
#define SGWM_RX_PPEI_Radar_info_0x53B				 	(LAST_SEND+20)
#define SGWM_RX_PPEI_Engine_status_0x0C9				 	(LAST_SEND+21)
#define SGWM_RX_FACTORY_0x77A				 	(LAST_SEND+22)


/*******RECV SIGNAL************/
#define SGWM_RX_BCM_RM_CMD_1_0x10B_SIGNAL	 				(1)
#define SGWM_RX_BCM_RM_CMD_2_0x102_SIGNAL	 				(2)
#define SGWM_RX_Vehicle_odo_0x120_SIGNAL	 				(3)
#define SGWM_RX_IC_Indication_Data_0x53A_SIGNAL	 				(4)
#define SGWM_RX_IC_Indication_Data_1_0x471_SIGNAL	 				(5)
#define SGWM_RX_IC_Indication_Data_2_0x473_SIGNAL	 				(6)
#define SGWM_RX_IC_Indication_Data_3_0x475_SIGNAL	 				(7)
#define SGWM_RX_IC_Indication_Data_4_0x477_SIGNAL	 				(8)
#define SGWM_RX_Vehicle_Info_Data_1_0x111_SIGNAL	 				(9)
#define SGWM_RX_Vehicle_Info_Data_2_0x113_SIGNAL	 				(10)
#define SGWM_RX_Vehicle_Info_Data_3_0x115_SIGNAL	 				(11)
#define SGWM_RX_Vehicle_Info_Data_4_0x119_SIGNAL	 				(12)
#define SGWM_RX_Vehicle_Info_Data_5_0x11d_SIGNAL	 				(13)
#define SGWM_RX_AC_STATUS_0x43B_SIGNAL	 				(14)
#define SGWM_RX_BCM_Set_Status_1_0x43D_SIGNAL	 				(15)
#define SGWM_RX_BCM_Set_Status_2_0x439_SIGNAL	 				(16)
#define SGWM_RX_SMM_SET_1_0x43C_SIGNAL	 				(17)
#define SGWM_RX_PPEI_General_Status_0x1F1_SIGNAL	 				(18)
#define SGWM_RX_PPEI_Wheel_Angle_0x1E5_SIGNAL	 				(19)
#define SGWM_RX_PPEI_Radar_info_0x53B_SIGNAL	 				(20)
#define SGWM_RX_PPEI_Engine_status_0x0C9_SIGNAL	 				(21)
#define SGWM_RX_FACTORY_0x77A_SIGNAL	 				(22)


/*SEND*/
#define SGWM_TX_TBOX_Rm_CMD1_0x103_NOTIFY_INDEX      		SGWM_TX_TBOX_Rm_CMD1_0x103
#define SGWM_TX_TBOX_Rm_CMD2_0x105_NOTIFY_INDEX      		SGWM_TX_TBOX_Rm_CMD2_0x105
#define SGWM_TX_AC_Control_CMD_0x433_NOTIFY_INDEX      		SGWM_TX_AC_Control_CMD_0x433
#define SGWM_TX_BCM_SET_CMD1_0x435_NOTIFY_INDEX      		SGWM_TX_BCM_SET_CMD1_0x435
#define SGWM_TX_BCM_SET_CMD2_0x431_NOTIFY_INDEX      		SGWM_TX_BCM_SET_CMD2_0x431
#define SGWM_TX_SMM_SET_CMD1_0x434_NOTIFY_INDEX      		SGWM_TX_SMM_SET_CMD1_0x434
#define SGWM_TX_Platform_ICE_DATA_0x532_NOTIFY_INDEX      		SGWM_TX_Platform_ICE_DATA_0x532
#define SGWM_TX_VT_Send_time_0x53D_NOTIFY_INDEX      		SGWM_TX_VT_Send_time_0x53D
#define SGWM_TX_EPS_SET_CMD_0x421_NOTIFY_INDEX      		SGWM_TX_EPS_SET_CMD_0x421
#define SGWM_TX_NAV_STATUS_0x41D_NOTIFY_INDEX      		SGWM_TX_NAV_STATUS_0x41D
#define SGWM_TX_Vehicle_Set_Ctl_CMD_0x430_NOTIFY_INDEX      		SGWM_TX_Vehicle_Set_Ctl_CMD_0x430
#define SGWM_TX_FACTORY_0x77B_NOTIFY_INDEX      		SGWM_TX_FACTORY_0x77B

//===============================================
#if 0
  /*RECV*/ 
#define SGWM_RX_BCM_RM_CMD_1_0x10B_NOTIFY_INDEX 					SGWM_RX_BCM_RM_CMD_1_0x10B
#define SGWM_RX_BCM_RM_CMD_2_0x102_NOTIFY_INDEX 					SGWM_RX_BCM_RM_CMD_2_0x102
#define SGWM_RX_Vehicle_odo_0x120_NOTIFY_INDEX 					SGWM_RX_Vehicle_odo_0x120
#define SGWM_RX_IC_Indication_Data_0x53A_NOTIFY_INDEX 					SGWM_RX_IC_Indication_Data_0x53A
#define SGWM_RX_IC_Indication_Data_1_0x471_NOTIFY_INDEX 					SGWM_RX_IC_Indication_Data_1_0x471
#define SGWM_RX_IC_Indication_Data_2_0x473_NOTIFY_INDEX 					SGWM_RX_IC_Indication_Data_2_0x473
#define SGWM_RX_IC_Indication_Data_3_0x475_NOTIFY_INDEX 					SGWM_RX_IC_Indication_Data_3_0x475
#define SGWM_RX_IC_Indication_Data_4_0x477_NOTIFY_INDEX 					SGWM_RX_IC_Indication_Data_4_0x477
#define SGWM_RX_Vehicle_Info_Data_1_0x111_NOTIFY_INDEX 					SGWM_RX_Vehicle_Info_Data_1_0x111
#define SGWM_RX_Vehicle_Info_Data_2_0x113_NOTIFY_INDEX 					SGWM_RX_Vehicle_Info_Data_2_0x113
#define SGWM_RX_Vehicle_Info_Data_3_0x115_NOTIFY_INDEX 					SGWM_RX_Vehicle_Info_Data_3_0x115
#define SGWM_RX_Vehicle_Info_Data_4_0x119_NOTIFY_INDEX 					SGWM_RX_Vehicle_Info_Data_4_0x119
#define SGWM_RX_Vehicle_Info_Data_5_0x11d_NOTIFY_INDEX 					SGWM_RX_Vehicle_Info_Data_5_0x11d
#define SGWM_RX_AC_STATUS_0x43B_NOTIFY_INDEX 					SGWM_RX_AC_STATUS_0x43B
#define SGWM_RX_BCM_Set_Status_1_0x43D_NOTIFY_INDEX 					SGWM_RX_BCM_Set_Status_1_0x43D
#define SGWM_RX_BCM_Set_Status_2_0x439_NOTIFY_INDEX 					SGWM_RX_BCM_Set_Status_2_0x439
#define SGWM_RX_SMM_SET_1_0x43C_NOTIFY_INDEX 					SGWM_RX_SMM_SET_1_0x43C
#define SGWM_RX_PPEI_General_Status_0x1F1_NOTIFY_INDEX 					SGWM_RX_PPEI_General_Status_0x1F1
#define SGWM_RX_PPEI_Wheel_Angle_0x1E5_NOTIFY_INDEX 					SGWM_RX_PPEI_Wheel_Angle_0x1E5
#define SGWM_RX_PPEI_Radar_info_0x53B_NOTIFY_INDEX 					SGWM_RX_PPEI_Radar_info_0x53B
#define SGWM_RX_PPEI_Engine_status_0x0C9_NOTIFY_INDEX 					SGWM_RX_PPEI_Engine_status_0x0C9
#define SGWM_RX_FACTORY_0x77A_NOTIFY_INDEX 					SGWM_RX_FACTORY_0x77A
#endif
/****************extern******************/
//extern uint16_t canmsg_mask;
//extern uint32_t canmsg_rcv_passed_mask;
extern void Set_CamMsg_Rcv_Passed_Mask(uint8_t ComRxId);
extern void Clr_CamMsg_Rcv_Passed_Mask(uint8_t ComRxId);
extern uint8_t Get_CamMsg_Rcv_Passed_Mask(uint8_t ComRxId);


/*****************Message copy*********************/



/********************Message timeout(node lost)*********************/
void RX_MMI_0x2A2_TimeoutCallout (uint16_t signal_id);
void RX_GW_0x287_TimeoutCallout (uint16_t signal_id);
/************************Message RX callout******************************/
#endif
