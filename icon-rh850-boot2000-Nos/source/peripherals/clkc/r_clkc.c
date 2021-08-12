/*===========================================================================*/
/* Project:  F1x StarterKit V3 Sample Software                               */
/* Module :  r_clkc.c                                                        */
/* Version:  V1.00                                                           */
/*===========================================================================*/
/*                                  COPYRIGHT                                */
/*===========================================================================*/
/* Copyright (c) 2016 by Renesas Electronics Europe GmbH,                    */
/*               a company of the Renesas Electronics Corporation            */
/*===========================================================================*/
/* In case of any question please do not hesitate to contact:                */
/*                                                                           */
/*        ABG Software Tool Support                                          */
/*                                                                           */
/*        Renesas Electronics Europe GmbH                                    */
/*        Arcadiastrasse 10                                                  */
/*        D-40472 Duesseldorf, Germany                                       */
/*                                                                           */
/*        e-mail: software_support-eu@lm.renesas.com                         */
/*        FAX:   +49 - (0)211 / 65 03 - 11 31                                */
/*                                                                           */
/*===========================================================================*/
/* Warranty Disclaimer                                                       */
/*                                                                           */
/* Because the Product(s) is licensed free of charge, there is no warranty   */
/* of any kind whatsoever and expressly disclaimed and excluded by Renesas,  */
/* either expressed or implied, including but not limited to those for       */
/* non-infringement of intellectual property, merchantability and/or         */
/* fitness for the particular purpose.                                       */
/* Renesas shall not have any obligation to maintain, service or provide bug */
/* fixes for the supplied Product(s) and/or the Application.                 */
/*                                                                           */
/* Each User is solely responsible for determining the appropriateness of    */
/* using the Product(s) and assumes all risks associated with its exercise   */
/* of rights under this Agreement, including, but not limited to the risks   */
/* and costs of program errors, compliance with applicable laws, damage to   */
/* or loss of data, programs or equipment, and unavailability or             */
/* interruption of operations.                                               */
/*                                                                           */
/* Limitation of Liability                                                   */
/*                                                                           */
/* In no event shall Renesas be liable to the User for any incidental,       */
/* consequential, indirect, or punitive damage (including but not limited    */
/* to lost profits) regardless of whether such liability is based on breach  */
/* of contract, tort, strict liability, breach of warranties, failure of     */
/* essential purpose or otherwise and even if advised of the possibility of  */
/* such damages. Renesas shall not be liable for any services or products    */
/* provided by third party vendors, developers or consultants identified or  */
/* referred to the User by Renesas in connection with the Product(s) and/or  */
/* the Application.                                                          */
/*                                                                           */
/*===========================================================================*/
/* History:                                                                  */
/*              V1.00: Initial version                                       */
/*                                                                           */
/*===========================================================================*/
/*                                                                           */
/* Source code for the clock controller configurations.                      */
/*                                                                           */
/*===========================================================================*/


/*===========================================================================*/
/* Includes */
/*===========================================================================*/
#include "r_device.h"
#include "r_clkc.h"                 

/*===========================================================================*/
/* Functions */
/*===========================================================================*/
/*****************************************************************************
** Function:    R_CLKC_PllInit
** Description: This function generates 120MHz CPU CLK and 80MHz PeripheralPLL CLK.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_CLKC_PllInit(void)
{ 
    /* Prepare 16MHz MainOsc */
  if((CLKCTLMOSCS&0x04u) != 0x4u)                                       /* Check if MainOsc needs to be started */
  {
   CLKCTLMOSCC=0x06;                                                    /* Set MainOSC gain for 16MHz */
   CLKCTLMOSCST= 0x0001FFFFUL;//;0x00008000;                                             /* Set MainOSC stabilization time to ~4.1ms */
   protected_write(WPROTRPROTCMD0,WPROTRPROTS0,CLKCTLMOSCE,0x01u);      /* Trigger Enable (protected write) */
   while ((CLKCTLMOSCS&0x04u) != 0x04u);                                /* Wait for active MainOSC */
  }

  if((CLKCTLPLLS&0x04u) != 0x04u)                                       /* Check if PLL needs to be started */
  {
    /* Prepare PLL*/
    CLKCTLPLLC=0x0001083B;//0x00000213UL;//0x00010B3B;                  /* 16 MHz MainOSC -> 80MHz PLL */
    protected_write(WPROTRPROTCMD1,WPROTRPROTS1,CLKCTLPLLE,0x01u);      /* Enable PLL */
    while((CLKCTLPLLS&0x04u) != 0x04u){}                                /* Wait for active PLL */
  }
  
  /* CPLLOUT = VCOOUT ¡Á 1/4 = 120 MHz (for Premium Device) */
  protected_write(WPROTRPROTCMD1,WPROTRPROTS1,CLKCTLCKSC_CPUCLKD_CTL,0x11);//0x01);//0x11);
  while(CLKCTLCKSC_CPUCLKD_ACT!=0x11);  
  
  /* CPLLOUT -> CPU Clock */ 
  protected_write(WPROTRPROTCMD1,WPROTRPROTS1,CLKCTLCKSC_CPUCLKS_CTL,0x03u);
  while(CLKCTLCKSC_CPUCLKS_ACT!=0x03u);
  
  /* PPLLOUT -> PPLLCLK = 80MHz */
  protected_write(WPROTRPROTCMD1,WPROTRPROTS1,CLKCTLCKSC_PPLLCLKS_CTL,0x3);
  while(CLKCTLCKSC_PPLLCLKS_ACT!=0x3);  
}

