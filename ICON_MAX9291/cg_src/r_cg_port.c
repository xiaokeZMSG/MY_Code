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
* File Name    : r_cg_port.c
* Version      : Code Generator for RH850/F1K V1.01.00.02 [19 Apr 2017]
* Device(s)    : R7F701582(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for Port module.
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
#include "r_cg_port.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read      /* Synchronization processing */;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_PORT_Create
* Description  : This function initializes the Port I/O.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_PORT_Create(void)
{
    /* PORT initialization */
    PORT.PIBC8 = _PORT_PIBC_INIT;
    PORT.PIBC10 = _PORT_PIBC_INIT;
    PORT.PIBC11 = _PORT_PIBC_INIT;
    PORT.PIBC12 = _PORT_PIBC_INIT;
    PORT.PBDC8 = _PORT_PBDC_INIT;
    PORT.PBDC10 = _PORT_PBDC_INIT;
    PORT.PBDC11 = _PORT_PBDC_INIT;
    PORT.PBDC12 = _PORT_PBDC_INIT;
    PORT.PM8 = _PORT_PM_INIT;
    PORT.PM10 = _PORT_PM_INIT;
    PORT.PM11 = _PORT_PM_INIT;
    PORT.PM12 = _PORT_PM_INIT;
    PORT.PMC8 = _PORT_PMC_INIT;
    PORT.PMC10 = _PORT_PMC_INIT;
    PORT.PMC11 = _PORT_PMC_INIT;
    PORT.PMC12 = _PORT_PMC_INIT;
    PORT.PIPC10= _PORT_PIPC_INIT;
    PORT.PIPC11= _PORT_PIPC_INIT;
    /* Port8 setting */
    PORT.PIS8 = _PORT_PIS8_DEFAULT_VALUE | _PORT_PISn12_TYPE_SHMT4 | _PORT_PISn11_TYPE_SHMT4 | 
                _PORT_PISn10_TYPE_SHMT4 | _PORT_PISn9_TYPE_SHMT4 | _PORT_PISn8_TYPE_SHMT4 | _PORT_PISn7_TYPE_SHMT4 | 
                _PORT_PISn6_TYPE_SHMT4 | _PORT_PISn5_TYPE_SHMT4 | _PORT_PISn4_TYPE_SHMT4 | _PORT_PISn3_TYPE_SHMT4 | 
                _PORT_PISn2_TYPE_SHMT4 | _PORT_PISn1_TYPE_SHMT4 | _PORT_PISn0_TYPE_SHMT1;
    PORT.PM8 = _PORT_PM8_DEFAULT_VALUE | _PORT_PMn12_MODE_UNUSED | _PORT_PMn11_MODE_UNUSED | _PORT_PMn10_MODE_UNUSED | 
               _PORT_PMn9_MODE_UNUSED | _PORT_PMn8_MODE_UNUSED | _PORT_PMn7_MODE_UNUSED | _PORT_PMn6_MODE_UNUSED | 
               _PORT_PMn5_MODE_UNUSED | _PORT_PMn4_MODE_UNUSED | _PORT_PMn3_MODE_UNUSED | _PORT_PMn2_MODE_UNUSED | 
               _PORT_PMn1_MODE_UNUSED | _PORT_PMn0_MODE_UNUSED;
    /* Port10 setting */
    PORT.PPCMD10 = _WRITE_PROTECT_COMMAND;
    PORT.PDSC10 = _PORT_PDSCn15_SLOW_MODE_SELECT | _PORT_PDSCn5_SLOW_MODE_SELECT | _PORT_PDSCn4_SLOW_MODE_SELECT | 
                  _PORT_PDSCn1_SLOW_MODE_SELECT;
    PORT.PDSC10 = (uint32_t) ~(_PORT_PDSCn15_SLOW_MODE_SELECT | _PORT_PDSCn5_SLOW_MODE_SELECT | 
                  _PORT_PDSCn4_SLOW_MODE_SELECT | _PORT_PDSCn1_SLOW_MODE_SELECT);
    PORT.PDSC10 = _PORT_PDSCn15_SLOW_MODE_SELECT | _PORT_PDSCn5_SLOW_MODE_SELECT | _PORT_PDSCn4_SLOW_MODE_SELECT | 
                  _PORT_PDSCn1_SLOW_MODE_SELECT;
    PORT.PPCMD10 = _WRITE_PROTECT_COMMAND;
    PORT.PODC10 = _PORT_PODCn15_PUSH_PULL | _PORT_PODCn5_PUSH_PULL | _PORT_PODCn4_PUSH_PULL | _PORT_PODCn1_PUSH_PULL;
    PORT.PODC10 = (uint32_t) ~(_PORT_PODCn15_PUSH_PULL | _PORT_PODCn5_PUSH_PULL | _PORT_PODCn4_PUSH_PULL | 
                  _PORT_PODCn1_PUSH_PULL);
    PORT.PODC10 = _PORT_PODCn15_PUSH_PULL | _PORT_PODCn5_PUSH_PULL | _PORT_PODCn4_PUSH_PULL | _PORT_PODCn1_PUSH_PULL;
    PORT.PBDC10 = _PORT_PBDCn15_PBDC_MODE_DISABLED | _PORT_PBDCn5_PBDC_MODE_DISABLED | 
                  _PORT_PBDCn4_PBDC_MODE_DISABLED | _PORT_PBDCn1_PBDC_MODE_DISABLED;
    PORT.PU10 = _PORT_PUn14_PULLUP_OFF | _PORT_PUn13_PULLUP_OFF | _PORT_PUn12_PULLUP_OFF | _PORT_PUn11_PULLUP_OFF | 
                _PORT_PUn10_PULLUP_OFF | _PORT_PUn9_PULLUP_OFF | _PORT_PUn8_PULLUP_OFF | _PORT_PUn7_PULLUP_OFF | 
                _PORT_PUn6_PULLUP_OFF | _PORT_PUn3_PULLUP_ON | _PORT_PUn2_PULLUP_ON | _PORT_PUn0_PULLUP_OFF;
    PORT.PD10 = _PORT_PDn14_PULLDOWN_OFF | _PORT_PDn13_PULLDOWN_OFF | _PORT_PDn12_PULLDOWN_OFF | 
                _PORT_PDn11_PULLDOWN_OFF | _PORT_PDn10_PULLDOWN_OFF | _PORT_PDn9_PULLDOWN_OFF | 
                _PORT_PDn8_PULLDOWN_OFF | _PORT_PDn7_PULLDOWN_OFF | _PORT_PDn6_PULLDOWN_OFF | _PORT_PDn0_PULLDOWN_OFF;
    PORT.PIS10 = _PORT_PISn14_TYPE_SHMT4 | _PORT_PISn13_TYPE_SHMT4 | _PORT_PISn12_TYPE_SHMT4 | 
                 _PORT_PISn11_TYPE_SHMT4 | _PORT_PISn10_TYPE_SHMT4 | _PORT_PISn9_TYPE_SHMT4 | _PORT_PISn8_TYPE_SHMT1 | 
                 _PORT_PISn7_TYPE_SHMT4 | _PORT_PISn6_TYPE_SHMT4 | _PORT_PISn3_TYPE_SHMT4 | _PORT_PISn2_TYPE_SHMT4 | 
                 _PORT_PISn0_TYPE_SHMT4;
    PORT.P10 = _PORT_Pn15_OUTPUT_LOW | _PORT_Pn5_OUTPUT_HIGH | _PORT_Pn4_OUTPUT_LOW | _PORT_Pn1_OUTPUT_LOW;
    PORT.PM10 = _PORT_PMn15_MODE_OUTPUT | _PORT_PMn14_MODE_UNUSED | _PORT_PMn13_MODE_UNUSED | 
                _PORT_PMn12_MODE_UNUSED | _PORT_PMn11_MODE_UNUSED | _PORT_PMn10_MODE_UNUSED | _PORT_PMn9_MODE_UNUSED | 
                _PORT_PMn8_MODE_UNUSED | _PORT_PMn7_MODE_UNUSED | _PORT_PMn6_MODE_UNUSED | _PORT_PMn5_MODE_OUTPUT | 
                _PORT_PMn4_MODE_OUTPUT | _PORT_PMn3_MODE_UNUSED | _PORT_PMn2_MODE_UNUSED | _PORT_PMn1_MODE_OUTPUT | 
                _PORT_PMn0_MODE_UNUSED;
    /* Port11 setting */
    PORT.PPCMD11 = _WRITE_PROTECT_COMMAND;
    PORT.PDSC11 = _PORT_PDSCn10_SLOW_MODE_SELECT | _PORT_PDSCn7_SLOW_MODE_SELECT | _PORT_PDSCn6_SLOW_MODE_SELECT | 
                  _PORT_PDSCn5_SLOW_MODE_SELECT | _PORT_PDSCn4_SLOW_MODE_SELECT | _PORT_PDSCn3_SLOW_MODE_SELECT | 
                  _PORT_PDSCn0_SLOW_MODE_SELECT;
    PORT.PDSC11 = (uint32_t) ~(_PORT_PDSCn10_SLOW_MODE_SELECT | _PORT_PDSCn7_SLOW_MODE_SELECT | 
                  _PORT_PDSCn6_SLOW_MODE_SELECT | _PORT_PDSCn5_SLOW_MODE_SELECT | _PORT_PDSCn4_SLOW_MODE_SELECT | 
                  _PORT_PDSCn3_SLOW_MODE_SELECT | _PORT_PDSCn0_SLOW_MODE_SELECT);
    PORT.PDSC11 = _PORT_PDSCn10_SLOW_MODE_SELECT | _PORT_PDSCn7_SLOW_MODE_SELECT | _PORT_PDSCn6_SLOW_MODE_SELECT | 
                  _PORT_PDSCn5_SLOW_MODE_SELECT | _PORT_PDSCn4_SLOW_MODE_SELECT | _PORT_PDSCn3_SLOW_MODE_SELECT | 
                  _PORT_PDSCn0_SLOW_MODE_SELECT;
    PORT.PPCMD11 = _WRITE_PROTECT_COMMAND;
    PORT.PODC11 = _PORT_PODCn10_PUSH_PULL | _PORT_PODCn7_PUSH_PULL | _PORT_PODCn6_PUSH_PULL | _PORT_PODCn5_PUSH_PULL | 
                  _PORT_PODCn4_PUSH_PULL | _PORT_PODCn3_PUSH_PULL | _PORT_PODCn0_PUSH_PULL;
    PORT.PODC11 = (uint32_t) ~(_PORT_PODCn10_PUSH_PULL | _PORT_PODCn7_PUSH_PULL | _PORT_PODCn6_PUSH_PULL | 
                  _PORT_PODCn5_PUSH_PULL | _PORT_PODCn4_PUSH_PULL | _PORT_PODCn3_PUSH_PULL | _PORT_PODCn0_PUSH_PULL);
    PORT.PODC11 = _PORT_PODCn10_PUSH_PULL | _PORT_PODCn7_PUSH_PULL | _PORT_PODCn6_PUSH_PULL | _PORT_PODCn5_PUSH_PULL | 
                  _PORT_PODCn4_PUSH_PULL | _PORT_PODCn3_PUSH_PULL | _PORT_PODCn0_PUSH_PULL;
    PORT.PBDC11 = _PORT_PBDCn10_PBDC_MODE_DISABLED | _PORT_PBDCn7_PBDC_MODE_DISABLED | 
                  _PORT_PBDCn6_PBDC_MODE_DISABLED | _PORT_PBDCn5_PBDC_MODE_DISABLED | 
                  _PORT_PBDCn4_PBDC_MODE_DISABLED | _PORT_PBDCn3_PBDC_MODE_DISABLED | _PORT_PBDCn0_PBDC_MODE_DISABLED;
    PORT.P11 = _PORT_Pn10_OUTPUT_LOW | _PORT_Pn7_OUTPUT_LOW | _PORT_Pn6_OUTPUT_HIGH | _PORT_Pn5_OUTPUT_HIGH | 
               _PORT_Pn4_OUTPUT_LOW | _PORT_Pn3_OUTPUT_HIGH | _PORT_Pn0_OUTPUT_LOW;
    PORT.PM11 = _PORT_PMn15_MODE_UNUSED | _PORT_PMn14_MODE_UNUSED | _PORT_PMn13_MODE_UNUSED | 
                _PORT_PMn12_MODE_UNUSED | _PORT_PMn11_MODE_UNUSED | _PORT_PMn10_MODE_OUTPUT | _PORT_PMn9_MODE_UNUSED | 
                _PORT_PMn8_MODE_UNUSED | _PORT_PMn7_MODE_OUTPUT | _PORT_PMn6_MODE_OUTPUT | _PORT_PMn5_MODE_OUTPUT | 
                _PORT_PMn4_MODE_OUTPUT | _PORT_PMn3_MODE_OUTPUT | _PORT_PMn2_MODE_UNUSED | _PORT_PMn1_MODE_UNUSED | 
                _PORT_PMn0_MODE_OUTPUT;
    /* Port12 setting */
    PORT.PPCMD12 = _WRITE_PROTECT_COMMAND;
    PORT.PDSC12 = _PORT_PDSCn0_SLOW_MODE_SELECT;
    PORT.PDSC12 = (uint32_t) ~_PORT_PDSCn0_SLOW_MODE_SELECT;
    PORT.PDSC12 = _PORT_PDSCn0_SLOW_MODE_SELECT;
    PORT.PPCMD12 = _WRITE_PROTECT_COMMAND;
    PORT.PODC12 = _PORT_PODCn0_PUSH_PULL;
    PORT.PODC12 = (uint32_t) ~_PORT_PODCn0_PUSH_PULL;
    PORT.PODC12 = _PORT_PODCn0_PUSH_PULL;
    PORT.PBDC12 = _PORT_PBDCn0_PBDC_MODE_DISABLED;
    PORT.P12 = _PORT_Pn0_OUTPUT_HIGH;
    PORT.PM12 = _PORT_PM12_DEFAULT_VALUE | _PORT_PMn2_MODE_UNUSED | _PORT_PMn1_MODE_UNUSED | _PORT_PMn0_MODE_OUTPUT;
    /* Synchronization processing */
    g_cg_sync_read = PORT.PM8;
    __syncp();
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
