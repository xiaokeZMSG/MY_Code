
/**********************************************************************
*	file:	osal_timer.c
*	Author:	mgd
*	Date:	2021.08.01	
*	Description:  timer function
*********************************************************************/


#include "osal.h"
#include "osal_timer.h"


/******************************************************************************
* Constant and Macro Definitions using #define
*****************************************************************************/

/******************************************************************************
* Enumerations and Structures and Typedefs
*****************************************************************************/
typedef struct
{
   //uint16_t 	timer_id;
   uint32_t 	timeout;
   bool         active;
   TimerCbFuncType timerCb;
   void         *arg;
} osalTimerRec_t;

/******************************************************************************
* Global and Const Variable Defining Definitions / Initializations
*****************************************************************************/
static osalTimerRec_t timer_array[TIMER_MAX_ID];

void osal_timer_init( void )
{
	uint8_t i;
	for ( i = 0; i < (uint8_t)TIMER_MAX_ID; i++) 
	{
		//timer_array[i].timer_id = (TIMER_EX_ID)i;
		timer_array[i].timeout 	   = 0;
		timer_array[i].active      = false;
		timer_array[i].timerCb     = NULL;
	}

}
void osal_timer_task(void)
{
  uint8_t i;
  for ( i = 0; i< (uint8_t)TIMER_MAX_ID; i++) 
  {
	if (timer_array[i].active)
	{
		if ((osal_time() > timer_array[i].timeout) && (timer_array[i].timerCb != NULL)) 
		{
			timer_array[i].active	= false;
			timer_array[i].timerCb(timer_array[i].arg);
			
		}
	}
  }
}
uint8_t osal_start_timer( TIMER_ID_e timerId, uint32_t timeout, TimerCbFuncType timerCb, void *arg)
{
	uint8_t res = 0;
	if (timerId > TIMER_MAX_ID)
	{
		res = -1;
	}
	else
	{
	   timer_array[timerId].timeout = osal_time() + timeout;
	   timer_array[timerId].active  = true;
	   timer_array[timerId].timerCb = timerCb;
	   timer_array[timerId].arg     = arg;
	}
	return res;
}

uint8_t osal_stop_timer( TIMER_ID_e timerId)
{
	uint8_t res = 0;
	if (timerId > TIMER_MAX_ID)
	{
		res = -1;
	}
	else
	{
	  timer_array[timerId].timeout	= 0;
	  timer_array[timerId].active	= false;
	}
	return res;
}

bool osal_timer_isActive(TIMER_ID_e timerId)  
{
	if( TIMER_MAX_ID > timerId )
	{
	    return timer_array[(timerId)].active;
	}
	return false;
}

static bool osal_timer_isRunning(TIMER_ID_e timerId) 
{
	if(TIMER_MAX_ID > timerId)
	{
	   return (osal_time() < timer_array[timerId].timeout);
	}
	return false;
}

bool osal_timer_isPause(TIMER_ID_e timerId)    
{
	return (!osal_timer_isActive(timerId) && osal_timer_isRunning(timerId));
}
