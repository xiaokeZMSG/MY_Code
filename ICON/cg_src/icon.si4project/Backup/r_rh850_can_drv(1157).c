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
* File Name    : r_rh850_can_drv.c 
* Version      : 1.1 
* Description  : This is source file for CAN driver code.
******************************************************************************/ 
/***************************************************************************** 
* History      : DD.MM.YYYY Version Description 
*              : 28.09.2012 1.00     First Release 
*              : 31.03.2014 1.10
******************************************************************************/

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_rh850_can_drv.h"
#include "r_rh850_can_sfr.h"
#include "r_cg_can.h"
#include "r_cg_port.h"
#include "r_cg_macrodriver.h"

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Macro definitions
 *****************************************************************************/

#define CAN_FIFO_PTR_INC                    0xffUL

#define CAN_PAGE_RX_RULE_IDX_MASK           0xfU
#define CAN_RX_RULE_PAGE_IDX_BIT_POS        4U

#define CAN_8_BITS_MASK                     0x000000FFUL

#define MAX_CAN_DATA_NUM                         0x2U


/*****************************************************************************
 Private variables and functions
 *****************************************************************************/
/*===========================================================================*/
/* Variables */
/*===========================================================================*/
uint8_t can_num_cur = 0;    //0  send 0£»   1  send 1
/* Create Can_FrameType for send and receive data */
const can_frame_t CAN_TraStandData[MAX_CAN_DATA_NUM]=
{
{
  //ID
  0x0A,      // ID     29
  0,         // THDSE  1
  0,         // RTR    1
  0,         // IDE    1

  0x0000,    // TS     16					 
  0x00,      // LBL    12
  0x8,       // DLC    4

  //data 64
  {
	0x12,							 //DB0
	0x34,							 //DB1
	0x56,							 //DB2
	0x78,							 //DB3
	//
	0x87,							 //DB4
	0x65,							 //DB5
	0x43,							 //DB6
	0x21							 //DB7

	}
},
{
  //ID
  0x0B,      // ID     29
  0,         // THDSE  1
  0,         // RTR    1
  0,         // IDE    1

  0x0000,    // TS     16					 
  0x00,      // LBL    12
  0x8,       // DLC    4

  //data 64
  {
	0x55,							 //DB0
	0xaa,							 //DB1
	0x55,							 //DB2
	0xaa,							 //DB3
	//
	0x11,							 //DB4
	0x22,							 //DB5
	0x33,							 //DB6
	0x44							 //DB7

	}
}
};

/*****************************************************************************
 Exported global variables and functions (to be accessed by other files)
 *****************************************************************************/

/****************************************************************************** 
* Function Name: R_Can_Init
* Description  : Initialize CAN controller after reset
* Arguments    : none 
* Return Value : CAN_RTN_OK - 
*                    normal completion
*                CAN_RTN_RAM_INIT -
*                    CAN RAM initializing
*                CAN_RTN_MODE_WAIT -
*                    wait to change global mode or channel mode
******************************************************************************/

void R_CAN1_Creat(void)
{
    
    PORT.PFC10 |= (1u<<6);      
    PORT.PFCE10 |= (1u<<6);
    PORT.PFCAE10 &= ~(1u<<6);   
    PORT.PM10 |= (1u<<6);                         // 6 -- input   CAN1  RX  Alt4  input
    PORT.PMC10 |= (1u<<6);

    PORT.PFC10 |= (1u<<7);      
    PORT.PFCE10 |= (1u<<7);
    PORT.PFCAE10 &= ~(1u<<7);   
    PORT.PM10 &= ~(1u<<7);                        // 7--output    CAN1  TX  Alt4  output
    PORT.PMC10 |= (1u<<7);
      
    /* Enable Transceiver CAN1 */
    R_APORT0_SetCAN1(); 
    
    /* Initliaze CAN1 */
    while(CAN_RTN_OK != R_CAN_Init())
    {
        R_CAN_Init();
    }
    return;
}

/*****************************************************************************
** Function:    R_CAN1_Start
** Description: Sends a CAN frame on channel 1 
** Parameter:   None
** Return:      R_OK - Received frame matches sent frame.
**              R_ERROR - Mismatch detected.
******************************************************************************/
uint32_t R_CAN1_Start(void)

{
    R_CAN1_Creat();
    while(CAN_RTN_OK != R_CAN_GlobalStart())
    {
        __nop();
    };
	
    while(CAN_RTN_OK != R_CAN_ChStart(1))
    {
	    __nop();
    };

    return CAN_RTN_OK;
 
}

/*****************************************************************************
** Function:    R_CAN1_Test
** Description: Sends a CAN frame on channel 1 
** Parameter:   None
** Return:      R_OK - Received frame matches sent frame.
**              R_ERROR - Mismatch detected.
******************************************************************************/
uint32_t R_CAN1_Test(void)

{
    uint32_t i = 0;
    
    can_num_cur = can_num_cur + 1;
    if(can_num_cur >= 2)
    {
	can_num_cur = 0;
    }
       
    if(CAN_RTN_OK != R_CAN_TrmByTxBuf(1,0,&CAN_TraStandData[can_num_cur]))
    {
        return 1;
    }

    for(i=0; i<100000; i++);

    return 0;
}


