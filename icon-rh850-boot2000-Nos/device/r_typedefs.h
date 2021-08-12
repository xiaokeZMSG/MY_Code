/*
****************************************************************************
PROJECT : VLIB
FILE    : $Id: r_typedefs.h 3854 2014-09-15 14:29:17Z florian.zimmermann $
============================================================================ 
DESCRIPTION
Predefined data types
============================================================================
                            C O P Y R I G H T                                    
============================================================================
                           Copyright (c) 2012 
                                  by 
                       Renesas Electronics (Europe) GmbH. 
                           Arcadiastrasse 10
                          D-40472 Duesseldorf
                               Germany
                          All rights reserved.
============================================================================
Purpose: only for testing

DISCLAIMER                                                                   
This software is supplied by Renesas Electronics Corporation and is only     
intended for use with Renesas products. No other uses are authorized. This   
software is owned by Renesas Electronics Corporation and is protected under  
all applicable laws, including copyright laws.                               
THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING  
THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT      
LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE   
AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.          
TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS       
ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE  
FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR   
ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE  
BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.                             
Renesas reserves the right, without notice, to make changes to this software 
and to discontinue the availability of this software. By using this software,
you agree to the additional terms and conditions found by accessing the      
following link:                                                              
http://www.renesas.com/disclaimer *                                          
Copyright (C) 2011 Renesas Electronics Corporation. All rights reserved.     

****************************************************************************
*/

#ifndef R_TYPEDEF_H
#define R_TYPEDEF_H

/*******************************************************************************
*
*                   Defines
*
************************************************************
*/
#ifdef __GHS__
#pragma ghs startnomisra
#endif

#define R_STR(s)           # s
#define R_XSTR(s)          R_STR(s)
#define R_DOT(a,b)         a ## . ## b
#define R_XDOT(a,b)        R_DOT(a,b)
        
#define R_SPACE            " "
#define R_VERSIONPREFIX    "@(#)Version "
#define R_VERSIONPOSTFIX   " - "

#define R_VERSION(macro, hi, lo)        { "@(#)" # macro " driver version "  R_XSTR(hi) "."  R_XSTR(lo)}

#if defined (R_DBG_PRINT_MSG)
#define R_HALT_ON_ERROR(txt)    {R_DBG_PRINT(R_DBG_MSG_ERR, txt); for ( ; ; ){}}
#define R_DISPLAY_ERROR(txt)     R_DBG_PRINT(R_DBG_MSG_ERR, txt)
#define R_LOG(...)              printf(__VA_ARGS__)

#else
#define R_HALT_ON_ERROR(txt)    {for ( ; ; ){}}
#define R_DISPLAY_ERROR(txt)    
#define R_LOG(...)             
#endif

#define R_INLINE inline

#ifdef __GHS__
#pragma ghs endnomisra
#endif


/*******************************************************************************
*
*                   Enumerators 
*
************************************************************
*/

typedef enum
{
  R_OK = 0u,
  R_ERROR,
  R_ERROR_NOTIFY,
  R_PARAMETER_MISSING,
  R_PARAMETER_RANGE,
  R_PARAMETER_INCORRECT,
  R_DATA_MISMATCH
} r_Error_t;


/*******************************************************************************
*
*                   Types
*
************************************************************
*/

/* Define ISO conform exact types, if the compiler does not
   support them,
*/

#ifndef uint8_t
typedef char               char_t;
typedef signed char        int8_t;
typedef signed short       int16_t;  
typedef signed long        int32_t; 
typedef signed long long   int64_t; 
typedef signed char        sint8_t;
typedef signed short       sint16_t;  
typedef signed long        sint32_t; 
typedef signed long long   sint64_t;
typedef unsigned char      uint8_t;  
typedef unsigned short     uint16_t; 
typedef unsigned long      uint32_t; 
typedef unsigned long long uint64_t;  
typedef unsigned char      rBool;
#endif /* uint8_t */

#define INT8_MIN     (-128)
#define INT16_MIN    (-32768)
#define INT32_MIN    (-2147483647-1)
#define INT64_MIN    (-9223372036854775807LL-1LL)

#define INT8_MAX     (127)
#define INT16_MAX    (32767)
#define INT32_MAX    (2147483647)
#define INT64_MAX    (9223372036854775807LL)

#define UINT8_MAX    (255)
#define UINT16_MAX   (65535)
#define UINT32_MAX   (4294967295U)
#define UINT64_MAX   (18446744073709551615ULL)


typedef void* handle_t;  

/* Version info */
typedef struct 
{
    uint16_t major; 
    uint16_t minor; 
} r_version_t;     

#define bool   rBool
#ifndef R_NULL
#define R_NULL ((void*)0)
#endif /* R_NULL */

#ifndef R_TRUE
#define R_TRUE 1
#endif /* R_TRUE */

#ifndef R_FALSE
#define R_FALSE 0
#endif /* R_FALSE */

#define R_EXTERN extern

#ifndef BOOL
#define BOOL bool
#endif

#ifndef false
#define false 0
#endif

#ifndef true
#define true 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef NULL
#define NULL (void*)0
#endif

typedef uint32_t imask_t;
typedef int32_t AppModeType;
//#endif

#endif /* R_TYPEDEF_H_ */




