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

/* Code IMPROVEMENT
 * - REMOVE1
 * - REMOVE2
 * - Enable SOFT_RESET to guarantee that we get the same state every time
 *   (do in Can_InitController ?)
 */

/* ----------------------------[information]----------------------------------*/
/*
 * Author: mahi
 *
 *
 * Description:
 *   Implements the Can Driver module
 *
 * Support:
 *   General                  Have Support
 *   -------------------------------------------
 *   CAN_DEV_ERROR_DETECT            Y
 *   CAN_HW_TRANSMIT_CANCELLATION    Y
 *   CAN_IDENTICAL_ID_CANCELLATION   N
 *   CAN_INDEX                       N
 *   CAN_MULTIPLEXED_TRANSMISSION    N
 *   CAN_TIMEOUT_DURATION            N
 *   CAN_VERSION_INFO_API            N
 *
 *   Controller                  Have Support
 *   -------------------------------------------
 *   CAN_BUSOFF_PROCESSING           N  , Interrupt only
 *   CAN_RX_PROCESSING               N  , Interrupt only
 *   CAN_TX_PROCESSING               N  , Interrupt only
 *   CAN_WAKEUP_PROCESSING           N  , Interrupt only
 *   CAN_CPU_CLOCK_REFERENCE         N  , *)
 *   CanWakeupSourceRef              N  , **)
 *
 *   *) It assumes that there is a PERIPHERAL clock defined.
 *   **) The flexcan hardware cannot detect wakeup (at least now the ones
 *       this driver supports)
 *
 *   Devices    CLK_SRC
 *   ----------------------------------------------
 *   MPC5604B   ?
 *   MPC5606S   Only sys-clk it seems
 *   MPC551x    Both sys-clk and XOSC, See 3.3
 *   MPC5567    ?
 *   MPC5668    ?
 *
 *   MPC5554 is NOT supported (no individual mask)
 *
 * Implementation Notes:
 *   - Individual RXMASKs are always ON. No support for "old" chips.
 *   FIFO
 *   - Is always ON.
 *   - Is masked ONLY against 8 extended IDs
 *   - Have depth 6, with 8 ID and 8 RXMASK
 *
 *   MBOX ALLOCATION
 *     RX
 *       - First 8 boxes always allocated for RX FIFO
 *       - software filter for RX FIFO, to identify the right HRH.
 *       - HRHs are global indexed from 00
 *     TX
 *       - One HTH for each HOH (the HOH can have a number of mailboxes, in sequence)
 *       - HTHs are global (at least for each driver) indexed from 0
 *
 *    EXAMPLE ALLOCATION
 *      0 ,
 *      1  |
 *      2  |
 *      3  |   RX FIFO -> software lookup to map to right HTH
 *      4  |              1 FULL_CAN    HOH_0
 *      5  |              1 BASIC_CAN   HOH_1
 *      6  |
 *      7 锟�
 *
 *      8   RX FULL_CAN  -  HOH_2
 *      9   RX FULL_CAN  -  HOH_3
 *      10  RX BASIC_CAN  - HOH_4   |  RX with 2 boxes
 *      11                - HOH_4   |
 *      12  TX FULL_CAN   - HOH_5
 *      13  TX BASIC_CAN  - HOH_6   |  TX with 2 boxes
 *      14                - HOH_6   |
 *
 *    LOOKUP
 *      TX
 *        Can_Write(..) sends with HTH as argument. We need find the HOH first
 *        and then find one or more TX mailboxes.
 *      RX
 *        IMPROVEMENT: Add information
 *
 *    RAM USAGE:
 *      A "Can Unit":
 *      - mbToHrh, max 64  (could be moved to const... but PB problems?)
 *      - swPduHandles, max 64*2

 *  64 + 64*2 = 192*2 =
 *
 *  OBJECT MODEL
 *
 *     Can_ControllerConfigType
 *     |--- Can_Arc_Hoh -->  CanHardwareObjectConfig_CTRL_A
 *
 *     CanHardwareObjectConfig_CTRL_A
 *     |--- CanObjectId
 *
 *
 *
 *
 * Things left:
 *   All tags. Tags only on public functions now.
 *
 */
/*
 * General requirements
 * */
/** @req 4.1.2/SWS_Can_00234 *//* Mandatory interfaces */
/** @req 4.1.2/SWS_Can_00234 *//* Optional interfaces */
/** @req 4.1.2/SWS_Can_00237 *//* No transmit triggered by RTR */
/** @req 4.1.2/SWS_Can_00236 *//* No transmit triggered by RTR */
/** @req 4.1.2/SWS_Can_00238 *//* On-chip controller, does not use other drivers */
/** @req 4.1.2/SWS_Can_00280 *//* Poll hw events */
/** @req 4.1.2/SWS_Can_00058 *//* Interaction with other modules */
/** @req 4.1.2/SWS_Can_00401 *//* Multiple mbs per HTH */
/** @req 4.1.2/SWS_Can_00402 *//* Multiplexed transmission, possible to identify free mb */
/** @req 4.1.2/SWS_Can_00403 *//* Multiplexed transmission for device sending in priority (and we don't touch the LBUF bit which is 0 default ) */
/** @req 4.1.2/SWS_Can_00007 *//* Complete polling configurable */
/** @req 4.1.2/SWS_Can_00099 *//* Hw events detected by interrupt or polling */
/** @req 4.1.2/SWS_Can_00026 *//* Indicate dev errors */
/** @req 4.1.2/SWS_Can_00220 *//* Precompile variant */
/** @req 4.1.2/SWS_Can_00035 *//* No callbacks */
/** @req 4.1.2/SWS_Can_00413 *//* Can_ConfigType */
/* ----------------------------[includes]------------------------------------*/

#include "Can.h"
#include <stdio.h>
#include "CanIf_Cbk.h"
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if defined(USE_DEM)
#include "Dem.h"
#endif
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#if defined(USE_KERNEL)
#include "Os.h"
#endif
//#include "isr.h"
//#include "irq.h"
//#include "arc.h"
//#define USE_LDEBUG_PRINTF
#include "debug.h"

#include "Can_Cfg.h"

#include "r_can.h"
//#include "s32k14x_clock.h"
//#include "canCom0.h"
#include "Cpu.h"
#include "osal.h"

#include  "r_rh850_can_sfr.h"
#include  "r_rh850_can_drv.h"

/* ----------------------------[private define]------------------------------*/

#define MAX_NUM_OF_MAILBOXES    32
#define USE_CAN_STATISTICS      STD_OFF

#define INVALID_CANID 0xFFFFFFFF
#define EXTENDED_CANID_MAX 0x1FFFFFFF
// Message box status defines
#define MB_TX_ONCE              0xc
#define MB_INACTIVE             0x8
#define MB_RX                   0x4
#define MB_ABORT                0x1
#define MB_RX_OVERRUN           0x6


/* ----------------------------[private macro]-------------------------------*/