/****************************************************************************** 
* Function Name: R_Can_Init
* Description  : Initialize CAN controller after reset
* Arguments    : none 
* Return Value : CAN_RTN_OK - 
*                    normal completion
*                CAN_RTN_RAM_INIT -
*                    CAN RAM initializing
*                CAN_RTN_MODE_WAIT -
*                    wait to change global mode or channel mode
******************************************************************************/
Can_RtnType R_CAN_Init(void)
{
    uint8_t ch_idx;

    const can_ch_cfg_t * p_cfg;
    const can_ch_cfg_t * p_top_cfg;

    volatile can_ch_top_sfr_t * ptr_top_sfr;

    /* ==== CAN RAM initialization ==== */
    if ((RSCAN0GSTS & CAN_RAM_INIT_BIT_ON) != 0U)
    {
        return CAN_RTN_RAM_INIT;
    }

    /* ==== global mode switch (stop->reset) ==== */
    if ((RSCAN0GSTS & CAN_GLB_STP_STS_BIT_ON) != 0U)
    {
        /* exit global stop mode */
        RSCAN0GCTR &= (uint32_t)~(CAN_GLB_STP_BIT_ON);    // 0xfffffffb
        if ((RSCAN0GSTS & CAN_GLB_STP_STS_BIT_ON) != 0U)
        {
            return CAN_RTN_MODE_WAIT;
        }
    }

    /* ==== channel mode switch ==== */
    ptr_top_sfr = (volatile can_ch_top_sfr_t *)&RSCAN0CmCFG(0);
    for (ch_idx = 0; ch_idx < CANDEV_CH_NUM; ch_idx++)
    {
        if (g_ch_use_table[ch_idx] != CAN_NOUSE)
        {
            /* --- switch from channel stop mode ---- */
            if ((ptr_top_sfr->CmSTS & CAN_STP_STS_BIT_ON) != 0U)
            {
                /* exit channel stop mode */
                ptr_top_sfr->CmCTR &= (uint32_t)~CAN_STP_BIT_ON;   // 0xfffffffbu
                if ((ptr_top_sfr->CmSTS & CAN_STP_STS_BIT_ON) != 0U)
                {
                    return CAN_RTN_MODE_WAIT;
                }
            }
        }
        ptr_top_sfr++;
    }

    /* configuration table */
    p_top_cfg = &g_can_ch_cfg[0];

    /* ==== global function setting ==== */
    RSCAN0GCFG = CANCFG_REG_GLB_CONFIG;

    /* ==== communication speed setting ==== */
    ptr_top_sfr = (volatile can_ch_top_sfr_t *)&RSCAN0CmCFG(0);
    p_cfg = p_top_cfg;
    for (ch_idx = 0; ch_idx < CANDEV_CH_NUM; ch_idx++)
    {
        if (g_ch_use_table[ch_idx] != CAN_NOUSE)
        {
            ptr_top_sfr->CmCFG = p_cfg->br_cfg;
            p_cfg++;
        }
        ptr_top_sfr++;
    }

    /* ==== Rx rule setting ==== */
#if CANCFG_RX_RULE_NUM > 0
    {
        volatile uint32_t * ptr_reg;

        uint16_t rxrule_idx;

        /* ---- Set Rx rule number per channel ---- */
        RSCAN0GAFLCFG0(0) = CANCFG_REG_RULENUM0;
#if CANDEV_CH_NUM > 4
        RSCAN0GAFLCFG0(1) = CANCFG_REG_RULENUM1;
#endif

        /* ---- Rx rule write enable. ---- */
        RSCAN0GAFLECTR = CAN_RX_RULE_WRT_EN_BIT_ON;

        /* ---- Copy Rx rule one by one ---- */
        ptr_reg = &RSCAN0GAFLIDj(0);
        for (rxrule_idx = 0U; rxrule_idx < CANCFG_RX_RULE_NUM; rxrule_idx++)
        {
            /* Update target Rx rule page if necessary */
            if ((rxrule_idx & CAN_PAGE_RX_RULE_IDX_MASK) == 0U)
            {
                RSCAN0GAFLECTR = CAN_RX_RULE_WRT_EN_BIT_ON |
                                 (rxrule_idx >> CAN_RX_RULE_PAGE_IDX_BIT_POS);
                ptr_reg = &RSCAN0GAFLIDj(0);
            }

            /* Set a single Rx rule */
            *(ptr_reg++) = g_rxrule_table[rxrule_idx][0];
            *(ptr_reg++) = g_rxrule_table[rxrule_idx][1];
            *(ptr_reg++) = g_rxrule_table[rxrule_idx][2];
            *(ptr_reg++) = g_rxrule_table[rxrule_idx][3];
        }

        /* ---- Rx rule write disable ---- */
        RSCAN0GAFLECTR = 0x0UL;
    }
#endif /* CANCFG_RX_RULE_NUM > 0 */

    /* ==== buffer setting ==== */
    /* ---- Set Rx buffer number ---- */
    RSCAN0RMNB = (0xFFUL & CANCFG_RBNUM);

    /* ---- Set Rx FIFO buffer ---- */
#if CANCFG_USE_RXFIFO_0 == CAN_USE
    RSCAN0RFCCx(0) = CANCFG_REG_RXFIFO_0;
#endif
#if CANCFG_USE_RXFIFO_1 == CAN_USE
    RSCAN0RFCCx(1) = CANCFG_REG_RXFIFO_1;
#endif
#if CANCFG_USE_RXFIFO_2 == CAN_USE
    RSCAN0RFCCx(2) = CANCFG_REG_RXFIFO_2;
#endif
#if CANCFG_USE_RXFIFO_3 == CAN_USE
    RSCAN0RFCCx(3) = CANCFG_REG_RXFIFO_3;
#endif
#if CANCFG_USE_RXFIFO_4 == CAN_USE
    RSCAN0RFCCx(4) = CANCFG_REG_RXFIFO_4;
#endif
#if CANCFG_USE_RXFIFO_5 == CAN_USE
    RSCAN0RFCCx(5) = CANCFG_REG_RXFIFO_5;
#endif
#if CANCFG_USE_RXFIFO_6 == CAN_USE
    RSCAN0RFCCx(6) = CANCFG_REG_RXFIFO_6;
#endif
#if CANCFG_USE_RXFIFO_7 == CAN_USE
    RSCAN0RFCCx(7) = CANCFG_REG_RXFIFO_7;
#endif

    {
        volatile uint32_t * p_CFCCk;
        volatile uint16_t * p_TMIEC;
        volatile uint32_t * p_TXQCCm;

        p_cfg    = p_top_cfg;
        p_CFCCk  = &RSCAN0CFCCk(0, 0);
        p_TMIEC  = &RSCAN0TMIEC(0);
        p_TXQCCm = &RSCAN0TXQCCm(0);
        for (ch_idx = 0U; ch_idx < CANDEV_CH_NUM; ch_idx++)
        {
            if (g_ch_use_table[ch_idx] != CAN_NOUSE)
            {
                /* ---- Tx/Rx FIFO buffer ---- */
                *(p_CFCCk    ) = p_cfg->tr0_cfg;
                *(p_CFCCk + 1) = p_cfg->tr1_cfg;
                *(p_CFCCk + 2) = p_cfg->tr2_cfg;

                /* ---- Tx buffer transmission complete interrupt ---- */
                *(p_TMIEC) = p_cfg->tb_int_cfg;

                /* ---- Tx queue ---- */
                *(p_TXQCCm) = p_cfg->tq_cfg;

                p_cfg++;
            }
            p_CFCCk += 3;
            p_TMIEC++;
            p_TXQCCm++;
        }
    }

    /* ==== global error interrupt setting ==== */
    RSCAN0GCTR = (RSCAN0GCTR & (CAN_GLB_STP_BIT_ON | CAN_GLB_MODE_BITS_ON))
        | CANCFG_REG_GLB_IE;
   /* Set THLEIE disabled, MEIE(FIFO Message Lost Interrupt disabled) */
   //RSCAN0GCTR &= 0xfffff8ffu;    


   /* Set THLEIE disabled, MEIE(FIFO Message Lost Interrupt disabled) */
   //RSCAN0GCTR &= 0xfffff8ffu;	 
   

    /* ==== channel function setting ==== */
    ptr_top_sfr = (volatile can_ch_top_sfr_t *)&RSCAN0CmCFG(0);
    p_cfg = p_top_cfg;
    for (ch_idx = 0; ch_idx < CANDEV_CH_NUM; ch_idx++)
    {
        if (g_ch_use_table[ch_idx] != CAN_NOUSE)
        {
            ptr_top_sfr->CmCTR = (ptr_top_sfr->CmCTR &
                                  (CAN_GLB_STP_STS_BIT_ON | CAN_MODE_BITS_ON))
                                 + p_cfg->ch_func;
            p_cfg++;
        }
        ptr_top_sfr++;
    }

    return CAN_RTN_OK;
}

