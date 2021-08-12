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






#include "Com_Arc_Types.h"
#include "Com.h"
#include "Com_Internal.h"
#include "Com_misc.h"
#include <string.h>
#include "debug.h"
#include "generic/Cpu.h"
#include "CanIf.h"
#include "Dem.h"
//#include "standard.h"//Add
extern unsigned char  Communication_Control_TX_Disabled, Communication_Control_RX_Disabled;
#define timerDec(timer) \
	if (timer >= COMTX_MAIN_PERIOD) { \
		timer = timer - COMTX_MAIN_PERIOD; \
	} else {\
        timer = 0; \
	}\

/* Declared in Com_Cfg.c */
extern const ComNotificationCalloutType ComNotificationCallouts[];
extern const ComTimeoutNotificationCalloutType	ComTimeoutNotificationCallouts[];


void Com_MainFunctionRx(void) {
	/* !req COM513 */
	/* !req COM053 */
	/* !req COM352 */
	uint16_t pduId ;
	boolean pduUpdated = false;
	//uint16_t sri;
	const ComSignal_type *signal ;
	Com_Arc_Signal_type * Arc_Signal ;
	const ComIPdu_type *IPdu;
	Com_Arc_IPdu_type *Arc_IPdu;
	imask_t irq_state;
	
	if(TRUE == Communication_Control_RX_Disabled)
	{
	    return;
	}
	Irq_Save(irq_state);
	/* @req COM664 */
	if( COM_INIT != Com_GetStatus() ) {
		DET_REPORTERROR(COM_MAINFUNCTIONRX_ID, COM_E_UNINIT);
		return;
	}
	//DEBUG(DEBUG_MEDIUM, "Com_MainFunctionRx() excecuting\n");
	for (pduId = COM_NOF_TX_IPDU; pduId<COM_NOF_IPDU; pduId++) {
		IPdu = GET_IPdu(pduId);
		Arc_IPdu = GET_ArcIPdu(pduId);

		signal = IPdu->ComIPduSignalRef[0];
		Arc_Signal = GET_ArcSignal(signal->ComHandleId);
#if (DEM_ENABLE_CONDITION_SUPPORT == STD_ON) /*mgd修改，未必合理 2020年3月13日*/
		if (!DemEnableConditions[CONDITION_PHY_BUS]) {
			Arc_Signal->received = false;
			continue;
	        }
#endif
		if (!Arc_Signal->received)
			continue;
		if ( (Arc_IPdu->Com_Arc_IpduStarted) && (signal->ComTimeoutFactor > 0) ) {
			// Decrease deadline monitoring timer.
			timerDec(Arc_Signal->Com_Arc_DeadlineCounter);

			// Check if a timeout has occurred.
			if (Arc_Signal->Com_Arc_DeadlineCounter == 0) {
				/* @req COM500 */
				/* @req COM744 */
			    boolean signalChanged = FALSE;
				if (signal->Com_Arc_IsSignalGroup != 0 /*FALSE*/) {
					if (signal->ComRxDataTimeoutAction == COM_TIMEOUT_DATA_ACTION_REPLACE) {
						uint32_t i;
						for (i=0;signal->ComGroupSignal[i]!=NULL; i++)
						{
						
							Com_WriteSignalDataToPduBuffer(
									signal->ComGroupSignal[i]->ComHandleId,
									TRUE,
									signal->ComGroupSignal[i]->ComSignalInitValue,
									Arc_IPdu->ComIPduDataPtr,
									&signalChanged);
						
						}
						Arc_Signal->ComSignalUpdated = TRUE;
						Arc_Signal->timeout_cnt      = 0;

					}
				}
				else if (signal->ComRxDataTimeoutAction == COM_TIMEOUT_DATA_ACTION_REPLACE) {
					// Replace signal data.
					/* @req COM470 */
					Arc_Signal->ComSignalUpdated = TRUE;
					
					Com_WriteSignalDataToPdu(signal->ComHandleId, signal->ComSignalInitValue, &signalChanged);
                    
				}

				// A timeout has occurred.
				/* @req COM556 */
				//if ((signal->ComTimeoutNotification != COM_NO_FUNCTION_CALLOUT) && (ComNotificationCallouts[signal->ComTimeoutNotification] != NULL) ) {
					//ComNotificationCallouts[signal->ComTimeoutNotification](signal->ComHandleId,0,FALSE);
				//}
				
				if ((signal->ComTimeoutNotification != COM_NO_FUNCTION_CALLOUT) && (ComTimeoutNotificationCallouts[signal->ComTimeoutNotification] != NULL) ) {
					ComTimeoutNotificationCallouts[signal->ComTimeoutNotification](signal->ComHandleId);
				}

				// Restart timer
				/* !req COM291 */
				/* IMPROVEMENT: For signals and signal groups with update bit within the same
				 * I-PDU the smallest configured timeout parameter (ComSignalFirstTimeout,
				 * ComSignalGroupTimeout, ComSignalTimeout, ComSignalGroupTimeout)
				 * of the associated signals and signal groups should be used as reception
				 * timeout parameter. Handle this in generator?*/
				Arc_Signal->Com_Arc_DeadlineCounter = signal->ComTimeoutFactor;
			}
		}

		if (Arc_Signal->ComSignalUpdated) {
			pduUpdated = true;
		}
		

		if (pduUpdated && IPdu->ComIPduSignalProcessing == DEFERRED && IPdu->ComIPduDirection == RECEIVE) {
			uint16_t i;
			UnlockTpBuffer(getPduId(IPdu));
			memcpy(Arc_IPdu->ComIPduDeferredDataPtr,Arc_IPdu->ComIPduDataPtr,IPdu->ComIPduSize);
			for (i = 0; (IPdu->ComIPduSignalRef != NULL) && (IPdu->ComIPduSignalRef[i] != NULL); i++) {
				const ComSignal_type *signal = IPdu->ComIPduSignalRef[i];
				Com_Arc_Signal_type * Arc_Signal = GET_ArcSignal(signal->ComHandleId);
				if (Arc_Signal->ComSignalUpdated) {
					if ((signal->ComNotification != COM_NO_FUNCTION_CALLOUT) && (ComNotificationCallouts[signal->ComNotification] != NULL) ) {
						//ComNotificationCallouts[signal->ComNotification](signal->ComHandleId,0,FALSE);
					}
					Arc_Signal->ComSignalUpdated = FALSE;
				}
			}
		}
		Irq_Restore(irq_state);
	}
}

