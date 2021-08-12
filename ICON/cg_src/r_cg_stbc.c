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
* File Name    : r_cg_stbc.c
* Version      : Code Generator for RH850/F1K V1.01.00.02 [19 Apr 2017]
* Device(s)    : R7F701582(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for STBC module.
* Creation Date: 2021/6/30
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
#include "r_cg_stbc.h"
/* Start user code for include. Do not edit comment generated here */
#include "iodefine.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
#define WAKEUP_INTP11               (11U)
#define WAKEUP_INTP15               (15U)

/* Defines for filter settings */
#define R_FCLA_LEVEL_DETECTION      (0x00)
#define R_FCLA_LOW_LEVEL            (0x00)
#define R_FCLA_HIGH_LEVEL           (0x01)
#define R_FCLA_EDGE_DETECTION       (0x04)
#define R_FCLA_FALLING_EDGE         (0x02)
#define R_FCLA_RISING_EDGE          (0x01)

/* Enumeration for analog filter signals */
enum fcla_signal_t
{
    R_FCLA_INTP0 = 0,
    R_FCLA_INTP1,
    R_FCLA_INTP2,
    R_FCLA_INTP3,
    R_FCLA_INTP4,
    R_FCLA_INTP5,
    R_FCLA_INTP6,
    R_FCLA_INTP7,
    R_FCLA_INTP8,
    R_FCLA_INTP9,
    R_FCLA_INTP10,
    R_FCLA_INTP11,
    R_FCLA_INTP12,
    R_FCLA_INTP13,
    R_FCLA_INTP14,
    R_FCLA_INTP15,
    R_FCLA_NMI = 0x10
};

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_STBC_Prepare_Deep_Stop_Mode
* Description  : This function Prepare Deep Stop Mode.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_STBC_Prepare_Deep_Stop_Mode(void)
{
    /* Change the waiting time according to the system */
    R_STBC_Prepare_Deep_Stop_Mode_Set_Peripheral();
    /* Disable interrupts */
   // DI();
    /* Change the waiting time according to the system */
    R_STBC_Prepare_Deep_Stop_Mode_Set_Interrupt();
    /* Clear wake-up factor */
    STBC_WUF0.WUFC0 = 0xffffffffu; //_STBC_WUF0_CLEAR_144PIN;
    STBC_WUF20.WUFC20 = 0xffffffffu; //_STBC_WUF20_CLEAR_144PIN;
    STBC_WUFISO.WUFC_ISO0 =  0xffffffffu;
	
    /* Enable wake-up factor */
    STBC_WUF0.WUFMSK0 = ~(((uint32_t)(1<<31))|((uint32_t)(1<<27)));//_STBC_FACTOR_DEFAULT_VALUE & _STBC_WUF0_FACTOR_INTP11 & 0x7FFFFFFFU;
    STBC_WUF20.WUFMSK20 = 0xffffffffu;
    STBC_WUFISO.WUFMSK_ISO0 = 0xffffffffu;
    /* Clear reset flag */
    RESCTL.RESFC |= 0x000007ffU; // _RESFC_RESET_FLAG_CLEAR;  //0x000007ffU;
}


/***********************************************************************************************************************
* Function Name: R_STBC_Start_Deep_Stop_Mode
* Description  : This function Start Deep Stop Mode.
* Arguments    : value -
*                    counter value
* Return Value : None
***********************************************************************************************************************/
void R_STBC_Start_Deep_Stop_Mode(void)
{
    WPROTR.PROTCMD0 = _WRITE_PROTECT_COMMAND;
    STBC0.PSC = _STBC_DEEP_STOP_MODE_ENTERED;
    STBC0.PSC = (uint32_t) ~_STBC_DEEP_STOP_MODE_ENTERED;
    STBC0.PSC = _STBC_DEEP_STOP_MODE_ENTERED;
    R_STBC_Deep_Stop_Loop();

}
/***********************************************************************************************************************
* Function Name: R_STBC_Deep_Stop_Loop
* Description  : This function Deep Stop Loop.
* Arguments    : value -
*                    counter value
* Return Value : None
***********************************************************************************************************************/
void R_STBC_Deep_Stop_Loop(void)
{
    /* Start user code for global. Do not edit comment generated here */
    while (1U) 
    {
    }
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
uint32_t R_STBC_GetResfvalue(void)
{
    uint32_t resfregister = RESCTL.RESF;
    return resfregister;
}


/*****************************************************************************
** Function:    R_STBC_GetWakeUpFactor
** Description: This function returns the WakeUpFactor register.
** Parameter:   None
** Return:      WUF0 - WakeUpFactor register
******************************************************************************/
uint32_t R_STBC_GetWakeUpFactor(void)
{
    return STBC_WUF0.WUF0 ;
}

/*****************************************************************************
** Function:    R_STBC_ReleaseIoHold
** Description: This function releases the IO Hold function of ISO ports.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_STBC_ReleaseIoHold(void)
{
  /* Release I/O-Hold Buffer */
    WPROTR.PROTCMD0 = _WRITE_PROTECT_COMMAND;
    STBC_IOHOLD.IOHOLD = _STBC_IOHOLD_RELEASE;
    STBC_IOHOLD.IOHOLD = (uint32_t) ~_STBC_IOHOLD_RELEASE;
    STBC_IOHOLD.IOHOLD = _STBC_IOHOLD_RELEASE;
    
    while(STBC_IOHOLD.IOHOLD!=0x00u){}
}



/*****************************************************************************
** Function:    R_PORT_SetAnalogFilter
** Description: Sets analog filter setting.
** Parameter:   fcla_signal_t InputSignal:  R_FCLA_NMI or
**                                          R_FLCA_INTPn (n=0-15)
**
**              FilterSetting
** Return:      None
******************************************************************************/ 
void R_PORT_SetAnalogFilter(enum fcla_signal_t InputSignal, uint8_t FilterSetting)
{
    volatile uint8_t *loc_FCLA_INTP = (volatile uint8_t *)&FCLA0.CTL0_INTPL;
    
    if(InputSignal == R_FCLA_NMI)
        {
            FCLA0.CTL0_NMI = (FilterSetting&&0x07);
        }
    else
        {
            loc_FCLA_INTP += (InputSignal*4);
            *loc_FCLA_INTP = (FilterSetting&&0x07);
        }
}


/*****************************************************************************
** Function:    R_UI_INTP11_Init
** Description: Configures the port pin connected to button S1 for INTP11 usage
**              and the analog filter to falling edge detection. INTP11 is used
**              as wake-up signal in DeepSTOP.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_UI_INTP15_Init(void)
{
#if 0
    volatile uint8_t *loc_FCLA_INTP = (volatile uint8_t *)&FCLA0.CTL0_INTPL;    
    loc_FCLA_INTP += (WAKEUP_INTP11 * 4);
    *loc_FCLA_INTP = ((R_FCLA_EDGE_DETECTION||R_FCLA_RISING_EDGE)&&0x07);

    PORT.PFC10 |= (1u<<11);      
    PORT.PFCE10 &= ~(1u<<11);
    PORT.PFCAE10 &= ~(1u<<11);   
    PORT.PM10 |= (1u<<11);                         // 11 -- INTP11    Alt2  input
    PORT.PMC10 |= (1u<<11);
    
 #else
    volatile uint8_t *loc_FCLA_INTP = (volatile uint8_t *)&FCLA0.CTL0_INTPL;    
    loc_FCLA_INTP += (WAKEUP_INTP15 * 4);
    *loc_FCLA_INTP = ((R_FCLA_EDGE_DETECTION||R_FCLA_RISING_EDGE)&&0x07); 
    
//  R_PORT_SetAnalogFilter(R_FCLA_INTP15,(R_FCLA_EDGE_DETECTION||R_FCLA_RISING_EDGE));

    PORT.PFC1 |= (1u<<4);      
    PORT.PFCE1 &= ~(1u<<4);
    PORT.PFCAE1 &= ~(1u<<4);   
    PORT.PM1 |= (1u<<4);                         // 1-4 -- INTP15    Alt2  input
    PORT.PMC1 |= (1u<<4);
#endif
}

/* End user code. Do not edit comment generated here */