/****************************************************************************** 
* Function Name: R_CAN_GlobalStart
* Description  : Start global operation
* Arguments    : none 
* Return Value : CAN_RTN_OK -
*                    normal completion
*                CAN_RTN_MODE_WAIT -
*                    wait to change global mode
******************************************************************************/
Can_RtnType R_CAN_GlobalStart(void)
{
    const uint8_t * p_use_value;

    /* ==== switch to global operation mode from global reset mode ==== */
    if ((RSCAN0GSTS & CAN_GLB_RST_STS_BIT_ON) != 0U)
    {
        RSCAN0GCTR = (RSCAN0GCTR & (uint32_t)~CAN_GLB_MODE_BITS_ON) |
                      CAN_GLB_OPERATION_MODE;
        if ((RSCAN0GSTS & CAN_GLB_RST_STS_BIT_ON) != 0U)
        {
            return CAN_RTN_MODE_WAIT;
        }
    }

    /* ==== Global error ==== */
    RSCAN0GERFL = 0x0UL;

    /* ==== enable reception FIFO ==== */
    {
        volatile uint32_t * p_RFCCx;
        uint8_t  rxfifo_idx;

        p_RFCCx = &RSCAN0RFCCx(0);
        p_use_value = &g_rxfifo_use_table[0];
        for (rxfifo_idx = 0; rxfifo_idx < CAN_MAX_RXFIFO_NUM; rxfifo_idx++)
        {
            if (*(p_use_value) != CAN_NOUSE)
            {
                *(p_RFCCx) |= CAN_RFIFO_EN_BIT_ON;
            }
            p_RFCCx++;
            p_use_value++;
        }
    }

    /* ==== Tx/Rx FIFO setting ==== */
    {
        volatile uint32_t * p_CFCCk;
        uint8_t ch_idx;
        uint8_t trfifo_idx;

        p_CFCCk = &RSCAN0CFCCk(0, 0);
        p_use_value = &g_trfifo_use_table[0][0];
        for (ch_idx = 0U; ch_idx < CANDEV_CH_NUM; ch_idx++)
        {
            if (g_ch_use_table[ch_idx] != CAN_NOUSE)
            {
                for (trfifo_idx = 0; trfifo_idx < CAN_MAX_TRFIFO_NUM;
                                         trfifo_idx++)
                {
                    /* ---- enable Tx/Rx FIFO (Rx mode) ---- */
                    if (*(p_use_value) == CAN_USE_RX_MODE)
                    {
                        *(p_CFCCk) |= CAN_TRFIFO_EN_BIT_ON;
                    }
                    p_use_value++;
                    p_CFCCk++;
                }
            }
            else
            {
                p_CFCCk += CAN_MAX_TRFIFO_NUM;
            }
        }
    }

    return CAN_RTN_OK;
}

