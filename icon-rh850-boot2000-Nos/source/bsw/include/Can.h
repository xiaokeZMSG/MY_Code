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

#ifndef CAN_H_
#define CAN_H_

#define CAN_VENDOR_ID			    60
#define CAN_MODULE_ID			    80

#define CAN_AR_MAJOR_VERSION    4
#define CAN_AR_MINOR_VERSION    1
#define CAN_AR_PATCH_VERSION    2

#define CAN_SW_MAJOR_VERSION    3
#define CAN_SW_MINOR_VERSION    0
#define CAN_SW_PATCH_VERSION    0

#define CAN_E_PARAM_POINTER     0x01
#define CAN_E_PARAM_HANDLE     0x02
#define CAN_E_PARAM_DLC     	0x03
#define CAN_E_PARAM_CONTROLLER 0x04
// API service used without initialization
#define CAN_E_UNINIT           0x05
// Init transition for current mode
#define CAN_E_TRANSITION       0x06
#define CAN_E_DATALOST         0x07
#define CAN_E_PARAM_BAUDRATE   0x08


/** @name Service id's */
//@{
#define CAN_INIT_SERVICE_ID                         0x00
#define CAN_MAINFUNCTION_WRITE_SERVICE_ID           0x01
#define CAN_SETCONTROLLERMODE_SERVICE_ID            0x03
#define CAN_DISABLECONTROLLERINTERRUPTS_SERVICE_ID  0x04
#define CAN_ENABLECONTROLLERINTERRUPTS_SERVICE_ID   0x05
#define CAN_WRITE_SERVICE_ID                        0x06
#define CAN_GETVERSIONINFO_SERVICE_ID               0x07
#define CAN_MAINFUNCTION_READ_SERVICE_ID            0x08
#define CAN_MAINFUNCTION_BUSOFF_SERVICE_ID          0x09
#define CAN_MAINFUNCTION_WAKEUP_SERVICE_ID          0x0a
#define CAN_CBK_CHECKWAKEUP_SERVICE_ID              0x0b
#define CAN_MAIN_FUNCTION_MODE_SERVICE_ID           0x0c
#define CAN_CHANGE_BAUD_RATE_SERVICE_ID             0x0d
#define CAN_CHECK_BAUD_RATE_SERVICE_ID              0x0e
//@}


//#if defined(CFG_PPC)

/* HOH flags */
#define CAN_HOH_FIFO_MASK           (1UL<<0)
//#define CAN_HOH_EOL_MASK            (1<<9)

/* Controller flags */
#define CAN_CTRL_RX_PROCESSING_INTERRUPT        (1UL<<0)
#define CAN_CTRL_RX_PROCESSING_POLLING          0
#define CAN_CTRL_TX_PROCESSING_INTERRUPT        (1UL<<1)
#define CAN_CTRL_TX_PROCESSING_POLLING          0
#define CAN_CTRL_WAKEUP_PROCESSING_INTERRUPT    (1UL<<2)
#define CAN_CTRL_WAKEUP_PROCESSING_POLLING      0
#define CAN_CTRL_BUSOFF_PROCESSING_INTERRUPT    (1UL<<3)
#define CAN_CTRL_BUSOFF_PROCESSING_POLLING      0
#define CAN_CTRL_ACTIVATION                     (1UL<<4)

#define CAN_CTRL_LOOPBACK                       (1UL<<5)
#define CAN_CTRL_FIFO                           (1UL<<6)

#define CAN_CTRL_ERROR_PROCESSING_INTERRUPT    (1UL<<7)
#define CAN_CTRL_ERROR_PROCESSING_POLLING      0

//#endif

#include "CanIf_Types.h"
#include "ComStack_Types.h"/** @req 4.1.2/SWS_Can_00388 */
#include "Can_GeneralTypes.h"/** @req 4.1.2/SWS_Can_00435 */
//#include "Mcu.h"
#include "Platform_Types.h"
//#include "Can_Cfg.h"
typedef uint8_t CanControllerIdType;
typedef struct {
	uint32_t txSuccessCnt;
	uint32_t rxSuccessCnt;
	uint32_t txErrorCnt;
	uint32_t rxErrorCnt;
	uint32_t boffCnt;
	uint32_t fifoOverflow;
	uint32_t fifoWarning;
} Can_Arc_StatisticsType;


#if defined(CFG_CAN_TEST)
typedef struct {
	uint64_t mbMaskTx;
	uint64_t mbMaskRx;
} Can_TestType;
#endif

/* Good things to know
 * L-PDU  - Link PDU
 *
 *
 */

/* Error from  CAN controller */
typedef union {
     volatile uint32_t R;
     struct {
    	 volatile uint32_t:24;
         volatile uint32_t BIT1ERR:1;
         volatile uint32_t BIT0ERR:1;
         volatile uint32_t ACKERR:1;
         volatile uint32_t CRCERR:1;
         volatile uint32_t FRMERR:1;
         volatile uint32_t STFERR:1;
         volatile uint32_t TXWRN:1;
         volatile uint32_t RXWRN:1;
     } B;
 } Can_Arc_ErrorType;