//#define CTRL_TO_UNIT_PTR(_controller)   &CanUnit[_controller]
#define CTRL_TO_UNIT_PTR(_controller)   &CanUnit[Can_Global.config->CanConfigSetPtr->ArcCtrlToUnit[_controller]]
#define VALID_CONTROLLER(_ctrl)         (Can_Global.configuredMask & (1<<(_ctrl)))
#define GET_CALLBACKS()                 (Can_Global.config->CanConfigSetPtr->CanCallbacks)

#if 0
#if defined(CFG_MPC5604P)
#define GET_CONTROLLER(_controller) 	\
        					((struct FLEXCAN_tag *)(0xFFFC0000 + 0x28000*(_controller)))
#elif defined(CFG_MPC5744P)
#define GET_CONTROLLER(_controller) ((volatile struct FLEXCAN_tag *)((uint8*)&CAN_0 + ((uint8*)&CAN_1 - (uint8*)&CAN_0) * _controller))
#else
#define GET_CONTROLLER(_controller) 	\
        					((volatile struct FLEXCAN_tag *)(0xFFFC0000 + 0x4000*(_controller)))
#endif
#else
	/*  Modify for S32K144, 
		FlexCAN0 base address: 4002_4000h
		FlexCAN1 base address: 4002_5000h
		FlexCAN2 base address: 4002_B000h
	*/
//#define GET_CONTROLLER(_controller)  ((volatile struct CAN_Type *)(CAN0_BASE + 0x1000*(_controller)))
#define GET_CONTROLLER(_controller)  ((CAN_Type *)(0xFFD00000 + 0x10*(_controller)))
        					
#endif

#define INSTALL_HANDLER4(_name, _can_entry, _vector, _priority, _app)\
	do { \
		ISR_INSTALL_ISR2(_name, _can_entry, _vector+0, _priority, _app); \
		ISR_INSTALL_ISR2(_name, _can_entry, _vector+1, _priority, _app); \
		ISR_INSTALL_ISR2(_name, _can_entry, _vector+2, _priority, _app); \
		ISR_INSTALL_ISR2(_name, _can_entry, _vector+3, _priority, _app); \
	} while(0)

#define INSTALL_HANDLER16(_name, _can_entry, _vector, _priority, _app)\
	do { \
		INSTALL_HANDLER4(_name, _can_entry, _vector+0, _priority, _app); \
		INSTALL_HANDLER4(_name, _can_entry, _vector+4, _priority, _app); \
		INSTALL_HANDLER4(_name, _can_entry, _vector+8, _priority, _app); \
		INSTALL_HANDLER4(_name, _can_entry, _vector+12,_priority, _app); \
	} while(0)

//-------------------------------------------------------------------

#if ( CAN_DEV_ERROR_DETECT == STD_ON )
/** @req 4.0.3/CAN027 */
/** @req 4.1.2/SWS_Can_00091*/
/** @req 4.1.2/SWS_Can_00089*/
#define VALIDATE(_exp,_api,_err ) \
        if( !(_exp) ) { \
          Det_ReportError(CAN_MODULE_ID,0,_api,_err); \
          return CAN_NOT_OK; \
        }

#define VALIDATE_NO_RV(_exp,_api,_err ) \
        if( !(_exp) ) { \
          Det_ReportError(CAN_MODULE_ID,0,_api,_err); \
          return; \
        }

#define DET_REPORTERROR(_x,_y,_z,_q) Det_ReportError(_x, _y, _z, _q)
#else
/** @req 4.0.3/CAN424 */
#define VALIDATE(_exp,_api,_err )
#define VALIDATE_NO_RV(_exp,_api,_err )
#define DET_REPORTERROR(_x,_y,_z,_q)
#endif

#if defined(USE_DEM)
#define VALIDATE_DEM(_exp,_err,_rv) \
        if( !(_exp) ) { \
          Dem_ReportErrorStatus(_err, DEM_EVENT_STATUS_FAILED); \
          return _rv; \
        }
#else
#define VALIDATE_DEM(_exp,_err,_rv )
#endif


/* ----------------------------[private typedef]-----------------------------*/

//typedef volatile struct FLEXCAN_tag flexcan_t;
typedef volatile struct CAN_Type flexcan_t; //Modify for S32K144.

#if defined(CFG_CAN_TEST)
Can_TestType Can_Test;
#endif

typedef enum {
    CAN_UNINIT = 0, CAN_READY
} Can_DriverStateType;

#if 0
typedef enum {
    CAN_CTRL_INDICATION_NONE,
    CAN_CTRL_INDICATION_PENDING_START,
    CAN_CTRL_INDICATION_PENDING_STOP,
    CAN_CTRL_INDICATION_PENDING_SLEEP /* Sleep is not implemented - but we need a logical sleep mode*/
} Can_CtrlPendingStateIndicationType;
#endif

/* Type for holding global information used by the driver */
typedef struct {
    Can_DriverStateType     initRun;            /* If Can_Init() have been run */
    const Can_ConfigType *  config;             /* Pointer to config */
    uint32                  configuredMask;     /* What units are configured */
} Can_GlobalType;


/* Type for holding information about each controller */
typedef struct {
    /* This unit have uses controller */
    CanControllerIdType                 controllerId;
    CanIf_ControllerModeType            state;
    const Can_ControllerConfigType *    cfgCtrlPtr;     /* Pointer to controller config  */
    const Can_HardwareObjectType *      cfgHohPtr;     /* List of HOHs */
//    flexcan_t *                         hwPtr;
    CAN_Type *                         hwPtr;
    uint32      lock_cnt;
    uint64      Can_Arc_RxMbMask;
    uint64      Can_Arc_TxMbMask;
    uint64      mbTxFree;
    uint8_t     mbMax;                              /* Max number of mailboxes used for this unit */
    uint8_t     numMbMax;                           /* Max number of mailboxes available for this unit */
    Can_CtrlPendingStateIndicationType  pendingStateIndication;
#if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
    uint64     mbTxCancel;
    uint64     suppressMbTxCancel;
#endif
#if (USE_CAN_STATISTICS == STD_ON)
    Can_Arc_StatisticsType stats;
#endif
} Can_UnitType;

/* ----------------------------[private function prototypes]-----------------*/
//void Can_Isr(void);
//void Can_Err(void);
//void Can_BusOff(void);

/* ----------------------------[private variables]---------------------------*/
#define CAN_ARC_CTRL_CONFIG_CNT  1 //CAN_INSTANCE_COUNT //3
Can_UnitType    CanUnit[CAN_ARC_CTRL_CONFIG_CNT];
//Can_GlobalType  Can_Global = { .initRun = CAN_UNINIT ,};/** @req 4.1.2/SWS_Can_00103 */
Can_GlobalType  Can_Global = { CAN_UNINIT, NULL, 0};/** @req 4.1.2/SWS_Can_00103 */