/****************************************************************************** 
* Function Name: R_CAN_ChStart 
* Description  : Start channel operation
* Arguments    : ch_idx - 
*                    channel index
* Return Value : CAN_RTN_OK -
*                    normal completion
*                CAN_RTN_MODE_WAIT -
*                    wait to change channel mode
*                CAN_RTN_ARG_ERROR -
*                    invalid argument specification
******************************************************************************/
Can_RtnType R_CAN_ChStart(can_ch_t ch_idx)
{
    uint8_t use_ch_idx;

#if defined(__CHECK__)
    /* ----  Check can channel index ---- */
    if ((ch_idx >= CANDEV_CH_NUM) ||
        (g_ch_use_table[ch_idx] == CAN_NOUSE))
    {
        return CAN_RTN_ARG_ERROR;
    }
#endif

    /* ---- switch to channel operation mode ---- */
    {
        volatile can_ch_top_sfr_t * ptr;

        ptr = (volatile can_ch_top_sfr_t *)&RSCAN0CmCFG(ch_idx);
        if ((ptr->CmSTS & CAN_RST_STS_BIT_ON) != 0U)
        {
            ptr->CmCTR = (ptr->CmCTR & (uint32_t)~CAN_MODE_BITS_ON) |
                                         CAN_MODE_CH_COMM_MODE;
            if ((ptr->CmSTS & CAN_RST_STS_BIT_ON) != 0U)
            {
                return CAN_RTN_MODE_WAIT;
            }
        }
    }

    use_ch_idx = (uint8_t)(g_ch_use_table[ch_idx] & CAN_USE_CH_MASK);

    /* ---- enable Tx/Rx FIFO (Tx mode or gateway mode) ---- */
    {
        volatile uint32_t * p_CFCCk;
        uint32_t trfifo_idx;
        const uint8_t * p_use_value;

        p_CFCCk = &RSCAN0CFCCk(ch_idx, 0);
        p_use_value = &g_trfifo_use_table[use_ch_idx][0];
        for (trfifo_idx = 0; trfifo_idx < CAN_MAX_TRFIFO_NUM; trfifo_idx++)
        {
            if ((*(p_use_value) == CAN_USE_TX_MODE) || 
                (*(p_use_value) == CAN_USE_GW_MODE))
            {
                *(p_CFCCk) |= CAN_TRFIFO_EN_BIT_ON;
            }
            p_use_value++;
            p_CFCCk++;
        }
    }

    /* ---- enable Tx queue ---- */
    if (g_txqueue_use_table[use_ch_idx] != CAN_NOUSE)
    {
        RSCAN0TXQCCm(ch_idx) |= CAN_TXQUEUE_EN_BIT_ON;
    }

    return CAN_RTN_OK;
}


