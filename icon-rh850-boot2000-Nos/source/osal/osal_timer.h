/**********************************************************************
*	file:	osal_timer.h
*	Author:	mgd
*	Date:	2021.08.01	
*	Description:  timer function
*********************************************************************/

#ifndef  __OSAL_TIMER_H__
#define  __OSAL_TIMER_H__
#include "r_typedefs.h"
/******************************************************************************
* Enumerations and Structures and Typedefs
*****************************************************************************/

typedef enum {
  TIMER_ACC_ID, 
  TIMER_POWER_ID,
  TIMER_DELAY_ID,
  TIMER_MAX_ID
}TIMER_ID_e;
typedef void (*TimerCbFuncType)(void *arg);



#define osal_delay(tm)    do{                                                   \
                              osal_start_timer(TIMER_DELAY_ID, tm, NULL, NULL); \
                              while(osal_timer_isActive(TIMER_DELAY_ID)){}      \
                            }while(0)

/******************************************************************************
 * Function Prototypes for Private Functions with File Level Scope
*****************************************************************************/
void osal_timer_init(void);
void osal_timer_task(void);
uint8_t osal_start_timer( TIMER_ID_e timerId, uint32_t timeout, TimerCbFuncType timerCb,void *arg);
uint8_t osal_stop_timer( TIMER_ID_e timerId);
bool osal_timer_isActive(TIMER_ID_e timerId);
bool osal_timer_isPause(TIMER_ID_e timerId);

#endif /*__OSAL_TIMER_H__*/

