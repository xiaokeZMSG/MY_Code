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
* File Name    : r_rh850_can_drv.h 
* Version      : 1.1 
* Description  : This is header file for CAN driver code.
******************************************************************************/ 
/***************************************************************************** 
* History      : DD.MM.YYYY Version Description 
*              : 28.09.2012 1.00     First Release 
*              : 31.03.2014 1.10
******************************************************************************/
#ifndef R_RH850_CAN_DRV_H
#define R_RH850_CAN_DRV_H
#include "r_typedefs.h"
#if 0
typedef signed char         int8_t;
typedef unsigned char       uint8_t;
typedef signed short        int16_t;
typedef unsigned short      uint16_t;
typedef signed long         int32_t;
typedef unsigned long       uint32_t;
typedef signed long long    int64_t;
typedef unsigned long long  uint64_t;
#endif

typedef unsigned int  Can_RtnType;

typedef uint8_t  can_ch_t;
typedef uint8_t  can_rxfifo_t;
typedef uint8_t  can_trfifo_t;
typedef uint8_t  can_txbuf_t;

/* ---- Channel ---- */
#define CAN_CH0             (0U)
#define CAN_CH1             (1U)
#define CAN_CH2             (2U)
#define CAN_CH3             (3U)
#define CAN_CH4             (4U)
#define CAN_CH5             (5U)

/* ---- Rx FIFO ---- */
#define CAN_RXFIFO0         (0U)
#define CAN_RXFIFO1         (1U)
#define CAN_RXFIFO2         (2U)
#define CAN_RXFIFO3         (3U)
#define CAN_RXFIFO4         (4U)
#define CAN_RXFIFO5         (5U)
#define CAN_RXFIFO6         (6U)
#define CAN_RXFIFO7         (7U)
#define CAN_MAX_RXFIFO_NUM  (8U)

/* ---- Common (Tx/Rx) FIFO ---- */
#define CAN_TRFIFO0         (0U)
#define CAN_TRFIFO1         (1U)
#define CAN_TRFIFO2         (2U)
#define CAN_MAX_TRFIFO_NUM  (3U)

/* ---- Tx buffers ---- */
#define CAN_TXBUF0          (0U)
#define CAN_TXBUF1          (1U)
#define CAN_TXBUF2          (2U)
#define CAN_TXBUF3          (3U)
#define CAN_TXBUF4          (4U)
#define CAN_TXBUF5          (5U)
#define CAN_TXBUF6          (6U)
#define CAN_TXBUF7          (7U)
#define CAN_TXBUF8          (8U)
#define CAN_TXBUF9          (9U)
#define CAN_TXBUF10         (10U)
#define CAN_TXBUF11         (11U)
#define CAN_TXBUF12         (12U)
#define CAN_TXBUF13         (13U)
#define CAN_TXBUF14         (14U)
#define CAN_TXBUF15         (15U)
#define CAN_MAX_TXBUF_NUM   (16U)

/* ---- CAN frame ----- */
typedef struct
{
    uint32_t ID :29;   /* ID Data                            */
    uint32_t THDSE :1; /* Transmit History Data Store Enable */
    uint32_t RTR :1;   /* RTR  0:Data 1:Remote               */
    uint32_t IDE :1;   /* IDE  0:Standard 1:Extend           */
    uint32_t TS :16;   /* Timestamp Data                     */
    uint32_t LBL :12;  /* Label Data                         */
    uint32_t DLC :4;   /* DLC Data                           */
    uint8_t  DB[8];    /* Data Byte                          */
} can_frame_t;

typedef struct {
    /* ---- Channel control ---- */
    uint32_t  ch_func;
    /* ---- Baudrate ---- */
    uint32_t  br_cfg;
    /* ---- Common (Tx/Rx) FIFO ---- */
    uint32_t  tr0_cfg;
    uint32_t  tr1_cfg;
    uint32_t  tr2_cfg;
    /* ---- Tx queue ---- */
    uint32_t  tq_cfg;
    /* ---- Tx buffer transmission complete interrupt ---- */
    uint16_t  tb_int_cfg;
    uint8_t   dummy[2];
} can_ch_cfg_t;

/* ---- function return value ---- */
#define CAN_RTN_OK                          (0U)
#define CAN_RTN_OK_WITH_LOST                (1U)
#define CAN_RTN_FIFO_FULL                   (2U)
#define CAN_RTN_BUFFER_EMPTY                (3U)
#define CAN_RTN_MODE_WAIT                   (4U)
#define CAN_RTN_RAM_INIT                    (5U)

#define CAN_RTN_TRANSMITTING                (0U)
#define CAN_RTN_TX_ABORT_OVER               (1U)
#define CAN_RTN_TX_END                      (2U)
#define CAN_RTN_TX_END_WITH_ABORT_REQ       (3U)

#define CAN_RTN_ERROR                       (0x80000000UL)
#define CAN_RTN_ARG_ERROR                   (CAN_RTN_ERROR + 0x7FFFFFFF)
#define CAN_RTN_STS_ERROR                   (CAN_RTN_ERROR + 0x7FFFFFFE)
#define CAN_RTN_OVERWRITE                   (CAN_RTN_ERROR + 0x7FFFFFFD)
#define CAN_RTN_MODE_ERROR                  (CAN_RTN_ERROR + 0x7FFFFFFC)

extern Can_RtnType R_CAN_Init(uint8_t Controller, const uint16_t Baudrate);
extern Can_RtnType R_CAN_GlobalStart(void);
extern Can_RtnType R_CAN_ChStart(can_ch_t ch_idx);
extern Can_RtnType R_CAN_TrmByTxBuf(can_ch_t ch_idx, can_txbuf_t txbuf_idx, const can_frame_t* pFrame);
extern Can_RtnType R_CAN_AbortTrm(can_ch_t ch_idx, uint32_t NrMail);
extern Can_RtnType R_CAN_CheckTxBufResult(can_ch_t ch_idx, can_txbuf_t txbuf_idx);
extern Can_RtnType R_CAN_TrmByTRFIFO(can_ch_t ch_idx, can_trfifo_t trfifo_idx, const can_frame_t* pFrame);
extern Can_RtnType R_CAN_TrmByTxQueue(can_ch_t ch_idx, const can_frame_t* pFrame);
extern Can_RtnType R_CAN_ReadRxBuffer(uint8_t* p_rxbuf_idx, can_frame_t* pFrame);
extern Can_RtnType R_CAN_ReadRxFIFO(can_rxfifo_t rxfifo_idx, can_frame_t* pFrame);
extern Can_RtnType R_CAN_ReadTRFIFO(can_ch_t ch_idx, can_trfifo_t trfifo_idx, can_frame_t* pFrame);
extern Can_RtnType R_CAN_ReadChStatus(can_ch_t ch_idx);

#endif /* R_RH850_CAN_DRV_H */
