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

/** @tagSettings DEFAULT_ARCHITECTURE=PPC */
/** @reqSettings DEFAULT_SPECIFICATION_REVISION=4.1.2 */


/** @addtogroup Port Port Driver
 *  @{ */

/** @file Port.h
 * API and type definitions for Port Driver.
 */

#ifndef PORT_H_
#define PORT_H_

#define PORT_MODULE_ID           124
#define PORT_VENDOR_ID           60

#define PORT_SW_MAJOR_VERSION   2
#define PORT_SW_MINOR_VERSION   0
#define PORT_SW_PATCH_VERSION   0

#define PORT_AR_RELEASE_MAJOR_VERSION   4
#define PORT_AR_RELEASE_MINOR_VERSION   1
#define PORT_AR_RELEASE_PATCH_VERSION   2

/** @req SWS_Port_00130 */
/** @req SWS_Port_00208 Published via Port_Cfg.h */
/** @req SWS_Port_00228 Defined in Port_Cfg.h */
#include "Std_Types.h"
#include "Port_Cfg.h"

/** @name Error Codes */
/** @req SWS_Port_00051 */
/** @req PORT116 */
#define PORT_E_PARAM_PIN              0x0a
#define PORT_E_DIRECTION_UNCHANGEABLE 0x0b
#define PORT_E_PARAM_CONFIG           0x0c
#define PORT_E_PARAM_INVALID_MODE     0x0d
#define PORT_E_MODE_UNCHANGEABLE      0x0e
#define PORT_E_UNINIT                 0x0f
#define PORT_E_PARAM_POINTER          0x10
//@}

/** @name Service id's */
//@{
#define PORT_INIT_ID                    0x00
#define PORT_SET_PIN_DIRECTION_ID       0x01
#define PORT_REFRESH_PORT_DIRECTION_ID  0x02
#define PORT_GET_VERSION_INFO_ID        0x03
#define PORT_SET_PIN_MODE_ID            0x04
//@}

/** @req SWS_Port_00230
 *  @req SWS_Port_00220
 *  @req SWS_Port_00046
 * The type Port_PinDirectionType is a type for defining the direction of a Port Pin.
 * PORT_PIN_IN Sets port pin as input. 
 * PORT_PIN_OUT  Sets port pin as output. 
 */
typedef enum
{
    PORT_PIN_IN = 0, PORT_PIN_OUT,
} Port_PinDirectionType;

#if defined(CFG_HC1X)
typedef uint8 Port_PinModeType;
#else  // CFG_PPC, CFG_STM32_STAMP and others
/** @req SWS_Port_00221 */
/** @req SWS_Port_00231*/
typedef uint32 Port_PinModeType;
#endif

/** @req SWS_Port_00229 */
/** @req SWS_Port_00219 */
#if defined(CFG_PPC)
typedef uint16 Port_PinType;
#elif defined(CFG_ARM)
typedef uint8_t Port_PinType;
#else
#error "Invalid architecture"
#endif


/* @req SWS_Port_00140 */
void Port_Init(const Port_ConfigType *configType);

#if ( PORT_SET_PIN_DIRECTION_API == STD_ON )
/** @req SWS_Port_00141 */
/** @req SWS_Port_00086 */
void Port_SetPinDirection(Port_PinType pin, Port_PinDirectionType direction);
#endif

/** @req  SWS_Port_00142 */
void Port_RefreshPortDirection(void);

#if (PORT_SET_PIN_MODE_API == STD_ON)
/** @req SWS_Port_00145 */
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif

#if (PORT_VERSION_INFO_API == STD_ON)
/* @req SWS_Port_00143 */
void Port_GetVersionInfo(Std_VersionInfoType *versionInfo);
#endif


#endif /*PORT_H_*/
/** @} */
