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
    PORT.APIBC0 = _PORT_APIBC_INIT;
    PORT.APIBC1 = _PORT_APIBC_INIT;
    PORT.PIBC0 = _PORT_PIBC_INIT;
    PORT.PIBC8 = _PORT_PIBC_INIT;
    PORT.PIBC9 = _PORT_PIBC_INIT;
    PORT.PIBC10 = _PORT_PIBC_INIT;
    PORT.APBDC0 = _PORT_APBDC_INIT;
    PORT.APBDC1 = _PORT_APBDC_INIT;
    PORT.PBDC0 = _PORT_PBDC_INIT;
    PORT.PBDC8 = _PORT_PBDC_INIT;
    PORT.PBDC9 = _PORT_PBDC_INIT;
    PORT.PBDC10 = _PORT_PBDC_INIT;
    PORT.APM0 = _PORT_APM_INIT;
    PORT.APM1 = _PORT_APM_INIT;
    PORT.PM0 = _PORT_PM_INIT;
    PORT.PM8 = _PORT_PM_INIT;
    PORT.PM9 = _PORT_PM_INIT;
    PORT.PM10 = _PORT_PM_INIT;
    PORT.PMC0 = _PORT_PMC_INIT;
    PORT.PMC8 = _PORT_PMC_INIT;
    PORT.PMC9 = _PORT_PMC_INIT;
    PORT.PMC10 = _PORT_PMC_INIT;
    PORT.PIPC0= _PORT_PIPC_INIT;
    PORT.PIPC10= _PORT_PIPC_INIT;
    /* Analog Port0 setting */
    PORT.APBDC0 = _PORT_APBDCn7_APBDC_MODE_DISABLED | _PORT_APBDCn5_APBDC_MODE_DISABLED | 
                  _PORT_APBDCn4_APBDC_MODE_DISABLED | _PORT_APBDCn1_APBDC_MODE_DISABLED;
    PORT.AP0 = _PORT_APn7_OUTPUT_HIGH | _PORT_APn5_OUTPUT_HIGH | _PORT_APn4_OUTPUT_LOW | _PORT_APn1_OUTPUT_HIGH;
    PORT.APM0 = _PORT_APMn15_MODE_UNUSED | _PORT_APMn14_MODE_UNUSED | _PORT_APMn13_MODE_UNUSED | 
                _PORT_APMn12_MODE_UNUSED | _PORT_APMn11_MODE_UNUSED | _PORT_APMn10_MODE_UNUSED | 
                _PORT_APMn9_MODE_UNUSED | _PORT_APMn8_MODE_UNUSED | _PORT_APMn7_MODE_OUTPUT | 
                _PORT_APMn6_MODE_UNUSED | _PORT_APMn5_MODE_OUTPUT | _PORT_APMn4_MODE_OUTPUT | 
                _PORT_APMn3_MODE_UNUSED | _PORT_APMn2_MODE_UNUSED | _PORT_APMn1_MODE_OUTPUT | _PORT_APMn0_MODE_UNUSED;
    /* Analog Port1 setting */
    PORT.APBDC1 = _PORT_APBDCn7_APBDC_MODE_DISABLED | _PORT_APBDCn3_APBDC_MODE_DISABLED | 
                  _PORT_APBDCn0_APBDC_MODE_DISABLED;
    PORT.AP1 = _PORT_APn7_OUTPUT_HIGH | _PORT_APn3_OUTPUT_LOW | _PORT_APn2_OUTPUT_HIGH | _PORT_APn0_OUTPUT_LOW;
    PORT.APM1 = _PORT_APM1_DEFAULT_VALUE | _PORT_APMn7_MODE_OUTPUT | _PORT_APMn6_MODE_UNUSED | 
                _PORT_APMn5_MODE_UNUSED | _PORT_APMn4_MODE_UNUSED | _PORT_APMn3_MODE_OUTPUT | 
                _PORT_APMn2_MODE_UNUSED | _PORT_APMn1_MODE_UNUSED | _PORT_APMn0_MODE_OUTPUT;
    /* Port0 setting */
    PORT.PU0 = _PORT_PUn14_PULLUP_OFF | _PORT_PUn13_PULLUP_OFF | _PORT_PUn12_PULLUP_OFF | _PORT_PUn11_PULLUP_OFF | 
               _PORT_PUn10_PULLUP_OFF | _PORT_PUn9_PULLUP_OFF | _PORT_PUn8_PULLUP_ON | _PORT_PUn7_PULLUP_OFF | 
               _PORT_PUn6_PULLUP_OFF | _PORT_PUn5_PULLUP_OFF | _PORT_PUn4_PULLUP_OFF | _PORT_PUn3_PULLUP_OFF | 
               _PORT_PUn2_PULLUP_OFF | _PORT_PUn1_PULLUP_OFF | _PORT_PUn0_PULLUP_OFF;
    PORT.PD0 = _PORT_PDn12_PULLDOWN_OFF | _PORT_PDn11_PULLDOWN_OFF | _PORT_PDn10_PULLDOWN_OFF | 
               _PORT_PDn9_PULLDOWN_OFF | _PORT_PDn7_PULLDOWN_OFF | _PORT_PDn6_PULLDOWN_OFF | _PORT_PDn5_PULLDOWN_OFF | 
               _PORT_PDn4_PULLDOWN_OFF | _PORT_PDn3_PULLDOWN_OFF | _PORT_PDn2_PULLDOWN_OFF | _PORT_PDn1_PULLDOWN_OFF | 
               _PORT_PDn0_PULLDOWN_OFF;
    PORT.PM0 = _PORT_PM0_DEFAULT_VALUE | _PORT_PMn14_MODE_UNUSED | _PORT_PMn13_MODE_UNUSED | _PORT_PMn12_MODE_UNUSED | 
               _PORT_PMn11_MODE_UNUSED | _PORT_PMn10_MODE_UNUSED | _PORT_PMn9_MODE_UNUSED | _PORT_PMn8_MODE_UNUSED | 
               _PORT_PMn7_MODE_UNUSED | _PORT_PMn6_MODE_UNUSED | _PORT_PMn5_MODE_UNUSED | _PORT_PMn4_MODE_UNUSED | 
               _PORT_PMn3_MODE_UNUSED | _PORT_PMn2_MODE_UNUSED | _PORT_PMn1_MODE_UNUSED | _PORT_PMn0_MODE_UNUSED;
    /* Port8 setting */
    PORT.PPCMD8 = _WRITE_PROTECT_COMMAND;
    PORT.PODC8 = _PORT_PODCn9_PUSH_PULL | _PORT_PODCn8_PUSH_PULL | _PORT_PODCn6_PUSH_PULL | _PORT_PODCn4_PUSH_PULL | 
                 _PORT_PODCn1_PUSH_PULL;
    PORT.PODC8 = (uint32_t) ~(_PORT_PODCn9_PUSH_PULL | _PORT_PODCn8_PUSH_PULL | _PORT_PODCn6_PUSH_PULL | 
                 _PORT_PODCn4_PUSH_PULL | _PORT_PODCn1_PUSH_PULL);
    PORT.PODC8 = _PORT_PODCn9_PUSH_PULL | _PORT_PODCn8_PUSH_PULL | _PORT_PODCn6_PUSH_PULL | _PORT_PODCn4_PUSH_PULL | 
                 _PORT_PODCn1_PUSH_PULL;
    PORT.PBDC8 = _PORT_PBDCn9_PBDC_MODE_DISABLED | _PORT_PBDCn8_PBDC_MODE_DISABLED | _PORT_PBDCn6_PBDC_MODE_DISABLED | 
                 _PORT_PBDCn4_PBDC_MODE_DISABLED | _PORT_PBDCn1_PBDC_MODE_DISABLED;
    PORT.PU8 = _PORT_PUn12_PULLUP_OFF | _PORT_PUn11_PULLUP_OFF | _PORT_PUn10_PULLUP_OFF | _PORT_PUn7_PULLUP_OFF | 
               _PORT_PUn3_PULLUP_OFF | _PORT_PUn2_PULLUP_OFF | _PORT_PUn0_PULLUP_OFF;
    PORT.PD8 = _PORT_PDn12_PULLDOWN_OFF | _PORT_PDn11_PULLDOWN_OFF | _PORT_PDn10_PULLDOWN_OFF | 
               _PORT_PDn7_PULLDOWN_OFF | _PORT_PDn5_PULLDOWN_ON | _PORT_PDn3_PULLDOWN_OFF | _PORT_PDn2_PULLDOWN_OFF | 
               _PORT_PDn0_PULLDOWN_OFF;
    PORT.PIS8 = _PORT_PIS8_DEFAULT_VALUE | _PORT_PISn12_TYPE_SHMT4 | _PORT_PISn11_TYPE_SHMT4 | 
                _PORT_PISn10_TYPE_SHMT4 | _PORT_PISn7_TYPE_SHMT4 | _PORT_PISn5_TYPE_SHMT4 | _PORT_PISn3_TYPE_SHMT4 | 
                _PORT_PISn2_TYPE_SHMT4 | _PORT_PISn0_TYPE_SHMT4;
    PORT.P8 = _PORT_Pn9_OUTPUT_HIGH | _PORT_Pn8_OUTPUT_HIGH | _PORT_Pn6_OUTPUT_HIGH | _PORT_Pn4_OUTPUT_HIGH | 
              _PORT_Pn1_OUTPUT_LOW;
    PORT.PM8 = _PORT_PM8_DEFAULT_VALUE | _PORT_PMn12_MODE_UNUSED | _PORT_PMn11_MODE_UNUSED | _PORT_PMn10_MODE_INPUT | 
               _PORT_PMn9_MODE_OUTPUT | _PORT_PMn8_MODE_OUTPUT | _PORT_PMn7_MODE_UNUSED | _PORT_PMn6_MODE_OUTPUT | 
               _PORT_PMn5_MODE_UNUSED | _PORT_PMn4_MODE_OUTPUT | _PORT_PMn3_MODE_UNUSED | _PORT_PMn2_MODE_UNUSED | 
               _PORT_PMn1_MODE_OUTPUT | _PORT_PMn0_MODE_UNUSED;
    PORT.PIBC8 = _PORT_PIBCn10_INPUT_BUFFER_ENABLE;
    /* Port9 setting */
    PORT.PPCMD9 = _WRITE_PROTECT_COMMAND;
    PORT.PODC9 = _PORT_PODCn0_PUSH_PULL;
    PORT.PODC9 = (uint32_t) ~_PORT_PODCn0_PUSH_PULL;
    PORT.PODC9 = _PORT_PODCn0_PUSH_PULL;
    PORT.PBDC9 = _PORT_PBDCn0_PBDC_MODE_DISABLED;
    PORT.P9 = _PORT_Pn0_OUTPUT_HIGH;
    PORT.PM9 = _PORT_PM9_DEFAULT_VALUE | _PORT_PMn6_MODE_UNUSED | _PORT_PMn5_MODE_UNUSED | _PORT_PMn4_MODE_UNUSED | 
               _PORT_PMn3_MODE_UNUSED | _PORT_PMn2_MODE_UNUSED | _PORT_PMn1_MODE_UNUSED | _PORT_PMn0_MODE_OUTPUT;
    /* Port10 setting */
    PORT.PU10 = _PORT_PUn15_PULLUP_OFF | _PORT_PUn14_PULLUP_OFF | _PORT_PUn13_PULLUP_OFF | _PORT_PUn12_PULLUP_OFF | 
                _PORT_PUn11_PULLUP_OFF | _PORT_PUn10_PULLUP_OFF | _PORT_PUn9_PULLUP_OFF | _PORT_PUn8_PULLUP_OFF | 
                _PORT_PUn7_PULLUP_OFF | _PORT_PUn6_PULLUP_OFF | _PORT_PUn5_PULLUP_OFF | _PORT_PUn4_PULLUP_OFF | 
                _PORT_PUn3_PULLUP_ON | _PORT_PUn2_PULLUP_ON | _PORT_PUn1_PULLUP_OFF | _PORT_PUn0_PULLUP_OFF;
    PORT.PD10 = _PORT_PDn15_PULLDOWN_OFF | _PORT_PDn14_PULLDOWN_OFF | _PORT_PDn13_PULLDOWN_OFF | 
                _PORT_PDn12_PULLDOWN_OFF | _PORT_PDn11_PULLDOWN_OFF | _PORT_PDn10_PULLDOWN_OFF | 
                _PORT_PDn9_PULLDOWN_OFF | _PORT_PDn8_PULLDOWN_OFF | _PORT_PDn7_PULLDOWN_OFF | 
                _PORT_PDn6_PULLDOWN_OFF | _PORT_PDn5_PULLDOWN_OFF | _PORT_PDn4_PULLDOWN_OFF | 
                _PORT_PDn1_PULLDOWN_OFF | _PORT_PDn0_PULLDOWN_OFF;
    PORT.PM10 = _PORT_PMn15_MODE_UNUSED | _PORT_PMn14_MODE_UNUSED | _PORT_PMn13_MODE_UNUSED | 
                _PORT_PMn12_MODE_UNUSED | _PORT_PMn11_MODE_UNUSED | _PORT_PMn10_MODE_UNUSED | _PORT_PMn9_MODE_UNUSED | 
                _PORT_PMn8_MODE_UNUSED | _PORT_PMn7_MODE_UNUSED | _PORT_PMn6_MODE_UNUSED | _PORT_PMn5_MODE_UNUSED | 
                _PORT_PMn4_MODE_UNUSED | _PORT_PMn3_MODE_UNUSED | _PORT_PMn2_MODE_UNUSED | _PORT_PMn1_MODE_UNUSED | 
                _PORT_PMn0_MODE_UNUSED;
    /* Synchronization processing */
    g_cg_sync_read = PORT.APM0;
    __syncp();
}

