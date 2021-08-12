/*********************************************************************************************************************
 * File Name     : $Source: eelapp_control.c $
 * Mod. Revision : $Revision: 1.8 $
 * Mod. Date     : $Date: 2014/09/10 18:53:53JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : Application sample program control module
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * DISCLAIMER 
 * This software is supplied by Renesas Electronics Corporation and is only  intended for use with Renesas products. 
 * No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all 
 * applicable laws, including copyright laws. 
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED 
 * OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
 * NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. 
 * TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS 
 * AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY 
 * REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH 
 * DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of 
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link: 
 * http://www.renesas.com/disclaimer 
 * 
 * Copyright (C) 2014 Renesas Electronics Corporation. All rights reserved.     
 *********************************************************************************************************************/


/*********************************************************************************************************************
 * header files include
 *********************************************************************************************************************/
#include "R_TypeDefs.h"
#include "R_FDL.h"
#include "FDL_Descriptor.h"
#include "R_EEL.h"
#include "EEL_Descriptor.h"
#include "fdl_user.h"
#include "osal.h"
#include "eeprom-if.h"

/*********************************************************************************************
 *      Macro Define
 ********************************************************************************************/
#define FDL_WAIT_TIMEOUT_UM     (10000)         // 10ms
#define EEL_WAIT_TIMEOUT_UM     (120000UL)      // 600ms
#define EEL_LOOP_FIN            (3U)

/*********************************************************************************************************************
 * Module internal function prototypes
 *********************************************************************************************************************/




/*********************************************************************************************************************
   Function name:  eeprom_ErrorHdr
 *********************************************************************************************************************/

/*********************************************************************************************************************
   Function name:  eeprom_HdrLoop
 *********************************************************************************************************************/
static r_eel_status_t eeprom_HdrLoop( r_eel_request_t *req )
{
    uint32_t  loopCnt; 
    loopCnt = 0;
   
    /* Wait until operation end */
    while(loopCnt < EEL_WAIT_TIMEOUT_UM)
    {
        if( R_EEL_BUSY == req->status_enu )
	{
	        loopCnt++;
	        R_EEL_Handler();
	}
        else
        {
          //eeprom_ErrorHdr( req->status_enu);         /* Return value check */
           break;
        }
    }
    /* Process result */  
    return req->status_enu;
}
/*********************************************************************************************************************
   Function name:  eelApp_WaitIdle
 *********************************************************************************************************************/
r_eel_status_t eelApp_WaitIdle(void)
{
    uint32_t auwLoopCnt;
    r_eel_driver_status_t  driverStatus;

    /* variable init */
    auwLoopCnt  = 0;
    
    /* Wait until early read/write is possible (or error) */
    while(auwLoopCnt < EEL_WAIT_TIMEOUT_UM)
    {
        R_EEL_Handler();
        R_EEL_GetDriverStatus( &driverStatus );

        /* Call the R_EEL_Handler for startup processing until limited access is possible or 
           error occurred. */
        if(R_EEL_OPERATION_IDLE != driverStatus.operationStatus_enu)
        {
            auwLoopCnt++;                              
        }
        else
        {           
            break;           
        }        
    }  

    return driverStatus.operationStatus_enu;
}
/*********************************************************************************************************************
   Function name:  eelFormat
 *********************************************************************************************************************/

r_eel_status_t eelFormat(void)
{
    r_eel_request_t myReq;
    myReq.command_enu = R_EEL_CMD_FORMAT;
    R_EEL_Execute(&myReq);
    eeprom_HdrLoop(&myReq); 
    return myReq.status_enu;
}

/*********************************************************************************************************************
   Function name:  eelDelay1us
 *********************************************************************************************************************/

static void eelDelay1us(void)
{
    uint32_t  cnt;
    for(cnt = 0; cnt < 5U; cnt++)
    {
                __nop();
                __nop();
                __nop();
                __nop();
                __nop();
				__nop();
                __nop();
    }
}

/*********************************************************************************************************************
   Function name:  eelInit
 *********************************************************************************************************************/
r_eel_status_t eelInit( void )
{
    r_eel_status_t                eelRet;
    r_eel_driver_status_t         driverStatus;
    r_fdl_request_t               req;
    uint32_t                      timeCnt;

    /* 1st initialize the FDL */
    //fdlRet = R_FDL_Init( &eeprom_fdlConfig_enu );
    FDL_Init();
   
    /* Next initialize the EEL */
    eelRet = R_EEL_Init( &eelConfig_enu, R_EEL_OPERATION_MODE_NORMAL );
    //eeprom_ErrorHdr( eelRet );         /* Return value check */
    
    eelRet = R_EEL_Startup();
   // eeprom_ErrorHdr( eelRet );         /* Return value check */
    
    /* Call the R_EEL_Handler for startup processing until limited access is possible or 
       error occurred. */
    for(timeCnt=0; timeCnt<EEL_WAIT_TIMEOUT_UM; timeCnt++)
    {
        R_EEL_Handler();
        R_EEL_GetDriverStatus( &driverStatus );
    
    /* Wait until early read/write is possible (or error) */
         if( ( R_EEL_OPERATION_STARTUP == driverStatus.operationStatus_enu ) &&( R_EEL_ACCESS_LOCKED == driverStatus.accessStatus_enu) )
         {  
		
         }
	 else
	 { 
		break;
	}
     }
   
    return driverStatus.operationStatus_enu;
}

/*********************************************************************************************************************
   Function name:  eelClose
 *********************************************************************************************************************/
r_eel_status_t eelClose( void )
{
    uint32_t      loopCnt;
    r_eel_driver_status_t   driverStatus;

    loopCnt  = 0;

    /* Shut down processing */
    R_EEL_ShutDown();

    /* wait EEL shutdown execute finish */
    while(loopCnt < EEL_WAIT_TIMEOUT_UM)
    {
        R_EEL_Handler();
        R_EEL_GetDriverStatus( &driverStatus );

        /* Call the R_EEL_Handler for shutdown processing until limited access is possible or 
           error occurred. */
        if( R_EEL_OPERATION_PASSIVE != driverStatus.operationStatus_enu )
        {
            loopCnt++;                      
        }
        else
        {
            /* exit     */           
            break;
        }        
    } 
    return driverStatus.operationStatus_enu;
}

/*********************************************************************************************************************
   Function name:  eelWrite
 *********************************************************************************************************************/
r_eel_status_t eelWrite( uint16_t id, uint8_t *wBuf, int32_t len )
{
        r_eel_request_t myReq;
        myReq.address_pu08  = wBuf;
	myReq.identifier_u16 = id;
	myReq.length_u16 = len;
	myReq.offset_u16 = 0;
	myReq.command_enu = R_EEL_CMD_WRITE;
	R_EEL_Execute( &myReq );
        eeprom_HdrLoop( &myReq );		
	return myReq.status_enu;
}

/*********************************************************************************************************************
   Function name:  eelRead
 *********************************************************************************************************************/
r_eel_status_t eelRead( uint16_t id, uint8_t *rBuf, int32_t len )
{  
        r_eel_request_t    myReq;
	myReq.address_pu08  = rBuf;
	myReq.identifier_u16 = id;
	myReq.length_u16 = len;
	myReq.offset_u16 = 0;
	myReq.command_enu = R_EEL_CMD_READ;
	R_EEL_Execute( &myReq );
        eeprom_HdrLoop( &myReq );		
	return myReq.status_enu;
}


