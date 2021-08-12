
#include "CanIf_Cfg.h"


#define CONTROLLER_ID_0 0
#define CONTROLLER_ID_1 1
#define HTH_ID_0 0
#define HTH_ID_1 1
#define HTH_ID_2 2
#define HTH_ID_3 3
#define HTH_ID_4 4
#define HTH_ID_5 5
#define HTH_ID_6 6
#define HTH_ID_7 7


#define TX_BUFFER_NUM 3

#define TX_BUFFER_ID_0 0
#define TX_BUFFER_ID_1 1
#define TX_BUFFER_ID_2 2
#define TX_BUFFER_ID_3 3
#define TX_BUFFER_ID_4 4
#define TX_BUFFER_ID_5 5
#define TX_BUFFER_ID_6 6

#define CANIF_TXPDU_ID_0 0
#define CANIF_TXPDU_ID_1 1
#define CANIF_TXPDU_ID_2 2
#define CANIF_TXPDU_ID_3 3
#define CANIF_TXPDU_ID_4 4
#define CANIF_TXPDU_ID_5 5
#define CANIF_TXPDU_ID_6 6

#define CANIF_RXPDU_ID_0 0
#define CANIF_RXPDU_ID_1 1
#define CANIF_RXPDU_ID_2 2
#define CANIF_RXPDU_ID_3 3
#define CANIF_RXPDU_ID_4 4
#define CANIF_RXPDU_ID_5 5
#define CANIF_RXPDU_ID_6 6
#define CANIF_RXPDU_ID_7 7
#define CANIF_RXPDU_ID_8 8
#define CANIF_RXPDU_ID_9 9
#define CANIF_RXPDU_ID_10 10
#define CANIF_RXPDU_ID_11 11
#define CANIF_RXPDU_ID_12 12
#define CANIF_RXPDU_ID_13 13
#define CANIF_RXPDU_ID_14 14
#define CANIF_RXPDU_ID_15 15
#define CANIF_RXPDU_ID_16 16
#define CANIF_RXPDU_ID_17 17
#define CANIF_RXPDU_ID_18 18
#define CANIF_RXPDU_ID_19 19
#define CANIF_RXPDU_ID_20 20
#define CANIF_RXPDU_ID_21 21
#define CANIF_RXPDU_ID_22 22
#define CANIF_RXPDU_ID_23 23
#define CANIF_RXPDU_ID_24 24

#define CANIF_NUMBER_OF_RXPDUID   7//21
#define CANIF_NUMBER_OF_TXPDUID   3
#define CANIF_NUMBER_OF_TXBUFFER  3

#define CANIFRX_CANNM_INDICATION   0
#define CANIFRX_COM_INDICATION     1
#define CANIFRX_TP_INDICATION      2

#define CANIFTX_CANNM_INDICATION   0
#define CANIFTX_COM_INDICATION     1
#define CANIFTX_TP_INDICATION      2



CanIf_HthConfigType const  CanIf_HthConfig[] = {
    {
        CAN_ARC_HANDLE_TYPE_FULL,
        CONTROLLER_ID_0,//Ccontroller id
        HTH_ID_0,//anIfHthIdSymRef ;
        false,//anIf_Arc_EOL;
    },
    {
        CAN_ARC_HANDLE_TYPE_FULL,
        CONTROLLER_ID_0,//Ccontroller id
        HTH_ID_1,//anIfHthIdSymRef ;
        false,//anIf_Arc_EOL;
    },
    {
        CAN_ARC_HANDLE_TYPE_FULL,
        CONTROLLER_ID_0,//Ccontroller id
        HTH_ID_2,//anIfHthIdSymRef ;
        false,//anIf_Arc_EOL;
    },
    {
		CAN_ARC_HANDLE_TYPE_FULL,
		CONTROLLER_ID_0,//Ccontroller id
		HTH_ID_3,//anIfHthIdSymRef ;
		false,//anIf_Arc_EOL;
     },
     {
		CAN_ARC_HANDLE_TYPE_FULL,
		CONTROLLER_ID_0,//Ccontroller id
		HTH_ID_4,//anIfHthIdSymRef ;
		false,//anIf_Arc_EOL;
     },
     {
		CAN_ARC_HANDLE_TYPE_FULL,
		CONTROLLER_ID_0,//Ccontroller id
		HTH_ID_5,//anIfHthIdSymRef ;
		false,//anIf_Arc_EOL;
     },
     {
		CAN_ARC_HANDLE_TYPE_FULL,
		CONTROLLER_ID_0,//Ccontroller id
		HTH_ID_6,//anIfHthIdSymRef ;
		false,//anIf_Arc_EOL;
     },
      {//end
		CAN_ARC_HANDLE_TYPE_FULL,
		CONTROLLER_ID_0,//Ccontroller id
		HTH_ID_6,//anIfHthIdSymRef ;
		true,//anIf_Arc_EOL;
     },
} ;


