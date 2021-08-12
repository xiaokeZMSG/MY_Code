/***********************************************************************\
*	file name  : hp-external.h
*	Author     : mgd
*	Description: Can module external interface function description
* |----------------------------------------------------------|
* |	Version    |	 Date     |	Author  |   change           |
* |------------|--------------|---------|--------------------|
* |   1.0      |   2021.08.05 |   mgd   |  first version     |
* |----------------------------------------------------------|
\*********************************************************************/
#ifndef __HP_EXTERNAL_H__
#define __HP_EXTERNAL_H__
/****************************************************************************\
* Include header files
\****************************************************************************/
#include "r_typedefs.h"

/****************************************************************************\
* Constant and Macro Definitions using #define
\*****************************************************************************/



/****************************************************************************\
* Enumerations and Structures and Typedefs
\*****************************************************************************/  
typedef enum{
   HP_DTC_BK_TEMP_HIGH_ID,
   HP_DTC_LCD_TEMP_HIGH,
   HP_DTC_DESER_ERR,
}hp_dtc_id_e;

/****************************************************************************\
* Function Prototypes for Private Functions with File Level Scope
\*****************************************************************************/
/*****************************************************************************\
 * Function    : hp_set_dtc_status                                           *
 * Parameters  : id for hp_dtc_id_e 
 *                 HP_DTC_BK_TEMP_HIGH_ID : backlight temperature high
 *                 HP_DTC_LCD_TEMP_HIGH   : LCD temperature high
 *                 HP_DTC_DESER_ERR       : Max9278 chip error
 *             : status for
 *                 0:    OK;   1: failer
 * Returns     : None
 * Description : 1)When the system is started, the backlight temperature, 
 *                 LCD temperature and max9278 status are sent once;
 *				 2)Send a new status when the backlight temperature, 
 *                 LCD temperature and max9278 status changes
 * provided by : This function is provided by can module and called by the can module
\*****************************************************************************/ 
extern void hp_set_dtc_status(hp_dtc_id_e id, uint8_t  status);

/*****************************************************************************\
 * Function    : hp_eel_write_data                                           *
 * Parameters  : group for 
 *                 0 : First set of structure data
 *                 1 : The second set of structure data
 *             : buf
 *                 Pointer to the structure data to be written
 * Returns     : 0:ok;1:error
 * Description : The data is saved in EEPROM, 32 bytes for each group of data, 
 *               and 64 bytes for two groups of data in total
 * note        : Do not call the read / write EEPROM function frequently 
                 and not called in interrupt function
 * provided by : This function is provided by can module and called by the user module
\*****************************************************************************/ 
uint8_t hp_eel_write_data(uint8_t group, void *buf);

/*****************************************************************************\
 * Function    : hp_eel_read_data                                            *
 * Parameters  : group for 
 *                 0 : First set of structure data
 *                 1 : The second set of structure data
 *             : buf
 *                 Pointer to the structure data to be read
 * Returns     : 0:ok;1:error
 * Description : Read data from EEPROM, 32 bytes for each group of data, 
 *               64 bytes for two groups of data in total
 * note        : Do not call the read / write EEPROM function frequently 
 * provided by : This function is provided by can module and called by the user module
\*****************************************************************************/ 
uint8_t hp_eel_read_data(uint8_t group, void *buf);

/*****************************************************************************\
 * Function    : hp_set_mmi_data                                             *
 * Parameters  : HPBacklightMode for 
 *                 0x0: No Request
 *				   0x1: Level 1 Request
 *				   0x2: Level 2 Request
 *				   0x3: Level 3 Request
 *				   0x4: Level 4 Request
 *				   0x5: Level 5 Request
 *				   0x6: Level 6 Request
 *				   0x7: Level 7 Request
 *				   0x8: Level 8 Request
 *				   0x9: Level 9 Request
 *				   0xA: Level 10 Request
 *				   0xB~0xE: Reserved
 *				   0xF: Invalid
 *             : HPAcive for
 *                 0x0: No Request 
 *                 0x1: Off
 *                 0x2: On 
 *                 0x3: Reserved
 *             : HPBacklightLevel for
 *                0x0: No Request
 *                0x1: Auto Request
 *                0x2: Manual Request
 *                0x3: Reserved   
 * Returns     : void
 * Description : The data is transmitted to the user through can 
 * provided by : This function is provided by the user module and called by the can module
\*****************************************************************************/ 
void hp_set_mmi_data(uint8_t HPBacklightMode, uint8_t HPAcive, uint8_t HPBacklightLevel);

/*****************************************************************************\
 * Function    : hp_get_mmi_data                                             *
 * Parameters  : *HPBacklightMode for 
 *                 0x0: Default
 *				   0x1: Level 1 Request
 *				   0x2: Level 2 Request
 *				   0x3: Level 3 Request
 *				   0x4: Level 4 Request
 *				   0x5: Level 5 Request
 *				   0x6: Level 6 Request
 *				   0x7: Level 7 Request
 *				   0x8: Level 8 Request
 *				   0x9: Level 9 Request
 *				   0xA: Level 10 Request
 *				   0xB~0xE: Reserved
 *				   0xF: Invalid
 *             : *HPAcive for
 *                 0x0: Default 
 *                 0x1: Off
 *                 0x2: On 
 *                 0x3: Reserved
 *             : *HPBacklightLevel for
 *                0x0: Default
 *                0x1: Auto Request
 *                0x2: Manual Request
 *                0x3: Reserved   
 * Returns     : 0:OK; 1:error
 * Description : The data saved by the user module required by the can module is obtained once 
                 when the system is started
 * provided by : This function is provided by the user module and called by the can module
\*****************************************************************************/ 
uint8_t hp_get_mmi_data(uint8_t *HPBacklightMode, uint8_t *HPAcive, uint8_t *HPBacklightLevel);
	
/*****************************************************************************\
 * Function    : hp_set_bcm_brightness										 *
 * Parameters  : HudBrightnessValue for 
 *				   0--0x7E ,7F--FF Invalid
 *			   : HudBrightnessUnit:  Light intensity unit level
 *				 0x0：No Level  
 *				 0x1：100 lux
 *				 0x2：1000 lux 
 *				 0x3：Reserved
 * Returns	   : void
 * Description : The data is transmitted to the user through can 
 * provided by : This function is provided by the user module and called by the can module
\*****************************************************************************/ 

void hp_set_bcm_brightness(uint8_t HudBrightnessValue, uint8_t HudBrightnessUnit);

/*****************************************************************************\
 * Function    : hp_get_acc_state                                            *
 * Parameters  : void
 * Returns     : 0: ON;1:OFF;2:sleep
 * Description : k15 state
 * provided by : This function is provided by the user module and called by the can module
\*****************************************************************************/ 
uint8_t hp_get_acc_state(void);

/*****************************************************************************\
 * Function    : hp_set_io2f_backlight                                       *
 * Parameters  : HPBacklightLevel  
 *                 1--10 for Level 1 to Level 10
 *                 0xff  for exit io2f control
 * Returns     : void
 * Description : 1)The test tool controls the backlight brightness through io2f;
 *               2)When the parameter is 1-10, enter the test tool control mode; 
                   When the parameter is 0xff, exit the test tool control mode 
                   and restore the original brightness value, switch and brightness mode
 * provided by : This function is provided by the user module and called by the can module
\*****************************************************************************/ 
void hp_set_io2f_backlight(uint8_t HPBacklightLevel);


#endif/*__HP_EXTERNAL_H__*/
