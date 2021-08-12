#include "CanTp.h"
#define USE_CANIF
#define USE_PDUR
//#if defined(USE_CANIF)
#include "CanIf_Cfg.h"
//#endif
#if defined(USE_PDUR)
#include "PduR.h"
#endif
#include "CanTp_Cfg.h"


//NSa
const CanTp_NSaType CanTpNSaConfig_RX_vEcuC_Pdu6 = 
{
	/* .CanTpNSa = */ 0,
};
//NTa
const CanTp_NTaType CanTpNTaConfig_RX_vEcuC_Pdu6 = 
{
	/* .CanTpNTa = */ 0,
};

//NSa
const CanTp_NSaType CanTpNSaConfig_RX_vEcuC_Pdu7 = 
{
	/* .CanTpNSa = */ 0,
};
//NTa
const CanTp_NTaType CanTpNTaConfig_RX_vEcuC_Pdu7 = 
{
	/* .CanTpNTa = */ 0,
};
#if 0
//NSa
const CanTp_NSaType CanTpNSaConfig_RX_vEcuC_Pdu8 = 
{
	/* .CanTpNSa = */ 0,
};
//NTa
const CanTp_NTaType CanTpNTaConfig_RX_vEcuC_Pdu8 = 
{
	/* .CanTpNTa = */ 0,
};

//NSa
const CanTp_NSaType CanTpNSaConfig_RX_vEcuC_Pdu9 = 
{
	/* .CanTpNSa = */ 0,
};
//NTa
const CanTp_NTaType CanTpNTaConfig_RX_vEcuC_Pdu9 = 
{
	/* .CanTpNTa = */ 0,
};
#endif
//NSa
const CanTp_NSaType CanTpNSaConfig_TX_vEcuC_Pdu0 = 
{
	/* .CanTpNSa = */ 0,
};
//NTa
const CanTp_NTaType CanTpNTaConfig_TX_vEcuC_Pdu0 = 
{
	/* .CanTpNTa = */ 0,
};

//NSa
const CanTp_NSaType CanTpNSaConfig_TX_vEcuC_Pdu2 = 
{
	/* .CanTpNSa = */ 0,
};
//NTa
const CanTp_NTaType CanTpNTaConfig_TX_vEcuC_Pdu2 = 
{
	/* .CanTpNTa = */ 0,
};
#if 0
//NSa
const CanTp_NSaType CanTpNSaConfig_TX_vEcuC_Pdu3 = 
{
	/* .CanTpNSa = */ 0,
};
//NTa
const CanTp_NTaType CanTpNTaConfig_TX_vEcuC_Pdu3 = 
{
	/* .CanTpNTa = */ 0,
};

//NSa
const CanTp_NSaType CanTpNSaConfig_TX_vEcuC_Pdu4 = 
{
	/* .CanTpNSa = */ 0,
};
//NTa
const CanTp_NTaType CanTpNTaConfig_TX_vEcuC_Pdu4 = 
{
	/* .CanTpNTa = */ 0,
};

//NSa
const CanTp_NSaType CanTpNSaConfig_TX_vEcuC_Pdu5 = 
{
	/* .CanTpNSa = */ 0,
};
//NTa
const CanTp_NTaType CanTpNTaConfig_TX_vEcuC_Pdu5 = 
{
	/* .CanTpNTa = */ 0,
};
#endif



