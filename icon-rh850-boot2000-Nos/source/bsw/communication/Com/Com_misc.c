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
#include <string.h>
#include <assert.h>

#include "Com_Arc_Types.h"
#include "Com.h"
#include "Com_Internal.h"
#include "Com_misc.h"
#include "debug.h"
#include "generic/Cpu.h"

//#include "standard.h"//Add

/* Declared in Com_Cfg.c */
extern const ComNotificationCalloutType ComNotificationCallouts[];

static void Com_ReadDataSegment(uint8_t *dest, const uint8_t *source, uint8_t destByteLength,
		Com_BitPositionType segmentStartBitOffset, uint8_t segmentBitLength, boolean signedOutput);

static void Com_WriteDataSegment(uint8_t *pdu, uint8_t *pduSignalMask, const uint8_t *signalDataPtr, uint8_t destByteLength,\
		Com_BitPositionType segmentStartBitOffset, uint8_t segmentBitLength);

void Com_CopySignalGroupDataFromShadowBufferToPdu(const Com_SignalIdType signalGroupId, boolean deferredBufferDestination, boolean *dataChanged) {

	// Get PDU
	const ComSignal_type * Signal = GET_Signal(signalGroupId);
	const ComIPdu_type *IPdu = GET_IPdu(Signal->ComIPduHandleId);
	Com_Arc_Signal_type * Arc_Signal = GET_ArcSignal(Signal->ComHandleId);
	uint8_t *pduDataPtr = 0;
    uint8_t *buf = (uint8_t *)Arc_Signal->Com_Arc_ShadowBuffer;
    uint8_t data = 0;
    int32_t i;
    
    *dataChanged = FALSE;
    
	
	if (deferredBufferDestination) {
		pduDataPtr = GET_ArcIPdu(Signal->ComIPduHandleId)->ComIPduDeferredDataPtr;
	} else {
		pduDataPtr = GET_ArcIPdu(Signal->ComIPduHandleId)->ComIPduDataPtr;
	}

	// Aligned opaque data -> straight copy with signalgroup mask

    for(i= 0; i < IPdu->ComIPduSize; i++){
        data = (~Signal->Com_Arc_ShadowBuffer_Mask[i] & *pduDataPtr) |
               (Signal->Com_Arc_ShadowBuffer_Mask[i] & *buf);
        if(*pduDataPtr != data) {
            *dataChanged = TRUE;
        }
        *pduDataPtr = data;
        buf++;
        pduDataPtr++;
    }

}


void Com_CopySignalGroupDataFromPduToShadowBuffer(const Com_SignalIdType signalGroupId) {

	// Get PDU
	const ComSignal_type * Signal = GET_Signal(signalGroupId);
	const ComIPdu_type *IPdu = GET_IPdu(Signal->ComIPduHandleId);
	uint8_t *buf = (uint8_t *)GET_ArcSignal(Signal->ComHandleId)->Com_Arc_ShadowBuffer;
	int32_t i;
	
	const uint8_t *pduDataPtr = 0;
	if (IPdu->ComIPduSignalProcessing == DEFERRED && IPdu->ComIPduDirection == RECEIVE) {
		pduDataPtr = GET_ArcIPdu(Signal->ComIPduHandleId)->ComIPduDeferredDataPtr;
	} else {
		pduDataPtr = GET_ArcIPdu(Signal->ComIPduHandleId)->ComIPduDataPtr;
	}

	// Aligned opaque data -> straight copy with signalgroup mask
	
	for(i= 0; i < IPdu->ComIPduSize; i++){
		*buf++ = Signal->Com_Arc_ShadowBuffer_Mask[i] & *pduDataPtr++;
	}
}

