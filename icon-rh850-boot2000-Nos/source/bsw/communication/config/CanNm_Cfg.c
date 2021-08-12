#include "CanNm.h"


#define NM_NETWORK_HANDLE_0 0
#define ECM_NODE_INDEX      0x15
#define MAIN_FUNC_PERIOD    5//10
#define NM_TIME_OUT         2000
#define REPEAT_MESSAGE_TIME 1600
#define WAIT_BUS_SLEEP_TIME 2000
#define MESSAGE_CYCLE_TIME  500
#define NM_TX_PDU_ID        0
#define NM_T_START_OFFSET   10

CanNm_ChannelType const CanNm_Channel = {
	true,
	NM_NETWORK_HANDLE_0,
	ECM_NODE_INDEX,
	MAIN_FUNC_PERIOD,
	NM_TIME_OUT,//	/** @req CANNM246 */
	REPEAT_MESSAGE_TIME,//	/** @req CANNM247 */
	WAIT_BUS_SLEEP_TIME,//	/** @req CANNM248 */
	MESSAGE_CYCLE_TIME,//	
	NM_T_START_OFFSET,//					MessageCycleOffsetTime;
	100,//                    MessageTimeoutTime;
	NM_TX_PDU_ID,
	8,//						PduLength;
	(CanNm_PduBytePositionType)0,//	NidPosition;            /**< @req CANNM074 */
	(CanNm_PduBytePositionType)1,//	CbvPosition;            /**< @req CANNM075 */
	20,//					ImmediateNmCycleTime;	/**< @req CANNM335 */
	5,//					ImmediateNmTransmissions;
#if (CANNM_COM_USER_DATA_SUPPORT == STD_ON)
	const PduIdType					CanNmTxPduId;
#endif
    (CanNm_PduBytePositionType)2,
    (CanNm_PduBytePositionType)3,

} ;

uint8_t                ChannelLookups[] = {0};


CanNm_ConfigType const CanNm_Config= {
	&CanNm_Channel,       /* Pointer to the CanNm channels */
	ChannelLookups,/* Pointer to lookup from NetworkHandle to index in CanNm channels */
} ;		