CanTp_NSduType  CanTpNSduConfigList[] = {
	{
	    /*direction*/ISO15765_RECEIVE,
	    /*CanTp_ListItemType */CANTP_NOT_LAST_ENTRY,
	    {
		    /* .configData.CanTpRxNSdu.CanTp_FcPduId = */     0xDEAD,
		    /* .configData.CanTpRxNSdu.CanIf_FcPduId = */     CANIF_RX_vEcuC_Pdu1,
		    /* .configData.CanTpRxNSdu.PduR_PduId = */        0,
		    /* .configData.CanTpRxNSdu.CanTpAddressingFormant = */ CANTP_STANDARD,
		    /* .configData.CanTpRxNSdu.CanTpBs = */           0,
		    /* .configData.CanTpRxNSdu.CanTpNar = */          25,
		    /* .configData.CanTpRxNSdu.CanTpNbr = */          10,
		    /* .configData.CanTpRxNSdu.CanTpNcr = */          150,
		    /* .configData.CanTpRxNSdu.CanTpRxChannel = */    0,
		    /* .configData.CanTpRxNSdu.CanTpRxDI = */         8,
		    /* .configData.CanTpRxNSdu.CanTpRxPaddingActivation = */ CANTP_ON,
		    /* .configData.CanTpRxNSdu.CanTpRxTaType = */     CANTP_PHYSICAL,
		    /* .configData.CanTpRxNSdu.CanTpWftMax = */       5,
		    /* .configData.CanTpRxNSdu.CanTpSTmin = */        10,
		    /* .configData.CanTpRxNSdu.CanTpNSa = */          &CanTpNSaConfig_RX_vEcuC_Pdu6,
		    /* .configData.CanTpRxNSdu.CanTpNTa = */          &CanTpNTaConfig_RX_vEcuC_Pdu6,
	    },
    },
    {
		/* .direction = */ ISO15765_RECEIVE,
		/* .listItemType = */ CANTP_NOT_LAST_ENTRY,
		{
			/* .configData.CanTpRxNSdu.CanTp_FcPduId = */ 0xDEAD,
			/* .configData.CanTpRxNSdu.CanIf_FcPduId = */ CANIF_RX_vEcuC_Pdu1,
			/* .configData.CanTpRxNSdu.PduR_PduId = */ 1,
			/* .configData.CanTpRxNSdu.CanTpAddressingFormant = */ CANTP_STANDARD,
			/* .configData.CanTpRxNSdu.CanTpBs = */ 0,
			/* .configData.CanTpRxNSdu.CanTpNar = */ 25,
			/* .configData.CanTpRxNSdu.CanTpNbr = */ 10,
			/* .configData.CanTpRxNSdu.CanTpNcr = */ 150,
			/* .configData.CanTpRxNSdu.CanTpRxChannel = */ 1,
			/* .configData.CanTpRxNSdu.CanTpRxDI = */ 8,
			/* .configData.CanTpRxNSdu.CanTpRxPaddingActivation = */ CANTP_ON,
			/* .configData.CanTpRxNSdu.CanTpRxTaType = */ CANTP_FUNCTIONAL,
			/* .configData.CanTpRxNSdu.CanTpWftMax = */ 5,
			/* .configData.CanTpRxNSdu.CanTpSTmin = */ 10,
			/* .configData.CanTpRxNSdu.CanTpNSa = */ &CanTpNSaConfig_RX_vEcuC_Pdu7,
			/* .configData.CanTpRxNSdu.CanTpNTa = */ &CanTpNTaConfig_RX_vEcuC_Pdu7,
		}
	},
	{
		/* .direction = */ IS015765_TRANSMIT,
		/* .listItemType = */ CANTP_NOT_LAST_ENTRY,
		{
            /* .configData.CanTpTxNSdu.CanIf_PduId = */ CANIF_TXPDU_ID_0x738,
			/* .configData.CanTpTxNSdu.PduR_PduId = */ DCM_TX_vEcuC_Pdu0,
			/* .configData.CanTpTxNSdu.CanTp_FcPduId = */ 0xDEAD,
			
			
			/* .configData.CanTpTxNSdu.CanTpAddressingMode = */ CANTP_STANDARD,
			/* .configData.CanTpRxNSdu.reserved_CanTpBs = */ 0xDB,
			/* .configData.CanTpTxNSdu.CanTpNas = */ 25,
			/* .configData.CanTpTxNSdu.CanTpNbs = */ 75,
			/* .configData.CanTpTxNSdu.CanTpNcs = */ 25,
			/* .configData.CanTpTxNSdu.CanTpTxChannel = */ 0,
			/* .configData.CanTpTxNSdu.CanTpTxDI = */ 8,
			/* .configData.CanTpTxNSdu.CanTpTxPaddingActivation = */ CANTP_ON,
			/* .configData.CanTpTxNSdu.CanTpTxTaType = */ CANTP_PHYSICAL,
			/* .configData.CanTpTxNSdu.reserved_CanTpWftMax = */ 0xDB,
			/* .configData.CanTpTxNSdu.reserved_CanTpSTmin = */ 0xDEAD,
			/* .configData.CanTpTxNSdu.CanTpNSa = */ &CanTpNSaConfig_TX_vEcuC_Pdu0,
			/* .configData.CanTpTxNSdu.CanTpNTa = */ &CanTpNTaConfig_TX_vEcuC_Pdu0,
		}
	},
	{
		/* .direction = */ IS015765_TRANSMIT,
		/* .listItemType = */ CANTP_NOT_LAST_ENTRY,
		{
			
			/* .configData.CanTpTxNSdu.CanIf_PduId = */ CANIF_TXPDU_ID_0x738,
			/* .configData.CanTpTxNSdu.PduR_PduId = */ DCM_TX_vEcuC_Pdu1,
			/* .configData.CanTpTxNSdu.CanTp_FcPduId = */ 0xDEAD,
			/* .configData.CanTpTxNSdu.CanTpAddressingMode = */ CANTP_STANDARD,
			/* .configData.CanTpRxNSdu.reserved_CanTpBs = */ 0xDB,
			/* .configData.CanTpTxNSdu.CanTpNas = */ 25,
			/* .configData.CanTpTxNSdu.CanTpNbs = */ 75,
			/* .configData.CanTpTxNSdu.CanTpNcs = */ 25,
			/* .configData.CanTpTxNSdu.CanTpTxChannel = */ 0,
			/* .configData.CanTpTxNSdu.CanTpTxDI = */ 8,
			/* .configData.CanTpTxNSdu.CanTpTxPaddingActivation = */ CANTP_ON,
			/* .configData.CanTpTxNSdu.CanTpTxTaType = */ CANTP_FUNCTIONAL,
			/* .configData.CanTpTxNSdu.reserved_CanTpWftMax = */ 0xDB,
			/* .configData.CanTpTxNSdu.reserved_CanTpSTmin = */ 0xDEAD,
			/* .configData.CanTpTxNSdu.CanTpNSa = */ &CanTpNSaConfig_TX_vEcuC_Pdu2,
			/* .configData.CanTpTxNSdu.CanTpNTa = */ &CanTpNTaConfig_TX_vEcuC_Pdu2,
		}
	}
} ;


const CanTp_RxIdType CanTp_RxIdList[] = 
{
	{
		CANTP_STANDARD,
		0,
		0,
	},
	{
		CANTP_STANDARD,
		1,
		1,//0xFFFF
	},
	{
		CANTP_STANDARD,
		2,
		0,
	},
	{
		CANTP_STANDARD,
		3,
		0,
	}
};

const CanTp_GeneralType  CanTpGeneralConfig = {
	/*main_function_period*/10,
	/*number_of_sdus*/    3,
	/*number_of_pdus*/    3,
	/*padding*/           0xAA,
	/*start 0f txsdu*/    2,
	/*start 0f txpdu*/    CANIF_TXPDU_ID_0x738
} ; 

const CanTp_ConfigType CanTpConfig =
{
	/* .CanTpGeneral 	= */ 	&CanTpGeneralConfig,
	/* .CanTpNSduList = */	 CanTpNSduConfigList,
	/* .CanTpRxIdList = */     CanTp_RxIdList
};



