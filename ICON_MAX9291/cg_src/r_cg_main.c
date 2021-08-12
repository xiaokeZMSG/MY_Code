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
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_riic.h"
/* Start user code for include. Do not edit comment generated here */
#include "r_cg_MAX9291_register.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
uint8_t      I2C_send_data[ 2U] = {0, 0};
uint8_t      I2C_recv_data[ 2U] = {0, 0};
 
#define     MAX_9291_ADDR     (0x80) >> 1
#define     MAX_9278_ADDR     (0x90) >> 1  


/* MAX9291 REGISTER */     
#define   HDMI_MHL_DEVICE                   (0xF0) >>1   
#define   HPD_C_CTRL                        (0xE9)
#define   HPD_OEN_CTRL                      (0xEA)

#define   HDMI_AON_DEVICE                   (0x60) >> 1  
#define   HDMI_TX_CONNECTION                (0x0C)

#define   HDMI_Video_DEVICE                 (0xA0) >> 1
#define   INVERT_COLOR_CTRL                 (0x48)
#define   EN_COLOR_CTRL                     (0x49)
#define   SAMPLE_CTRL                       (0x4A)
#define   Video_CLK_CTRL                    (0xBC)

#define   HDMI_EDID_DEVICE                  (0xFE) >> 1
#define   HDMI_EDID_START                   (0x00)

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
    test_max9291();
    while (1U)
    {
        ;
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
    for(i=0;i<8000*ms;i++);
}

uint16_t test_value = 0;
void test_max9291(void)
{
    int16_t num = 0;
    int16_t i = 0;
#if 1
    /* Write  EDID */
    for(i=0;i<256;i++)
    {
        I2C_send_data[0] = 0x00 + i;
        I2C_send_data[1] = EDID[i];
        R_RIIC0_Master_Send(HDMI_EDID_DEVICE, (uint8_t*)&I2C_send_data,sizeof(I2C_send_data));
        delay(1);
    }
#else
    for(i=0;i<256;i++)
    {
        /* read  EDID */
        I2C_send_data[0] = i;
        num = 1;
        R_RIIC0_Master_Send(HDMI_EDID_DEVICE,(uint8_t*)&I2C_send_data[0], num);
        delay(1);
        R_RIIC0_Master_Receive(HDMI_EDID_DEVICE, (uint8_t*)&I2C_recv_data[0], 1);
        delay(1);
	
	if(I2C_recv_data[0] != EDID[i])
	{
            num = 0;
	    I2C_send_data[0] = 0;
	}
    }
#endif

    /* ------  MAX_9291_ADDR  ------ */
    I2C_send_data[0] = 0x02;
    I2C_send_data[1] = 0x1F;
    R_RIIC0_Master_Send(MAX_9291_ADDR, (uint8_t*)&I2C_send_data,sizeof(I2C_send_data));
    delay(1);
    
    I2C_send_data[0] = 0x04;
    I2C_send_data[1] = 0xC3;
    R_RIIC0_Master_Send(MAX_9291_ADDR, (uint8_t*)&I2C_send_data,sizeof(I2C_send_data));
    delay(1);
    
    I2C_send_data[0] = 0x14;
    I2C_send_data[1] = 0xA0;
    R_RIIC0_Master_Send(MAX_9291_ADDR, (uint8_t*)&I2C_send_data,sizeof(I2C_send_data));
    delay(1);

    /* read MAX_9291_ADDR 0x08  0x1E  0x1F*/
    I2C_send_data[0] = 0x1F;
    num = 1;
    R_RIIC0_Master_Send(MAX_9291_ADDR,(uint8_t*)&I2C_send_data[0] , num);
    delay(1);
    R_RIIC0_Master_Receive(MAX_9291_ADDR, (uint8_t*)&I2C_recv_data[0], 1);
    delay(1);
    
     /* ------  HDMI_AON_DEVICE ------ */
    I2C_send_data[0] = 0x09;
    I2C_send_data[1] = 0x90;
    R_RIIC0_Master_Send(HDMI_AON_DEVICE, (uint8_t*)&I2C_send_data,sizeof(I2C_send_data));
    delay(1);
    
    I2C_send_data[0] = HDMI_TX_CONNECTION;
    num = 1;
    R_RIIC0_Master_Send(HDMI_AON_DEVICE,(uint8_t*)&I2C_send_data[0] , num);
    delay(1);
    R_RIIC0_Master_Receive(HDMI_AON_DEVICE, (uint8_t*)&I2C_recv_data[0], 1);
    delay(1);
    
    /* test read */
    I2C_send_data[0] = 0x09;
    num = 1;
    R_RIIC0_Master_Send(HDMI_AON_DEVICE,(uint8_t*)&I2C_send_data[0] , num);
    delay(1);
    R_RIIC0_Master_Receive(HDMI_AON_DEVICE, (uint8_t*)&I2C_recv_data[0], 1);
    delay(1);
    

    /* ------  HDMI_MHL_DEVICE ------ */
    I2C_send_data[0] = HPD_C_CTRL;
    I2C_send_data[1] = 0x01;
    R_RIIC0_Master_Send(HDMI_MHL_DEVICE, (uint8_t*)&I2C_send_data,sizeof(I2C_send_data));
    delay(1);
    
    /* read */
    I2C_send_data[0] = HPD_C_CTRL;
    num = 1;
    R_RIIC0_Master_Send(HDMI_MHL_DEVICE,(uint8_t*)&I2C_send_data[0] , num);
    delay(1);
    R_RIIC0_Master_Receive(HDMI_MHL_DEVICE, (uint8_t*)&I2C_recv_data[0], 1);
    delay(1);
      
    /* write */
    I2C_send_data[0] = HPD_OEN_CTRL;
    I2C_send_data[1] = 0x01;
    R_RIIC0_Master_Send(HDMI_MHL_DEVICE, (uint8_t*)&I2C_send_data,sizeof(I2C_send_data));
    delay(1);
    
    /* ------  HDMI_Video_DEVICE ------ */
    I2C_send_data[0] = INVERT_COLOR_CTRL;
    I2C_send_data[1] = 0xC0;
    R_RIIC0_Master_Send(HDMI_Video_DEVICE, (uint8_t*)&I2C_send_data,sizeof(I2C_send_data));
    delay(1);
   
    return;
}
/* End user code. Do not edit comment generated here */
