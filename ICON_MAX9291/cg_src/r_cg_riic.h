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
* File Name    : r_cg_riic.h
* Version      : Code Generator for RH850/F1K V1.01.00.02 [19 Apr 2017]
* Device(s)    : R7F701582(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for RIIC module.
* Creation Date: 2021/7/27
***********************************************************************************************************************/
#ifndef RIIC_H
#define RIIC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    I2C Bus Control Register 1 (RIICnCR1)
*/
/* Initiates the RIIC reset or internal reset (BUSCONTROL1) */
#define _RIIC_DISABLE                           (0x0000000CU) /* RIIC disable */
#define _RIIC_RESET                             (0x00000040U) /* RIIC reset */
#define _RIIC_INTERNAL_RESET                    (0x000000C0U) /* RIIC internal reset */
#define _RIIC_CLEAR_INTERNAL_RESET              (0x0000008CU) /* Clear RIIC internal reset */

/*
    I2C Bus Control Register 2 (RIICnCR2)
*/
/* Bus Busy Detection Flag (BBSY) */
#define _RIIC_BUS_FREE                          (0x00000000U) /* The I2C bus is released (the bus is free). */
#define _RIIC_BUS_BUSY                          (0x00000080U) /* The I2C bus is occupied (the bus is busy). */
/* Master/Slave Mode (MST) */
#define _RIIC_SLAVE_MODE                        (0x00000000U) /* Slave mode */
#define _RIIC_MASTER_MODE                       (0x00000040U) /* Master mode */
/* Transmit/Receive Mode (TRS) */
#define _RIIC_RECEIVE_MODE                      (0x00000000U) /* Receive mode */
#define _RIIC_TRANSMIT_MODE                     (0x00000020U) /* Transmit mode */
/* Stop Condition Issuance Request (SP) */
#define _RIIC_STOP_CONDITION_NOT_REQUEST        (0x00000000U) /* Does not request to issue a stop condition. */
#define _RIIC_STOP_CONDITION_REQUEST            (0x00000008U) /* Requests to issue a stop condition. */
/* Restart Condition Issuance Request (RS) */
#define _RIIC_RESTART_CONDITION_NOT_REQUEST     (0x00000000U) /* Does not request to issue a restart condition. */
#define _RIIC_RESTART_CONDITION_REQUEST         (0x00000004U) /* Requests to issue a restart condition. */
/* Start Condition Issuance Request (ST) */
#define _RIIC_START_CONDITION_NOT_REQUEST       (0x00000000U) /* Does not request to issue a start condition. */
#define _RIIC_START_CONDITION_REQUEST           (0x00000002U) /* Requests to issue a start condition. */

/*
    I2C Bus Mode Register 1 (RIICnMR1)
*/
/* MST/TRS Write Protect (MTWP) */
#define _RIIC_MST_TRS_WRITE_DISABLE             (0x00000000U) /* Disables writing to the RIICnCR2.MST and TRS bits. */
#define _RIIC_MST_TRS_WRITE_ENABLE              (0x00000080U) /* Enables writing to the RIICnCR2.MST and TRS bits. */
/* BC Write Protect (BCWP) */
#define _RIIC_BC_WRITE_ENABLE                   (0x00000000U) /* Enables a value writing in the BC[2:0] bits. */
#define _RIIC_BC_WRITE_PROTECT                  (0x00000008U) /* Protects the BC[2:0] bits. */
/* Internal Reference Clock Selection (IIC?) (CKS2,CKS1,CKS0) */
#define _RIIC_CLOCK_SELECTION_1                 (0x00000000U) /* PCLK/1 clock */
#define _RIIC_CLOCK_SELECTION_2                 (0x00000010U) /* PCLK/2 clock */
#define _RIIC_CLOCK_SELECTION_4                 (0x00000020U) /* PCLK/4 clock */
#define _RIIC_CLOCK_SELECTION_8                 (0x00000030U) /* PCLK/8 clock */
#define _RIIC_CLOCK_SELECTION_16                (0x00000040U) /* PCLK16 clock */
#define _RIIC_CLOCK_SELECTION_32                (0x00000050U) /* PCLK/32 clock */
#define _RIIC_CLOCK_SELECTION_64                (0x00000060U) /* PCLK/64 clock */
#define _RIIC_CLOCK_SELECTION_128               (0x00000070U) /* PCLK/128 clock */
/* Bit Counter (BC2,BC1,BC0) */
#define _RIIC_BIT_COUNTER_9                     (0x00000000U) /* 9 bits */
#define _RIIC_BIT_COUNTER_2                     (0x00000001U) /* 2 bits */
#define _RIIC_BIT_COUNTER_3                     (0x00000002U) /* 3 bits */
#define _RIIC_BIT_COUNTER_4                     (0x00000003U) /* 4 bits */
#define _RIIC_BIT_COUNTER_5                     (0x00000004U) /* 5 bits */
#define _RIIC_BIT_COUNTER_6                     (0x00000005U) /* 6 bits */
#define _RIIC_BIT_COUNTER_7                     (0x00000006U) /* 7 bits */
#define _RIIC_BIT_COUNTER_8                     (0x00000007U) /* 8 bits */

/*
    I2C Bus Mode Register 2 (RIICnMR2)
*/
/* SDA Output Delay Clock Source Selection (DLCS) */
#define _RIIC_SDAO_COUNTER_SOURCE_CLOCK         (0x00000000U) /* Internal reference clock is selected. */
#define _RIIC_SDAO_COUNTER_SOURCE_CLOCK2        (0x00000080U) /* Internal reference clock divided by 2 is selected. */
/* Timeout H Count Control (TMOH) */
#define _RIIC_TIMEOUT_HIGH_COUNT_DISABLE        (0x00000000U) /* Disables counting while SCL line is at high level. */
#define _RIIC_TIMEOUT_HIGH_COUNT_ENABLE         (0x00000004U) /* Enables counting while SCL line is at high level. */
/* Timeout L Count Control (TMOL) */
#define _RIIC_TIMEOUT_LOW_COUNT_DISABLE         (0x00000000U) /* Disables counting while SCL line is at a low level. */
#define _RIIC_TIMEOUT_LOW_COUNT_ENABLE          (0x00000002U) /* Enables counting while SCL line is at a low level. */
/* Timeout Detection Time Selection (TMOS) */
#define _RIIC_TIMEOUT_DETECTION_MODE_LONG       (0x00000000U) /* Long mode is selected. */
#define _RIIC_TIMEOUT_DETECTION_MODE_SHORT      (0x00000001U) /* Short mode is selected. */
/* SDA Output Delay Counter (SDDL2,SDDL1,SDDL0) */
#define _RIIC_SDAO_DELAY_COUNTER_NO             (0x00000000U) /* No output delay */
#define _RIIC_SDAO_DELAY_COUNTER_1              (0x00000010U) /* 1 IIC? cycle */
#define _RIIC_SDAO_DELAY_COUNTER_2              (0x00000020U) /* 2 IIC? cycle */
#define _RIIC_SDAO_DELAY_COUNTER_3              (0x00000030U) /* 3 IIC? cycle */
#define _RIIC_SDAO_DELAY_COUNTER_4              (0x00000040U) /* 4 IIC? cycle */
#define _RIIC_SDAO_DELAY_COUNTER_5              (0x00000050U) /* 5 IIC? cycle */
#define _RIIC_SDAO_DELAY_COUNTER_6              (0x00000060U) /* 6 IIC? cycle */
#define _RIIC_SDAO_DELAY_COUNTER_7              (0x00000070U) /* 7 IIC? cycle */

/*
    I2C Bus Mode Register 3 (RIICnMR3)
*/
/* WAIT (WAIT) */
#define _RIIC_WAIT_NO                           (0x00000000U) /* Not held period between 9th and 1st clock cycle low. */
#define _RIIC_WAIT                              (0x00000040U) /* Hold period between 9th and 1st clock cycle low. */
/* RDRF Flag Set Timing Selection (RDRFS) */
#define _RIIC_RDRF_FLAG_SET_SCL_NINTH           (0x00000000U) /* Set at the rising edge of the 9th SCL clock cycle. */
#define _RIIC_RDRF_FLAG_SET_SCL_EIGHTH          (0x00000020U) /* Set at the rising edge of the 8th SCL clock cycle. */
/* ACKBT Write Protect (ACKWP) */
#define _RIIC_ACKBT_BIT_MODIFICATION_DISABLED   (0x00000000U) /* Modification of the ACKBT bit is disabled */
#define _RIIC_ACKBT_BIT_MODIFICATION_ENABLED    (0x00000010U) /* Modification of the ACKBT bit is enabled. */
/* Transmit Acknowledge (ACKBT) */
#define _RIIC_ACK_TRANSMISSION                  (0x00000000U) /* A 0 is sent as the acknowledge bit. */
#define _RIIC_NACK_TRANSMISSION                 (0x00000008U) /* A 1 is sent as the acknowledge bit. */
/* Receive Acknowledge (ACKBR) */
#define _RIIC_ACK_RECEPTION                     (0x00000000U) /* A 0 is received as the acknowledge bit . */
#define _RIIC_NACK_RECEPTION                    (0x00000004U) /* A 1 is received as the acknowledge bit . */
/* Digital noise Filter Stage Selection (NF1,NF0) */
#define _RIIC_DIGITAL_NF_STAGE_SINGLE           (0x00000000U) /* Noise of up to one IIC? cycle is filtered out. */
#define _RIIC_DIGITAL_NF_STAGE_2                (0x00000001U) /* Noise of up to two IIC? cycles is filtered out. */
#define _RIIC_DIGITAL_NF_STAGE_3                (0x00000002U) /* Noise of up to three IIC? cycles is filtered out. */
#define _RIIC_DIGITAL_NF_STAGE_4                (0x00000003U) /* Noise of up to four IIC? cycles is filtered out. */

/*
    I2C Bus Function Enable Register (RIICnFER)
*/
/* SCL Synchronous Circuit Enable (SCLE) */
#define _RIIC_SCL_SYNC_CIRCUIT_NOT_USED         (0x00000000U) /* No SCL synchronous circuit is used. */
#define _RIIC_SCL_SYNC_CIRCUIT_USED             (0x00000040U) /* An SCL synchronous circuit is used. */
/* Digital Noise Filter Circuit Enable (NFE) */
#define _RIIC_NOISE_FILTER_UNUSED               (0x00000000U) /* No digital noise filter circuit is used */
#define _RIIC_NOISE_FILTER_USED                 (0x00000020U) /* A digital noise filter circuit is used. */
/* NACK Reception Transfer Suspension Enable (NACKE) */
#define _RIIC_TRANSFER_SUSPENSION_DISABLED      (0x00000000U) /* Transfer is not suspended during NACK reception. */
#define _RIIC_TRANSFER_SUSPENSION_ENABLED       (0x00000010U) /* Transfer is suspended during NACK reception. */
/* Slave Arbitration-Lost Detection Enable (SALE) */
#define _RIIC_SLAVE_ARBITRATION_DISABLE         (0x00000000U) /* Slave arbitration-lost detection is disabled. */
#define _RIIC_SLAVE_ARBITRATION_ENABLE          (0x00000008U) /* Slave arbitration-lost detection is enabled. */
/* NACK Transmission Arbitration-Lost Detection Enable (NALE) */
#define _RIIC_NACK_ARBITRATION_DISABLE          (0x00000000U) /* NACK transmission AL detection is disabled */
#define _RIIC_NACK_ARBITRATION_ENABLE           (0x00000004U) /* NACK transmission AL detection is enabled */
/* Master Arbitration-Lost Detection Enable (MALE) */
#define _RIIC_MASTER_ARBITRATION_DISABLE        (0x00000000U) /* Master arbitration-lost detection is disabled. */
#define _RIIC_MASTER_ARBITRATION_ENABLE         (0x00000002U) /* Master arbitration-lost detection is enabled. */
/* Timeout Function Enable (TMOE) */
#define _RIIC_TIMEOUT_FUNCTION_DISABLED         (0x00000000U) /* The timeout function is disabled. */
#define _RIIC_TIMEOUT_FUNCTION_ENABLED          (0x00000001U) /* The timeout function is enabled. */

/*
    I2C Bus Status Enable Register (RIICnSER)
*/
/* Device-ID Address Detection Enable (DIDE) */
#define _RIIC_DEVICEID_DETECT_DISABLE           (0x00000000U) /* Device-ID address detection is disabled. */
#define _RIIC_DEVICEID_DETECT_ENABLE            (0x00000020U) /* Device-ID address detection is enabled. */
/* General Call Address Enable (GCE) */
#define _RIIC_GENERAL_CALL_ADDRESS_DISABLE      (0x00000000U) /* General call address detection is disabled. */
#define _RIIC_GENERAL_CALL_ADDRESS_ENABLE       (0x00000008U) /* General call address detection is enabled. */
/* Slave Address Register 2 Enable (SAR2) */
#define _RIIC_SLAVE_2_DISABLE                   (0x00000000U) /* Slave address in RIICnSAR2 is disabled. */
#define _RIIC_SLAVE_2_ENABLE                    (0x00000004U) /* Slave address in RIICnSAR2 is enabled. */
/* Slave Address Register 1 Enable (SAR1) */
#define _RIIC_SLAVE_1_DISABLE                   (0x00000000U) /* Slave address in RIICnSAR1 is disabled. */
#define _RIIC_SLAVE_1_ENABLE                    (0x00000002U) /* Slave address in RIICnSAR1 is enabled. */
/* Slave Address Register 0 Enable (SAR0) */
#define _RIIC_SLAVE_0_DISABLE                   (0x00000000U) /* Slave address in RIICnSAR0 is disabled. */
#define _RIIC_SLAVE_0_ENABLE                    (0x00000001U) /* Slave address in RIICnSAR0 is enabled. */

/*
    I2C Bus Interrupt Enable Register (RIICnIER)
*/
/* Transmit Data Empty Interrupt Enable (TIE) */
#define _RIIC_TRANSMIT_DATA_EMPTY_INT_DISABLE   (0x00000000U) /* Interrupt request INTIICnTI) is disabled. */
#define _RIIC_TRANSMIT_DATA_EMPTY_INT_ENABLE    (0x00000080U) /* Interrupt request INTIICnTI is enabled. */
/* Transmit End Interrupt Enable (TEIE) */
#define _RIIC_TRANSMIT_END_INT_DISABLE          (0x00000000U) /* Interrupt request INTIICnTEI is disabled. */
#define _RIIC_TRANSMIT_END_INT_ENABLE           (0x00000040U) /* Interrupt request INTIICnTEI is enabled. */
/* Receive Complete Interrupt Enable (RIE) */
#define _RIIC_RECEIVE_COMPLETE_INT_DISABLE      (0x00000000U) /* Interrupt request INTIICnRI is disabled. */
#define _RIIC_RECEIVE_COMPLETE_INT_ENABLE       (0x00000020U) /* Interrupt request INTIICnRI is enabled. */
/* NACK Reception Interrupt Enable (NAKIE) */
#define _RIIC_NACK_RECEPTION_INT_DISABLE        (0x00000000U) /* Interrupt request NAKI is disabled. */
#define _RIIC_NACK_RECEPTION_INT_ENABLE         (0x00000010U) /* Interrupt request NAKI is enabled. */
/* Stop Condition Detection Interrupt Enable (SPIE) */
#define _RIIC_STOP_CONDITION_INT_DISABLE        (0x00000000U) /* Interrupt request SPI is disabled. */
#define _RIIC_STOP_CONDITION_INT_ENABLE         (0x00000008U) /* Interrupt request SPI is enabled. */
/* Start Condition Detection Interrupt Enable (STIE) */
#define _RIIC_START_CONDITION_INT_DISABLE       (0x00000000U) /* Interrupt request STI is disabled. */
#define _RIIC_START_CONDITION_INT_ENABLE        (0x00000004U) /* Interrupt request STI is enabled. */
/* Arbitration-Lost Interrupt Enable (ALIE) */
#define _RIIC_ARBITRATION_LOST_INT_DISABLE      (0x00000000U) /* AL interrupt request (ALI) is disabled. */
#define _RIIC_ARBITRATION_LOST_INT_ENABLE       (0x00000002U) /* AL interrupt request (ALI) is enabled. */
/* Timeout Interrupt Enable (TMOIE) */
#define _RIIC_TIMEOUT_INT_DISABLE               (0x00000000U) /* Timeout interrupt request (TMOI) is disabled. */
#define _RIIC_TIMEOUT_INT_ENABLE                (0x00000001U) /* Timeout interrupt request (TMOI) is enabled. */

/*
    I2C Bus Status Register 1 (RIICnSR1)
*/
/* Device-ID Address Detection Flag (DID) */
#define _RIIC_DEVICEID_ADDRESS_NOT_DETECTED     (0x00000000U) /* Device-ID address is not detected. */
#define _RIIC_DEVICEID_ADDRESS_DETECTED         (0x00000020U) /* Device-ID address is detected. */
/* General Call Address Detection Flag (GCA) */
#define _RIIC_GENERAL_CALL_ADDRESS_NOT_DETECTED (0x00000000U) /* General call address is not detected. */
#define _RIIC_GENERAL_CALL_ADDRESS_DETECTED     (0x00000008U) /* General call address is detected. */
/* Slave Address 2 Detection Flag (AAS2) */
#define _RIIC_SLAVE_ADDRESS2_NOT_DETECTED       (0x00000000U) /* Slave address 2 is not detected. */
#define _RIIC_SLAVE_ADDRESS2_DETECTED           (0x00000004U) /* Slave address 2 is detected. */
/* Slave Address 1 Detection Flag (AAS2) */
#define _RIIC_SLAVE_ADDRESS1_NOT_DETECTED       (0x00000000U) /* Slave address 1 is not detected. */
#define _RIIC_SLAVE_ADDRESS1_DETECTED           (0x00000002U) /* Slave address 1 is detected. */
/* Slave Address 0 Detection Flag (AAS2) */
#define _RIIC_SLAVE_ADDRESS0_NOT_DETECTED       (0x00000000U) /* Slave address 0 is not detected. */
#define _RIIC_SLAVE_ADDRESS0_DETECTED           (0x00000001U) /* Slave address 0 is detected. */

/*
    I2C Bus Status Register 2 (RIICnSR2)
*/
/* Transmit Data Empty Flag (TDRE) */
#define _RIIC_TRANSMIT_DATA_NOT_EMPTY           (0x00000000U) /* RIICnDRT contains transmit data */
#define _RIIC_TRANSMIT_DATA_EMPTY               (0x00000080U) /* RIICnDRT contains no transmit data */
/* Transmit End Flag (TEND) */
#define _RIIC_TRANSMIT_NOT_END                  (0x00000000U) /* Data is being transmitted. */
#define _RIIC_TRANSMIT_END                      (0x00000040U) /* Data has been transmitted. */
/* Receive Complete Flag (RDRF) */
#define _RIIC_RECEIVE_NOT_COMPLETE              (0x00000000U) /* RIICnDRR contains no receive data. */
#define _RIIC_RECEIVE_COMPLETE                  (0x00000020U) /* RIICnDRR contains receive data. */
/* NACK Detection Flag (NACKF) */
#define _RIIC_NACK_NOT_DETECTED                 (0x00000000U) /* NACK is not detected. */
#define _RIIC_NACK_DETECTED                     (0x00000010U) /* NACK is detected. */
/* Stop Condition Detection Fla (STOP) */
#define _RIIC_STOP_CONDITION_NOT_DETECTED       (0x00000000U) /* Stop condition is not detected. */
#define _RIIC_STOP_CONDITION_DETECTED           (0x00000008U) /* Stop condition is detected. */
/* Start Condition Detection Flag (START) */
#define _RIIC_START_CONDITION_NOT_DETECTED      (0x00000000U) /* Start condition is not detected. */
#define _RIIC_START_CONDITION_DETECTED          (0x00000004U) /* Start condition is detected. */
/* Arbitration-Lost Flag (AL) */
#define _RIIC_ARBITRATION_NOT_LOST              (0x00000000U) /* Arbitration is not lost. */
#define _RIIC_ARBITRATION_LOST                  (0x00000002U) /* Arbitration is lost. */
/* Timeout Detection Flag (TMOF) */
#define _RIIC_TIMEOUT_NOT_DETECTED              (0x00000000U) /* Timeout is not detected. */
#define _RIIC_TIMEOUT_DETECTED                  (0x00000001U) /* Timeout is detected. */

/*
    I2C Slave Address Register y (y = 0 to 2) (RIICnSARm)
*/
/* 7-Bit/10-Bit Address Format Selection (FSm) */
#define _RIIC_ADDRESS_FORMAT_7BITS              (0x00000000U) /* The 7-bit address format is selected. */
#define _RIIC_ADDRESS_FORMAT_10BITS             (0x00008000U) /* The 10-bit address format is selected. */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _RIIC_BITRATE_LOW_LEVEL_PERIOD          (0x0000001FU) /* Bit Rate Low-Level Period */
#define _RIIC_BITRATE_HIGH_LEVEL_PERIOD         (0x0000000CU) /* Bit Rate High-Level Period */
#define _RIIC_RIIC0BRL_DEFAULT_VALUE            (0x000000E0U) /* RIIC0BRL default value */
#define _RIIC_RIIC0BRH_DEFAULT_VALUE            (0x000000E0U) /* RIIC0BRH default value */
#define _RIIC_ADDRESS_FORMAT_FLAG                (0x00001000)
#define _RIIC_ADDRESS_7BIT                       (0x0000007F)
#define _RIIC_ADDRESS_10BIT                      (0x000003FF)					
#define _RIIC_ADDRESS_7BIT_SHIFT                 (0x01)
#define _RIIC_ADDRESS_10BIT_SHIFT                (0x07)
#define _RIIC_ADDRESS_10BIT_UPPER_FORMAT         (0x00F0)					
#define _RIIC_ADDRESS_10BIT_UPPER                (0x0300)
#define _RIIC_ADDRESS_10BIT_LOWER                (0x00FF)					
#define _RIIC_ADDRESS_RECEIVE                    (0x0001)

/* Master State Flags */
#define _RIIC_MASTER_SENDS_ADR_7_R               (0x00U) /* Master sends 7 bits address with read */
#define _RIIC_MASTER_SENDS_ADR_7_W               (0x01U) /* Master sends 7 bits address with write */
#define _RIIC_MASTER_SENDS_ADR_10A_W             (0x02U) /* Master sends first 10 bits address with write */
#define _RIIC_MASTER_SENDS_ADR_10A_R             (0x03U) /* Master sends first 10 bits address with read */
#define _RIIC_MASTER_SENDS_ADR_10B               (0x04U) /* Master sends second 10 bits address */
#define _RIIC_MASTER_SENDS_DATA                  (0x05U) /* Master sends data */
#define _RIIC_MASTER_SENDS_END                   (0x06U) /* Master sends prepares to stop */
#define _RIIC_MASTER_SENDS_STOP                  (0x07U) /* Master sends stopping */
#define _RIIC_MASTER_RECEIVES_START              (0x08U) /* Master receive to start */
#define _RIIC_MASTER_RECEIVES_DATA               (0x09U) /* Master is receiving data */
#define _RIIC_MASTER_RECEIVES_STOPPING           (0x0AU) /* Master receive prepares to stop */
#define _RIIC_MASTER_RECEIVES_STOP               (0x0BU) /* Master receive stopping */
#define _RIIC_MASTER_RECEIVE                     (0x0CU) /* Master receive mode */
#define _RIIC_MASTER_TRANSMIT                    (0x0DU) /* Master transmit mode */
#define _RIIC_MASTER_RECEIVES_RESTART            (0x0EU) /* Master receive restarting */

/* Slave State Flags */
#define _RIIC_SLAVE_RECEIVES_DATA                (0x10U) /* Slave receiving data */
#define _RIIC_SLAVE_SENDS_DATA                   (0x11U) /* Slave sending data */
#define _RIIC_SLAVE_SENDS_END                    (0x12U) /* Slave send prepares to stop */
#define _RIIC_SLAVE_SENDS_STOP                   (0x13U) /* Slave send stopping */
#define _RIIC_SLAVE_RECEIVES_STOP                (0x14U) /* Slave receive stopping */
#define _RIIC_SLAVE_WAIT_START_CONDITION         (0x15U) /* Slave is waiting for start condition */
#define _RIIC_SLAVE_RECEIVE                      (0x16U) /* Slave receive mode */
#define _RIIC_SLAVE_TRANSMIT                     (0x17U) /* Slave transmit mode */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_RIIC0_Create(void);
void R_RIIC0_Start(void);
void R_RIIC0_Stop(void);
MD_STATUS R_RIIC0_Master_Send(uint16_t adr, uint8_t * const tx_buf, uint16_t tx_num);
MD_STATUS R_RIIC0_Master_Receive(uint16_t adr, uint8_t * const rx_buf, uint16_t rx_num);
void R_RIIC0_StartCondition(void);
void R_RIIC0_StopCondition(void);
static void r_riic0_callback_transmitend(void);
static void r_riic0_callback_receiveend(void);
static void r_riic0_callback_receiveerror(MD_STATUS status);

/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif