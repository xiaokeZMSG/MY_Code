#ifndef __EEPROM_H__
#define __EEPROM_H__
#include "R_TypeDefs.h"
#include "R_EEL.h"



r_eel_status_t init_eeprom( void );
r_eel_status_t eeprom_write( uint16_t id, uint8_t *wBuf, int32_t len );
r_eel_status_t eeprom_read( uint16_t id, uint8_t *rBuf, int32_t len );
void write_updateflag(uint8_t flag);

uint8_t read_updateflag(void);
#endif /*__EEPROM_H__*/