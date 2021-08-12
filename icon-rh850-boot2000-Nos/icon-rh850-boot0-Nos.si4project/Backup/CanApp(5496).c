/**********************************************************************
*
*   	Copyright 2021 , All Rights Reserved.
*
*	Title:	CanApp.c
*	Author:	mgd
*	Date:	2021.05.10	
*	Description:  This is the standard code file for CanApp.c
*********************************************************************/

/******************************************************************************
* Include header files
*****************************************************************************/
#include "r_typedefs.h"
#include "CanApp.h"
#include "BswM.h"
#include "Dcm.h"

//#include "rtc.h"
#include "r_can.h"
#include "CanIf.h"
#include "CanNm.h"
#include "CanSM.h"
#include "ComM.h"
#include "Com.h"
#include "BswM.h"
#include "CanTp.h"
#include "Dcm.h"
#include "can.h"
#include "Nm.h"
#include "Dcm_Internal.h"
#include "Dem.h"
#include "Dcm_cbk.h"
#include "Can_Cfg.h"
#include "CanIf_Cfg.h"
#include "CanIf.h"
#include "CanSM_Cfg.h"
#include "m_gpio.h"
#include "r_adc.h"

extern CanNm_ConfigType CanNm_Config;
extern Can_ConfigType const Can_Config;
extern CanIf_ConfigType const CanIf_Config;
extern CanSM_ConfigType const CanSM_Config;
extern ComM_ConfigType ComM_Config;
extern Com_ConfigType Com_Config;
extern CanTp_ConfigType CanTpConfig;
extern Dcm_ConfigType DCM_Config;
extern Dem_ConfigType DEM_Config;

//uint8_t can_sleep = TRUE;//For test




/******************************************************************************
* Constant and Macro Definitions using #define
*****************************************************************************/


/******************************************************************************
* Enumerations and Structures and Typedefs
*****************************************************************************/



/******************************************************************************
* Function Prototypes for Private Functions with File Level Scope
*****************************************************************************/
//static void prvCanDrv_ActivateTransceiver(void);
//static void prvCanDrv_Sleep_Transceiver(void);
static void prvCan_Rx_Polling(void);

static void ACC_On_Off_Process(void);
//static void Can_NM_LimpHome_Test(void);

static void Send_can_0x226_message(uint8* can_dat);
extern void vCanApp_ComRx_Processing(void *ComIPduDataPtr,unsigned char Rxpduid);
extern void vCanApp_ComRx_Lost_Processing(uint32_t *EventMask);

static void prvCan_MMI_0x2A2(void *ComIPduDataPtr);
static void prvCan_IPK_0x3F1(void *ComIPduDataPtr);
static void prvCan_GW_ESC_0x125(void *ComIPduDataPtr);
static void prvCan_GW_BCM_0x287(void *ComIPduDataPtr);

uint16 get_KL30_Voltage(void);


/******************************************************************************
* Global and Const Variable Defining Definitions / Initializations
*****************************************************************************/

uint32_t CanSignalStopRecvCnt=0;

static uint8_t CanData[4][8];
const CanId_Recv  CanIdDataRecv[]={
{RX_PDUID_0,  0, 		           false,  NULL,		NULL},
{RX_PDUID_1,  RX_MMI_0x2A2_ID,	    true,  CanData[0],	prvCan_MMI_0x2A2},	
{RX_PDUID_2,  RX_IPK_0x3F1_ID, 	    true,  CanData[1],	prvCan_IPK_0x3F1},	
{RX_PDUID_3,  RX_GW_ESC_0x125_ID,   true,  CanData[2],	prvCan_GW_ESC_0x125},	
{RX_PDUID_4,  RX_GW_BCM_0x287_ID,   true,  CanData[3],	prvCan_GW_BCM_0x287},	

};

/*judge recv can data is update or not */
 uint8_t  CanDataIsNeedUpdate[]={  
	false, // 0 
	false, // 1
	false, // 2
	false, // 3
	false, // 4
	false, // 5
	false, // 6
	false, // 7
	false, // 8	
	false, // 9
	false, // 10
	false, // 11
	false, // 12
	
};

void *CanDataParse[]={
	NULL, // 0
	NULL, // 1
	NULL, // 2
	NULL, // 3
	NULL, // 4
	NULL, // 5
	NULL, // 6
	NULL, // 7
	NULL, // 8	
	NULL, // 9
	NULL, // 10
	NULL, // 11
	NULL, // 12	
};


