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
* (c) 2014 Renesas Electronics Corporation All rights reserved.
*******************************************************************************/


/******************************************************************************
* File Name     : r_can.c
* Version       : 1.0
* Device(s)     : R7F701035xAFP RH850/F1L
* Tool-Chain    : CubeSuite+(V2.01.00)
* Description   : This file is a sample of RS-CAN.
* Operation     : -
*******************************************************************************
*******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 20.03.2014 1.00    First Release
******************************************************************************/

/******************************************************************************
Includes <System Includes> , gProject Includesh
******************************************************************************/
#include  "dr7f701587.dvf.h"
#include  "r_typedefs.h"
#include  "r_intc.h"
#include  "r_rh850_can_sfr.h"
#include  "r_rh850_can_drv.h"
#include  "can_cfg.h"
#include "dtcApp.h"
/* Structure */

#define __ICON_HW01__
/* ---- CAN frame ----- */
typedef struct
{
	#if 0
    unsigned long ID :29;
    unsigned long THLEN :1;
    unsigned long RTR :1;
    unsigned long IDE :1;
    
    unsigned long TS :16;
    unsigned long LBL :12;
    unsigned long DLC :4;
    unsigned char DB[8];
    #else
    uint32_t RMID;
    uint32_t RMPTR;
    uint32_t RMDF0;
    uint32_t RMDF1;
    #endif
} Can_FrameType;


#define CAN_RX_RULE_TYPE               can_cre_type
#define CAN_RX_RULE_PAGE_IDX_BIT_POS        4U

/******************************************************************************
Imported global variables and functions (from other files)
******************************************************************************/
static uint8_t CanHwIsInit = 0;

/******************************************************************************
Macro definitions
******************************************************************************/
#define R_CAN_GRAMINIT_ON  (0x8UL)
#define R_CAN_GSLPSTS_ON   (0x4UL)
#define R_CAN_GRSTSTS_ON   (0x1UL)
#define R_CAN_CSLPSTS_ON   (0x4UL)
#define R_CAN_CHLTSTS_ON   (0x2UL)
#define R_CAN_CRSTSTS_ON   (0x1UL)
#define R_CAN_TMTRM_ON     (0x8U)
#define R_CAN_TMTR_ON      (0x1U)
#define R_CAN_AFLDAE_ON    (0x100UL)
#define R_CAN_GSLPR_MASK   (0x4UL)
#define R_CAN_GMDC_MASK    (0x3UL)
#define R_CAN_CSLPR_MASK   (0x4UL)
#define R_CAN_CHMDC_MASK   (0x3UL)


/* ---- bit value ---- */
#define CAN_SET                             1U
#define CAN_CLR                             0U

/* ---- bit mask ---- */
#define CAN_1_BIT_MASK                      1U
#define CAN_2_BIT_MASK                      3U
#define CAN_3_BIT_MASK                      7U
#define CAN_4_BIT_MASK                      0xfU
#define CAN_5_BIT_MASK                      0x1fU

/* ---- bit position ---- */
#define CAN_B0_BIT_POS                      0U
#define CAN_B1_BIT_POS                      1U
#define CAN_B2_BIT_POS                      2U
#define CAN_B3_BIT_POS                      3U
#define CAN_B4_BIT_POS                      4U
#define CAN_B5_BIT_POS                      5U
#define CAN_B6_BIT_POS                      6U
#define CAN_B7_BIT_POS                      7U
#define CAN_B8_BIT_POS                      8U
#define CAN_B9_BIT_POS                      9U
#define CAN_B10_BIT_POS                     10U
#define CAN_B11_BIT_POS                     11U
#define CAN_B12_BIT_POS                     12U
#define CAN_B13_BIT_POS                     13U
#define CAN_B14_BIT_POS                     14U
#define CAN_B15_BIT_POS                     15U

/*---- structure for Tx Frame information --------------------*/
/* ---- CAN function return ---- */
//typedef unsigned char Can_RtnType;

/* ---- function return value ---- */

#define CAN_RTN_ERR                         255U


#define CAN_CRBRCF0_RX_BUF_NUM              32U
#define CAN_CRBRCF1_RX_BUF_NUM              32U
#define CAN_CRBRCF2_RX_BUF_NUM              32U
#define CAN_PAGE_RX_RULE_IDX_MASK           0xfU
#define CAN_RX_RULE_PAGE_IDX_BIT_POS        4U
#define CAN_RAM_LW_SIZE                     (0x1C20U >> 2U)
#define CAN_RAM_PAGE_IDX_BIT_POS            6U
#define CAN_RAM_DATA_IDX_MASK               0x3fU

#define RX_RULE_NUM_MAX              (192U)       /* Max Rx Rule number */
#define RX_RULE_PAGE_NUM             (1U)         /* Rx Rule Table page number */

/* ---- TX buffer, TX status flag ---- */
#define CAN_TBTST_NOT_TRANSMITTING          0U
#define CAN_TBTST_TRANSMITTING              1U

/* ---- bit operations ---- */
#define GET_BIT(reg, pos)              (((reg) >> (pos)) & 1U)
#define SET_BIT(reg, pos)              ((reg) |= 1U << (pos))
#define CLR_BIT(reg, pos)              ((reg) &= ~(1UL << (pos)))

/* ---- CiTBCRj ---- */
#define CAN_TBTR_BIT_POS                    0U
#define CAN_TBAR_BIT_POS                    1U
#define CAN_TBOE_BIT_POS                    2U

/* transmission command */
#define CAN_TBCR_TRM                        (CAN_ENABLE << CAN_TBTR_BIT_POS)

#define kCanCrFifoEnable             0x00000001u
#define kCanCrRxFifoIntEnable        0x00000002u
#define kCanCrTxFifoIntEnable        0x00000004u
#define kCanCrRxFifoSet              0x00001000u /* interrupt every message */ 
#define kCanCrTxFifoSet              0x00011000u /* link to TB0; transmit mode; interrupt every message */
#define kCanSrFifoEmpty              0x00000001u
#define kCanSrFifoFull               0x00000002u
#define kCanSrFifoOverrun            0x00000004u
#define kCanSrRxFifoIntFlag          0x00000008u
#define kCanSrTxFifoIntFlag          0x00000010u
#define kCanSrFifoMsgCount           0x0000FF00u
#define kCanPcrFifoPC                0x000000FFu

