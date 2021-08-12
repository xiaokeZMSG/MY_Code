#ifndef __COM_CFG_H
#define __COM_CFG_H

#define COM_MAX_N_IPDUS 			5//23
#define COM_MAX_BUFFER_SIZE 		(COM_MAX_N_IPDUS* 8)
#define COM_MAX_N_SIGNALS 			5//23
#define COM_MAX_N_GROUP_SIGNALS 	5//23
#define COM_N_SUPPORTED_IPDU_GROUPS	5

#define COM_CONFIG_ID 			0
#define COM_NOF_IPDU 			5//RX+TX
#define COM_NOF_TX_IPDU 		1
#define COM_NOF_SIGNAL 			5//RX+TX
#define COM_NOF_GROUP_SIGNAL	5//RX+TX



#define COM_RX_TIMEOUT_CNT 6

/****************ComRxIPduCallout ******************/
#define COM_RX_IPDU_CALLOUT 0

#define HP_MMI_0X2A2_Timeout 	    1
#define HP_IPK_0x3F1_Timeout 	    2
#define HP_GW_ESC_0X125_Timeout 	3
#define HP_GW_BCM_0X287_Timeout 	4
/****************ComTxIPduCallout ******************/
#define COM_TX_IPDU_CALLOUT 0


#define COMTX_IPDU_MINIMUMDELAY_FACTOR 20

#define COMTX_IPDU_UNUSED_AREAS_DEFAULT 0
#define COMTXMODE_TIME_PERIOD 500
#define COMTXMODE_TIME_OFFSET 10
#define COMTXMODE_REPETION_PERIOD 20 
#define COMTXMODE_REPETION_PERIOD_50  50 
#define COMTXMODE_NOF_REPETION 3

#define COMTX_MAIN_PERIOD 5  //10


#define COMTXMODE_TIME0_PERIOD 100
#define COMTXMODE_TIME2_PERIOD 500
#define COMTXMODE_TIME3_PERIOD 300
#define COMTXMODE_TIME4_PERIOD 100//500
#define COMTXMODE_TIME5_PERIOD 500
#define COMTXMODE_TIME8_PERIOD 100

#define COMTXMODE_TIME0_OFFSET 0    //5
#define COMTXMODE_TIME2_OFFSET 10    //10
#define COMTXMODE_TIME3_OFFSET 15   //15
#define COMTXMODE_TIME4_OFFSET 10    //5
#define COMTXMODE_TIME5_OFFSET 15    //10
#define COMTXMODE_TIME8_OFFSET 5    //10


#define COM_PDUID_CANIF_RX_START 1
#define COM_PDUID_COM_RX_START   1 //if add tx id ,should be add

#define COM_PDUID_CANIF_TX_START 1




#define ARC_IPDU_ID_0 		0
#define ARC_IPDU_ID_0_SIZE 	8
#define COM_IPDU_GROUP_ID_0 0
#define COM_IPDU_GROUP_ID_1 1


#define ARC_IPDU_ID_1 		1
#define ARC_IPDU_ID_1_SIZE 	8

#define ARC_IPDU_ID_2 		2
#define ARC_IPDU_ID_2_SIZE 	8

#define ARC_IPDU_ID_3 		3
#define ARC_IPDU_ID_3_SIZE 	4

#define ARC_IPDU_ID_4 		4
#define ARC_IPDU_ID_4_SIZE 	8


/********SEND CAN  SIGNAL INFO***********/
/*************HP_ComfortSetting*******************/
#define SIGNAL_TX_HP_BIT_POS            0
#define SIGNAL_TX_HP_BIT_SIZE           64
#define SIGNAL_TX_HP_ERR_NOTIFY         NULL
#define SIGNAL_TX_HP_FIRST_TIMEOUT      1000
#define SIGNAL_TX_HP_COM_HANDLE         0
#define SIGNAL_TX_HP_COM_NOTIFY         NULL
#define SIGNAL_TX_HP_COM_TIMEOUT        1000
#define SIGNAL_TX_HP_COM_TIMEOUT_NOTIFY NULL
#define SIGNAL_TX_HP_UPDATA_BIT_POS     25
#define SIGNAL_TX_HP_USE_UPDATE_BIT     FALSE
#define SIGNAL_TX_HP_IS_GROUP_SIGNAL    FALSE
#define SIGNAL_TX_HP_GROUP_SIGNAL_REF   NULL
#define SIGNAL_TX_HP_SHADOW_BUF_MASK    0

/*************TX CAN SIGNAL INFO*****************/
#define SIGNAL_TX_HP_IPDU_HANDLE        0
#define TX_LAST_HANDLE                  0

/********RECV CAN  SIGNAL INFO***********/

/*****************MMI_LIGHTY_0x2A2 Message********************/
#define SIGNAL_RX_MMI_LIGHT_0x2A2_BIT_POS			2
#define SIGNAL_RX_MMI_LIGHT_0x2A2_SIZE			    2
#define SIGNAL_RX_MMI_LIGHT_0x2A2_HANDLE			TX_LAST_HANDLE+1

/*****************GW_IPK_0x3F1 Message********************/
#define SIGNAL_RX_GW_IPK_0x3F1_BIT_POS 			2
#define SIGNAL_RX_GW_IPK_0x3F1_SIZE				2
#define SIGNAL_RX_GW_IPK_0x3F1_HANDLE				TX_LAST_HANDLE+2
/*****************GW_ESC_0x125 Message********************/
#define SIGNAL_RX_GW_ESC_0x125_BIT_POS 			2
#define SIGNAL_RX_GW_ESC_0x125_SIZE				2
#define SIGNAL_RX_GW_ESC_0x125_HANDLE				TX_LAST_HANDLE+3
/*****************GW_BCM_0x287 Message********************/
#define SIGNAL_RX_GW_BCM_0x287_BIT_POS 			2
#define SIGNAL_RX_GW_BCM_0x287_SIZE				2
#define SIGNAL_RX_GW_BCM_0x287_HANDLE				TX_LAST_HANDLE+4



/********SEND************/
#define HP_TX_MMI_LIGHT_0x226					    0
#define LAST_SEND			                        0
/*******RECV************/
#define HP_RX_MMI_LIGHT_0x2A2                       (LAST_SEND+1)
#define HP_RX_GW_IPK_0x3F1                        	(LAST_SEND+2) 
#define HP_RX_GW_ESC_0x125                        	(LAST_SEND+3) 
#define HP_RX_GW_BCM_0x287                        	(LAST_SEND+4) 




#define HP_RX_MMI_LIGHT_0x2A2_SIGNAL 	            0
#define HP_RX_GW_IPK_0x3F1_SIGNAL	 				1
#define HP_RX_GW_ESC_0x125_SIGNAL	 				2
#define HP_RX_GW_BCM_0x287_SIGNAL	 				3


/*SEND*/
#define HP_TX_MMI_LIGHT_0x226_INDEX      			HP_TX_MMI_LIGHT_0x226

/*RECV*/
#define HP_RX_MMI_LIGHT_0x2A2_NOTIFY_INDEX 	        HP_RX_MMI_LIGHT_0x2A2
#define HP_RX_GW_IPK_0x3F1_NOTIFY_INDEX	 		    HP_RX_GW_IPK_0x3F1	
#define HP_RX_GW_ESC_0x125_NOTIFY_INDEX	 		    HP_RX_GW_ESC_0x125
#define HP_RX_GW_BCM_0x287_NOTIFY_INDEX	 		    HP_RX_GW_BCM_0x287



#endif 
