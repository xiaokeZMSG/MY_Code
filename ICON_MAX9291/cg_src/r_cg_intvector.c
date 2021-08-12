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
* Creation Date: 2021/7/20
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
/* Reserved */
extern void eiint0(void);
/* Reserved */
extern void eiint1(void);
/* Reserved */
extern void eiint2(void);
/* Reserved */
extern void eiint3(void);
/* Reserved */
extern void eiint4(void);
/* Reserved */
extern void eiint5(void);
/* Reserved */
extern void eiint6(void);
/* Reserved */
extern void eiint7(void);
/* Interrupt for CH0 of TAUD0/CSIH2 communication status interrupt */
extern void eiint8(void);
/* Interrupt for CH2 of TAUD0/CSIH3 communication status interrupt */
extern void eiint9(void);
/* Interrupt for CH4 of TAUD0/CSIH2 receive status interrupt */
extern void eiint10(void);
/* Interrupt for CH6 of TAUD0/CSIH2 communication error interrupt */
extern void eiint11(void);
/* Interrupt for CH8 of TAUD0/CSIH2 job completion interrupt */
extern void eiint12(void);
/* Interrupt for CH10 of TAUD0/CSIH3 receive status interrupt */
extern void eiint13(void);
/* Interrupt for CH12 of TAUD0/CSIH3 communication error interrupt */
extern void eiint14(void);
/* Interrupt for CH14 of TAUD0/CSIH3 job completion interrupt */
extern void eiint15(void);
/* TAPA0 peak interrupt 0/CSIH1 communication status interrupt */
extern void eiint16(void);
/* TAPA0 valley interrupt 0/CSIH1 receive status interrupt */
extern void eiint17(void);
/* ADCA0 SG1 end interrupt */
extern void eiint18(void);
/* ADCA0 SG2 end interrupt */
extern void eiint19(void);
/* ADCA0 SG3 end interrupt/6 CSIH0 job completion interrupt */
extern void eiint20(void);
/* Dedicated interrupt for on-chip debug function */
extern void eiint21(void);
/* CAN global error interrupt */
extern void eiint22(void);
/* CAN receive FIFO interrupt */
extern void eiint23(void);
/* CAN0 error interrupt */
extern void eiint24(void);
/* CAN0 transmit/receive FIFO receive complete interrupt */
extern void eiint25(void);
/* CAN0 transmit interrupt */
extern void eiint26(void);
/* CSIG0 communication status interrupt/CSIH1 communication error interrupt */
extern void eiint27(void);
/* CSIG0 receive status interrupt/CSIH1 job interrupt */
extern void eiint28(void);
/* CSIH0 communication status interrupt */
extern void eiint29(void);
/* CSIH0 receive status interrupt */
extern void eiint30(void);
/* CSIH0 communication error interrupt */
extern void eiint31(void);
/* CSIH0 job completion interrupt/ADCA0 SG3 end interrupt */
extern void eiint32(void);
/* RLIN30 interrupt */
extern void eiint33(void);
/* RLIN30 transmit interrupt */
extern void eiint34(void);
/* RLIN30 receive complete interrupt */
extern void eiint35(void);
/* RLIN30 status interrupt */
extern void eiint36(void);
/* External interrupt(INTP0) */
extern void eiint37(void);
/* External interrupt(INTP1) */
extern void eiint38(void);
/* External interrupt(INTP2) */
extern void eiint39(void);
/* WDTA0 75% interrupt */
extern void eiint40(void);
/* WDTA1 75% interrupt */
extern void eiint41(void);
/* Reserved */
extern void eiint42(void);
/* External interrupt(INTP3) */
extern void eiint43(void);
/* External interrupt(INTP4) */
extern void eiint44(void);
/* External interrupt(INTP5) */
extern void eiint45(void);
/* External interrupt(INTP10) */
extern void eiint46(void);
/* External interrupt(INTP11) */
extern void eiint47(void);
/* Interrupt for TAUD0 channel 1 */
extern void eiint48(void);
/* Interrupt for TAUD0 channel 3 */
extern void eiint49(void);
/* Interrupt for TAUD0 channel 5 */
extern void eiint50(void);
/* Interrupt for TAUD0 channel 7 */
extern void eiint51(void);
/* Interrupt for TAUD0 channel 9 */
extern void eiint52(void);
/* Interrupt for TAUD0 channel 11 */
extern void eiint53(void);
/* Interrupt for TAUD0 channel 13 */
extern void eiint54(void);
/* Interrupt for TAUD0 channel 15 */
extern void eiint55(void);
/* ADCA0 error interrupt */
extern void eiint56(void);
/* CSIG0 receive error interrupt */
extern void eiint57(void);
/* RLIN20 interrupt */
extern void eiint58(void);
/* RLIN21 interrupt */
extern void eiint59(void);
/* DMA0 transfer completion */
extern void eiint60(void);
/* DMA1 transfer completion */
extern void eiint61(void);
/* DMA2 transfer completion */
extern void eiint62(void);
/* DMA3 transfer completion */
extern void eiint63(void);
/* DMA4 transfer completion */
extern void eiint64(void);
/* DMA5 transfer completion */
extern void eiint65(void);
/* DMA6 transfer completion */
extern void eiint66(void);
/* DMA7 transfer completion */
extern void eiint67(void);
/* DMA8 transfer completion */
extern void eiint68(void);
/* DMA9 transfer completion */
extern void eiint69(void);
/* DMA10 transfer completion */
extern void eiint70(void);
/* DMA11 transfer completion */
extern void eiint71(void);
/* DMA12 transfer completion */
extern void eiint72(void);
/* DMA13 transfer completion */
extern void eiint73(void);
/* DMA14 transfer completion */
extern void eiint74(void);
/* DMA15 transfer completion */
extern void eiint75(void);
/* RIIC transmit data empty interrupt */
extern void r_riic0_transmit_interrupt(void);
/* RIIC receive error/event interrupt */
extern void r_riic0_error_interrupt(void);
/* RIIC receive end interrupt */
extern void r_riic0_receive_interrupt(void);
/* RIIC transmit end interrupt */
extern void r_riic0_transmitend_interrupt(void);
/* Interrupt for TAUJ0 channel 0 */
extern void eiint80(void);
/* Interrupt for TAUJ0 channel 1 */
extern void eiint81(void);
/* Interrupt for TAUJ0 channel 2 */
extern void eiint82(void);
/* Interrupt for TAUJ0 channel 3 */
extern void eiint83(void);
/* OSTM0 interrupt */
extern void eiint84(void);
/* ENCA0 overflow interrupt/PWGA4 interrupt */
extern void eiint85(void);
/* ENCA0 underflow interrupt/PWGA5 interrupt */
extern void eiint86(void);
/* ENCA0 match or capture interrupt 0/PWGA6 interrupt */
extern void eiint87(void);
/* ENCA0 match or capture interrupt 1/PWGA7 interrupt */
extern void eiint88(void);
/* ENCA0 encoder clear interrupt */
extern void eiint89(void);
/* Key interrupt */
extern void eiint90(void);
/* PWSA queue full interrupt */
extern void eiint91(void);
/* PWGA0 interrupt */
extern void eiint92(void);
/* PWGA1 interrupt */
extern void eiint93(void);
/* PWGA2 interrupt */
extern void eiint94(void);
/* PWGA3 interrupt */
extern void eiint95(void);
/* PWGA8 interrupt */
extern void eiint96(void);
/* PWGA9 interrupt */
extern void eiint97(void);
/* PWGA10 interrupt */
extern void eiint98(void);
/* PWGA11 interrupt */
extern void eiint99(void);
/* PWGA12 interrupt */
extern void eiint100(void);
/* PWGA13 interrupt */
extern void eiint101(void);
/* PWGA14 interrupt */
extern void eiint102(void);
/* PWGA15 interrupt */
extern void eiint103(void);
/* ICUSE CMD register ready to write interrupt */
extern void eiint104(void);
/* ICUSE CMD register ready to read interrupt */
extern void eiint105(void);
/* Reserved */
extern void eiint106(void);
/* Reserved */
extern void eiint107(void);
/* Reserved */
extern void eiint108(void);
/* Reserved */
extern void eiint109(void);
/* Flash sequencer end error interrupt */
extern void eiint110(void);
/* Flash sequencer end interrupt */
extern void eiint111(void);
/* LPS port polling end interrupt */
extern void eiint112(void);
/* CAN1 error interrupt */
extern void eiint113(void);
/* CAN1 transmit/receive FIFO receive complete interrupt */
extern void eiint114(void);
/* CAN1 transmit interrupt */
extern void eiint115(void);
/* CSIH1 communication status interrupt/TAPA0 peak interrupt 0 */
extern void eiint116(void);
/* CSIH1 receive status interrupt/TAPA0 valley interrupt 0 */
extern void eiint117(void);
/* CSIH1 communication error interrupt/CSIG0 communication status interrupt */
extern void eiint118(void);
/* CSIH1 job interrupt/CSIG0 receive status interrupt */
extern void eiint119(void);
/* RLIN31 interrupt */
extern void eiint120(void);
/* RLIN31 transmit interrupt */
extern void eiint121(void);
/* RLIN31 receive complete interrupt */
extern void eiint122(void);
/* RLIN31 status interrupt */
extern void eiint123(void);
/* PWGA20 interrupt */
extern void eiint124(void);
/* PWGA21 interrupt */
extern void eiint125(void);
/* PWGA22 interrupt */
extern void eiint126(void);
/* PWGA23 interrupt */
extern void eiint127(void);
/* External interrupt(INTP6) */
extern void eiint128(void);
/* External interrupt(INTP7) */
extern void eiint129(void);
/* External interrupt(INTP8) */
extern void eiint130(void);
/* External interrupt(INTP12) */
extern void eiint131(void);
/* CSIH2 communication status interrupt/Interrupt for TAUD0 channel 0 */
extern void eiint132(void);
/* CSIH2 communication status interrupt/Interrupt for TAUD0 channel 4 */
extern void eiint133(void);
/* CSIH2 communication error interrupt/Interrupt for TAUD0 channel 6 */
extern void eiint134(void);
/* CSIH2 job completion interrupt/Interrupt for TAUD0 channel 8 */
extern void eiint135(void);
/* Reserved */
extern void eiint136(void);
/* Reserved */
extern void eiint137(void);
/* Reserved */
extern void eiint138(void);
/* Reserved */
extern void eiint139(void);
/* Reserved */
extern void eiint140(void);
/* Reserved */
extern void eiint141(void);
/* Interrupt for TAUB0 channel 0 */
extern void eiint142(void);
/* Interrupt for TAUB0 channel 1 */
extern void eiint143(void);
/* Interrupt for TAUB0 channel 2 */
extern void eiint144(void);
/* Interrupt for TAUB0 channel 3/PWGA16 interrupt */
extern void eiint145(void);
/* Interrupt for TAUB0 channel 4 */
extern void eiint146(void);
/* Interrupt for TAUB0 channel 5/PWGA17 interrupt */
extern void eiint147(void);
/* Interrupt for TAUB0 channel 6 */
extern void eiint148(void);
/* Interrupt for TAUB0 channel 7/PWGA18 interrupt */
extern void eiint149(void);
/* Interrupt for TAUB0 channel 8 */
extern void eiint150(void);
/* Interrupt for TAUB0 channel 9/PWGA19 interrupt */
extern void eiint151(void);
/* Interrupt for TAUB0 channel 10 */
extern void eiint152(void);
/* Interrupt for TAUB0 channel 11/PWGA26 interrupt */
extern void eiint153(void);
/* Interrupt for TAUB0 channel 12 */
extern void eiint154(void);
/* Interrupt for TAUB0 channel 13/PWGA30 interrupt */
extern void eiint155(void);
/* Interrupt for TAUB0 channel 14 */
extern void eiint156(void);
/* Interrupt for TAUB0 channel 15/PWGA31 interrupt */
extern void eiint157(void);
/* CSIH3 communication status interrupt/Interrupt for TAUD0 channel 2 */
extern void eiint158(void);
/* CSIH3 receive status interrupt/Interrupt for TAUD0 channel 10 */
extern void eiint159(void);
/* CSIH3 communication error interrupt/Interrupt for TAUD0 channel 12 */
extern void eiint160(void);
/* CSIH3 job completion interrupt/Interrupt for TAUD0 channel 14 */
extern void eiint161(void);
/* RLIN22 interrupt */
extern void eiint162(void);
/* RLIN23 interrupt */
extern void eiint163(void);
/* RLIN32 interrupt */
extern void eiint164(void);
/* RLIN32 transmit interrupt */
extern void eiint165(void);
/* RLIN32 receive complete interrupt */
extern void eiint166(void);
/* RLIN32 status interrupt */
extern void eiint167(void);
/* Interrupt for TAUJ1 channel 0 */
extern void eiint168(void);
/* Interrupt for TAUJ1 channel 1 */
extern void eiint169(void);
/* Interrupt for TAUJ1 channel 2 */
extern void eiint170(void);
/* Interrupt for TAUJ1 channel 3 */
extern void eiint171(void);
/* Reserved */
extern void eiint172(void);
/* Reserved */
extern void eiint173(void);
/* Reserved */
extern void eiint174(void);
/* Reserved */
extern void eiint175(void);
/* Reserved */
extern void eiint176(void);
/* Reserved */
extern void eiint177(void);
/* Reserved */
extern void eiint178(void);
/* Reserved */
extern void eiint179(void);
/* Reserved */
extern void eiint180(void);
/* Reserved */
extern void eiint181(void);
/* Reserved */
extern void eiint182(void);
/* Reserved */
extern void eiint183(void);
/* PWGA24 interrupt */
extern void eiint184(void);
/* PWGA25 interrupt */
extern void eiint185(void);
/* PWGA27 interrupt */
extern void eiint186(void);
/* PWGA28 interrupt */
extern void eiint187(void);
/* PWGA29 interrupt */
extern void eiint188(void);
/* PWGA32 interrupt */
extern void eiint189(void);
/* PWGA33 interrupt */
extern void eiint190(void);
/* PWGA34 interrupt */
extern void eiint191(void);
/* PWGA35 interrupt */
extern void eiint192(void);
/* PWGA36 interrupt */
extern void eiint193(void);
/* PWGA37 interrupt */
extern void eiint194(void);
/* PWGA38 interrupt */
extern void eiint195(void);
/* PWGA39 interrupt */
extern void eiint196(void);
/* PWGA40 interrupt */
extern void eiint197(void);
/* PWGA41 interrupt */
extern void eiint198(void);
/* PWGA42 interrupt */
extern void eiint199(void);
/* PWGA43 interrupt */
extern void eiint200(void);
/* PWGA44 interrupt */
extern void eiint201(void);
/* PWGA45 interrupt */
extern void eiint202(void);
/* PWGA46 interrupt */
extern void eiint203(void);
/* PWGA47 interrupt */
extern void eiint204(void);
/* External interrupt(INTP9) */
extern void eiint205(void);
/* External interrupt(INTP13) */
extern void eiint206(void);
/* External interrupt(INTP14) */
extern void eiint207(void);
/* External interrupt(INTP15) */
extern void eiint208(void);
/* 1 second interrupt */
extern void eiint209(void);
/* Alarm interrupt */
extern void eiint210(void);
/* Periodic interrupt */
extern void eiint211(void);
/* ADCA1 error interrupt */
extern void eiint212(void);
/* ADCA1 scan group 1(SG1) end interrupt */
extern void eiint213(void);
/* ADCA1 scan group 2(SG2) end interrupt */
extern void eiint214(void);
/* ADCA1 scan group 3(SG3) end interrupt */
extern void eiint215(void);
/* Reserved */
extern void eiint216(void);
/* CAN2 error interrupt */
extern void eiint217(void);
/* CAN2 transmit/receive FIFO receive complete interrupt */
extern void eiint218(void);
/* CAN2 transmit interrupt */
extern void eiint219(void);
/* CAN3 error interrupt */
extern void eiint220(void);
/* CAN3 transmit/receive FIFO receive complete interrupt */
extern void eiint221(void);
/* CAN3 transmit interrupt */
extern void eiint222(void);
/* CSIG1 communication status interrupt */
extern void eiint223(void);
/* CSIG1 receive status interrupt */
extern void eiint224(void);
/* CSIG1 receive error interrupt */
extern void eiint225(void);
/* RLIN24 interrupt */
extern void eiint226(void);
/* RLIN25 interrupt */
extern void eiint227(void);
/* RLIN33 interrupt */
extern void eiint228(void);
/* RLIN33 transmit interrupt */
extern void eiint229(void);
/* RLIN33 receive complete interrupt */
extern void eiint230(void);
/* RLIN33 status interrupt */
extern void eiint231(void);
/* RLIN34 interrupt */
extern void eiint232(void);
/* RLIN34 transmit interrupt */
extern void eiint233(void);
/* RLIN34 receive complete interrupt */
extern void eiint234(void);
/* RLIN34 status interrupt */
extern void eiint235(void);
/* RLIN35 interrupt */
extern void eiint236(void);
/* RLIN35 transmit interrupt */
extern void eiint237(void);
/* RLIN35 receive complete interrupt */
extern void eiint238(void);
/* RLIN35 status interrupt */
extern void eiint239(void);
/* PWGA48 interrupt */
extern void eiint240(void);
/* PWGA49 interrupt */
extern void eiint241(void);
/* PWGA50 interrupt */
extern void eiint242(void);
/* PWGA51 interrupt */
extern void eiint243(void);
/* PWGA52 interrupt */
extern void eiint244(void);
/* PWGA53 interrupt */
extern void eiint245(void);
/* PWGA54 interrupt */
extern void eiint246(void);
/* PWGA55 interrupt */
extern void eiint247(void);
/* PWGA56 interrupt */
extern void eiint248(void);
/* PWGA57 interrupt */
extern void eiint249(void);
/* PWGA58 interrupt */
extern void eiint250(void);
/* PWGA59 interrupt */
extern void eiint251(void);
/* PWGA60 interrupt */
extern void eiint252(void);
/* PWGA61 interrupt */
extern void eiint253(void);
/* PWGA62 interrupt */
extern void eiint254(void);
/* PWGA63 interrupt */
extern void eiint255(void);
/* Reserved */
extern void eiint256(void);
/* Reserved */
extern void eiint257(void);
/* Reserved */
extern void eiint258(void);
/* Reserved */
extern void eiint259(void);
/* Reserved */
extern void eiint260(void);
/* Reserved */
extern void eiint261(void);
/* Reserved */
extern void eiint262(void);
/* Reserved */
extern void eiint263(void);
/* Reserved */
extern void eiint264(void);
/* Reserved */
extern void eiint265(void);
/* Reserved */
extern void eiint266(void);
/* Reserved */
extern void eiint267(void);
/* Reserved */
extern void eiint268(void);
/* Reserved */
extern void eiint269(void);
/* Reserved */
extern void eiint270(void);
/* Reserved */
extern void eiint271(void);
/* CAN4 error interrupt */
extern void eiint272(void);
/* CAN4 transmit/receive FIFO receive complete interrupt */
extern void eiint273(void);
/* CAN4 transmit interrupt */
extern void eiint274(void);
/* Reserved */
extern void eiint275(void);
/* Reserved */
extern void eiint276(void);
/* Reserved */
extern void eiint277(void);
/* Reserved */
extern void eiint278(void);
/* Reserved */
extern void eiint279(void);
/* Reserved */
extern void eiint280(void);
/* Reserved */
extern void eiint281(void);
/* Reserved */
extern void eiint282(void);
/* Reserved */
extern void eiint283(void);
/* Reserved */
extern void eiint284(void);
/* Reserved */
extern void eiint285(void);
/* Reserved */
extern void eiint286(void);
/* CAN5 error interrupt */
extern void eiint287(void);
/* CAN5 transmit/receive FIFO receive complete interrupt */
extern void eiint288(void);
/* CAN5 transmit interrupt */
extern void eiint289(void);
/* Reserved */
extern void eiint290(void);
/* Reserved */
extern void eiint291(void);
/* Reserved */
extern void eiint292(void);
/* Reserved */
extern void eiint293(void);
/* Reserved */
extern void eiint294(void);
/* Reserved */
extern void eiint295(void);
/* Reserved */
extern void eiint296(void);
/* Reserved */
extern void eiint297(void);
/* Reserved */
extern void eiint298(void);
/* Reserved */
extern void eiint299(void);
/* Reserved */
extern void eiint300(void);
/* Reserved */
extern void eiint301(void);
/* Reserved */
extern void eiint302(void);
/* Reserved */
extern void eiint303(void);
/* Reserved */
extern void eiint304(void);
/* Reserved */
extern void eiint305(void);
/* Reserved */
extern void eiint306(void);
/* Reserved */
extern void eiint307(void);
/* Reserved */
extern void eiint308(void);
/* Reserved */
extern void eiint309(void);
/* Reserved */
extern void eiint310(void);
/* Reserved */
extern void eiint311(void);
/* Reserved */
extern void eiint312(void);
/* Reserved */
extern void eiint313(void);
/* Reserved */
extern void eiint314(void);
/* Reserved */
extern void eiint315(void);
/* Reserved */
extern void eiint316(void);
/* Reserved */
extern void eiint317(void);
/* Reserved */
extern void eiint318(void);
/* Reserved */
extern void eiint319(void);
/* Reserved */
extern void eiint320(void);
/* Reserved */
extern void eiint321(void);
/* Reserved */
extern void eiint322(void);
/* Reserved */
extern void eiint323(void);
/* Reserved */
extern void eiint324(void);
/* Reserved */
extern void eiint325(void);
/* Reserved */
extern void eiint326(void);
/* Reserved */
extern void eiint327(void);
/* Reserved */
extern void eiint328(void);
/* Reserved */
extern void eiint329(void);
/* Reserved */
extern void eiint330(void);
/* Reserved */
extern void eiint331(void);
/* Reserved */
extern void eiint332(void);
/* Reserved */
extern void eiint333(void);
/* Reserved */
extern void eiint334(void);
/* Reserved */
extern void eiint335(void);
/* Reserved */
extern void eiint336(void);
/* Reserved */
extern void eiint337(void);
/* Reserved */
extern void eiint338(void);
/* Reserved */
extern void eiint339(void);
/* Reserved */
extern void eiint340(void);
/* Reserved */
extern void eiint341(void);
/* Reserved */
extern void eiint342(void);
/* Reserved */
extern void eiint343(void);
/* Reserved */
extern void eiint344(void);
/* Reserved */
extern void eiint345(void);
/* Reserved */
extern void eiint346(void);
/* Reserved */
extern void eiint347(void);
/* Reserved */
extern void eiint348(void);
/* Reserved */
extern void eiint349(void);
/* Reserved */
extern void eiint350(void);
/* Reserved */
extern void eiint351(void);
/* Reserved */
extern void eiint352(void);
/* Reserved */
extern void eiint353(void);
/* Reserved */
extern void eiint354(void);
/* Reserved */
extern void eiint355(void);
/* LPS digital port error interrupt */
extern void eiint356(void);
/* LPS analog port error interrupt */
extern void eiint357(void);

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
    0,
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
    0,
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
    (void *)r_riic0_transmit_interrupt,
    /* RIIC receive error/event interrupt */
    (void *)r_riic0_error_interrupt,
    /* RIIC receive end interrupt */
    (void *)r_riic0_receive_interrupt,
    /* RIIC transmit end interrupt */
    (void *)r_riic0_transmitend_interrupt,
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
    0,
    /* Interrupt for TAUB0 channel 11/PWGA26 interrupt */
    0,
    /* Interrupt for TAUB0 channel 12 */
    0,
    /* Interrupt for TAUB0 channel 13/PWGA30 interrupt */
    0,
    /* Interrupt for TAUB0 channel 14 */
    0,
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
    0,
    /* RLIN35 receive complete interrupt */
    0,
    /* RLIN35 status interrupt */
    0,
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
