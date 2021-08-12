/*===========================================================================*/
/* Project:  F1x StarterKit V3 Sample Software                               */
/* Module :  r_intc.h                                                        */
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
#ifndef R_INTC_H
#define R_INTC_H

/*===========================================================================*/
/* Defines */
/*===========================================================================*/
#define R_ICADCA0I0     &INTC2.ICADCA0I0.UINT16
#define R_ICOSTM0       &INTC2.ICOSTM0.UINT16
#define R_ICTAUJ0I1     &INTC2.ICTAUJ0I1.UINT16
#define R_ICADCA0ERR    &INTC2.ICADCA0ERR.UINT16
#define R_ICRLIN30UR0   &INTC2.ICRLIN30UR0.UINT16
#define R_ICRLIN35UR0   &INTC2.ICRLIN35UR0.UINT16
#define R_ICRLIN35UR1   &INTC2.ICRLIN35UR1.UINT16
#define R_ICDMA0        &INTC2.ICDMA0.UINT16
#define R_ICDMA8        &INTC2.ICDMA8.UINT16
#define R_ICDMA9        &INTC2.ICDMA9.UINT16
#define R_ICP5          &INTC2.ICP5.UINT16
#define R_ICRIIC0TI     &INTC2.ICRIIC0TI.UINT16
#define R_ICRIIC0TEI    &INTC2.ICRIIC0TEI.UINT16
#define R_ICRIIC0RI     &INTC2.ICRIIC0RI.UINT16
#define R_ICRIIC0EE     &INTC2.ICRIIC0EE.UINT16





#define R_REQUEST_FLAG_NOT_SET  0
#define R_REQUEST_FLAG_SET      1

/*===========================================================================*/
/* Function defines */
/*===========================================================================*/
void R_INTC_MaskInterrupt(volatile uint16_t *IC_ptr);
void R_INTC_UnmaskInterrupt(volatile uint16_t *IC_ptr);
void R_INTC_SetPriority(volatile uint16_t *IC_ptr, uint8_t Priority);
void R_INTC_SetTableBit(volatile uint16_t *IC_ptr);
void R_INTC_ResetTableBit(volatile uint16_t *IC_ptr);
void R_INTC_ResetRequestFlag(volatile uint16_t *IC_ptr);
uint32_t R_INTC_GetRequestFlag(volatile uint16_t *IC_ptr);

#endif /* R_INTC_H */

