/*
 * Copyright (c) 2020-2021, MCU  Team
 * file: m_gpio.h
 *
 * Change Logs:
 * Date           Author            Notes
 * 2021-06-13    maguangdong      First edition
 */
#ifndef __M_GPIO_H__
#define __M_GPIO_H__
#include "r_device.h"
#include "r_port.h"
#include "port/r_port.h"

#ifndef FALSE
#define FALSE   (0)
#endif

#ifndef TRUE
#define TRUE    (1)
#endif

#define  GPIO_HIGH     (1)
#define  GPIO_LOW      (0)
/*==========================================================================*/
/*macro  define */
/*==========================================================================*/
/*read pin*/
#define read_acc_status()  R_PORT_GetLevel(Port1,4)   /*read acc state */


/*write pin*/
#define set_inh_status(x) R_PORT_GpioOutput(Port11, 9, x)
#define Set_ansceiver(x)  R_PORT_GpioOutput(APort0, 2, x)
#define Set_testP11_8(x)  R_PORT_GpioOutput(Port11, 8, x)
/* Defines */
/*==========================================================================*/
struct m_gpio_tag{
	enum port_t Port;
	uint32_t Pin;
	enum alt_t Alt;      /*alt=6 PMC_Reg=0*/
	enum io_t  IO;       /*gpio direct */
	enum level_t Level;  /*level of pin Out*/
	uint8_t IsOpenDrain; /*Is OpenDrain */
	uint8_t IsUpDn;      /*0: no UP and DN;1:UP;  2:DN*/
	uint8_t bidirect;
	uint8_t EOL;         /*true end*/
};
/*==========================================================================*/
/* Function  defines */
/*==========================================================================*/
void init_m_gpio(void);

#endif /* __M_GPIO_H__ */