extern uint32_t CanSignalStopRecvCnt;
unsigned char diag_error_count = 0x00;
//extern uint8_t can_sleep;//For test.

extern void extern_releaseExternalRxTxBuffers();
uint32 find_fist_one(uint32 value);

/* ----------------------------[private functions]---------------------------*/

/**
 * Hardware error ISR for CAN
 *
 * @param unit CAN controller number( from 0 )
 */
uint32_t err_cn = 0;
//static TickType_t xTimeNow, xTimeLast,xBetweenTime;
/* Store the time at which this interrupt was entered. */
//static int flag = 0;
void Can_Err(uint8_t controller)
{  
#if 0
   CAN_Type * base = g_flexcanBase[controller];

   err_cn=base->ECR&0xff;
   xTimeNow = xTaskGetTickCountFromISR();
   flag = base->ESR1;
   flag&=(1<<13);
   if((flag != 0)&& ( err_cn < 5 ))
   {
     xTimeLast = xTimeNow;
   }
  
   if(( err_cn >= 0x80)&&(flag!=0))
   {
         xBetweenTime = xTimeNow - xTimeLast;
        // if(xBetweenTime>15)
        //     Can_SetControllerMode(controller, CAN_T_STOP);
   }
#endif
 //  base->ESR1 = 0x0007U;
 //  (void)(base->ESR1);
}

#if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
static void HandlePendingTxCancel(Can_UnitType *canUnit)
{
    uint8 mbNr;
    uint64_t mbCancelMask;
    //flexcan_t *canHw = canUnit->hwPtr;
    CAN_Type *canHw = canUnit->hwPtr;
    PduIdType pduId;
    PduInfoType pduInfo;
    imask_t state;
    Irq_Save(state);
    mbCancelMask = canUnit->mbTxCancel;
	uint8_t CanData[8];
	//R_CAN_AbortTrm(1);/*? add by mgd  on 20210702*/
	#if 0
    for( ; mbCancelMask; mbCancelMask &= ~(1 << mbNr) ) {
        mbNr = ilog2_64(mbCancelMask);
        canHw->BUF[mbNr].CS.B.CODE = MB_ABORT;
        // Did it take
        if (canHw->BUF[mbNr].CS.B.CODE == MB_ABORT) {
            // Aborted
            // Clear interrupt
            clearMbFlag(canHw,mbNr);
            canUnit->mbTxFree |= (1 << mbNr);
            pduId = canUnit->cfgCtrlPtr->Can_Arc_TxPduHandles[mbNr-canUnit->cfgCtrlPtr->Can_Arc_TxMailboxStart];
            pduInfo.SduLength = canHw->BUF[mbNr].CS.B.LENGTH;
            pduInfo.SduDataPtr = (uint8*)&canHw->BUF[mbNr].DATA;
            /** @req 4.0.3/CAN287 *//** @req 4.1.2/SWS_Can_00287 */
            if( NULL != GET_CALLBACKS()->CancelTxConfirmation ) {
                GET_CALLBACKS()->CancelTxConfirmation(pduId, &pduInfo);
            }
        } else {
            /* Did not take. Interrupt will be generated.
             * CancelTxConfirmation will be handled there. */
        }
        canUnit->mbTxCancel &= ~(1<<mbNr);
        canUnit->suppressMbTxCancel &= ~(1<<mbNr);
    }
	#endif
	#if 1
	 for( mbNr=0; mbNr <16; mbNr) 
	 {
        mbNr = ilog2_64(mbCancelMask);
        // Did it take
        if (MB_ABORT == R_CAN_AbortTrmMail(1, mbNr)) {
            // Aborted
            // Clear interrupt
           // clearMbFlag(canHw,mbNr);
            canUnit->mbTxFree |= (1 << mbNr);
            pduId = canUnit->cfgCtrlPtr->Can_Arc_TxPduHandles[mbNr-canUnit->cfgCtrlPtr->Can_Arc_TxMailboxStart];
           // pduInfo.SduLength = canHw->BUF[mbNr].CS.B.LENGTH;
           // pduInfo.SduDataPtr = (uint8*)&canHw->BUF[mbNr].DATA;
           R_CAN_GetAbortTrmData(1, mbNr, &pduInfo.SduLength, CanData);
		   pduInfo.SduDataPtr = CanData;
            /** @req 4.0.3/CAN287 *//** @req 4.1.2/SWS_Can_00287 */
            if( NULL != GET_CALLBACKS()->CancelTxConfirmation ) {
                GET_CALLBACKS()->CancelTxConfirmation(pduId, &pduInfo);
            }
        } else {
            /* Did not take. Interrupt will be generated.
             * CancelTxConfirmation will be handled there. */
        }
        canUnit->mbTxCancel &= ~(1<<mbNr);
        canUnit->suppressMbTxCancel &= ~(1<<mbNr);
    }
	 #endif
    Irq_Restore(state);
}
#endif

/**
 *
 * @param canHw
 * @param canUnit
 */
// Uses 25.4.5.1 Transmission Abort Mechanism
//void Can_AbortTx(flexcan_t *canHw, Can_UnitType *canUnit)
void Can_AbortTx(CAN_Type *canHw, Can_UnitType *canUnit)
{

	uint32 mbMask;
	uint8 mbNr;
	//uint32 temp;
	//int i = 0;
#if 1
	//CAN_Type * base = canHw;//；g_flexcanBase[INST_CANCOM0];
    mbMask = canUnit->Can_Arc_TxMbMask;
    for (; mbMask; mbMask &= ~(1 << mbNr)) 
	{
		mbNr = find_fist_one(mbMask);	
		R_CAN_AbortTrm(1, mbNr);
		#if 0
		canHw->RAMn[mbNr*4] |= (MB_ABORT<<24);
		if( (( canHw->RAMn[mbNr*4]>>24 ) & 0x0F) != MB_ABORT)
		{
        	  i = 0;

		  temp = canHw->IFLAG1;
                  while (temp & (1 << mbNr)) 
		  {
                     i++;
                     if (i > 1000) 
		     {
                          break;
                     }
                     temp = canHw->IFLAG1;//mgd add in 2018-08-07
                 }
                #endif
           
        }
		//FLEXCAN_HAL_ClearMsgBuffIntStatusFlag(canHw, 1UL << mbNr);
		
		canUnit->mbTxFree |= (1 << mbNr);
	#if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
		canUnit->suppressMbTxCancel |= (1<<mbNr);
		canUnit->mbTxCancel &= ~(1 << mbNr);

    }
	#endif
#endif	

}

/**
 * BusOff ISR for CAN
 *
 * @param unit CAN controller number( from 0 )
 */
