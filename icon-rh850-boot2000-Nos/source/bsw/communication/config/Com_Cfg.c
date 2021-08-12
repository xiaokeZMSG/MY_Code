#include "Com.h"
#include "CanAppComRxCallback.h"
/** Top-level configuration container for COM. Exists once per configuration. */



#define SIGNAL_RX_0_ERR_NOTIFY         NULL
#define SIGNAL_RX_0_FIRST_TIMEOUT      1000


#define SIGNAL_RX_0_COM_TIMEOUT        1000
#define SIGNAL_RX_0_COM_TIMEOUT_NOTIFY NULL
#define SIGNAL_RX_0_UPDATA_BIT_POS     25
#define SIGNAL_RX_0_USE_UPDATE_BIT     FALSE
#define SIGNAL_RX_0_IS_GROUP_SIGNAL    FALSE
#define SIGNAL_RX_0_GROUP_SIGNAL_REF   NULL
#define SIGNAL_RX_0_SHADOW_BUF_MASK    0




ComIPduGroup_type ComIPduTxGroup[] = {
    {
	    COM_IPDU_GROUP_ID_0,
	    FALSE
    },
    {
	    COM_IPDU_GROUP_ID_0,
	    TRUE
    },
} ;

ComIPduGroup_type ComIPduRxGroup[] = {
    {
	    COM_IPDU_GROUP_ID_1,
	    FALSE
    },
    {
	    COM_IPDU_GROUP_ID_1,
	    TRUE
    },
} ;


uint8_t Signal_Tx_0_Init[] = {
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
};

uint8_t Signal_Tx_Setting_Req_Init[] = {
	0x80,//fcw_on
	0x10,//aeb_on
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
};

//eps default value
uint8_t Signal_Tx_ComfortSetting_Init[] = {
	0x01,//invalid setting
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
};

 
ComGroupSignal_type const ComGroupSignal[] = {
	      
	{// 0
		SIGNAL_RX_MMI_LIGHT_0x2A2_BIT_POS,
		SIGNAL_RX_MMI_LIGHT_0x2A2_SIZE,
		HP_RX_MMI_LIGHT_0x2A2_SIGNAL,
		COM_BIG_ENDIAN,
		Signal_Tx_0_Init,
		SIGNAL_UINT16,
		FALSE,
	},
	{// 1
		SIGNAL_RX_GW_IPK_0x3F1_BIT_POS,
		SIGNAL_RX_GW_IPK_0x3F1_SIZE,
		HP_RX_GW_IPK_0x3F1_SIGNAL,
		COM_BIG_ENDIAN,
		Signal_Tx_0_Init,
		SIGNAL_UINT8,
		FALSE,
	},
	{// 2
		SIGNAL_RX_GW_ESC_0x125_BIT_POS,
		SIGNAL_RX_GW_ESC_0x125_SIZE,
		HP_RX_GW_ESC_0x125_SIGNAL,
		COM_BIG_ENDIAN,
		Signal_Tx_0_Init,
		SIGNAL_UINT8,
		FALSE,
	},

	{// 3
		SIGNAL_RX_GW_BCM_0x287_BIT_POS,
		SIGNAL_RX_GW_BCM_0x287_SIZE,
		HP_RX_GW_BCM_0x287_SIGNAL,
		COM_BIG_ENDIAN,
		Signal_Tx_0_Init,
		SIGNAL_UINT8,
		FALSE,
	},

	{// 4
		SIGNAL_RX_GW_IPK_0x3F1_BIT_POS,
		SIGNAL_RX_GW_IPK_0x3F1_SIZE,
		HP_RX_GW_IPK_0x3F1_SIGNAL,
		COM_BIG_ENDIAN,
		Signal_Tx_0_Init,
		SIGNAL_UINT8,
		TRUE,
	},
	

	
};

