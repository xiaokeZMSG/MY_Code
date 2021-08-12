/**********************************************************************
*	Title:	DtcApp.c
*	Author:	mgd
*	Date:	2021.07.16	
*	Description:  This is the standard code file for DtcApp.c
*********************************************************************/

/******************************************************************************
* Include header files
*****************************************************************************/
#include "r_typedefs.h"
#include "osal.h"
#include "DtcApp.h"
#include "m_gpio.h"
#include "r_adc.h"
#include "dem_Types.h"
#include "Dem_cfg.h"


/******************************************************************************
* Constant and Macro Definitions using #define
*****************************************************************************/
#define CHECKCOUNT           (5)
#define DTC_OK               (0)
#define POWER_VOL_HIGH       (160)/*16V*/
#define POWER_VOL_LOW        (90) /*9V*/
#define POWER_VOL_HYSTER     (5)  /*0.5V*/
/******************************************************************************
* Enumerations and Structures and Typedefs
*****************************************************************************/
typedef struct dtc_data_tag
{
   uint8_t  BacklightTempSts;
   uint8_t  LcdTempSts;
   uint8_t  ChipSts;
   uint8_t  BusoffSts;
   uint8_t  PowerVolHSts;
   uint8_t  PowerVolLSts;
   uint8_t  MMI_2A2_lost;
   uint8_t  GW_287_lost;
}dtc_data_t;
typedef struct Dtc_det_tag
{   
   uint8_t  DemEvntID;
   uint8_t  *status;
   uint8_t (*DtcCondition)(struct Dtc_det_tag *);
}dtc_det_t;



/****************************************************************************
* Function Prototypes for Private Functions with File Level Scope
*****************************************************************************/

static uint8_t dtcCondtion_Vol(dtc_det_t* dtc);

void voltageDetectTask(void);
uint16_t get_KL30_Voltage(void);


/****************************************************************************
* Global and Const Variable Defining Definitions / Initializations
*****************************************************************************/
static dtc_data_t dtc_data;
static const dtc_det_t dtc_det_table[]={

	{DEM_EVENT_VOLTAGE_HIGH,  &dtc_data.PowerVolHSts,        NULL},
	{DEM_EVENT_VOLTAGE_LOW,   &dtc_data.PowerVolLSts,        NULL},
	{DEM_EVENT_CAN_BUSOFF,    &dtc_data.BusoffSts,        dtcCondtion_Vol},
	{DEM_EVENT_BK_TEMP_HIGH,  &dtc_data.BacklightTempSts, dtcCondtion_Vol},
	{DEM_EVENT_LCD_TEMP_HIGH, &dtc_data.LcdTempSts,       dtcCondtion_Vol},
	{DEM_EVENT_DESER_ERR,     &dtc_data.ChipSts,          dtcCondtion_Vol},
	{DEM_EVENT_MMI_2A2_LOST,  &dtc_data.MMI_2A2_lost,        NULL},
	{DEM_EVENT_GW_287_LOST,   &dtc_data.GW_287_lost,        NULL},
};

const uint8_t DTC_DET_NUM = sizeof(dtc_det_table)/sizeof(dtc_det_t);

/****************************************************************************
*Function Name: 	vDtc_init_data
*Parameters:		void
*Returns:		void
*Description:		
******************************************************************************/
void vDtc_init_data(void)
{
   memset((char*)&dtc_data, DTC_UNINIT, sizeof(dtc_data_t));
}

/****************************************************************************
*Function Name: 	vCanApp_CAN_Task
*Parameters:		void
*Returns:		void
*Description:		
******************************************************************************/
static uint8_t dtc_index = 0;
void vDtcApp_Task(void) 
{
   dtc_det_t *dtc;
   dtc_index = dtc_index%DTC_DET_NUM;
   dtc = (dtc_det_t*)&dtc_det_table[dtc_index];
   if(NULL != dtc->DtcCondition )
   {
   	   if(true != dtc->DtcCondition(dtc))
   	   {
   	        dtc_index++;	   
   	        return;
   	   }
   }
   if(DTC_ERROR == *dtc->status)
   {
        Dem_SetEventStatus(dtc->DemEvntID, DEM_EVENT_STATUS_FAILED);
   }
   else if(DTC_NORMAL == *dtc->status)
   {
        Dem_SetEventStatus(dtc->DemEvntID, DEM_EVENT_STATUS_PASSED);
   }
   else
   {
   }

   dtc_index++;	   
}

static void dtc_set_event_status(uint8_t DemEvntID, uint8_t  st)
{
	uint8_t i;
	for(i=0; i< DTC_DET_NUM; i++)
	{
	   if(DemEvntID == dtc_det_table[i].DemEvntID)
	   {
	       osal_enter_critical();
	       if(DTC_NORMAL == st)
	       {
	           *dtc_det_table[i].status = DTC_NORMAL;
	       }
		   else
		   {
			   *dtc_det_table[i].status = DTC_ERROR;
		   }
		   osal_exit_critical();
	   }
	}
}
void set_dtc_BacklightTempSts(hp_dtc_stat_e st)
{
   dtc_set_event_status(DEM_EVENT_BK_TEMP_HIGH,st);
}
void set_dtc_LcdTempSts(hp_dtc_stat_e st)
{
   dtc_set_event_status(DEM_EVENT_LCD_TEMP_HIGH,st);
}
void set_dtc_ChipSts(hp_dtc_stat_e st)
{
   dtc_set_event_status(DEM_EVENT_DESER_ERR,st);
}
void set_dtc_BusoffSts(hp_dtc_stat_e st)
{
   dtc_set_event_status(DEM_EVENT_CAN_BUSOFF,st);
   if(DTC_NORMAL == st)
   	{
   	  Dem_SetEnableCondition(CONDITION_T_STARTUP_ACC, true);
   	}
   else
   	{
   	  Dem_SetEnableCondition(CONDITION_T_STARTUP_ACC, false);
   	}
}
void set_dtc_PowerVolHSts(hp_dtc_stat_e st)
{
   dtc_set_event_status(DEM_EVENT_VOLTAGE_HIGH,st);
}
void set_dtc_PowerVolLSts(hp_dtc_stat_e st)
{
   dtc_set_event_status(DEM_EVENT_VOLTAGE_LOW,st);
}
/****************************************************************************
*Function Name: 	hp_set_dtc_status
*Parameters:		id:HP_DTC_BK_TEMP_HIGH_ID, HP_DTC_LCD_TEMP_HIGH,HP_DTC_DESER_ERR
                    st:DTC_NORMAL,DTC_ERROR
*Returns:		     no
*Description:		
******************************************************************************/

void hp_set_dtc_status(hp_dtc_id_e id, hp_dtc_stat_e st)
{
   if(DTC_OK == st)
   {
      st = DTC_NORMAL;
   }
   else
   {
      st = DTC_ERROR;
   }
   switch(id)
   {
          case HP_DTC_BK_TEMP_HIGH_ID:
	       dtc_set_event_status(DEM_EVENT_BK_TEMP_HIGH, st);
	       break;
	  case HP_DTC_LCD_TEMP_HIGH:
	       dtc_set_event_status(DEM_EVENT_LCD_TEMP_HIGH, st);
	       break;
	  case HP_DTC_DESER_ERR:
	       dtc_set_event_status(DEM_EVENT_DESER_ERR, st);
	       break;
	  default:
	       break;
   }
}

static uint8_t dtcCondtion_Vol(dtc_det_t* dtc)
{
   (void)dtc;
   return true;
}

