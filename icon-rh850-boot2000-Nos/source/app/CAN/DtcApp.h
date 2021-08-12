/***********************************************************************
*	Title:	DtcApp.h
*	Author:	mgd
*	Date:	2021.05.15	
*	Description:  This is the standard code file for DtcApp.h
*********************************************************************/
#ifndef __DTCAPP_H__
#define __DTCAPP_H__
#include "r_typedefs.h"
typedef enum{
   DTC_UNINIT,
   DTC_NORMAL,
   DTC_ERROR
}hp_dtc_stat_e;
  
typedef enum{
   HP_DTC_BK_TEMP_HIGH_ID,
   HP_DTC_LCD_TEMP_HIGH,
   HP_DTC_DESER_ERR,
}hp_dtc_id_e;

extern void hp_set_dtc_status(hp_dtc_id_e id, uint8_t  st);
extern void set_dtc_PowerVolHSts(hp_dtc_stat_e st);
extern void set_dtc_PowerVolLSts(hp_dtc_stat_e st);
#endif/*__DTCAPP_H__*/
