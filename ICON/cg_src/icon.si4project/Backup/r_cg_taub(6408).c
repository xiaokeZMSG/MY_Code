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
* File Name    : r_cg_taub.c
* Version      : Code Generator for RH850/F1K V1.01.00.02 [19 Apr 2017]
* Device(s)    : R7F701582(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for TAUB module.
* Creation Date: 2021/7/14
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
#include "r_cg_taub.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_TAUB0_Create
* Description  : This function initializes the TAUB0 Bus Interface.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Create(void)
{
    /* Disable channel0 counter operation */
    TAUB0.TT = _TAUB_CHANNEL15_COUNTER_STOP | _TAUB_CHANNEL14_COUNTER_STOP | _TAUB_CHANNEL13_COUNTER_STOP | 
               _TAUB_CHANNEL12_COUNTER_STOP | _TAUB_CHANNEL11_COUNTER_STOP | _TAUB_CHANNEL10_COUNTER_STOP | 
               _TAUB_CHANNEL9_COUNTER_STOP | _TAUB_CHANNEL8_COUNTER_STOP | _TAUB_CHANNEL7_COUNTER_STOP | 
               _TAUB_CHANNEL6_COUNTER_STOP | _TAUB_CHANNEL5_COUNTER_STOP | _TAUB_CHANNEL4_COUNTER_STOP | 
               _TAUB_CHANNEL3_COUNTER_STOP | _TAUB_CHANNEL2_COUNTER_STOP | _TAUB_CHANNEL1_COUNTER_STOP | 
               _TAUB_CHANNEL0_COUNTER_STOP;
    /* Disable INTTAUB0I10 operation and clear request */
    INTC2.ICTAUB0I10.BIT.MKTAUB0I10 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I10.BIT.RFTAUB0I10 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUB0I12 operation and clear request */
    INTC2.ICTAUB0I12.BIT.MKTAUB0I12 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I12.BIT.RFTAUB0I12 = _INT_REQUEST_NOT_OCCUR;
#if 0
    /* Disable INTTAUB0I14 operation and clear request */
    INTC2.ICTAUB0I14.BIT.MKTAUB0I14 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I14.BIT.RFTAUB0I14 = _INT_REQUEST_NOT_OCCUR;
#endif
    /* Set INTTAUB0I10 setting */
    INTC2.ICTAUB0I10.BIT.TBTAUB0I10 = _INT_TABLE_VECTOR;
    INTC2.ICTAUB0I10.UINT16 &= _INT_PRIORITY_LOWEST;
    /* Set INTTAUB0I12 setting */
    INTC2.ICTAUB0I12.BIT.TBTAUB0I12 = _INT_TABLE_VECTOR;
    INTC2.ICTAUB0I12.UINT16 &= _INT_PRIORITY_LOWEST;
#if 0
    /* Set INTTAUB0I14 setting */
    INTC2.ICTAUB0I14.BIT.TBTAUB0I14 = _INT_TABLE_VECTOR;
    INTC2.ICTAUB0I14.UINT16 &= _INT_PRIORITY_LOWEST;
#endif
    TAUB0.TPS = _TAUB_CK3_PRE_PCLK_0 | _TAUB_CK2_PRE_PCLK_0 | _TAUB_CK1_PRE_PCLK_0 | _TAUB_CK0_PRE_PCLK_0;
    /* Set channel 10 setting */
    TAUB0.CMOR10 = _TAUB_SELECTION_CK0 | _TAUB_OPERATION_CLOCK | _TAUB_MASTER_CHANNEL | _TAUB_SOFTWARE_TRIGGER | 
                   _TAUB_OVERFLOW_AUTO_CLEAR | _TAUB_INTERVAL_TIMER_MODE | _TAUB_START_INT_GENERATED;
    TAUB0.CMUR10 = _TAUB_INPUT_EDGE_UNUSED;
    TAUB0.CDR10 = _TAUB0_CHANNEL10_COMPARE_VALUE;
    /* Set channel 12 setting */
    TAUB0.CMOR12 = _TAUB_SELECTION_CK0 | _TAUB_OPERATION_CLOCK | _TAUB_SLAVE_CHANNEL | _TAUB_MASTER_START | 
                   _TAUB_OVERFLOW_AUTO_CLEAR | _TAUB_ONE_COUNT_MODE | _TAUB_START_TRIGGER_ENABLE;
    TAUB0.CMUR12 = _TAUB_INPUT_EDGE_UNUSED;
    TAUB0.CDR12 = _TAUB0_CHANNEL12_COMPARE_VALUE;
#if 0
    /* Set channel 14 setting */
    TAUB0.CMOR14 = _TAUB_SELECTION_CK0 | _TAUB_OPERATION_CLOCK | _TAUB_SLAVE_CHANNEL | _TAUB_MASTER_START | 
                   _TAUB_OVERFLOW_AUTO_CLEAR | _TAUB_ONE_COUNT_MODE | _TAUB_START_TRIGGER_ENABLE;
    TAUB0.CMUR14 = _TAUB_INPUT_EDGE_UNUSED;
    TAUB0.CDR14 = _TAUB0_CHANNEL14_COMPARE_VALUE;
#endif
    /* Set output mode setting */
    TAUB0.TOE = _TAUB_CHANNEL12_ENABLES_OUTPUT_MODE | 
                _TAUB_CHANNEL10_DISABLES_OUTPUT_MODE;        // _TAUB_CHANNEL14_ENABLES_OUTPUT_MODE | 
    TAUB0.TOM = _TAUB_CHANNEL12_SYNCHRONOUS_OUTPUT_MODE;     // _TAUB_CHANNEL14_SYNCHRONOUS_OUTPUT_MODE | 
    TAUB0.TOC = _TAUB_CHANNEL12_OPERATION_MODE1;             // _TAUB_CHANNEL14_OPERATION_MODE1 | 
    TAUB0.TOL = _TAUB_CHANNEL12_POSITIVE_LOGIC;              // _TAUB_CHANNEL14_POSITIVE_LOGIC | 
    TAUB0.TDE = _TAUB_CHANNEL12_DISABLE_DEAD_TIME_OPERATE;   //_TAUB_CHANNEL14_DISABLE_DEAD_TIME_OPERATE | 
    TAUB0.TDL = _TAUB_CHANNEL12_POSITIVE_PHASE_PERIOD;       // _TAUB_CHANNEL14_POSITIVE_PHASE_PERIOD | 
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TPS;
    __syncp();

    /* Set TAUB0O12 pin */
    // |= (1u<<6);     // 6??1
    // &= ~(1u<<6);    // 6??0
    
    PORT.PIBC0 &= ~(1u<<13); //_PORT_CLEAR_BIT13;
    PORT.PBDC0 &= ~(1u<<13); // _PORT_CLEAR_BIT13;
    PORT.PM0 |= (1u<<13);    // _PORT_SET_BIT13;  
    PORT.PMC0 &= ~(1u<<13);  //_PORT_CLEAR_BIT13;
    PORT.PIPC0 &= ~(1u<<13); //_PORT_CLEAR_BIT13;
    PORT.PFC0 &= ~(1u<<13);  //_PORT_CLEAR_BIT13;
    PORT.PFCE0 |= (1u<<13); //_PORT_SET_BIT13;  
    PORT.PFCAE0 &= ~(1u<<13); //_PORT_CLEAR_BIT13;
    PORT.PMC0 |= (1u<<13); // _PORT_SET_BIT13;  
    PORT.PM0 &= ~(1u<<13); //_PORT_CLEAR_BIT13;
#if 0
    /* Set TAUB0O14 pin */
    PORT.PIBC0 &= ~(1u<<14); //_PORT_CLEAR_BIT14;
    PORT.PBDC0 &= ~(1u<<14); // _PORT_CLEAR_BIT14;
    PORT.PM0 |= (1u<<14);    // _PORT_SET_BIT14;  
    PORT.PMC0 &= ~(1u<<14);  //_PORT_CLEAR_BIT14;
    PORT.PIPC0 &= ~(1u<<14); //_PORT_CLEAR_BIT14;
    PORT.PFC0 &= ~(1u<<14);  //_PORT_CLEAR_BIT14;
    PORT.PFCE0 |= (1u<<14);  // _PORT_SET_BIT14;  
    PORT.PFCAE0 &= ~(1u<<14); //_PORT_CLEAR_BIT14;
    PORT.PMC0 |= (1u<<14);    // _PORT_SET_BIT14;  
    PORT.PM0 &= ~(1u<<14);   // _PORT_CLEAR_BIT14;
#endif
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel10_Start
* Description  : This function clears TAUB010 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel10_Start(void)
{
    /* Clear INTTAUB0I10 request and enable operation */
    INTC2.ICTAUB0I10.BIT.RFTAUB0I10 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICTAUB0I10.BIT.MKTAUB0I10 = _INT_PROCESSING_ENABLED;    
    /* Clear INTTAUB0I12 request and enable operation */
    INTC2.ICTAUB0I12.BIT.RFTAUB0I12 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICTAUB0I12.BIT.MKTAUB0I12 = _INT_PROCESSING_ENABLED; 
#if 0
    /* Clear INTTAUB0I14 request and enable operation */
    INTC2.ICTAUB0I14.BIT.RFTAUB0I14 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICTAUB0I14.BIT.MKTAUB0I14 = _INT_PROCESSING_ENABLED; 
#endif
    /* Enable channel10 counter operation */
    TAUB0.TS |= _TAUB_CHANNEL10_COUNTER_START | _TAUB_CHANNEL12_COUNTER_START | _TAUB_CHANNEL14_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel10_Stop
* Description  : This function disables TAUB010 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel10_Stop(void)
{
    /* Disable channel10 counter operation */
    TAUB0.TT |= _TAUB_CHANNEL10_COUNTER_STOP | _TAUB_CHANNEL12_COUNTER_STOP | _TAUB_CHANNEL14_COUNTER_STOP;
    /* Disable INTTAUB0I0 operation and clear request */
    INTC2.ICTAUB0I10.BIT.MKTAUB0I10 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I10.BIT.RFTAUB0I10 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUB0I12 operation and clear request */
    INTC2.ICTAUB0I12.BIT.MKTAUB0I12 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I12.BIT.RFTAUB0I12 = _INT_REQUEST_NOT_OCCUR;
#if 0
    /* Disable INTTAUB0I14 operation and clear request */
    INTC2.ICTAUB0I14.BIT.MKTAUB0I14 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I14.BIT.RFTAUB0I14 = _INT_REQUEST_NOT_OCCUR;
#endif
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TT;
    __syncp();
}

/* Start user code for adding. Do not edit comment generated here */
void R_TAUB0_Channel12_duty(uint32_t value)
{ 
    TAUB0.CDR12 = value * 0x1000U + _TAUB0_CHANNEL12_COMPARE_VALUE;
 //   TAUB0.RDT = TAUB0C12;
}

void R_TAUB0_Channel12_lowValue(void)
{     
    PORT.P0 &= ~(1u<<13);
    PORT.PM0 &= ~(1u<<13);
    PORT.PMC0 &= ~(1u<<13);
 //   TAUB0.RDT = TAUB0C12;
}

void R_TAUB0_Channel12_highValue(void)
{     
    PORT.P0 |= (1u<<13);
    PORT.PM0 &= ~(1u<<13);
    PORT.PMC0 &= ~(1u<<13);
 //   TAUB0.RDT = TAUB0C12;
}


void R_TAUB0_Channel12_normalValue(void)
{ 
    TAUB0.CDR12 = _TAUB0_CHANNEL12_COMPARE_VALUE;
    delay(10);
    PORT.PMC0 |= (1u<<13);
    
//    PORT.P0 |= (1u<<13);
//    PORT.PM0 &= ~(1u<<13);
//    PORT.PMC0 &= ~(1u<<13);
 //   TAUB0.RDT = TAUB0C12;
}



void R_TAUB0_ReInit(void)
{ 
    PORT.PIBC0 &= ~(1u<<13);
    PORT.PM0 |= (1u<<13);
}
/* End user code. Do not edit comment generated here */
