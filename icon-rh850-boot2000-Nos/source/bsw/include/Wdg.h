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

#ifndef WDG_H_
#define WDG_H_

#include "Std_Types.h"

#include "Wdg_Cfg.h"

#define WDG_MODULE_ID          (102)
#define VENDOR_ID_ARCCORE      (60)

#define WDG_SW_MAJOR_VERSION   2
#define WDG_SW_MINOR_VERSION   0
#define WDG_SW_PATCH_VERSION   0

#define WDG_AR_RELASE_MAJOR_VERSION   4
#define WDG_AR_RELASE_MINOR_VERSION   1
#define WDG_AR_RELASE_PATCH_VERSION   2

#define WDG_GETVERSIONINFO_ID  4

#if defined(CFG_ARM_CM3)
void Wdg_IWDG_Init (const Wdg_IWDG_ConfigType* ConfigPtr);
void Wdg_IWDG_Trigger (void);
Std_ReturnType Wdg_IWDG_SetMode (WdgIf_ModeType Mode);
void Wdg_IWDG_GetVersionInfo (void /* IMPROVEMENT Std_VersionInfoType* versioninfo*/);

void Wdg_WWDG_Init (const Wdg_WWDG_ConfigType* ConfigPtr);
void Wdg_WWDG_Trigger (void);
Std_ReturnType Wdg_WWDG_SetMode (WdgIf_ModeType Mode);
void Wdg_WWDG_GetVersionInfo (void /* IMPROVEMENT Std_VersionInfoType* versioninfo*/);
#endif

#if (WDG_VERSION_INFO_API == STD_ON)
/** @req SWS_Wdg_00109 */
void Wdg_GetVersionInfo( Std_VersionInfoType *versionInfo );
#endif

/** @req SWS_Wdg_00106 */
void Wdg_Init (const Wdg_ConfigType* ConfigPtr);
/** @req SWS_Wdg_00107 */
void Wdg_SetTriggerCondition (uint16 timeout);
/** @req SWS_Wdg_00155 */
Std_ReturnType Wdg_SetMode (WdgIf_ModeType Mode);


#endif /* WDG_H_ */
