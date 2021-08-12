#ifndef __CANNM_CFG_H
#define __CANNM_CFG_H


#define CANNM_COM_USER_DATA_SUPPORT STD_OFF
#define CANNM_CHANNEL_COUNT 1
#define CANNM_USER_DATA_ENABLED STD_ON
#define CANNM_PASSIVE_MODE_ENABLED STD_OFF
#define CANNM_NODE_DETECTION_ENABLED STD_ON
#define USE_NM
#define NM_TX_PDU_START     0


//added for OSEK
#define NM_RANGE_MASK                        0x3F
/* Nm channel properties */
//#define kNmTxObj                             CanTxNmTPMS
#define kNmCallCycle                         5   //20
#define NMCFG_COUNT_RINGTYP             (20)  // Ttyp=100ms
#define NMCFG_COUNT_RINGMAX             (52-1) // Tmax=260ms
#define NMCFG_COUNT_LIMPHOME            (200)  //Terror=1000ms
#define NMCFG_COUNT_WAITBUSSLEEP        (300)   //Twbs=1500ms
#define NMCFG_COUNT_ACTIVEMIN			(800)//Tactive_min = 4000ms

#endif

