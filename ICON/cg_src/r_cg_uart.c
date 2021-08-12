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
* File Name    : r_cg_uart.c
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
extern volatile uint32_t g_cg_sync_read;
volatile uint8_t  * gp_uart5_tx_address;       /* uart5 transmit data address */
volatile uint16_t   g_uart5_tx_count;          /* uart5 transmit data number */
volatile uint8_t  * gp_uart5_rx_address;       /* uart5 receive data address */
volatile uint16_t   g_uart5_rx_count;          /* uart5 receive data number */
volatile uint16_t   g_uart5_rx_length;         /* uart5 receive data length */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_UART5_Create
* Description  : This function initializes the UART5 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART5_Create(void)
{
    /* Set LIN reset mode */
    RLN35.LCUC = _UART_LIN_RESET_MODE_CAUSED;
    /* Disable ICRLIN35UR0 operation and clear request */
    INTC2.ICRLIN35UR0.BIT.MKRLIN35UR0 = _INT_PROCESSING_DISABLED;
    INTC2.ICRLIN35UR0.BIT.RFRLIN35UR0 = _INT_REQUEST_NOT_OCCUR;
    /* Disable ICRLIN35UR1 operation and clear request */
    INTC2.ICRLIN35UR1.BIT.MKRLIN35UR1 = _INT_PROCESSING_DISABLED;
    INTC2.ICRLIN35UR1.BIT.RFRLIN35UR1 = _INT_REQUEST_NOT_OCCUR;
    /* Disable ICRLIN35UR2 operation and clear request */
    INTC2.ICRLIN35UR2.BIT.MKRLIN35UR2 = _INT_PROCESSING_DISABLED;
    INTC2.ICRLIN35UR2.BIT.RFRLIN35UR2 = _INT_REQUEST_NOT_OCCUR;
    /* Set ICRLIN35UR0 table method */
    INTC2.ICRLIN35UR0.BIT.TBRLIN35UR0 = _INT_TABLE_VECTOR;
    /* Set ICRLIN35UR0 priority */
    INTC2.ICRLIN35UR0.UINT16 &= _INT_PRIORITY_LOWEST;
    /* Set ICRLIN35UR1 table method */
    INTC2.ICRLIN35UR1.BIT.TBRLIN35UR1 = _INT_TABLE_VECTOR;
    /* Set ICRLIN35UR1 priority */
    INTC2.ICRLIN35UR1.UINT16 &= _INT_PRIORITY_LOWEST;
    /* Set ICRLIN35UR2 table method */
    INTC2.ICRLIN35UR2.BIT.TBRLIN35UR2 = _INT_TABLE_VECTOR;
    /* Set ICRLIN35UR2 priority */
    INTC2.ICRLIN35UR2.UINT16 &= _INT_PRIORITY_LOWEST;
    /* Set UART5 setting */
    RLN35.LWBR = _UART_9_SAMPLING | _UART_PRESCALER_CLOCK_SELECT_1;
    RLN35.LBRP01.UINT16 = _UART5_BAUD_RATE_PRESCALER;
    RLN35.LMD = _UART_NOISE_FILTER_ENABLED | _UART_MODE_SELECT;
    RLN35.LEDE = _UART_FRAMING_ERROR_DETECTED | _UART_OVERRUN_ERROR_DETECTED | _UART_BIT_ERROR_DETECTED;
    RLN35.LBFC = _UART_TRANSMISSION_NORMAL | _UART_RECEPTION_NORMAL | _UART_PARITY_PROHIBITED | _UART_STOP_BIT_1 | 
                 _UART_LSB | _UART_LENGTH_8;
    RLN35.LCUC = _UART_LIN_RESET_MODE_CANCELED;
    /* Synchronization processing */
    g_cg_sync_read = RLN35.LCUC;
    __syncp(); 
    /* Set RLIN35RX pin */
    PORT.PIBC11 &= _PORT_CLEAR_BIT9;
    PORT.PBDC11 &= _PORT_CLEAR_BIT9;
    PORT.PM11 |= _PORT_SET_BIT9;  
    PORT.PMC11 &= _PORT_CLEAR_BIT9;
    PORT.PIPC11 &= _PORT_CLEAR_BIT9;
    PORT.PFC11 &= _PORT_CLEAR_BIT9;
    PORT.PFCAE11 |= _PORT_SET_BIT9;  
    PORT.PMC11 |= _PORT_SET_BIT9;  
    /* Set RLIN35TX pin */
    PORT.PIBC11 &= _PORT_CLEAR_BIT8;
    PORT.PBDC11 &= _PORT_CLEAR_BIT8;
    PORT.PM11 |= _PORT_SET_BIT8;  
    PORT.PMC11 &= _PORT_CLEAR_BIT8;
    PORT.PFC11 &= _PORT_CLEAR_BIT8;
    PORT.PMC11 |= _PORT_SET_BIT8;  
    PORT.PM11 &= _PORT_CLEAR_BIT8;
}
/***********************************************************************************************************************
* Function Name: R_UART5_Start
* Description  : This function starts the UART5 operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART5_Start(void)
{
    /* Enable UART5 operation */
    RLN35.LUOER |= _UART_RECEPTION_ENABLED | _UART_TRABSMISSION_ENABLED;
    /* Clear ICRLIN35UR0 interrupt request and enable operation */
    INTC2.ICRLIN35UR0.BIT.RFRLIN35UR0 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICRLIN35UR0.BIT.MKRLIN35UR0 = _INT_PROCESSING_ENABLED;    
    /* Clear ICRLIN35UR1 interrupt request and enable operation */
    INTC2.ICRLIN35UR1.BIT.RFRLIN35UR1 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICRLIN35UR1.BIT.MKRLIN35UR1 = _INT_PROCESSING_ENABLED;    
    /* Clear ICRLIN35UR2 interrupt request and enable operation */
    INTC2.ICRLIN35UR2.BIT.RFRLIN35UR2 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICRLIN35UR2.BIT.MKRLIN35UR2 = _INT_PROCESSING_ENABLED;    
}
/***********************************************************************************************************************
* Function Name: R_UART5_Stop
* Description  : This function stops the UART5 operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART5_Stop(void)
{
    /* Disable ICRLIN35UR0 operation */
    INTC2.ICRLIN35UR0.BIT.MKRLIN35UR0 = _INT_PROCESSING_DISABLED;
    /* Disable ICRLIN35UR1 operation */
    INTC2.ICRLIN35UR1.BIT.MKRLIN35UR1 = _INT_PROCESSING_DISABLED;
    /* Disable ICRLIN35UR2 operation */
    INTC2.ICRLIN35UR2.BIT.MKRLIN35UR2 = _INT_PROCESSING_DISABLED;
    /* Disable UART5 operation */
    RLN35.LUOER &= (uint8_t) ~(_UART_RECEPTION_ENABLED | _UART_TRABSMISSION_ENABLED);
    /* Synchronization processing */
    g_cg_sync_read = RLN35.LCUC;
    __syncp();
    /* Clear ICRLIN35UR0 request */
    INTC2.ICRLIN35UR0.BIT.RFRLIN35UR0 = _INT_REQUEST_NOT_OCCUR;
    /* Clear ICRLIN35UR1 request */
    INTC2.ICRLIN35UR1.BIT.RFRLIN35UR1 = _INT_REQUEST_NOT_OCCUR;
    /* Clear ICRLIN35UR2 request */
    INTC2.ICRLIN35UR2.BIT.RFRLIN35UR2 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = RLN35.LCUC;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_UART5_Receive
