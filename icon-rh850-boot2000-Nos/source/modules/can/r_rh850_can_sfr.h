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
* File Name    : r_rh850_can_sfr.h 
* Version      : 1.1 
* Description  : This is include file for CAN I/O registers.
******************************************************************************/ 
/***************************************************************************** 
* History      : DD.MM.YYYY Version Description 
*              : 28.09.2012 1.00     First Release 
*              : 31.03.2014 1.10
******************************************************************************/
#ifndef R_RH850_CAN_SFR_H
#define R_RH850_CAN_SFR_H

#define CANDEV_CH_NUM               (6U)
#define CANDEV_START_ADDR           (0xFFD00000UL)

#define BIT_ON(x)     (unsigned long)(1 << (x))
#define BITS_2_ON(x)  (unsigned long)(3 << (x))

/* ---- Address ---- */
#define CAN_REG8(x)   (*((volatile unsigned char *)(CANDEV_START_ADDR + (x))))
#define CAN_REG16(x)  (*((volatile unsigned short *)(CANDEV_START_ADDR + (x))))
#define CAN_REG32(x)  (*((volatile unsigned long *)(CANDEV_START_ADDR + (x))))

/* ---- Channel ---- */
typedef struct {
    volatile unsigned long CmCFG;
    volatile unsigned long CmCTR;
    volatile unsigned long CmSTS;
    volatile unsigned long CmERFL;
} can_ch_top_sfr_t;

#define RSCAN0CmCFG(ch)              CAN_REG32(0x0000 + (sizeof(can_ch_top_sfr_t) * (ch)))
#define RSCAN0TMTCSTSy16(ch)         CAN_REG16(0x370+2*(ch))

/* ---- Global ---- */
//#define RSCAN0GCFG                   CAN_REG32(0x0084)
//#define RSCAN0GCTR                   CAN_REG32(0x0088)
//#define RSCAN0GSTS                   CAN_REG32(0x008C)
//#define RSCAN0GERFL                  CAN_REG32(0x0090)
//#define RSCAN0FMSTS                  CAN_REG32(0x0240)

/* ---- Rx rules ---- */
//#define RSCAN0GAFLECTR               CAN_REG32(0x0098)
#define RSCAN0GAFLCFG(x)            CAN_REG32(0x009C + (0x04 * (x)))

/* ---- Rx buffers ---- */
//#define RSCAN0RMNB                   CAN_REG32(0x00A4)
#define RSCAN0RMND(ch)               CAN_REG16(0x00A8 + (0x02 * (ch)))

/* ---- Rx FIFO ---- */
#define RSCAN0RFCCx(rxfifo)          CAN_REG32(0x00B8 + (0x04 * (rxfifo)))
#define RSCAN0RFSTSx(rxfifo)         CAN_REG32(0x00D8 + (0x04 * (rxfifo)))
#define RSCAN0RFPCTRx(rxfifo)        CAN_REG32(0x00F8 + (0x04 * (rxfifo)))


/* ---- Ch Set/status---- */
//#define RSCAN0CmCFG(ch)              CAN_REG32(0x0000 + (0x10 * (ch)))
#define RSCAN0CmCTR(ch)              CAN_REG32(0x0004 + (0x10 * (ch)))
#define RSCAN0CmSTS(ch)              CAN_REG32(0x0008 + (0x10 * (ch)))
#define RSCAN0CmERFL(ch)             CAN_REG32(0x000C + (0x10 * (ch)))


/* ---- Common (Tx/Rx) FIFO ---- */
#define RSCAN0CFCCk(ch, trfifo)      CAN_REG32(0x0118 + (0x0C * (ch)) + (0x04 * (trfifo)))
#define RSCAN0CFSTSk(ch, trfifo)     CAN_REG32(0x0178 + (0x0C * (ch)) + (0x04 * (trfifo)))
#define RSCAN0CFPCTRk(ch, trfifo)    CAN_REG32(0x01D8 + (0x0C * (ch)) + (0x04 * (trfifo)))