#if defined(C_ENABLE_IMMEDIATE_BUSOFF_RECOVERY)
# define kCanCrHaltAtBusoff          0x00200000u /* halt mode at bus-off entry (BOM=01) */
#else
# define kCanCrHaltAtBusoff          0x00400000u /* default: halt mode at bus-off end (BOM=10) */
#endif
#define kCanModeMask                 0xFFFFFFF8u /* incl. STP */
#define kCanOperationMode            0x00000000u /* global and channel */
#define kCanOperationModeCheck       0x00000080u /* channel only */
#define kCanResetMode                0x00000001u /* global and channel */
#define kCanTestMode                 0x00000002u /* global only */
#define kCanHaltMode                 0x00000002u /* channel only */
#define kCanStopMode                 0x00000005u /* global and channel */

#define kCanIntMaskBusoff            0x00000800u /* BO entry */
#define kCanEfMaskBusoff             0x0008u     /* BO entry */
#define kCanEfMaskBusoffClear        0x7FF7u

#define kCanRxFifoMask               0x000000FFu
#define kCanSrFifoOverrun            0x00000004u
#define BUSOFF_STATUS_MASK           0x10
#define kCanModeBits                 0x00000007u

/* checks the global mode (also checks if RAMIST==0) */
#define CanLL_GlobalModeCheck(mode) (RSCAN0.GSTS.UINT32 == (mode))
/* requests a global mode */
#define CanLL_GlobalModeReq(mode)   (RSCAN0.GCTR.UINT32 = ((RSCAN0.GCTR.UINT32 & kCanModeMask) | (mode)))
/* requests a on a physical channel */
#define CanLL_ModeReq_Phys(mode)  (RSCAN0.C1CTR.UINT32 = ((RSCAN0.C1CTR.UINT32 & kCanModeMask) | (mode)))
/* checks the mode on a physical channel */
#define CanLL_ModeCheck_Phys(mode) ((RSCAN0.C1STS.UINT32 & kCanModeBits) == ((mode) & kCanModeBits))

#define CanLL_HwIsBusOff()           ((RSCAN0.C1STS.UINT32 & BUSOFF_STATUS_MASK)!=0)
#define CanLL_CanTimerWait(condition)    while (condition) { ; }


#define CAN_INIT                      (1)
//#define RECEIVE_BUF
/******************************************************************************
Exported global variables and functions (to be accessed by other files)
******************************************************************************/

bool    R_CAN_Send_TxBuf0(uint32_t can_id, uint8_t dlc, uint8_t msg[8]);
bool    R_CAN_Receive_RxBuf0(uint32_t * p_can_id, uint8_t * p_dlc, uint8_t msg[8]);


/******************************************************************************
Private global variables and functions
******************************************************************************/
#define CanRxFifoDepth          7
#define kCanCrRxFifoSet        0x00001000u
#define kCanCrRxFifoIntEnable  0x00000002u
#define R_ICCAN1REC            &INTC2.ICRCAN1REC.UINT16
#define R_ICCAN1TRX            &INTC2.ICRCAN1TRX.UINT16
#define R_ICCAN1ERR            &INTC2.ICRCAN1ERR.UINT16
#define R_ICCANGREC0           &INTC1.ICRCANGRECC0.UINT16

static void Can_SetRxRule(uint8_t chn);

