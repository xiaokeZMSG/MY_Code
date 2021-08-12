#include "Can.h"
#include "Debug.h"
#include "CanIf_Cbk.h"
#include "Can_Cfg.h"
#include "CanAppComRxCallback.h"

/* ArcCore extensions */

/* CANIF699 */
#define CAN_CONTROLLER_ID_0                 0
#define CAN_CONTROLLER_ID_1                 1
#define CAN_CONTROLLER_ID_2                 2
#define CAN_CONTROLLER_DEFAULT_BAUDRATE     500
#define CAN_CONTROLLER_SUPPORT_BAUDRATE_CNT 1
#define CAN_CPU_CLOCK_REF                   64
#define CAN_WAKEUP_SRC_REF                  0

#define CAN_MAILBOX_RX_MASK                 0x0000FFFF
#define CAN_MAILBOX_TX_MASK                 0xFFFF0000


#define CAN_MAILBOX_INDEX_0  0
#define CAN_MAILBOX_INDEX_1  1
#define CAN_MAILBOX_INDEX_2  2
#define CAN_MAILBOX_INDEX_3  3
#define CAN_MAILBOX_INDEX_4  4
#define CAN_MAILBOX_INDEX_5  5
#define CAN_MAILBOX_INDEX_6  6
#define CAN_MAILBOX_INDEX_7  7
#define CAN_MAILBOX_INDEX_8  8
#define CAN_MAILBOX_INDEX_9  9
#define CAN_MAILBOX_INDEX_10 10
#define CAN_MAILBOX_INDEX_11 11
#define CAN_MAILBOX_INDEX_12 12
#define CAN_MAILBOX_INDEX_13 13
#define CAN_MAILBOX_INDEX_14 14
#define CAN_MAILBOX_INDEX_15 15
#define CAN_MAILBOX_INDEX_16 16
#define CAN_MAILBOX_INDEX_17 17
#define CAN_MAILBOX_INDEX_18 18
#define CAN_MAILBOX_INDEX_19 19
#define CAN_MAILBOX_INDEX_20 20
#define CAN_MAILBOX_INDEX_21 21
#define CAN_MAILBOX_INDEX_22 22
#define CAN_MAILBOX_INDEX_23 23
#define CAN_MAILBOX_INDEX_24 24

#define CAN_ARC_HOH_CNT      	9//21 
#define CAN_ARC_HOH_FIFO_CNT    7
#define CAN_ARC_TXMAILBOX_START 7
#define CAN_ARC_MAILBOX_MAX     16
#define CAN_ARC_MAILBOX_NUM     16


#if 0
#define CAN_TX_ID_NM
#define CAN_TX_ID_MP5_1   				0x365 
#define CAN_TX_ID_MP5_2   				0x366 
#define CAN_TX_ID_MP5_STATE   			0x393 
#define CAN_TX_ID_MP5_AVM_CALI_REQUEST  0x395 
#define CAN_TX_ID_DIAG_RESPONSE			0x769
#endif

#define CAN_HW_FILTER_CODE_MAILBOX_0_NM    				0x412	
#define CAN_HW_FILTER_CODE_MAILBOX_1_MMI             	0x2A2
#define CAN_HW_FILTER_CODE_MAILBOX_2_HP   			    0x262
#define CAN_HW_FILTER_CODE_MAILBOX_3_IPK             	0x3F1
#define CAN_HW_FILTER_CODE_MAILBOX_4_ESC             	0x125
#define CAN_HW_FILTER_CODE_MAILBOX_5_BCM             	0x287
#define CAN_HW_FILTER_CODE_MAILBOX_DIAG_PHY_REQ   		0x730  
#define CAN_HW_FILTER_CODE_MAILBOX_DIAG_FUN_REQ   		0x7DF  
#define CAN_HW_FILTER_CODE_MAILBOX_DIAG_REPOSE   		0x738 



#define CAN_HW_FILTER_MASK_MAILBOX_NM   0x700
#define CAN_HW_FILTER_MASK_MAILBOX_7FF  0x7FF