/* ---- Tx buffers ---- */
#define RSCAN0TMCp(ch, txbuf)        CAN_REG8(0x0250 + (0x10 * (ch)) + txbuf)
#define RSCAN0TMSTSp(ch, txbuf)      CAN_REG8(0x02D0 + (0x10 * (ch)) + txbuf)
#define RSCAN0TMIEC(ch)              CAN_REG16(0x0390 + (0x02 * (ch)))
#define RSCAN0TMTARSTSy(ch)          CAN_REG16(0x0360 + (0x02 * (ch)))


/* ---- Tx queue ---- */
#define RSCAN0TXQCCm(ch)             CAN_REG32(0x03A0 + (0x04 * (ch)))
#define RSCAN0TXQSTSn(ch)            CAN_REG32(0x03C0 + (0x04 * (ch)))
#define RSCAN0TXQPCTRn(ch)           CAN_REG32(0x03E0 + (0x04 * (ch)))

/* ---- RAM ---- */
#define RSCAN0GAFLIDj(rxrule)        CAN_REG32(0x0500 + (0x10 * (rxrule)))

#define RSCAN0RMIDp(buf)             CAN_REG32(0x0600 + (0x10 * (buf)))

#define RSCAN0RFIDx(rxfifo)          CAN_REG32(0x0E00 + (0x10 * (rxfifo)))

#define RSCAN0CFIDk(ch, trfifo)      CAN_REG32(0x0E80 + (0x30 * (ch)) + (0x10 * (trfifo)))

#define RSCAN0TMIDp(ch, txbuf)       CAN_REG32(0x1000 + (0x100 * (ch)) + (0x10 * (txbuf)))
#define RSCAN0TMID15n(ch)            CAN_REG32(0x10F0 + (0x100 * (ch)))


/* ==== CAN SFR register bit field position ==== */
/* ---- RSCAN0CmCFG ---- */
#define CAN_SJW_BIT_POS                 (24U)
#define CAN_TSEG2_BIT_POS               (20U)
#define CAN_TSEG1_BIT_POS               (16U)
#define CAN_BRP_BIT_POS                  (0U)

#define CAN_VAL_CH_BAUDRATE(brp, tseg1, tseg2, sjw) \
    ( ((brp)   << CAN_BRP_BIT_POS  ) \
    | ((tseg1) << CAN_TSEG1_BIT_POS) \
    | ((tseg2) << CAN_TSEG2_BIT_POS) \
    | ((sjw)   << CAN_SJW_BIT_POS  ) )

/* ---- RSCAN0CmCTR ---- */
#define CAN_ERRD_BIT_POS                (23U)
#define CAN_BOM_BIT_POS                 (21U)
#define CAN_TAIE_BIT_POS                (16U)
#define CAN_ALIE_BIT_POS                (15U)
#define CAN_BLIE_BIT_POS                (14U)
#define CAN_OLIE_BIT_POS                (13U)
#define CAN_BORIE_BIT_POS               (12U)
#define CAN_BOEIE_BIT_POS               (11U)
#define CAN_EPIE_BIT_POS                (10U)
#define CAN_EWIE_BIT_POS                 (9U)
#define CAN_BEIE_BIT_POS                 (8U)
#define CAN_CSLPR_BIT_POS                (2U)
#define CAN_CHMDC_BIT_POS                (0U)

#define CAN_VAL_CH_CTRL(ie_bus, ie_ew, ie_ep, ie_boe, \
                        ie_bor, ie_ol, ie_bl, ie_al,  \
                        ie_ta, boff_mode, er_disp)    \
    ( ((ie_bus)    << CAN_BEIE_BIT_POS ) \
    | ((ie_ew)     << CAN_EWIE_BIT_POS ) \
    | ((ie_ep)     << CAN_EPIE_BIT_POS ) \
    | ((ie_boe)    << CAN_BOEIE_BIT_POS) \
    | ((ie_bor)    << CAN_BORIE_BIT_POS) \
    | ((ie_ol)     << CAN_OLIE_BIT_POS ) \
    | ((ie_bl)     << CAN_BLIE_BIT_POS ) \
    | ((ie_al)     << CAN_ALIE_BIT_POS ) \
    | ((ie_ta)     << CAN_TAIE_BIT_POS ) \
    | ((boff_mode) << CAN_BOM_BIT_POS  ) \
    | ((er_disp)   << CAN_ERRD_BIT_POS ) )

