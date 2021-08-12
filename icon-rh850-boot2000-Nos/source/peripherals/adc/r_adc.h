/*===========================================================================*/
/* Project:  F1x StarterKit V3 Sample Software                               */
/* Module :  r_adc.h                                                         */
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
#ifndef R_ADC_H
#define R_ADC_H

/*===========================================================================*/
/* Defines */
/*===========================================================================*/
/* Enumeration for analog pins of anlog port AP0 */
enum APorts
{
    AP0_0 = 0,
    AP0_1,
    AP0_2,
    AP0_3,
    AP0_4,
    AP0_5,
    AP0_6,
    AP0_7,
    AP0_8,
    AP0_9,
    AP0_10,
    AP0_11,
    AP0_12,
    AP0_13,
    AP0_14,
    AP0_15
};

//ADC0
#define AD0_MCU_TEMP        (5u)     /*ADC0_SE5  PTB1*/
#define AD0_BATT            (7u)     /*ADC0_SE6  PTB2*/
#define AD0_WHEEL1          (18u)    /*ADC0_SE18  PTB3*/
#define AD0_WHEEL2          (19u)    /*ADC0_SE19  PTB4*/

#define AD0_5VLDO           (12u)    /*ADC0_SE12  PTC14*/
#define AD0_SYS_5V          (13u)    /*ADC0_SE13  PTC15*/

#define AD0_HSD             (14u)    /*ADC0_SE14  PTC16*/
#define AD0_GPS_PWR         (15u)    /*ADC0_SE15  PTC17*/

/*===========================================================================*/
/* Function defines */
/*===========================================================================*/
void R_ADCA0_AssignLimitErrorCB(void (CB_Ptr)(uint32_t));
void R_ADCA0_ConnectPullDown(enum APorts AP_x);
void R_ADCA0_DisconnectPullDown(enum APorts AP0_x);
void R_ADCA0_Init(void);
uint16_t R_ADCA0_PinRead(enum APorts AP0_x);
void R_ADCA0_LpsInit(void);
void R_ADCA0_SetUpperLowerLimit(uint32_t limit_table, uint16_t upper, uint16_t lower);
void R_ADCA0_PwsaTriggerEnable(void);
void R_ADCA0_PwsaTriggerDisable(void);
uint32_t R_ADCA0_PwmDReadresult(void);

void R_ADCA1_AssignLimitErrorCB(void (CB_Ptr)(uint32_t));
void R_ADCA1_ConnectPullDown(enum APorts AP_x);
void R_ADCA1_DisconnectPullDown(enum APorts AP0_x);
void R_ADCA1_Init(void);
uint16_t R_ADCA1_PinRead(enum APorts AP0_x);
void R_ADCA1_LpsInit(void);
void R_ADCA1_SetUpperLowerLimit(uint32_t limit_table, uint16_t upper, uint16_t lower);
void R_ADCA1_PwsaTriggerEnable(void);
void R_ADCA1_PwsaTriggerDisable(void);
uint32_t R_ADCA1_PwmDReadresult(void);


#endif /* R_ADC_H */