void Can_BusOff(uint8_t controller)
{
#if 0
  
	CAN_Type *canHw = GET_CONTROLLER(controller);;
	Can_UnitType *canUnit = CTRL_TO_UNIT_PTR(controller);
	
//	CanSignalStopRecvCnt=0;
	
//	uint32_t esr;

//	esr = CAN0->ESR1;
	
	/* Clear ERROVR, ERRINT_FAST, BOFFDONEINT, SYNCH, TWRNINT, RWRNINT. */
	canHw->ESR1 = 0x003F0000;

	if( canHw->ESR1 & 0x00000004 )
	{
		GET_CALLBACKS()->ControllerBusOff(controller);

		/* @req SWS_Can_00020 */
        /** @req 4.0.3/CAN272 *//** @req 4.1.2/SWS_Can_00272 */
        /* NOTE: This will give an indication to CanIf that stopped is reached. Should it? */
        Can_SetControllerMode(controller, CAN_T_STOP);

		/* Clear BOFFINT, ERRINT */
		canHw->ESR1 = 0x00000007; 

		Can_AbortTx(canHw, canUnit);/** @req 4.0.3/CAN273 *//** @req 4.1.2/SWS_Can_00273 */

		if( canHw->CTRL1 & 0x00000040 ) 
		{
			canHw->CTRL1 &= 0xFFFFFFBF;
			canHw->CTRL1 |= 0x00000040;
		}
	}	

#endif

}

/**
 *
 * @param uPtr
 */


void Can_Isr_Tx(uint8_t controller,uint8_t mbNr)
{

	//uint32 flag_reg;
	//CAN_Type * base = g_flexcanBase[INST_CANCOM[controller]];
   //     flexcan_state_t * state;// = g_flexcanStatePtr[controller];
	//flexcan_msgbuff_t rx_info;
	//uint32 mask;
	//uint8 mbNr;
	PduIdType pduId;
       //uint32 err;

	Can_UnitType *uPtr = CTRL_TO_UNIT_PTR(controller);
	pduId = uPtr->cfgCtrlPtr->Can_Arc_TxPduHandles[mbNr - uPtr->cfgCtrlPtr->Can_Arc_TxMailboxStart];
	uPtr->cfgCtrlPtr->Can_Arc_TxPduHandles[mbNr - uPtr->cfgCtrlPtr->Can_Arc_TxMailboxStart] = 0;   
	  uPtr->mbTxFree |= (1 << mbNr);
     if (GET_CALLBACKS()->TxConfirmation != NULL) 
	  {
                      GET_CALLBACKS()->TxConfirmation(pduId);
     }           

}



/* Modify for S32K144.
 *
 */

void Can_Isr_Rx(uint8_t controller, can_frame_t *rx_info)
{
	//uint32 flag_reg;
	//CAN_Type * base = g_flexcanBase[INST_CANCOM[controller]];
	//flexcan_msgbuff_t rx_info;
	uint32 mask;
	uint8 fifoNr;
	Can_UnitType *uPtr = CTRL_TO_UNIT_PTR(controller);

	CanSignalStopRecvCnt = 0;

			/* Must now do a manual match to find the right CanHardwareObject
             * to pass to CanIf. We know that the FIFO objects are sorted first.
             */
		//	for (fifoNr = 0; fifoNr < uPtr->cfgCtrlPtr->Can_Arc_HohFifoCnt; fifoNr++)
        for (fifoNr = 0; fifoNr < uPtr->cfgCtrlPtr->Can_Arc_HohCnt; fifoNr++)
	{
		 mask = uPtr->cfgCtrlPtr->Can_Arc_Hoh[fifoNr].CanHwFilterMask;
                 if ((rx_info->ID & mask) != (uPtr->cfgCtrlPtr->Can_Arc_Hoh[fifoNr].CanHwFilterCode & mask)) 
		 {
		        continue;
		 }

		 if (GET_CALLBACKS()->RxIndication != NULL) 
		 {
			 GET_CALLBACKS()->RxIndication(uPtr->cfgCtrlPtr->Can_Arc_MailBoxToHrh[fifoNr], rx_info->ID, rx_info->DLC, &rx_info->DB[0]);
		 }
		 break;
        }

}




// This initiates ALL can controllers
void Can_Init(const Can_ConfigType *Config)
{
    /** @req 4.0.3/CAN223 *//** @req 4.1.2/SWS_Can_00223 */
    /** @req 4.1.2/SWS_Can_00021 */
    /** @req 4.1.2/SWS_Can_00291 */
    /** !req 4.1.2/SWS_Can_00408 */
    /** @req 4.1.2/SWS_Can_00419 *//* Disable all unused interrupts. We only enable the ones used.. */
    /** @req 4.1.2/SWS_Can_00053 *//* Don't change registers for controllers not used */
    /** @req 4.1.2/SWS_Can_00250 *//* Initialize variables, init controllers */
	int configId = 0;
    Can_UnitType *unitPtr;
    //CAN_Type *canHw;
	
    /** @req 4.0.3/CAN104 *//** @req 4.1.2/SWS_Can_00104 */
    /** @req 4.0.3/CAN174 *//** @req 4.1.2/SWS_Can_00174 */
    VALIDATE_NO_RV( (Can_Global.initRun == CAN_UNINIT), CAN_INIT_SERVICE_ID, CAN_E_TRANSITION );
    /** @req 4.0.3/CAN175 *//** @req 4.1.2/SWS_Can_00175 */
    VALIDATE_NO_RV( (Config != NULL ), CAN_INIT_SERVICE_ID, CAN_E_PARAM_POINTER );

    // Save config
    Can_Global.config = Config;
    /** !req 4.1.2/SWS_Can_00246 *//* Should be done after initializing all controllers */
    Can_Global.initRun = CAN_READY;
  
    for (configId = 0; configId < CAN_ARC_CTRL_CONFIG_CNT; configId++)/*modify by mgd on 2018-06-27*/ 
    {
	const Can_ControllerConfigType *cfgCtrlPtr  = &Can_Global.config->CanConfigSetPtr->CanController[configId];
	Can_Global.configuredMask |= (1 << cfgCtrlPtr->CanControllerId);
	unitPtr = &CanUnit[configId];

	Can_DisableControllerInterrupts(cfgCtrlPtr->CanControllerId);

	memset(unitPtr, 0, sizeof(Can_UnitType));

	unitPtr->controllerId = cfgCtrlPtr->CanControllerId;
	unitPtr->hwPtr = GET_CONTROLLER(cfgCtrlPtr->CanControllerId);
	unitPtr->numMbMax = cfgCtrlPtr->Can_Arc_NumMsgBox;
	unitPtr->cfgCtrlPtr = cfgCtrlPtr;
	/** @req 4.0.3/CAN259 *//** @req 4.1.2/SWS_Can_00259 */
	unitPtr->state = CANIF_CS_STOPPED;
	unitPtr->cfgHohPtr = cfgCtrlPtr->Can_Arc_Hoh;
	unitPtr->Can_Arc_RxMbMask = cfgCtrlPtr->Can_Arc_RxMailBoxMask;
	unitPtr->Can_Arc_TxMbMask = cfgCtrlPtr->Can_Arc_TxMailBoxMask;
	unitPtr->pendingStateIndication = CAN_CTRL_INDICATION_NONE;

	//for (configId = 0; configId < CAN_ARC_CTRL_CONFIG_CNT; configId++) /*modify by mgd on 2018-06-27*/
	//{/*modify by mgd on 2018-06-27*/
	//unitPtr = &CanUnit[configId];/*modify by mgd on 2018-06-27*/

     //ChangeBaudrate(unitPtr->controllerId, unitPtr->cfgCtrlPtr->CanControllerDefaultBaudrate);
     R_CAN_Init(unitPtr->controllerId, unitPtr->cfgCtrlPtr->CanControllerDefaultBaudrate);
	 unitPtr->mbTxFree = unitPtr->Can_Arc_TxMbMask;
    }
}