#define CAN_STP_BIT_ON                  BIT_ON(CAN_CSLPR_BIT_POS)
#define CAN_MODE_BITS_ON                BITS_2_ON(CAN_CHMDC_BIT_POS)

/* ---- RSCAN0CmSTS ---- */
#define CAN_CSLPSTS_BIT_POS              (2U)
#define CAN_CRSTSTS_BIT_POS              (0U)

#define CAN_STP_STS_BIT_ON              BIT_ON(CAN_CSLPSTS_BIT_POS)
#define CAN_RST_STS_BIT_ON              BIT_ON(CAN_CRSTSTS_BIT_POS)

/* ---- RSCAN0GCFG ---- */
#define CAN_ITRCP_BIT_POS               (16U)
#define CAN_TSSS_BIT_POS                (12U)
#define CAN_TSP_BIT_POS                  (8U)
#define CAN_DCS_BIT_POS                  (4U)
#define CAN_MME_BIT_POS                  (3U)
#define CAN_DRE_BIT_POS                  (2U)
#define CAN_DCE_BIT_POS                  (1U)
#define CAN_TPRI_BIT_POS                 (0U)

#define CAN_VAL_GLB_CONFIG(priority, dlc_check, dlc_replace, \
                           mirror, can_clock, ts_clock,      \
                           ts_pr, it_pr)                     \
    ( ((priority)    << CAN_TPRI_BIT_POS ) \
    | ((dlc_check)   << CAN_DCE_BIT_POS  ) \
    | ((dlc_replace) << CAN_DRE_BIT_POS  ) \
    | ((mirror)      << CAN_MME_BIT_POS  ) \
    | ((can_clock)   << CAN_DCS_BIT_POS  ) \
    | ((ts_pr)       << CAN_TSP_BIT_POS  ) \
    | ((ts_clock)    << CAN_TSSS_BIT_POS ) \
    | ((it_pr)       << CAN_ITRCP_BIT_POS) )

/* ---- RSCAN0GCTR ---- */
#define CAN_THLEIE_BIT_POS              (10U)
#define CAN_MEIE_BIT_POS                 (9U)
#define CAN_DEIE_BIT_POS                 (8U)
#define CAN_GSLPR_BIT_POS                (2U)
#define CAN_GMDC_BIT_POS                 (0U)

#define CAN_VAL_GLB_IE(overflow_ie, msg_lost_ie, dlc_error_ie) \
    ( ((overflow_ie)  << CAN_THLEIE_BIT_POS) \
    | ((msg_lost_ie)  << CAN_MEIE_BIT_POS  ) \
    | ((dlc_error_ie) << CAN_DEIE_BIT_POS  ) )

#define CAN_GLB_STP_BIT_ON              BIT_ON(CAN_GSLPR_BIT_POS)
#define CAN_GLB_MODE_BITS_ON            BITS_2_ON(CAN_GMDC_BIT_POS)

/* ---- RSCAN0GSTS ---- */
#define CAN_GRAMINIT_BIT_POS             (3U)
#define CAN_GSLPSTS_BIT_POS              (2U)
#define CAN_GRSTSTS_BIT_POS              (0U)

#define CAN_RAM_INIT_BIT_ON             BIT_ON(CAN_GRAMINIT_BIT_POS)
#define CAN_GLB_STP_STS_BIT_ON          BIT_ON(CAN_GSLPSTS_BIT_POS)
#define CAN_GLB_RST_STS_BIT_ON          BIT_ON(CAN_GRSTSTS_BIT_POS)

/* ---- RSCAN0GAFLECTR ---- */
#define CAN_AFLDAE_BIT_POS               (8U)

#define CAN_RX_RULE_WRT_EN_BIT_ON       BIT_ON(CAN_AFLDAE_BIT_POS)

/* ---- RSCAN0GAFLCFG0 ---- */
#define CAN_RNC0_BIT_POS                (24U)
#define CAN_RNC1_BIT_POS                (16U)
#define CAN_RNC2_BIT_POS                 (8U)
#define CAN_RNC3_BIT_POS                 (0U)

#define CAN_VAL_RULENUM0(ch0_num, ch1_num, ch2_num, ch3_num) \
    ( ((ch0_num) << CAN_RNC0_BIT_POS) \
    | ((ch1_num) << CAN_RNC1_BIT_POS) \
    | ((ch2_num) << CAN_RNC2_BIT_POS) \
    | ((ch3_num) << CAN_RNC3_BIT_POS) )

