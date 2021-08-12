/******************************************************************************* 
* DISCLAIMER 
* This software is supplied by Renesas Electronics Corporation and is only  
* intended for use with Renesas products. No other uses are authorized. This  
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE  
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. 
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS  
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE  
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software. By using this software, 
* you agree to the additional terms and conditions found by accessing the  
* following link: 
* http://www.renesas.com/disclaimer 
* 
* Copyright (C) 2012, 2014 Renesas Electronics Corporation. All rights reserved.     
*******************************************************************************/
/******************************************************************************* 
* File Name    : ICON_CAN.c
* Version      : 1.1 
* Description  : This is source file for CAN configuration.
******************************************************************************/ 
/***************************************************************************** 
* History      : DD.MM.YYYY Version Description 
*              : 28.09.2012 1.00     First Release 
*              : 31.03.2014 1.10
******************************************************************************/
#include "r_cg_can.h"

#if CANCFG_RX_RULE_NUM > 0
const uint32_t g_rxrule_table[CANCFG_RX_RULE_NUM][4] = {
    /* CAN1 */
   // { 0x00000000UL, 0xC0000000UL, 0x00000000UL, 0x000038F8UL }
    {0x00000010UL, 0xDFFFFFF0UL, 0xB0008000UL, 0x00000000UL}, /* NO.000 : std data frm ID = H'10~1F will be accepted, 20 data length, destination Rx Buffer0 */
    {0x00000020UL, 0xDFFFFFF0UL, 0xB0008100UL, 0x00000000UL}, /* NO.001 : std data frm ID = H'20~2F will be accepted, destination Rx Buffer1 */
    {0x00000030UL, 0xDFFFFFF0UL, 0xB0008200UL, 0x00000000UL}, /* NO.002 : std data frm ID = H'30~3F will be accepted, destination Rx Buffer2 */
    {0x00000040UL, 0xDFFFFFF0UL, 0xB0008300UL, 0x00000000UL}, /* NO.003 : std data frm ID = H'40~4F will be accepted, destination Rx Buffer3 */
    {0x00000050UL, 0xDFFFFFFFUL, 0xB0008400UL, 0x00000000UL}, /* NO.004 : std data frm ID = H'50 will be accepted, destination Rx Buffer4 */
    {0x00000060UL, 0xDFFFFFFFUL, 0xB0008500UL, 0x00000000UL}, /* NO.005 : std data frm ID = H'60 will be accepted, destination Rx Buffer5 */
    {0x00000070UL, 0xDFFFFFFFUL, 0xB0008600UL, 0x00000000UL}, /* NO.006 : std data frm ID = H'70 will be accepted, destination Rx Buffer6 */
    {0x00000080UL, 0xDFFFFFFFUL, 0xB0008700UL, 0x00000000UL}, /* NO.007 : std data frm ID = H'80 will be accepted, destination Rx Buffer7 */
};
#endif

/* ---- RxFIFO ---- */
const uint8_t  g_rxfifo_use_table[CAN_MAX_RXFIFO_NUM] = {
    CANCFG_USE_RXFIFO_0, CANCFG_USE_RXFIFO_1,
    CANCFG_USE_RXFIFO_2, CANCFG_USE_RXFIFO_3,
    CANCFG_USE_RXFIFO_4, CANCFG_USE_RXFIFO_5,
    CANCFG_USE_RXFIFO_6, CANCFG_USE_RXFIFO_7
};

/* ---- Use Channel ---- */
const uint8_t  g_ch_use_table[CANDEV_CH_NUM] = {
#if CANDEV_CH_NUM > 0
    CANCFG_USE_CH0,
#endif
#if CANDEV_CH_NUM > 1
    CANCFG_USE_CH1,
#endif
#if CANDEV_CH_NUM > 2
    CANCFG_USE_CH2,
#endif
#if CANDEV_CH_NUM > 3
    CANCFG_USE_CH3,
#endif
#if CANDEV_CH_NUM > 4
    CANCFG_USE_CH4,
#endif
#if CANDEV_CH_NUM > 5
    CANCFG_USE_CH5,
#endif
};

/* ---- Common (Tx/Rx) FIFO ---- */
const uint8_t  g_trfifo_use_table[CANCFG_USE_CH_NUM][CAN_MAX_TRFIFO_NUM] = {
#if (CANDEV_CH_NUM > 0) && (CANCFG_USE_CH0 != CAN_NOUSE)
    { CANCFG_USE_TRFIFO_0,  CANCFG_USE_TRFIFO_1,  CANCFG_USE_TRFIFO_2  },
#endif
#if (CANDEV_CH_NUM > 1) && (CANCFG_USE_CH1 != CAN_NOUSE)
    { CANCFG_USE_TRFIFO_3,  CANCFG_USE_TRFIFO_4,  CANCFG_USE_TRFIFO_5  },
#endif
#if (CANDEV_CH_NUM > 2) && (CANCFG_USE_CH2 != CAN_NOUSE)
    { CANCFG_USE_TRFIFO_6,  CANCFG_USE_TRFIFO_7,  CANCFG_USE_TRFIFO_8  },
#endif
#if (CANDEV_CH_NUM > 3) && (CANCFG_USE_CH3 != CAN_NOUSE)
    { CANCFG_USE_TRFIFO_9,  CANCFG_USE_TRFIFO_10, CANCFG_USE_TRFIFO_11 },
#endif
#if (CANDEV_CH_NUM > 4) && (CANCFG_USE_CH4 != CAN_NOUSE)
    { CANCFG_USE_TRFIFO_12, CANCFG_USE_TRFIFO_13, CANCFG_USE_TRFIFO_14 },
#endif
#if (CANDEV_CH_NUM > 5) && (CANCFG_USE_CH5 != CAN_NOUSE)
    { CANCFG_USE_TRFIFO_15, CANCFG_USE_TRFIFO_16, CANCFG_USE_TRFIFO_17 },
#endif
};