// Unitialize the module
void Can_Arc_DeInit()
{
    Can_UnitType *canUnit;
    const Can_ControllerConfigType *cfgCtrlPtr;
    uint32 ctlrId;
    int configId;
    
    if( CAN_UNINIT == Can_Global.initRun ) {
        return;
    }
    for (configId = 0; configId < CAN_ARC_CTRL_CONFIG_CNT; configId++) {
        cfgCtrlPtr = &Can_Global.config->CanConfigSetPtr->CanController[(configId)];
        ctlrId = cfgCtrlPtr->CanControllerId;

        canUnit = CTRL_TO_UNIT_PTR(ctlrId);

        Can_DisableControllerInterrupts(ctlrId);
 
        canUnit->state = CANIF_CS_UNINIT;

        canUnit->lock_cnt = 0;

#if (USE_CAN_STATISTICS == STD_ON)
        // Clear stats
        memset(&canUnit->stats, 0, sizeof(Can_Arc_StatisticsType));
#endif
    }

    Can_Global.config = NULL;
    Can_Global.initRun = CAN_UNINIT;

    return;
}



Can_ReturnType Can_SetControllerMode(uint8 Controller, Can_StateTransitionType Transition)
{
	
    /** @req 4.0.3/CAN230 *//** @req 4.1.2/SWS_Can_00230 */
    /** @req 4.0.3/CAN017 *//** @req 4.1.2/SWS_Can_00017 */
    /** !req 4.0.3/CAN294 *//** !req 4.1.2/SWS_Can_00294 *//* Wakeup not supported */
    /** !req 4.0.3/CAN197 *//** !req 4.1.2/SWS_Can_00197 *//* Disable interrupts */
    /** !req 4.0.3/CAN426 *//** !req 4.1.2/SWS_Can_00426 *//* Disable interrupts */
    /** @req 4.0.3/CAN200 *//** @req 4.1.2/SWS_Can_00200 *//* Detect invalid transitions */
    /** @req 4.1.2/SWS_Can_00404 *//* Hardware stopped while logical sleep active */
    /** @req 4.1.2/SWS_Can_00405 *//* Logical sleep left on CAN_T_WAKEUP */
    //flexcan_t *canHw;
//    CAN_Type *canHw;
//    imask_t state;
    Can_UnitType *canUnit;
    
    Can_ReturnType rv = CAN_OK;
#if 1
    /** @req 4.0.3/CAN104 *//** @req 4.1.2/SWS_Can_00104 */
    /** @req 4.0.3/CAN198 *//** @req 4.1.2/SWS_Can_00198 */
    VALIDATE( (Can_Global.initRun == CAN_READY), CAN_SETCONTROLLERMODE_SERVICE_ID, CAN_E_UNINIT );
    /** @req 4.0.3/CAN199 *//** @req 4.1.2/SWS_Can_00199 */
    VALIDATE( VALID_CONTROLLER(Controller), CAN_SETCONTROLLERMODE_SERVICE_ID, CAN_E_PARAM_CONTROLLER );
    VALIDATE( (canUnit->state!=CANIF_CS_UNINIT), CAN_SETCONTROLLERMODE_SERVICE_ID, CAN_E_UNINIT );

    canUnit = CTRL_TO_UNIT_PTR(Controller);
 //   canHw = canUnit->hwPtr;

    switch (Transition) {
    case CAN_T_START:
        /** @req 4.0.3/CAN409 *//** @req 4.1.2/SWS_Can_00409 */
        VALIDATE(canUnit->state == CANIF_CS_STOPPED, 0x3, CAN_E_TRANSITION);

        /** @req 4.0.3/CAN384 *//** @req 4.1.2/SWS_Can_00384 *//* I.e. present conf not changed */
        /** @req 4.1.2/SWS_Can_00261 */
	#if 0
        canHw->MCR.B.HALT = 0;
		canHw->MCR.B.FRZ = 0;
	#else //Modify for S32K144.
		//canHw->MCR = (canHw->MCR & ~CAN_MCR_HALT_MASK) | CAN_MCR_HALT(0U);
		//canHw->MCR = (canHw->MCR & ~CAN_MCR_FRZ_MASK) | CAN_MCR_FRZ(0U);
		
	    R_CAN_Set_NormalMode();
    //  canHw->MCR = 0xFF;
	#endif
        canUnit->state = CANIF_CS_STARTED;
    //    Irq_Save(state);
    	Disable_Interrupts();
        /** @req 4.0.3/CAN196 *//** @req 4.1.2/SWS_Can_00196 */
        /** @req 4.0.3/CAN425 *//** @req 4.1.2/SWS_Can_00425 */
        if (canUnit->lock_cnt == 0)
        {
            Can_EnableControllerInterrupts(Controller);
        }

    //    Irq_Restore(state);
    	Enable_Interrupts();
        canUnit->pendingStateIndication = CAN_CTRL_INDICATION_PENDING_START;
        break;
    case CAN_T_WAKEUP:
        /** @req 4.0.3/CAN267 *//** @req 4.1.2/SWS_Can_00267 */
        /** @req 4.0.3/CAN412 *//** @req 4.1.2/SWS_Can_00412 */
        VALIDATE(canUnit->state == CANIF_CS_SLEEP || canUnit->state == CANIF_CS_STOPPED, 0x3, CAN_E_TRANSITION);

        // Wake from logical sleep mode or stop
    #if 0
        canHw->MCR.B.HALT = 1;
	#else //Modify for S32K144.
		//canHw->MCR = (canHw->MCR & ~CAN_MCR_HALT_MASK) | CAN_MCR_HALT(1U);
		R_CAN_Set_NormalMode();
	#endif
        canUnit->state = CANIF_CS_STOPPED;
        canUnit->pendingStateIndication = CAN_CTRL_INDICATION_PENDING_STOP;
        break;
    case CAN_T_SLEEP:
        /** @req 4.0.3/CAN411 *//** @req 4.1.2/SWS_Can_00411 */
        /** @req 4.0.3/CAN258 *//** @req 4.1.2/SWS_Can_00258 */
        /** @req 4.0.3/CAN290 *//** @req 4.1.2/SWS_Can_00290 */
        /** !req 4.1.2/SWS_Can_00265 */
        VALIDATE(canUnit->state == CANIF_CS_STOPPED, 0x3, CAN_E_TRANSITION);

        // Logical sleep mode = Stop
	#if 0
        canHw->MCR.B.HALT = 1;
	#else //Modify for S32K144.
		//canHw->MCR = (canHw->MCR & ~CAN_MCR_HALT_MASK) | CAN_MCR_HALT(1U);
		R_CAN_Set_HaltMode();
	#endif
        canUnit->state = CANIF_CS_SLEEP;
        /** @req 4.1.2/SWS_Can_00283 *//* Can_AbortTx does not notify cancellation */
        //Can_AbortTx(canHw, canUnit);
        canUnit->pendingStateIndication = CAN_CTRL_INDICATION_PENDING_SLEEP;
        break;
    case CAN_T_STOP:
        /** @req 4.0.3/CAN410 *//** @req 4.1.2/SWS_Can_00410 */
        VALIDATE(canUnit->state == CANIF_CS_STARTED || canUnit->state == CANIF_CS_STOPPED, 0x3, CAN_E_TRANSITION);

        // Stop
        /** @req 4.1.2/SWS_Can_00263 */
	#if 0
        canHw->MCR.B.HALT = 1;
	#else //Modify for S32K144.
		//canHw->MCR = (canHw->MCR & ~CAN_MCR_HALT_MASK) | CAN_MCR_HALT(1U);
		R_CAN_Set_HaltMode();
	#endif
        canUnit->state = CANIF_CS_STOPPED;
        //Can_AbortTx(canHw, canUnit); /** @req 4.0.3/CAN282 *//** @req 4.1.2/SWS_Can_00282 */
        canUnit->pendingStateIndication = CAN_CTRL_INDICATION_PENDING_STOP;
        break;
    default:
        /** @req 4.0.3/CAN200 *//** @req 4.1.2/SWS_Can_00200 */
        VALIDATE(0, 0x3, CAN_E_TRANSITION); // Undefined state transition shall always raise CAN_E_TRANSITION
        break;
    }
#endif
    return rv;
}

