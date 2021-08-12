/**************************************************************************************************
  Filename:       OSAL_Nv.c
  Revised:        $Date: 2008-08-06 17:17:11 -0700 (Wed, 06 Aug 2008) $
  Revision:       $Revision: 17715 $

  Description:    This module contains the OSAL non-volatile memory functions.


  Copyright 2006-2009 Texas Instruments Incorporated. All rights reserved.

  IMPORTANT: Your use of this Software is limited to those specific rights
  granted under the terms of a software license agreement between the user
  who downloaded the software, his/her employer (which must be your employer)
  and Texas Instruments Incorporated (the "License").  You may not use this
  Software unless you agree to abide by the terms of the License. The License
  limits your use, and you acknowledge, that the Software may not be modified,
  copied or distributed unless embedded on a Texas Instruments microcontroller
  or used solely and exclusively in conjunction with a Texas Instruments radio
  frequency transceiver, which is integrated into your product.  Other than for
  the foregoing purpose, you may not use, reproduce, copy, prepare derivative
  works of, modify, distribute, perform, display or sell this Software and/or
  its documentation for any purpose.

  YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
  PROVIDED “AS IS?WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
  INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
  NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
  TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
  NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
  LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
  INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
  OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
  OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
  (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

  Should you have any questions regarding your right to use this Software,
  contact Texas Instruments Incorporated at www.TI.com.
**************************************************************************************************/

/**************************************************************************************************
  Notes:
    - A trick buried deep in initPage() requires that the MSB of the NV Item Id is to
      be reserved for use by this module.
**************************************************************************************************/

/*********************************************************************
 * INCLUDES
 */


#include "R_Typedefs.h"
#include "osal.h"
#include "OSAL_Nv.h"
#include "datacenter.h"
#include "eeprom-app.h"
/*********************************************************************
 * CONSTANTS
 */



/*********************************************************************
 * @fn      osal_nv_item_init
 *
 * @brief   If the NV item does not already exist, it is created and
 *          initialized with the data passed to the function, if any.
 *          This function must be called before calling osal_nv_read() or
 *          osal_nv_write().
 *
 * @param   id  - Valid NV item Id.
 * @param   len - Item length.
 * @param  *buf - Pointer to item initalization data. Set to NULL if none.
 *
 * @return  NV_ITEM_UNINIT - Id did not exist and was created successfully.
 *          ZSUCCESS       - Id already existed, no action taken.
 *          NV_OPER_FAILED - Failure to find or create Id.
 */
bool osal_nv_item_init( uint32_t id, uint16_t len, void *buf )
{

	uint8_t res;
	uint8_t read_buf[4];
	res=osal_nv_read(id, 4, read_buf);
	if( EEL_NO_INSTANCE == res ) //(0xff == read_buf[0])&&(0xff == read_buf[1])&&(0xff == read_buf[2])&&(0xff == read_buf[3]))
	{
		osal_nv_write(id,len,buf);
		//return 1;
	}
	return 0;
}


/*********************************************************************
 * @fn      osal_nv_item_len
 *
 * @brief   Get the data length of the item stored in NV memory.
 *
 * @param   id  - Valid NV item Id.
 *
 * @return  Item length, if found; zero otherwise.
 */
uint16_t osal_nv_item_len( uint16_t id )
{
   return 0;
}
/*********************************************************************
 * @fn      osal_nv_init
 *
 * @brief   Initialize NV service.
 *
 * @param   p - Not used.
 *
 * @return  none
 */
void osal_nv_init( void *p )
{
	(void)p;  
	eelApp_init();
}
/*********************************************************************
 * @fn      osal_nv_write
 *
 * @brief   Write a data item to NV. Function can write an entire item to NV or
 *          an element of an item by indexing into the item with an offset.
 *
 * @param   id  - Valid NV item Id.
 * @param   ndx - Index offset into item
 * @param   len - Length of data to write.
 * @param  *buf - Data to write.
 *
 * @return  ZSUCCESS if successful, NV_ITEM_UNINIT if item did not
 *          exist in NV and offset is non-zero, NV_OPER_FAILED if failure.
 */
uint8_t osal_nv_write( uint16_t id,  uint16_t len, void *buf )
{	
    return (uint8_t)eelApp_write(id,buf,len);
}


/*********************************************************************
 * @fn      osal_nv_read
 *
 * @brief   Read data from NV. This function can be used to read an entire item from NV or
 *          an element of an item by indexing into the item with an offset.
 *          Read data is copied into *buf.
 *
 * @param   id  - Valid NV item Id.
 * @param   ndx - Index offset into item
 * @param   len - Length of data to read.
 * @param  *buf - Data is read into this buffer.
 *
 * @return  ZSUCCESS if NV data was copied to the parameter 'buf'.
 *          Otherwise, NV_OPER_FAILED for failure.
 */
uint8_t osal_nv_read( uint16_t id, uint16_t len, void *buf )
{ 
    return (uint8_t)eelApp_read(id,buf,len);
}

/*********************************************************************
 * @fn      hp_eel_write_data
 
 *
 * @return  ZSUCCESS if NV data was copied to the parameter 'buf'.
 *          Otherwise, NV_OPER_FAILED for failure.
 */

uint8_t hp_eel_write_data(uint8_t group, void *buf)
{
   uint8_t res;
   if(0 == group)
   	{
   	  res = osal_nv_write(HP_APP1_NV_ID, HP_APP_NV_DATA_MAX,buf);	  
   	}
    else
    {
      res = osal_nv_write(HP_APP2_NV_ID, HP_APP_NV_DATA_MAX,buf);	  
    }
	return res;
}
/*********************************************************************
 * @fn      hp_eel_read_data
 
 *
 * @return  ZSUCCESS if NV data was copied to the parameter 'buf'.
 *          Otherwise, NV_OPER_FAILED for failure.
 */

uint8_t hp_eel_read_data(uint8_t group, void *buf)
{
   uint8_t res;
   if(0 == group)
   	{
   	  res = eelApp_write(HP_APP1_NV_ID, buf, HP_APP_NV_DATA_MAX);	  
   	}
    else
    {
      res = osal_nv_read(HP_APP2_NV_ID, buf, HP_APP_NV_DATA_MAX);	  
    }
	return res;
}

/*********************************************************************
*********************************************************************/
