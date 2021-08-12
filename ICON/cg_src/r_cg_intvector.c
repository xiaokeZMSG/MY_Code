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
* File Name    : r_cg_intvector.c
* Version      : Code Generator for RH850/F1K V1.01.00.02 [19 Apr 2017]
* Device(s)    : R7F701582(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file initializes the vector table.
* Creation Date: 2021/6/8
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
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/

/* ADCA0 SG1 end interrupt */
extern void r_adc0_scan_group1_end_interrupt(void);  // 18

/* ADCA0 error interrupt */
extern void r_adc0_error_interrupt(void);            // 56

/* RIIC transmit data empty interrupt */
extern void r_riic0_transmit_interrupt(void);        //76
/* RIIC receive error/event interrupt */
extern void r_riic0_error_interrupt(void);          // 77
/* RIIC receive end interrupt */
extern void r_riic0_receive_interrupt(void);        // 78
/* RIIC transmit end interrupt */
extern void r_riic0_transmitend_interrupt(void);    // 79

/* Interrupt for TAUB0 channel 10 */
extern void r_taub0_channel10_interrupt(void);    // 152
/* Interrupt for TAUB0 channel 12 */
extern void r_taub0_channel12_interrupt(void);    // 154
/* Interrupt for TAUB0 channel 14 */
extern void r_taub0_channel14_interrupt(void);    // 156

/* RLIN35 transmit interrupt */
extern void r_uart5_interrupt_send(void);     // 237
/* RLIN35 receive complete interrupt */
extern void r_uart5_interrupt_receive(void);   // 238
/* RLIN35 status interrupt */
extern void r_uart5_interrupt_error(void);     // 239


#pragma section const "EIINTTBL"

void * const INT_Vectors[358] = {
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Interrupt for CH0 of TAUD0/CSIH2 communication status interrupt */
    0,
    /* Interrupt for CH2 of TAUD0/CSIH3 communication status interrupt */
    0,
    /* Interrupt for CH4 of TAUD0/CSIH2 receive status interrupt */
    0,
    /* Interrupt for CH6 of TAUD0/CSIH2 communication error interrupt */
    0,
    /* Interrupt for CH8 of TAUD0/CSIH2 job completion interrupt */
    0,
    /* Interrupt for CH10 of TAUD0/CSIH3 receive status interrupt */
    0,
    /* Interrupt for CH12 of TAUD0/CSIH3 communication error interrupt */
    0,
    /* Interrupt for CH14 of TAUD0/CSIH3 job completion interrupt */
    0,
    /* TAPA0 peak interrupt 0/CSIH1 communication status interrupt */
    0,
    /* TAPA0 valley interrupt 0/CSIH1 receive status interrupt */
    0,
    /* ADCA0 SG1 end interrupt */
    (void *)r_adc0_scan_group1_end_interrupt,   // 18
    /* ADCA0 SG2 end interrupt */
    0,
    /* ADCA0 SG3 end interrupt/6 CSIH0 job completion interrupt */
    0,
    /* Dedicated interrupt for on-chip debug function */
    0,
    /* CAN global error interrupt */
    0,
    /* CAN receive FIFO interrupt */
    0,
    /* CAN0 error interrupt */
    0,
    /* CAN0 transmit/receive FIFO receive complete interrupt */
    0,
    /* CAN0 transmit interrupt */
    0,
    /* CSIG0 communication status interrupt/CSIH1 communication error interrupt */
    0,
    /* CSIG0 receive status interrupt/CSIH1 job interrupt */
    0,
    /* CSIH0 communication status interrupt */
    0,
    /* CSIH0 receive status interrupt */
    0,
    /* CSIH0 communication error interrupt */
    0,
    /* CSIH0 job completion interrupt/ADCA0 SG3 end interrupt */
    0,
    /* RLIN30 interrupt */
    0,
    /* RLIN30 transmit interrupt */
    0,
    /* RLIN30 receive complete interrupt */
    0,
    /* RLIN30 status interrupt */
    0,
    /* External interrupt(INTP0) */
    0,
    /* External interrupt(INTP1) */
    0,
    /* External interrupt(INTP2) */
    0,
    /* WDTA0 75% interrupt */
    0,
    /* WDTA1 75% interrupt */
    0,
    /* Reserved */
    0,
    /* External interrupt(INTP3) */
    0,
    /* External interrupt(INTP4) */
    0,
    /* External interrupt(INTP5) */
    0,
    /* External interrupt(INTP10) */
    0,
    /* External interrupt(INTP11) */
    0,
    /* Interrupt for TAUD0 channel 1 */
    0,
    /* Interrupt for TAUD0 channel 3 */
    0,
    /* Interrupt for TAUD0 channel 5 */
    0,
    /* Interrupt for TAUD0 channel 7 */
    0,
    /* Interrupt for TAUD0 channel 9 */
    0,
    /* Interrupt for TAUD0 channel 11 */
    0,
    /* Interrupt for TAUD0 channel 13 */
    0,
    /* Interrupt for TAUD0 channel 15 */
    0,
    /* ADCA0 error interrupt */
    (void *)r_adc0_error_interrupt,       // 56
    /* CSIG0 receive error interrupt */
    0,
    /* RLIN20 interrupt */
    0,
    /* RLIN21 interrupt */
    0,
    /* DMA0 transfer completion */
    0,
    /* DMA1 transfer completion */
    0,
    /* DMA2 transfer completion */
    0,
    /* DMA3 transfer completion */
    0,
    /* DMA4 transfer completion */
    0,
    /* DMA5 transfer completion */
    0,
    /* DMA6 transfer completion */
    0,
    /* DMA7 transfer completion */
    0,
    /* DMA8 transfer completion */
    0,
    /* DMA9 transfer completion */
    0,
    /* DMA10 transfer completion */
    0,
    /* DMA11 transfer completion */
    0,
    /* DMA12 transfer completion */
    0,
    /* DMA13 transfer completion */
    0,
    /* DMA14 transfer completion */
    0,
    /* DMA15 transfer completion */
    0,
    /* RIIC transmit data empty interrupt */
    (void *)r_riic0_transmit_interrupt,       // 76
    /* RIIC receive error/event interrupt */
    (void *)r_riic0_error_interrupt,          // 77
    /* RIIC receive end interrupt */
    (void *)r_riic0_receive_interrupt,        // 78
    /* RIIC transmit end interrupt */
    (void *)r_riic0_transmitend_interrupt,    // 79
    /* Interrupt for TAUJ0 channel 0 */
    0,
    /* Interrupt for TAUJ0 channel 1 */
    0,
    /* Interrupt for TAUJ0 channel 2 */
    0,
    /* Interrupt for TAUJ0 channel 3 */
    0,
    /* OSTM0 interrupt */
    0,
    /* ENCA0 overflow interrupt/PWGA4 interrupt */
    0,
    /* ENCA0 underflow interrupt/PWGA5 interrupt */
    0,
    /* ENCA0 match or capture interrupt 0/PWGA6 interrupt */
    0,
    /* ENCA0 match or capture interrupt 1/PWGA7 interrupt */
    0,
    /* ENCA0 encoder clear interrupt */
    0,
    /* Key interrupt */
    0,
    /* PWSA queue full interrupt */
    0,
    /* PWGA0 interrupt */
    0,
    /* PWGA1 interrupt */
    0,
    /* PWGA2 interrupt */
    0,
    /* PWGA3 interrupt */
    0,
    /* PWGA8 interrupt */
    0,
    /* PWGA9 interrupt */
    0,
    /* PWGA10 interrupt */
    0,
    /* PWGA11 interrupt */
    0,
    /* PWGA12 interrupt */
    0,
    /* PWGA13 interrupt */
    0,
    /* PWGA14 interrupt */
    0,
    /* PWGA15 interrupt */
    0,
    /* ICUSE CMD register ready to write interrupt */
    0,
    /* ICUSE CMD register ready to read interrupt */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Flash sequencer end error interrupt */
    0,
    /* Flash sequencer end interrupt */
    0,
    /* LPS port polling end interrupt */
    0,
    /* CAN1 error interrupt */
    0,
    /* CAN1 transmit/receive FIFO receive complete interrupt */
    0,
    /* CAN1 transmit interrupt */
    0,
    /* CSIH1 communication status interrupt/TAPA0 peak interrupt 0 */
    0,
    /* CSIH1 receive status interrupt/TAPA0 valley interrupt 0 */
    0,
    /* CSIH1 communication error interrupt/CSIG0 communication status interrupt */
    0,
    /* CSIH1 job interrupt/CSIG0 receive status interrupt */
    0,
    /* RLIN31 interrupt */
    0,
    /* RLIN31 transmit interrupt */
    0,
    /* RLIN31 receive complete interrupt */
    0,
    /* RLIN31 status interrupt */
    0,
    /* PWGA20 interrupt */
    0,
    /* PWGA21 interrupt */
    0,
    /* PWGA22 interrupt */
    0,
    /* PWGA23 interrupt */
    0,
    /* External interrupt(INTP6) */
    0,
    /* External interrupt(INTP7) */
    0,
    /* External interrupt(INTP8) */
    0,
    /* External interrupt(INTP12) */
    0,
    /* CSIH2 communication status interrupt/Interrupt for TAUD0 channel 0 */
    0,
    /* CSIH2 communication status interrupt/Interrupt for TAUD0 channel 4 */
    0,
    /* CSIH2 communication error interrupt/Interrupt for TAUD0 channel 6 */
    0,
    /* CSIH2 job completion interrupt/Interrupt for TAUD0 channel 8 */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Interrupt for TAUB0 channel 0 */
    0,
    /* Interrupt for TAUB0 channel 1 */
    0,
    /* Interrupt for TAUB0 channel 2 */
    0,
    /* Interrupt for TAUB0 channel 3/PWGA16 interrupt */
    0,
    /* Interrupt for TAUB0 channel 4 */
    0,
    /* Interrupt for TAUB0 channel 5/PWGA17 interrupt */
    0,
    /* Interrupt for TAUB0 channel 6 */
    0,
    /* Interrupt for TAUB0 channel 7/PWGA18 interrupt */
    0,
    /* Interrupt for TAUB0 channel 8 */
    0,
    /* Interrupt for TAUB0 channel 9/PWGA19 interrupt */
    0,
    /* Interrupt for TAUB0 channel 10 */
    (void *)r_taub0_channel10_interrupt,    // 152
    /* Interrupt for TAUB0 channel 11/PWGA26 interrupt */
    0,
    /* Interrupt for TAUB0 channel 12 */
    (void *)r_taub0_channel12_interrupt,    // 154
    /* Interrupt for TAUB0 channel 13/PWGA30 interrupt */
    0,
    /* Interrupt for TAUB0 channel 14 */
    (void *)r_taub0_channel14_interrupt,    // 156
    /* Interrupt for TAUB0 channel 15/PWGA31 interrupt */
    0,
    /* CSIH3 communication status interrupt/Interrupt for TAUD0 channel 2 */
    0,
    /* CSIH3 receive status interrupt/Interrupt for TAUD0 channel 10 */
    0,
    /* CSIH3 communication error interrupt/Interrupt for TAUD0 channel 12 */
    0,
    /* CSIH3 job completion interrupt/Interrupt for TAUD0 channel 14 */
    0,
    /* RLIN22 interrupt */
    0,
    /* RLIN23 interrupt */
    0,
    /* RLIN32 interrupt */
    0,
    /* RLIN32 transmit interrupt */
    0,
    /* RLIN32 receive complete interrupt */
    0,
    /* RLIN32 status interrupt */
    0,
    /* Interrupt for TAUJ1 channel 0 */
    0,
    /* Interrupt for TAUJ1 channel 1 */
    0,
    /* Interrupt for TAUJ1 channel 2 */
    0,
    /* Interrupt for TAUJ1 channel 3 */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* PWGA24 interrupt */
    0,
    /* PWGA25 interrupt */
    0,
    /* PWGA27 interrupt */
    0,
    /* PWGA28 interrupt */
    0,
    /* PWGA29 interrupt */
    0,
    /* PWGA32 interrupt */
    0,
    /* PWGA33 interrupt */
    0,
    /* PWGA34 interrupt */
    0,
    /* PWGA35 interrupt */
    0,
    /* PWGA36 interrupt */
    0,
    /* PWGA37 interrupt */
    0,
    /* PWGA38 interrupt */
    0,
    /* PWGA39 interrupt */
    0,
    /* PWGA40 interrupt */
    0,
    /* PWGA41 interrupt */
    0,
    /* PWGA42 interrupt */
    0,
    /* PWGA43 interrupt */
    0,
    /* PWGA44 interrupt */
    0,
    /* PWGA45 interrupt */
    0,
    /* PWGA46 interrupt */
    0,
    /* PWGA47 interrupt */
    0,
    /* External interrupt(INTP9) */
    0,
    /* External interrupt(INTP13) */
    0,
    /* External interrupt(INTP14) */
    0,
    /* External interrupt(INTP15) */
    0,
    /* 1 second interrupt */
    0,
    /* Alarm interrupt */
    0,
    /* Periodic interrupt */
    0,
    /* ADCA1 error interrupt */
    0,
    /* ADCA1 scan group 1(SG1) end interrupt */
    0,
    /* ADCA1 scan group 2(SG2) end interrupt */
    0,
    /* ADCA1 scan group 3(SG3) end interrupt */
    0,
    /* Reserved */
    0,
    /* CAN2 error interrupt */
    0,
    /* CAN2 transmit/receive FIFO receive complete interrupt */
    0,
    /* CAN2 transmit interrupt */
    0,
    /* CAN3 error interrupt */
    0,
    /* CAN3 transmit/receive FIFO receive complete interrupt */
    0,
    /* CAN3 transmit interrupt */
    0,
    /* CSIG1 communication status interrupt */
    0,
    /* CSIG1 receive status interrupt */
    0,
    /* CSIG1 receive error interrupt */
    0,
    /* RLIN24 interrupt */
    0,
    /* RLIN25 interrupt */
    0,
    /* RLIN33 interrupt */
    0,
    /* RLIN33 transmit interrupt */
    0,
    /* RLIN33 receive complete interrupt */
    0,
    /* RLIN33 status interrupt */
    0,
    /* RLIN34 interrupt */
    0,
    /* RLIN34 transmit interrupt */
    0,
    /* RLIN34 receive complete interrupt */
    0,
    /* RLIN34 status interrupt */
    0,
    /* RLIN35 interrupt */
    0,
    /* RLIN35 transmit interrupt */
    (void *)r_uart5_interrupt_send,              // 237
    /* RLIN35 receive complete interrupt */
    (void *)r_uart5_interrupt_receive,           // 238
    /* RLIN35 status interrupt */
    (void *)r_uart5_interrupt_error,             // 239
    /* PWGA48 interrupt */
    0,
    /* PWGA49 interrupt */
    0,
    /* PWGA50 interrupt */
    0,
    /* PWGA51 interrupt */
    0,
    /* PWGA52 interrupt */
    0,
    /* PWGA53 interrupt */
    0,
    /* PWGA54 interrupt */
    0,
    /* PWGA55 interrupt */
    0,
    /* PWGA56 interrupt */
    0,
    /* PWGA57 interrupt */
    0,
    /* PWGA58 interrupt */
    0,
    /* PWGA59 interrupt */
    0,
    /* PWGA60 interrupt */
    0,
    /* PWGA61 interrupt */
    0,
    /* PWGA62 interrupt */
    0,
    /* PWGA63 interrupt */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* CAN4 error interrupt */
    0,
    /* CAN4 transmit/receive FIFO receive complete interrupt */
    0,
    /* CAN4 transmit interrupt */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* CAN5 error interrupt */
    0,
    /* CAN5 transmit/receive FIFO receive complete interrupt */
    0,
    /* CAN5 transmit interrupt */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* Reserved */
    0,
    /* LPS digital port error interrupt */
    0,
    /* LPS analog port error interrupt */
    0,

};

#pragma section

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