/****************************************************************************** 
* Function Name: R_CAN_TrmByTxBuf
* Description  : Transmit a frame by Tx buffer
* Arguments    : ch_idx -
*                    channel index
*                txbuf_idx -
*                    Tx buffer index
*                pFrame -
*                    pointer to frame to be transmitted
* Return Value : CAN_RTN_OK -
*                    normal completion
*                CAN_RTN_STS_ERROR -
*                    failure to clear Tx buffer status
*                CAN_RTN_ARG_ERROR -
*                    invalid argument specification
******************************************************************************/
Can_RtnType R_CAN_TrmByTxBuf(can_ch_t ch_idx, can_txbuf_t txbuf_idx,
                             const can_frame_t * pFrame)
{
#if defined(__CHECK__)
    /* ----  Check can channel index ---- */
    if ((ch_idx >= CANDEV_CH_NUM) ||
        (g_ch_use_table[ch_idx] == CAN_NOUSE))
    {
        return CAN_RTN_ARG_ERROR;
    }

    /* ----  Check Tx buffer index ---- */
    if (txbuf_idx >= CAN_MAX_TXBUF_NUM)
    {
        return CAN_RTN_ARG_ERROR;
    }
#endif

    /* ---- Clear Tx buffer status ---- */
    {
        volatile uint8_t  * p_TMSTSp;

        p_TMSTSp = &(RSCAN0TMSTSp(ch_idx, txbuf_idx));
        *p_TMSTSp = 0x0U;
	
	//   test_can_val = *p_TMSTSp;
        if (*p_TMSTSp != 0x0U)
        {
            return CAN_RTN_STS_ERROR;
        }
    }

    /* ---- Store message to tx buffer ---- */
    {
        volatile uint32_t * p_CiTBp;
        uint32_t *p_data;

        p_CiTBp = &(RSCAN0TMIDp(ch_idx, txbuf_idx));
        p_data = (uint32_t *)pFrame;
	
        *(p_CiTBp++) = *(p_data++); // *(p_data++);
        *(p_CiTBp++) = *(p_data++);
        *(p_CiTBp++) = *(p_data++);
        *(p_CiTBp  ) = *(p_data  );

    }

    /* ---- Set transmission request ---- */
    RSCAN0TMCp(ch_idx, txbuf_idx) = CAN_TXBUF_TRM_BIT_ON;

    return CAN_RTN_OK;
}

/****************************************************************************** 
* Function Name: R_CAN_AbortTrm
* Description  : Abort a CAN transmission
* Arguments    : ch_idx -
*                    channel index
*                txbuf_idx -
*                    Tx buffer index
* Return Value : CAN_RTN_OK -
*                    normal completion
*                CAN_RTN_ARG_ERROR -
*                    invalid argument specification
******************************************************************************/
Can_RtnType R_CAN_AbortTrm(can_ch_t ch_idx, can_txbuf_t txbuf_idx)
{
#if defined(__CHECK__)
    /* ----  Check can channel index ---- */
    if ((ch_idx >= CANDEV_CH_NUM) ||
        (g_ch_use_table[ch_idx] == CAN_NOUSE))
    {
        return CAN_RTN_ARG_ERROR;
    }

    /* ----  Check Tx buffer index ---- */
    if (txbuf_idx >= CAN_MAX_TXBUF_NUM)
    {
        return CAN_RTN_ARG_ERROR;
    }
#endif

    /* ---- Set transmission abort request ---- */
    RSCAN0TMCp(ch_idx, txbuf_idx) |= CAN_TXBUF_ABT_BIT_ON;

    return CAN_RTN_OK;
}

/****************************************************************************** 
* Function Name: R_CAN_CheckTxBufResult
* Description  : Read the result of transmission from Tx buffer
* Arguments    : ch_idx -
*                    channel index
*                txbuf_idx -
*                    Tx buffer index
* Return Value : CAN_RTN_TRANSMITTING -
*                    Transmission is in progress
*                    or no transmit request is present.
*                CAN_RTN_TX_ABORT_OVER -
*                    Transmit abort has been completed.
*                CAN_RTN_TX_END -
*                    Transmission has been completed
*                    (without transmit abortrequest).
*                CAN_RTN_TX_END_WITH_ABORT_REQ -
*                    Transmission has been completed
*                    (with transmit abort request).
*                CAN_RTN_ARG_ERROR -
*                    invalid argument specification
******************************************************************************/
Can_RtnType R_CAN_CheckTxBufResult(can_ch_t ch_idx, can_txbuf_t txbuf_idx)
{
    Can_RtnType rtn_value;

    volatile uint8_t * p_TMSTSp;

#if defined(__CHECK__)
    /* ----  Check can channel index ---- */
    if ((ch_idx >= CANDEV_CH_NUM) ||
        (g_ch_use_table[ch_idx] == CAN_NOUSE))
    {
        return CAN_RTN_ARG_ERROR;
    }

    /* ----  Check Tx buffer index ---- */
    if (txbuf_idx >= CAN_MAX_TXBUF_NUM)
    {
        return CAN_RTN_ARG_ERROR;
    }
#endif

    p_TMSTSp = &(RSCAN0TMSTSp(ch_idx, txbuf_idx));

    rtn_value = (Can_RtnType)((*p_TMSTSp & CAN_TXBUF_RSLT_BITS_ON)
                              >> CAN_TXBUF_RSLT_BITS_POS);

    /* ---- Tx transmission completed/abort? ---- */
    if (rtn_value != CAN_RTN_TRANSMITTING)
    {
        /* Clear Tx buffer status */
        *p_TMSTSp = 0x0U;
    }

    return rtn_value;
}