void R_CAN_Clock_Init(void)
{
	       /* Source Clock Setting for C_ISO_CAN
    CKSC_ICANS_CTL    - C_ISO_CAN Source Clock Selection Register
    b31:b 2                         - Reserved set to 0
    b 1:b 0             ICANSCSID   - Source Clock Setting for C_ISO_CAN  - mainosc=16M                */
    do
    {
        WPROTR.PROTCMD1       = 0x000000A5UL;
        CLKCTL.CKSC_ICANS_CTL = 0x00000001UL;
        CLKCTL.CKSC_ICANS_CTL = ~0x00000001UL;
        CLKCTL.CKSC_ICANS_CTL = 0x00000001UL;
    }
    while (WPROTR.PROTS1 != 0x0UL);

    
    while (CLKCTL.CKSC_ICANS_ACT != 0x3UL)
    {
        /* Waiting for C_ISO_CAN to set. */
    }

    /* Clock Divider Setting for C_ISO_CANOSC
    CKSC_ICANOSCD_CTL - C_ISO_CANOSC Divided Clock Selection Register
    b31:b 2                         - Reserved set to 0
    b 1:b 0             CANOSCDCSID - Clock Divider Setting for C_ISO_CANOSC - MainOSC X /1       */
    do
    {
        WPROTR.PROTCMD1          = 0x000000A5UL;
        CLKCTL.CKSC_ICANOSCD_CTL = 0x00000001UL;
        CLKCTL.CKSC_ICANOSCD_CTL = 0xFFFFFFFEUL;
        CLKCTL.CKSC_ICANOSCD_CTL = 0x00000001UL;
    }
    while (WPROTR.PROTS1 != 0x0UL);
    
    while (CLKCTL.CKSC_ICANOSCD_ACT != 0x1UL)
    {
        /* Waiting for C_ISO_CANOSC to set. */
    }

    /* RS-CAN port settings (Channel 1) */
    /* P10_6 (CAN1RX) 4 input*/
    PORT.PFCAE10 &= ~(1<<6);
    PORT.PFCE10  |=   1<<6;
    PORT.PFC10   |=   1<<6;
    PORT.PM10    |=   1<<6;
    PORT.PMC10   |=   1<<6;

    /* P10_7 (CAN1TX) 4 output*/
    PORT.PFCAE10 &= ~(1<<7);
    PORT.PFCE10  |=   1<<7;
    PORT.PFC10   |=   1<<7;    
    PORT.P10     |=   1<<7;
    PORT.PM10    &= ~(1<<7);
    PORT.PMC10   |=   1<<7;

#ifdef  __ICON_HW01__   
    PORT.APSR0   = 0x00060006UL;//stb en
    PORT.APMSR0  = 0x00060000UL;///pin out
#else
    PORT.APSR0   = 0x00200020UL;//stb
    PORT.APMSR0  = 0x00200000UL;///pin out

    PORT.PSR9   = 0x00010001UL;//en
    PORT.PMSR9  = 0x00010000UL;//pin out
#endif
}
/******************************************************************************
* Function Name : void R_CAN_Init( void )
* Description   : This function initializes RS-CAN.
* Argument      : none
* Return Value  : none
******************************************************************************/
Can_RtnType CAN_Init(void)
{
    uint32_t canTmpReg;
    if((CanHwIsInit&CAN_INIT) == CAN_INIT) 
    {
      /* wait for completion of busoff recovery */
      if (CanLL_HwIsBusOff())
      {
        CanLL_CanTimerWait(CanLL_HwIsBusOff()); 
      }
    
      /* switch to reset mode and check if it is reached */
      CanLL_ModeReq_Phys(kCanResetMode);  
      CanLL_CanTimerWait(!CanLL_ModeCheck_Phys(kCanResetMode));
    }
	   /* set busoff return behavior (and current mode bits) */
    canTmpReg = kCanCrHaltAtBusoff | kCanResetMode;
    /* enable busoff interrupt (also used if special busoff behaviour is configured) */
#if !defined(C_ENABLE_ERROR_POLLING)
    canTmpReg |= kCanIntMaskBusoff;
#endif
    RSCAN0.C1CTR.UINT32 |= canTmpReg;

    RSCAN0.RFCC1.UINT32 &= ( ~0x00000001u);
      /* delete fifo interrupt and overrun flags */
    RSCAN0.RFSTS1.UINT32 &= ( ~(0x00000008u | 0x00000004u));
    RSCAN0.RFCC1.UINT32 |= kCanCrRxFifoSet|(CanRxFifoDepth<<8);//
    RSCAN0.RFCC1.UINT32 |= 0x00000002u;/*enable recv fifo interrupt*/

	 /* Channel reset mode -> Channel communication mode (Channel 0)
    RSCAN0CmCTR   - Channel Control Register
    b31:b27                  - Reserved set to 0
    b26:b25         CTMS     - Communication Test Mode Select      - not change
    b24:            CTME     - Communication Test Mode Enable      - not change
    b23:            ERRD     - Error Display Mode Select           - not change
    b22:b21         BOM      - Bus Off Recovery Mode Select        - not change
    b20:b17                  - Reserved set to 0
    b16:            TAIE     - Transmit Abort Interrupt Enable     - not change
    b15:            ALIE     - Arbitration Lost Interrupt Enable   - not change
    b15:            BLIE     - Bus Lock Interrupt Enable           - not change
    b15:            OLIE     - Overload Frame Transmit
                               Interrupt Enable                    - not change
    b15:            BORIE    - Bus Off Recovery Interrupt Enable   - not change
    b15:            BOEIE    - Bus Off Entry Interrupt Enable      - not change
    b15:            EPIE     - Error Passive Interrupt Enable      - not change
    b15:            EWIE     - Error Warning Interrupt Enable      - not change
    b15:            BEIE     - Bus Error Interrupt Enable          - not change
    b 7:b 4                  - Reserved set to 0
    b 3:            RTBO     - Forcible Return from Bus-off        - not change
    b 2             CSLPR    - Channel Stop Mode                   - not change
    b 1:b 0         CHMDC    - Mode Select                         - Channel communication mode. Set to 00'b */
    RSCAN0.C1CTR.UINT32 &= ~R_CAN_CHMDC_MASK; /* CHMDC[1:0] = 00B */
    
    while ((RSCAN0.C1STS.UINT32 & R_CAN_CRSTSTS_ON) != 0UL)
    {
        __nop();
    }
}
/******************************************************************************
* Function Name : void R_CAN_Init( void )
* Description   : This function initializes RS-CAN.
* Argument      : none
* Return Value  : none
******************************************************************************/

