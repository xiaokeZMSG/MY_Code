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
* File Name    : r_cg_uart_user.c
* Version      : Code Generator for RH850/F1K V1.01.00.02 [19 Apr 2017]
* Device(s)    : R7F701582(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for UART module.
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
#include "r_cg_uart.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint8_t  * gp_uart5_tx_address;    /* uart5 transmit data address */
extern volatile uint16_t   g_uart5_tx_count;       /* uart5 transmit data number */
extern volatile uint8_t  * gp_uart5_rx_address;    /* uart5 receive data address */
extern volatile uint16_t   g_uart5_rx_count;       /* uart5 receive data number */
extern volatile uint16_t   g_uart5_rx_length;      /* uart5 receive data length */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_uart5_interrupt_receive
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_uart5_interrupt_receive(enable=false, channel=238, fpu=true, callt=false)
void r_uart5_interrupt_receive(void)
{
    uint8_t rx_data_8;
    uint16_t temp; 

    rx_data_8 = RLN35.LURDR.UINT16; 

    temp = g_uart5_rx_count;
    if (g_uart5_rx_length > temp)
    {
        *gp_uart5_rx_address = rx_data_8;
        gp_uart5_rx_address++;
        g_uart5_rx_count++;

        temp = g_uart5_rx_count;
        if (g_uart5_rx_length == temp)
        {
            r_uart5_callback_receiveend();
        }
    }
}
/***********************************************************************************************************************
* Function Name: r_uart5_interrupt_error
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_uart5_interrupt_error(enable=false, channel=239, fpu=true, callt=false)
void r_uart5_interrupt_error(void)
{
    *gp_uart5_rx_address = RLN35.LURDR.UINT16;
    RLN35.LEST &= (uint8_t) ~_UART_CLEAR_ERROR_FLAG;
}
/***********************************************************************************************************************
* Function Name: r_uart5_interrupt_send
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_uart5_interrupt_send(enable=false, channel=237, fpu=true, callt=false)
void r_uart5_interrupt_send(void)
{
    if (g_uart5_tx_count > 0U)
    {
        RLN35.LUTDR.UINT16 = *gp_uart5_tx_address;
        gp_uart5_tx_address++;
        g_uart5_tx_count--;
    }
}
/***********************************************************************************************************************
* Function Name: r_uart5_callback_receiveend
* Description  : This function is a callback function called when UART5 completed data reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_uart5_callback_receiveend(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
