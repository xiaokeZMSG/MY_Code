#ifndef __EEPROM_IF_H__
#define __EEPROM_IF_H__
#include "R_TypeDefs.h"
#include "R_EEL.h"


r_eel_status_t eelFormat(void);
r_eel_status_t eelInit(void);
r_eel_status_t eelClose(void);
r_eel_status_t eelWrite( uint16_t id, uint8_t *wBuf, int32_t len );
r_eel_status_t eelRead( uint16_t id, uint8_t *rBuf, int32_t len );
r_eel_status_t eelApp_WaitIdle(void);
#endif /*__EEPROM_IF_H__*/