Can_RtnType R_CAN_Init(uint8_t Controller, const uint16_t Baudrate)
{

    uint16_t* addr;
	uint32_t canTmpReg;
     /* RAM initialize */
    while ((RSCAN0.GSTS.UINT32 & R_CAN_GRAMINIT_ON) != 0UL)
    {
        __nop();
    }


#if 1
    /* transit to global stop mode in order to stop all channels that may have been active before */
    if (!CanLL_GlobalModeCheck(kCanStopMode))
    {
        if (!CanLL_GlobalModeCheck(kCanResetMode))
        {
          CanLL_GlobalModeReq(kCanResetMode);
          CanLL_CanTimerWait(!CanLL_GlobalModeCheck(kCanResetMode)); 
        }
		CanLL_GlobalModeReq(kCanStopMode);
		CanLL_CanTimerWait(!CanLL_GlobalModeCheck(kCanStopMode));
    }

	 /* transit to global reset mode */
    CanLL_GlobalModeReq(kCanResetMode);

    CanLL_CanTimerWait(!CanLL_GlobalModeCheck(kCanResetMode)); 
#else	
    /* Global stop mode -> Global reset mode
    RSCAN0GCTR    - Global Control Register
    b31:b17                  - Reserved set to 0
    b16:            TSRST    - Timestamp Counter Reset             - Set to default
    b15:b11                  - Reserved set to 0
    b10             THLEIE   - Transmit History Buffer Overflow
                               Interrupt Enable                    - Set to default
    b 9             MEIE     - FIFO Message Lost Interrupt Enable  - Set to default
    b 8             DEIE     - DLC Error Interrupt Enable          - Set to default
    b 7:b 3                  - Reserved set to 0
    b 2             GSLPR    - Global Stop Mode                    - Other than global stop mode. Set to 0
    b 1:b 0         GMDC     - Global Mode Select                  - Set to default */
    RSCAN0.GCTR.UINT32 &= ~R_CAN_GSLPR_MASK; /* GSLPR=0 */
    while ((RSCAN0.GSTS.UINT32 & R_CAN_GSLPSTS_ON) != 0UL)
    {
        __nop();
    }
#endif

    /* Channel stop mode -> Channel reset mode (Channel 0)
    RSCAN0CmCTR   - Channel Control Register
    b31:b27                  - Reserved set to 0
    b26:b25         CTMS     - Communication Test Mode Select      - Set to default
    b24:            CTME     - Communication Test Mode Enable      - Set to default
    b23:            ERRD     - Error Display Mode Select           - Set to default
    b22:b21         BOM      - Bus Off Recovery Mode Select        - Set to default
    b20:b17                  - Reserved set to 0
    b16:            TAIE     - Transmit Abort Interrupt Enable     - Set to default
    b15:            ALIE     - Arbitration Lost Interrupt Enable   - Set to default
    b14:            BLIE     - Bus Lock Interrupt Enable           - Set to default
    b13:            OLIE     - Overload Frame Transmit
                               Interrupt Enable                    - Set to default
    b12:            BORIE    - Bus Off Recovery Interrupt Enable   - Set to default
    b11:            BOEIE    - Bus Off Entry Interrupt Enable      - Set to default
    b10:            EPIE     - Error Passive Interrupt Enable      - Set to default
    b 9:            EWIE     - Error Warning Interrupt Enable      - Set to default
    b 8:            BEIE     - Bus Error Interrupt Enable          - Set to default
    b 7:b 4                  - Reserved set to 0
    b 3:            RTBO     - Forcible Return from Bus-off        - Set to default
    b 2             CSLPR    - Channel Stop Mode                   - Other than channel stop mode. Set to 0
    b 1:b 0         CHMDC    - Mode Select                         - Set to default */
    RSCAN0.C1CTR.UINT32 &= ~R_CAN_CSLPR_MASK; /* CSLPR = 0B */
    while ((RSCAN0.C1STS.UINT32 & R_CAN_CSLPSTS_ON) != 0UL)
    {
        __nop();
    }



    /* Set RSCAN0GCFG register.
    RSCAN0GCFG    - Global Configuration Register
    b31:b16         ITRCP    - Interval Timer Prescaler Set        - When these bits are set to M,
                                                                     the pclk is divided by M. Set to 0000H
    b15:b13         TSBTCS   - Timestamp Clock Source Select       - Channel 0 bit time clock. Set to 000'b
    b12:            TSSS     - Timestamp Source Select             - pclk/2. Set to 0
    b11:b 8         TSP      - Timestamp Clock Source Division     - Not divided. Set to 0
    b 7:b 5                  - Reserved set to 0
    b 4:            DCS      - CAN Clock Source Select             - clk_xincan. Set to 1
    b 3:            MME      - Mirror Function Enable              - Mirror function is disabled. Set to 0
    b 2:            DRE      - DLC Replacement Enable              - DLC replacement is disabled. Set to 0
    b 1:            DCE      - DLC Check Enable                    - DLC check is disabled. Set to 0
    b 0:            TPRI     - Transmit Priority Select            - ID priority. Set to 0 */
    RSCAN0.GCFG.UINT32       = 0x00000010UL; /* DCS=1 */

    /* Set RSCAN0C0CFG register.
    RSCAN0CmCFG   - Channel Configuration Register
    b31:b26                  - Reserved set to 0
    b25:b24         SJW      - Resynchronization Jump Width Control- 4 Tq. Set to 11'b
    b23                      - Reserved set to 0
    b22:b20         TSEG2    - Time Segment 2 Control              - 4 Tq. Set to 011'b 
    b19:b16         TSEG1    - Time Segment 2 Control              - 11 Tq. Set to 1010'b 
    b15:b10                  - Reserved set to 0
    b 9:b 0         BRP      - Prescaler Division Ratio Set        - fCAN / (1 + 1). Set to 0000000001'b */
    RSCAN0.C1CFG.UINT32      = 0x012b0001UL;//0x033A0000UL; /* SJW=4Tq, TSEG2=3Tq, TSEG1=12Tq, BRP=1 */

    /* ==== Rx rule setting ==== */
     Can_SetRxRule(1);

     
   
    /* Set Rx buffer number.
    RSCAN0RMNB    - Receive Buffer Number Register
    b31:b 8                  - Reserved set to 0
    b 7:b 0         NRXMB    - Receive Buffer Number Configuration - set to 1 */
#if defined(RECEIVE_BUF)
    RSCAN0.RMNB.UINT32       = 2UL;
#else
    RSCAN0.RMNB.UINT32       = 0UL;
#endif
    RSCAN0.TMIEC0.UINT32     = 0xffffffff;
    /* Set RSCAN0GCTR register.
    RSCAN0GCTR    - Global Control Register
    b31:b17                  - Reserved set to 0
    b16:            TSRST    - Timestamp Counter Reset             - Set to 0
    b15:b11                  - Reserved set to 0
    b10             THLEIE   - Transmit History Buffer Overflow
                               Interrupt Enable                    - Transmit history buffer overflow
                                                                     interrupt is disabled. Set to 0
    b 9             MEIE     - FIFO Message Lost Interrupt Enable  - FIFO message lost interrupt is disabled.
                                                                     Set to 0
    b 8             DEIE     - DLC Error Interrupt Enable          - DLC error interrupt is disabled. Set to 0
    b 7:b 3                  - Reserved set to 0
    b 2             GSLPR    - Global Stop Mode                    - Other than global stop mode. Set to 0
    b 1:b 0         GMDC     - Global Mode Select                  - Global reset mode. Set to 01'b */
    RSCAN0.GCTR.UINT32       = 0x00000001UL; /* GMDC[1:0]=01B */

    /* Channel stop mode -> Channel reset mode (Channel 0)
    RSCAN0CmCTR   - Channel Control Register
    b31:b27                  - Reserved set to 0
    b26:b25         CTMS     - Communication Test Mode Select      - Set to default
    b24:            CTME     - Communication Test Mode Enable      - Set to default
    b23:            ERRD     - Error Display Mode Select           - Set to default
    b22:b21         BOM      - Bus Off Recovery Mode Select        - Set to default
    b20:b17                  - Reserved set to 0
    b16:            TAIE     - Transmit Abort Interrupt Enable     - Set to default
    b15:            ALIE     - Arbitration Lost Interrupt Enable   - Set to default
    b14:            BLIE     - Bus Lock Interrupt Enable           - Set to default
    b13:            OLIE     - Overload Frame Transmit
                               Interrupt Enable                    - Set to default
    b12:            BORIE    - Bus Off Recovery Interrupt Enable   - Set to default
    b11:            BOEIE    - Bus Off Entry Interrupt Enable      - Set to default
    b10:            EPIE     - Error Passive Interrupt Enable      - Set to default
    b 9:            EWIE     - Error Warning Interrupt Enable      - Set to default
    b 8:            BEIE     - Bus Error Interrupt Enable          - Set to default
    b 7:b 4                  - Reserved set to 0
    b 3:            RTBO     - Forcible Return from Bus-off        - Set to default
    b 2             CSLPR    - Channel Stop Mode                   - not change
    b 1:b 0         CHMDC    - Mode Select                         - Channel reset mode. Set to 01'b */
    RSCAN0.C1CTR.UINT32      = 0x00000001UL; /* CHMDC[1:0]=01B */
#if 1   
   /* set busoff return behavior (and current mode bits) */
    canTmpReg = kCanCrHaltAtBusoff | kCanResetMode;
    /* enable busoff interrupt (also used if special busoff behaviour is configured) */
#if !defined(C_ENABLE_ERROR_POLLING)
    canTmpReg |= kCanIntMaskBusoff;
#endif
    RSCAN0.C1CTR.UINT32 |= canTmpReg;

    RSCAN0.RFCC1.UINT32 &= ( ~0x00000001u);
      /* delete fifo interrupt and overrun flags */
    RSCAN0.RFSTS1.UINT32 &= ( ~(0x00000008u | 0x00000004u));
    RSCAN0.RFCC1.UINT32 |= kCanCrRxFifoSet|(CanRxFifoDepth<<8);//
    RSCAN0.RFCC1.UINT32 |= 0x00000002u;/*enable recv fifo interrupt*/
  //RSCAN0.RFCC1.UINT32 |= kCanCrRxFifoIntEnable;
#endif
  #if 0
  RSCAN0.CFCC3.UINT32 &=  ~0x00000001u;
    /* delete fifo interrupt and overrun flags */
  RSCAN0.CFSTS3.UINT32 &= ( ~(0x00000008u | 0x00000004u));
  RSCAN0.CFCC3.UINT32 |= kCanCrRxFifoSet|(CanRxFifoDepth<<8);//
  RSCAN0.CFCC3.UINT32 |= 0x00000002u|(1<<12)|(7<<8);/*enable recv fifo interrupt*/
  #endif
      /* re-enable fifo */

    /* Global reset mode -> global communication mode
    RSCAN0GCTR    - Global Control Register
    b31:b17                  - Reserved set to 0
    b16:            TSRST    - Timestamp Counter Reset             - not change
    b15:b11                  - Reserved set to 0
    b10             THLEIE   - Transmit History Buffer Overflow
                               Interrupt Enable                    - not change
    b 9             MEIE     - FIFO Message Lost Interrupt Enable  - not change
    b 8             DEIE     - DLC Error Interrupt Enable          - not change
    b 7:b 3                  - Reserved set to 0
    b 2             GSLPR    - Global Stop Mode                    - not change
    b 1:b 0         GMDC     - Global Mode Select                  - Global operating mode. Set to 00'b */
    RSCAN0.GCTR.UINT32 &= ~R_CAN_GMDC_MASK; /* GMDC[1:0] = 00B */
    while ((RSCAN0.GSTS.UINT32 & R_CAN_GRSTSTS_ON) != 0UL)
    {
        __nop();
    }
#if 0
    /* Channel reset mode -> Channel communication mode (Channel 0)
    RSCAN0CmCTR   - Channel Control Register
    b31:b27                  - Reserved set to 0
    b26:b25         CTMS     - Communication Test Mode Select      - not change
    b24:            CTME     - Communication Test Mode Enable      - not change
    b23:            ERRD     - Error Display Mode Select           - not change
    b22:b21         BOM      - Bus Off Recovery Mode Select        - not change
    b20:b17                  - Reserved set to 0
    b16:            TAIE     - Transmit Abort Interrupt Enable     - not change
    b15:            ALIE     - Arbitration Lost Interrupt Enable   - not change
    b15:            BLIE     - Bus Lock Interrupt Enable           - not change
    b15:            OLIE     - Overload Frame Transmit
                               Interrupt Enable                    - not change
    b15:            BORIE    - Bus Off Recovery Interrupt Enable   - not change
    b15:            BOEIE    - Bus Off Entry Interrupt Enable      - not change
    b15:            EPIE     - Error Passive Interrupt Enable      - not change
    b15:            EWIE     - Error Warning Interrupt Enable      - not change
    b15:            BEIE     - Bus Error Interrupt Enable          - not change
    b 7:b 4                  - Reserved set to 0
    b 3:            RTBO     - Forcible Return from Bus-off        - not change
    b 2             CSLPR    - Channel Stop Mode                   - not change
    b 1:b 0         CHMDC    - Mode Select                         - Channel communication mode. Set to 00'b */
    RSCAN0.C1CTR.UINT32 &= ~R_CAN_CHMDC_MASK; /* CHMDC[1:0] = 00B */
    
    while ((RSCAN0.C1STS.UINT32 & R_CAN_CRSTSTS_ON) != 0UL)
    {
        __nop();
    }
 #endif   
  if((CanHwIsInit&CAN_INIT) == CAN_INIT) 
    {
      /* wait for completion of busoff recovery */
      if (CanLL_HwIsBusOff())
      {
        CanLL_CanTimerWait(CanLL_HwIsBusOff()); 
      }
    
      /* switch to reset mode and check if it is reached */
      CanLL_ModeReq_Phys(kCanResetMode);  
      CanLL_CanTimerWait(!CanLL_ModeCheck_Phys(kCanResetMode));
    }
	   /* set busoff return behavior (and current mode bits) */
    canTmpReg = kCanCrHaltAtBusoff | kCanResetMode;
    /* enable busoff interrupt (also used if special busoff behaviour is configured) */
#if !defined(C_ENABLE_ERROR_POLLING)
    canTmpReg |= kCanIntMaskBusoff;
#endif
    RSCAN0.C1CTR.UINT32 |= canTmpReg;

    RSCAN0.RFCC1.UINT32 &= ( ~0x00000001u);
      /* delete fifo interrupt and overrun flags */
    RSCAN0.RFSTS1.UINT32 &= ( ~(0x00000008u | 0x00000004u));
    RSCAN0.RFCC1.UINT32 |= kCanCrRxFifoSet|(CanRxFifoDepth<<8);//
    RSCAN0.RFCC1.UINT32 |= 0x00000002u;/*enable recv fifo interrupt*/

	 /* Channel reset mode -> Channel communication mode (Channel 0)
    RSCAN0CmCTR   - Channel Control Register
    b31:b27                  - Reserved set to 0
    b26:b25         CTMS     - Communication Test Mode Select      - not change
    b24:            CTME     - Communication Test Mode Enable      - not change
    b23:            ERRD     - Error Display Mode Select           - not change
    b22:b21         BOM      - Bus Off Recovery Mode Select        - not change
    b20:b17                  - Reserved set to 0
    b16:            TAIE     - Transmit Abort Interrupt Enable     - not change
    b15:            ALIE     - Arbitration Lost Interrupt Enable   - not change
    b15:            BLIE     - Bus Lock Interrupt Enable           - not change
    b15:            OLIE     - Overload Frame Transmit
                               Interrupt Enable                    - not change
    b15:            BORIE    - Bus Off Recovery Interrupt Enable   - not change
    b15:            BOEIE    - Bus Off Entry Interrupt Enable      - not change
    b15:            EPIE     - Error Passive Interrupt Enable      - not change
    b15:            EWIE     - Error Warning Interrupt Enable      - not change
    b15:            BEIE     - Bus Error Interrupt Enable          - not change
    b 7:b 4                  - Reserved set to 0
    b 3:            RTBO     - Forcible Return from Bus-off        - not change
    b 2             CSLPR    - Channel Stop Mode                   - not change
    b 1:b 0         CHMDC    - Mode Select                         - Channel communication mode. Set to 00'b */
    RSCAN0.C1CTR.UINT32 &= ~R_CAN_CHMDC_MASK; /* CHMDC[1:0] = 00B */
    
    while ((RSCAN0.C1STS.UINT32 & R_CAN_CRSTSTS_ON) != 0UL)
    {
        __nop();
    }
  CanHwIsInit |= CAN_INIT; 
  /*Receive FIFO interrupt is enabled*/
  RSCAN0.RFCC1.UINT32 |= 0x00000001u;
  
  addr = (uint16_t*)R_ICCANGREC0;
  R_INTC_SetTableBit(addr);
  R_INTC_UnmaskInterrupt(addr);
  

      /* re-enable fifo */
  RSCAN0.CFCC3.UINT32 |= 0x00000001u;

  
  addr = (uint16_t*)R_ICCAN1REC;
  R_INTC_SetTableBit(addr);
  R_INTC_UnmaskInterrupt(addr);
 // R_INTC_SetPriority(addr,5);

     
  addr = (uint16_t*)R_ICCAN1TRX;
  R_INTC_SetTableBit(addr);
  R_INTC_UnmaskInterrupt(addr);

  addr = (uint16_t*)R_ICCAN1ERR;
  R_INTC_SetTableBit(addr);
  R_INTC_UnmaskInterrupt(addr);

 
  return CAN_RTN_OK;
  
}