void Com_ReadSignalDataFromPduBuffer(
		const uint16_t  signalId,
		Com_SignalGroupIdType GroupSignalId,
		const boolean isGroupSignal,
		void         *signalData,
		const void   *pduBuffer) {

	Com_SignalType          signalType;
	ComSignalEndianess_type signalEndianess;
	uint8_t                   signalLength;
	Com_BitPositionType     bitPosition;
	uint8_t                   bitSize;
	uint8_t                   destSize ;

	uint8_t                  *signalDataBytes = (uint8_t *)signalData;
	uint8_t                   signalDataBytesArray[8];
	const uint8_t            *pduBufferBytes ;
	Com_BitPositionType     startBitOffset = 0;
	imask_t                 state;
	uint8_t                   i;
    const ComSignal_type   *Signal =  GET_Signal(signalId);
	const ComGroupSignal_type *GroupSignal = GET_GroupSignal(GroupSignalId);

	if (!isGroupSignal) {
		signalType      = Signal->ComSignalType;
		signalEndianess = Signal->ComSignalEndianess;
		signalLength    = Signal->ComBitSize / 8;
		bitPosition     = Signal->ComBitPosition;
		bitSize         = Signal->ComBitSize;
	} else {
		/* Groupsignal, we actually read from shadowbuffer */
		signalType      = GroupSignal->ComSignalType;
		signalEndianess = GroupSignal->ComSignalEndianess;
		signalLength    = GroupSignal->ComBitSize / 8;
		bitPosition     = GroupSignal->ComBitPosition;
		bitSize         = GroupSignal->ComBitSize;
	}

	destSize = SignalTypeToSize(signalType, signalLength);

	// Pointer to a byte of the source and dest respectively.
	pduBufferBytes = (const uint8_t *)pduBuffer + (bitPosition/8);
	Irq_Save(state);

	if (signalEndianess == COM_OPAQUE || signalType == SIGNAL_UINT8_N) {
		// Aligned opaque data -> straight copy
		/* @req COM472 */
		memcpy(signalDataBytes, pduBufferBytes, destSize);

	} else {
		// Unaligned data and/or endianness conversion

		if (signalEndianess == COM_LITTLE_ENDIAN) {
			// Swap source bytes before reading
			// IMPROVEMENT: Must adapt to larger PDUs!
			uint8_t pduBufferBytes_swap[8];
			for (i = 0; i < 8; ++i) {
				pduBufferBytes_swap[i] = pduBufferBytes[7 - i];
			}
			startBitOffset = intelBitNrToPduOffset(bitPosition%8, bitSize, 64);
			Com_ReadDataSegment(
					signalDataBytesArray, pduBufferBytes_swap, destSize,
					startBitOffset, bitSize,
					SignalTypeSignedness(signalType));
		} else {
			startBitOffset = motorolaBitNrToPduOffset(bitPosition%8);
			Com_ReadDataSegment(
					signalDataBytesArray, pduBufferBytes, destSize,
					startBitOffset, bitSize,
					SignalTypeSignedness(signalType));
		}

		if (Com_SystemEndianness == COM_BIG_ENDIAN) {
			for (i = 0; i < destSize; i++) {  // Straight copy
				signalDataBytes[i] = signalDataBytesArray[i];
			}

		} else if (Com_SystemEndianness == COM_LITTLE_ENDIAN) {
			// Data copy algorithm creates big-endian output data so we swap
			for (i = 0; i < destSize; i++) {
				signalDataBytes[(destSize - 1) - i] = signalDataBytesArray[i];
			}
		}
	}
	Irq_Restore(state);
}


void Com_WriteSignalDataToPdu(
			const Com_SignalIdType signalId,
			const void *signalData,
			boolean * dataChanged) {

	// Get PDU
	const ComSignal_type *Signal     = GET_Signal(signalId);
	const Com_Arc_IPdu_type   *Arc_IPdu       = GET_ArcIPdu(Signal->ComIPduHandleId);


	// Get data
	Com_WriteSignalDataToPduBuffer(
			signalId,
			FALSE,
			signalData,
			Arc_IPdu->ComIPduDataPtr,
			dataChanged);
}

