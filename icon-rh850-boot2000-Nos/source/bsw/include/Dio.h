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

/** @reqSettings DEFAULT_SPECIFICATION_REVISION=4.1.2 */
/** @tagSettings DEFAULT_ARCHITECTURE=PPC */

/** @req SWS_Dio_00103 */

/* Dio_ChannelType */
/** @req SWS_Dio_00182 */
/** @req SWS_Dio_00015 */
/** @req SWS_Dio_00180 */

/* Dio_PortType */
/** @req SWS_Dio_00183 */
/** @req SWS_Dio_00018 */
/** @req SWS_Dio_00181 */

/* Dio_ChannelGroupType */
/** @req SWS_Dio_00184 */
/** @req SWS_Dio_00021 */


/* Dio_LevelType */
/** @req SWS_Dio_00185 */
/** @req SWS_Dio_00023 */

/* Dio_PortLevelType */
/** @req SWS_Dio_00186 */
/** @req SWS_Dio_00024 */

#ifndef DIO_H_
#define DIO_H_

#include "Std_Types.h" /** @req SWS_Dio_00170 */

// API Service ID's
#define DIO_READCHANNEL_ID			0x00
#define DIO_WRITECHANNEL_ID			0x01
#define DIO_READPORT_ID				0x02
#define DIO_WRITEPORT_ID			0x03
#define DIO_READCHANNELGROUP_ID		0x04
#define DIO_WRITECHANNELGROUP_ID	0x05
#define DIO_GETVERSIONINFO_ID		0x12

#define DIO_E_PARAM_INVALID_CHANNEL_ID 		10
#define DIO_E_PARAM_INVALID_PORT_ID 		20
#define DIO_E_PARAM_INVALID_GROUP_ID 		31
#define DIO_E_PARAM_POINTER                 0x20

#if defined(CFG_HC1X) || defined(CFG_TMS570)
typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;

typedef struct
{
  Dio_PortType port;
  uint8 offset;
  uint8 mask;
} Dio_ChannelGroupType;

typedef uint8 Dio_LevelType;

typedef uint8 Dio_PortLevelType;

#else	// CFG_PPC, CFG_STM32_STAMP and others
typedef uint32 Dio_ChannelType;
typedef uint32 Dio_PortType;
typedef struct
{
  Dio_PortType port;
  uint8 offset;
  uint32 mask;
} Dio_ChannelGroupType;

typedef uint8 Dio_LevelType;

typedef uint16 Dio_PortLevelType;
#endif


#define DIO_MODULE_ID			(120)
#define DIO_VENDOR_ID			(60)

#define DIO_SW_MAJOR_VERSION	2
#define DIO_SW_MINOR_VERSION	0
#define DIO_SW_PATCH_VERSION	0

#define DIO_AR_RELEASE_MAJOR_VERSION	4
#define DIO_AR_RELEASE_MINOR_VERSION	1
#define DIO_AR_RELEASE_PATCH_VERSION	2

//#include "Dio_Cfg.h"

/** @req SWS_Dio_00139 */
#if (DIO_VERSION_INFO_API == STD_ON)
void Dio_GetVersionInfo( Std_VersionInfoType *versionInfo );
#endif

/** @req SWS_Dio_00133 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType channelId);

/** @req SWS_Dio_00134 */
void Dio_WriteChannel(Dio_ChannelType channelId, Dio_LevelType level);

/** @req SWS_Dio_00135 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType portId);

/** @req SWS_Dio_00136 */
void Dio_WritePort(Dio_PortType portId, Dio_PortLevelType level);

/** @req SWS_Dio_00137 */
Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType *channelGroupIdPtr );

/** @req SWS_Dio_00138 */
void Dio_WriteChannelGroup(const Dio_ChannelGroupType *channelGroupIdPtr, Dio_PortLevelType level);

#endif /*DIO_H_*/
