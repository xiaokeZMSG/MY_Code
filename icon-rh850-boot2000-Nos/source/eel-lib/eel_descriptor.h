/*********************************************************************************************************************
 * File Name     : $Source: eel_descriptor.h $
 * Mod. Revision : $Revision: 1.8 $
 * Mod. Date     : $Date: 2014/09/10 18:54:32JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : EEL run-time configuration descriptor variable related defines. 
 *                 To be configured according to the application needs
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * DISCLAIMER 
 * This software is supplied by Renesas Electronics Corporation and is only  intended for use with Renesas products. 
 * No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all 
 * applicable laws, including copyright laws. 
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED 
 * OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
 * NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. 
 * TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS 
 * AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY 
 * REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH 
 * DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of 
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link: 
 * http://www.renesas.com/disclaimer 
 * 
 * Copyright (C) 2014 Renesas Electronics Corporation. All rights reserved.     
 *********************************************************************************************************************/


#ifndef R_EEL_DESCRIPTOR_H
#define R_EEL_DESCRIPTOR_H
#include "r_eel.h"
#define EEPROM_INITFLAG_ID     (4u)
#define UPDATEFLAG               (0x08)
#define DTC_BASE_ADDR            (0x10)
#define EVENT_SIZE               (0x20)
#define FREESE_SIZE              (0x10)
#define EXT_SIZE                 (0x08)
#define AGE_SIZE                 (0x08)
#define DTC_MAX_NUM              (40)
#define DID_SIZE4                (4)


//#define DID_NV_ID(Nr)            ( DID_BASE_ADDR + (Nr)*DID_SIZE4)
#define DTC_NV_EVENT(x)          ( DTC_BASE_ADDR + (x)*(EVENT_SIZE + FREESE_SIZE + EXT_SIZE + AGE_SIZE) )
#define DTC_NV_FREEZE(x)         ( DTC_NV_EVENT(x) + EVENT_SIZE)
#define DTC_NV_EXT(x)            ( DTC_NV_FREEZE(x) + FREESE_SIZE)
#define DTC_NV_AGE(x)            ( DTC_NV_EXT(x) + EXT_SIZE)
/*********************************************************************************************************************
 * User changable section
 *********************************************************************************************************************/

    /******************************************************************************************************************
    * Important definitions for run-time configuration of the EEL
    ******************************************************************************************************************/
    #define EEL_CONFIG_VBLK_SIZE                    32           /**< Virtual block size (# physical Flash blocks) */
    #define EEL_CONFIG_VBLK_CNT_REFRESH_THRESHOLD    3           /**< Threshold for minimum no. of prepared blocks */
    #define EEL_CONFIG_ERASE_SUSPEND_THRESHOLD      10           /**< Threshold for erase suspend cnt. Exceeding this 
                                                                      results in a warning */
    
    /******************************************************************************************************************
    * R_EEL_CONFIG_IDL_TABLE
    * Descriptor table containing data set identifier and data set length
    * as: 
    * { { <16-bit ID>, <16-bit length in bytes> }, {...}, {...}, .... }
    ******************************************************************************************************************/
#define  EEPROM_INIT_FLAG    { EEPROM_INITFLAG_ID,      4 }
#define  UPDATE_FLAG         { UPDATEFLAG,       4 }
#define  DID_NV_0200_SIZE    (4)
#define  DID_NV_0201_SIZE    (4)
#define  DID_NV_DF00_SIZE    (4)
#define  DID_NV_DF01_SIZE    (4)
#define  DID_NV_F101_SIZE    (16)
#define  DID_NV_F110_SIZE    (8)
#define  DID_NV_F112_SIZE    (8)
#define  DID_NV_F187_SIZE    (12)
#define  DID_NV_F18A_SIZE    (8)
#define  DID_NV_F18C_SIZE    (24)
#define  DID_NV_F190_SIZE    (20)
#define  DID_NV_F191_SIZE    (16)
#define  DID_NV_F193_SIZE    (16)
#define  DID_NV_F195_SIZE    (24)
#define  DID_NV_F19D_SIZE    (4)
#define  DID_NV_RES1_SIZE    (16)
#define  DID_NV_RES2_SIZE    (16)
#define  DID_NV_RES3_SIZE    (24)



