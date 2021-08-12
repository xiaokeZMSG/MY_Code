/*********************************************************************************************************************
 * File Name     : $Source: eel_descriptor.c $
 * Mod. Revision : $Revision: 1.7 $
 * Mod. Date     : $Date: 2014/09/10 18:53:29JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : Descriptor variable definition
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


/*********************************************************************************************************************
 * FDL header files include
 *********************************************************************************************************************/
#include "R_TypeDefs.h"
#include "R_EEL.h"
#include "EEL_Descriptor.h"


/*********************************************************************************************************************
 * EEL descriptor variable definitions
 *********************************************************************************************************************/
/**< ROM ID-L table definition.
     The table data is retrieved from the definition in R_EEL_Descriptor.h */
const r_eel_ds_cfg_t IDLTab_astr[] = EEL_CONFIG_IDL_TABLE;

/**< RAM ID-X table definition */
uint16_t         IDXTab_au16[ sizeof (IDLTab_astr) / sizeof (r_eel_ds_cfg_t) ];

/**< EEL decriptor structure */
const r_eel_descriptor_t  eelConfig_enu = 
{
    EEL_CONFIG_VBLK_SIZE,                           /**< Virtual block size (# physical Flash blocks) */
    EEL_CONFIG_VBLK_CNT_REFRESH_THRESHOLD,          /**< threshold for minimum no. of prepared blocks */
    &(IDLTab_astr[0]),                              /**< pointer to the ID-L table in ROM */
    &(IDXTab_au16[0]),                              /**< pointer to the ID-X table in RAM */
    (sizeof(IDLTab_astr) / sizeof(r_eel_ds_cfg_t)), /**< number of table entries */     
    EEL_CONFIG_ERASE_SUSPEND_THRESHOLD              /**< threshold for erase suspend */
};