CanIf_TxBufferConfigType const  CanIf_TxBufferConfig[] ={
    {
	    &CanIf_HthConfig[0],
	    2,//CanIfBufferSize;
	    TX_BUFFER_ID_0,//CanIf_Arc_BufferId;
    },
    {
	    &CanIf_HthConfig[1],
	    2,//CanIfBufferSize;
	    TX_BUFFER_ID_1,//CanIf_Arc_BufferId;
    },
    {
	    &CanIf_HthConfig[2],
	    2,//CanIfBufferSize;
	    TX_BUFFER_ID_2,//CanIf_Arc_BufferId;
    },
 
} ;


CanIf_TxPduConfigType  const CanIf_TxPduConfig[] = {
	{
		 CANIF_TXPDU_ID_0,	   // CanIfTxPduId;
		 0x410, //anIfCanTxPduIdCanId;
		 8, 	//CanIfCanTxPduIdDlc;
		 CANIF_PDU_TYPE_STATIC,
		 CANIF_CAN_ID_TYPE_11,
		 CANIFTX_CANNM_INDICATION,// CanIfUserTxConfirmation;
		 &CanIf_TxBufferConfig[0],
		 NULL,//void *PduIdRef;
	 },
	{
		 CANIF_TXPDU_ID_1,	   // CanIfTxPduId;
		 0x226, //anIfCanTxPduIdCanId;
		 8, 	//CanIfCanTxPduIdDlc;
		 CANIF_PDU_TYPE_STATIC,
		 CANIF_CAN_ID_TYPE_11,
		 CANIFTX_COM_INDICATION,// CanIfUserTxConfirmation;
		 &CanIf_TxBufferConfig[1],
		 NULL,//void *PduIdRef;
	 },
	 {
		 CANIF_TXPDU_ID_2, 	// CanIfTxPduId;
		 0x738, //anIfCanTxPduIdCanId;
		 8, 	//CanIfCanTxPduIdDlc;
		 CANIF_PDU_TYPE_STATIC,
		 CANIF_CAN_ID_TYPE_11,
		 CANIFTX_TP_INDICATION,// CanIfUserTxConfirmation;
		 &CanIf_TxBufferConfig[2],
		 NULL,//void *PduIdRef;
	 },
} ;

CanIf_HrhRangeConfigType const CanIf_HrhRangeConfig ={
	0x400,
	0x43f
} ;


CanIf_HrhConfigType const CanIf_HrhConfig[] = {
    {// 0
        CAN_ARC_HANDLE_TYPE_FULL,
	    false, //software filter
	    0,//controller id
	    0,//hrh id
	    &CanIf_HrhRangeConfig,
        false
    },
    {// 1
        CAN_ARC_HANDLE_TYPE_FULL,
	    false, //software filter
	    0,//controller id
	    1,//hrh id
	    &CanIf_HrhRangeConfig,
        false
    },
   
    {// 2
        CAN_ARC_HANDLE_TYPE_FULL,
	    false, //software filter
	    0,//controller id
	    2,//hrh id
	    &CanIf_HrhRangeConfig,
        false
    },  
    {// 3
        CAN_ARC_HANDLE_TYPE_FULL,
	    false, //software filter
	    0,//controller id
	    3,//hrh id
	    &CanIf_HrhRangeConfig,
        false
    },  
     {// 4
        CAN_ARC_HANDLE_TYPE_FULL,
	    false, //software filter
	    0,//controller id
	    4,//hrh id
	    &CanIf_HrhRangeConfig,
        false
    }, 
      {// 5
        CAN_ARC_HANDLE_TYPE_FULL,
	    false, //software filter
	    0,//controller id
	    5,//hrh id
	    &CanIf_HrhRangeConfig,
        false
    }, 
      {// 6
        CAN_ARC_HANDLE_TYPE_FULL,
	    false, //software filter
	    0,//controller id
	    6,//hrh id
	    &CanIf_HrhRangeConfig,
        false
    }, 
      {// end
        CAN_ARC_HANDLE_TYPE_FULL,
	    false, //software filter
	    0,//controller id
	    3,//hrh id
	    &CanIf_HrhRangeConfig,
        true
    }, 
} ;