/*extern unsigned char Vehicle_at_standstill_flag;*/
extern void Save_system_config_data(unsigned short Diag_id,unsigned long len,void *data);
extern void  Diag_Init();


/*********************************************************************\
* ROM Const Variables With File Level Scope                         *
\*********************************************************************/
void Check_Vehicle_Func_Config()
{

}


/*********************************************************************\
*process for recieving can meeage again, clear DTC                  *
\*********************************************************************/

void vCanApp_ComRx_Lost_Processing(uint32_t *EventMask)
{

}

/****************************************************************************\
*Function Name: 	vCanApp_CAN_Task
*Parameters:		void
*Returns:			void
*Description:		
\****************************************************************************/
#define CANAPP_CAN_TASK_PERIOD  (5)
void vCanApp_CAN_Init(void)
{
	Check_Vehicle_Func_Config();
        CAN_MODE_INIT();
	//CanNm_PassiveStartUp(0);
	Nm_NetworkMode(0);
	CanIf_SetPduMode( 0, CANIF_SET_ONLINE );
	(void)Dem_SetOperationCycleState(DEM_POWER, DEM_CYCLE_STATE_START);
}
static int testSnapshot=0;
void vCanApp_CAN_Task(void) 
{
     HP_0x226_Msg_Type  *txMsg;
	static uint8_t sDiag_cnt = 0;	

	{
       // Nm_NetworkRequest(0);
	//	  TASK_FEED_WATCHDOG;
	   sDiag_cnt++;  // 1-2 -1-2 : cycle time is 10ms
               
		//OS_Wait_Resource(RES_CAN, MAX_CAN_WAIT_TIME);  /* wait for semaphore or timeout */
               // OS_Sleep(5);
		Can_MainFunction_Mode(0);
	 	//CanSM_MainFunction();
		if((sDiag_cnt==2))//&&(Dem_data_Init_Flag==true))
		{
			//CanSM_MainFunction();
			CanTp_MainFunction();
			//Dcm_MainFunction();
			sDiag_cnt=0;
			//veh_data.KL30_Vol = get_KL30_Voltage();
			//Com_GetPduBufferBysignalId(TX_SIGLE_HP_0x226_HANDLE,&txMsg);
			//txMsg->resv6 = veh_data.KL30_Vol;			
		}
		//Feed_Dog();

		//CanNm_MainFunction();
		
		//mgd 20210629 test can Tx //if(Communication_Control_Disabled==0)
		{	
                 
	 	// Com_MainFunctionRx();
	 	// Com_MainFunctionTx();
		}
		Set_can_limphome_state();
	 	ACC_On_Off_Process();	
	 	prvCan_Rx_Polling();//can msg handle

		testSnapshot++;
		if(10000 == testSnapshot)
		{
		   Dem_SetEventStatus(DEM_EVENT_BK_TEMP_HIGH,DEM_EVENT_STATUS_FAILED);
		}
	}
}


/**********************************************************************\
 *   Function: CAN_Drv_Stop
 *   Parameters: channel number
 *   Returns: None
 *   Description:   CAN stop
\***********************************************************************/
void prvCanDrv_Stop(void)
{
  //  prvCanDrv_Sleep_Transceiver();
}

/**********************************************************************\
 *   Function: CAN_Drv_Start
 *   Parameters: channel number
 *   Returns: None
 *   Description:   CAN start
\***********************************************************************/
void CAN_Drv_Start(void)
{
  //  prvCanDrv_ActivateTransceiver();
}

/****************************************************************************
*Function Name: 	prvCan_Rx_Polling
*Parameters:		void
*Returns:			void
*Description:		poll to receive message
******************************************************************************/	
static void prvCan_Rx_Polling(void)
{
	uint8_t id_index;
	for(id_index = 0; id_index <10/*RX_PDUID_MAX_NUB*/; id_index++)
	{
	
		if(CanDataIsNeedUpdate[id_index])
		{
			if(CanIdDataRecv[id_index].msg_handler!= NULL)
			{
				CanIdDataRecv[id_index].msg_handler(CanDataParse[id_index]);//trans can msg to mpu
				CanDataIsNeedUpdate[id_index]=false;
			}
			else
			{
				//CanIdDataRecv[id_index].IsNeedUpdate=false;
				//do nothing 
			}			
		}
	
	}

//	can_sleep = TRUE;
}


