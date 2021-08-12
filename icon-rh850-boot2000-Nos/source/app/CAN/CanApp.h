/**********************************************************************
*	Title:	CanApp.h
*	Author:	Charles Wang
*	Date:	2021.07.15	
*	Description:  This is the standard code file for CanApp.h
*********************************************************************/
#ifndef CANAPP_H
#define CANAPP_H
#include "datacenter.h"
/******************************************************************************
* Include header files
*****************************************************************************/

/******************************************************************************
* Constant and Macro Definitions using #define
*****************************************************************************/
//#define CAN 0
//#define NM_ENABLE_VOLCANO_VCT true

//#define AS21_VTP false
#define ACC_ON   1
#define ACC_OFF 0

#define AUTO_LIGHT_ON   1
#define AUTO_LIGHT_OFF  0

typedef enum
{
	RX_PDUID_0,
	RX_PDUID_1,
	RX_PDUID_2,
	RX_PDUID_3,
	RX_PDUID_4,
	RX_PDUID_5,
	RX_PDUID_6,
	RX_PDUID_7,
	RX_PDUID_8,
	RX_PDUID_9,
	RX_PDUID_10,
	RX_PDUID_11,
	RX_PDUID_12,
	RX_PDUID_13,	
	RX_PDUID_MAX_NUB
}CAN_RX_PDUID;






/*===========================================================================*\
 * #define MACROS
\*===========================================================================*/
/*
 * define to CANpi_WAKE() for hardware where transceiver
 * wake-up is recognized via INHibit-pin
 * else to CANpi_ERR()
 * Purpose: Check on the CAN_Wake pin (INH) if transceiver enters 
 *          sleep mode properly
 */
/*
 * high level at GPIO CAN_WAKE means that CAN Transceiver is sleeping
 */
#define RX_MMI_0x2A2_ID    				0x2A2
#define RX_IPK_0x3F1_ID    				0x3F1
#define RX_GW_ESC_0x125_ID    			0x125
#define RX_GW_BCM_0x287_ID    			0x287

#define TX_SIGLE_HP_0x226_HANDLE      (0)


/******************************************************************************
* Enumerations and Structures and Typedefs
*****************************************************************************/
typedef void (*msg_handler)(void); 


/*need parse can data*/

typedef struct {
	uint8_t		resv0:8;	
	uint8_t		resv1:8;	
	uint8_t		resv2:8;
	uint8_t		MMI_HPBacklightModeReq:2;
	uint8_t		MMI_HPAciveReq:2;
	uint8_t		MMI_HPBacklightLevelReq:4;	
	uint8_t		resv4:8;
	uint8_t		resv5:8;	
	uint8_t		resv6:8;
	uint8_t		resv7:8;
} MMI_0x2A2_Msg_Type;

typedef struct {
	uint8_t		IPKTotalOdometer_H:8;
	uint8_t		IPKTotalOdometer_M:8;
	uint8_t		IPKTotalOdometer_L:8;
	uint8_t		resv3:8;
	uint8_t		resv4:8;
	uint8_t		resv5:8;
	uint8_t		resv6:8;
	uint8_t		resv7:8;
} IPK_0x3F1_Msg_Type;

typedef struct {
	uint8_t		resv0:8;
	uint8_t		VehicleSpeed_H:8;
	uint8_t		resv2:3;
	uint8_t		VehicleSpeed_L5:5;
	uint8_t		resv3:8;
	uint8_t		resv4:8;
	uint8_t		resv5:8;
	uint8_t		resv6:8;
	uint8_t		resv7:8;
} GW_ESC_0x125_Msg_Type;

typedef struct {
	uint8_t		resv0:8;
	uint8_t		resv1:8;
	uint8_t		resv2:8;	
	uint8_t		resv3:8;	
	uint8_t		Light_HudBrightnessValue:7;
	uint8_t		resv4:1;
	uint8_t		resv5:4;
	uint8_t		Light_HudBrightnessUnit:2;
	uint8_t		resv5_2:2;	
	uint8_t		resv6:8;
	uint8_t		resv7:8;

} GW_BCM_0x287_Msg_Type;

typedef struct {
	uint8_t		MMI_HPBacklightLevelSts:4;
	uint8_t		MMI_HPAciveSts:2;
	uint8_t		MMI_HPBacklightMode:2;	
	uint8_t		resv1:8;	
	uint8_t		resv2:8;	
	uint8_t		resv3:8;
	uint8_t		resv4:8;
	uint8_t		resv5:8;	
	uint8_t		resv6:8;
	uint8_t		resv7:8;
} HP_0x226_Msg_Type;

 
typedef   void (*msg_handler_t)(void *ComIPduDataPtr); 
typedef struct can_data_tag
{
	uint16_t  RxPduId;
	uint32_t CanId;
	uint8_t  IsNeedParse;
	void *ComIPduDataPtr;
	msg_handler_t msg_handler;
}CanId_Recv;




/******************************************************************************
* Global and Const Variable Defining Definitions / Initializations
*****************************************************************************/

extern const  CanId_Recv CanIdDataRecv[];
extern uint8_t  CanDataIsNeedUpdate[];
extern void *CanDataParse[];
extern uint32_t CanSignalStopRecvCnt;
//extern uint8_t SwcCtrl;//SWC CTRL
//extern uint8_t IHU_DISP_BUF[8];
//extern TMR_Type_T RealseIcuCtrlSWCTime;
//extern uint8_t PhoneNeedSWC;
//extern uint8_t tx_speed[3];
//extern uint8_t tx_wheel_angle[2];
//extern uint8_t recovery_status;

extern void CAN_MODE_INIT(void);
extern void Can_Pdu_RX_Task(void *pvParameters);
extern void vCanApp_CAN_Task(void); 
extern bool CAN_Get_Status(void);
extern bool CAN_Is_Normal_Status(void);
extern bool CAN_Bus_Wake_Up(void);
extern void prvCanDrv_Stop(void);
extern void CAN_Drv_Start(void);
bool vCan_Set_Cur_Time(const uint8_t * buf);



extern void Set_can_busoff_state(bool temp);
extern void Set_can_limphome_state(void);
extern void Check_Vehicle_Func_Config(void);
extern void prvCanApp_Initialize_CAN(void);
extern void Control_KL15_Communication_enable(void);
extern void Control_KL15_Communication_disable(void);
extern void Control_vol_Communication_enable(void);
extern void Control_vol_Communication_disable(void);


#endif

