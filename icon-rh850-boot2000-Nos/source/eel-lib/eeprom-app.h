#ifndef __EEPROM_APP_H__
#define __EEPROM_APP_H__
#include "R_TypeDefs.h"
#include "eeprom-if.h"

#define EEL_OK            (0u)
#define EEL_ERROR         (1u)
#define EEL_NO_INSTANCE   (0x24)


uint8_t eelApp_init (void);
uint8_t eelApp_write( uint16_t id, uint8_t *wBuf, int32_t len );
uint8_t eelApp_read( uint16_t id, uint8_t *rBuf, int32_t len );
void write_updateflag(uint8_t flag);
uint8_t read_updateflag(void);
#endif /*__EEPROM_APP_H__*/