void Com_WriteSignalDataToPduBuffer(
			const uint16_t signalId,
			const boolean isGroupSignal,
			const void *signalData,
			void *pduBuffer,
			boolean *dataChanged) {
	// IMPROVEMENT: Implement writing little-endian signals
	/* @req COM221 */
	/* @req COM353 */
	Com_SignalType signalType;
	uint8_t signalLength;
	Com_BitPositionType bitPosition;
	uint8_t bitSize;
	ComSignalEndianess_type endian;
	uint8_t signalBufferSize ;
	uint8_t pduSignalMask[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

	uint8_t signalDataBytesArray[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	const uint8_t *signalDataBytes = (const uint8_t *)signalData;
	imask_t irq_state;
    uint8_t *pduBufferBytes ;
    uint8_t i;
	const ComSignal_type * Signal =  GET_Signal(signalId);
    const ComGroupSignal_type *GroupSignal = GET_GroupSignal(signalId);
    //uint8_t *pduBufferBytes ;
    uint8_t startFromPduByte ;
	
	*dataChanged = FALSE;
	if (!isGroupSignal) {
		
		signalType = Signal->ComSignalType;
		signalLength = Signal->ComBitSize / 8;
		bitPosition = Signal->ComBitPosition;
		bitSize = Signal->ComBitSize;
		endian = Signal->ComSignalEndianess;
	} else {
		/* Groupsignal, we actually write to shadowbuffer */
		
		signalType = GroupSignal->ComSignalType;
		signalLength = GroupSignal->ComBitSize / 8;
		bitPosition = GroupSignal->ComBitPosition;
		bitSize = GroupSignal->ComBitSize;
		endian = GroupSignal->ComSignalEndianess;
	}

	signalBufferSize = SignalTypeToSize(signalType, signalLength);


	Irq_Save(irq_state);
	if (endian == COM_OPAQUE || signalType == SIGNAL_UINT8_N) {
		//assert(bitPosition % 8 == 0);
		//assert(bitSize % 8 == 0);
		/* @req COM472 */
		pduBufferBytes = (uint8_t *)pduBuffer;
		startFromPduByte = bitPosition / 8;
		//if( 0 != memcmp(pduBufferBytes + startFromPduByte, signalDataBytes, signalLength) )//no memcmp data when write data to can
		{
		    *dataChanged = TRUE;
		}
		memcpy(pduBufferBytes + startFromPduByte, signalDataBytes, signalLength);
	} else {
		if (Com_SystemEndianness == COM_BIG_ENDIAN) {
			// Straight copy
			for (i = 0; i < signalBufferSize; i++) {
				signalDataBytesArray[i] = signalDataBytes[i];
			}

		} else if (Com_SystemEndianness == COM_LITTLE_ENDIAN) {
			// Data copy algorithm assumes big-endian input data so we swap
			for (i = 0; i < signalBufferSize; i++) {
				signalDataBytesArray[(signalBufferSize - 1) - i] = signalDataBytes[i];
			}
		} else {
			//assert(0);
		}
        if (endian == COM_BIG_ENDIAN) {
            Com_BitPositionType startBitOffset = motorolaBitNrToPduOffset(bitPosition%8);
            uint8_t pduBufferBytesStraight[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

			Com_WriteDataSegment(pduBufferBytesStraight, pduSignalMask,
					signalDataBytesArray, signalBufferSize, startBitOffset, bitSize);

            // Straight copy into real pdu buffer (with mutex)
            pduBufferBytes = ((uint8_t *)pduBuffer)+(bitPosition/8);
            
            for (i = 0; i < 8; i++) {
                if( pduBufferBytesStraight[i] != (pduBufferBytes[i]  & pduSignalMask[i]) ) {
                    *dataChanged = TRUE;
                }
                pduBufferBytes[ i ]  &=        ~( pduSignalMask[ i ] );
                pduBufferBytes[ i ]  |=  pduBufferBytesStraight[ i ];
            }

        } else {
            uint8_t startBitOffset = intelBitNrToPduOffset(bitPosition%8, bitSize, 64);
            uint8_t pduBufferBytesSwapped[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

            Com_WriteDataSegment(pduBufferBytesSwapped, pduSignalMask,
                    signalDataBytesArray, signalBufferSize, startBitOffset, bitSize);

            // Swapped copy into real pdu buffer (with mutex)
            pduBufferBytes = ((uint8_t *)pduBuffer)+(bitPosition/8);
            
            // actually it is only necessary to iterate through the bytes that are written.
            for (i = 0; i < 8; i++) {
                if( pduBufferBytesSwapped[(8 - 1) - i] != (pduBufferBytes[i] & (pduSignalMask[(8 - 1) - i])) ) {
                    *dataChanged = TRUE;
                }
                pduBufferBytes[ i ]  &=       ~( pduSignalMask[ (8 - 1) - i] );
                pduBufferBytes[ i ]  |=  pduBufferBytesSwapped[ (8 - 1) - i ];
            }
        }
	}
	Irq_Restore(irq_state);
}


/*
 * Read an arbitrary signal segment from buffer.
 * dest:                   pointer to start of destination buffer
 * source:                 pointer to start of source buffer
 * destByteLength:         size of destination buffer in bytes
 * segmentStartBitOffset:  bit offset to signal segment (from first bit in *source data)
 * segmentBitLength:       length in bits of the signal segment to be read
 *
 * Example:
 *    Source data: (ABC... = signal segment)
 *    | -----ABC | DEFGHIJK | LMNOPQ-- |
 *         B0         B1         B2
 *  Parameters:
 *    dest:                  pointer to 32 bit space (needs to be at least 3 bytes to keep the 17 signal bits)
 *    destByteLength:          4
 *    source:                *B0
 *    segmentStartBitOffset:   5
 *    segmentBitLength:       17
 *
 *  Result:
 *    Destination:
 *    | -------- | -------A | BCDEFGHI | JKLMNOPQ |
 *
 */
static void Com_ReadDataSegment(uint8_t *dest, const uint8_t *source, uint8_t destByteLength,
		Com_BitPositionType segmentStartBitOffset, uint8_t segmentBitLength, boolean signedOutput) {

	Com_BitPositionType sourceEndBitOffset = segmentStartBitOffset + segmentBitLength - 1;
	Com_BitPositionType sourceStartByte = segmentStartBitOffset / 8;
	uint8_t sourceEndByte = (sourceEndBitOffset) / 8;
	uint8_t sourceByteLength = sourceEndByte - sourceStartByte;

	uint8_t segmentStartBitOffsetInsideByte = segmentStartBitOffset % 8;
	uint16_t sourceStartByteMask;

	uint8_t sourceAlignmentShift = 7 - (sourceEndBitOffset % 8);
	uint8_t segmentByteLength = 1 + (segmentBitLength - 1) / 8;
	uint8_t sourceByteNr = 0;
	uint8_t destByteNr = 0;

	uint16_t shiftReg = 0;

	boolean negative;
	/* @req COM008 */
	if ( signedOutput && (*(source + sourceStartByte) & (0x80u >> segmentStartBitOffsetInsideByte)) ) {
		negative = TRUE;
		sourceStartByteMask = (0xFF00u >> segmentStartBitOffsetInsideByte);
		memset(dest, 0xFF, destByteLength);
	} else {
		negative = FALSE;
		sourceStartByteMask = (0x00FFu >> segmentStartBitOffsetInsideByte);
		memset(dest, 0x00u, destByteLength);
	}

	// setup to point to end (LSB) of buffers
	source += sourceEndByte;
	dest += destByteLength - 1;

	if (negative) {
	// compiles and writes one destination byte on each iteration
		do {
			shiftReg = *(source - sourceByteNr) | 0xFF00u;		// read source byte (already matching "byte space")
			if (sourceByteNr == sourceByteLength) {				// if we are on the last source byte..
				shiftReg |= sourceStartByteMask;			// ..we need to mask out stuff we don't want
			}
			shiftReg >>= sourceAlignmentShift;					// shift down to align
			*(dest - destByteNr) &= shiftReg | 0xFF00u;		// write into destination byte

			sourceByteNr++;										// move to next source byte
			if ( (sourceAlignmentShift != 0)						// do we have more bits for current dest. byte in this source byte?
					&& (sourceByteNr <= sourceByteLength) ) {
				shiftReg = *(source - sourceByteNr) | 0xFF00u;	// read next source byte
				if (sourceByteNr == sourceByteLength) {			// if we are on the last source byte..
					shiftReg |= sourceStartByteMask;		// ..we need to mask out stuff we don't want
				}
				shiftReg = (uint16_t)~(shiftReg);						// shifting inverted to shift in 1:s
				shiftReg <<= 8;								// shift up (to match destination "byte space")
				shiftReg = (uint16_t)~shiftReg;
				shiftReg >>= sourceAlignmentShift;				// shift down to align
				*(dest - destByteNr) &= shiftReg | 0xFF00u;	// write into destination byte
			}
			destByteNr++;
		} while (destByteNr < segmentByteLength);
	} else { // positive
		do {
			shiftReg = *(source - sourceByteNr) & 0x00FFu;		// read source byte (already matching "byte space")
			if (sourceByteNr == sourceByteLength) {				// if we are on the last source byte..
				shiftReg &= sourceStartByteMask;			// ..we need to mask out stuff we don't want
			}
			shiftReg >>= sourceAlignmentShift;					// shift down to align
			*(dest - destByteNr) |= shiftReg & 0x00FFu;		// write into destination byte

			sourceByteNr++;										// move to next source byte
			if (sourceAlignmentShift != 0						// do we have more bits for current dest. byte in this source byte?
					&& sourceByteNr <= sourceByteLength) {
				shiftReg = *(source - sourceByteNr) & 0x00FFu;	// read next source byte
				if (sourceByteNr == sourceByteLength) {			// if we are on the last source byte..
					shiftReg &= sourceStartByteMask;		// ..we need to mask out stuff we don't want
				}
				shiftReg <<= 8;								// shift up (to match destination "byte space")
				shiftReg >>= sourceAlignmentShift;				// shift down to align
				*(dest - destByteNr) |= shiftReg & 0x00FFu;	// write into destination byte
			}
			destByteNr++;
		} while (destByteNr < segmentByteLength);
	}
}

/*
 * Copies the <segmentBitLength> least significant bits from <signal> into <pdu>.
 * The bit segment is placed in <pdu> so that the most significant bit ends up
 * at <segmentStartBitOffset> from the msb of <pdu>.
 * <pduSignalMask> is cleared and written to contain a mask with 1�s where the
 * signal is located in the <pdu>.
 */
void Com_WriteDataSegment(uint8_t *pdu, uint8_t *pduSignalMask, const uint8_t *signalDataPtr, uint8_t destByteLength,
		Com_BitPositionType segmentStartBitOffset, uint8_t segmentBitLength) {
	Com_BitPositionType pduEndBitOffset = segmentStartBitOffset + segmentBitLength - 1;
	uint8_t pduStartByte = segmentStartBitOffset / 8;
	uint8_t pduEndByte = (pduEndBitOffset) / 8;
	uint8_t pduByteLength = pduEndByte - pduStartByte;

	uint8_t segmentStartBitOffsetInsideByte = segmentStartBitOffset % 8;
	uint8_t pduStartByteMask = (0xFFu >> segmentStartBitOffsetInsideByte);

	uint8_t pduAlignmentShift = 7 - (pduEndBitOffset % 8);
	uint8_t segmentByteLength = 1 + (segmentBitLength - 1) / 8;
	uint8_t pduByteNr = 0;
	uint8_t signalByteNr = 0;

	uint16_t shiftReg = 0;
	uint16_t clearReg = 0;

	// clear pduSignalMask all the way from 0
	memset(pduSignalMask, 0x00, pduEndByte);

	// setup to point to end (LSB) of buffers
	pdu           += pduEndByte;
	pduSignalMask += pduEndByte;

	signalDataPtr += destByteLength - 1;

	// splits and writes one source byte on each iteration
	do {
		shiftReg = *(signalDataPtr - signalByteNr) & 0x00FFu;
		clearReg = 0x00FF;
		//lint -save -e701 -e734 //PC-Lint Wrong interpretation of MISRA rule 10.5.
		shiftReg <<= pduAlignmentShift;
		clearReg <<= pduAlignmentShift;
		//lint -restore
		if (pduByteNr == pduByteLength) {
			shiftReg &= pduStartByteMask;
			clearReg &= pduStartByteMask;
		}
		*(pdu           - pduByteNr) &= (uint16_t)~(clearReg & 0x00FFu);
		*(pduSignalMask - pduByteNr) |= (uint16_t) (clearReg & 0x00FFu);
		*(pdu           - pduByteNr) |= shiftReg & 0x00FFu;

		pduByteNr++;
		if ( (pduAlignmentShift != 0)
				&& (pduByteNr <= pduByteLength) ) {
			shiftReg = *(signalDataPtr - signalByteNr) & 0x00FFu;
			clearReg = 0x00FF;
			//lint -save -e701 -e734 //PC-Lint Wrong interpretation of MISRA rule 10.5.
			shiftReg <<= pduAlignmentShift;
			clearReg <<= pduAlignmentShift;
			shiftReg >>= 8;
			clearReg >>= 8;
			//lint -restore
			if (pduByteNr == pduByteLength) {
				shiftReg &= pduStartByteMask;
				clearReg &= pduStartByteMask;
			}
			*(pdu           - pduByteNr) &= (uint16_t)~(clearReg & 0x00FFu);
			*(pduSignalMask - pduByteNr) |= (uint16_t) (clearReg & 0x00FFu);
			*(pdu           - pduByteNr) |= shiftReg & 0x00FFu;
		}
		signalByteNr++;
	} while (signalByteNr < segmentByteLength);
}

/*
 * Converts from motorola CAN bit nr to PDU bit offset
 *
 *             motorolaBitNr:  7  6  5  4  3  2  1  0 15 14 13 12 ...
 *  motorolaBitNrToPduOffset:  0  1  2  3  4  5  6  7  8  9 10 11 ...
 */
Com_BitPositionType motorolaBitNrToPduOffset (Com_BitPositionType motorolaBitNr) {
	uint8_t byte = motorolaBitNr / 8;
	Com_BitPositionType offsetToByteStart = (Com_BitPositionType) (byte * 8u);
	Com_BitPositionType offsetInsideByte = motorolaBitNr % 8;
	return (Com_BitPositionType) (offsetToByteStart + (7u - offsetInsideByte));
}

/*
 * Converts from intel CAN bit nr to PDU bit offset
 *
 *                        pduNumBits: 40
 *  intelBitNr (after PDU byte-swap): 39 38 37 36 35 34 33 32 31 ...  3  2  1  0
 *             intelBitNrToPduOffset:  0  1  2  3  4  5  6  7  8 ... 36 37 38 39
 */
Com_BitPositionType intelBitNrToPduOffset (Com_BitPositionType intelBitNr, Com_BitPositionType segmentBitLength, Com_BitPositionType pduBitLength) {
	return pduBitLength - (intelBitNr + segmentBitLength);
}

void Com_RxProcessSignals(const ComIPdu_type *IPdu,Com_Arc_IPdu_type *Arc_IPdu) {
	/* !req COM053 */
	/* @req COM055 */
	/* !req COM396 */ /* Neither invalidation nor filtering supported */
	/* !req COM352 */
	uint8_t i;//,j;
	const ComSignal_type *comSignal;
	Com_Arc_Signal_type * Arc_Signal;
	
	for (i = 0; IPdu->ComIPduSignalRef[i] != NULL; i++) {
		comSignal = IPdu->ComIPduSignalRef[i];
		Arc_Signal = GET_ArcSignal(comSignal->ComHandleId);

		// If this signal uses an update bit, then it is only considered if this bit is set.
		/* @req COM324 */
		/* @req COM067 */
		if ( (!comSignal->ComSignalArcUseUpdateBit) ||
			( (comSignal->ComSignalArcUseUpdateBit) && (TESTBIT(Arc_IPdu->ComIPduDataPtr, comSignal->ComUpdateBitPosition)) ) ) {

			if (comSignal->ComTimeoutFactor > 0) { // If reception deadline monitoring is used.
				// Reset the deadline monitoring timer.
				/* @req COM715 */
				Arc_Signal->Com_Arc_DeadlineCounter = comSignal->ComTimeoutFactor;
			}

			// Check the signal processing mode.
			if (IPdu->ComIPduSignalProcessing == IMMEDIATE) {
				// If signal processing mode is IMMEDIATE, notify the signal callback.
				/* @req COM300 */
				/* @req COM301 */
#if 0
				if ((IPdu->ComIPduSignalRef[i]->ComNotification != COM_NO_FUNCTION_CALLOUT) &&
					(ComNotificationCallouts[IPdu->ComIPduSignalRef[i]->ComNotification] != NULL) ) {
					if (IPdu->ComIPduSignalRef[i]->ComGroupSignal[i]!=NULL) {
					        ComNotificationCallouts[IPdu->ComIPduSignalRef[i]->ComNotification](Arc_IPdu->ComIPduDataPtr);
					}else {
					    ComNotificationCallouts[IPdu->ComIPduSignalRef[i]->ComNotification](Arc_IPdu->ComIPduDataPtr);
					}
				}
#endif
			} else {
				// Signal processing mode is DEFERRED, mark the signal as updated.
				Arc_Signal->ComSignalUpdated = TRUE;
			}

		} else {
			DEBUG(DEBUG_LOW, "Com_RxIndication: Ignored signal %d of I-PD %d since its update bit was not set\n", comSignal->ComHandleId, ComRxPduId);
		}
	}
}
void UnlockTpBuffer(PduIdType PduId) {
	Com_BufferPduState[PduId].locked = false;
	Com_BufferPduState[PduId].currentPosition = 0;
}

boolean isPduBufferLocked(PduIdType id) {
	imask_t state;
	boolean bufferLocked = Com_BufferPduState[id].locked;
	
	Irq_Save(state);

	Irq_Restore(state);
	if (bufferLocked) {
		return true;
	} else {
		return false;
	}
}
PduIdType getPduId(const ComIPdu_type* IPdu) {
	return (PduIdType)(IPdu - (ComConfig->ComIPdu));
}

void Com_Internal_UpdateShadowSignal(Com_SignalIdType SignalId, const void *SignalDataPtr) {
	Com_Arc_GroupSignal_type *Arc_GroupSignal = GET_ArcGroupSignal(SignalId);
	/* @req COM632 */
	/* @req COM633 */ /* Sign extension? */
	boolean dataChanged = FALSE;
	Com_WriteSignalDataToPduBuffer(SignalId, TRUE, SignalDataPtr, (void *)Arc_GroupSignal->Com_Arc_ShadowBuffer, &dataChanged);
}

/* Helpers for getting and setting that a TX PDU confirmation status
 * These function uses the ComSignalUpdated for the first signal within the Pdu. The
 * ComSignalUpdated isn't used for anything else in TxSignals and it is mainly used
 * in Rx signals.
 * The reason is to save RAM.
 */

void SetTxConfirmationStatus(const ComIPdu_type *IPdu, boolean value) {

    const ComSignal_type *signal = IPdu->ComIPduSignalRef[0];

    if (signal != NULL) {
        Com_Arc_Signal_type * Arc_Signal = GET_ArcSignal(signal->ComHandleId);
        Arc_Signal->ComSignalUpdated = value;
    }
}

boolean GetTxConfirmationStatus(const ComIPdu_type *IPdu) {
    const ComSignal_type *signal = IPdu->ComIPduSignalRef[0];
    Com_Arc_Signal_type * Arc_Signal = GET_ArcSignal(signal->ComHandleId);
    if (IPdu == NULL) {
        return FALSE;
    }



    if (signal == NULL) {
        return FALSE;
    }

 
    return Arc_Signal->ComSignalUpdated;
}


