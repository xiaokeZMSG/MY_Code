/*===========================================================================*/
/* Project:  F1x StarterKit V3 Sample Software                               */
/* Module :  r_lps.c                                                         */
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
/* Source code for the LowPowerSampler.                                      */
/*                                                                           */
/*===========================================================================*/

/*===========================================================================*/
/* Includes */
/*===========================================================================*/
#include "r_device.h"
#include "r_lps.h"

/*===========================================================================*/
/* Functions */
/*===========================================================================*/
/*****************************************************************************
** Function:    R_LPS_Init
** Description: Configures the LPS for usage of an 8to1 multiplexer.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_LPS_Init(void)
{
  /* Set-up digital and analogue stabilization time */
  LPS0CNTVAL = 0xFFCFu;         /* AP0 stabilization time  = (1/8MHz high-speed IntOSC) × 16 × CNT(upper 8 Bits) = 0.51ms */
                                /* DP0 stabilization time  = (1/8MHz high-speed IntOSC) × 16 × CNT(lower 8 Bits) = 0.414ms */

  /* Enable comparison of the first bit of each compare register */
  LPS0DPSELR0 = 0x01u;         /* Enable D0EN_0 */
  LPS0DPSELR1 = 0x01u;         /* Enable D1EN_0 */
  LPS0DPSELR2 = 0x01u;         /* Enable D2EN_0 */
  LPS0DPSELR3 = 0x01u;         /* Enable D3EN_0 */
  LPS0DPSELR4 = 0x01u;         /* Enable D4EN_0 */
  LPS0DPSELR5 = 0x01u;         /* Enable D5EN_0 */
  LPS0DPSELR6 = 0x01u;         /* Enable D6EN_0 */
  LPS0DPSELR7 = 0x01u;         /* Enable D7EN_0 */
    
  LPS0SCTLR = 0x73u;           /* Sequence Start Trigger is INTTAUJ0I0 / read 8 times / digital/analog mode enabled */
    
  LPS0EVFR = 0u;               /* Clear event flag register */
}

/*****************************************************************************
** Function:    R_LPS_Disable
** Description: Disables LPS operation.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_LPS_Disable(void)
{
  /* Disable LPS */
  LPS0SCTLR = 0u;    
}

/*****************************************************************************
** Function:    R_LPS_SetCompareValue
** Description: Sets the bit pattern to be compared with by LPS.
** Parameter:   Compare_Value - Bit pattern to be compared.
** Return:      None
******************************************************************************/
void R_LPS_SetCompareValue(uint8_t Compare_Value)
{
  /* Reset compare registers */
  
  LPS0DPDSR0 = (Compare_Value>>0)&0x01;  /* Set D0_0 */
  LPS0DPDSR1 = (Compare_Value>>1)&0x01;  /* Set D0_1 */
  LPS0DPDSR2 = (Compare_Value>>2)&0x01;  /* Set D0_2 */
  LPS0DPDSR3 = (Compare_Value>>3)&0x01;  /* Set D0_3 */
  LPS0DPDSR4 = (Compare_Value>>4)&0x01;  /* Set D0_4 */
  LPS0DPDSR5 = (Compare_Value>>5)&0x01;  /* Set D0_5 */
  LPS0DPDSR6 = (Compare_Value>>6)&0x01;  /* Set D0_6 */
  LPS0DPDSR7 = (Compare_Value>>7)&0x01;  /* Set D0_7 */
}