/* ---- RSCAN0GAFLCFG1 ---- */
#define CAN_RNC4_BIT_POS                (24U)
#define CAN_RNC5_BIT_POS                (16U)

#define CAN_VAL_RULENUM1(ch4_num, ch5_num) \
    ( ((ch4_num) << CAN_RNC4_BIT_POS) \
    | ((ch5_num) << CAN_RNC5_BIT_POS) )

/* ---- RSCAN0RFCCx ---- */
#define CAN_RFIGCV_BIT_POS              (13U)
#define CAN_RFIM_BIT_POS                (12U)
#define CAN_RFDC_BIT_POS                 (8U)
#define CAN_RFIE_BIT_POS                 (1U)
#define CAN_RFE_BIT_POS                  (0U)

#define CAN_VAL_RXFIFO(dc, i_enable, i_factor, i_timing) \
    ( ((i_timing) << CAN_RFIGCV_BIT_POS) \
    | ((i_factor) << CAN_RFIM_BIT_POS  ) \
    | ((i_enable) << CAN_RFIE_BIT_POS  ) \
    | ((dc)       << CAN_RFDC_BIT_POS  ) )

#define CAN_RFIFO_EN_BIT_ON             BIT_ON(CAN_RFE_BIT_POS)

/* ---- RSCAN0RFSTSx ---- */
#define CAN_RFIF_BIT_POS                 (3U)
#define CAN_RFMLT_BIT_POS                (2U)
#define CAN_RFEMP_BIT_POS                (0U)

#define CAN_RFIFO_MSGLST_BIT_ON         BIT_ON(CAN_RFMLT_BIT_POS)
#define CAN_RFIFO_EMPTY_BIT_ON          BIT_ON(CAN_RFEMP_BIT_POS)

#define CAN_CLR_WITHOUT_RX_INT          BIT_ON(CAN_RFIF_BIT_POS)

/* ---- RSCAN0CFCCk ---- */
#define CAN_CFITT_BIT_POS               (24U)
#define CAN_CFTML_BIT_POS               (20U)
#define CAN_CFITR_BIT_POS               (19U)
#define CAN_CFITSS_BIT_POS              (18U)
#define CAN_CFM_BIT_POS                 (16U)
#define CAN_CFIGCV_BIT_POS              (13U)
#define CAN_CFIM_BIT_POS                (12U)
#define CAN_CFDC_BIT_POS                 (8U)
#define CAN_CFTXIE_BIT_POS               (2U)
#define CAN_CFRXIE_BIT_POS               (1U)
#define CAN_CFE_BIT_POS                  (0U)

#define CAN_VAL_TRFIFO_TX(dc, txbuf_idx, i_enable, i_factor,  \
                          timer, time)                        \
    ( ((time)               << CAN_CFITT_BIT_POS ) \
    | ((txbuf_idx)          << CAN_CFTML_BIT_POS ) \
    | ((timer)              << CAN_CFITSS_BIT_POS) \
    | ((CAN_TRFIFO_TX_MODE) << CAN_CFM_BIT_POS   ) \
    | ((i_factor)           << CAN_CFIM_BIT_POS  ) \
    | ((dc)                 << CAN_CFDC_BIT_POS  ) \
    | ((i_enable)           << CAN_CFTXIE_BIT_POS) )

#define CAN_VAL_TRFIFO_RX(dc, i_enable, i_factor, i_timing)     \
    ( ((CAN_TRFIFO_RX_MODE) << CAN_CFM_BIT_POS   ) \
    | ((i_timing)           << CAN_CFIGCV_BIT_POS) \
    | ((i_factor)           << CAN_CFIM_BIT_POS  ) \
    | ((dc)                 << CAN_CFDC_BIT_POS  ) \
    | ((i_enable)           << CAN_CFRXIE_BIT_POS) )