void Can_DisableControllerInterrupts(uint8 Controller)
{
    /** @req 4.0.3/CAN231 *//** @req 4.1.2/SWS_Can_00231 */
    /** @req 4.0.3/CAN202 *//** @req 4.1.2/SWS_Can_00202 */
    /** !req 4.0.3/CAN204 *//** !req 4.1.2/SWS_Can_00204 */
	Can_UnitType *canUnit;
//	flexcan_t *canHw;
   // CAN_Type *canHw;
//	imask_t state;
	
	VALIDATE_NO_RV( (Can_Global.initRun == CAN_READY), CAN_DISABLECONTROLLERINTERRUPTS_SERVICE_ID, CAN_E_UNINIT );
    /** @req 4.0.3/CAN206 *//** @req 4.1.2/SWS_Can_00206*/
    VALIDATE_NO_RV( VALID_CONTROLLER(Controller) , CAN_DISABLECONTROLLERINTERRUPTS_SERVICE_ID, CAN_E_PARAM_CONTROLLER );
    /** @req 4.0.3/CAN205 *//** @req 4.1.2/SWS_Can_00205 */
    VALIDATE_NO_RV( (canUnit->state!=CANIF_CS_UNINIT), CAN_DISABLECONTROLLERINTERRUPTS_SERVICE_ID, CAN_E_UNINIT );

	canUnit = CTRL_TO_UNIT_PTR(Controller);
//    Irq_Save(state);
	Disable_Interrupts();

    /** @req 4.0.3/CAN049 *//** @req 4.1.2/SWS_Can_00049 */
	if (canUnit->lock_cnt > 0) 
	{
	//  Interrupts already disabled
		canUnit->lock_cnt++;
	//	Irq_Restore(state);
		Enable_Interrupts();
		return;
	}
    canUnit->lock_cnt++;
//    Irq_Restore(state); 
	Enable_Interrupts();

    /* Don't try to be intelligent, turn everything off */
   // canHw = GET_CONTROLLER(Controller);

#if 0
    /* Turn off the interrupt mailboxes */
    if (canUnit->numMbMax > 32) {
        canHw->IMRH.R = 0;
    }
    canHw->IMRL.R = 0;

    /* Turn off the bus off/tx warning/rx warning and error */
    canHw->MCR.B.WRNEN = 0; /* Disable warning int */
    canHw->CR.B.ERRMSK = 0; /* Disable error interrupt */
    canHw->CR.B.BOFFMSK = 0; /* Disable bus-off interrupt */
    canHw->CR.B.TWRNMSK = 0; /* Disable Tx warning */
    canHw->CR.B.RWRNMSK = 0; /* Disable Rx warning */
#else //Modify for S32K144.
#if 0
	canHw->IMASK1 = (canHw->IMASK1 & ~CAN_IMASK1_BUF31TO0M_MASK) | CAN_IMASK1_BUF31TO0M(0);
	canHw->MCR = (canHw->MCR & ~CAN_MCR_WRNEN_MASK) | CAN_MCR_WRNEN(0);
	canHw->CTRL1 = (canHw->CTRL1 & ~CAN_CTRL1_ERRMSK_MASK) | CAN_CTRL1_ERRMSK(0);
	canHw->CTRL1 = (canHw->CTRL1 & ~CAN_CTRL1_BOFFMSK_MASK) | CAN_CTRL1_BOFFMSK(0);
	canHw->CTRL1 = (canHw->CTRL1 & ~CAN_CTRL1_TWRNMSK_MASK) | CAN_CTRL1_TWRNMSK(0);
	canHw->CTRL1 = (canHw->CTRL1 & ~CAN_CTRL1_RWRNMSK_MASK) | CAN_CTRL1_RWRNMSK(0);
#endif
#endif
}

void Can_EnableControllerInterrupts(uint8 Controller)
{
    /** @req 4.0.3/CAN232 *//** @req 4.1.2/SWS_Can_00232 */
    /** @req 4.0.3/CAN050 *//** @req 4.1.2/SWS_Can_00050 */

    Can_UnitType *canUnit;
//  flexcan_t *canHw;
//	CAN_Type *canHw;
//    imask_t state;

    /** @req 4.0.3/CAN209 *//** @req 4.1.2/SWS_Can_00209 */
	VALIDATE_NO_RV( (Can_Global.initRun == CAN_READY), CAN_ENABLECONTROLLERINTERRUPTS_SERVICE_ID, CAN_E_UNINIT );
    /** @req 4.0.3/CAN210 *//** @req 4.1.2/SWS_Can_00210 */
    VALIDATE_NO_RV( VALID_CONTROLLER(Controller), CAN_ENABLECONTROLLERINTERRUPTS_SERVICE_ID, CAN_E_PARAM_CONTROLLER );
    canUnit = CTRL_TO_UNIT_PTR(Controller);
    VALIDATE_NO_RV( (canUnit->state!=CANIF_CS_UNINIT), CAN_ENABLECONTROLLERINTERRUPTS_SERVICE_ID, CAN_E_UNINIT );


    	Disable_Interrupts();
    if (canUnit->lock_cnt > 0) {
        canUnit->lock_cnt--;
    }
    if (canUnit->lock_cnt > 0){
        Enable_Interrupts();
        return;
    }
	Enable_Interrupts();


}