/****************************************************************************** 
* Function Name: R_CAN_TrmByTRFIFO
* Description  : Transmit a frame by common (Tx/Rx) FIFO
* Arguments    : ch_idx -
*                    channel index
*                trfifo_idx -
*                    Tx/Rx FIFO index
*                pFrame -
*                    pointer to frame to be transmitted
* Return Value : CAN_RTN_OK -
*                    Frame is successfully pushed into FIFO.
*                CAN_RTN_FIFO_FULL -
*                    Specified FIFO is full.
*                CAN_RTN_ARG_ERROR -
*                    invalid argument specification
******************************************************************************/
Can_RtnType R_CAN_TrmByTRFIFO(can_ch_t ch_idx, can_trfifo_t trfifo_idx,
                              const can_frame_t * pFrame)
{
#if defined(__CHECK__)
    /* ----  Check can channel index ---- */
    if ((ch_idx >= CANDEV_CH_NUM) ||
        (g_ch_use_table[ch_idx] == CAN_NOUSE))
    {
        return CAN_RTN_ARG_ERROR;
    }

    /* ----  Check Tx/Rx FIFO index ---- */
    {
        uint8_t  use_ch_idx;
        use_ch_idx = (uint8_t)(g_ch_use_table[ch_idx] & CAN_USE_CH_MASK);
        if ((trfifo_idx >= CAN_MAX_TRFIFO_NUM) ||
            (g_trfifo_use_table[use_ch_idx][trfifo_idx] != CAN_USE_TX_MODE))
        {
            return CAN_RTN_ARG_ERROR;
        }
    }
#endif

    /* ---- Return if Tx/Rx FIFO is full ---- */
    if ((RSCAN0CFSTSk(ch_idx, trfifo_idx) & CAN_TRFIFO_FULL_BIT_ON) != 0)
    {
        return CAN_RTN_FIFO_FULL;
    }

    /* ---- Send message into Tx/Rx FIFO if it is not full ---- */
    {
        volatile uint32_t *p_CiTRFAk;
        uint32_t *p_data;

        p_CiTRFAk = &(RSCAN0CFIDk(ch_idx, trfifo_idx));
        p_data = (uint32_t *)pFrame;
        *(p_CiTRFAk++) = *(p_data++);
        *(p_CiTRFAk++) = *(p_data++);
        *(p_CiTRFAk++) = *(p_data++);
        *(p_CiTRFAk  ) = *(p_data  );
    }

    /* ---- Increment Tx/Rx FIFO buffer pointer ---- */
    RSCAN0CFPCTRk(ch_idx, trfifo_idx) = CAN_FIFO_PTR_INC;

    return CAN_RTN_OK;
}

/****************************************************************************** 
* Function Name: R_CAN_TrmByTxQueue
* Description  : Transmit a frame by Tx queue
* Arguments    : ch_idx -
*                    channel index
*                pFrame -
*                    pointer to frame to be transmitted
* Return Value : CAN_RTN_OK -
*                    Frame is successfully pushed into queue.
*                CAN_RTN_FIFO_FULL -
*                    Specified queue is full.
*                CAN_RTN_ARG_ERROR -
*                    invalid argument specification
******************************************************************************/
Can_RtnType R_CAN_TrmByTxQueue(can_ch_t ch_idx, const can_frame_t * pFrame)
{
#if defined(__CHECK__)
    /* ----  Check can channel index ---- */
    if ((ch_idx >= CANDEV_CH_NUM) ||
        (g_ch_use_table[ch_idx] == CAN_NOUSE))
    {
        return CAN_RTN_ARG_ERROR;
    }

    /* ----  Check Tx queue index ---- */
    {
        uint8_t  use_ch_idx;
        use_ch_idx = (uint8_t)(g_ch_use_table[ch_idx] & CAN_USE_CH_MASK);
        if (g_txqueue_use_table[use_ch_idx] == CAN_NOUSE)
        {
            return CAN_RTN_ARG_ERROR;
        }
    }

#endif

    /* ---- Return if Tx queue is full ---- */
    if ((RSCAN0TXQSTSn(ch_idx) & CAN_TXQUEUE_FULL_BIT_ON) != 0)
    {
        return CAN_RTN_FIFO_FULL;
    }

    /* ---- Send message into Tx queue if it is not full ---- */
    {
        volatile uint32_t *p_CiTB15;
        uint32_t *p_data;

        p_CiTB15 = &RSCAN0TMID15n(ch_idx);
        p_data = (uint32_t *)pFrame;
        *(p_CiTB15++) = *(p_data++);
        *(p_CiTB15++) = *(p_data++);
        *(p_CiTB15++) = *(p_data++);
        *(p_CiTB15  ) = *(p_data  );
    }

    /* ---- Increment transmission queue pointer ---- */
    RSCAN0TXQPCTRn(ch_idx) = CAN_FIFO_PTR_INC;

    return CAN_RTN_OK;
}

