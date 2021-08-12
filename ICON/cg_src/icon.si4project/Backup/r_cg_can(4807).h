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
* File Name    : ICON_CAN.h
* Version      : 1.1 
* Description  : This is include file for CAN configuration.
******************************************************************************/ 
/***************************************************************************** 
* History      : DD.MM.YYYY Version Description 
*              : 28.09.2012 1.00     First Release 
*              : 31.03.2014 1.10
******************************************************************************/
#ifndef ICON_CAN_H
#define ICON_CAN_H

#include "r_rh850_can_sfr.h"
#include "r_rh850_can_drv.h"

#define __CHECK__

/* ---- Define for configuration ---- */
#define CAN_NOUSE                   (0x00U)
#define CAN_USE                     (0x80U)
#define CAN_USE_RX_MODE             (0x81U)
#define CAN_USE_TX_MODE             (0x82U)
#define CAN_USE_GW_MODE             (0x83U)
#define CAN_USE_CH_MASK             (0x07U)

/* ---- Device information: RH850/F1L (R7F701031xAFP (144 pin)) ---- */
#define CANDEV_CH_NUM               (6U)
#define CANDEV_START_ADDR           (0xFFD00000UL)

/* ---- Channel number ---- */
#define CANCFG_USE_CH0              CAN_NOUSE
#define CANCFG_USE_CH1              (CAN_USE | 0U)
#define CANCFG_USE_CH2              CAN_NOUSE
#define CANCFG_USE_CH3              CAN_NOUSE
#define CANCFG_USE_CH4              CAN_NOUSE
#define CANCFG_USE_CH5              CAN_NOUSE
#define CANCFG_USE_CH_NUM           (1U)


/* ==== Global configuration ==== */
/* ---- Global setting ---- */
#define CANCFG_TX_PRIORITY          CAN_TX_ID_FIRST
#define CANCFG_DLC_CHECK            CAN_DISABLE
#define CANCFG_DLC_REPLACE          CAN_DISABLE
#define CANCFG_MIRROR               CAN_DISABLE
#define CANCFG_CLOCK                CAN_SOURCE_MAIN_CLOCK_X_DIV
#define CANCFG_TS_CLOCK             CAN_TS_PCLOCK
#define CANCFG_TS_PR                CAN_TS_NO_DIV
#define CANCFG_IT_PR                (0U)

#define CANCFG_OVERFLOW_IE          CAN_DISABLE
#define CANCFG_MSG_LOST_IE          CAN_DISABLE
#define CANCFG_DLC_ERROR_IE         CAN_DISABLE

#define CANCFG_REG_GLB_CONFIG \
    CAN_VAL_GLB_CONFIG(CANCFG_TX_PRIORITY, \
                       CANCFG_DLC_CHECK, CANCFG_DLC_REPLACE, \
                       CANCFG_MIRROR, CANCFG_CLOCK, \
                       CANCFG_TS_CLOCK, CANCFG_TS_PR, \
                       CANCFG_IT_PR)

#define CANCFG_REG_GLB_IE \
    CAN_VAL_GLB_IE(CANCFG_OVERFLOW_IE, \
                   CANCFG_MSG_LOST_IE, CANCFG_DLC_ERROR_IE)

/* ---- Rx rule ---- */
#define CANCFG_RX_RULE_NUM_CH0      (0U)
#define CANCFG_RX_RULE_NUM_CH1      (1U)
#define CANCFG_RX_RULE_NUM_CH2      (0U)
#define CANCFG_RX_RULE_NUM_CH3      (0U)
#define CANCFG_RX_RULE_NUM_CH4      (0U)
#define CANCFG_RX_RULE_NUM_CH5      (0U)
#define CANCFG_RX_RULE_NUM          (1U)

#define CANCFG_REG_RULENUM0 \
    CAN_VAL_RULENUM0(CANCFG_RX_RULE_NUM_CH0, CANCFG_RX_RULE_NUM_CH1, \
                     CANCFG_RX_RULE_NUM_CH2, CANCFG_RX_RULE_NUM_CH3)

#define CANCFG_REG_RULENUM1 \
    CAN_VAL_RULENUM1(CANCFG_RX_RULE_NUM_CH4, CANCFG_RX_RULE_NUM_CH5)

/* ---- Rx buffer ---- */
#define CANCFG_RBNUM                (16U)

/* ---- RxFIFO ---- */
#define CANCFG_USE_RXFIFO_0         CAN_USE
#define CANCFG_USE_RXFIFO_1         CAN_NOUSE
#define CANCFG_USE_RXFIFO_2         CAN_NOUSE
#define CANCFG_USE_RXFIFO_3         CAN_NOUSE
#define CANCFG_USE_RXFIFO_4         CAN_NOUSE
#define CANCFG_USE_RXFIFO_5         CAN_NOUSE
#define CANCFG_USE_RXFIFO_6         CAN_NOUSE
#define CANCFG_USE_RXFIFO_7         CAN_NOUSE