void R_CAN_Set_ResetMode(void  )
{
    RSCAN0.GCTR.UINT32       = 0x00000001UL; /* GMDC[1:0]=01B */
    RSCAN0.C1CTR.UINT32      = 0x00000001UL; /* CHMDC[1:0]=01B */
}
void R_CAN_Set_HaltMode(void  )
{
    RSCAN0.GCTR.UINT32       = 0x00000002UL; /* GMDC[1:0]=01B */
    RSCAN0.C1CTR.UINT32      = 0x00000002UL; /* CHMDC[1:0]=01B */
}

void R_CAN_Set_NormalMode(void  )
{
    RSCAN0.GCTR.UINT32 &= ~R_CAN_GMDC_MASK; /* GMDC[1:0] = 00B */
    while ((RSCAN0.GSTS.UINT32 & R_CAN_GRSTSTS_ON) != 0UL)
    {
	__nop();
    }

    RSCAN0.C1CTR.UINT32 &= ~R_CAN_CHMDC_MASK; /* CHMDC[1:0] = 00B */    
    while ((RSCAN0.C1STS.UINT32 & R_CAN_CRSTSTS_ON) != 0UL)
    {
        __nop();
    }
}
/*****************************************************************************
** Function:    Can_SetRxRule
** Description: Set all Rx rules
** Parameter:   None
** Return:      None
******************************************************************************/