/*****************************************************************************
** Function:    R_CLKC_SetRscanClockDomain
** Description: Select the RS-CAN Module Clock and the Communication Clock.
** Parameter:   RscanModuleClockDomain - Clock for operation of the CAN module itself.
**              RscanComClockDomain - Clock used for the communication speed setting.
** Return:      None
******************************************************************************/
void R_CLKC_SetRscanClockDomain(uint32_t RscanModuleClockDomain, uint32_t RscanComClockDomain)
{
  /* Select RS-CAN Module Clock */
  protected_write(WPROTRPROTCMD1, WPROTRPROTS1, CLKCTLCKSC_ICANS_CTL, RscanModuleClockDomain);
  while (CLKCTLCKSC_ICANS_ACT !=RscanModuleClockDomain);

  /* Select RS-CAN Communication Clock */
  protected_write(WPROTRPROTCMD1, WPROTRPROTS1, CLKCTLCKSC_ICANOSCD_CTL, RscanComClockDomain);
  while (CLKCTLCKSC_ICANOSCD_CTL != RscanComClockDomain);
}

/*****************************************************************************
** Function:    R_CLKC_SetAdca0ClockDomain
** Description: Select the ADCA0 Clock domain.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_CLKC_SetAdca0ClockDomain(uint32_t Adca0ClockDomain)
{
  protected_write(WPROTRPROTCMD0, WPROTRPROTS0, CLKCTLCKSC_AADCAS_CTL, Adca0ClockDomain);
  while(CLKCTLCKSC_AADCAS_ACT != Adca0ClockDomain);
}

/*****************************************************************************
** Function:    R_CLKC_SetTaujClockDomain
** Description: Select the TAUJ Clock domain.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_CLKC_SetTaujClockDomain(uint32_t TaujClockDomain)
{
  protected_write(WPROTRPROTCMD0, WPROTRPROTS0, CLKCTLCKSC_ATAUJS_CTL, TaujClockDomain);
  while(CLKCTLCKSC_ATAUJS_CTL != TaujClockDomain);
}  

/*****************************************************************************
** Function:    R_CLKC_SetAdca0StopMask
** Description: Sets the stop-mask bit for the ADCA0 clock supply so it is not  
**              stopped in DeepSTOP.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_CLKC_SetAdca0StopMask(void)
{
    CLKCTLCKSC_AADCAD_STPM = R_CLKC_STOPMASK_SET;
}

/*****************************************************************************
** Function:    R_CLKC_ResetAdca0StopMask
** Description: Resets the stop-mask bit for the ADCA0 clock supply so it is  
**              stopped in DeepSTOP.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_CLKC_ResetAdca0StopMask(void)
{
    CLKCTLCKSC_AADCAD_STPM = R_CLKC_STOPMASK_RESET;
}

/*****************************************************************************
** Function:    R_CLKC_SetTaujStopMask
** Description: Sets the stop-mask bit for the TAUJ clock supply so it is not  
**              stopped in DeepSTOP.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_CLKC_SetTaujStopMask(void)
{
    CLKCTLCKSC_ATAUJD_STPM = R_CLKC_STOPMASK_SET;
}

/*****************************************************************************
** Function:    R_CLKC_ResetTaujStopMask
** Description: Resets the stop-mask bit for the TAUJ clock supply so it is  
**              stopped in DeepSTOP.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_CLKC_ResetTaujStopMask(void)
{
    CLKCTLCKSC_ATAUJD_STPM = R_CLKC_STOPMASK_RESET;
}