CanIf_RxPduConfigType const CanIf_RxPduConfig[] = {
    {// 0x4xx
        CANIF_RXPDU_ID_0, //pdu id
	    0x400,
	    0x43f,
	    8,	
	    CANIF_CAN_ID_TYPE_11,
	    CANIFRX_CANNM_INDICATION,//CanIfUserRxIndication;
	    &CanIf_HrhConfig[0],
	    NULL,//*PduIdRef;
	    0xFFF// CanIfCanRxPduCanIdMask;
    },
    {// 0x02A2
        CANIF_RXPDU_ID_1, //pdu id
	    0x2A2,
	    0x2FF,
	    8,		
	    CANIF_CAN_ID_TYPE_11,
	    CANIFRX_COM_INDICATION,//CanIfUserRxIndication;
	    &CanIf_HrhConfig[1],
	    NULL,//*PduIdRef;
	    0xFFF// CanIfCanRxPduCanIdMask;
    },
     {// IPK 0x03f1
        CANIF_RXPDU_ID_2, //pdu id
	    0x3f1,
	    0x3FF,
	    8,		
	    CANIF_CAN_ID_TYPE_11,
	    CANIFRX_COM_INDICATION,//CanIfUserRxIndication;
	    &CanIf_HrhConfig[2],
	    NULL,//*PduIdRef;
	    0xFFF// CanIfCanRxPduCanIdMask;
    },
       {// ESC 0x0125
        CANIF_RXPDU_ID_3, //pdu id
	    0x125,
	    0x2FF,
	    8,		
	    CANIF_CAN_ID_TYPE_11,
	    CANIFRX_COM_INDICATION,//CanIfUserRxIndication;
	    &CanIf_HrhConfig[3],
	    NULL,//*PduIdRef;
	    0xFFF// CanIfCanRxPduCanIdMask;
    },
       {// BCM 0x0287
        CANIF_RXPDU_ID_4, //pdu id
	    0x287,
	    0x2FF,
	    8,		
	    CANIF_CAN_ID_TYPE_11,
	    CANIFRX_COM_INDICATION,//CanIfUserRxIndication;
	    &CanIf_HrhConfig[4],
	    NULL,//*PduIdRef;
	    0xFFF// CanIfCanRxPduCanIdMask;
    },

#if 0
    {// 0x77A
        CANIF_RXPDU_ID_22, //pdu id
	    0x7e8,
	    0x7ea,
	    8,		
	    CANIF_CAN_ID_TYPE_11,
	    CANIFRX_COM_INDICATION,//CanIfUserRxIndication;
	    &CanIf_HrhConfig[22],
	    NULL,//*PduIdRef;
	    0xFFF// CanIfCanRxPduCanIdMask;
    },
    #endif
	{// 0x730
		CANIF_RXPDU_ID_5, //pdu id
		0x730,
		0x732,
		8,			
		CANIF_CAN_ID_TYPE_11,
		CANIFRX_TP_INDICATION,//CanIfUserRxIndication;
		&CanIf_HrhConfig[5],
		NULL,//*PduIdRef;
		0xFFF// CanIfCanRxPduCanIdMask;
	},
	
	{// 0x7DF
		CANIF_RXPDU_ID_6, //pdu id
		0x7e8,
		0x7ea,
		8,			
		CANIF_CAN_ID_TYPE_11,
		CANIFRX_TP_INDICATION,//CanIfUserRxIndication;
		&CanIf_HrhConfig[6],
		NULL,//*PduIdRef;
		0xFFF// CanIfCanRxPduCanIdMask;
	},
} ;



CanIf_InitHohConfigType  const CanIf_InitHohConfig = {
  CanIf_HrhConfig ,
  CanIf_HthConfig,
  true
} ;


CanIf_InitConfigType const CanIf_InitConfig = {
	0,//uint32 CanIfConfigSet;
	CANIF_NUMBER_OF_RXPDUID,//uint32 CanIfNumberOfCanRxPduIds;
	CANIF_NUMBER_OF_TXPDUID,//uint32 CanIfNumberOfCanTXPduIds;
	0,//uint32 CanIfNumberOfDynamicCanTXPduIds;
	CANIF_NUMBER_OF_TXBUFFER,//uint16 CanIfNumberOfTxBuffers;
	CanIf_TxBufferConfig,
	&CanIf_InitHohConfig,
	CanIf_RxPduConfig,
	CanIf_TxPduConfig
} ;
CanIf_TxBufferConfigType const * const CanIf_TxBufferConfigArray[] = {
	&CanIf_TxBufferConfig[0],
	&CanIf_TxBufferConfig[1],
	&CanIf_TxBufferConfig[2],
	//&CanIf_TxBufferConfig[3],
	//&CanIf_TxBufferConfig[4],
	//&CanIf_TxBufferConfig[5],
	//&CanIf_TxBufferConfig[6],
};


/** CanIf channel configuration */
CanIf_Arc_ChannelConfigType const CanIf_Arc_ChannelConfig[] = {
    {
		CanIf_TxBufferConfigArray,
        CONTROLLER_ID_0,
        TX_BUFFER_NUM// NofTxBuffers;
    },
    {
		CanIf_TxBufferConfigArray,
        CONTROLLER_ID_1,
        TX_BUFFER_NUM// NofTxBuffers;
    },
} ;


CanIf_ConfigType const CanIf_Config = {
    &CanIf_InitConfig,
	NULL,
    CanIf_Arc_ChannelConfig
} ;

CanIfUserRxIndicationType const CanIfUserRxIndications[] = {
   NULL,//CanNm_RxIndication,
   Com_RxIndication,
   CanTp_RxIndication,
};
CanIfUserTxConfirmationType const CanIfUserTxConfirmations[] = {
    NULL,//CanNm_TxConfirmation,
    Com_TxConfirmation,
    CanTp_TxConfirmation,
};


CanIf_DispatchConfigType const CanIfDispatchConfig = {
    NULL,
    NULL,
    NULL,
    NULL,//CanSM_ControllerModeIndication,
};