#if 0
const uint32_t can_hw_filter_mask[FILTER_MASK_NUM] = 
{
	CAN_HW_FILTER_MASK_MAILBOX_0, 
	CAN_HW_FILTER_MASK_MAILBOX_1, 
	CAN_HW_FILTER_MASK_MAILBOX_2, 
	CAN_HW_FILTER_MASK_MAILBOX_3, 
	CAN_HW_FILTER_MASK_MAILBOX_4, 
	CAN_HW_FILTER_MASK_MAILBOX_5, 
	CAN_HW_FILTER_MASK_MAILBOX_6, 
	CAN_HW_FILTER_MASK_MAILBOX_7, 
	CAN_HW_FILTER_MASK_MAILBOX_8, 
	CAN_HW_FILTER_MASK_MAILBOX_9, 
	CAN_HW_FILTER_MASK_MAILBOX_10, 
	CAN_HW_FILTER_MASK_MAILBOX_11, 
	CAN_HW_FILTER_MASK_MAILBOX_12, 
	CAN_HW_FILTER_MASK_MAILBOX_13, 
	CAN_HW_FILTER_MASK_MAILBOX_14, 
	CAN_HW_FILTER_MASK_MAILBOX_15, 
//	CAN_HW_FILTER_MASK_MAILBOX_16, 
//	CAN_HW_FILTER_MASK_MAILBOX_17, 
//	CAN_HW_FILTER_MASK_MAILBOX_18, 
//	CAN_HW_FILTER_MASK_MAILBOX_19,
};


uint32_t CanDrv_ID_Filter[FILTER_EXT_LEN] = {
	CAN_HW_FILTER_CODE_MAILBOX_0_NM,    					
	CAN_HW_FILTER_CODE_MAILBOX_1_ts1,  	
	CAN_HW_FILTER_CODE_MAILBOX_2_ts2,   				
	CAN_HW_FILTER_CODE_MAILBOX_3_ts3,  
    CAN_HW_FILTER_CODE_MAILBOX_DIAG_PHY_REQ,
    CAN_HW_FILTER_CODE_MAILBOX_DIAG_FUN_REQ,
};
#endif
const can_cre_type CAN_RX_RULE_TABLE[CAN_RX_RULE_TABLE_NUM] = {
/*1channel of RSCAN0  reception rules */
    {CAN_HW_FILTER_CODE_MAILBOX_0_NM,         CAN_HW_FILTER_MASK_MAILBOX_NM,  0x00000000UL, 0x00000002UL}, /* NO.000 : std data frm ID = H'10~1F will be accepted, destination Rx Buffer0 */
    {CAN_HW_FILTER_CODE_MAILBOX_1_MMI,        CAN_HW_FILTER_MASK_MAILBOX_7FF, 0x00008100UL, 0x00000002UL}, /* NO.001 : std data frm ID = H'20~2F will be accepted, destination Rx Buffer1 */
    {CAN_HW_FILTER_CODE_MAILBOX_3_IPK,        CAN_HW_FILTER_MASK_MAILBOX_7FF, 0x00008200UL, 0x00000002UL}, /* NO.001 : std data frm ID = H'20~2F will be accepted, destination Rx Buffer1 */
    //{CAN_HW_FILTER_CODE_MAILBOX_DIAG_PHY_REQ, CAN_HW_FILTER_MASK_MAILBOX_7FF, 0x00008500UL, 0x00000002UL}, /* NO.005 : std data frm ID = H'60 will be accepted, destination Rx Buffer5 */
    {CAN_HW_FILTER_CODE_MAILBOX_4_ESC,        CAN_HW_FILTER_MASK_MAILBOX_7FF, 0x00008300UL, 0x00000002UL}, /* NO.001 : std data frm ID = H'20~2F will be accepted, destination Rx Buffer1 */
    {CAN_HW_FILTER_CODE_MAILBOX_5_BCM,        CAN_HW_FILTER_MASK_MAILBOX_7FF, 0x00008600UL, 0x00000002UL}, /* NO.001 : std data frm ID = H'20~2F will be accepted, destination Rx Buffer1 */ 
    {CAN_HW_FILTER_CODE_MAILBOX_DIAG_PHY_REQ, CAN_HW_FILTER_MASK_MAILBOX_7FF, 0x00008500UL, 0x00000002UL}, /* NO.005 : std data frm ID = H'60 will be accepted, destination Rx Buffer5 */
    {CAN_HW_FILTER_CODE_MAILBOX_DIAG_FUN_REQ, CAN_HW_FILTER_MASK_MAILBOX_7FF, 0x00008400UL, 0x00000002UL}, /* NO.004 : std data frm ID = H'50 will be accepted, destination Rx Buffer4 */
};


Can_CallbackType const CanCallbacks = {
#if 0
	NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#else
    CanIf_CancelTxConfirmation,
    CanIf_RxIndication,
    CanIf_ControllerBusOff,
    CanIf_TxConfirmation,
    NULL,
    NULL,
    CanIf_ControllerModeIndication,
#endif
} ;