ComGroupSignal_type const * const HP_Com_MMI_LIGHT_0x2A2_Signal_Group[] =
{
	&ComGroupSignal[0],
	NULL,
};
ComGroupSignal_type const * const HP_Com_GW_IPK_0x3F1_Signal_Group[] =
{
	&ComGroupSignal[1],
	NULL,
};
ComGroupSignal_type const * const HP_Com_GW_ESC_0x125_Signal_Group[] =
{
	&ComGroupSignal[2],
	NULL,
};
ComGroupSignal_type const * const HP_Com_GW_BCM_0x287_Signal_Group[] =
{
	&ComGroupSignal[3],
	NULL,
};



ComSignal_type const ComIPduSignal[] = { 
     /************ TX signal 0************/
    {// 0x226
	    0,   //ComBitPosition;
	    64,  //ComBitSize;
	    0,   //ComErrorNotification;
	    100,//ComFirstTimeoutFactor;
	    HP_TX_MMI_LIGHT_0x226,			  //ComHandleId;
	    HP_TX_MMI_LIGHT_0x226_INDEX, //ComNotification;
	    COM_TIMEOUT_DATA_ACTION_NONE,		  // ComRxDataTimeoutAction;
	    COM_LITTLE_ENDIAN,	// ComSignalEndianess;
	    Signal_Tx_0_Init,	// ComSignalInitValue;
	    SIGNAL_UINT8_N,
	    100, //ComTimeoutFactor;
	    0,	  //ComTimeoutNotification;
	    TRIGGERED_ON_CHANGE,
	    SIGNAL_TX_HP_UPDATA_BIT_POS    ,//ComUpdateBitPosition;
	    SIGNAL_TX_HP_USE_UPDATE_BIT    ,//ComSignalArcUseUpdateBit;
	    SIGNAL_TX_HP_IS_GROUP_SIGNAL   ,// Com_Arc_IsSignalGroup;
	    SIGNAL_TX_HP_GROUP_SIGNAL_REF  ,// *ComGroupSignal;
	    SIGNAL_TX_HP_SHADOW_BUF_MASK   ,//Com_Arc_ShadowBuffer_Mask;
	    SIGNAL_TX_HP_IPDU_HANDLE       ,// ComIPduHandleId;
	    FALSE
    }, 	
  
     /************ recv signal 0 ***********/
    {//0x2A2
	    0,                            //ComBitPosition;
	    64,                           // ComBitSize;
	    0,                            //ComErrorNotification;
	    100,                         //ComFirstTimeoutFactor;
	    HP_RX_MMI_LIGHT_0x2A2,                    // ComHandleId;
	    HP_RX_MMI_LIGHT_0x2A2_NOTIFY_INDEX,//ComNotification;
	    COM_TIMEOUT_DATA_ACTION_REPLACE,// ComRxDataTimeoutAction;
	    COM_BIG_ENDIAN,              // ComSignalEndianess;
	    Signal_Tx_0_Init,
	    SIGNAL_UINT16,
	    100,                        //ComTimeoutFactor;
	    1,//ComTimeoutNotification;
	    TRIGGERED_ON_CHANGE,
	    0, //ComUpdateBitPosition;
	    FALSE,//ComSignalArcUseUpdateBit;
	    TRUE,
	    HP_Com_MMI_LIGHT_0x2A2_Signal_Group,
	    0,
	    SIGNAL_RX_MMI_LIGHT_0x2A2_HANDLE,
	    FALSE
    },
         /************recv signal 1 **********/
    {// 0x3F1
	    0,                            //ComBitPosition;
	    64,                           // ComBitSize;
	    0,                            //ComErrorNotification;
	    100,                         //ComFirstTimeoutFactor;
	    HP_RX_GW_IPK_0x3F1,                    // ComHandleId;
	    HP_RX_GW_IPK_0x3F1_NOTIFY_INDEX,//ComNotification;
	    COM_TIMEOUT_DATA_ACTION_REPLACE,// ComRxDataTimeoutAction;
	    COM_BIG_ENDIAN,              // ComSignalEndianess;
	    Signal_Tx_0_Init,
	    SIGNAL_UINT16,
	    1000,                        //ComTimeoutFactor;
	    0,//ComTimeoutNotification;
	    TRIGGERED_ON_CHANGE,
	    0,
	    FALSE,
	    TRUE,
	    HP_Com_GW_IPK_0x3F1_Signal_Group,
	    0,
	    SIGNAL_RX_GW_IPK_0x3F1_HANDLE,
	    FALSE
    },
          /************recv signal 2 **********/
    {// 0x125
	    0,                            //ComBitPosition;
	    64,                           // ComBitSize;
	    0,                            //ComErrorNotification;
	    100,                         //ComFirstTimeoutFactor;
	    HP_RX_GW_ESC_0x125,                    // ComHandleId;
	    HP_RX_GW_ESC_0x125_NOTIFY_INDEX,//ComNotification;
	    COM_TIMEOUT_DATA_ACTION_REPLACE,// ComRxDataTimeoutAction;
	    COM_BIG_ENDIAN,              // ComSignalEndianess;
	    Signal_Tx_0_Init,
	    SIGNAL_UINT16,
	    20,                        //ComTimeoutFactor;
	    0,//ComTimeoutNotification;
	    TRIGGERED_ON_CHANGE,
	    0,
	    FALSE,
	    TRUE,
	    HP_Com_GW_ESC_0x125_Signal_Group,
	    0,
	    SIGNAL_RX_GW_ESC_0x125_HANDLE,
	    FALSE
    },
          /************recv signal 3 **********/
    {// 0x287
	    0,                            //ComBitPosition;
	    64,                           // ComBitSize;
	    0,                            //ComErrorNotification;
	    100,                         //ComFirstTimeoutFactor;
	    HP_RX_GW_BCM_0x287,                    // ComHandleId;
	    HP_RX_GW_BCM_0x287_NOTIFY_INDEX,//ComNotification;
	    COM_TIMEOUT_DATA_ACTION_REPLACE,// ComRxDataTimeoutAction;
	    COM_BIG_ENDIAN,              // ComSignalEndianess;
	    Signal_Tx_0_Init,
	    SIGNAL_UINT16,
	    100,                        //ComTimeoutFactor;
	    2,//ComTimeoutNotification;
	    TRIGGERED_ON_CHANGE,
	    0,
	    FALSE,
	    TRUE,
	    HP_Com_GW_BCM_0x287_Signal_Group,
	    0,
	    SIGNAL_RX_GW_BCM_0x287_HANDLE,
	    FALSE
    },

	  {// end
	    0,                            //ComBitPosition;
	    64,                           // ComBitSize;
	    0,                            //ComErrorNotification;
	    100,                         //ComFirstTimeoutFactor;
	    HP_RX_GW_BCM_0x287,                    // ComHandleId;
	    HP_RX_GW_BCM_0x287_NOTIFY_INDEX,//ComNotification;
	    COM_TIMEOUT_DATA_ACTION_REPLACE,// ComRxDataTimeoutAction;
	    COM_BIG_ENDIAN,              // ComSignalEndianess;
	    Signal_Tx_0_Init,
	    SIGNAL_UINT16,
	    100,                        //ComTimeoutFactor;
	    0,//ComTimeoutNotification;
	    TRIGGERED_ON_CHANGE,
	    0,
	    FALSE,
	    TRUE,
	    HP_Com_GW_BCM_0x287_Signal_Group,
	    0,
	    SIGNAL_RX_GW_BCM_0x287_HANDLE,
	    TRUE
    },
   

} ;


