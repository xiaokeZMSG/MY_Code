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

/** @req CANTP157 */

#ifndef CANTP_H_
#define CANTP_H_
#include "Std_Types.h"
#include "CanTp_Types.h"

//#define CAN_MAILBOX_INDEX_8  8
#define CAN_DIAG_MSG_START 5//modify for BAIC


#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE (!FALSE)
#endif

#ifndef 	NULL
#define	NULL	0
#endif

//#define NTFRSLT_OK						0x00
//#define NTFRSLT_E_NOT_OK				0x01
//#define NTFRSLT_E_CANCELATION_NOT_OK	0x0C
//#define NTFRSLT_E_WRONG_SN 				0x05
//#define NTFRSLT_E_NO_BUFFER 			0x09


typedef enum {
	BUFREQEST_OK=0,
	BUFREQEST_NOT_OK,
	BUFREQEST_BUSY,
	BUFREQEST_OVFL
} BufReq_BackType;



//typedef unsigned short PduLengthType;
typedef struct {
	unsigned char *SduDataPtr;			 /* payload */
	PduLengthType SduLength;	 /* length of SDU */
} PduInformationType;


void CanTp_Init( const CanTp_ConfigType* CfgPtr);


void CanTp_Shutdown(void); /** @req CANTP211 */

Std_ReturnType CanTp_Transmit( PduIdType CanTpTxSduId, const PduInfoType * CanTpTxInfoPtr ); /** @req CANTP212 */

void CanTp_MainFunction(void); /** @req CANTP213 */




#endif /* CANTP_H_ */
