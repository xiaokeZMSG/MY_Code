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
* File Name    : r_cg_stbc_user.c
* Version      : Code Generator for RH850/F1K V1.01.00.02 [19 Apr 2017]
* Device(s)    : R7F701582(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for STBC module.
* Creation Date: 2021/6/30
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
#include "r_cg_stbc.h"
/* Start user code for include. Do not edit comment generated here */
#include "r_cg_taub.h"
#include "r_cg_uart.h"
#include "r_cg_port.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_STBC_Prepare_Deep_Stop_Mode_Set_Peripheral
* Description  : This function Prepare Deep Stop Mode Set Peripheral.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_STBC_Prepare_Deep_Stop_Mode_Set_Peripheral(void)
{
    /* Start user code. Do not edit comment generated here */
    //R_CLKC_SetAdca0ClockDomain(0x01);

    //R_CLKC_SetAdca0StopMask();
    CLKCTL.CKSC_AADCAD_STPM = 0x02;  // Resets the stop-mask bit for the ADCA0 clock supply so it is stopped in DeepSTOP.
    
    R_TAUB0_ReInit();
    R_UART5_ReInit();
    R_PORT_ReInit();
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: R_STBC_Prepare_Deep_Stop_Mode_Set_Interrupt
* Description  : This function Prepare Deep stop Mode Set Interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_STBC_Prepare_Deep_Stop_Mode_Set_Interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