/****************************************************************************** 
* Function Name: R_CAN_ReadRxBuffer
* Description  : Read message from Rx buffer
* Arguments    : p_rxbuf_idx -
*                    pointer to Rx buffer that receives frame
*                pFrame -
*                    pointer to stored frame position
* Return Value : CAN_RTN_OK -
*                    A frame is successfully read out.
*                CAN_RTN_BUFFER_EMPTY -
*                    No frame is read out.
*                CAN_RTN_STS_ERROR -
*                    failure to clear Rx complete flag
*                CAN_RTN_OVERWRITE -
*                    A frame is overwritten.
******************************************************************************/
Can_RtnType R_CAN_ReadRxBuffer(uint8_t * p_rxbuf_idx, can_frame_t * pFrame)
{
    uint8_t  buf_idx;
    uint8_t  rb_idx;
    uint8_t  ch_idx;
    uint16_t temp_rbrcf;
    uint16_t pattern;

    volatile uint16_t * p_RMND;

    /* ---- Judge if new messages are available ---- */
    rb_idx = 0xFF;
    p_RMND = &RSCAN0RMND(0);
    for (ch_idx = 0U; ch_idx < CANDEV_CH_NUM; ch_idx++)
    {
        temp_rbrcf = *(p_RMND);
        if (temp_rbrcf != 0U)
        {
            rb_idx = ch_idx;
            break;
        }
        p_RMND++;
    }

    if (temp_rbrcf == 0)
    {
        return CAN_RTN_BUFFER_EMPTY;
    }

    /* ---- Get Rx buffer that has new message ---- */
    if (temp_rbrcf != 0)
    {
        pattern = 1;
        for (buf_idx = 0U; buf_idx < 16U; ++buf_idx)
        {
            if ((temp_rbrcf & pattern) != 0)
            {
                *p_rxbuf_idx = buf_idx + (rb_idx * 16);
                break;
            }
            pattern <<= 1;
        }
    }

    /* ---- Clear Rx complete flag of corresponding Rx buffer ---- */
    *p_RMND = (uint16_t)~pattern;
    if ((*p_RMND & pattern) != 0)
    {
        return CAN_RTN_STS_ERROR;
    }

    /* ---- Read out message from Rx buffer ---- */
    {
        volatile uint32_t *p_CRBn;
        uint32_t *p_data;

        p_CRBn = &(RSCAN0RMIDp((*p_rxbuf_idx)));
        p_data = (uint32_t *)pFrame;
        *(p_data++) = *(p_CRBn++);
        *(p_data++) = *(p_CRBn++);
        *(p_data++) = *(p_CRBn++);
        *(p_data  ) = *(p_CRBn  );
    }

    /* ---- Judge if current message is overwritten ---- */
    if ((*p_RMND & pattern) != 0)
    {
        return CAN_RTN_OVERWRITE;
    }

    return CAN_RTN_OK;
}

/****************************************************************************** 
* Function Name: R_CAN_ReadRxFIFO
* Description  : Read message from Rx FIFO
* Arguments    : rxfifo_idx -
*                    Rx FIFO index
*                pFrame -
*                    pointer to stored frame position
* Return Value : CAN_RTN_OK -
*                    A frame is successfully read out.
*                CAN_RTN_OK_WITH_LOST -
*                    A frame is successfully read out (with message lost).
*                CAN_RTN_BUFFER_EMPTY -
*                    No frame is read out.
*                CAN_RTN_ARG_ERROR -
*                    invalid argument specification
******************************************************************************/
Can_RtnType R_CAN_ReadRxFIFO(can_rxfifo_t rxfifo_idx, can_frame_t * pFrame)
{
    uint32_t    temp_status;
    Can_RtnType rtn_value;

    volatile uint32_t * ptr_reg;

#if defined(__CHECK__)
    /* ----  Check Rx FIFO index ---- */
    if ((rxfifo_idx >= CAN_MAX_RXFIFO_NUM) ||
        (g_rxfifo_use_table[rxfifo_idx] == CAN_NOUSE))
    {
        return CAN_RTN_ARG_ERROR;
    }
#endif

    /* ----  Check if any unread message is available in Rx FIFO ---- */
    temp_status = RSCAN0RFSTSx(rxfifo_idx);
    if ((temp_status & CAN_RFIFO_EMPTY_BIT_ON) != 0)
    {
        return CAN_RTN_BUFFER_EMPTY;
    }

    /* ----  Set return value ---- */
    rtn_value = CAN_RTN_OK;

    /* ---- Check if Rx FIFO has message lost ---- */
    if ((temp_status & CAN_RFIFO_MSGLST_BIT_ON) != 0)
    {
        /* ---- Clear message lost flag ---- */
        RSCAN0RFSTSx(rxfifo_idx) = CAN_CLR_WITHOUT_RX_INT;

        /* ----  Set return value ---- */
        rtn_value = CAN_RTN_OK_WITH_LOST;
    }

    /* ---- Read out message from Rx FIFO ---- */
    {
        uint32_t *p_data;

        ptr_reg = &(RSCAN0RFIDx(rxfifo_idx));
        p_data = (uint32_t *)pFrame;
        *(p_data++) = *(ptr_reg++);
        *(p_data++) = *(ptr_reg++);
        *(p_data++) = *(ptr_reg++);
        *(p_data  ) = *(ptr_reg  );
    }

    /* ---- Increment Rx FIFO buffer pointer ---- */
    RSCAN0RFPCTRx(rxfifo_idx) = CAN_FIFO_PTR_INC;

    return rtn_value;
}