/**********************************************************************
*  Function: CAN_Is_Normal_Status
*  Parameters: none
*  Returns: ON  : CAN active
*           OFF : CAN passive
*  Description: get the state of the CAN bus
**********************************************************************/
bool CAN_Is_Normal_Status(void)
{
#if NM_ENABLE_VOLCANO_VCT
	//return (V_NWM_NORMAL == v_nwm_get_state( &nwm_slave_instance ));
	return true;
#else
   return 0;
#endif
}

static void Send_can_0x226_message(uint8* can_dat)
{
    if(NULL != can_dat)
    {
		Com_SendSignal(TX_SIGLE_HP_0x226_HANDLE,can_dat);
    }
}

/**********************************************************************
 *	Name:    
 *	Purpose:    
 * 	Parameters:    
 *	Returns:    
 *	Description:   
 *            
 *********************************************************************/
static void prvCan_MMI_0x2A2(void *ComIPduDataPtr)
{
        HP_0x226_Msg_Type  txMsg;
	MMI_0x2A2_Msg_Type *MSG = (MMI_0x2A2_Msg_Type *)ComIPduDataPtr;
	if((veh_data.MMI_HPBacklightModeReq != MSG->MMI_HPBacklightModeReq)||
	   (veh_data.MMI_HPAciveReq != MSG->MMI_HPAciveReq)||
	   (veh_data.MMI_HPBacklightLevelReq != MSG->MMI_HPBacklightLevelReq)
	  )
	{
		veh_data.MMI_BacklightValidflag = DATAVALID;
		veh_data.MMI_HPBacklightModeReq = MSG->MMI_HPBacklightModeReq;
		veh_data.MMI_HPAciveReq = MSG->MMI_HPAciveReq;
		veh_data.MMI_HPBacklightLevelReq = MSG->MMI_HPBacklightLevelReq;
		memset((char*)&txMsg,0,8);
		txMsg.MMI_HPAciveSts = veh_data.MMI_HPAciveReq;
		txMsg.MMI_HPBacklightLevelSts = veh_data.MMI_HPBacklightLevelReq;
		txMsg.MMI_HPBacklightMode = veh_data.MMI_HPBacklightModeReq;
		txMsg.resv6=get_KL30_Voltage()*10;
		Send_can_0x226_message((uint8*)&txMsg);
	}

}
static void prvCan_IPK_0x3F1(void *ComIPduDataPtr)
{
    uint32_t IPKTotalOdometer;
	IPK_0x3F1_Msg_Type *MSG = (IPK_0x3F1_Msg_Type *)ComIPduDataPtr;
	IPKTotalOdometer = (MSG->IPKTotalOdometer_H<<16)|(MSG->IPKTotalOdometer_M<<8)|MSG->IPKTotalOdometer_L;
	if(veh_data.IPKTotalOdometer != IPKTotalOdometer)
	{
		veh_data.IPKTotalOdometer = IPKTotalOdometer;
		veh_data.IPKOdometerValidflag = DATAVALID;
	}

}

static void prvCan_GW_ESC_0x125(void *ComIPduDataPtr)
{
    uint16_t VehicleSpeed;
	GW_ESC_0x125_Msg_Type *MSG=(GW_ESC_0x125_Msg_Type *)ComIPduDataPtr;
	VehicleSpeed=(MSG->VehicleSpeed_H<<5)|MSG->VehicleSpeed_L5;
	if(veh_data.VehicleSpeed !=VehicleSpeed ) 
	{
	     veh_data.VehicleSpeed = VehicleSpeed ;
	     veh_data.VehicleSpeedValidflag = DATAVALID;
	}
 	

}
static void prvCan_GW_BCM_0x287(void *ComIPduDataPtr)
{
	GW_BCM_0x287_Msg_Type *MSG=(GW_BCM_0x287_Msg_Type *)ComIPduDataPtr;
	if((veh_data.Light_HudBrightnessValue != MSG->Light_HudBrightnessValue) || 
	   (veh_data.Light_HudBrightnessUnit  != MSG->Light_HudBrightnessUnit)
	  )
	{
		veh_data.Light_HudBrightnessValue = MSG->Light_HudBrightnessValue;
		veh_data.Light_HudBrightnessUnit  = MSG->Light_HudBrightnessUnit;
		veh_data.Light_BrightnessValidflag = DATAVALID;
	}
}