* Description  : This function receives UART5 data.
* Arguments    : rx_buf -
*                    receive buffer pointer
*                rx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_UART5_Receive(uint8_t * const rx_buf, uint16_t rx_num)
{
    MD_STATUS status = MD_OK;

    if (rx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        if ((RLN35.LST & _UART_RECEPTION_OPERATED) == 0U)
        {
            g_uart5_rx_count = 0U;
            g_uart5_rx_length = rx_num;
            gp_uart5_rx_address = rx_buf;
        }
    }

    return (status);
}
/***********************************************************************************************************************
* Function Name: R_UART5_Send
* Description  : This function sends UART5 data.
* Arguments    : tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR or MD_ERROR
***********************************************************************************************************************/
MD_STATUS R_UART5_Send(uint8_t * const tx_buf, uint16_t tx_num)
{
    MD_STATUS status = MD_OK;
    uint32_t i =0;
    
    if(tx_buf == 0)
    {
	return MD_ARGERROR;
    }
    else
    {
	while(tx_buf[i] != '\0')
	{
	    i++;
	}
    }
    tx_num = i;
    if (tx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        gp_uart5_tx_address = tx_buf;
        g_uart5_tx_count = tx_num;       

        if ((RLN35.LST & _UART_TRANSMISSION_OPERATED) == 0U)
        {
            /* Clear ICRLIN35UR0 request and Disable operation */
            INTC2.ICRLIN35UR0.BIT.MKRLIN35UR0 = _INT_PROCESSING_DISABLED;
            INTC2.ICRLIN35UR0.BIT.RFRLIN35UR0 = _INT_REQUEST_NOT_OCCUR;
            RLN35.LUTDR.UINT16 = *gp_uart5_tx_address;
            gp_uart5_tx_address++;
            g_uart5_tx_count--;
            /* Clear ICRLIN35UR0 requestt and enable operation */
            INTC2.ICRLIN35UR0.BIT.RFRLIN35UR0 = _INT_REQUEST_NOT_OCCUR;
            INTC2.ICRLIN35UR0.BIT.MKRLIN35UR0 = _INT_PROCESSING_ENABLED;	
        }
        else
        {
            status = MD_ERROR;
        }
    }
    return (status);
}

/* Start user code for adding. Do not edit comment generated here */
void R_UART5_ReInit(void)
{
    PORT.PIBC11 &= ~(1u<<9);
    PORT.PM11 |= (1u<<9);
    
    PORT.PIBC11 &= ~(1u<<8);
    PORT.PM11 |= (1u<<8);
}
/* End user code. Do not edit comment generated here */