#define  DID_BASE_ADDR       ( DTC_BASE_ADDR + DTC_MAX_NUM*(EVENT_SIZE+FREESE_SIZE+EXT_SIZE+AGE_SIZE))
#define  DID_NV_ADDR(x)      (DID_BASE_ADDR + x)
#define  DID_NV_0200_ID    DID_NV_ADDR(0)
#define  DID_NV_0201_ID    DID_NV_ADDR(1)
#define  DID_NV_DF00_ID    DID_NV_ADDR(2)
#define  DID_NV_DF01_ID    DID_NV_ADDR(3)
#define  DID_NV_F101_ID    DID_NV_ADDR(4)
#define  DID_NV_F110_ID    DID_NV_ADDR(5)
#define  DID_NV_F112_ID    DID_NV_ADDR(6)
#define  DID_NV_F187_ID    DID_NV_ADDR(7)
#define  DID_NV_F18A_ID    DID_NV_ADDR(8)
#define  DID_NV_F18C_ID    DID_NV_ADDR(9)
#define  DID_NV_F190_ID    DID_NV_ADDR(10)
#define  DID_NV_F191_ID    DID_NV_ADDR(11)
#define  DID_NV_F193_ID    DID_NV_ADDR(12)
#define  DID_NV_F195_ID    DID_NV_ADDR(13)
#define  DID_NV_F19D_ID    DID_NV_ADDR(14)
#define  DID_NV_RES1_ID    DID_NV_ADDR(15)
#define  DID_NV_RES2_ID    DID_NV_ADDR(16)
#define  DID_NV_RES3_ID    DID_NV_ADDR(17)
#define  DID_NV_MAX_ID     DID_NV_ADDR(DID_NV_RES3_ID+1)

#define  DID_NV_0200_TB      { DID_NV_0200_ID,  DID_NV_0200_SIZE }
#define  DID_NV_0201_TB      { DID_NV_0201_ID,  DID_NV_0201_SIZE }
#define  DID_NV_DF00_TB      { DID_NV_DF00_ID,  DID_NV_DF00_SIZE }
#define  DID_NV_DF01_TB      { DID_NV_DF01_ID,  DID_NV_DF01_SIZE }
#define  DID_NV_F101_TB      { DID_NV_F101_ID,  DID_NV_F101_SIZE }
#define  DID_NV_RES2_TB      { DID_NV_RES2_ID,  DID_NV_RES2_SIZE }
#define  DID_NV_F110_TB      { DID_NV_F110_ID,  DID_NV_F110_SIZE }
#define  DID_NV_F112_TB      { DID_NV_F112_ID,  DID_NV_F112_SIZE }
#define  DID_NV_F187_TB      { DID_NV_F187_ID,  DID_NV_F187_SIZE }
#define  DID_NV_F18A_TB      { DID_NV_F18A_ID,  DID_NV_F18A_SIZE }
#define  DID_NV_F18C_TB      { DID_NV_F18C_ID,  DID_NV_F18C_SIZE }
#define  DID_NV_F190_TB      { DID_NV_F190_ID,  DID_NV_F190_SIZE }
#define  DID_NV_F191_TB      { DID_NV_F191_ID,  DID_NV_F191_SIZE }
#define  DID_NV_F193_TB      { DID_NV_F193_ID,  DID_NV_F193_SIZE }
#define  DID_NV_F195_TB      { DID_NV_F195_ID,  DID_NV_F195_SIZE }
#define  DID_NV_F19D_TB      { DID_NV_F19D_ID,  DID_NV_F19D_SIZE }
#define  DID_NV_RES1_TB      { DID_NV_RES1_ID,  DID_NV_RES1_SIZE }
#define  DID_NV_RES3_TB      { DID_NV_RES3_ID,  DID_NV_RES3_SIZE }

#define NrofsecAcssAttemptsID (DID_NV_MAX_ID+4) 
#define NrofsecAcssAttemptsTB {NrofsecAcssAttemptsID, 4}

#define HP_APP_NV_DATA_MAX   (32)
#define HP_APP_NV_BASE_ID  ( DID_NV_MAX_ID + 0x16)
#define HP_APP1_NV_ID      ( HP_APP_NV_BASE_ID )
#define HP_APP2_NV_ID      ( HP_APP1_NV_ID +32 )
#define HP_APP3_NV_ID      ( HP_APP1_NV_ID +36 )

#define HP_APP1_NV_TB        { HP_APP1_NV_ID, 32}
#define HP_APP2_NV_TB        { HP_APP2_NV_ID, 32}
#define HP_APP3_NV_TB        { HP_APP3_NV_ID, 32}