/* ---- Tx queue ---- */
const uint8_t  g_txqueue_use_table[CANCFG_USE_CH_NUM] = {
#if (CANDEV_CH_NUM > 0) && (CANCFG_USE_CH0 != CAN_NOUSE)
    CANCFG_USE_TXQUEUE_0,
#endif
#if (CANDEV_CH_NUM > 1) && (CANCFG_USE_CH1 != CAN_NOUSE)
    CANCFG_USE_TXQUEUE_1,
#endif
#if (CANDEV_CH_NUM > 2) && (CANCFG_USE_CH2 != CAN_NOUSE)
    CANCFG_USE_TXQUEUE_2,
#endif
#if (CANDEV_CH_NUM > 3) && (CANCFG_USE_CH3 != CAN_NOUSE)
    CANCFG_USE_TXQUEUE_3,
#endif
#if (CANDEV_CH_NUM > 4) && (CANCFG_USE_CH4 != CAN_NOUSE)
    CANCFG_USE_TXQUEUE_4,
#endif
#if (CANDEV_CH_NUM > 5) && (CANCFG_USE_CH5 != CAN_NOUSE)
    CANCFG_USE_TXQUEUE_5,
#endif
};

/* ---- Register value ---- */
const can_ch_cfg_t  g_can_ch_cfg[CANCFG_USE_CH_NUM] = {
#if (CANDEV_CH_NUM > 0) && (CANCFG_USE_CH0 != CAN_NOUSE)
    {
        CANCFG_REG_CH0_CTRL,
        CANCFG_REG_CH0_BAUDRATE,
        CANCFG_REG_TRFIFO_0,  CANCFG_REG_TRFIFO_1,  CANCFG_REG_TRFIFO_2,
        CANCFG_REG_TXQUEUE_0,
        CANCFG_REG_CH0_TXBUF_IE
    },
#endif
#if (CANDEV_CH_NUM > 1) && (CANCFG_USE_CH1 != CAN_NOUSE)
    {
        CANCFG_REG_CH1_CTRL,
        CANCFG_REG_CH1_BAUDRATE,
        CANCFG_REG_TRFIFO_3,  CANCFG_REG_TRFIFO_4,  CANCFG_REG_TRFIFO_5,
        CANCFG_REG_TXQUEUE_1,
        CANCFG_REG_CH1_TXBUF_IE
    },
#endif
#if (CANDEV_CH_NUM > 2) && (CANCFG_USE_CH2 != CAN_NOUSE)
    {
        CANCFG_REG_CH2_CTRL,
        CANCFG_REG_CH2_BAUDRATE,
        CANCFG_REG_TRFIFO_6,  CANCFG_REG_TRFIFO_7,  CANCFG_REG_TRFIFO_8,
        CANCFG_REG_TXQUEUE_2,
        CANCFG_REG_CH2_TXBUF_IE
    },
#endif
#if (CANDEV_CH_NUM > 3) && (CANCFG_USE_CH3 != CAN_NOUSE)
    {
        CANCFG_REG_CH3_CTRL,
        CANCFG_REG_CH3_BAUDRATE,
        CANCFG_REG_TRFIFO_9,  CANCFG_REG_TRFIFO_10, CANCFG_REG_TRFIFO_11,
        CANCFG_REG_TXQUEUE_3,
        CANCFG_REG_CH3_TXBUF_IE
    },
#endif
#if (CANDEV_CH_NUM > 4) && (CANCFG_USE_CH4 != CAN_NOUSE)
    {
        CANCFG_REG_CH4_CTRL,
        CANCFG_REG_CH4_BAUDRATE,
        CANCFG_REG_TRFIFO_12, CANCFG_REG_TRFIFO_13, CANCFG_REG_TRFIFO_14,
        CANCFG_REG_TXQUEUE_4,
        CANCFG_REG_CH4_TXBUF_IE,
    },
#endif
#if (CANDEV_CH_NUM > 5) && (CANCFG_USE_CH5 != CAN_NOUSE)
    {
        CANCFG_REG_CH5_CTRL,
        CANCFG_REG_CH5_BAUDRATE,
        CANCFG_REG_TRFIFO_15, CANCFG_REG_TRFIFO_16, CANCFG_REG_TRFIFO_17,
        CANCFG_REG_TXQUEUE_5,
        CANCFG_REG_CH5_TXBUF_IE
    },
#endif
};