static void Can_SetRxRule(uint8_t chn)
{
  uint16_t RxRuleIdx;
  uint8_t PageRxRuleIdx;
  volatile CAN_RX_RULE_TYPE* pCRE;

  /* Set Rx rule number per channel */
  if(chn > 3)
  {
    return;   
  }
  RSCAN0.GAFLCFG0.UINT32 |= CAN_RX_RULE_TABLE_NUM<<((3-chn)*8);//0x00060000;    /* Channel1 rule number is 6 */
  /* Get access base address of Rx rule */
  pCRE = (volatile CAN_RX_RULE_TYPE*)&(RSCAN0.GAFLID0.UINT32);

  /* Receive Rule Table Write Enable */
  RSCAN0.GAFLECTR.UINT32 |= 0x00000100;

  /* Copy Rx rule one by one */
  for (RxRuleIdx = 0U; RxRuleIdx < CAN_RX_RULE_TABLE_NUM; RxRuleIdx++) 
  {
    PageRxRuleIdx = (uint8_t) (RxRuleIdx & 0x0f);

    /* Update target Rx rule page if necessary */
    if (PageRxRuleIdx == 0U) 
    {
      RSCAN0.GAFLECTR.UINT32 = 0x00000100|(RxRuleIdx >> CAN_RX_RULE_PAGE_IDX_BIT_POS);
    }
#if defined(RECEIVE_BUF)
    /* Set a single Rx rule.*/
    pCRE[PageRxRuleIdx].lword[0] = CAN_RX_RULE_TABLE[RxRuleIdx].lword[0];
    pCRE[PageRxRuleIdx].lword[1] = CAN_RX_RULE_TABLE[RxRuleIdx].lword[1];
    pCRE[PageRxRuleIdx].lword[2] = CAN_RX_RULE_TABLE[RxRuleIdx].lword[2];
    pCRE[PageRxRuleIdx].lword[3] = 0;//CAN_RX_RULE_TABLE[RxRuleIdx].lword[3];
#else
    pCRE[PageRxRuleIdx].lword[0] = CAN_RX_RULE_TABLE[RxRuleIdx].lword[0];
    pCRE[PageRxRuleIdx].lword[1] = CAN_RX_RULE_TABLE[RxRuleIdx].lword[1];
    pCRE[PageRxRuleIdx].lword[2] = 0;//CAN_RX_RULE_TABLE[RxRuleIdx].lword[2];
    pCRE[PageRxRuleIdx].lword[3] = CAN_RX_RULE_TABLE[RxRuleIdx].lword[3];
#endif
  
  }
    RSCAN0.RMNB.UINT32       = 0UL;
  /* Rx rule write disable */
  RSCAN0.GAFLECTR.UINT32 &= 0xfffffeffu;
}


