/*
 * Copyright (c) 2020-2021, MCU  Team
 * file: m_gpio.c
 *
 * Change Logs:
 * Date           Author            Notes
 * 2021-06-13    maguangdong      First edition
 */


/*===========================================================================*/
/* Includes */
/*===========================================================================*/
#include "r_device.h"
#include "m_gpio.h"

/* Peripheral Includes */
//#include "intc/r_intc.h"
#include "port/r_port.h"
//#include "rlin/r_rlin.h"
#include "m_gpio_cfg.h"
/*===========================================================================*/
/* Functions */
/*===========================================================================*/
/*****************************************************************************
** Function:    init_m_gpio
** Description: Configures 
** Parameter:   None
** Return:      None
******************************************************************************/
void init_m_gpio(void)
{
    struct m_gpio_tag *gpio_cfg = (struct m_gpio_tag *)&g_gpio_st[0];
    while(gpio_cfg->EOL != TRUE)
    {
      if( gpio_cfg->Alt < Alt6 )
      {
          R_PORT_SetAltFunc(gpio_cfg->Port, gpio_cfg->Pin, gpio_cfg->Alt, gpio_cfg->IO);
      }
      else if( gpio_cfg->Alt == Alt6 )
      {
          if(gpio_cfg->IO == Output)
          {
             R_PORT_SetGpioOutput(gpio_cfg->Port, gpio_cfg->Pin, gpio_cfg->Level);
          }
          else /*io input*/
          {	
             R_PORT_SetGpioInput(gpio_cfg->Port, gpio_cfg->Pin);
          }
      }
      else
      {
          continue;
      }
	  
	  if(gpio_cfg->IsOpenDrain)
	  {
		  R_PORT_SetOpenDrain(gpio_cfg->Port, gpio_cfg->Pin);
	  }
	  else
	  {
		  //R_PORT_SetPushPull(gpio_cfg->Port, gpio_cfg->Pin);
	  }
	  
	  if(gpio_cfg->bidirect)
	  {
		  R_PORT_SetGpioBidirection(gpio_cfg->Port, gpio_cfg->Pin);
	  }
	  else
	  {
		  //R_PORT_SetPushPull(gpio_cfg->Port, gpio_cfg->Pin);
	  }
	  
	  if(1 == gpio_cfg->IsUpDn)
	  {
		  R_PORT_SetPullup(gpio_cfg->Port, gpio_cfg->Pin);
	  }
	  else if(2 == gpio_cfg->IsUpDn)
	  {
		  R_PORT_SetPulldn(gpio_cfg->Port, gpio_cfg->Pin);
	  }
	  else
	  {
		  //R_PORT_ClearPulldn(gpio_cfg->Port, gpio_cfg->Pin);
	  }
	  
	  gpio_cfg++;
	}
	  
}