uint32 find_fist_one(uint32 value)
{
	uint32 cnt = 0;
	uint32 position = 0;
	
	while(value > 0)
	{	
               
		if(value & 0x0001)
		{
			position = cnt;
			return position;
		}
		value >>= 1;
                 ++cnt;
	}
	
	return position;
}

/* Modify for S32K144.
 *
 */
 
Can_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType *PduInfo)
{
    uint32_t rtncode ;
//	uint32 iflag;
//	uint32 iHwFlag;
	uint32 mbNr;
//        uint8_t ControllerId ;
       // static int testcn=0;
//	flexcan_t *canHw;
//    CAN_Type *canHw;
	const Can_HardwareObjectType *hohObj;
    Can_UnitType *canUnit;
	Can_ReturnType rv = CAN_OK;
//	imask_t state;
	
	canUnit = &CanUnit[Can_Global.config->CanConfigSetPtr->ArcHthToUnit[Hth]];
    hohObj  =  &canUnit->cfgHohPtr[Can_Global.config->CanConfigSetPtr->ArcHthToHoh[Hth]];
//    canHw   =  canUnit->hwPtr;
//	ControllerId=canUnit->controllerId;
	Disable_Interrupts();
	{
  	can_frame_t pFrame;
	mbNr = hohObj->CanObjectId;
	pFrame.RTR = 0;
	pFrame.IDE = 0;
	pFrame.ID = PduInfo->id;
	pFrame.DLC = PduInfo->length;
	memcpy(pFrame.DB,PduInfo->sdu,pFrame.DLC);
    rtncode = R_CAN_TrmByTxBuf(1,mbNr,&pFrame);
	if(CAN_RTN_STS_ERROR == rtncode )
	{
	    rv = CAN_BUSY;
	}
	else 
	{
	   canUnit->cfgCtrlPtr->Can_Arc_TxPduHandles[mbNr-canUnit->cfgCtrlPtr->Can_Arc_TxMailboxStart] = PduInfo->swPduHandle;
	}
  }

	Enable_Interrupts(); 

    return rv;
}

Can_ReturnType Can_CheckWakeup( uint8 Controller ) {
    /** !req 4.0.3/CAN360 *//** !req 4.1.2/SWS_Can_00360 */
    /** !req 4.0.3/CAN361 *//** !req 4.1.2/SWS_Can_00361 */
    /** !req 4.0.3/CAN362 *//** !req 4.1.2/SWS_Can_00362 */
    /** !req 4.0.3/CAN363 *//** !req 4.1.2/SWS_Can_00363 */
    /** !req 4.1.2/SWS_Can_00484 */
    /** !req 4.1.2/SWS_Can_00485 */

    /* NOT SUPPORTED */
	(void)Controller;
	return CAN_NOT_OK;
}

#if (CAN_USE_WRITE_POLLING == STD_ON)
void Can_MainFunction_Write( void ) {
    /** @req 4.0.3/CAN225 *//** @req 4.1.2/SWS_Can_00225 */
    /** @req 4.0.3/CAN031 *//** @req 4.1.2/SWS_Can_00031 */
    /** !req 4.1.2/SWS_Can_00441 */

    Can_UnitType *uPtr;

    /** @req 4.0.3/CAN179 *//** @req 4.1.2/SWS_Can_00179 *//* CAN_E_UNINIT */
    VALIDATE_NO_RV( (Can_Global.initRun == CAN_READY), CAN_MAINFUNCTION_WRITE_SERVICE_ID, CAN_E_UNINIT );

    /** @req 4.0.3/CAN431 *//* On Uninit, return immediately without prod err */
    if (Can_Global.initRun == CAN_UNINIT) {
        return;
    }

    for(int i=0;i<CAN_ARC_CTRL_CONFIG_CNT; i++ ) {
        uPtr = &CanUnit[i];
        if( (uPtr->cfgCtrlPtr->Can_Arc_Flags & CAN_CTRL_TX_PROCESSING_INTERRUPT) == 0 ) {
            Can_Isr_Tx(uPtr);
        }
    }
}
#endif

#if (CAN_USE_READ_POLLING == STD_ON)
void Can_MainFunction_Read(void)
{
    /** @req 4.0.3/CAN226 *//** @req 4.1.2/SWS_Can_00226 */
    /** @req 4.0.3/CAN108 *//** @req 4.1.2/SWS_Can_00108 */
    /** !req 4.1.2/SWS_Can_00442 */

    Can_UnitType *uPtr;

    /** @req 4.0.3/CAN181 *//** @req 4.1.2/SWS_Can_00181 *//* CAN_E_UNINIT */
    VALIDATE_NO_RV( (Can_Global.initRun == CAN_READY), CAN_MAINFUNCTION_READ_SERVICE_ID, CAN_E_UNINIT );

    /** @req 4.0.3/CAN431 *//* On Uninit, return immediately without prod err */
    if (Can_Global.initRun == CAN_UNINIT) {
        return;
    }

    for(int i=0;i<CAN_ARC_CTRL_CONFIG_CNT; i++ ) {
        uPtr = &CanUnit[i];
        if( (uPtr->cfgCtrlPtr->Can_Arc_Flags & CAN_CTRL_RX_PROCESSING_INTERRUPT) == 0 ) {
            Can_Isr_Rx(uPtr);
        }
    }
}
#endif

#if (CAN_USE_BUSOFF_POLLING == STD_ON)
void Can_MainFunction_BusOff(void)
{
    /** @req 4.0.3/CAN227 *//** @req 4.1.2/SWS_Can_00227 */
    /** @req 4.0.3/CAN109 *//** @req 4.1.2/SWS_Can_00109 */

    /* Bus-off polling events */

    Can_UnitType *uPtr;

    /** @req 4.0.3/CAN184 *//** @req 4.1.2/SWS_Can_00184 *//* CAN_E_UNINIT */
    VALIDATE_NO_RV( (Can_Global.initRun == CAN_READY), CAN_MAINFUNCTION_BUSOFF_SERVICE_ID, CAN_E_UNINIT );

    /** @req 4.0.3/CAN431 *//* On Uninit, return immediately without prod err */
    if (Can_Global.initRun == CAN_UNINIT) {
        return;
    }

    for(int i=0;i<CAN_ARC_CTRL_CONFIG_CNT; i++ ) {
        uPtr = &CanUnit[i];
        if( (uPtr->cfgCtrlPtr->Can_Arc_Flags & CAN_CTRL_BUSOFF_PROCESSING_INTERRUPT) == 0 ) {
        	Can_BusOff(i);
        }
    }
}
#endif

