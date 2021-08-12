#ifndef __CANIF_CFG_H
#define __CANIF_CFG_H

#include "can.h"
#include "CanIf_ConfigTypes.h"
#include "CanNm_Cbk.h"
#include "CanSM_Cbk.h"
#include "Com_Com.h"
#include "CanTp_Cbk.h"


#define CANIF_CTRLDRV_TX_CANCELLATION       STD_ON
#define CANIF_READTXPDU_NOTIFY_STATUS_API   0
#define CANIF_ARC_RUNTIME_PDU_CONFIGURATION	1
#define CANIF_ARC_MAX_NOF_TX_BUFFERS       	2//7 modify by mgd on 20210703 
#define CANIF_ARC_MAX_NUM_LPDU_TX_BUF      	14 
#define CANIF_PUBLIC_TX_BUFFERING           1
#define CANIF_CHANNEL_CNT                   2


#define CANIF_TXPDU_ID_0x738	2//12


/* Tx PduId For CanIF */
#define DCM_TX_vEcuC_Pdu0		0
#define DCM_TX_vEcuC_Pdu1		1
#define DCM_TX_vEcuC_Pdu2		2
#define DCM_TX_vEcuC_Pdu3		3
#define DCM_TX_vEcuC_Pdu4		4
#define DCM_TX_vEcuC_Pdu5		5
#define DCM_TX_vEcuC_Pdu6		6

/* Rx PduId For CanIF */
#define CANIF_RX_vEcuC_Pdu1		0
#define CANIF_RX_vEcuC_Pdu2		1
#define CANIF_RX_vEcuC_Pdu3		2
#define CANIF_RX_vEcuC_Pdu4		3
#define CANIF_RX_vEcuC_Pdu5		4
#define CANIF_RX_vEcuC_Pdu6		5
#define CANIF_RX_vEcuC_Pdu7		6
#define CANIF_RX_vEcuC_Pdu8		7
#define CANIF_RX_vEcuC_Pdu9		8
#define CANIF_RX_vEcuC_Pdu10	9
#define CANIF_RX_vEcuC_Pdu0		10

#define CANIF_PRIVATE_DLC_CHECK STD_ON


extern CanIf_ConfigType const CanIf_Config;

#endif
