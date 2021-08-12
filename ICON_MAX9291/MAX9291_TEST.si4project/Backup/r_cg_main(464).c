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
* Creation Date: 2021/7/8
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
#include "r_cg_riic.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
 uint8_t     send_data[ 2U];
 uint8_t     recv_data[ 2U];
 
 #define     MAX_9291_ADDR     (0x80)
 #define     MAX_9278_ADDR     (0x90)


/* MAX9291 REGISTER */     
#define   HDMI_MHL_DEVICE                   (0xF0)
#define   HPD_C_CTRL                        (0xE9)
#define   HPD_OEN_CTRL                      (0xEA)

#define   HDMI_AON_DEVICE                   (0x60)   // 0X62
#define   HDMI_TX_CONNECTION                (0x0C)
 
void delay(uint32_t ms);
void test_max9291(void);

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
    R_RIIC0_Start();
    while (1U)
    {
        test_max9291();
    }
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
void delay(uint32_t ms)
{
    uint32_t i; 
    for(i=0;i<80*ms;i++);
}


void test_max9291(void)
{
    int num = 0;
    send_data[0] = HDMI_TX_CONNECTION;
    num = 1;
    R_RIIC0_Master_Send(MAX_9291_ADDR,(uint8_t*)&send_data , num);
    delay(10000);

    R_RIIC0_Master_Receive(MAX_9291_ADDR, (uint8_t*)&recv_data, sizeof(recv_data));
    delay(10000);

		
    send_data[0] = HPD_C_CTRL;
    send_data[1] = 0x01;
    R_RIIC0_Master_Send(HDMI_MHL_DEVICE,(uint8_t*)&send_data , sizeof(send_data));
    delay(10000);
	
    send_data[0] = HPD_OEN_CTRL;
    send_data[1] = 0x01;
    R_RIIC0_Master_Send(HDMI_MHL_DEVICE,(uint8_t*)&send_data , sizeof(send_data));
    delay(10000);

    return;
}
/* End user code. Do not edit comment generated here */

