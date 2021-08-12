//#include "CanSM.h"
#include "CanSM_Cfg.h"

#define CANIF_CONTROLLER_ID 0 //1//mgd 2018-08-02
#define CANIF_CONTROLLER_CNT 1
#define COM_NETWORK_HANDLE 0
#define CANSM_BORTIME_TXENSURED 200  //2000MS
#define CANSM_BORTIME_L1  100//8//10
#define CANSM_BORTIME_L2  100//8//10
#define CANSM_BORCNT_L1ToL2 10 //8//10
#define CANSM_BORTX_CONFIRM_POLL false
#define CANSM_MODEREQ_REPETION_MAX 5
#define CANSM_MODEREQ_REPETION_TIME 200

CanSM_ControllerType const CanSM_Controller = {
	CANIF_CONTROLLER_ID,
} ;

CanSM_NetworkType const CanSM_Network ={
	&CanSM_Controller,
	CANIF_CONTROLLER_CNT,
	COM_NETWORK_HANDLE,
	CANSM_BORTIME_TXENSURED,
	CANSM_BORTIME_L1,
	CANSM_BORTIME_L2,
	CANSM_BORCNT_L1ToL2,
	CANSM_BORTX_CONFIRM_POLL ,
//#if (USE_DEM)
#if define USE_DEM
	Dem_EventIdType					CanSMDemEventId;
#endif
#if (CANSM_CAN_TRCV_SUPPORT == STD_ON)
	const uint8						CanIfTransceiverId;
#endif
} ;

CanSM_ConfigType const CanSM_Config = {
	CANSM_MODEREQ_REPETION_MAX,
	CANSM_MODEREQ_REPETION_TIME,
	&CanSM_Network
} ;

