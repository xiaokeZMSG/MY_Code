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
* File Name    : r_cg_stbc.h
* Version      : Code Generator for RH850/F1K V1.01.00.02 [19 Apr 2017]
* Device(s)    : R7F701582(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for STBC module.
* Creation Date: 2021/6/30
***********************************************************************************************************************/
#ifndef STBC_H
#define STBC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Wake up factor register (WUF0)
*/
/* Indicates the generation of a wake-up event */
#define _STBC_WUF0_CLEAR_100PIN                                 (0x72FFFFE7) /* Wake-up event is not generated */
#define _STBC_WUF0_CLEAR_144PIN                                 (0xFFFFFFE7) /* Wake-up event is not generated */
#define _STBC_WUF0_CLEAR_176PIN                                 (0xFFFFFFE7) /* Wake-up event is not generated */
/*
    Wake up factor register (WUF_ISO0)
*/
/* Indicates the generation of a wake-up event */
#define _STBC_WUF_ISO0_CLEAR_100PIN                             (0x000001FE) /* Wake-up event is not generated */
#define _STBC_WUF_ISO0_CLEAR_144PIN                             (0x000001FE) /* Wake-up event is not generated */
#define _STBC_WUF_ISO0_CLEAR_176PIN                             (0x000007FE) /* Wake-up event is not generated */
/*
    Wake up factor register (WUF20)
*/
/* Indicates the generation of a wake-up event */
#define _STBC_WUF20_CLEAR_100PIN                                (0x000023FF) /* Wake-up event is not generated */
#define _STBC_WUF20_CLEAR_144PIN                                (0x0000FFFF) /* Wake-up event is not generated */
#define _STBC_WUF20_CLEAR_176PIN                                (0x0000FFFF) /* Wake-up event is not generated */
/*
    Wake up factor register (WUF0)
*/
/* Indicates the generation of a wake-up event (WUF00) */
#define _STBC_WUF0_FACTOR_TNMI                                  (0xFFFFFFFE) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF01) */
#define _STBC_WUF0_FACTOR_WDTA0NMI                              (0xFFFFFFFD) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF02) */
#define _STBC_WUF0_FACTOR_INTLVIL                               (0xFFFFFFFB) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF05) */
#define _STBC_WUF0_FACTOR_INTP0                                 (0xFFFFFFDF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF06) */
#define _STBC_WUF0_FACTOR_INTP1                                 (0xFFFFFFBF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF07) */
#define _STBC_WUF0_FACTOR_INTP2                                 (0xFFFFFF7F) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF08) */
#define _STBC_WUF0_FACTOR_INTWDTA0                              (0xFFFFFEFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF09) */
#define _STBC_WUF0_FACTOR_INTP3                                 (0xFFFFFDFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF10) */
#define _STBC_WUF0_FACTOR_INTP4                                 (0xFFFFFBFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF11) */
#define _STBC_WUF0_FACTOR_INTP5                                 (0xFFFFF7FF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF12) */
#define _STBC_WUF0_FACTOR_INTP10                                (0xFFFFEFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF13) */
#define _STBC_WUF0_FACTOR_INTP11                                (0xFFFFDFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF14) */
#define _STBC_WUF0_FACTOR_WUTRG1                                (0xFFFFBFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF15) */
#define _STBC_WUF0_FACTOR_INTTAUJ0I0                            (0xFFFF7FFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF16) */
#define _STBC_WUF0_FACTOR_INTTAUJ0I1                            (0xFFFEFFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF17) */
#define _STBC_WUF0_FACTOR_INTTAUJ0I2                            (0xFFFDFFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF18) */
#define _STBC_WUF0_FACTOR_INTTAUJ0I3                            (0xFFFBFFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF19) */
#define _STBC_WUF0_FACTOR_WUTRG0                                (0xFFF7FFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF20) */
#define _STBC_WUF0_FACTOR_INTP6                                 (0xFFEFFFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF21) */
#define _STBC_WUF0_FACTOR_INTP7                                 (0xFFDFFFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF22) */
#define _STBC_WUF0_FACTOR_INTP8                                 (0xFFBFFFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF23) */
#define _STBC_WUF0_FACTOR_INTP12                                (0xFF7FFFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF24) */
#define _STBC_WUF0_FACTOR_INTP9                                 (0xFEFFFFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF25) */
#define _STBC_WUF0_FACTOR_INTP13                                (0xFDFFFFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF26) */
#define _STBC_WUF0_FACTOR_INTP14                                (0xFBFFFFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF27) */
#define _STBC_WUF0_FACTOR_INTP15                                (0xF7FFFFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF28) */
#define _STBC_WUF0_FACTOR_INTRTCA01S                            (0xEFFFFFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF29) */
#define _STBC_WUF0_FACTOR_INTRTCA0AL                            (0xDFFFFFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF30) */
#define _STBC_WUF0_FACTOR_INTRTCA0R                             (0xBFFFFFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF31) */
#define _STBC_WUF0_FACTOR_INTDCUTDI                             (0x7FFFFFFF) /* Wake-up event is generated */
/*
    Wake up factor register (WUF_ISO0)
*/
/* Indicates the generation of a wake-up event (WUF01) */
#define _STBC_WUF_ISO0_FACTOR_INTKR0                            (0xFFFFFFFD) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF02) */
#define _STBC_WUF_ISO0_FACTOR_INTRCANGRECC0                     (0xFFFFFFFB) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF03) */
#define _STBC_WUF_ISO0_FACTOR_INTRCAN0REC                       (0xFFFFFFF7) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF04) */
#define _STBC_WUF_ISO0_FACTOR_INTRCAN1REC                       (0xFFFFFFEF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF05) */
#define _STBC_WUF_ISO0_FACTOR_INTRCAN2REC                       (0xFFFFFFDF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF06) */
#define _STBC_WUF_ISO0_FACTOR_INTRCAN3REC                       (0xFFFFFFBF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF07) */
#define _STBC_WUF_ISO0_FACTOR_INTRCAN4REC                       (0xFFFFFF7F) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF08) */
#define _STBC_WUF_ISO0_FACTOR_INTRCAN5REC                       (0xFFFFFEFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF09) */
#define _STBC_WUF_ISO0_FACTOR_INTRCANGRECC1                     (0xFFFFFDFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF10) */
#define _STBC_WUF_ISO0_FACTOR_INTRCAN6REC                       (0xFFFFFBFF) /* Wake-up event is generated */
/*
    Wake up factor register (WUF20)
*/
/* Indicates the generation of a wake-up event (WUF00) */
#define _STBC_WUF20_FACTOR_INTADCA0I0                           (0xFFFFFFFE) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF01) */
#define _STBC_WUF20_FACTOR_INTADCA0I1                           (0xFFFFFFFD) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF02) */
#define _STBC_WUF20_FACTOR_INTADCA0I2                           (0xFFFFFFFB) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF03) */
#define _STBC_WUF20_FACTOR_INTRLIN30                            (0xFFFFFFF7) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF04) */
#define _STBC_WUF20_FACTOR_INTTAUJ0I0                           (0xFFFFFFEF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF05) */
#define _STBC_WUF20_FACTOR_INTTAUJ0I1                           (0xFFFFFFDF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF06) */
#define _STBC_WUF20_FACTOR_INTTAUJ0I2                           (0xFFFFFFBF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF07) */
#define _STBC_WUF20_FACTOR_INTTAUJ0I3                           (0xFFFFFF7F) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF08) */
#define _STBC_WUF20_FACTOR_INTRLIN31                            (0xFFFFFEFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF09) */
#define _STBC_WUF20_FACTOR_INTRLIN32                            (0xFFFFFDFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF10) */
#define _STBC_WUF20_FACTOR_INTRTCA01S                           (0xFFFFFBFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF11) */
#define _STBC_WUF20_FACTOR_INTRTCA0AL                           (0xFFFFF7FF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF12) */
#define _STBC_WUF20_FACTOR_INTRTCA0R                            (0xFFFFEFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF13) */
#define _STBC_WUF20_FACTOR_INTRLIN33                            (0xFFFFDFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF14) */
#define _STBC_WUF20_FACTOR_INTRLIN34                            (0xFFFFBFFF) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF15) */
#define _STBC_WUF20_FACTOR_INTRLIN35                            (0xFFFF7FFF) /* Wake-up event is generated */

/*
    Power save control register (STBC0PSC)
*/
/* Power save control (STBC0DISTRG) */
#define _STBC_DEEP_STOP_MODE_DISABLE                            (0x00000000U) /* Writing 0 has no effect */
#define _STBC_DEEP_STOP_MODE_ENTERED                            (0x00000002U) /* DeepSTOP mode is entered */

/*
    Power stop trigger register (STBC0STPT)
*/
/* Power stop trigger (STBC0STPTRG) */
#define _STBC_STOP_MODE_DISABLE                                 (0x00000000U) /* Writing 0 has no effect */
#define _STBC_STOP_MODE_ENTERED                                 (0x00000001U) /* Stop mode is entered */

/*
    reset factor clear register (RESFC)
*/
/* Reset flag clear by DeepSTOP mode (RESFC10) */
#define _RESFC_RESET_FLAG_CLEAR                                 (0x00000400U) /* Clear reset flag */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Cycle time */
#define _STBC_WAITTIME                                          (0x5U)
#define _STBC_FACTOR_DEFAULT_VALUE                              (0xFFFFFFFF)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
#define _STBC_IOHOLD_RELEASE                                    (0x00000000U)

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_STBC_Prepare_Deep_Stop_Mode(void);
void R_STBC_Start_Deep_Stop_Mode(void);
void R_STBC_Deep_Stop_Loop(void);
void R_STBC_Prepare_Deep_Stop_Mode_Set_Peripheral(void);
void R_STBC_Prepare_Deep_Stop_Mode_Set_Interrupt(void);

/* Start user code for function. Do not edit comment generated here */
uint32_t R_STBC_GetWakeUpFactor(void);
void R_STBC_ReleaseIoHold(void);
void R_UI_INTP15_Init(void);
uint32_t R_STBC_GetResfvalue(void);
/* End user code. Do not edit comment generated here */
#endif