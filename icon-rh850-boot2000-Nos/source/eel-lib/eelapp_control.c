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
#include "target.h"

/*********************************************************************************************************************
 * Module internal function prototypes
 *********************************************************************************************************************/
static r_eel_status_t SampleApp_EEL_Init( void );
static void         SampleApp_EEL_HdrLoop( r_eel_request_t *req );
static void         SampleApp_EEL_ErrorHdr( r_eel_status_t stat );

/*********************************************************************************************************************
   Function name:  SampleApp_EEL_ErrorHdr
 *********************************************************************************************************************/
/**
    error reaction function, to check the result of a EEL user operation or of the background 
    operations
    
    Note:
    The reaction of this applicaiton sample is a simple while loop. The user application need 
    to fill this or another error handler with life and with appropriate reactions on the 
    different errors and warnings!
   
    @param[in]  stat        (error) status of an ended EEL operation or of an ended background 
                            operation (operational status is idle)
    @return     ---
*/  
/*********************************************************************************************************************/
static void SampleApp_EEL_ErrorHdr( r_eel_status_t stat )
{
    if( R_EEL_OK != stat )
    {
        if( R_EEL_ERR > stat )
        {
            /* If the status is a warning only, we might ignore it */
        }
        else
        {
            /* Error handler */
           // while( 1 )
                ;
        }
    }
}


/*********************************************************************************************************************
   Function name:  SampleApp_EEL_HdrLoop
 *********************************************************************************************************************/
/**
    loop to finish initiated EEL operations (REad/Write/Format)
    
    Note:
    This simple sample function just polls the end of an EEL operation. In the user application
    the frequent R_EEL_Handler call will be most probably called differently, e.g. in a timed
    task.
   
    @param[in]  req         pointer to the operations request structure
    
    @return     ---
*/  
/*********************************************************************************************************************/
static void SampleApp_EEL_HdrLoop( r_eel_request_t *req )
{
    /* Wait until operation end */
    while( R_EEL_BUSY == req->status_enu )
    {
        R_EEL_Handler();
    }

    SampleApp_EEL_ErrorHdr( req->status_enu);         /* Return value check */
    
    return;
}



/*********************************************************************************************************************
   Function name:  SampleApp_EEL_Init
 *********************************************************************************************************************/
/**
    function to initialize and start of the EEL operation.
    At functions end the EEL has passed the startup processing so far, that either limited access
    is possible (See documentation) or an error has occurred. 
    
    Note: 
    In this simple application sample the startup processing is forwarded by continuous handler 
    function call. So, the function execution time will be long

    @param[in]  req         pointer to the operations request structure
    
    @return     operations status return (OK, warning or error)
*/  
/*********************************************************************************************************************/
static r_eel_status_t SampleApp_EEL_Init( void )
{
    r_fdl_status_t                fdlRet;
    r_eel_status_t                eelRet;
    r_eel_driver_status_t         driverStatus;
    r_fdl_request_t               req;
    
    /* 1st initialize the FDL */
    fdlRet = R_FDL_Init( &eeprom_fdlConfig_enu );
    if( R_FDL_OK != fdlRet )
    {   
        /* Error handler */
        while( 1 )
            ;
    }
    
    /* Prepare the environment */
    req.command_enu     = R_FDL_CMD_PREPARE_ENV;
    req.idx_u32         = 0;
    req.cnt_u16         = 0;
    req.accessType_enu  = R_FDL_ACCESS_NONE;
    R_FDL_Execute( &req );
    
    while( R_FDL_BUSY == req.status_enu )
    {
        R_FDL_Handler();
    }
    if( R_FDL_OK != req.status_enu )
    {   
        /* Error handler */
       // while( 1 )
            ;
    }
    
    /* Next initialize the EEL */
    eelRet = R_EEL_Init( &eelConfig_enu, R_EEL_OPERATION_MODE_NORMAL );
    SampleApp_EEL_ErrorHdr( eelRet );         /* Return value check */
    
    eelRet = R_EEL_Startup();
    SampleApp_EEL_ErrorHdr( eelRet );         /* Return value check */
    
    /* Call the R_EEL_Handler for startup processing until limited access is possible or 
       error occurred. */
    do
    {
        R_EEL_Handler();
        R_EEL_GetDriverStatus( &driverStatus );
    }
    /* Wait until early read/write is possible (or error) */
    while(   ( R_EEL_OPERATION_STARTUP == driverStatus.operationStatus_enu )
           &&( R_EEL_ACCESS_LOCKED     == driverStatus.accessStatus_enu) );

    return( driverStatus.backgroundStatus_enu );
}



/*********************************************************************************************************************
   Function name:  SampleApp_EEL_Control 
 *********************************************************************************************************************/
