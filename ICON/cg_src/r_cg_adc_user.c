/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software.  By using this software, 
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2015, 2017 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_adc_user.c
* Version      : Code Generator for RH850/F1K V1.01.00.02 [19 Apr 2017]
* Device(s)    : R7F701582(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for ADCA module.
* Creation Date: 2021/7/27
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_adc.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
extern uint16_t buffer_adc[];
extern r_System_s g_SystemStatus;

uint8_t  syssta = 0;            // 0:stop     1:work
uint8_t  sysvoltagesta = 1;     // 0:350mA    1:1000mA
uint8_t  first_taub = 0;

#define WAKEUP_VOLTAGE    558   // 558 --- 4.8v   660 --- 6v
#define STOP_VOLTAGE      2000
//#define SET350MA          890
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_adc0_error_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_adc0_error_interrupt(enable=false, channel=56, fpu=true, callt=false)
void r_adc0_error_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_adc0_scan_group1_end_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_adc0_scan_group1_end_interrupt(enable=false, channel=18, fpu=true, callt=false)
void r_adc0_scan_group1_end_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
void r_adc0_DetectVolatage(void)
{
    if(buffer_adc[2] >= WAKEUP_VOLTAGE && buffer_adc[2] <= STOP_VOLTAGE && r_Port8_Get10Level() == 0 ) 
    {
    	R_PROT_ResetLEDInit();
    }
    else
    {
	 return;
    }
    
}

void r_adc0_SetPWMSta(void)
{
    R_ADC0_ScanGroup1_GetResult(buffer_adc);
    if(buffer_adc[2] >= WAKEUP_VOLTAGE && buffer_adc[2] <= STOP_VOLTAGE  && (1 != syssta || g_SystemStatus.refreshflag_LED == 1) )  //
    {
        R_TAUB0_Channel10_Start();
	if(first_taub == 0)
	{
	    first_taub = 1;
	    R_TAUB0_Channel12_first_duty((uint32_t)g_SystemStatus.LED_Luminance);
	}
	else
	{
	    first_taub = 1;
            R_TAUB0_Channel12_duty((uint32_t)g_SystemStatus.LED_Luminance);
	}
        syssta = 1;
	g_SystemStatus.refreshflag_LED = 0;
        delay(20);
        PrintText("****** Set TAUB0 OK! ******\n");
    }
    else if((buffer_adc[2] < WAKEUP_VOLTAGE || buffer_adc[2] > STOP_VOLTAGE )&& (0 != syssta))
    {
        R_TAUB0_Channel10_Stop();
        R_TAUB0_Channel12_lowValue();
        syssta = 0;
    }
    else
    {
        delay(20);
    }
}

uint16_t r_adc0_GetK15Value(void)
{
    return buffer_adc[2];
}
/* End user code. Do not edit comment generated here */