/****************************************************************************** 
* Function Name: R_CAN_ReadTRFIFO
* Description  : Read message from common (Tx/Rx) FIFO
* Arguments    : ch_idx -
*                    channel index
*                trfifo_idx -
*                    common (Tx/Rx) FIFO index
*                pFrame -
*                    pointer to stored frame position
* Return Value : CAN_RTN_OK -
*                    A frame is successfully read out.
*                CAN_RTN_OK_WITH_LOST -
*                    A frame is successfully read out (with message lost).
*                CAN_RTN_BUFFER_EMPTY -
*                    No frame is read out.
*                CAN_RTN_ARG_ERROR -
*                    invalid argument specification
******************************************************************************/
Can_RtnType R_CAN_ReadTRFIFO(can_ch_t ch_idx, can_trfifo_t trfifo_idx,
                             can_frame_t * pFrame)
{
    uint32_t    temp_ctrfsr;
    Can_RtnType rtn_value;

    volatile uint32_t * ptr_reg;

#if defined(__CHECK__)
    /* ----  Check can channel index ---- */
    if ((ch_idx >= CANDEV_CH_NUM) ||
        (g_ch_use_table[ch_idx] == CAN_NOUSE))
    {
        return CAN_RTN_ARG_ERROR;
    }

    /* ----  Check common (Tx/Rx) FIFO index ---- */
    {
        uint8_t  use_ch_idx;
        use_ch_idx = (uint8_t)(g_ch_use_table[ch_idx] & CAN_USE_CH_MASK);
        if ((trfifo_idx >= CAN_MAX_TRFIFO_NUM) ||
            (g_trfifo_use_table[use_ch_idx][trfifo_idx] != CAN_USE_RX_MODE))
        {
            return CAN_RTN_ARG_ERROR;
        }
    }
#endif

    /* ----  Check if any unread message is available in common (Tx/Rx) FIFO ---- */
    temp_ctrfsr = RSCAN0CFSTSk(ch_idx, trfifo_idx);
    if ((temp_ctrfsr & CAN_TRFIFO_EMPTY_BIT_ON) != 0)
    {
        return CAN_RTN_BUFFER_EMPTY;
    }

    /* ----  Set return value ---- */
    rtn_value = CAN_RTN_OK;

    /* ---- Check if common (Tx/Rx) FIFO has message lost ---- */
    if ((temp_ctrfsr & CAN_TRFIFO_MSGLST_BIT_ON) != 0)
    {
        /* ---- Clear message lost flag ---- */
        RSCAN0CFSTSk(ch_idx, trfifo_idx) = CAN_CLR_WITHOUT_TX_RX_INT;

        /* ----  Set return value ---- */
        rtn_value = CAN_RTN_OK_WITH_LOST;
    }

    /* ---- Read out message from common (Tx/Rx) FIFO ---- */
    {
        uint32_t *p_data;

        ptr_reg = &(RSCAN0CFIDk(ch_idx, trfifo_idx));
        p_data = (uint32_t *)pFrame;
        *(p_data++) = *(ptr_reg++);
        *(p_data++) = *(ptr_reg++);
        *(p_data++) = *(ptr_reg++);
        *(p_data  ) = *(ptr_reg  );
    }

    /* ---- Increment common (Tx/Rx) FIFO buffer pointer ---- */
    RSCAN0CFPCTRk(ch_idx, trfifo_idx) = CAN_FIFO_PTR_INC;

    return rtn_value;
}

/****************************************************************************** 
* Function Name: R_CAN_ReadChStatus
* Description  : Read channel status
* Arguments    : ch_idx -
*                    channel index
* Return Value : channel status (<= 0xFF) -
*                    normal completion
*                CAN_RTN_ARG_ERROR -
*                    invalid argument specification
******************************************************************************/
Can_RtnType R_CAN_ReadChStatus(can_ch_t ch_idx)
{
    volatile can_ch_top_sfr_t * ptr_top_sfr;

#if defined(__CHECK__)
    /* ----  Check can channel index ---- */
    if ((ch_idx >= CANDEV_CH_NUM) ||
        (g_ch_use_table[ch_idx] == CAN_NOUSE))
    {
        return CAN_RTN_ARG_ERROR;
    }
#endif

    ptr_top_sfr = (volatile can_ch_top_sfr_t *)&RSCAN0CmCFG(ch_idx);

    return (Can_RtnType)(ptr_top_sfr->CmSTS & CAN_8_BITS_MASK);
}