/******************************************************************************
* Function Name : R_Can_ClrBusPassiveError
* Description   : This function clr error.
* Argument      : NO
* Return Value  : NO
******************************************************************************/


void R_Can_ClrBusPassiveError(void)
{
	if(CanLL_HwIsPassive(CH1))
	{
		return;
	}
	else
	{
		CanLL_ClrAllErrorFlag(CH1);	
		
	}	
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
Can_RtnType R_CAN_AbortTrm(can_ch_t ch_idx, uint32_t NrMail)
{
   //uint32_t txbuf_idx = 0;
  // for(txbuf_idx = 0; txbuf_idx <16; txbuf_idx++)
   {
     if(RSCAN0TMSTSp(ch_idx,NrMail)&CANTMTSTS_ON == CANTMTSTS_ON)
     {
           /* ---- Set transmission abort request ---- */
         RSCAN0TMCp(ch_idx, NrMail) |= CAN_TXBUF_ABT_BIT_ON;
     }
   	}
    return CAN_RTN_OK;
}


/****************************************************************************** 
* Function Name: R_CAN_AbortTrmMail
* Description  : Abort a CAN transmission
* Arguments    : ch_idx -
*                    channel index
*                NrMail -
*                    Tx buffer index
* Return Value : uint16_t -
*                     
******************************************************************************/
uint16_t R_CAN_AbortTrmMail(can_ch_t ch_idx, uint32_t NrMail)
{
    RSCAN0TMCp(ch_idx, NrMail) |= CAN_TXBUF_ABT_BIT_ON;
    return (uint16_t)(((uint16_t)RSCAN0TMTARSTSy(ch_idx)>>NrMail)&0x01);
}
/****************************************************************************** 
* Function Name: R_CAN_GetAbortTrm
* Description  : get  Abort a CAN transmission data
* Arguments    : ch_idx -
*                    channel index
*                txbuf_idx -
*                    Tx buffer index
* Return Value : CAN_RTN_OK -
*                    normal completion
*                CAN_RTN_ARG_ERROR -
*                    invalid argument specification
******************************************************************************/
Can_RtnType R_CAN_GetAbortTrmData(can_ch_t ch_idx,uint32_t NrMail, uint8_t *len, uint8_t *canData)
{
     volatile uint32_t * p_CiTBp;
     p_CiTBp = &(RSCAN0TMIDp(ch_idx, NrMail));
     *(canData++) = *(p_CiTBp++) ;
     *(canData++) = *(p_CiTBp++) ;
     *(canData++) = *(p_CiTBp++) ;
     *canData = *(p_CiTBp++) ;
     return CAN_RTN_OK;
}

/****************************************************************************** 
* Function Name: R_CAN_Get_Status
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

Can_RtnType R_CAN_Get_Status(can_ch_t ch_idx)
{
   Can_RtnType ret;
   if( RSCAN0CmSTS(ch_idx)&0x07)
   {
   	   ret = CAN_RTN_ERROR;
   }
   else
   {
      ret = CAN_RTN_OK;
   }
   return ret;
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
#include "m_gpio.h"
Can_RtnType R_CAN_TrmByTxBuf(can_ch_t ch_idx, can_txbuf_t txbuf_idx, const can_frame_t * pFrame)
{
	//  static int x=0;   
  // set_inh_status(x);
  // x=!x;


    /* ---- Clear Tx buffer status ---- */
    {
        volatile uint8_t  * p_TMSTSp;

        p_TMSTSp = &(RSCAN0TMSTSp(ch_idx, txbuf_idx));
        *p_TMSTSp = 0x0U;
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
        *(p_CiTBp++) = *(p_data++);
        *(p_CiTBp++) = *(p_data++);
        *(p_CiTBp++) = *(p_data++);
        *(p_CiTBp  ) = *(p_data  );
    }

    /* ---- Set transmission request ---- */
    RSCAN0TMCp(ch_idx, txbuf_idx) = CAN_TXBUF_TRM_BIT_ON;

    return CAN_RTN_OK;
}