void prvCan_Transceiver_ctrlIO_init(void)
{
	#if 0
	s32k14x_clock_enable(CAN_TRANS0_EN_CK, CLOCK_ENABLE);
	//enable
	s32k14x_pin_function_set(CAN_TRANS0_EN_PORT, CAN_TRANS0_EN_PIN, PIN_FUNCTION_GPIO);
	s32k14x_pin_dir_set(CAN_TRANS0_EN_PT, CAN_TRANS0_EN_PIN, DIR_OUTPUT);
    //wake	
	s32k14x_pin_function_set(CAN_TRANS0_WAKE_PORT, CAN_TRANS0_WAKE_PIN, PIN_FUNCTION_GPIO);
	s32k14x_pin_dir_set(CAN_TRANS0_WAKE_PT, CAN_TRANS0_WAKE_PIN, DIR_OUTPUT);
	
        s32k14x_pin_function_set(CAN_TRANS0_STBY_PORT, CAN_TRANS0_STBY_PIN, PIN_FUNCTION_GPIO);
	s32k14x_pin_dir_set(CAN_TRANS0_STBY_PT, CAN_TRANS0_STBY_PIN, DIR_OUTPUT);
	
        s32k14x_pin_function_set(CAN_TRANS0_INH_PORT, CAN_TRANS0_INH_PIN, PIN_FUNCTION_GPIO);
	s32k14x_pin_dir_set(CAN_TRANS0_INH_PT, CAN_TRANS0_INH_PIN, DIR_INPUT);
	#endif
}

void CAN_MODE_INIT(void)
{

    prvCan_Transceiver_ctrlIO_init();
	Can_Init(&Can_Config);
	CanIf_Init(&CanIf_Config) ;
	//CanNm_Init(&CanNm_Config);
	
	CanSM_Init(&CanSM_Config);
	ComM_Init(&ComM_Config);
	Com_Init(&Com_Config);
	BswM_Init(NULL);
	CanTp_Init( &CanTpConfig);
	osal_nv_init(NULL);

	Dcm_Init(&DCM_Config);
//	
	Dem_PreInit(&DEM_Config);
	
	Dem_Init();	
	Communication_Control_Disabled=0;

}
static uint8_t AccOn;
static void ACC_On_Off_Process(void) 
{

    static uint8_t AccSts = 0xf;
AccOn = 1;
	//Nm_NetworkRequest(0);
CanIf_SetPduMode( 0, CANIF_SET_ONLINE );
	if(!AccSts && AccOn) // acc on
	{ 
		//Nm_NetworkRequest(0);
		//Nm_NetworkMode(0);
	}
	else if(AccSts && !AccOn) //acc off
	{
		//Nm_NetworkRelease( 0 );
	}
	AccSts = AccOn;

}


void Set_can_busoff_state(bool temp)
{
	//G_DTCVariable[BUS_OFF].TestResult = temp; 
	if(temp == 0)//bus off
	{
//		Dem_SetEventStatus(DEM_EVENT_CAN_BUSOFF, DEM_EVENT_STATUS_FAILED);
//		Dem_SetEventStatus(DEM_EVENT_CAN_ERROR, DEM_EVENT_STATUS_FAILED); 
	}
	else if(temp == 1)//bus normall
	{
//		Dem_SetEventStatus(DEM_EVENT_CAN_BUSOFF, DEM_EVENT_STATUS_PASSED);
//		Dem_SetEventStatus(DEM_EVENT_CAN_ERROR, DEM_EVENT_STATUS_PASSED);
	}
	else//do nothing
	{
	
	}

	//ReleaseExternalRxTxBuffers();
}
void Set_can_limphome_state(void)
{
	//uint8_t limphome_status = return_limphome_status();

	//if(limphome_status != 0x01)
	//{
//		Dem_SetEventStatus(DEM_EVENT_NETWORK_MANGE_LIMPHOME , DEM_EVENT_STATUS_PASSED);
	//}
	//else
	//{
//		Dem_SetEventStatus(DEM_EVENT_NETWORK_MANGE_LIMPHOME, DEM_EVENT_STATUS_FAILED);
	//}
}

uint16 get_KL30_Voltage(void)
{
   uint32 ADvol;
   ADvol = R_ADCA0_PinRead(AP0_6);
   ADvol = ADvol*33*110/4096+5;
   return (uint16)(ADvol/10);
}