#if (ARC_CAN_ERROR_POLLING == STD_ON)
void Can_Arc_MainFunction_Error(void)
{
    /* Error polling events */
    // NOTE: remove function (not in req spec)

    Can_UnitType *uPtr;
    VALIDATE_NO_RV( (Can_Global.initRun == CAN_READY), CAN_MAINFUNCTION_ERROR_SERVICE_ID, CAN_E_UNINIT );

    if (Can_Global.initRun == CAN_UNINIT) {
        return;
    }
    for(int i=0;i<CAN_ARC_CTRL_CONFIG_CNT; i++ ) {
        uPtr = &CanUnit[i];
        if( uPtr->cfgCtrlPtr->Can_Arc_Flags & CAN_CTRL_ERROR_PROCESSING_INTERRUPT == 0) {
        	Can_Err(uPtr->controllerId);
        }
    }
}
#endif

#if (CAN_USE_WAKEUP_POLLING == STD_ON)
void Can_MainFunction_Wakeup(void)
{
    /** !req 4.0.3/CAN228 *//** !req 4.1.2/SWS_Can_00228 */
    /** !req 4.0.3/CAN112 *//** !req 4.1.2/SWS_Can_00112 */
    /** !req 4.0.3/CAN186 *//** !req 4.1.2/SWS_Can_00186 */
    /* Wakeup polling events */

    /* NOT SUPPORTED */
}
#endif

void Can_MainFunction_Mode( uint8_t Controller )
{
    /** @req 4.0.3/CAN368 *//** @req 4.1.2/SWS_Can_00368 *//* API */
    /** @req 4.0.3/CAN369 *//** @req 4.1.2/SWS_Can_00369 *//* Polling */

    /** !req 4.0.3/CAN398 *//** !req 4.1.2/SWS_Can_00398 *//* Blocking call not supported */
    /** !req 4.0.3/CAN371 *//** !req 4.1.2/SWS_Can_00371 *//* Blocking call not supported */
    /** !req 4.0.3/CAN372 *//** !req 4.1.2/SWS_Can_00372 *//* Blocking call not supported */

    Can_UnitType *uPtr;
    int i;
#if 1
    /** @req 4.0.3/CAN379 *//** @req 4.1.2/SWS_Can_00379 *//* CAN_E_UNINIT */
    VALIDATE_NO_RV( (Can_Global.initRun == CAN_READY), CAN_MAIN_FUNCTION_MODE_SERVICE_ID, CAN_E_UNINIT );

    uPtr = CTRL_TO_UNIT_PTR(Controller);
    if(uPtr->cfgCtrlPtr->Can_Arc_Flags & CAN_CTRL_RX_PROCESSING_INTERRUPT ){
        //Can_Isr_Rx(uPtr);
    }
    /** @req 4.0.3/CAN431 *//* On Uninit, return immediately without prod err */
    if (Can_Global.initRun == CAN_UNINIT) {
        return;
    }

    for(i=0;i<CAN_ARC_CTRL_CONFIG_CNT; i++ )
    {
        boolean clearPending = TRUE;
        CanIf_ControllerModeType indicateMode = CANIF_CS_UNINIT;
        uPtr = &CanUnit[i];
        switch (uPtr->pendingStateIndication)
        {
            case CAN_CTRL_INDICATION_PENDING_START:
                if (uPtr->state == CANIF_CS_STARTED) {
                  //  if ((uPtr->hwPtr->MCR & CAN_MCR_HALT_MASK) == 0) {
                  if ((R_CAN_Get_Status(1)) == 0) {
                        // NOTRDY==0 FlexCAN module is either in normal mode, listen-only mode or loop-back mode
                        // Started OK, indicate to upper layer
                        indicateMode = CANIF_CS_STARTED;
                    } else {
                        // NOTRDY==1 FlexCAN module is either disabled or freeze mode
                        // Not yet ready
                        clearPending = FALSE;
                    }
                }
                break;

            case CAN_CTRL_INDICATION_PENDING_STOP:
                if (uPtr->state == CANIF_CS_STOPPED) {
                    // Stopped, indicate to upper layer
                    indicateMode = CANIF_CS_STOPPED;
                }
                break;

            case CAN_CTRL_INDICATION_PENDING_SLEEP:
                if (uPtr->state == CANIF_CS_SLEEP) {
                    // Stopped, indicate to upper layer
                    indicateMode = CANIF_CS_SLEEP;
                }
                break;


            case CAN_CTRL_INDICATION_NONE:
            default:
                // No action necessary
                clearPending = FALSE;
                break;
        }
        if( (CANIF_CS_UNINIT != indicateMode) && (NULL != GET_CALLBACKS()->ControllerModeIndication) ) {
            /** @req 4.0.3/CAN370 *//** @req 4.1.2/SWS_Can_00370 */
            /** @req 4.0.3/CAN373 *//** @req 4.1.2/SWS_Can_00373 */
#if defined(CFG_CAN_USE_SYMBOLIC_CANIF_CONTROLLER_ID)
            GET_CALLBACKS()->ControllerModeIndication(uPtr->cfgCtrlPtr->Can_Arc_CanIfControllerId, indicateMode);
#else
            GET_CALLBACKS()->ControllerModeIndication(uPtr->controllerId, indicateMode);
#endif
        }
        if (clearPending) {
            uPtr->pendingStateIndication = CAN_CTRL_INDICATION_NONE;
        }
#if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
        if(0 != uPtr->mbTxCancel) {
            HandlePendingTxCancel(uPtr);
        }
#endif
    }
#endif
}

#if ( CAN_VERSION_INFO_API == STD_ON )
void Can_GetVersionInfo( Std_VersionInfoType* versioninfo) {

    /* @req SWS_Can_00224 */
    /* @req SWS_Can_00177 */
    VALIDATE_NO_RV( ( NULL != versioninfo ), CAN_GETVERSIONINFO_SERVICE_ID, CAN_E_PARAM_POINTER);

    versioninfo->vendorID = CAN_VENDOR_ID;
    versioninfo->moduleID = CAN_MODULE_ID;
    versioninfo->sw_major_version = CAN_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = CAN_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = CAN_SW_PATCH_VERSION;
}
#endif

#if (USE_CAN_STATISTICS == STD_ON)
/**
 * Get send/receive/error statistics for a controller
 *
 * @param controller The controller
 * @param stats Pointer to data to copy statistics to
 */


void Can_Arc_GetStatistics(uint8 controller, Can_Arc_StatisticsType *stats)
{
	if(Can_Global.initRun == CAN_READY)
	{
		Can_UnitType *canUnit = CTRL_TO_UNIT_PTR(controller);
		*stats = canUnit->stats;
	}
}
#endif

 



void HalCanWakeUpEnable(void)
{
}
void HalCanWakeUpDisable(void)
{
	//INT_SYS_DisableIRQ(PORTE_IRQn);
}