/*TX*/
ComSignal_type const *  const ComIPdu_0_Tx_SignalRef[] = {
    &ComIPduSignal[0],
	NULL,
};
ComSignal_type const *  const ComIPdu_1_Tx_SignalRef[] = {
    &ComIPduSignal[1],
	NULL,
};
ComSignal_type const *  const ComIPdu_2_Tx_SignalRef[] = {
    &ComIPduSignal[2],
	NULL,
};

ComSignal_type const *  const ComIPdu_3_Tx_SignalRef[] = {
    &ComIPduSignal[3],
	NULL,
};

ComSignal_type const *  const ComIPdu_4_Tx_SignalRef[] = {
    &ComIPduSignal[4],
	NULL,
};

/*TX send number*/
#define SignalNum  1//if add  can tx ipdu,should change 

/*RX*/
ComSignal_type const * const ComIPdu_Rx_MMI_0x226_SignalRef[] = {
    &ComIPduSignal[SignalNum+1],
	NULL,
};
ComSignal_type const * const ComIPdu_Rx_IPK_0x3F1_SignalRef[] = {
	&ComIPduSignal[SignalNum+2],
	NULL,
};
ComSignal_type const * const ComIPdu_Rx_GW_ESC_0x125_SignalRef[] = {
	&ComIPduSignal[SignalNum+3],
	NULL,
};
ComSignal_type const * const ComIPdu_Rx_GW_BCM_0x287_SignalRef[] = {
	&ComIPduSignal[SignalNum+4],
	NULL,
};



