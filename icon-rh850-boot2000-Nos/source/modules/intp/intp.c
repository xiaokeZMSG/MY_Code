/*===========================================================================*/
/* Project:  F1x StarterKit V3 Sample Software                               */
/* Module :  intp.c                                                          */
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
/* Functions to handle user inputs on the StarterKit Board.                  */
/*                                                                           */
/*===========================================================================*/


/*===========================================================================*/
/* Includes */
/*===========================================================================*/
#include "r_device.h"
#include "intp.h"
//#include "intc.h"
#include "intc/r_intc.h"
#include "port/r_port.h"

/*===========================================================================*/
/* Defines */
/*===========================================================================*/
#define R_PRESS_SHORT         10
#define R_PRESS_LONG        1000

/*===========================================================================*/
/* Functions */
/*===========================================================================*/
/*****************************************************************************
** Function:    R_UI_Poti1_Init
** Description: Configure AP0_0 to high impedant input mode of potentiometer 
**              POT1.
** Parameter:   None
** Return:      None
******************************************************************************/
void R_Pot1_Init(void)
{ 
  R_PORT_SetAltFunc(Port8, 1, Alt3, Input);
  FCLA0CTL5_INTPL=0x01;
 // R_INTC_SetRequestFlag((uint16_t*)R_ICP5);
  R_INTC_SetTableBit((uint16_t*)R_ICP5);
  R_INTC_UnmaskInterrupt((uint16_t*)R_ICP5);
}

#ifdef __IAR__
    #pragma vector = NUMINTP5
    __interrupt void INTITP5(void)
#endif
#ifdef __GHS__
    #pragma ghs interrupt
    void INTITP5(void)
#endif
#ifdef __CSP__
  #pragma interrupt INTITP5(enable=manual)
  void INTITP5(void)
#endif /* __CSP__*/
{
   RLN35LUTDR = 0x33;// RLN35LURDR&0xff;
  // R_INTC_SetRequestFlag((uint16_t*)R_ICP5);
   R_INTC_UnmaskInterrupt((uint16_t*)R_ICP5);
}


