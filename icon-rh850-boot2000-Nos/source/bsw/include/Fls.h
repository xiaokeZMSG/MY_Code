/*-------------------------------- Arctic Core ------------------------------
 * Copyright (C) 2013, ArcCore AB, Sweden, www.arccore.com.
 * Contact: <contact@arccore.com>
 *
 * You may ONLY use this file:
 * 1)if you have a valid commercial ArcCore license and then in accordance with
 * the terms contained in the written license agreement between you and ArcCore,
 * or alternatively
 * 2)if you follow the terms found in GNU General Public License version 2 as
 * published by the Free Software Foundation and appearing in the file
 * LICENSE.GPL included in the packaging of this file or here
 * <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>
 *-------------------------------- Arctic Core -----------------------------*/


#ifndef FLS_H_
#define FLS_H_

#include "Std_Types.h"
#include "MemIf_Types.h"

#define FLS_VENDOR_ID                       60u
#define FLS_MODULE_ID                       92u
#define FLS_SW_MAJOR_VERSION                2u
#define FLS_SW_MINOR_VERSION                0u
#define FLS_SW_PATCH_VERSION                0u
#define FLS_AR_RELEASE_MAJOR_VERSION        4u
#define FLS_AR_RELEASE_MINOR_VERSION        1u
#define FLS_AR_RELEASE_PATCH_VERSION        2u

// Development errors
#define FLS_E_PARAM_CONFIG			0x01u
#define FLS_E_PARAM_ADDRESS 		0x02u
#define FLS_E_PARAM_LENGTH 			0x03u
#define FLS_E_PARAM_DATA 			0x04u
#define FLS_E_UNINIT				0x05u
#define FLS_E_BUSY 					0x06u
#define FLS_E_VERIFY_ERASE_FAILED	0x07u
#define FLS_E_VERIFY_WRITE_FAILED	0x08u
#define FLS_E_TIMEOUT               0x09u
#define FLS_E_PARAM_POINTER         0x0Au

// Service id's for fls functions
#define FLS_INIT_ID					0x00
#define FLS_ERASE_ID				0x01
#define FLS_WRITE_ID				0x02
#define FLS_CANCEL_ID				0x03
#define FLS_GET_STATUS_ID			0x04
#define FLS_GET_JOB_RESULT_ID		0x05
#define FLS_MAIN_FUNCTION_ID		0x06
#define FLS_READ_ID					0x07
#define FLS_COMPARE_ID				0x08
#define FLS_SET_MODE_ID				0x09
#define FLS_GET_VERSION_INFO_ID		0x10

// Used as address offset from the configured flash base address to access a certain
// flash memory area.
/* @req SWS_Fls_00369 */
typedef uint32 Fls_AddressType;

// Specifies the number of bytes to read/write/erase/compare
//
// Note!
// Shall be the same type as Fls_AddressType because of
// arithmetic operations. Size depends on target platform and
// flash device.
/* @req SWS_Fls_00370 */
typedef uint32 Fls_LengthType;


#include "Fls_Cfg.h"

/**
 * Initializes the Flash Driver.
 *
 * @param ConfigPtr Pointer to flash driver configuration set.
 */
/* @req SWS_Fls_00249 */
void Fls_Init( const Fls_ConfigType *ConfigPtr );


/**
 * Erases flash sector(s).
 *
 * @param TargetAddress Target address in flash memory.
 *                      This address offset will be
 *						added to the flash memory base address.
 *						Min.: 0
 *                      Max.: FLS_SIZE - 1
 *
 * @param Length 		Number of bytes to erase
 *                      Min.: 1
 *                      Max.: FLS_SIZE - TargetAddress
 *
 * @return E_OK: erase command has been accepted
 *         E_NOT_OK: erase command has not been accepted
 */

/* @req SWS_Fls_00250 */
Std_ReturnType Fls_Erase(Fls_AddressType TargetAddress, Fls_LengthType Length );

/* @req SWS_Fls_00251 */
Std_ReturnType Fls_Write ( Fls_AddressType   TargetAddress,
                           const uint8 *SourceAddressPtr,
                           Fls_LengthType Length );


/* @req SWS_Fls_00252 */
//void Fls_Cancel( void );



/* @req SWS_Fls_00253 */
//MemIf_StatusType Fls_GetStatus( void );



/* @req SWS_Fls_00254 */
//MemIf_JobResultType Fls_GetJobResult( void );


/* @req SWS_Fls_00255 */
//void Fls_MainFunction( void );

/* @req SWS_Fls_00256 */
/*Std_ReturnType Fls_Read (Fls_AddressType SourceAddress,
                         uint8 *TargetAddressPtr,
                         Fls_LengthType Length );*/


/* @req SWS_Fls_00257 */
/*Std_ReturnType Fls_Compare( Fls_AddressType SourceAddress,
                            const uint8 *TargetAddressPtr,
                            Fls_LengthType Length );I*/


/* @req SWS_Fls_00258 */
/* @req SWS_Fls_00187 */
//void Fls_SetMode( MemIf_ModeType Mode );



/* @req SWS_Fls_00259 */
//void Fls_GetVersionInfo( Std_VersionInfoType *VersioninfoPtr );

void HalFlashRead(uint8_t pg,uint32_t offset,uint8_t *buf,uint16 cnt);
void HalFlashErase(uint8_t pg);

void HalFlashWriteWord( uint8 pg, uint32 offset, uint8 *buf,bool ignoreFail );

//void ecc_error_interrupt(void);


extern uint8_t flash_read_pg ;
extern bool flash_read_flag;

#endif /*FLS_H_*/
