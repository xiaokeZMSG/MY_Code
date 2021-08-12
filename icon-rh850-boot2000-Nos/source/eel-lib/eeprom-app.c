#include "R_TypeDefs.h"
#include "R_EEL.h"
#include "EEL_Descriptor.h"
#include "osal.h"
#include "eeprom-app.h"

#define EEL_ERROR_MAX_COUNT     (10u)
typedef struct eel_init_data_tag{
  uint16_t id;
  uint16_t len;  
  const uint8_t *Data;
}eel_init_data_t;

const uint8_t eepromInitFlagData[] = {0x5A, 0x5A, 0x5A, 0x5A};
const uint8_t updateFlagInitData[] = {0xff, 0xff, 0xff, 0xff};
const uint8_t eepromEndFlagData[]  = {0xA5, 0xA5, 0x5A, 0x5A};

eel_init_data_t  el_init_data_table[]={
   { EEPROM_INITFLAG_ID, 4,  eepromInitFlagData},
   { UPDATEFLAG,           4,  updateFlagInitData},
   { EEPROM_ENDFLAG_ID,  4,  eepromEndFlagData},
};

static void eelApp_InitE2promData(void)
{
   uint16_t i;
   for(i=0; i<sizeof(el_init_data_table)/sizeof(eel_init_data_t); i++)
   {
      eelWrite(el_init_data_table[i].id, el_init_data_table[i].Data, el_init_data_table[i].len);
   }
}


