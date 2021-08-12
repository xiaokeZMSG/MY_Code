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
* File Name    : r_cg_riic_user.c
* Version      : Code Generator for RH850/F1K V1.01.00.02 [19 Apr 2017]
* Device(s)    : R7F701582(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for RIIC module.
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
#include "r_cg_riic.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint8_t          g_riic0_mode_flag;               /* RIIC0 master transmit receive flag */
extern volatile uint8_t          g_riic0_state;                   /* RIIC0 master state */
extern volatile uint16_t         g_riic0_slave_address;           /* RIIC0 slave address */
extern volatile const uint8_t *  gp_riic0_tx_address;             /* RIIC0 transmit buffer address */
extern volatile uint16_t         g_riic0_tx_count;                /* RIIC0 transmit data number */
extern volatile uint8_t *        gp_riic0_rx_address;             /* RIIC0 receive buffer address */
extern volatile uint16_t         g_riic0_rx_count;                /* RIIC0 receive data number */
extern volatile uint16_t         g_riic0_rx_length;               /* RIIC0 receive data length */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_riic0_transmit_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_riic0_transmit_interrupt(enable=false, channel=76, fpu=true, callt=false)
void r_riic0_transmit_interrupt(void)
{
    if (g_riic0_mode_flag == _RIIC_MASTER_TRANSMIT)
    {
        if (g_riic0_state == _RIIC_MASTER_SENDS_ADR_7_W)
        {
            RIIC0.DRT.UINT32 = (uint8_t)(g_riic0_slave_address << _RIIC_ADDRESS_7BIT_SHIFT);
            g_riic0_state = _RIIC_MASTER_SENDS_DATA;
        }
        else if (g_riic0_state == _RIIC_MASTER_SENDS_ADR_10A_W)
        {
            RIIC0.DRT.UINT32 = (uint8_t)(((g_riic0_slave_address & _RIIC_ADDRESS_10BIT_UPPER) >> _RIIC_ADDRESS_10BIT_SHIFT) | _RIIC_ADDRESS_10BIT_UPPER_FORMAT);
            g_riic0_state = _RIIC_MASTER_SENDS_ADR_10B;
        }
        else if (g_riic0_state == _RIIC_MASTER_SENDS_ADR_10B)
        {
            RIIC0.DRT.UINT32 = (uint8_t)(g_riic0_slave_address & _RIIC_ADDRESS_10BIT_LOWER);
            g_riic0_state = _RIIC_MASTER_SENDS_DATA;
        }
        else if (g_riic0_state == _RIIC_MASTER_SENDS_DATA)
        {
            if (g_riic0_tx_count > 0U)
            {
                RIIC0.DRT.UINT32 = *gp_riic0_tx_address;
                gp_riic0_tx_address++;
                g_riic0_tx_count--;
            } 
            else
            {
                g_riic0_state = _RIIC_MASTER_SENDS_END;
            }
        }
    }
    else if (g_riic0_mode_flag == _RIIC_MASTER_RECEIVE)
    {
        if (g_riic0_state == _RIIC_MASTER_SENDS_ADR_7_R)
        {
            RIIC0.DRT.UINT32 = (uint8_t)((g_riic0_slave_address << _RIIC_ADDRESS_7BIT_SHIFT)  | _RIIC_ADDRESS_RECEIVE);
            g_riic0_state = _RIIC_MASTER_RECEIVES_START;
        }
        else if (g_riic0_state == _RIIC_MASTER_SENDS_ADR_10A_W)
        {
            RIIC0.DRT.UINT32 = (uint8_t)(((g_riic0_slave_address & _RIIC_ADDRESS_10BIT_UPPER) >> _RIIC_ADDRESS_10BIT_SHIFT) | _RIIC_ADDRESS_10BIT_UPPER_FORMAT);
            g_riic0_state = _RIIC_MASTER_SENDS_ADR_10B;
        }
        else if (g_riic0_state == _RIIC_MASTER_SENDS_ADR_10B)
        {
            RIIC0.DRT.UINT32 = (uint8_t)(g_riic0_slave_address &  _RIIC_ADDRESS_10BIT_LOWER);
            g_riic0_state = _RIIC_MASTER_RECEIVES_RESTART;
        }
        else if (g_riic0_state == _RIIC_MASTER_RECEIVES_RESTART)
        {
            RIIC0.IER.UINT32 |= _RIIC_START_CONDITION_INT_ENABLE;
            /* Set restart condition flag */
            RIIC0.CR2.UINT32 |= _RIIC_RESTART_CONDITION_REQUEST;
        }
        else if (g_riic0_state == _RIIC_MASTER_SENDS_ADR_10A_R)
        {
            RIIC0.DRT.UINT32 = (uint8_t)(((g_riic0_slave_address &  _RIIC_ADDRESS_10BIT_UPPER) >> _RIIC_ADDRESS_10BIT_SHIFT) | _RIIC_ADDRESS_10BIT_UPPER_FORMAT | _RIIC_ADDRESS_RECEIVE);
            g_riic0_state = _RIIC_MASTER_RECEIVES_START;
        }
    }
}
/***********************************************************************************************************************
* Function Name: r_riic0_transmitend_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_riic0_transmitend_interrupt(enable=false, channel=79, fpu=true, callt=false)
void r_riic0_transmitend_interrupt(void)
{
    if (g_riic0_state == _RIIC_MASTER_SENDS_END)
    {
        RIIC0.SR2.UINT32 &= (uint32_t) ~_RIIC_STOP_CONDITION_DETECTED;
        RIIC0.CR2.UINT32 |= _RIIC_STOP_CONDITION_REQUEST;
        g_riic0_state = _RIIC_MASTER_SENDS_STOP;
    }
}
/***********************************************************************************************************************
* Function Name: r_riic0_receive_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_riic0_receive_interrupt(enable=false, channel=78, fpu=true, callt=false)
void r_riic0_receive_interrupt(void)
{
    volatile uint8_t dummy;
    uint16_t temp;

    if (g_riic0_state == _RIIC_MASTER_RECEIVES_START)
    {
        if (g_riic0_rx_length < 3U)					
        {					
            RIIC0.MR3.UINT32 |= _RIIC_WAIT;					
            if (g_riic0_rx_length == 1U)					
            {					
                RIIC0.MR3.UINT32 |= _RIIC_ACKBT_BIT_MODIFICATION_ENABLED;					
                RIIC0.MR3.UINT32 |= _RIIC_NACK_TRANSMISSION;					
            }					
        }					
        dummy = RIIC0.DRR.UINT32;					
					
        if (g_riic0_rx_length == 1U)					
        {					
            g_riic0_state = _RIIC_MASTER_RECEIVES_STOPPING;					
        }					
        else					
        {					
            g_riic0_state = _RIIC_MASTER_RECEIVES_DATA;					
        }					
    }
    else if (g_riic0_state == _RIIC_MASTER_RECEIVES_DATA)
    {
        temp = g_riic0_rx_length;
        if (g_riic0_rx_count < temp)
        {
			temp = g_riic0_rx_length;
            if (g_riic0_rx_count == (temp - 3U))
            {
                RIIC0.MR3.UINT32 |= _RIIC_WAIT;
                *gp_riic0_rx_address = RIIC0.DRR.UINT32;
                gp_riic0_rx_address++;
                g_riic0_rx_count++;
            }
            else if (g_riic0_rx_count == (temp - 2U))
            {
                RIIC0.MR3.UINT32 |= _RIIC_ACKBT_BIT_MODIFICATION_ENABLED;
                RIIC0.MR3.UINT32 |= _RIIC_NACK_TRANSMISSION;
                *gp_riic0_rx_address = RIIC0.DRR.UINT32;
                gp_riic0_rx_address++;
                g_riic0_rx_count++;
                g_riic0_state = _RIIC_MASTER_RECEIVES_STOPPING;
            }
            else
            {
                *gp_riic0_rx_address = RIIC0.DRR.UINT32;
                gp_riic0_rx_address++;
                g_riic0_rx_count++;
            }
        }
    }
    else if (g_riic0_state == _RIIC_MASTER_RECEIVES_STOPPING)
    {
        RIIC0.SR2.UINT32 &= (uint32_t) ~_RIIC_STOP_CONDITION_DETECTED;
        RIIC0.CR2.UINT32 |= _RIIC_STOP_CONDITION_REQUEST;
        *gp_riic0_rx_address = RIIC0.DRR.UINT32;
        gp_riic0_rx_address++;
        g_riic0_rx_count++;
        RIIC0.MR3.UINT32 &= (uint32_t) ~_RIIC_WAIT;
        g_riic0_state = _RIIC_MASTER_RECEIVES_STOP;
    }
}
/***********************************************************************************************************************
* Function Name: r_riic0_error_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_riic0_error_interrupt(enable=false, channel=77, fpu=true, callt=false)
void r_riic0_error_interrupt(void)
{
    volatile uint8_t dummy;

    if((RIIC0.IER.UINT32 & _RIIC_ARBITRATION_LOST_INT_ENABLE) && (RIIC0.SR2.UINT32 & _RIIC_ARBITRATION_LOST))
    {
        r_riic0_callback_receiveerror(MD_ERROR1);
    }
    else if((RIIC0.IER.UINT32 & _RIIC_TIMEOUT_INT_ENABLE) && (RIIC0.SR2.UINT32 & _RIIC_TIMEOUT_DETECTED))
    {
        r_riic0_callback_receiveerror(MD_ERROR2);
    }
    else if((RIIC0.IER.UINT32 & _RIIC_NACK_RECEPTION_INT_ENABLE) && (RIIC0.SR2.UINT32 & _RIIC_NACK_DETECTED)) 
    {
        /* Dummy read to release SCL */
        dummy = RIIC0.DRR.UINT32;
        RIIC0.SR2.UINT32 &= (uint32_t) ~_RIIC_NACK_DETECTED;
        r_riic0_callback_receiveerror(MD_ERROR3);
    }
    else if (g_riic0_mode_flag == _RIIC_MASTER_TRANSMIT)
    {
        if ((g_riic0_state == _RIIC_MASTER_SENDS_ADR_7_W) || (g_riic0_state == _RIIC_MASTER_SENDS_ADR_10A_W))
        {
            RIIC0.SR2.UINT32 &= (uint32_t) ~_RIIC_START_CONDITION_DETECTED;
            RIIC0.IER.UINT32 &= (uint32_t) ~_RIIC_START_CONDITION_INT_ENABLE;
        }
        else if (g_riic0_state == _RIIC_MASTER_SENDS_STOP)
        {
            RIIC0.SR2.UINT32 &= (uint32_t) ~_RIIC_NACK_DETECTED;
            RIIC0.SR2.UINT32 &= (uint32_t) ~_RIIC_STOP_CONDITION_DETECTED;

            r_riic0_callback_transmitend();
        }
    }
    else if (g_riic0_mode_flag == _RIIC_MASTER_RECEIVE)
    {
        if ((g_riic0_state == _RIIC_MASTER_SENDS_ADR_7_R) || (g_riic0_state == _RIIC_MASTER_SENDS_ADR_10A_W))
        {
            RIIC0.SR2.UINT32 &= (uint32_t) ~_RIIC_START_CONDITION_DETECTED;
            RIIC0.IER.UINT32 &= (uint32_t) ~_RIIC_START_CONDITION_INT_ENABLE;
        }
        else if (g_riic0_state == _RIIC_MASTER_RECEIVES_RESTART)
        {
            RIIC0.SR2.UINT32 &= (uint32_t) ~_RIIC_START_CONDITION_DETECTED;
            RIIC0.IER.UINT32 &= (uint32_t) ~_RIIC_START_CONDITION_INT_ENABLE;
            g_riic0_state = _RIIC_MASTER_SENDS_ADR_10A_R;
        }
        else if (g_riic0_state == _RIIC_MASTER_RECEIVES_STOP)
        {
            RIIC0.SR2.UINT32 &= (uint32_t) ~_RIIC_NACK_DETECTED;
            RIIC0.SR2.UINT32 &= (uint32_t) ~_RIIC_STOP_CONDITION_DETECTED;

            r_riic0_callback_receiveend();
        }
    }
}
/***********************************************************************************************************************
* Function Name: r_riic0_callback_transmitend
* Description  : This function is a callback function when RIIC0 completed data transmission.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_riic0_callback_transmitend(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_riic0_callback_receiveend
* Description  : This function is a callback function when  RIIC0 completed data reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_riic0_callback_receiveend(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_riic0_callback_receiveerror
* Description  : This function is a callback function when  RIIC0 transfer error or event generation occures.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_riic0_callback_receiveerror(MD_STATUS status)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
