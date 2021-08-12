/*
 * Copyright (c) 2020-2021, SAIC  Team
 * file: hal-init.c
   *  Description:  This the code filefor rtc operate
 *
 * Change Logs:
 * Date           Author         VER      Notes        
 * 2021-06-13    maguangdong     0.1    First edition  
 *
 */

/**********************************************************************
 * Include header files
 *********************************************************************/
#include "r_device.h"
#include <stdint.h>
#include <stdbool.h>
#include "gensubs.h"
#include "r_adc.h"
#include "system/r_system.h"
#include "m_gpio.h"
#include "osal.h"
void Init_INTOSTM0_interrupt( void );

uint32_t ResetCause =0;

void hal_init(void)
{
	R_SYSTEM_ClockInit();
	Init_INTOSTM0_interrupt(  );
	init_m_gpio();
	R_ADCA0_Init();
	osal_nv_init();
	ResetCause = R_SYSTEM_GetResetCause();
	//osal_kprintf("reset case[0x%02x]\n",ResetCause);//R_SYSTEM_GetResetCause());
		
}