/* Rx FIFO 0 */
#define CANCFG_RXFIFO_0_DEPTH       CAN_FIFO_DEPTH_4
#define CANCFG_RXFIFO_0_IE          CAN_ENABLE
#define CANCFG_RXFIFO_0_IMODE       CAN_FIFO_INT_THRESHOLD
#define CANCFG_RXFIFO_0_ITHR        CAN_FIFO_THRESHOLD_2_8

#define CANCFG_REG_RXFIFO_0 \
    CAN_VAL_RXFIFO(CANCFG_RXFIFO_0_DEPTH, CANCFG_RXFIFO_0_IE, \
                   CANCFG_RXFIFO_0_IMODE, CANCFG_RXFIFO_0_ITHR)


/* ==== Channel 1 configuration ==== */
/* ---- Channel control ---- */
#define CANCFG_CH1_IE_BUS           CAN_DISABLE
#define CANCFG_CH1_IE_EW            CAN_DISABLE
#define CANCFG_CH1_IE_EP            CAN_DISABLE
#define CANCFG_CH1_IE_BOE           CAN_DISABLE
#define CANCFG_CH1_IE_BOR           CAN_DISABLE
#define CANCFG_CH1_IE_OL            CAN_DISABLE
#define CANCFG_CH1_IE_BL            CAN_DISABLE
#define CANCFG_CH1_IE_AL            CAN_DISABLE
#define CANCFG_CH1_IE_TA            CAN_DISABLE
#define CANCFG_CH1_BOFF_MODE        CAN_BOFF_RECOVERY_ISO11898
#define CANCFG_CH1_ER_DISP          CAN_ERRDISP_FIRST_ERR_ONLY

#define CANCFG_REG_CH1_CTRL \
    CAN_VAL_CH_CTRL(CANCFG_CH1_IE_BUS, CANCFG_CH1_IE_EW, CANCFG_CH1_IE_EP, \
                    CANCFG_CH1_IE_BOE, CANCFG_CH1_IE_BOR, CANCFG_CH1_IE_OL, \
                    CANCFG_CH1_IE_BL, CANCFG_CH1_IE_AL, CANCFG_CH1_IE_TA, \
                    CANCFG_CH1_BOFF_MODE, CANCFG_CH1_ER_DISP)

/* ---- Baudrate ---- */
#define CANCFG_CH1_BRP              (1U)
#define CANCFG_CH1_TSEG1            CAN_TSEG1_8TQ
#define CANCFG_CH1_TSEG2            CAN_TSEG2_7TQ
#define CANCFG_CH1_SJW              CAN_SJW_1TQ

#define CANCFG_REG_CH1_BAUDRATE \
    CAN_VAL_CH_BAUDRATE(CANCFG_CH1_BRP, CANCFG_CH1_TSEG1, CANCFG_CH1_TSEG2, \
                        CANCFG_CH1_SJW)

/* ---- Common (Tx/Rx) FIFO 3 ---- */
#define CANCFG_USE_TRFIFO_3         CAN_USE_RX_MODE

#define CANCFG_TRFIFO_3_DEPTH       CAN_FIFO_DEPTH_4

#define CANCFG_TRFIFO_3_RX_IE       CAN_ENABLE
#define CANCFG_TRFIFO_3_IMODE       CAN_FIFO_INT_THRESHOLD
#define CANCFG_TRFIFO_3_ITHR        CAN_FIFO_THRESHOLD_2_8

#define CANCFG_REG_TRFIFO_3 \
    CAN_VAL_TRFIFO_RX(CANCFG_TRFIFO_3_DEPTH, CANCFG_TRFIFO_3_RX_IE, \
                      CANCFG_TRFIFO_3_IMODE, CANCFG_TRFIFO_3_ITHR)

/* ---- Common (Tx/Rx) FIFO 4 ---- */
#define CANCFG_USE_TRFIFO_4        CAN_NOUSE
#define CANCFG_REG_TRFIFO_4        (0UL)

/* ---- Common (Tx/Rx) FIFO 5 ---- */
#define CANCFG_USE_TRFIFO_5        CAN_NOUSE
#define CANCFG_REG_TRFIFO_5        (0UL)

/* ---- Tx queue 1 ---- */
#define CANCFG_USE_TXQUEUE_1        CAN_NOUSE
#define CANCFG_REG_TXQUEUE_1        (0UL)

/* ---- Tx buffer transmission complete interrupt ---- */
#define CANCFG_REG_CH1_TXBUF_IE     (0x0000U)


/* ==== External variables ==== */
extern const uint8_t       g_ch_use_table[];
extern const uint8_t       g_rxfifo_use_table[CAN_MAX_RXFIFO_NUM];
extern const uint8_t       g_trfifo_use_table[][CAN_MAX_TRFIFO_NUM];
extern const uint8_t       g_txqueue_use_table[];
extern const can_ch_cfg_t  g_can_ch_cfg[];
extern const uint8_t  g_fifo_lost_isr;
#if CANCFG_RX_RULE_NUM > 0
extern const uint32_t g_rxrule_table[][4];
#endif /* CANCFG_RX_RULE_NUM > 0 */

#endif