#define CAN_VAL_TRFIFO_GW(dc, i_factor,                        \
                          txbuf_idx, tx_i_enable, timer, time, \
                          rx_i_enable, rx_i_timing)            \
    ( ((time)               << CAN_CFITT_BIT_POS ) \
    | ((txbuf_idx)          << CAN_CFTML_BIT_POS ) \
    | ((timer)              << CAN_CFITSS_BIT_POS) \
    | ((CAN_TRFIFO_GW_MODE) << CAN_CFM_BIT_POS   ) \
    | ((rx_i_timing)        << CAN_CFIGCV_BIT_POS) \
    | ((i_factor)           << CAN_CFIM_BIT_POS  ) \
    | ((dc)                 << CAN_CFDC_BIT_POS  ) \
    | ((tx_i_enable)        << CAN_CFTXIE_BIT_POS) \
    | ((rx_i_enable)        << CAN_CFRXIE_BIT_POS) )

#define CAN_TRFIFO_EN_BIT_ON            BIT_ON(CAN_CFE_BIT_POS)

/* ---- RSCAN0CFSTSk ---- */
#define CAN_CFTXIF_BIT_POS               (4U)
#define CAN_CFRXIF_BIT_POS               (3U)
#define CAN_CFMLT_BIT_POS                (2U)
#define CAN_CFFLL_BIT_POS                (1U)
#define CAN_CFEMP_BIT_POS                (0U)

#define CAN_TRFIFO_MSGLST_BIT_ON        BIT_ON(CAN_CFMLT_BIT_POS)
#define CAN_TRFIFO_FULL_BIT_ON          BIT_ON(CAN_CFFLL_BIT_POS)
#define CAN_TRFIFO_EMPTY_BIT_ON         BIT_ON(CAN_CFEMP_BIT_POS)

#define CAN_CLR_WITHOUT_TX_RX_INT \
    (BIT_ON(CAN_CFTXIF_BIT_POS) | BIT_ON(CAN_CFRXIF_BIT_POS))

/* ---- RSCAN0TXQCCm ---- */
#define CAN_TXQIM_BIT_POS               (13U)
#define CAN_TXQIE_BIT_POS               (12U)
#define CAN_TXQDC_BIT_POS                (8U)
#define CAN_TXQE_BIT_POS                 (0U)

#define CAN_VAL_TXQUEUE(dc, i_enable, i_factor) \
    ( ((dc)       << CAN_TXQDC_BIT_POS) \
    | ((i_factor) << CAN_TXQIM_BIT_POS) \
    | ((i_enable) << CAN_TXQIE_BIT_POS) )

#define CAN_TXQUEUE_EN_BIT_ON           BIT_ON(CAN_TXQE_BIT_POS)

/* ---- RSCAN0TMCp ---- */
#define CAN_TMTAR_BIT_POS                (1U)
#define CAN_TMTR_BIT_POS                 (0U)

#define CAN_TXBUF_ABT_BIT_ON            (uint8_t)(1 << (CAN_TMTAR_BIT_POS))
#define CAN_TXBUF_TRM_BIT_ON            (uint8_t)(1 << (CAN_TMTR_BIT_POS))

/* ---- RSCAN0TMSTSp ---- */
#define CAN_TMTRF_BIT_POS                (1U)

#define CAN_TXBUF_RSLT_BITS_POS         CAN_TMTRF_BIT_POS
#define CAN_TXBUF_RSLT_BITS_ON          (uint8_t)(3 << (CAN_TXBUF_RSLT_BITS_POS))

/* ---- RSCAN0TXQSTSn ---- */
#define CAN_TXQFLL_BIT_POS               (1U)

#define CAN_TXQUEUE_FULL_BIT_ON         BIT_ON(CAN_TXQFLL_BIT_POS)


/* ==== CAN SFR register value ==== */

/* ---- Enable ---- */
#define CAN_ENABLE                       (1U)
#define CAN_DISABLE                      (0U)

/* ---- Resynchronization jump width ---- */
#define CAN_SJW_1TQ                      (0U)
#define CAN_SJW_2TQ                      (1U)
#define CAN_SJW_3TQ                      (2U)
#define CAN_SJW_4TQ                      (3U)

/* ---- Time segment 2 ---- */
#define CAN_TSEG2_2TQ                    (1U)
#define CAN_TSEG2_3TQ                    (2U)
#define CAN_TSEG2_4TQ                    (3U)
#define CAN_TSEG2_5TQ                    (4U)
#define CAN_TSEG2_6TQ                    (5U)
#define CAN_TSEG2_7TQ                    (6U)
#define CAN_TSEG2_8TQ                    (7U)