void Com_IPDUTxTimingClr(void)
{
	const ComIPdu_type *IPdu;
	Com_Arc_IPdu_type *Arc_IPdu;
	uint8_t i;

	for ( i = 0; i<COM_NOF_IPDU; i++) {
		IPdu = &ComConfig->ComIPdu[i];
		Arc_IPdu = GET_ArcIPdu(i);

		if (IPdu->ComIPduDirection == SEND) {
			Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeTimePeriodTimer  = 0;
		}
	}
}

void Com_MainFunctionTx(void) {
	/* !req	COM789 */
	/* !req COM305 */
	imask_t irq_state;
	const ComIPdu_type *IPdu;
	Com_Arc_IPdu_type *Arc_IPdu;
	uint16_t i;
	boolean confirmationStatus;
	const ComSignal_type *signal;
	uint8_t signalIndex;
	if(TRUE == Communication_Control_TX_Disabled)
	{    
	     return;
	}
	/* @req COM665 */
	if( COM_INIT != Com_GetStatus() ) {
		DET_REPORTERROR(COM_MAINFUNCTIONTX_ID, COM_E_UNINIT);
		return;
	}
	//DEBUG(DEBUG_MEDIUM, "Com_MainFunctionTx() excecuting\n");
	// Decrease timers.
	for ( i = 0; i<COM_NOF_TX_IPDU; i++) {
		IPdu     = &ComConfig->ComIPdu[i];
		Arc_IPdu = GET_ArcIPdu(i);
//      if(i== 3)
//		{
//			Calculate_CanData_CheckSum_And_RollingCount(Arc_IPdu);// 0x310 need calculate checksum
//	    }
		
		Irq_Save(irq_state);
		/* !req COM471 */
		// Is this a IPdu that should be transmitted?
	 	if ( (IPdu->ComIPduDirection == SEND) && (Arc_IPdu->Com_Arc_IpduStarted) ) {
      //  if ( 1) {//Just for test, 2017-9-8 19:21:58
			// Decrease minimum delay timer
			timerDec(Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduMinimumDelayTimer);

			// If IPDU has periodic or mixed transmission mode.
			if ( (IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeMode == PERIODIC)
				|| (IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeMode == MIXED) ) {

				timerDec(Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeTimePeriodTimer);

				// Is it time for a direct transmission?
				if ( (IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeMode == MIXED)
					&& (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduNumberOfRepetitionsLeft > 0) ) {

					timerDec(Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeRepetitionPeriodTimer);

					// Is it time for a transmission?
					if ( (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeRepetitionPeriodTimer == 0)
						&& (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduMinimumDelayTimer == 0) ) {

					    Com_TriggerIPDUSend(i);

						// Reset periodic timer
						Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeRepetitionPeriodTimer = IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeRepetitionPeriodFactor;

						// Register this nth-transmission.
						/* @req COM494 */
						Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduNumberOfRepetitionsLeft--;
					}
				}

				// Is it time for a cyclic transmission?
				if ( (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeTimePeriodTimer == 0) && (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduMinimumDelayTimer == 0) ) {
					
                                       
                                         Com_TriggerIPDUSend(i);
					// Reset periodic timer.
					Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeTimePeriodTimer = IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeTimePeriodFactor;
                                      //  Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduMinimumDelayTimer = IPdu->ComTxIPdu.ComTxIPduMinimumDelayFactor;
				}

			// If IPDU has direct transmission mode.
			} 
			else if (IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeMode == DIRECT) {
				// Do we need to transmit anything?
				if (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduNumberOfRepetitionsLeft > 0) {
					timerDec(Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeRepetitionPeriodTimer);

					// Is it time for a transmission?
					if ( (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeRepetitionPeriodTimer == 0) && (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduMinimumDelayTimer == 0) ) {
					    Com_TriggerIPDUSend(i);

						// Reset periodic timer
						Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeRepetitionPeriodTimer = IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeRepetitionPeriodFactor;

						// Register this nth-transmission.
						Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduNumberOfRepetitionsLeft--;
					}
				}

			// The IDPU has NONE transmission mode.
				/* @req COM135 */
			} else {
				// Don't send!
			}

		}

		Irq_Restore(irq_state);

        /* Check notifications */
        confirmationStatus = GetTxConfirmationStatus(IPdu);
        SetTxConfirmationStatus(IPdu, FALSE);

        for (signalIndex = 0; confirmationStatus && (IPdu->ComIPduSignalRef[signalIndex] != NULL); signalIndex++) {
            signal = IPdu->ComIPduSignalRef[signalIndex];
            if ((signal->ComNotification != COM_NO_FUNCTION_CALLOUT) &&
                (ComNotificationCallouts[signal->ComNotification] != NULL) ) {
                //ComNotificationCallouts[signal->ComNotification](signal->ComHandleId,0,FALSE);
            }
        }
	}
}