/* Start user code for adding. Do not edit comment generated here */

void R_APORT0_SetCAN1(void)
{
    uint32_t i;
    
    PORT.AP0   |= (1u<<1);   // _PORT_APn1_OUTPUT_HIGH;
    PORT.APM0  &= ~(1u<<1);
	
    /* Analog Port1 setting STB */
    PORT.AP1   &= ~(1u<<2);  // _PORT_APn2_OUTPUT_LOW;
    PORT.APM1  &= ~(1u<<2);
    
    /* Port9 setting */
    PORT.P9   &= ~ (1u<<0);  // _PORT_Pn0_OUTPUT_LOW;
    PORT.PM9  &= ~(1u<<0);
	
    for(i=0;i<10000;i++);
	
    /* Analog Port1 setting STB */
    PORT.AP1   |= (1u<<2);  // _PORT_APn2_OUTPUT_HIGH;
    PORT.APM1  &= ~(1u<<2);
    /* Port9 setting */
    PORT.P9   |= (1u<<0);  // _PORT_Pn0_OUTPUT_HIGH;
    PORT.PM9  &= ~(1u<<0);
}


void R_APORT0_SleepLCD(void)
{
    //uint32_t i;
    /* Analog Port0 setting */
    //PORT.AP0   &= ~(1u<<7);  // _PORT_APn7_OUTPUT_LOW;
    //PORT.APM0  &= ~(1u<<7);
    
    //for(i=0;i<2*80000;i++);

    //PORT.P8 = _PORT_Pn9_OUTPUT_HIGH;
    PORT.P8 |= (1u<<9);
    PORT.PM8 &= ~(1u<<9);
    
}