/* ---- Time segment 1 ---- */
#define CAN_TSEG1_4TQ                    (3U)
#define CAN_TSEG1_5TQ                    (4U)
#define CAN_TSEG1_6TQ                    (5U)
#define CAN_TSEG1_7TQ                    (6U)
#define CAN_TSEG1_8TQ                    (7U)
#define CAN_TSEG1_9TQ                    (8U)
#define CAN_TSEG1_10TQ                   (9U)
#define CAN_TSEG1_11TQ                  (10U)
#define CAN_TSEG1_12TQ                  (11U)
#define CAN_TSEG1_13TQ                  (12U)
#define CAN_TSEG1_14TQ                  (13U)
#define CAN_TSEG1_15TQ                  (14U)
#define CAN_TSEG1_16TQ                  (15U)

/* ---- Error display mode ---- */
#define CAN_ERRDISP_FIRST_ERR_ONLY       (0U)
#define CAN_ERRDISP_ALL_ERR              (1U)

/* ---- Bus off recovery mode ---- */
#define CAN_BOFF_RECOVERY_ISO11898       (0U)
#define CAN_BOFF_RECOVERY_START_ENTRY    (1U)
#define CAN_BOFF_RECOVERY_END_ENTRY      (2U)
#define CAN_BOFF_RECOVERY_MANUAL_ENTRY   (3U)

/* ---- Channel mode ---- */
#define CAN_MODE_CH_COMM_MODE            (0U)
#define CAN_MODE_CH_RESET_MODE           (1U)
#define CAN_MODE_CH_HALT_MODE            (2U)

/* ---- Time stamp clock source ---- */
#define CAN_TS_PCLOCK                    (0U)
#define CAN_TS_CAN0_BT_CLOCK             (1U)
#define CAN_TS_CAN1_BT_CLOCK             (3U)
#define CAN_TS_CAN2_BT_CLOCK             (5U)
#define CAN_TS_CAN3_BT_CLOCK             (7U)
#define CAN_TS_CAN4_BT_CLOCK             (9U)
#define CAN_TS_CAN5_BT_CLOCK            (11U)

/* ---- Time stamp clock source division ---- */
#define CAN_TS_NO_DIV                    (0U)
#define CAN_TS_2_DIV                     (1U)
#define CAN_TS_4_DIV                     (2U)
#define CAN_TS_8_DIV                     (3U)
#define CAN_TS_16_DIV                    (4U)
#define CAN_TS_32_DIV                    (5U)
#define CAN_TS_64_DIV                    (6U)
#define CAN_TS_128_DIV                   (7U)
#define CAN_TS_256_DIV                   (8U)
#define CAN_TS_512_DIV                   (9U)
#define CAN_TS_1024_DIV                 (10U)
#define CAN_TS_2048_DIV                 (11U)
#define CAN_TS_4096_DIV                 (12U)
#define CAN_TS_8192_DIV                 (13U)
#define CAN_TS_16384_DIV                (14U)
#define CAN_TS_32768_DIV                (15U)

/* ---- CAN clock source ---- */
#define CAN_SOURCE_PCLOCK_PLL2           (0U)
#define CAN_SOURCE_MAIN_CLOCK_X_DIV      (1U)

/* ---- Transmission priority ---- */
#define CAN_TX_ID_FIRST                  (0U)
#define CAN_TX_BUF_IDX_FIRST             (1U)

/* ---- Global mode ---- */
#define CAN_GLB_OPERATION_MODE           (0U)
#define CAN_GLB_RESET_MODE               (1U)
#define CAN_GLB_TEST_MODE                (2U)

/* ---- FIFO (Rx, Common) interrupt generation timing ---- */
#define CAN_FIFO_THRESHOLD_1_8           (0U)
#define CAN_FIFO_THRESHOLD_2_8           (1U)
#define CAN_FIFO_THRESHOLD_3_8           (2U)
#define CAN_FIFO_THRESHOLD_4_8           (3U)
#define CAN_FIFO_THRESHOLD_5_8           (4U)
#define CAN_FIFO_THRESHOLD_6_8           (5U)
#define CAN_FIFO_THRESHOLD_7_8           (6U)
#define CAN_FIFO_THRESHOLD_FULL          (7U)

