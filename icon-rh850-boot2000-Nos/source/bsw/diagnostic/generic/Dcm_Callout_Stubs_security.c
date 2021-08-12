/*-------------------------------- Arctic Core ------------------------------
 * Copyright (C) 2013, ArcCore AB, Sweden, www.arccore.com.
 * Contact: <contact@arccore.com>
 * 
 * You may ONLY use this file:
 * 1)if you have a valid commercial ArcCore license and then in accordance with  
 * the terms contained in the written license agreement between you and ArcCore, 
 * or alternatively
 * 2)if you follow the terms found in GNU General Public License version 2 as 
 * published by the Free Software Foundation and appearing in the file 
 * LICENSE.GPL included in the packaging of this file or here 
 * <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>
 *-------------------------------- Arctic Core -----------------------------*/

/* Ecum Callout Stubs - generic version */

#include "Dcm.h"
#if defined(USE_MCU)
#include "Mcu.h"
#endif
#include "osal.h"
#define DescMake32Bit(hiHiByte,hiLoByte,loHiByte,loLoByte)           ((uint32_t)((((uint32_t)(hiHiByte))<<24)| \
                                                                     (((uint32_t)(hiLoByte))<<16)| \
                                                                     (((uint32_t)(loHiByte))<<8) | \
                                                                     ((uint32_t)(loLoByte))))

/* decompose 32 bit data in byte stream */
#define DescGetHiHiByte(data)                                        ((uint8_t)(((uint32_t)(data))>>24))
#define DescGetHiLoByte(data)                                        ((uint8_t)(((uint32_t)(data))>>16))
#define DescGetLoHiByte(data)                                        ((uint8_t)(((uint32_t)(data))>>8))
#define DescGetLoLoByte(data)                                        ((uint8_t)(data))

static volatile uint32_t g_randomData;
//==================================================
const uint8_t KEY_MASK[4] = {0x48,0x50,0x5A,0xA5};
static uint32_t uds_calc_key(uint32_t seed)   
{
	uint8_t caLData[4],key[4];
	caLData[0] = (seed>>24)&0xff;
	caLData[1] = (seed>>16)&0xff;
	caLData[2] = (seed>>8)&0xff;
	caLData[3] = seed&0xff;
	caLData[0] = caLData[0] ^ KEY_MASK[0];
	caLData[1] = caLData[1] ^ KEY_MASK[1];
	caLData[2] = caLData[2] ^ KEY_MASK[2];
	caLData[3] = caLData[3] ^ KEY_MASK[3];
	key[0]=((caLData[3]&0x0f)<<4)|(caLData[3]&0xf0);
	key[1]=((caLData[1]&0x0f)<<4)|((caLData[0]&0xf0)>>4);
	key[2]= (caLData[1]&0xf0)|((caLData[2]&0xf0)>>4);
	key[3]=((caLData[0]&0x0f)<<4)|(caLData[2]&0x0f);
	return (uint32_t)((key[0]<<24)|(key[1]<<16)|(key[2]<<8)|key[3]);
       
}


Std_ReturnType SecurityAccessGetSeed(Dcm_OpStatusType OpStatus, unsigned char *seed, unsigned char *errorCode)
{
        volatile uint32_t tempData;
	g_randomData = osal_time();    	
 	tempData =  osal_time();
	g_randomData = (uint32_t)(tempData<<16); /*lint !e701*/
	g_randomData |= tempData;
	g_randomData ^= 0xA55A55AA; 
	*(seed+0)=(unsigned char)(g_randomData>>24);
	*(seed+1)=(unsigned char)(g_randomData>>16);
	*(seed+2)=(unsigned char)(g_randomData>>8);
	*(seed+3)=(unsigned char)(g_randomData);
	
	*errorCode= DCM_E_POSITIVERESPONSE;
	
	return E_OK;
}
Std_ReturnType SecurityAccessCompareKey(const uint8_t *key)
{
//    unsigned char   compareKeystate=E_OK;
	uint32_t 		tmpKey;     /* Store Key on the stack, invisible for extern access */
	uint32_t          tmpSeed;

	tmpSeed =DescMake32Bit(*(key+0),*(key+1),*(key+2),*(key+3));

	tmpKey = uds_calc_key(g_randomData);

	if (tmpKey != tmpSeed)   {
		return E_NOT_OK;
	}

	return E_OK;
}

