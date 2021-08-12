#ifndef __CANTP_H
#define __CANTP_H
#define CANTP_MAX_NO_CHANNELS 4

/* CanTp Rx NSdu Id */
#define CANTP_RX_vEcuC_Pdu6 0
#define CANTP_RX_vEcuC_Pdu7 1
#define CANTP_RX_vEcuC_Pdu8 2
#define CANTP_RX_vEcuC_Pdu9 3

/* CanTp Tx NSdu Id */
#define CANTP_TX_vEcuC_Pdu0 4
#define CANTP_TX_vEcuC_Pdu2 5
#define CANTP_TX_vEcuC_Pdu3 6
#define CANTP_TX_vEcuC_Pdu4 7
#define CANTP_TX_vEcuC_Pdu5 8


#define	CANTP_FCPDUIDTX   				 0
#define	CANIF_PDUIDPHYSTX    			 12     //if add new can signal ,should be add
#define	CANIF_PDUIDFUNCTX    			 6
#define	PDUR_PDUIDPHYSTX    			 0
#define	PDUR_PDUIDFUNCTX    			 1
#define	CANTPBSTX    					 0
#define	CANTPNAS						 2	
#define	CANTPNBS						 7
#define	CANTPNCS						 0
#define	CANTPTXCHANNELPHYS			 2
#define	CANTPTXCHANNELFUNC			 3
#define	CANTPTXDI						 6
#define	CANTPWFTMAXTX 				 5
#define	CANTPSTMIANTX					 0x0A

#define  CANTP_FCPDUIDRX				0
#define	CANIF_PDUIDPHYSRX    			 0
#define	CANIF_PDUIDFUNCRX    			 0
#define	PDUR_PDUIDPHYSRX    			 0
#define	PDUR_PDUIDFUNCRX    			 1
#define	CANTPRXCHANNELPHYS			 0
#define	CANTPRXCHANNELFUNC			 1
#define	CANTPBSRX    					 0
#define	CANTPNAR						 2	
#define	CANTPNBR						 1
#define	CANTPNCR						 15
#define	CANTPRXDI						 6
#define	CANTPWFTMAXRX 				 5
#define	CANTPSTMIANRX					 0x0A

#define CANTP_MAIN_FUNCTION_PERIOD_TIME_MS	1000
#define CANTP_CONVERT_MS_TO_MAIN_CYCLES(x) 	(x)/CANTP_MAIN_FUNCTION_PERIOD_TIME_MS

#define CANTP_NSDU_CONFIG_LIST_SIZE		4
#define CANTP_NSDU_RUNTIME_LIST_SIZE		4


//extern CanTp_ConfigType CanTpConfig;
//extern const CanTp_NSduType CanTpNSduConfigList[];

#endif