ComIPdu_type const ComIPdu[] = {
	{// 0:tx 226
		COM_RX_IPDU_CALLOUT,
		COM_TX_IPDU_CALLOUT,
		ARC_IPDU_ID_0,
		IMMEDIATE,
		ARC_IPDU_ID_0_SIZE,
		SEND,
		ComIPduTxGroup,
		{
			COMTX_IPDU_MINIMUMDELAY_FACTOR,
			COMTX_IPDU_UNUSED_AREAS_DEFAULT,
			{
				MIXED,
				COMTXMODE_NOF_REPETION,
				COMTXMODE_REPETION_PERIOD,
				COMTXMODE_TIME0_OFFSET,
				COMTXMODE_TIME0_PERIOD
			},
		},
		ComIPdu_0_Tx_SignalRef,
		NULL,
		FALSE,
	},
	
    {// 1:Rx 0x2A2
		HP_MMI_0X2A2_Timeout,
		COM_TX_IPDU_CALLOUT,
		HP_RX_MMI_LIGHT_0x2A2,
		IMMEDIATE,
		ARC_IPDU_ID_1_SIZE,
		RECEIVE,

		ComIPduRxGroup,
		{
	    	COMTX_IPDU_MINIMUMDELAY_FACTOR,
		    COMTX_IPDU_UNUSED_AREAS_DEFAULT,
	    	{
	        	MIXED,
	        	COMTXMODE_NOF_REPETION,
            	COMTXMODE_REPETION_PERIOD,
            	COMTXMODE_TIME_OFFSET,
	        	COMTXMODE_TIME_PERIOD
        	},
    	},
		ComIPdu_Rx_MMI_0x226_SignalRef,
		NULL,
		FALSE,
    },
     {// 2:Rx 0x3f1 IPK
		HP_IPK_0x3F1_Timeout,
		COM_TX_IPDU_CALLOUT,
		HP_RX_MMI_LIGHT_0x2A2,
		IMMEDIATE,
		ARC_IPDU_ID_1_SIZE,
		RECEIVE,

		ComIPduRxGroup,
		{
	    	COMTX_IPDU_MINIMUMDELAY_FACTOR,
		    COMTX_IPDU_UNUSED_AREAS_DEFAULT,
	    	{
	        	MIXED,
	        	COMTXMODE_NOF_REPETION,
            	COMTXMODE_REPETION_PERIOD,
            	COMTXMODE_TIME_OFFSET,
	        	COMTXMODE_TIME_PERIOD
        	},
    	},
		ComIPdu_Rx_IPK_0x3F1_SignalRef,
		NULL,
		FALSE,
    },
     {// 3:Rx 0x125 ESC
		HP_GW_ESC_0X125_Timeout,
		COM_TX_IPDU_CALLOUT,
		HP_RX_MMI_LIGHT_0x2A2,
		IMMEDIATE,
		ARC_IPDU_ID_1_SIZE,
		RECEIVE,

		ComIPduRxGroup,
		{
	    	COMTX_IPDU_MINIMUMDELAY_FACTOR,
		    COMTX_IPDU_UNUSED_AREAS_DEFAULT,
	    	{
	        	MIXED,
	        	COMTXMODE_NOF_REPETION,
            	COMTXMODE_REPETION_PERIOD,
            	COMTXMODE_TIME_OFFSET,
	        	COMTXMODE_TIME_PERIOD
        	},
    	},
		ComIPdu_Rx_GW_ESC_0x125_SignalRef,
		NULL,
		FALSE,
    },
     {// 4:Rx 0x287  BCM
		HP_GW_BCM_0X287_Timeout,
		COM_TX_IPDU_CALLOUT,
		HP_RX_MMI_LIGHT_0x2A2,
		IMMEDIATE,
		ARC_IPDU_ID_1_SIZE,
		RECEIVE,

		ComIPduRxGroup,
		{
	    	COMTX_IPDU_MINIMUMDELAY_FACTOR,
		    COMTX_IPDU_UNUSED_AREAS_DEFAULT,
	    	{
	        	MIXED,
	        	COMTXMODE_NOF_REPETION,
            	COMTXMODE_REPETION_PERIOD,
            	COMTXMODE_TIME_OFFSET,
	        	COMTXMODE_TIME_PERIOD
        	},
    	},
		ComIPdu_Rx_GW_BCM_0x287_SignalRef,
		NULL,
		FALSE,
    },
        {// end
		HP_GW_BCM_0X287_Timeout,
		COM_TX_IPDU_CALLOUT,
		HP_RX_MMI_LIGHT_0x2A2,
		IMMEDIATE,
		ARC_IPDU_ID_1_SIZE,
		RECEIVE,

		ComIPduRxGroup,
		{
	    	COMTX_IPDU_MINIMUMDELAY_FACTOR,
		    COMTX_IPDU_UNUSED_AREAS_DEFAULT,
	    	{
	        	MIXED,
	        	COMTXMODE_NOF_REPETION,
            	COMTXMODE_REPETION_PERIOD,
            	COMTXMODE_TIME_OFFSET,
	        	COMTXMODE_TIME_PERIOD
        	},
    	},
		ComIPdu_Rx_GW_BCM_0x287_SignalRef,
		NULL,
		TRUE,
    },
  
} ;