/*****************************************************************************
** Function:    CanIsrGRxFifo
** Description: CAN gloabe receive FIFO interrupt.
** Parameter:   None
** Return:      None
******************************************************************************/
void Can_Isr_Rx(uint8_t controller, can_frame_t *rxinfo);
#ifdef __IAR__
    #pragma vector = CanIsrGRxFifo
    __interrupt void CanIsrGRxFifo(void)
#endif
#ifdef __GHS__
    #pragma ghs interrupt
    void CanIsrGRxFifo(void)
#endif
#ifdef __CSP__
  #pragma interrupt CanIsrGRxFifo(enable=true)//true false manual
  void CanIsrGRxFifo(void)
#endif /* __CSP__*/
{
  can_frame_t pFrame;
  uint32_t FESTS = 0;
  uint8_t MaxCount = 128;
  do
  {   
	RSCAN0.RFSTS1.UINT32 &= ((uint32_t)~kCanSrRxFifoIntFlag);   
	pFrame.ID = RSCAN0.RFID1.UINT32;//& 0x7FFUL;
	pFrame.DLC    = (uint8_t)(RSCAN0.RFPTR1.UINT32 >> 28);
	*((uint32_t *)&pFrame.DB[0]) = RSCAN0.RFDF01.UINT32;
	*((uint32_t *)&pFrame.DB[4]) = RSCAN0.RFDF11.UINT32;	
	
	if((RSCAN0.RFCC1.UINT32&0x01)&&(0 == (RSCAN0.RFSTS1.UINT32&0x01)))
	{ 
	   /* Point to next msg in fifo */
	   RSCAN0.RFPCTR1.UINT32 = 0x000000ff;
	}
	Can_Isr_Rx(0,&pFrame); 
	
	FESTS = RSCAN0.FESTS.UINT32&0x02;
	
   }while((!FESTS) && (MaxCount--));
}
#if 0
/*****************************************************************************
** Function:    INTRLIN30UR0
** Description: RLIN30 UART Tx Completion interrupt.
** Parameter:   None
** Return:      None
******************************************************************************/
#ifdef __IAR__
    #pragma vector = CanIsrRxFifo
    __interrupt void CanIsrRxFifo(void)
#endif
#ifdef __GHS__
    #pragma ghs interrupt
    void CanIsrRxFifo(void)
#endif
#ifdef __CSP__
  #pragma interrupt CanIsrRxFifo(enable=manual)
  void CanIsrRxFifo(void)
#endif /* __CSP__*/
{
	//bool     ret;
  uint32_t can_id;
  uint8_t  dlc;
  uint8_t  msg[8];
  RSCAN0.CFSTS3.UINT32 &= (~kCanSrRxFifoIntFlag); 
  can_id = RSCAN0.CFID3.UINT32& 0x7FFUL;
  dlc    = (uint8_t)(RSCAN0.CFPTR3.UINT32 >> 28);
  *((uint32_t *)&msg[0]) = RSCAN0.CFDF03.UINT32;
  *((uint32_t *)&msg[4]) = RSCAN0.CFDF13.UINT32;
  /* Point to next msg in fifo */
   RSCAN0.CFPCTR3.UINT32 = 0xff;
  // RSCAN0.CFSTS3.YINT32 &= ~(3<<3);
  /* Point to next msg in fifo */
 // RSCFD0.RSCAN0CFDRFPCTR0.UINT32 = kCanPcrFifoPC;
 
}
#endif
/*****************************************************************************
** Function:    Can_Isr_Tx
** Description: Tx Completion interrupt.
** Parameter:   None
** Return:      None
******************************************************************************/
extern void Can_Isr_Tx(uint8_t controller,uint8_t mb_index);
static void CanIsrTxcomplete(uint8_t channel)
{
	//int i = 0;
	int NrTxMail = 0;
	uint16_t state;
	state = RSCAN0TMTCSTSy16(channel);
	for(NrTxMail=0; NrTxMail<16; NrTxMail++)
	{
	    if(state&0x01)
	    {
		RSCAN0TMSTSp(channel, NrTxMail)&= ~(3<<1);
		Can_Isr_Tx(0,NrTxMail);
	    }
	    else if(0 == state)
	    {
		  return ;
	    }
	    state = state>>1;
	   // NrTxMail++;
	}
}
/*****************************************************************************
** Function:    CanIsrTx
** Description: Tx Completion interrupt.
** Parameter:   None
** Return:      None
******************************************************************************/
#ifdef __IAR__
    #pragma vector = Can1IsrTx
    __interrupt void CanIsrTx(void)
#endif
#ifdef __GHS__
    #pragma ghs interrupt
    void Can1IsrTx(void)
#endif
#ifdef __CSP__
  #pragma interrupt Can1IsrTx(enable=true)
  void Can1IsrTx(void)
#endif /* __CSP__*/
{
  R_Can_ClrBusPassiveError();
  CanIsrTxcomplete(CH1);
  set_dtc_BusoffSts(DTC_NORMAL);
}
/*****************************************************************************
** Function:    Can1IsrErr
** Description: Can1IsrErr interrupt.
** Parameter:   None
** Return:      None
******************************************************************************/
#ifdef __IAR__
    #pragma vector = Can1IsrErr
    __interrupt void Can1IsrErr(void)
#endif
#ifdef __GHS__
    #pragma ghs interrupt
    void Can1IsrErr(void)
#endif
#ifdef __CSP__
  #pragma interrupt Can1IsrErr(enable=true)
  void Can1IsrErr(void)
#endif /* __CSP__*/
{
  if(kCanEfMaskBusoff == (RSCAN0.C1ERFL.UINT16[0] & kCanEfMaskBusoff) )
  {
	RSCAN0.C1ERFL.UINT16[0] = kCanEfMaskBusoffClear;
	Can_BusOff(CH1);
	CbdWrpBusOff();
	set_dtc_BusoffSts(DTC_ERROR);
  }
  if(0 != RSCAN0.FMSTS.UINT32 &kCanRxFifoMask )
  {
      RSCAN0.RFSTS1.UINT32 &=  ~kCanSrFifoOverrun;
  }
}