/**
    EEL control program. Executing a set of dummy EEPROM emulaiton operations

    @param          ---
    @return         ---
*/  
/*********************************************************************************************************************/
void SampleApp_EEL_Control( void )
{
    r_eel_request_t           myReq;
    r_eel_driver_status_t     driverStatus;
    r_eel_status_t            reqStat;
    uint32_t                 i;
    
    uint8_t wBuf_au08[0x100] =  {   0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 
                                    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 
                                    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 
                                    0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 
                                    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 
                                    0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 
                                    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 
                                    0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f 
                                };
    uint8_t rBuf_au08[0x100];
    
   #if 0 
    /* ------------------------------------------------------------------------------------------
        EEL Initialization
        Here we wait until the EEL has at least partly access. Startup processing has not yet 
        ended
       ------------------------------------------------------------------------------------------ */
    reqStat = SampleApp_EEL_Init();

    /* Here we expect:
      driverStatus.operationStatus_enu  = R_EEL_OPERATION_STARTUP
    & driverStatus.accessStatus_enu     = R_EEL_ACCESS_READ_WRITE
    & driverStatus.backgroundStatus_enu = R_EEL_OK
    
    Possible error cases are:
      driverStatus.operationStatus_enu  = R_EEL_OPERATION_STARTUP
    & driverStatus.accessStatus_enu     = R_EEL_ACCESS_READ_WRITE
    & driverStatus.backgroundStatus_enu = a warning

      driverStatus.operationStatus_enu  = R_EEL_OPERATION_PASSIVE
    & driverStatus.accessStatus_enu     = R_EEL_ACCESS_LOCKED
    & driverStatus.backgroundStatus_enu = an error
    */

    /* For debug purpose we can react on an inconsistent pool with format. In the 
       final application, this ought to be avoided as all data is destroyed in the Data Flash */
    if( R_EEL_ERR_POOL_INCONSISTENT == reqStat )
    {    
        myReq.command_enu = R_EEL_CMD_FORMAT;
        R_EEL_Execute( &myReq );
        SampleApp_EEL_HdrLoop( &myReq );

        /* Format procedure ends with EEL re-init */
        reqStat = SampleApp_EEL_Init();
    }

    /* Error check of startup processing (with and without Format) */
    SampleApp_EEL_ErrorHdr( reqStat ); 

#endif
    /* ------------------------------------------------------------------------------------------
        Early operations before startup flow of the EEL has completely ended
       ------------------------------------------------------------------------------------------ */
    /* ----- write access ----- */
    myReq.address_pu08 = (uint8_t*)(&wBuf_au08[0]);
    myReq.identifier_u16 = 0xccccu;
    myReq.command_enu = R_EEL_CMD_WRITE;
    R_EEL_Execute( &myReq );
    SampleApp_EEL_HdrLoop( &myReq );

    /* ----- read access ----- */
    for( i=0; i<0x100; i++ )    /* Initialize the read buffer to prove the read effect */
    {
        rBuf_au08[i] = 0xaa;
    }
    myReq.address_pu08 = (uint8_t*)(&rBuf_au08[3]);
    myReq.identifier_u16 = 0xccccu;
    myReq.length_u16 = 0x9u;
    myReq.offset_u16 = 0x13u;
    myReq.command_enu = R_EEL_CMD_READ;
    R_EEL_Execute( &myReq );
    SampleApp_EEL_HdrLoop( &myReq );
                          
    /* ------------------------------------------------------------------------------------------
        Wait for fully operational and access unlock
       ------------------------------------------------------------------------------------------ */
    do
    {
        R_EEL_Handler();
        R_EEL_GetDriverStatus( &driverStatus );
    }
    /* Wait until the system is completely up and running (or error) */
    while( R_EEL_OPERATION_STARTUP == driverStatus.operationStatus_enu );

    /* Here we expect:
      driverStatus.operationStatus_enu  = R_EEL_OPERATION_BUSY or R_EEL_OPERATION_IDLE
    & driverStatus.accessStatus_enu     = R_EEL_ACCESS_UNLOCKED
    & driverStatus.backgroundStatus_enu = R_EEL_OK
    
    Possible error cases are:
      driverStatus.operationStatus_enu  = R_EEL_OPERATION_BUSY or R_EEL_OPERATION_IDLE
    & driverStatus.accessStatus_enu     = R_EEL_ACCESS_UNLOCKED
    & driverStatus.backgroundStatus_enu = a warning

      driverStatus.operationStatus_enu  = R_EEL_OPERATION_PASSIVE
    & driverStatus.accessStatus_enu     = R_EEL_ACCESS_LOCKED
    & driverStatus.backgroundStatus_enu = an error
    */
    
    /* Error check of background processing */
    SampleApp_EEL_ErrorHdr( driverStatus.backgroundStatus_enu ); 


    /* ------------------------------------------------------------------------------------------
        Normal operations 
       ------------------------------------------------------------------------------------------ */
    /* ----- write access ----- */
    myReq.address_pu08 = (uint8_t*)(&wBuf_au08[0]);
    myReq.identifier_u16 = 0xccccu;
    myReq.command_enu = R_EEL_CMD_WRITE;
    R_EEL_Execute( &myReq );
    SampleApp_EEL_HdrLoop( &myReq );

    /* ----- read access ----- */
    for( i=0; i<0x100; i++ )    /* Initialize the read buffer to prove the read effect */
    {
        rBuf_au08[i] = 0xaa;
    }
    myReq.address_pu08 = (uint8_t*)(&rBuf_au08[3]);
    myReq.identifier_u16 = 0xccccu;
    myReq.length_u16 = 0x10u;
    myReq.offset_u16 = 0x13u;
    myReq.command_enu = R_EEL_CMD_READ;
    R_EEL_Execute( &myReq );
    SampleApp_EEL_HdrLoop( &myReq );
#if 0
    /* ------------------------------------------------------------------------------------------
        Shut down processing
       ------------------------------------------------------------------------------------------ */
    reqStat = R_EEL_ShutDown();
    SampleApp_EEL_ErrorHdr( reqStat ); 
    
    do
    {
        R_EEL_Handler();
        R_EEL_GetDriverStatus( &driverStatus );
    }
    while(R_EEL_OPERATION_PASSIVE != driverStatus.operationStatus_enu );
    
    /* Error check of startup processing (with and without Format) */
    SampleApp_EEL_ErrorHdr( driverStatus.backgroundStatus_enu ); 
 #endif   
    return;
}