/* Start user code for adding. Do not edit comment generated here */
void R_APORT0_WakeupLCD(void)
{
    //uint32_t i;
    /* Analog Port0 setting */
    //PORT.AP0   |= (1u<<7);  // _PORT_APn7_OUTPUT_HIGH;
    //PORT.APM0  &= ~(1u<<7);
	
    //for(i=0;i<2*80000;i++);

    //PORT.P8 = _PORT_Pn9_OUTPUT_HIGH;
    PORT.P8 &= ~(1u<<9);
    PORT.PM8 &= ~(1u<<9);
    
}

void R_APORT0_ResetLCD(void)
{
    uint32_t i;
    /* Analog Port0 setting */
    PORT.AP0   &= ~(1u<<7);  // _PORT_APn7_OUTPUT_LOW;
    PORT.APM0  &= ~(1u<<7);
	//PORT.APMC0 &= ~(1u<<7);
	
    

    //if(Level == Low)
    //{
    //    *PortList[Port].P_Reg &= ~(1u<<Pin);
    //}
    //else /* Level = High */
    //{
    //    *PortList[Port].P_Reg |= (1u<<Pin);
    //}
    //*PortList[Port].PM_Reg &= ~(1u<<Pin);
    //*PortList[Port].PMC_Reg &= ~(1u<<Pin);


    //PORT.P8 = _PORT_Pn9_OUTPUT_HIGH;
    PORT.P8 |= (1u<<9);
    PORT.PM8 &= ~(1u<<9);

    
    for(i=0;i<2*80000;i++);

    PORT.AP0   |= (1u<<7);  // _PORT_APn7_OUTPUT_HIGH;
    PORT.APM0  &= ~(1u<<7);
	//PORT.APMC0 &= ~(1u<<7);
    
    
    for(i=0;i<2*80000;i++);
    //PORT.P8 = _PORT_Pn9_OUTPUT_LOW;
    PORT.P8 &= ~(1u<<9);
    PORT.PM8 &= ~(1u<<9);
    
}