Com_ConfigType Com_Config = {
	COM_CONFIG_ID,
	COM_NOF_IPDU,
	COM_NOF_SIGNAL,
	COM_NOF_GROUP_SIGNAL,
	ComIPdu,
	ComIPduTxGroup,//ComIPduGroup;
	ComIPduSignal, /** Signal definitions */
	ComGroupSignal,/** Group signal definitions */

};

 ComRxIPduCalloutType ComRxIPduCallouts[] = {
 #if 0
	GEELY_ABS_ESP_0X68_RxCallout,
	//GEELY_ACU_0X268_RxCallout,
	//GEELY_BCM_0X2D4_RxCallout,
	//GEELY_EPS_0X334_RxCallout,
	//GEELY_FCS_0X21C_RxCallout,
	//GEELY_FRS_0X231_RxCallout,
	//GEELY_ICU_0X360_RxCallout,
	GEELY_PEPS_0XE2_RxCallout,
	//GEELY_HVAC_0X2F1_RxCallout,
	GEELY_BCM_0X4D4_RxCallout,
#endif

	NULL
};
 ComTxIPduCalloutType ComTxIPduCallouts[] = {
    NULL,
};



ComNotificationCalloutType const ComNotificationCallouts[]= {
	/*0*/NULL,
	/*1*/NULL,
	/*2*/NULL,
	/*3*/NULL,
	/*4*/NULL,
	/*5*/NULL,
	/*6*/NULL,
	/*7*/NULL,
	/*8*/NULL,
	/*9*/NULL,
	/*10*/NULL
};

ComTimeoutNotificationCalloutType const ComTimeoutNotificationCallouts[]= {

	/*0*/NULL,
	/*1*/RX_MMI_0x2A2_TimeoutCallout,
	/*2*/RX_GW_0x287_TimeoutCallout,
	/*3*/NULL,
	/*4*/NULL,
	/*5*/NULL,
	/*6*/NULL,
	/*7*/NULL,
	/*8*/NULL,
	/*9*/NULL
};