#define HP_APP_NV_MAX_ID    ( HP_APP2_NV_ID +32)
#define EEPROM_ENDFLAG_ID   ( HP_APP_NV_MAX_ID +16)
#define EEPROM_END_FLAG     { EEPROM_ENDFLAG_ID, 8 }

#if 1
#define  DTC_NV_TB(Nr)       { DTC_NV_EVENT(Nr),  EVENT_SIZE },   \
					 		 { DTC_NV_FREEZE(Nr), FREESE_SIZE },  \
                             { DTC_NV_EXT(Nr),    EXT_SIZE },     \
					  		 { DTC_NV_AGE(Nr),    AGE_SIZE }
#else
#define  DTC_NV_ID(Nr)       { DTC_NV_EVENT(Nr),  EVENT_SIZE+FREESE_SIZE+ EXT_SIZE+AGE_SIZE}
#endif

#define EEL_CONFIG_IDL_TABLE  {                 \
	                                      EEPROM_INIT_FLAG,\
                                          UPDATE_FLAG,     \
                                          HP_APP3_NV_TB,   \
                                          NrofsecAcssAttemptsTB,\
                                          DTC_NV_TB(0),    \
					  DTC_NV_TB(1),    \
                                          DTC_NV_TB(2),    \
                                          DTC_NV_TB(3),    \
                                          DTC_NV_TB(4),    \
					  DTC_NV_TB(5),    \
                                          DTC_NV_TB(6),    \
                                          DTC_NV_TB(7),    \
                                          DTC_NV_TB(8),    \
					  DTC_NV_TB(9),    \
                                          DTC_NV_TB(10),   \
                                          DTC_NV_TB(11),   \
                                          DTC_NV_TB(12),   \
					  DTC_NV_TB(13),   \
                                          DTC_NV_TB(14),   \
                                          DTC_NV_TB(15),   \
                                          DTC_NV_TB(16),   \
					  DTC_NV_TB(17),   \
                                          DTC_NV_TB(18),   \
                                          DTC_NV_TB(19),   \
                                          DTC_NV_TB(20),   \
					  DTC_NV_TB(21),   \
                                          DTC_NV_TB(22),   \
                                          DTC_NV_TB(23),   \
                                          DTC_NV_TB(24),   \
					  DTC_NV_TB(25),   \
                                          DTC_NV_TB(26),   \
                                          DTC_NV_TB(27),   \
                                          DTC_NV_TB(28),   \
					  DTC_NV_TB(29),   \
                                          DTC_NV_TB(30),   \
                                          DTC_NV_TB(31),   \
                                          DTC_NV_TB(32),   \
					  DTC_NV_TB(33),   \
                                          DTC_NV_TB(34),   \
                                          DTC_NV_TB(35),   \
                                          DTC_NV_TB(36),   \
					  DTC_NV_TB(37),   \
                                          DTC_NV_TB(38),   \
                                          DTC_NV_TB(39),   \
                                          DID_NV_RES3_TB,  \
                                          DID_NV_0200_TB,  \
                                          DID_NV_0201_TB,  \
                                          DID_NV_DF00_TB,  \
                                          DID_NV_DF01_TB,  \
                                          DID_NV_F101_TB,  \
                                          DID_NV_RES1_TB,  \
                                          DID_NV_F110_TB,  \
                                          DID_NV_F112_TB,  \
                                          DID_NV_F187_TB,  \
                                          DID_NV_F18A_TB,  \
                                          DID_NV_F18C_TB,  \
                                          DID_NV_F190_TB,  \
                                          DID_NV_F191_TB,  \
                                          DID_NV_F193_TB,  \
                                          DID_NV_F195_TB,  \
                                          DID_NV_F19D_TB,  \
                                          DID_NV_RES2_TB,  \
                                          HP_APP1_NV_TB,   \
                                          HP_APP2_NV_TB,   \
                                          EEPROM_END_FLAG, \
                                 }      


/*********************************************************************************************************************
 * Even if possible, this section should not b echanged by the user
 *********************************************************************************************************************/
    
    /*****************************************************************************************************************
     * Descriptor variable declaration
     *****************************************************************************************************************/
    extern const r_eel_descriptor_t eelConfig_enu;


/*********************************************************************************************************************/
#endif  /* #ifndef R_EEL_DESCRIPTOR_H */
