/*
 * Copyright (c) 20109-2020, SAIC  Team
 * file: osal.h
 *
 * Change Logs:
 * Date           Author            Notes
 * 2020-01-17    maguangdong      First edition
 */
#ifndef __OSAL_H__
#define __OSAL_H__
#include <r_typedefs.h>
#include "osal_timer.h"
//#include "freertos.h"
//#include "task.h"
//#include "osal-cfg.h"
//#include "rtos.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define LOCK_UART_QUEUE()   
#define UNLOCK_UART_QUEUE()
#define LOCK_SIP()
#define UNLOCK_SIP()
#define LOCK_TX_QUEUE()
#define UNLOCK_TX_QUEUE()
#define LOCK_TXUSER_QUEUE()
#define UNLOCK_TXUSER_QUEUE()
#define LOCK_RX_QUEUE()
#define UNLOCK_RX_QUEUE()
#define LOCK_RXUSER_QUEUE()
#define UNLOCK_RXUSER_QUEUE()

//typedef void *mqHandle_t;
//typedef void *taskHandle_t;

#define OS_Sleep(x)   {}

typedef uint8_t Std_ReturnType;

#define E_OK 				(Std_ReturnType)0
#define E_NOT_OK 			(Std_ReturnType)1

#define E_NO_DTC_AVAILABLE		(Std_ReturnType)2
#define E_SESSION_NOT_ALLOWED	        (Std_ReturnType)4
#define E_PROTOCOL_NOT_ALLOWED	        (Std_ReturnType)5
#define E_REQUEST_NOT_ACCEPTED	        (Std_ReturnType)8
#define E_REQUEST_ENV_NOK		(Std_ReturnType)9
#define E_PENDING		        (Std_ReturnType)10
#define E_COMPARE_KEY_FAILED	        (Std_ReturnType)11
#define E_FORCE_RCRRP			(Std_ReturnType)12

#define E_REQUEST_NOT_FUNCADDR		(Std_ReturnType)13
#define E_IIC_NOT_ACK                   (Std_ReturnType)14
#define E_OS_MUTEX_ERROR                (Std_ReturnType)15

#define E_POINT_NULL_ERROR              (Std_ReturnType)16

/*************TASK ********************************/
#define TASK_MSG_SIZE_ZERO        0
#define TASK_KEY_MSG_SIZE         TASK_MSG_SIZE_ZERO
#define TASK_MULTIFUNC_MSG_SIZE   32/*TASK_MSG_SIZE_ZERO*/
#define TASK_CONSOLE_MSG_SIZE     128
#define TASK_CAN_MSG_SIZE         128

/***********update********************************/
#define NORMAL_RUN        (0xffu)
#define UPDATE_REQ_FLAG   (0x5fu)
#define UPDATING_FLAG     (0x55u)
#define UPDATED_FLAG      (0x00u)

extern void  osal_start(void);

extern void  osal_print(char *format, ...);
extern void  osal_msleep(int32_t ms);

#define OSAL_DEBUG(format,...) /*printf("[%s][%s][%d]"format"\n",__FILE__,__func__,__LINE__,##__VA_ARGS__) */

#define osal_time()      getOsTick()

/* Interrupt control macros. */
/* Interrupt control macros. */
#define portDISABLE_INTERRUPTS() __DI()
#define portENABLE_INTERRUPTS()	 __EI()

/* Critical section control macros. */
#define portNO_CRITICAL_SECTION_NESTING		( ( uint16_t ) 0 )

#define portENTER_CRITICAL()														\
{																					\
extern volatile uint16_t  usCriticalNesting;						\
																					\
	portDISABLE_INTERRUPTS();														\
																					\
	/* Now interrupts are disabled ulCriticalNesting can be accessed */				\
	/* directly.  Increment ulCriticalNesting to keep a count of how many */		\
	/* times portENTER_CRITICAL() has been called. */								\
	usCriticalNesting++;															\
}

#define portEXIT_CRITICAL()															\
{																					\
extern volatile uint16_t  usCriticalNesting;						\
																					\
	if( usCriticalNesting > portNO_CRITICAL_SECTION_NESTING )						\
	{																				\
		/* Decrement the nesting count as we are leaving a critical section. */		\
		usCriticalNesting--;														\
																					\
		/* If the nesting level has reached zero then interrupts should be */		\
		/* re-enabled. */															\
		if( usCriticalNesting == portNO_CRITICAL_SECTION_NESTING )					\
		{																			\
			portENABLE_INTERRUPTS();												\
		}																			\
	}																				\
}
#define osal_enter_critical()  portENTER_CRITICAL()
#define osal_exit_critical()   portEXIT_CRITICAL()

#define Enable_Interrupts()    portEXIT_CRITICAL()
#define Disable_Interrupts()   portENTER_CRITICAL()

#ifndef UNUSED_PARAM
#define UNUSED_PARAM(param)                     (void)(param)
#endif

#ifndef  NEAR
#define  NEAR
#endif

#ifndef  FAR
#define  FAR
#endif

#ifndef  SAFE
#define  SAFE
#endif

#ifndef  NONREENTRANT
#define  NONREENTRANT
#endif

#ifndef  INTERRUPT
#define  INTERRUPT
#endif


void Init_INTOSTM0_interrupt( void );
uint32_t getOSTM0CNT(void);


#endif /*__OSAL_H__*/