/* ---- FIFO (Rx, Common) interrupt factor ---- */
#define CAN_FIFO_INT_THRESHOLD           (0U)
#define CAN_FIFO_INT_EACH_MSG            (1U)

/* ---- FIFO (Rx, Common) depth define ---- */
#define CAN_FIFO_DEPTH_0                 (0U)
#define CAN_FIFO_DEPTH_4                 (1U)
#define CAN_FIFO_DEPTH_8                 (2U)
#define CAN_FIFO_DEPTH_16                (3U)
#define CAN_FIFO_DEPTH_32                (4U)
#define CAN_FIFO_DEPTH_48                (5U)
#define CAN_FIFO_DEPTH_64                (6U)
#define CAN_FIFO_DEPTH_128               (7U)

/* ---- Tx buffer ---- */
#define CAN_TX_BUFFER_0                  (0U)
#define CAN_TX_BUFFER_1                  (1U)
#define CAN_TX_BUFFER_2                  (2U)
#define CAN_TX_BUFFER_3                  (3U)
#define CAN_TX_BUFFER_4                  (4U)
#define CAN_TX_BUFFER_5                  (5U)
#define CAN_TX_BUFFER_6                  (6U)
#define CAN_TX_BUFFER_7                  (7U)
#define CAN_TX_BUFFER_8                  (8U)
#define CAN_TX_BUFFER_9                  (9U)
#define CAN_TX_BUFFER_10                (10U)
#define CAN_TX_BUFFER_11                (11U)
#define CAN_TX_BUFFER_12                (12U)
#define CAN_TX_BUFFER_13                (13U)
#define CAN_TX_BUFFER_14                (14U)
#define CAN_TX_BUFFER_15                (15U)

/* ---- Common FIFO interval time counter source ---- */
#define CAN_IT_PCLOCK                    (0U)
#define CAN_IT_CAN_BIT_CLK               (1U)
#define CAN_IT_PCLOCK_10                 (2U)

/* ---- Common FIFO mode ---- */
#define CAN_TRFIFO_RX_MODE               (0U)
#define CAN_TRFIFO_TX_MODE               (1U)
#define CAN_TRFIFO_GW_MODE               (2U)

/* ---- TX queue interrupt factor ---- */
#define CAN_TX_QUEUE_INT_EMPTY           (0U)
#define CAN_TX_QUEUE_INT_EACH_MSG        (1U)

/* ---- TX queue depth define ---- */
#define CAN_TX_QUEUE_DEPTH_0             (0U)
#define CAN_TX_QUEUE_DEPTH_3             (2U)
#define CAN_TX_QUEUE_DEPTH_4             (3U)
#define CAN_TX_QUEUE_DEPTH_5             (4U)
#define CAN_TX_QUEUE_DEPTH_6             (5U)
#define CAN_TX_QUEUE_DEPTH_7             (6U)
#define CAN_TX_QUEUE_DEPTH_8             (7U)
#define CAN_TX_QUEUE_DEPTH_9             (8U)
#define CAN_TX_QUEUE_DEPTH_10            (9U)
#define CAN_TX_QUEUE_DEPTH_11           (10U)
#define CAN_TX_QUEUE_DEPTH_12           (11U)
#define CAN_TX_QUEUE_DEPTH_13           (12U)
#define CAN_TX_QUEUE_DEPTH_14           (13U)
#define CAN_TX_QUEUE_DEPTH_15           (14U)
#define CAN_TX_QUEUE_DEPTH_16           (15U)

#define CANTMTSTS_ON                    (1)

#define CH1                             (1)
#define PASSIVE_ERROR_STATUS_MASK	    (0x8UL)
#define CLR_ALL_ERROR_FLAG	            (0x00007FFFUL)

#define CanLL_HwIsPassive( ch )         ((RSCAN0CmSTS(ch) & PASSIVE_ERROR_STATUS_MASK)!=0)
#define CanLL_ClrAllErrorFlag(ch)	    (RSCAN0CmERFL(ch) &= ~(CLR_ALL_ERROR_FLAG))


#endif /* R_RH850_CAN_SFR_H */
