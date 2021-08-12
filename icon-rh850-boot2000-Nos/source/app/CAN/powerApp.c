/**************************************************************************
*	Title:	PowerApp.c
*	Author:	mgd
*	Date:	2021.07.15	
*	Description:  This is the standard code file for PowerApp.c
****************************************************************************/

/****************************************************************************
* Include header files
*****************************************************************************/
#include "r_typedefs.h"
#include "PowerApp.h"
#include "r_adc.h"
#include "dem.h"
#include "dem_cfg.h"
#include "DtcApp.h"
#include "m_gpio.h"

/****************************************************************************
* Constant and Macro Definitions using #define
*****************************************************************************/
#define VOLOVER              (160u)
#define VOLLOW               (90u)
#define VOLRH                (5u)
#define ZERO_CNT             (0)
#define CONDITION_ACCON_DELAY      (3000) //3s
#define CONDITION_ACCOFF_DELAY     (500)  // 500ms
#define CONDITION_VOLNORNMAL_DELAY (300)  //300ms
/****************************************************************************
* Enumerations and Structures and Typedefs
*****************************************************************************/
typedef enum {
  VOL_STAT_UNINIT,
  VOL_STAT_NORMAL,
  VOL_STAT_OVER,
  VOL_STAT_LOW
}BATT_STAT_E;

typedef enum {
  ACC_OFF,
  ACC_ON,  
  ACC_UINIT,
}ACC_STAT_E;

struct bat_stat_tag{
    uint8_t     low_cnt;
    uint8_t     over_cnt;
    uint8_t     normal_cnt;
    BATT_STAT_E satus;
};

struct acc_stat_tag{
    uint8_t     on_cnt;
    uint8_t     off_cnt;
    ACC_STAT_E satus;
};

/****************************************************************************
* Function Prototypes for Private Functions with File Level Scope
*****************************************************************************/
extern void set_can_network_on(void);
extern void set_can_network_off(void);
static void KL30_vol_detect_process(void);

/****************************************************************************
* Global and Const Variable Defining Definitions / Initializations
*****************************************************************************/
static struct bat_stat_tag batStatus={
  ZERO_CNT, 
  ZERO_CNT, 
  ZERO_CNT, 
  VOL_STAT_UNINIT,
};

static struct acc_stat_tag accStatus={
  ZERO_CNT, 
  ZERO_CNT, 
  ACC_UINIT,
};
/*****************************************************************************
*Function Name: 	acc_delay_func
*Parameters:		arg
*Returns:		    void 
*Description:		timer
******************************************************************************/
static void acc_delay_func(void *arg)
{
   
   if(ACC_OFF == accStatus.satus)
   {
	Dem_SetEnableCondition(CONDITION_T_STARTUP_ACC, false);
   }
   else if(ACC_ON == accStatus.satus)
   {
	Dem_SetEnableCondition(CONDITION_T_STARTUP_ACC, true);
   }
   else
   {
   }
}
static void acc_on_off_process(void) 
{
    ACC_STAT_E stat;
    stat = (ACC_STAT_E)read_acc_status();
    if(ACC_UINIT == accStatus.satus)
    {
        if(ACC_OFF == stat)
	{
	     if(accStatus.off_cnt>3)
	     {
		   accStatus.satus = ACC_OFF;
		   accStatus.off_cnt = 0;
		   accStatus.on_cnt  = 0;
		   Dem_SetEnableCondition(CONDITION_T_STARTUP_ACC, false);
		   set_can_network_off();
	     }
	     else
	     {
		   accStatus.off_cnt++;
		   accStatus.on_cnt = 0;
	     }
	}
	else if(ACC_ON == stat)
	{
	     if(accStatus.on_cnt>3)
	     {
		   accStatus.satus  = ACC_ON;
		   accStatus.on_cnt = 0;
		   accStatus.off_cnt = 0;
		   //Dem_SetEnableCondition(CONDITION_T_STARTUP_ACC, true);
		   osal_start_timer(TIMER_ACC_ID, CONDITION_ACCON_DELAY,acc_delay_func,NULL);
		   set_can_network_on();
	     }
	     else
	     {
		   accStatus.on_cnt++;
		   accStatus.off_cnt = 0;
	     }
	}
	else
	{
		accStatus.on_cnt  = 0;
		accStatus.off_cnt = 0;
	}
    }
    else if(ACC_OFF == accStatus.satus)
    {
	if(ACC_ON == stat)
	{
	     if(accStatus.on_cnt>3)
	     {
		   accStatus.satus   = ACC_ON;
		   accStatus.on_cnt  = 0;
		   accStatus.off_cnt = 0;
		   set_can_network_on();
		   //Dem_SetEnableCondition(CONDITION_T_STARTUP_ACC, true);
		    osal_start_timer(TIMER_ACC_ID, CONDITION_ACCON_DELAY,acc_delay_func,NULL);
	     }
	     else
	     {
		   accStatus.on_cnt++;
		   accStatus.off_cnt = 0;
	     }
	}
	else
	{
	        accStatus.on_cnt  = 0;
		accStatus.off_cnt = 0;
	}
    }
    else if(ACC_ON == accStatus.satus)
    {
	if(ACC_OFF == stat)
	{
	     if(accStatus.off_cnt>3)
	     {
		   accStatus.satus = ACC_OFF;
		   accStatus.off_cnt = 0;
		   accStatus.on_cnt  = 0;
		   //Dem_SetEnableCondition(CONDITION_T_STARTUP_ACC, false);
		    osal_start_timer(TIMER_ACC_ID, CONDITION_ACCOFF_DELAY,acc_delay_func,NULL);
		   set_can_network_off();		   
	     }
	     else
	     {
		   accStatus.off_cnt++;
		   accStatus.on_cnt = 0;
	     }
	}
	else
	{
		accStatus.on_cnt  = 0;
		accStatus.off_cnt = 0;
	}
    }

}