/** @req 4.1.2/SWS_Can_00414 */
typedef struct {
    // Specifies the buadrate of the controller in kbps.
    uint32_t CanControllerBaudRate;

    // Specifies propagation delay in time quantas.
    uint8_t CanControllerPropSeg;

    // Specifies phase segment 1 in time quantas.
    uint8_t CanControllerSeg1;

    // Specifies phase segment 2 in time quantas.
    uint8_t CanControllerSeg2;

    // Specifies the resynchronization jump width in time quantas.
    uint8_t CanControllerSyncJumpWidth;
} Can_ControllerBaudrateConfigType;

typedef enum {
    CAN_ID_TYPE_EXTENDED,
    CAN_ID_TYPE_MIXED,
    CAN_ID_TYPE_STANDARD
} Can_IdTypeType;

typedef enum {
    CAN_ARC_HANDLE_TYPE_BASIC,
    CAN_ARC_HANDLE_TYPE_FULL
} Can_Arc_HohType;

typedef struct Can_Callback {
    void (*CancelTxConfirmation)( PduIdType, const PduInfoType *);
    void (*RxIndication)( uint8_t ,Can_IdType ,uint8_t , const uint8_t * );
    void (*ControllerBusOff)(uint8_t);
    void (*TxConfirmation)(PduIdType);
    void (*ControllerWakeup)(uint8_t);
    void (*Arc_Error)(uint8_t,Can_Arc_ErrorType);
    void (*ControllerModeIndication)(uint8_t, CanIf_ControllerModeType);
} Can_CallbackType;

typedef enum {
    CAN_ARC_PROCESS_TYPE_INTERRUPT,
    CAN_ARC_PROCESS_TYPE_POLLING
} Can_Arc_ProcessType;

typedef uint32_t Can_FilterMaskType;

typedef enum {
    CAN_OBJECT_TYPE_RECEIVE,
    CAN_OBJECT_TYPE_TRANSMIT
} Can_ObjectTypeType;


typedef struct {
    //  Specifies the InstanceId of this module instance. If only one instance is
    //  present it shall have the Id 0
    uint8_t CanIndex;
} Can_GeneralType;

 typedef struct Can_HardwareObjectStruct {
     /* PC/PB, Specifies the type (Full-CAN or Basic-CAN) of a hardware object. */
     Can_Arc_HohType CanHandleType;

     /* PC/PB, Specifies whether the IdValue is of type - standard identifier - extended
      * identifier - mixed mode ImplementationType: Can_IdType */
     Can_IdTypeType CanIdType;

     /* PC/PB Specifies (together with the filter mask) the identifiers range that passes
      *  the hardware filter. */
     uint32_t CanHwFilterCode;

     /* PC/PB Holds the handle ID of HRH or HTH. The value of this parameter is unique
      *  in a given CAN Driver, and it should start with 0 and continue without any
      *  gaps. The HRH and HTH Ids are defined under two different name-spaces.
      *  Example: HRH0-0, HRH1-1, HTH0-2, HTH1-3 */
     uint32_t CanObjectId;

     /* PC/PB, Specifies if the HardwareObject is used as Transmit or as Receive object */
     Can_ObjectTypeType CanObjectType;

     /* PC/PB The filter mask that is used for hardware filtering together
      * with the CanHwFilterCode */
     Can_FilterMaskType CanHwFilterMask;
//#if defined(CFG_PPC)
     /* PC,  See CAN_HOH_XX macros */
     uint32_t Can_Arc_Flags;

     /* PC, Number of mailboxes that is owned by this HOH */
//     uint8_t  ArcCanNumMailboxes;
     uint64_t  ArcMailboxMask;

//#endif
 } Can_HardwareObjectType;

