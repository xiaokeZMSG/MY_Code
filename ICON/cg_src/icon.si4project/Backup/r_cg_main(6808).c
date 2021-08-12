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
* File Name    : r_cg_main.c
* Version      : Code Generator for RH850/F1K V1.01.00.02 [19 Apr 2017]
* Device(s)    : R7F701582(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements main function.
* Creation Date: 2021/7/14
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
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_uart.h"
#include "r_cg_riic.h"
#include "r_cg_ostm.h"
#include "r_cg_taub.h"
#include "r_cg_adc.h"
/* Start user code for include. Do not edit comment generated here */
#include "r_rh850_can_drv.h"
#include "r_cg_stbc.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */

/* Wake-up factors */
#define R_WUF_RESET           (uint32_t)0x00
#define R_WUF_INTP11          (uint32_t)(1<<13)
#define R_WUF_INTP15          (uint32_t)(1<<27)
#define R_WUF_ERROR           (uint32_t)0xff

#define K15_SLEEP_VALUE       (600)


uint8_t  uart_rx_buf[5] = {0,0,0,0,0};
uint16_t uart_rx_num = 5;
uint16_t buffer_adc[10]={0,0,0,0,0,0,0,0,0,0};

uint8_t I2C_send_data[ 3U];
uint8_t I2C_recv_data[ 3U];

#pragma section r0_disp32 "RETENTION_RAM"
r_System_s g_SystemStatus = {R_RESET,R_RESET,0,0,3};
#pragma section default

//r_System_s g_SystemStatus = {R_RESET,R_RESET,0,0,0};

/* End user code. Do not edit comment generated here */


void R_MAIN_UserInit(void);
/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */
    R_TASKS_Start();
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
    DI();
    R_Systeminit();
    EI();
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */

/*****************************************************************************
** Function:    R_TASKS_Start
** Description: Call peripheral initialization functions and handle executed 
**              modes.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_TASKS_Start(void)
{ 
    uint32_t loc_WakeUpFactor;

    loc_WakeUpFactor = R_STBC_GetWakeUpFactor();
    PrintText("\n\r>>START  mode 1\r\n");
 
    if(loc_WakeUpFactor == R_WUF_RESET)
    {
        g_SystemStatus.CurrentMode = R_NORMALWORK;
        g_SystemStatus.PreviousMode = R_RESET;
    }
    /* Wake-up from DeepSTOP */
    else
    {
        if (R_WUF_INTP15&loc_WakeUpFactor)
        {
            PrintText("\n\r>>Wake-up from DeepSTOP by INTP11 Button!\r\n");
        }
        switch(g_SystemStatus.PreviousMode)
        {
            case R_NORMALWORK:
                PrintText("\n\r>>Enter previous mode 1\r\n");
            break;
            
            default:
            break;
        }
        
        g_SystemStatus.CurrentMode = R_NORMALWORK;
        g_SystemStatus.PreviousMode = R_DEEPSTOP;
        
        /* Release IO hold state of the Ports after DeepSTOP */
        R_STBC_ReleaseIoHold();
    }
		
      /* Mode handler loop */
      while(1)
      {
          switch(g_SystemStatus.CurrentMode)
          {
              case R_NORMALWORK:
                  NormalWork();
              break;
              
              case R_DEEPSTOP:
                  DeepSTOP();
              break;
              
              default:
              break;
          }
      }
}

/*****************************************************************************
** Function:    NormalWork
** Description: normal work functions and handle executed 
**              modes.
** Parameter:   None
** Return:      None
******************************************************************************/
void NormalWork(void)
{
    uint16_t k15value;
 
    R_UART5_Start();
    delay(20);
    PrintText("****** Start UART5 OK! ******\n");
    
    R_PORT8_Set1000mA();
    delay(20);
    PrintText("****** Set 1000mA OK! ******\n");
    
    R_APORT0_ResetLCD();
    PrintText("****** ReSet LCD OK! ******\n");

    R_ADC0_ScanGroup1_OperationOn();
    R_ADC0_ScanGroup1_Start();
    delay(20);
   
    R_CAN1_Start();
    delay(20);

    R_RIIC0_Start();
    
    r_Port8_Set10Input();

 
    while (g_SystemStatus.CurrentMode == R_NORMALWORK)
    {
        R_UART5_Receive(uart_rx_buf, uart_rx_num);
        
        delay(10);
        r_adc0_DetectVolatage();
        r_adc0_SetPWMSta();
        delay(20);
	
        //PrintText("******  RUNNING! ******\n");
        
        k15value = r_adc0_GetK15Value();
        if(k15value < K15_SLEEP_VALUE)
        {
            g_SystemStatus.PreviousMode = R_NORMALWORK;
            g_SystemStatus.CurrentMode = R_DEEPSTOP;
        }
       	
        R_CAN1_Test();
        delay(200);
        NOP();

        R_RIIC0_Master_Send(0x80, (uint8_t*)&I2C_send_data,sizeof(I2C_send_data));

    }
   
    /*leave normal mode*/
    R_TAUB0_Channel10_Stop();
    R_TAUB0_Channel12_lowValue();
    delay(50);

    R_ADC0_Halt();
    delay(50);

    R_RIIC0_Stop();

    
}

/*****************************************************************************
** Function:    DeepSTOP
** Description: going to deepsleep functions and handle executed 
**              modes.
** Parameter:   None
** Return:      None
******************************************************************************/
void DeepSTOP(void)
{
    R_UI_INTP15_Init();
    
    /*judge deepsleep condition*/
    R_STBC_Prepare_Deep_Stop_Mode();
    R_STBC_Start_Deep_Stop_Mode();
}

/* End user code. Do not edit comment generated here */