void R_PORT8_Set1000mA(void)
{
    /* Port8 setting */
    
    PORT.P8 |= (1u<<6);     // PORT_Pn6_OUTPUT_HIGH
    PORT.P8 &= ~(1u<<8);    // PORT_Pn8_OUTPUT_LOW
    PORT.PM8 &= ~(1u<<6);
    PORT.PM8 &= ~(1u<<8);
}

void R_PORT8_Set350mA(void)
{
    /* Port8 setting */
    PORT.P8 &= ~(1u<<6);    // PORT_Pn6_OUTPUT_LOW
    PORT.P8 |= (1u<<8);     // PORT_Pn8_OUTPUT_HIGH
    PORT.PM8 &= ~(1u<<6);
    PORT.PM8 &= ~(1u<<8);  
}


void R_PROT_ResetLEDInit(void)
{  
    uint32_t i = 0;
    PORT.P8 &= ~(1u<<1);    // PORT_Pn1_OUTPUT_low
    PORT.P8 |= (1u<<4);     // PORT_Pn4_OUTPUT_high
    PORT.PM8 &= ~(1u<<1);
    PORT.PM8 &= ~(1u<<4);
    
    for(i=0;i<2*8000000;i++);
    
    /*set low voltage*/
    PORT.P8 |= (1u<<1);    // PORT_Pn1_OUTPUT_high
    PORT.P8 &= ~(1u<<4);     // PORT_Pn4_OUTPUT_low
    PORT.PM8 &= ~(1u<<1);
    PORT.PM8 &= ~(1u<<4);
}

