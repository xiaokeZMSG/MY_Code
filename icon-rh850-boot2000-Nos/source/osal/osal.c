/*
 * Copyright (c) 20109-2020, SAIC  Team
 * file: osal.c
 *
 * Change Logs:
 * Date           Author            Notes
 * 2020-01-17    maguangdong      First edition
 */
//#include "FreeRTOS.h"
//#include "task.h"
//#include "queue.h"
//#include "semphr.h"
//#include "event_groups.h"
#include "r_device.h"
#include "osal.h"
//#include "osif2.h"
/***************************************************task*****************************************************************/
void vCanApp_CAN_Task(void); 
void vPowerApp_Task(void);

#define SCHED_PERIOD_5MS   (5)
#define SCHED_PERIOD_20MS  (20)

static uint32_t Sched_5ms_Count = 0;
static uint32_t Sched_20ms_Count = 0;
static uint32_t OSTM0_count = 0;
uint16_t volatile  usCriticalNesting = 0;
void vDtcApp_Task(void);
void vDtc_init_data(void);
void  osal_print(char *format, ...)
{
}

/*
 * Hardware initialisation to generate the RTOS tick.  This uses
 */
void Init_INTOSTM0_interrupt( void )//1ms
{
    OSTM0CMP = 60000;
    OSTM0CTL=0x01; 
    OSTM0TS=1; /*start*/
    INTC2.ICOSTM0.UINT16 = 0x00;
}

#pragma interrupt  INTOSTM0_interrupt( enable=manual , channel=76 , callt=false , fpu=false )
void INTOSTM0_interrupt( void )
{
    Sched_5ms_Count++;
    Sched_20ms_Count++;
    OSTM0_count++;
}
uint32_t getOsTick(void)
{
    return OSTM0_count;
}
uint32_t getOSTM0CNT(void)
{
   return OSTM0CNT;
}
void osal_start(void)
{
  osal_timer_init();
  vCanApp_CAN_Init();
  vDtc_init_data();
  
  while(1)
  {
    R_SYSTEM_FeedWatchdog();
    osal_timer_task();
    if( Sched_5ms_Count>= SCHED_PERIOD_5MS)
    {
	  Sched_5ms_Count = 0;
	  vCanApp_CAN_Task(); 
    }
    else if( Sched_20ms_Count>= SCHED_PERIOD_20MS)
    {
	  Sched_20ms_Count = 0;
	  vDtcApp_Task();
	  vPowerApp_Task();
    }
  }
}