static uint8_t eelApp_ErrorHdr( r_eel_status_t stat )
{
    uint8_t ret;

    ret = EEL_ERROR;
    
    switch(stat)
    {
        case R_EEL_OK:                              /**< Normal:  Operation ended successfully   */
            ret  = EEL_OK;
            break;
        case R_EEL_BUSY:                            /**< Normal:  EEL busy (Operation ongoing)   */
            ret  = eelApp_WaitIdle();
            break;
        case R_EEL_ERR_ERASESUSPEND_OVERFLOW:       /**< Warning: Too often erase suspend/resume */
            ret  = EEL_OK;                       // ignore warning  - return RES_OK
            break;
        case R_EEL_ERR_FIX_DONE:                    /**< Warning: Fix done during startup        */
            ret  = EEL_OK;                       // ignore warning  - return RES_OK
            break;
        case R_EEL_ERR_CONFIGURATION:               /**< Error:   Configuration error            */
            ret  = eelFormat();
            break;
        case R_EEL_ERR_PARAMETER:                   /**< Error:   Parameter error                */
            ret  = EEL_ERROR;
            break;
        case R_EEL_ERR_REJECTED:                    /**< Error:   Operation rejected, EEL busy   */
            ret  = eelApp_WaitIdle();
            break;
        case R_EEL_ERR_ACCESS_LOCKED:               /**< Error:   Read/Write access locked       */
            ret = EEL_ERROR;                        // reserve to process   - return RES_NG
            break;
        case R_EEL_ERR_NO_INSTANCE:                 /**< Error:   No data instance for the ID    */
            ret = EEL_ERROR;                        // reserve to process   - return RES_NG
            break;
        case R_EEL_ERR_POOL_FULL:                   /**< Error:   Pool is full. Write is blocked */
            ret  = eelApp_WaitIdle();
            break;
        case R_EEL_ERR_FLASH_ERROR:                 /**< Error:   Flash write error              */
            ret  = eelClose();
            ret  = eelFormat();
            break;
        case R_EEL_ERR_INTERNAL:                    /**< Error:   Internal undefined error       */
            ret  = eelClose();
            ret  = eelFormat();
            break;
        case R_EEL_ERR_POOL_EXHAUSTED:              /**< Error:   Pool exhausted                 */
            ret =  EEL_ERROR;                        // reserve to process   - return RES_NG
            break;
        case R_EEL_ERR_POOL_INCONSISTENT:           /**< Error:   Pool inconsistent              */
            ret  = eelFormat();
            ret  = eelInit();
	    eelApp_InitE2promData(); 
            break;
        case R_EEL_ERR_COMMAND:                     /**< Error:   Unknown command                */
            ret = EEL_ERROR;                        // reserve to process   - return RES_NG
            break;
        default:
            ret = EEL_ERROR;
            break;
    }

    return ret;
}
uint8_t eelApp_init(void)
{
    r_eel_request_t    myReq;
    r_eel_status_t     reqStat;
    reqStat = eelInit();
    if( R_EEL_ERR_POOL_INCONSISTENT == reqStat )
    {    
       eelFormat();
        /* Format procedure ends with EEL re-init */
        reqStat = eelInit();
	/*Write eeprom init Data*/	
	eelApp_InitE2promData(); 
    }
   // nubEelApp_ErrorHdr(reqStat);
    return reqStat;
}
uint8_t eelApp_write( uint16_t id, uint8_t *wBuf, int32_t len )
{
    uint8_t  stat = EEL_ERROR;
    r_eel_status_t      status_enu; 
    uint32_t     loopCount;
    loopCount = 0;
    while(loopCount < 3)
    {
	status_enu= eelWrite(id, wBuf, len);
	if((R_EEL_ERR_CONFIGURATION == status_enu)||(R_EEL_ERR_FLASH_ERROR == status_enu)||(R_EEL_ERR_INTERNAL == status_enu)||(R_EEL_ERR_NO_INSTANCE == status_enu))
	{
	    eelClose();
		eelFormat();
        eelInit();
	    loopCount ++;; 
	    stat = EEL_ERROR;
	}
	else if((R_EEL_OK == status_enu)||(R_EEL_ERR_FIX_DONE == status_enu))
	{
            stat = EEL_OK;
	    break;
	}
	else if((R_EEL_BUSY== status_enu)||(R_EEL_ERR_REJECTED == status_enu)||(R_EEL_ERR_POOL_FULL == status_enu))
	{
	    status_enu = eelApp_WaitIdle();
	    if(R_EEL_OK == status_enu)
	    {
		 stat = EEL_OK;
		 break;
	    }
	    else
	    {
		 stat = EEL_ERROR;
	    }
	}
	else 
	{
	    stat = EEL_ERROR;
	    break;
	}
    }
    return stat;
}
uint8_t eelApp_read( uint16_t id, uint8_t *rBuf, int32_t len )
{
    uint8_t  stat = EEL_ERROR;
    r_eel_status_t   status_enu; 
    uint32_t      loopCount;
    loopCount = 0;    
    
    while(loopCount < 3)
    {
	status_enu= eelRead(id, rBuf, len);
	if((R_EEL_ERR_CONFIGURATION == status_enu)||(R_EEL_ERR_FLASH_ERROR == status_enu)||(R_EEL_ERR_INTERNAL == status_enu))
	{
	    eelClose();
		eelFormat();
        eelInit();
	loopCount ++;; 
	    stat = EEL_ERROR;	    
	}
	else if(R_EEL_ERR_NO_INSTANCE == status_enu)
	{
	    stat = EEL_NO_INSTANCE;
	    break;
	}
	else if((R_EEL_OK == status_enu)||(R_EEL_ERR_FIX_DONE == status_enu))
	{
        stat = EEL_OK;
	    break;
	}
	else if((R_EEL_BUSY== status_enu)||(R_EEL_ERR_REJECTED == status_enu))
	{
	    status_enu = eelApp_WaitIdle();
	    if(R_EEL_OK == status_enu)
	    {
		 stat = EEL_OK;	
		 break;
	    }
	    else
	    {
		 stat = EEL_ERROR;
	    }
	}
	else 
	{
	    stat = EEL_ERROR;
	    break;
	}
    }
	return stat;
}

void write_updateflag(uint8_t flag)
{
	uint32_t stat = (uint32_t)flag;
	eelApp_write(UPDATEFLAG,(uint8_t*)&stat,4);
}

uint8_t read_updateflag(void)
{
	uint32_t stat = 0xf0;
	eelApp_read(UPDATEFLAG,(uint8_t*)&stat,4);
	return (uint8_t)stat;
}