void R_PROT_Init(void)
{
    /*set high voltage*/
    PORT.P8 |= (1u<<1);    // PORT_Pn1_OUTPUT_high   on
    PORT.P8 &= ~(1u<<4);     // PORT_Pn4_OUTPUT_low  on
    PORT.PM8 &= ~(1u<<1);
    PORT.PM8 &= ~(1u<<4);
}

void R_PORT_ReInit(void)
{
    /*set low voltage*/
    PORT.P8 &= ~(1u<<1);    // PORT_Pn1_OUTPUT_low  off 
    PORT.P8 |= (1u<<4);     // PORT_Pn4_OUTPUT_high  off
    PORT.PM8 &= ~(1u<<1);
    PORT.PM8 &= ~(1u<<4);
	
    PORT.APIBC0 &= ~(1u<<1);
    PORT.APM0 |= (1u<<1);
    
    PORT.APIBC0 &= ~(1u<<5);
    PORT.APM0 |= (1u<<5);
    
    PORT.APIBC0 &= ~(1u<<7);
    PORT.APM0 |= (1u<<7);
    
    PORT.PIBC8 &= ~(1u<<9);
    PORT.PM8 |= (1u<<9);
    
    PORT.PIBC8 &= ~(1u<<6);
    PORT.PM8 |= (1u<<6);
    
    PORT.PIBC8 &= ~(1u<<8);
    PORT.PM8 |= (1u<<8);
    
    PORT.PIBC9 &= ~(1u<<0);
    PORT.PM9 |= (1u<<0);

}

uint8_t r_Port8_Get10Level(void)
{
    uint16_t PortLevel;
    
    PortLevel = PORT.PPR8;
    PortLevel &= 1<<10;
  
    if(PortLevel == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void r_Port8_Set10Input(void)
{
     PORT.PM8 |= 1<<10;
     PORT.PIBC8 |= 1<<10;
     PORT.PMC8 &= ~(1u<<10);
}

/* End user code. Do not edit comment generated here */
