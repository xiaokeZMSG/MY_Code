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


/** @addtogroup Pwm PWM Driver
 *  @{ */

/** @file Pwm.h
 * API and type definitions for PWM Driver.
 */

#ifndef PWM_H_
#define PWM_H_

#define PWM_SW_MAJOR_VERSION        2
#define PWM_SW_MINOR_VERSION        0
#define PWM_SW_PATCH_VERSION        0

#define PWM_AR_RELEASE_MAJOR_VERSION        4
#define PWM_AR_RELEASE_MINOR_VERSION        1
#define PWM_AR_RELEASE_PATCH_VERSION        2


#define PWM_MODULE_ID			121
#define PWM_VENDOR_ID			60


/** @name Service id's */
//@{
#define PWM_INIT_SERVICE_ID                         0x00u
#define PWM_DEINIT_SERVICE_ID                       0x01u
#define PWM_SETDUTYCYCLE_SERVICE_ID                 0x02u
#define PWM_SETPERIODANDDUTY_SERVICE_ID             0x03u
#define PWM_SETOUTPUTTOIDLE_SERVICE_ID              0x04u
#define PWM_GETOUTPUTSTATE_SERVICE_ID               0x05u
#define PWM_DISABLENOTIFICATION_SERVICE_ID          0x06u
#define PWM_ENABLENOTIFICATION_SERVICE_ID           0x07u
#define PWM_GETVERSIONINFO_SERVICE_ID               0x08u
#define PWM_SETPOWERSTATE_SERVICE_ID                0x09u
#define PWM_GETPOWERSTATE_SERVICE_ID                0x0Au
#define PWM_GETTARGETPOWERSTATE_SERVICE_ID          0x0Bu
#define PWM_PREPAREPOWERSTATE_SERVICE_ID            0x0Cu
#define PWM_MAIN_POWERTRANSITIONMANAGER_SERVICE_ID  0x0Du
//@}


/** @name Error Codes */
//@{
#define PWM_E_PARAM_CONFIG              0x10u
#define PWM_E_UNINIT                    0x11u
#define PWM_E_PARAM_CHANNEL             0x12u
#define PWM_E_PERIOD_UNCHANGEABLE       0x13u
#define PWM_E_ALREADY_INITIALIZED       0x14u
#define PWM_E_PARAM_POINTER             0x15u
#define PWM_E_NOT_DISENGAGED            0x16u
#define PWM_E_POWER_STATE_NOT_SUPPORTED 0x17u
#define PWM_E_TRANSITION_NOT POSSIBLE   0x18u
#define PWM_E_PERIPHERAL_NOT_PREPARED   0x19u
//@}

#include "Std_Types.h"


/**************************************************************
 *  Type definitions
 **************************************************************/

/* @req SWS_PWM_00059 */
#define Pwm_100_Procent 	0x8000
#define Pwm_0_Procent		0

/* @req SWS_Pwm_00108 */
typedef enum {
	PWM_LOW,
	PWM_HIGH
} Pwm_OutputStateType;

/* @req SWS_Pwm_00109 */
typedef enum {
	PWM_FALLING_EDGE = PWM_LOW,
	PWM_RISING_EDGE =  PWM_HIGH,
	PWM_BOTH_EDGES
} Pwm_EdgeNotificationType;

#define PWM_NO_EDGES (PWM_BOTH_EDGES + 1)

/* @req SWS_Pwm_00110 */
typedef enum {
	PWM_VARIABLE_PERIOD,
	PWM_FIXED_PERIOD,
	PWM_FIXED_PERIOD_SHIFTED
} Pwm_ChannelClassType;

typedef void (*Pwm_NotificationHandlerType)();

/* @req SWS_Pwm_10075 */
#include "Pwm_Cfg.h"

extern const Pwm_ConfigType PwmConfig;

/*
 * With MPC551x, only the first 16 eMIOS channels are of the usable class for
 * hardware PWM.
 */
#if PWM_NUMBER_OF_CHANNELS > 16
#error "PWM_NUMBER_OF_CHANNELS is larger than supported by the target platform."
#endif

#if PWM_DUTYCYCLE_UPDATED_ENDPERIOD!=STD_ON
#error "Unbuffered PWM currently not supported by this driver."
#endif

/*
 * Implemented functions
 ****************************/

#if ( PWM_VERSION_INFO_API == STD_ON)
/* @req SWS_Pwm_00103 */
/* @req SWS_Pwm_20069 */
void Pwm_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif

/* @req SWS_Pwm_00095 */
void Pwm_Init(const Pwm_ConfigType* ConfigPtr);

/* @req SWS_Pwm_00096 */
/* @req SWS_Pwm_10080 */
/* @req SWS_Pwm_20080 */
#if (PWM_DE_INIT_API==STD_ON)
void Pwm_DeInit(void);
#endif


/* @req SWS_Pwm_00098 */
/* @req SWS_Pwm_00058 */
/* @req SWS_Pwm_10083 */
/* @req SWS_Pwm_20083 */
/* @req SWS_PWM_00058 */
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
void Pwm_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle);
#endif

/* @req SWS_Pwm_00097 */
/* @req SWS_Pwm_00058 */
/* @req SWS_Pwm_10082 */
/* @req SWS_Pwm_20082 */
/* @req SWS_PWM_00058 */
#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, uint16 DutyCycle);
#endif

/* @req SWS_Pwm_00099 */
/* @req SWS_Pwm_10084 */
/* @req SWS_Pwm_20084  */
#if ( PWM_SET_OUTPUT_TO_IDLE_API == STD_ON )
void Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber);
#endif

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/*@req SWS_Pwm_00100 */
/*@req SWS_Pwm_10085 */
/*@req SWS_Pwm_20085 */
Pwm_OutputStateType Pwm_GetOutputState(Pwm_ChannelType ChannelNumber);
#endif


#if (PWM_NOTIFICATION_SUPPORTED==STD_ON)
/* @req SWS_Pwm_00101 */
/* @req SWS_Pwm_10112 */
/* @req SWS_Pwm_20112 */
void Pwm_DisableNotification(Pwm_ChannelType ChannelNumber);

/* @req SWS_Pwm_00102 */
/* @req SWS_Pwm_10113 */
/* @req SWS_Pwm_20113 */
void Pwm_EnableNotification(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification);

#endif

#endif /* PWM_H_ */
/** @} */