uint8_t  ArcHthToUnit[]  = {0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // Hth mapped to controller
//uint8_t const ArcHthToHoh[]   = {8,9,10,11,12,13,14,15,16,17,18,19,20,21}; // Hth index mapped to Hoh index
//uint8_t const ArcHthToHoh[]   = {16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16};
uint8_t const ArcHthToHoh[]   = {7,7,8,5,8,9,10,11,12,13,14,15,16,17,18,19};
uint8_t  ArcCtrlToUnit[] = {0,1,2};// Controller mapped to unit  modify  by mgd  on 2018.06.27

 
Can_ControllerBaudrateConfigType const CanControllerSupportedBaudrates ={
    // Specifies the buadrate of the controller in kbps.
    500,

    // Specifies propagation delay in time quantas.
    8,//CanControllerPropSeg;

    // Specifies phase segment 1 in time quantas.
   4, //CanControllerSeg1;

    // Specifies phase segment 2 in time quantas.
   3,//CanControllerSeg2;

    // Specifies the resynchronization jump width in time quantas.
   1 //CanControllerSyncJumpWidth;
} ;


//Haedware object handle
Can_HardwareObjectType const Can_Arc_Hoh[CAN_ARC_HOH_CNT] = {//CAN_ARC_HOH_CNT=25
	{//0
		CAN_ARC_HANDLE_TYPE_FULL,
		CAN_ID_TYPE_STANDARD,
		CAN_HW_FILTER_CODE_MAILBOX_0_NM,
		CAN_MAILBOX_INDEX_0,
		CAN_OBJECT_TYPE_RECEIVE,
		CAN_HW_FILTER_MASK_MAILBOX_NM ,
		0,//2 
		CAN_MAILBOX_INDEX_0  //ArcMailboxMask;
	},
	{//1
		CAN_ARC_HANDLE_TYPE_FULL,
		CAN_ID_TYPE_STANDARD,
		CAN_HW_FILTER_CODE_MAILBOX_1_MMI,
		CAN_MAILBOX_INDEX_1,
		CAN_OBJECT_TYPE_RECEIVE,
		0xfff ,
		0,//2 
		CAN_MAILBOX_INDEX_1  
	},
	{//2
		CAN_ARC_HANDLE_TYPE_FULL,
		CAN_ID_TYPE_STANDARD,
		CAN_HW_FILTER_CODE_MAILBOX_3_IPK,
		CAN_MAILBOX_INDEX_2,
		CAN_OBJECT_TYPE_RECEIVE,
		0xfff ,
		0,//2 
		CAN_MAILBOX_INDEX_2 
	},
	{//3
		CAN_ARC_HANDLE_TYPE_FULL,
		CAN_ID_TYPE_STANDARD,
		CAN_HW_FILTER_CODE_MAILBOX_4_ESC,
		CAN_MAILBOX_INDEX_3,
		CAN_OBJECT_TYPE_RECEIVE,
		0xfff ,
		0,//2 
		CAN_MAILBOX_INDEX_3 
	},
	{//4
		CAN_ARC_HANDLE_TYPE_FULL,
		CAN_ID_TYPE_STANDARD,
		CAN_HW_FILTER_CODE_MAILBOX_5_BCM,
		CAN_MAILBOX_INDEX_4,
		CAN_OBJECT_TYPE_RECEIVE,
		0xfff ,
		0,//2 
		CAN_MAILBOX_INDEX_4 
	},

	{//5
		CAN_ARC_HANDLE_TYPE_FULL,
		CAN_ID_TYPE_STANDARD,
		CAN_HW_FILTER_CODE_MAILBOX_DIAG_PHY_REQ,
		CAN_MAILBOX_INDEX_5,
		CAN_OBJECT_TYPE_RECEIVE,
		0xfff ,
		0,//2 
		CAN_MAILBOX_INDEX_5
                //1 << CAN_MAILBOX_INDEX_16 
	},
	{//6
		CAN_ARC_HANDLE_TYPE_FULL,
		CAN_ID_TYPE_STANDARD,
		CAN_HW_FILTER_CODE_MAILBOX_DIAG_FUN_REQ,
		CAN_MAILBOX_INDEX_6,
		CAN_OBJECT_TYPE_RECEIVE,
		0xfff ,
		0,//2 
		CAN_MAILBOX_INDEX_6
	},
#if 1
	{//7
		CAN_ARC_HANDLE_TYPE_FULL,
		CAN_ID_TYPE_STANDARD,
		CAN_HW_FILTER_CODE_MAILBOX_2_HP,
		CAN_MAILBOX_INDEX_7,
		CAN_OBJECT_TYPE_TRANSMIT,
		0xfff ,
		0,//2 
		CAN_MAILBOX_INDEX_7
	},
	{//8
		CAN_ARC_HANDLE_TYPE_FULL,
		CAN_ID_TYPE_STANDARD,
		CAN_HW_FILTER_CODE_MAILBOX_DIAG_REPOSE,
		CAN_MAILBOX_INDEX_8,
		CAN_OBJECT_TYPE_TRANSMIT,
		0xfff ,
		0,//2 
		CAN_MAILBOX_INDEX_8
	},
#endif	
 } ;

uint8_t const Can_Arc_MailBoxToHrh[] = {
     CAN_MAILBOX_INDEX_0,
	 CAN_MAILBOX_INDEX_1,
	 CAN_MAILBOX_INDEX_2,
	 CAN_MAILBOX_INDEX_3,
	 CAN_MAILBOX_INDEX_4,
	 CAN_MAILBOX_INDEX_5,
	 CAN_MAILBOX_INDEX_6,
	 CAN_MAILBOX_INDEX_7,
};


uint16_t PduIdHandle[CAN_ARC_HOH_CNT - CAN_ARC_TXMAILBOX_START] ;





const Can_ControllerConfigType  CanController[] = {/*modify by mgd on 2018-06-27*/
{
    true,// CanControllerActivation;
    CAN_CONTROLLER_ID_0,
    CAN_CONTROLLER_DEFAULT_BAUDRATE,
    &CanControllerSupportedBaudrates,
    CAN_CONTROLLER_SUPPORT_BAUDRATE_CNT,
    CAN_CPU_CLOCK_REF,
    CAN_WAKEUP_SRC_REF,
    Can_Arc_Hoh,
    CAN_CTRL_RX_PROCESSING_INTERRUPT | CAN_CTRL_TX_PROCESSING_INTERRUPT | \
    CAN_CTRL_ACTIVATION | CAN_CTRL_BUSOFF_PROCESSING_INTERRUPT| \
    CAN_CTRL_FIFO,
    CAN_ARC_HOH_FIFO_CNT,
    CAN_ARC_HOH_CNT,/* Total number of HOHs in Can_Arc_Hoh */
    CAN_MAILBOX_RX_MASK,
    CAN_MAILBOX_TX_MASK,
    Can_Arc_MailBoxToHrh,
    &PduIdHandle[0],
    CAN_ARC_TXMAILBOX_START,
    CAN_ARC_MAILBOX_MAX, 
    CAN_ARC_MAILBOX_NUM
 } ,
 {/*add by mgd on 2018-06-27*/
    true,// CanControllerActivation;
	CAN_CONTROLLER_ID_1,
    CAN_CONTROLLER_DEFAULT_BAUDRATE,
    &CanControllerSupportedBaudrates,
    CAN_CONTROLLER_SUPPORT_BAUDRATE_CNT,
    CAN_CPU_CLOCK_REF,
    CAN_WAKEUP_SRC_REF,
    Can_Arc_Hoh,
     
    CAN_CTRL_RX_PROCESSING_INTERRUPT | CAN_CTRL_TX_PROCESSING_INTERRUPT | \
    CAN_CTRL_ACTIVATION | CAN_CTRL_BUSOFF_PROCESSING_INTERRUPT| \
    CAN_CTRL_FIFO,

    CAN_ARC_HOH_FIFO_CNT,
    CAN_ARC_HOH_CNT,
    CAN_MAILBOX_RX_MASK,
    CAN_MAILBOX_TX_MASK,
    Can_Arc_MailBoxToHrh,
    &PduIdHandle[0],
    CAN_ARC_TXMAILBOX_START,
    CAN_ARC_MAILBOX_MAX, 
    CAN_ARC_MAILBOX_NUM
 } ,
 {/*add by mgd on 2018-06-27*/
    true,// CanControllerActivation;
    CAN_CONTROLLER_ID_2,
    CAN_CONTROLLER_DEFAULT_BAUDRATE,
    &CanControllerSupportedBaudrates,
    CAN_CONTROLLER_SUPPORT_BAUDRATE_CNT,
    CAN_CPU_CLOCK_REF,
    CAN_WAKEUP_SRC_REF,
    Can_Arc_Hoh,
    CAN_CTRL_RX_PROCESSING_INTERRUPT | CAN_CTRL_TX_PROCESSING_INTERRUPT | \
    CAN_CTRL_ACTIVATION | CAN_CTRL_BUSOFF_PROCESSING_INTERRUPT| \
    CAN_CTRL_FIFO,
    CAN_ARC_HOH_FIFO_CNT,
    CAN_ARC_HOH_CNT,
    CAN_MAILBOX_RX_MASK,
    CAN_MAILBOX_TX_MASK,
    Can_Arc_MailBoxToHrh,
    &PduIdHandle[0],
    CAN_ARC_TXMAILBOX_START,
    CAN_ARC_MAILBOX_MAX/2, 
    CAN_ARC_MAILBOX_NUM/2
 } 
 } ;



Can_ConfigSetType const CanConfigSetPtr = {
    CanController,
    &CanCallbacks,
    ArcHthToUnit,
    ArcHthToHoh,
    ArcCtrlToUnit,
}; 

Can_GeneralType  CanGeneral = {
  0
};


const Can_ConfigType Can_Config = {
     &CanConfigSetPtr,
     &CanGeneral,
 } ;