/****************************************************************************
*Function Name: 	power_delay_func
*Parameters:		arg
*Returns:		void 
*Description:		timer
******************************************************************************/

static void power_delay_func(void *arg)
{   
   if(VOL_STAT_NORMAL == batStatus.satus )
   {
	Dem_SetEnableCondition(CONDITION_LOC_VOL, true);
   }
   else
   {
   }
}

/****************************************************************************
*Function Name: 	get_KL31_Voltage
*Parameters:		void
*Returns:		    voltage 
*Description:		
******************************************************************************/
static uint16_t get_KL31_Voltage(void)
{
   uint32_t ADvol;
   ADvol = R_ADCA0_PinRead(AP0_6);
   ADvol = ADvol*33*110/4096+5;
   return (uint16_t)(ADvol/10);
}
/****************************************************************************
*Function Name: 	KL30_vol_detect_process
*Parameters:		void
*Returns:		void 
*Description:		
******************************************************************************/
static void KL30_vol_detect_process(void)
{
   uint16_t vol;
   vol = get_KL31_Voltage();
   if(VOL_STAT_UNINIT == batStatus.satus)
   {
       if(vol < VOLLOW)
	   {	     
		  if(batStatus.low_cnt>3)
		  {
		     Control_vol_Communication_disable();
			 set_dtc_PowerVolLSts(DTC_ERROR);
			 set_dtc_PowerVolHSts(DTC_NORMAL);
			 osal_stop_timer(TIMER_POWER_ID);
			 Dem_SetEnableCondition(CONDITION_LOC_VOL, false);			 
		         batStatus.satus = VOL_STAT_LOW;
			 batStatus.low_cnt = 0;
		  }
		  else
		  {
		         batStatus.low_cnt++;
		         batStatus.over_cnt = 0;
		         batStatus.normal_cnt = 0;
		  }
	   }
	   else if(vol > VOLOVER)
	   {
	      
	   	  if(batStatus.over_cnt>3)
		  {	
		      Control_vol_Communication_disable();
		      osal_stop_timer(TIMER_POWER_ID);
		      Dem_SetEnableCondition(CONDITION_LOC_VOL, false);	  
		      set_dtc_PowerVolLSts(DTC_NORMAL);
		      set_dtc_PowerVolHSts(DTC_ERROR);
		      batStatus.satus = VOL_STAT_OVER;
		      batStatus.over_cnt = 0;
		  }
		  else
		  {
		      batStatus.over_cnt++;
		      batStatus.normal_cnt = 0;
		      batStatus.low_cnt = 0;
		  }
	   }
	   else
	   {
	      if(batStatus.normal_cnt>3)
		  {
		     Control_vol_Communication_enable();
		     //Dem_SetEnableCondition(CONDITION_LOC_VOL, true);	
		      osal_start_timer(TIMER_POWER_ID, CONDITION_VOLNORNMAL_DELAY,power_delay_func,NULL);
		     set_dtc_PowerVolLSts(DTC_NORMAL);
		     set_dtc_PowerVolHSts(DTC_NORMAL);			 
		     batStatus.satus = VOL_STAT_NORMAL;
		     batStatus.normal_cnt = 0;
		  }
		  else
		  {
		      batStatus.normal_cnt++;
		      batStatus.over_cnt = 0;
		      batStatus.low_cnt = 0;
		  }
	   }
       
   }
   else if(VOL_STAT_NORMAL == batStatus.satus)
   {
	   if(vol < VOLLOW)
	   {	     
		  if(batStatus.low_cnt>3)
		  {
		     Control_vol_Communication_disable();
		     batStatus.satus = VOL_STAT_LOW;
			 set_dtc_PowerVolLSts(DTC_ERROR);
			 set_dtc_PowerVolHSts(DTC_NORMAL);
			 osal_stop_timer(TIMER_POWER_ID);
			 Dem_SetEnableCondition(CONDITION_LOC_VOL, false);
			 //set_dtc_BusoffCurrentSts(DTC_ERROR);
			 batStatus.low_cnt = 0;
		  }
		  else
		  {
		     batStatus.low_cnt++;
		     batStatus.over_cnt = 0;
		     batStatus.normal_cnt = 0;
		  }
	   }
	   else if(vol > VOLOVER)
	   {
	      
	   	  if(batStatus.over_cnt>3)
		  {
		     Control_vol_Communication_disable();
			 set_dtc_PowerVolLSts(DTC_NORMAL);
			 set_dtc_PowerVolHSts(DTC_ERROR);
			 osal_stop_timer(TIMER_POWER_ID);
			 Dem_SetEnableCondition(CONDITION_LOC_VOL, false);
			 batStatus.satus = VOL_STAT_OVER;
			 batStatus.over_cnt = 0;
		  }
		  else
		  {
		      batStatus.over_cnt++;
		      batStatus.normal_cnt = 0;
		      batStatus.low_cnt = 0;
		  }
	   }
	   else
	   {
	          batStatus.low_cnt = 0;
		      batStatus.over_cnt = 0;
		     batStatus.normal_cnt = 0;
	   }
   }
   else if(VOL_STAT_OVER == batStatus.satus)
   {
      if(vol < VOLOVER - VOLRH)
      {          
		  if(batStatus.normal_cnt>3)
		  {
		     Control_vol_Communication_enable();
		     //Dem_SetEnableCondition(CONDITION_LOC_VOL, true);	
		     osal_start_timer(TIMER_POWER_ID, CONDITION_VOLNORNMAL_DELAY,power_delay_func,NULL);
		     set_dtc_PowerVolLSts(DTC_NORMAL);
		     set_dtc_PowerVolHSts(DTC_NORMAL);			 
		     batStatus.satus = VOL_STAT_NORMAL;
		     batStatus.normal_cnt = 0;
		  }
		  else
		  {
		     batStatus.normal_cnt++;
		     batStatus.low_cnt = 0;
		     batStatus.over_cnt = 0;
		  }
      }
      else
      {
	         batStatus.low_cnt = 0;
		     batStatus.over_cnt = 0;
		     batStatus.normal_cnt = 0;
      }
   }
   else if(VOL_STAT_LOW == batStatus.satus)
   {
      if(vol > VOLLOW + VOLRH)
      {         
		  if(batStatus.normal_cnt>3)
		  {
		     Control_vol_Communication_enable();
		     //Dem_SetEnableCondition(CONDITION_LOC_VOL, true);	
		      osal_start_timer(TIMER_POWER_ID, CONDITION_VOLNORNMAL_DELAY,power_delay_func,NULL);
		     set_dtc_PowerVolLSts(DTC_NORMAL);
		     set_dtc_PowerVolHSts(DTC_NORMAL);			 
		     batStatus.satus = VOL_STAT_NORMAL;
		     batStatus.normal_cnt = 0;
		  }
		  else
		  {
		      batStatus.normal_cnt++;
		      batStatus.low_cnt = 0;
		      batStatus.over_cnt = 0;
		  }
      }
      else
      {
	       batStatus.low_cnt = 0;
	       batStatus.over_cnt = 0;
	       batStatus.normal_cnt = 0;
      }
   }
   else
   {
   }
}
/****************************************************************************
*Function Name: 	vCanApp_CAN_Task
*Parameters:		void
*Returns:			void
*Description:		
******************************************************************************/

void vPowerApp_Task(void) 
{
  KL30_vol_detect_process();
  acc_on_off_process();
}