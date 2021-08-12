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
* File Name    : r_cg_adc.h
* Version      : Code Generator for RH850/F1K V1.01.00.02 [19 Apr 2017]
* Device(s)    : R7F701582(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for ADCA module.
* Creation Date: 2021/7/27
***********************************************************************************************************************/
#ifndef ADCA_H
#define ADCA_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
#define _ADC0_VCHANNEL_DATA_BASE                  (0xFFF20100U)
#define _ADC1_VCHANNEL_DATA_BASE                  (0xFFD6D100U)
/*
    Virtual channel control register (ADCAnVCRm)
*/
/* A/D Conversion End Interrupt Enable. (ADIE) */
#define _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE      (0x00000000U) /* not generated */
#define _ADC_VIRTUAL_CHANNEL_END_INT_ENABLE       (0x00000100U) /* generated */
/* Upper limit/lower limit table select (ULS[1-0]) */
#define _ADC_LIMIT_TABLE_SELECT_NONE              (0x00000000U) /* Upper limit and lower limit are not checked. */
#define _ADC_LIMIT_TABLE_SELECT_0                 (0x00000040U) /* Upper limit and lower limit are checked for ULLMTBR0. */
#define _ADC_LIMIT_TABLE_SELECT_1                 (0x00000080U) /* Upper limit and lower limit are checked for ULLMTBR1. */
#define _ADC_LIMIT_TABLE_SELECT_2                 (0x000000C0U) /* Upper limit and lower limit are checked for ULLMTBR2. */
/* A/D conversion general control (GCTRL[5-0]) */
#define _ADC_PHYSICAL_CHANNEL_AN00                (0x00000000U) /* AN00 */
#define _ADC_PHYSICAL_CHANNEL_AN01                (0x00000001U) /* AN01 */
#define _ADC_PHYSICAL_CHANNEL_AN02                (0x00000002U) /* AN02 */
#define _ADC_PHYSICAL_CHANNEL_AN03                (0x00000003U) /* AN03 */
#define _ADC_PHYSICAL_CHANNEL_AN04                (0x00000004U) /* AN04 */
#define _ADC_PHYSICAL_CHANNEL_AN05                (0x00000005U) /* AN05 */
#define _ADC_PHYSICAL_CHANNEL_AN06                (0x00000006U) /* AN06 */
#define _ADC_PHYSICAL_CHANNEL_AN07                (0x00000007U) /* AN07 */
#define _ADC_PHYSICAL_CHANNEL_AN08                (0x00000008U) /* AN08 */
#define _ADC_PHYSICAL_CHANNEL_AN09                (0x00000009U) /* AN09 */
#define _ADC_PHYSICAL_CHANNEL_AN10                (0x0000000AU) /* AN10 */
#define _ADC_PHYSICAL_CHANNEL_AN11                (0x0000000BU) /* AN11 */
#define _ADC_PHYSICAL_CHANNEL_AN12                (0x0000000CU) /* AN12 */
#define _ADC_PHYSICAL_CHANNEL_AN13                (0x0000000DU) /* AN13 */
#define _ADC_PHYSICAL_CHANNEL_AN14                (0x0000000EU) /* AN14 */
#define _ADC_PHYSICAL_CHANNEL_AN15                (0x0000000FU) /* AN15 */
#define _ADC_PHYSICAL_CHANNEL_AN16                (0x00000010U) /* AN16 */
#define _ADC_PHYSICAL_CHANNEL_AN17                (0x00000011U) /* AN17 */
#define _ADC_PHYSICAL_CHANNEL_AN18                (0x00000012U) /* AN18 */
#define _ADC_PHYSICAL_CHANNEL_AN19                (0x00000013U) /* AN19 */
#define _ADC_PHYSICAL_CHANNEL_AN20                (0x00000014U) /* AN20 */
#define _ADC_PHYSICAL_CHANNEL_AN21                (0x00000015U) /* AN21 */
#define _ADC_PHYSICAL_CHANNEL_AN22                (0x00000016U) /* AN22 */
#define _ADC_PHYSICAL_CHANNEL_AN23                (0x00000017U) /* AN23 */
#define _ADC_PHYSICAL_CHANNEL_AN24                (0x00000018U) /* AN24 */
#define _ADC_PHYSICAL_CHANNEL_AN25                (0x00000019U) /* AN25 */
#define _ADC_PHYSICAL_CHANNEL_AN26                (0x0000001AU) /* AN26 */
#define _ADC_PHYSICAL_CHANNEL_AN27                (0x0000001BU) /* AN27 */
#define _ADC_PHYSICAL_CHANNEL_AN28                (0x0000001CU) /* AN28 */
#define _ADC_PHYSICAL_CHANNEL_AN29                (0x0000001DU) /* AN29 */
#define _ADC_PHYSICAL_CHANNEL_AN30                (0x0000001EU) /* AN30 */
#define _ADC_PHYSICAL_CHANNEL_AN31                (0x0000001FU) /* AN31 */
#define _ADC_PHYSICAL_CHANNEL_AN32                (0x00000020U) /* AN32 */
#define _ADC_PHYSICAL_CHANNEL_AN33                (0x00000021U) /* AN33 */
#define _ADC_PHYSICAL_CHANNEL_AN34                (0x00000022U) /* AN34 */
#define _ADC_PHYSICAL_CHANNEL_AN35                (0x00000023U) /* AN35 */

/*
    A/D force halt register (ADCAnADHALTR)
*/
/* A/D force halt register (HALT) */
#define _ADC_HALT                                 (0x00000001U) /* Scan groups are halted */

/*
    A/D control register (ADCAnADCR)
*/
/* 12/10 Bit Select Mode (CTYP) */
#define _ADC_12_BIT_MODE                          (0x00000000U) /* 12-bit mode */
#define _ADC_10_BIT_MODE                          (0x00000010U) /* 10-bit mode */

/*
    TH sampling start control register (ADCAnTHSMPSTCR)
*/
/* TH sampling start control trigger (SMPST) */
#define _ADC_TH_SAMPLING_ALL_START                (0x00000001U) /* Sampling for all TH is started */

/*
    TH control register (ADCAnTHCR)
*/
/* Automatic sampling mask control (ASMPMSK) */
#define _ADC_TH_SAMPLING_MANUAL                   (0x00000000U) /* Automatic sampling is not performed */
#define _ADC_TH_SAMPLING_AUTOMATIC                (0x00000001U) /* Automatic sampling is performed */

/*
    TH group A/B control register (ADCAnTHABCR)
*/
/* TH group A/B hold trigger enable (HLDTE) */
#define _ADC_TH_SG_START_TRIGGER_USED             (0x00000000U) /* trigger is selected for the hold start trigger of TH group A/B */
#define _ADC_TH_SG_START_TRIGGER_UNUSED           (0x00000010U) /* trigger is not selected for the hold start trigger of TH group A/B */
/* TH group A/B scan group select (SGS[1-0]) */
#define _ADC_TH_SELECT_NONE                       (0x00000000U) /* No scan group is selected for TH group A/B */
#define _ADC_TH_SELECT_SG1                        (0x00000001U) /* SG1 is selected for TH group A/B */
#define _ADC_TH_SELECT_SG2                        (0x00000002U) /* SG2 is selected for TH group A/B */
#define _ADC_TH_SELECT_SG3                        (0x00000003U) /* SG3 is selected for TH group A/B */

/*
    TH enable register (ADCAnTHER)
*/
/* TH5 Enable (TH5E) */
#define _ADC_TH5_DISABLED                         (0x00000000U) /* TH5 is disabled */
#define _ADCn_TH5_ENABLED                         (0x00000020U) /* TH5 is enabled */
/* TH4 Enable (TH4E) */
#define _ADC_TH4_DISABLED                         (0x00000000U) /* TH4 is disabled */
#define _ADC_TH4_ENABLED                          (0x00000010U) /* TH4 is enabled */
/* TH3 Enable (TH3E) */
#define _ADC_TH3_DISABLED                         (0x00000000U) /* TH3 is disabled */
#define _ADC_TH3_ENABLED                          (0x00000008U) /* TH3 is enabled */
/* TH2 Enable (TH2E) */
#define _ADC_TH2_DISABLED                         (0x00000000U) /* TH2 is disabled */
#define _ADC_TH2_ENABLED                          (0x00000004U) /* TH2 is enabled */
/* TH1 Enable (TH1E) */
#define _ADC_TH1_DISABLED                         (0x00000000U) /* TH1 is disabled */
#define _ADC_TH1_ENABLED                          (0x00000002U) /* TH1 is enabled */
/* TH0 Enable (TH0E) */
#define _ADC_TH0_DISABLED                         (0x00000000U) /* TH0 is disabled */
#define _ADC_TH0_ENABLED                          (0x00000001U) /* TH0 is enabled */

/*
    TH group select register (ADCAnTHGSR)
*/
/* TH5 group select (TH5GS) */
#define _ADC_TH5_GROUP_A                          (0x00000000U) /* TH5 is selected to group A */
#define _ADC_TH5_GROUP_B                          (0x00000020U) /* TH5 is selected to group B */
/* TH4 group select (TH4GS) */
#define _ADC_TH4_GROUP_A                          (0x00000000U) /* TH4 is selected to group A */
#define _ADC_TH4_GROUP_B                          (0x00000010U) /* TH4 is selected to group B */
/* TH3 group select (TH3GS) */
#define _ADC_TH3_GROUP_A                          (0x00000000U) /* TH3 is selected to group A */
#define _ADC_TH3_GROUP_B                          (0x00000008U) /* TH3 is selected to group B */
/* TH2 group select (TH2GS) */
#define _ADC_TH2_GROUP_A                          (0x00000000U) /* TH2 is selected to group A */
#define _ADC_TH2_GROUP_B                          (0x00000004U) /* TH2 is selected to group B */
/* TH1 group select (TH1GS) */
#define _ADC_TH1_GROUP_A                          (0x00000000U) /* TH1 is selected to group A */
#define _ADC_TH1_GROUP_B                          (0x00000002U) /* TH1 is selected to group B */
/* TH0 group select (TH0GS) */
#define _ADC_TH0_GROUP_A                          (0x00000000U) /* TH0 is selected to group A */
#define _ADC_TH0_GROUP_B                          (0x00000001U) /* TH0 is selected to group B */

/*
    Sampling control register (ADCAnSMPCR)
*/
/* These bits are used to set the sampling time (the number of cycles) (SMPT[7-0]) */
#define _ADC_18_CYCLES                            (0x00000012U) /* 18 cycles (PCLK = 8 MHz to 32 MHz) */
#define _ADC_24_CYCLES                            (0x00000018U) /* 24 cycles (PCLK = 8 MHz to 40 MHz) */

/*
    Safety control register (ADCAnSFTCR)
*/
/* Read and clear enable (RDCLRE) */
#define _ADC_READ_CLEAR_DISABLED                  (0x00000000U) /* The A/D conversion result is not cleared by hardware */
#define _ADC_READ_CLEAR_ENABLED                   (0x00000010U) /* The A/D conversion result is cleared by hardware */
/* A/D Error Interrupt (INT_ADE) Enable on Upper/Lower Limit Error Detection (ULEIE) */
#define _ADC_LIMIT_ERROR_INT_DISABLE              (0x00000000U) /* Disabled */
#define _ADC_LIMIT_ERROR_INT_ENABLE               (0x00000008U) /* Enabled */
/* A/D Error Interrupt (INT_ADE) Enable on Overwrite Error Detection (OWEIE) */
#define _ADC_OVERWRITE_ERROR_INT_DISABLE          (0x00000000U) /* Disabled */
#define _ADC_OVERWRITE_ERROR_INT_ENABLE           (0x00000004U) /* Enabled */

/*
    Scan group 1 start control register (ADCAnSGSTCRm)
*/
/* Scan group start trigger (SGST) */
#define _ADC_START                                (0x00000001U) /* Starts the target SG */

/*
    Scan group 1 control register (ADCAnSGCRm)
*/
/* Scan mode (SCANMD) */
#define _ADC_SG_SCAN_MODE_MULTICYCLE              (0x00000000U) /* Multicycle scan mode */
#define _ADC_SG_SCAN_MODE_CONTINUOUS              (0x00000020U) /* Continuous scan mode */
/* Scan end interrupt enable (ADIE) */
#define _ADC_SG_SCAN_END_INT_DISABLE              (0x00000000U) /* INT_SG1 is not output */
#define _ADC_SG_SCAN_END_INT_ENABLE               (0x00000010U) /* INT_SG1 is output */
/* Trigger mode (TRGMD) */
#define _ADC_SG_HW_TRIGGER_DISABLE                (0x00000000U) /* Trigger input is disabled */
#define _ADC_SG_HW_TRIGGER_ENABLE                 (0x00000001U) /* Start trigger or hold complete trigger selected for the trigger input */

/*
    Scan Group 1 Multicycle Register (ADCAnSGMCYCRm)
*/
/* Multicycle number specification (MCYC[1-0]) */
#define _ADC_SG_MULTICYCLE_NUMBER_1               (0x00000000U) /* Number of scans = 1 */
#define _ADC_SG_MULTICYCLE_NUMBER_2               (0x00000001U) /* Number of scans = 2 */
#define _ADC_SG_MULTICYCLE_NUMBER_4               (0x00000003U) /* Number of scans = 4 */

/*
    A/D force halt register (ADCAnSGTSELm)
*/
/* A/D conversion hardware trigger select (T1SEL8) */
#define _ADC_SG_HW_TRIGGER_FACTOR_8               (0x00000100U) /* Connection Motor control (PIC0) trigger enabled */
/* A/D conversion hardware trigger select (T1SEL7) */
#define _ADC_SG_HW_TRIGGER_FACTOR_7               (0x00000080U) /* Connection Motor control (TAPA0) trigger enabled */
/* A/D conversion hardware trigger select (T1SEL6) */
#define _ADC_SG_HW_TRIGGER_FACTOR_6               (0x00000040U) /* Connection Motor control (TAPA0) trigger enabled */
/* A/D conversion hardware trigger select (T1SEL5) */
#define _ADC_SG_HW_TRIGGER_FACTOR_5               (0x00000020U) /* Connection ENCA0 trigger enabled */
/* A/D conversion hardware trigger select (T1SEL4) */
#define _ADC_SG_HW_TRIGGER_FACTOR_4               (0x00000010U) /* Connection LPS trigger enabled */
/* A/D conversion hardware trigger select (T1SEL3) */
#define _ADC_SG_HW_TRIGGER_FACTOR_3               (0x00000008U) /* Connection TAUD0 trigger enabled */
/* A/D conversion hardware trigger select (T1SEL2) */
#define _ADC_SG_HW_TRIGGER_FACTOR_2               (0x00000004U) /* Connection TAUD0 trigger enabled */
/* A/D conversion hardware trigger select (T1SEL1) */
#define _ADC_SG_HW_TRIGGER_FACTOR_1               (0x00000002U) /* Connection TAUJ0 trigger enabled */
/* A/D conversion hardware trigger select (T1SEL0) */
#define _ADC_SG_HW_TRIGGER_EXTERNAL_PIN           (0x00000001U) /* Connection External trigger pin trigger enabled */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _ADC0_UPPER_LIMIT_TABLE0                  (0xFFF00000U)
#define _ADC0_LOWER_LIMIT_TABLE0                  (0x00000000U)
#define _ADC0_UPPER_LIMIT_TABLE1                  (0xFFF00000U)
#define _ADC0_LOWER_LIMIT_TABLE1                  (0x00000000U)
#define _ADC0_UPPER_LIMIT_TABLE2                  (0xFFF00000U)
#define _ADC0_LOWER_LIMIT_TABLE2                  (0x00000000U)
#define _ADC0_SG1_START_POINTER                   (0x00000000U)
#define _ADC0_SG1_END_POINTER                     (0x00000006U)
#define _ADC_TH_SAMPLING_START                    (0x1U)
#define _ADC_FILTER_ENABLED                       (0x1U) 
#define _ADC_FILTER_EDGE_RISING                   (0x01U) 
#define _ADC_FILTER_EDGE_FALLING                  (0x02U)
#define _ADC_FILTER_EDGE_BOTH                     (0x03U)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_ADC0_Create(void);
void R_ADC0_Halt(void);
void R_ADC0_ScanGroup1_Start(void);
void R_ADC0_ScanGroup1_OperationOn(void);
void R_ADC0_ScanGroup1_GetResult(uint16_t * const buffer);

/* Start user code for function. Do not edit comment generated here */
void r_adc0_SetPWMSta(void);
uint16_t r_adc0_GetK15Value(void);
/* End user code. Do not edit comment generated here */
#endif