typedef struct {

     bool CanControllerActivation;

     //  This parameter provides the controller ID which is unique in a given CAN
     //  Driver. The value for this parameter starts with 0 and continue without any
     //  gaps.

     CanControllerIdType CanControllerId;

     // Specifies the default baud rate in kbps (from the list CanControllerSupportedBaudrates)
     uint32_t CanControllerDefaultBaudrate;

     // Specifies the supported baud rates
     const Can_ControllerBaudrateConfigType * const CanControllerSupportedBaudrates;

     // Specifices the length of the CanControllerSupportedBaudrates list
     uint32_t CanControllerSupportedBaudratesCount;

     //  Reference to the CPU clock configuration, which is set in the MCU driver
     //  configuration
     uint32_t CanCpuClockRef;

     //  This parameter contains a reference to the Wakeup Source for this
     //  controller as defined in the ECU State Manager. Implementation Type:
     //  reference to EcuM_WakeupSourceType
     uint32_t CanWakeupSourceRef;

     // List of Hoh id's that belong to this controller
     const Can_HardwareObjectType  * const Can_Arc_Hoh;
#if defined(CFG_CAN_USE_SYMBOLIC_CANIF_CONTROLLER_ID)
     uint8_t Can_Arc_CanIfControllerId;
#endif
//#if defined(CFG_PPC)
     /* Flags, See CAN_CTRL_XX macros */
     uint32_t Can_Arc_Flags;

     /* Number of FIFO MB in the HOH list */
     uint8_t Can_Arc_HohFifoCnt;

     /* Total number of HOHs in Can_Arc_Hoh */
     uint8_t Can_Arc_HohCnt;

     uint64_t Can_Arc_RxMailBoxMask;
     uint64_t Can_Arc_TxMailBoxMask;

     const uint8_t * const Can_Arc_MailBoxToHrh;

     PduIdType * const Can_Arc_TxPduHandles;

     uint8_t Can_Arc_TxMailboxStart;

     uint8_t Can_Arc_MailboxMax; //Used for MAXMB configuration in MCR

     uint8_t Can_Arc_NumMsgBox;//Maximum number of message boxes available per controller

//#endif
 } Can_ControllerConfigType;

typedef struct {
    const Can_ControllerConfigType *CanController;

    // Callbacks( Extension )
    const Can_CallbackType *CanCallbacks;
//#if defined(CFG_PPC)
    const  uint8_t * const ArcHthToUnit;
    const  uint8_t * const ArcHthToHoh;
    const  uint8_t * const ArcCtrlToUnit;
//#endif
} Can_ConfigSetType;

 typedef struct {
     // This is the multiple configuration set container for CAN Driver
     // Multiplicity 1..*
     const Can_ConfigSetType  *CanConfigSetPtr;
     // This container contains the parameters related each CAN
     // Driver Unit.
     // Multiplicity 1..*
     const Can_GeneralType    *CanGeneral;
 } Can_ConfigType;
 
 enum {
	 CAN_CTRL_A,
	 CAN_CTRL_B,
	 CAN_CTRL_C,
	 CAN_CTRL_D,
	 CAN_CTRL_E,
	 CAN_CTRL_F
 };

 /* Publish the configuration */
extern const Can_ConfigType CanConfigData;

void Can_Init( const Can_ConfigType *Config );
#if ( CAN_VERSION_INFO_API == STD_ON )
void Can_GetVersionInfo( Std_VersionInfoType* versioninfo);
#endif
Std_ReturnType Can_CheckBaudrate(uint8_t Controller, const uint16_t Baudrate);
Std_ReturnType Can_ChangeBaudrate(uint8_t Controller, const uint16_t Baudrate);
Can_ReturnType Can_SetControllerMode( uint8_t Controller, Can_StateTransitionType Transition );
void Can_DisableControllerInterrupts( uint8_t Controller );
void Can_EnableControllerInterrupts( uint8_t Controller );
Can_ReturnType Can_CheckWakeup( uint8_t Controller );
Can_ReturnType Can_Write( Can_HwHandleType Hth, const Can_PduType *PduInfo );
#if (CAN_USE_WRITE_POLLING == STD_ON)
void Can_MainFunction_Write( void );
#else
/** @req 4.0.3/CAN178 *//** @req 4.1.2/SWS_Can_00178 */
#define Can_MainFunction_Write()
#endif
#if (CAN_USE_READ_POLLING == STD_ON)
void Can_MainFunction_Read( void );
#else
/** @req 4.0.3/CAN180 *//** @req 4.1.2/SWS_Can_00180 */
#define Can_MainFunction_Read()
#endif
#if (CAN_USE_BUSOFF_POLLING == STD_ON)
void Can_MainFunction_BusOff( void );
#else
/** @req 4.0.3/CAN183 *//** @req 4.1.2/SWS_Can_00183 */
#define Can_MainFunction_BusOff()
#endif
#if (CAN_USE_WAKEUP_POLLING == STD_ON)
void Can_MainFunction_Wakeup( void );
#else
/** @req 4.0.3/CAN185 *//** @req 4.1.2/SWS_Can_00185 */
#define Can_MainFunction_Wakeup()
#endif
void Can_MainFunction_Mode( uint8_t Controller );

/* ArcCore specific */
#if (ARC_CAN_ERROR_POLLING == STD_ON)
void Can_Arc_MainFunction_Error( void );
#endif
void Can_Arc_GetStatistics( uint8_t controller, Can_Arc_StatisticsType * stat);
#if defined(CFG_CAN_TEST)
Can_TestType *Can_Arc_GetTestInfo( void  );
#endif

void Can_Arc_DeInit(void);

extern unsigned char Can_busoff_check();


#endif /*CAN_H_*/
