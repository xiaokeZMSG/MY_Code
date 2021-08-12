/*
 * Copyright (c) 2020-2021, MCU  Team
 * file: m_gpio_cfg.h
 *
 * Change Logs:
 * Date           Author            Notes
 * 2021-06-13    maguangdong      First edition
 */

/*==========================================================================*/
/*includes */
/*==========================================================================*/
#include "r_device.h"
#include "m_gpio.h"

/* Peripheral Includes */

#include "port/r_port.h"

const struct m_gpio_tag g_gpio_st[]=
{
	/* port   pin  alt   i/o    level  OpenDrain  UP/DN bidirect  EOL   */
	/*                                 /PushPull                        */
	{  Port11,  8,  Alt6, Output,  Low,     0,        0,    0,     FALSE}, /*CAN1Rx pin15*/      
	{  Port11,  9,  Alt6, Output,  Low,     0,        0,    0,     FALSE}, /*CAN1Tx pin16*/ 
	{  Port1,   4, Alt6, Input,   Low,     0,        2,    0,     FALSE}, /*CAN1Tx pin16*/ 
	

    /*EOL=true,end*/
	{  Port1,  5,  Alt6, Input,  High,    0,        0,    0,     TRUE}, /*EOL*/ 	
};	