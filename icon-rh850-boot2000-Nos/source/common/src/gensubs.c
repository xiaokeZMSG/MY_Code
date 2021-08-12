/*
 * Copyright (c) 20109-2020, SAIC  Team
 * file: gensubs.c
 *
 * Change Logs:
 * Date           Author          VER  Notes
 * 2020-02-25    maguangdong      0.1  First edition
 */


/*********************************************************************/
/* Include files                                                     */
/*********************************************************************/
#include <string.h>
#include <stdio.h>
#include <gensubs.h>
//#include "osal.h"
                                                                       
/*********************************************************************/
/* File level pragmas                                                */
/*********************************************************************/
                                                                       
/*********************************************************************/
/* Constant and Macro Definitions using #define                      */
/*********************************************************************/
#define  CHKSUM_OFFSET     0x5555
#define  CHECKSUM_SIZE     2                             /*define number of bytes in a checksum*/
#define  UPDATE_CHECKSUM   true                          /* update (change) checksum*/
#define  VERIFY_CHECKSUM   false                         /* do not modifiy checksum*/
#define  NEW_CHECKSUM      true                          /* Start a new checksum (not partial sum)*/
#define  RESET_CHECKSUM    true                          /* Start a new checksum (not partial sum)*/
#define  CONTINUE_CHECKSUM false                         /* Add to previous sum  (partial sum)*/

/*********************************************************************/
/* Function Prototypes for Private Functions with File Level Scope   */
/*********************************************************************/
                                                                       
/*********************************************************************/
/* Enumerations and Structures and Typedefs                          */
/*********************************************************************/
                                                                       
/*********************************************************************/
/* Global and Const Variable Defining Definitions / Initializations  */
/*********************************************************************/
                                                                       
/*********************************************************************/
/* Static Variables and Const Variables With File Level Scope        */
/*********************************************************************/
static const uint8_t reverse_bits_TBL[16] =
{
   0x00,
   0x08,
   0x04,
   0x0C,
   0x02,
   0x0A,
   0x06,
   0x0E,
   0x01,
   0x09,
   0x05,
   0x0D,
   0x03,
   0x0B,
   0x07,
   0x0F,
};

/*********************************************************************/
/* ROM Const Variables With File Level Scope                         */
/*********************************************************************/                                                                                                                                              
const uint8_t bits[8]     = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
const uint8_t not_bits[8] = {0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe};                                                                       
                                                                       
/*********************************************************************/
/* Function Definitions                                              */
/*********************************************************************/
/**********************************************************************
 * Function      : Assign_Bit
 * Description   : to set or to clear a bit given an address and a bit offset - used to implement a packed array of booleans
 * Parameters    : addr: address of object in which to set the bit
                 : bitnum: the bit offset, counted from the lowest address, MSB
                 : num_bits: size of bit array
                 : Set_or_Clear: 0--clear; 1--set
                 : RangeCheck: 0--no range check ; 1-- range check
 * Returns       : 
 * Description   : 
 *********************************************************************/
void Assign_Bit( void *addr, uint32_t bitnum, uint32_t num_bits, bool Set_or_Clear, bool RangeCheck)
{
   uint8_t *bit_ptr = (uint8_t *)addr;

   if (!RangeCheck || (bitnum < (num_bits + 1) ))
   {
	   if (Set_or_Clear)
	   {
	      *(bit_ptr + (bitnum / (8*sizeof(uint8_t)))) |= bits[bitnum % (8*sizeof(uint8_t))];
	   }
	   else
	   {
	      *(bit_ptr + (bitnum / (8*sizeof(uint8_t)))) &= not_bits[bitnum % (8*sizeof(uint8_t))];
	   }
   }
}

/**********************************************************************
 * Purpose:
 *   to read a bit given an address and a bit offset - used to implement
 *   a packed array of booleans
 *
 * Parameters:
 *   addr: address of object from which to read the bit
 *   bit: the bit offset, counted from the lowest address, MSB
 *
 *   returns: 1 if bit set, 0 if bit clear
 **********************************************************************/
int32_t Read_Bit_Subr( void *addr, uint32_t bitnum )
{
   uint8_t *bit_ptr = (uint8_t *)addr;

  return (0 != (*(bit_ptr + (bitnum / (8*sizeof(uint8_t)))) & bits[bitnum % (8*sizeof(uint8_t))]));
}

/**********************************************************************
 * Purpose: To find and clear the first active bit from an array
 *
 * Parameters:
 * array - the address of the array
 * bit_size - the size of the array in bits (not bytes)
 * consume_bit - if true the bit is cleared
 *
 * return: -1 if no bit is set, otherwise the offset, in bits, from the MSB
 *         of the lowest addressed byte in the array
 *          CLEARS the BIT
 **********************************************************************/
int32_t Find_First_Set_Bit(void *addr, size_t bit_size, bool consume_bit)
{
   uint8_t *bit_ptr = (uint8_t *)addr;
   int32_t byte_index;
   //uint_fast8_t bit_index;
   uint8_t bit_index;
   int32_t ret = -1;
   for (byte_index = 0; (byte_index * 8) < bit_size; byte_index++)
   {
      if (0 != *bit_ptr)                                       /* is byte non-zero?*/
      {
         for   (bit_index = 0; bit_index < 8; bit_index++)     /* search for bit within byte*/
         {
            if (0 != (bits[bit_index] & *bit_ptr))             /* find it?*/
            {
               if (consume_bit)
               {
                  *bit_ptr &= not_bits[bit_index];             /* clear bit*/
               }
               if ( ((byte_index * 8) + bit_index) < bit_size)
               {
                  ret = ((byte_index * 8) + bit_index);
               }
               else
               {
                  ret = (-1);                               /* bit was past last valid bit in bit_ptr*/
               }
            }
         }
      }
      bit_ptr++;
   } 
#if 0
   return(-1);                                              /* no bits set*/
#endif
   return ret;
}

/**********************************************************************
 * Purpose: To find next set bit in direction specified
 *
 * Parameters:
 * addr - the address of the array
 * bit_size - the size of the array in bits (not bytes)
 * starting_bit - bit position to start from (does not look at starting position)
 * up - 1 = look in up direction
 *
 * return: -1 if no bit is set, otherwise the offset, in bits, from the MSB
 *         of the lowest addressed byte in the array
 *
 **********************************************************************/
int32_t Find_Next_Bit_with_Wrap(void *addr, size_t bit_size, int32_t current_bit, bool up)
{
   uint8_t *bit_ptr = (uint8_t *)addr;
   int32_t    bits_tried = 0;
   int32_t    increment = (up ? 1 : -1);
   int32_t ret;
   do
   {
      current_bit += increment;

      if (current_bit < 0)
      {
         current_bit = bit_size - 1;
      }
      else if (current_bit >= bit_size)
      {
         current_bit = 0;
      }

      bits_tried++;

   } while ((0 == (*(bit_ptr + ((unsigned int)current_bit / (8*sizeof(uint8_t)))) &
                   bits[(unsigned int)current_bit % (8*sizeof(uint8_t))])) &&
            (bits_tried < bit_size));

   if (bits_tried >= bit_size)
   {
      ret = (-1);                                              /*no bits set*/
   }
   else
   {
      ret = (current_bit);
   }
   return ret;
}

/**********************************************************************
 * Function      : Sum_Bytes
 * Description   : Calculation the checksum from (Strt_addr),(size) of number bytes
 * Parameters    : 
 * Returns       : 
 * Description   : 
 *********************************************************************/
#if 0
static uint16_t Sum_Bytes(const void *Strt_Addr, size_t size)
{
    const uint8_t *ptr = ( uint8_t *) Strt_Addr;   /* pointer to start addr.*/
   uint16_t sum = 0;
   
   for (; (0 != size); size--)
   {
      sum += *ptr++;          /* add the bytes*/
   }
   return(sum);   
}/*Remove compiler warning about unused function*/
#endif
/**********************************************************************
 * Function      : CS_Write
 * Description   : writes 1 byte to checksum variable
 * Parameters    : dest     adddress of old data
                 : source   address  in new data
                 : count    number of bytes changing
                 : checksum address of checksum 
 * Returns       : 
 * Description   : 
 *********************************************************************/
void *CS_Write(void *dest, const void *source, size_t count, uint16_t *checksum)
{
   uint8_t *dptr = (uint8_t *) dest;                  /* pointer to dest addr*/
   const  uint8_t*sptr = ( uint8_t *) source;   /* pointer to source addr*/

   for (; (0 != count); count--)
   {
      *checksum  -= *dptr;                      /* add the delta to the checksum*/
      *checksum  += *sptr;
      *dptr++ = *sptr++;                        /* copy byte*/
   }
   return(dest);
}


/***********************************************************************
 *    Function: limit_check
 *
 *  Parameters: value, min, and max
 *
 *     Returns: Limit checked value
 *
 * Description: Forces value to within min and max inclusive 
 *
 ***********************************************************************/
int32_t Limit_Check (int32_t value, int32_t min, int32_t max)
{
   if (value < min)
   {
      value = min;
   }
   else if (value > max)
   {
      value = max;
   }
   return(value);
}

#ifndef   ASSEMBLY_PROJECT_IS
/***********************************************************************
 *    Function: Wrap_Check
 *
 *  Parameters: value, min, and max
 *
 *     Returns: wrapped value
 *
 * Description: wraps a value if out of limits (i.e > max goes to min)
 *
 ***********************************************************************/
int32_t Wrap_Check(int32_t value, int32_t min, int32_t max)
{
   if (min > value)
   {
      value = max;
   }
   else if (max < value)
   {
      value = min;
   }
   return(value);
}

/**********************************************************************
 *    Function: BCD_To_Hex
 *
 *  Parameters: BCD_Value   BCD value to be convereed to hex
 *
 *     Returns: Equivalent value in hexidecimal format
 *
 * Description: This routine converts a received value in BCD and
 *              converts it to a Hexidecimal value.
 *              Hex_value = (BCD_value & F0h) * ?
 *
 **********************************************************************/

uint8_t BCD_To_Hex (uint8_t BCD_Value)
{
   return(((BCD_Value / 16) * 10) + (BCD_Value % 16));
}
#endif   /*ASSEMBLY_PROJECT_IS*/

/**********************************************************************
 *    Function: Hex_To_BCD
 *
 *  Parameters: HexValue    Hexidecimal value to be converted to BCD
 *
 *     Returns: Equivalent value in BCD
 *
 * Description: This routine converts a received value in Hexidecimal
 *              and converts it to a BCD value.  If the value is too
 *              large a value of 99h is returned
 *
 *              BCD_Value = (HexValue / 10) * 10h  +  remainder
 *                          interger division    int modulo division
 **********************************************************************/

uint8_t Hex_To_BCD (uint8_t HexValue)
{
   uint8_t ret;
   if (99 < HexValue)     /* overflow condition true if HexValue > 99*/
   {
       ret = (0x99);
   }
   else
   {
       ret = (((HexValue / 10) * 0x10) + (HexValue % 10));       
   }
   return ret;
}

/**********************************************************************
 *    Function: Hex_To_WBCD
 *
 *  Parameters: HexValue    Hexidecimal value to be converted to BCD
 *
 *     Returns: Equivalent value in packed BCD (0x000 .. 0x0255)
 *
 * Description: This routine converts a received value in Hexidecimal
 *              and converts it to a word BCD value.
 **********************************************************************/
uint16_t Hex_To_WBCD (uint8_t HexValue)
{
   return(  ((HexValue / 100) * 0x100) +
           (((HexValue % 100) / 10) * 0x10) +
             (HexValue % 10));
}

/**********************************************************************
 *    Function: WHEX_To_WBCD
 *
 *  Parameters: 16 bit HexValue    Hexidecimal value to be converted to BCD
 *
 *     Returns: Equivalent value in packed BCD
 *
 * Description: This routine converts a 16 bit value in Hexidecimal
 *              to a 16 bit BCD value.
 **********************************************************************/
uint16_t WHEX_To_WBCD (uint16_t HexValue)
{
   uint16_t ret;
   if (9999 < HexValue)
   {
       ret = (0x9999);  /* overflow condition true if HexValue > 9999*/
   }
   else
   {
       ret = ( (((HexValue % 10000) / 1000) * 0x1000) + 
               (((HexValue % 1000) / 100) * 0x100) +
               (((HexValue % 100) / 10) * 0x10) +
                 (HexValue % 10));
   }
   return ret;
}

#ifndef   ASSEMBLY_PROJECT_IS
/**********************************************************************
 *    Function: WBCD_To_Hex
 *
 *  Parameters: Word BCD value (000 - 255)
 *
 *     Returns: Equivalent value in hexidecimal format (1 byte)
 *
 * Description: This routine converts a received word length BCD 
 *              value to a hex value (up to 255).
 **********************************************************************/
uint8_t WBCD_To_Hex (uint16_t WBCD_value)
{
   uint8_t ret;
   if (0x255 < WBCD_value)
   {
       ret = (0xFF); /* overflow condition true if WBCD_value > 255*/
   }
   else
   {
       ret = ((uint8_t) ((WBCD_value & 0x000F) + 
                        ((WBCD_value & 0x00F0) >> 4) * 10 +
                        ((WBCD_value & 0x0F00) >> 8) * 100) );
   }
   return ret;
}

/**********************************************************************
 *    Function: WBCD_To_WHEX
 *
 *  Parameters: Word BCD value (0000 - 9999)
 *
 *     Returns: Equivalent value in hexidecimal format (2 byte)
 *
 * Description: This routine converts a received word length BCD 
 *              value to a hex value (up to 9999).
 **********************************************************************/
uint16_t WBCD_To_WHEX (uint16_t WBCD_value)
{
   return(  (WBCD_value & 0x000F) 
         + ((WBCD_value & 0x00F0) >>  4) * 10
         + ((WBCD_value & 0x0F00) >>  8) * 100
         + ((WBCD_value & 0xF000) >> 12) * 1000);
}

/**********************************************************************
 *    Function: Is_BCD
 *
 *  Parameters: Potential_BCD_Value   BCD value to be convereed to hex
 *
 *     Returns: True if BCD, false if not BCD
 *
 * Description: This routine tests both nibbles to see if the value ia a
 *              valid BCD value.
 *
 **********************************************************************/

int32_t Is_BCD(uint8_t Potential_BCD_Value)
{
   return( (Potential_BCD_Value <= 0x99) &&           /* valid range 0x00 -- 0x99*/
           ((Potential_BCD_Value & 0x0F) <= 0x09));   /* check lower nibble <= 9*/
}

/**********************************************************************
 *    Function: BCD_increment
 *
 *  Parameters: BCD_value:   BCD value to be incremented
 *
 *     Returns: BCD value incremented by one if valid BCD received.
 *              0xFF if invalid BCD received.
 *
 * Description: This routine increments a received value in BCD and
 *              returns the incremented value if valid, otherwise 0xFF
 *
 **********************************************************************/

uint8_t BCD_increment(uint8_t BCD_value)
{
   if (Is_BCD(BCD_value))                    /* verify valid BCD value*/
   {
      if (BCD_value == 0x99)                 /* test for rollover case */
      {
         BCD_value = 0x00;                   /* correct for rollover case*/
      }
      else                                   /*is not rollover case*/
      {
         if ((BCD_value & 0x0F) == 0x09)     /* test for last digit = 9*/
         {
            BCD_value += 0x07;               /* add 7 for next valid BCD*/
         }
         else                                /* last digit != 9 */
         {
            BCD_value++;                     /* regular increment*/
         }
      }
   }
   else                                      /* invalid BCD*/
   {
      BCD_value = 0x99;                      /* set value to max for return*/
   }
   return(BCD_value);                        /* return inc'd BCD value*/
}

/**********************************************************************
 *    Function: BCD_decrement
 *
 *  Parameters: BCD_value:   BCD value to be decremented
 *
 *     Returns: BCD value decremented by one if valid BCD received.
 *              0xFF if invalid BCD received.
 *
 * Description: This routine decrements a received value in BCD and
 *              returns the decremented value if valid, otherwise 0xFF
 *
 **********************************************************************/

uint8_t BCD_decrement(uint8_t BCD_value)
{
   if ( Is_BCD(BCD_value) )                  /* verify valid BCD value*/
   {
      if ( BCD_value == 0x00 )               /* test for rollover case*/
      {
         BCD_value = 0x99;                   /* correct for rollover case*/
      }
      else                                   /* is not rollover case*/
      {
         if ( (BCD_value & 0x0F) == 0x00 )   /* test for last digit = 0*/
         {
            BCD_value -= 0x07;               /* sub. 7 for next valid BCD*/
         }
         else                                /* last digit != 0*/
         {
            BCD_value--;                     /* regular decrement*/
         }
      }
   }
   else                                      /* invalid BCD*/
   {
      BCD_value = 0x00;                      /* set value to min for return*/
   }
   return(BCD_value);                        /* return dec'd BCD value*/
}

/**********************************************************************
 *    Function: memcmpch
 *
 *  Parameters: src - pointer to beginning of string to compare
 *              ch  - character to compare against
 *              n   - how many bytes to compare
 *
 *     Returns: int
 *
 * Description: Compares src against a single character.  Returns 0 if
 *              the src string matches n ch characters, non-0 otherwise.
 *
 **********************************************************************/

int32_t memcmpch(void *src, uint8_t ch, size_t n)
{
    uint8_t *char_ptr = src;

    for (; (0 != n); n--)
    {
       if (*char_ptr++ != ch)
       {
         break;
       }
    }
    return(n);
}

/**********************************************************************
 *    Function: memexch
 *
 *  Parameters: src1 - pointer to beginning of first area to exchange
 *              src2 - pointer to beginning of second area to exchange
 *              n    - how many bytes to exchange
 *
 *     Returns: void
 *
 * Description: exchanges n bytes between an object indicated by src1
 *              and an object indicated by src2 provided they do not
 *              overlap.
 *
 **********************************************************************/

void memexch(void *src1, void *src2, size_t n)
{
   uint8_t *pch1;
   uint8_t *pch2;
   uint8_t temp;
   
   if (src1 < src2)           /* set lower address to ch1 */
   {
      pch1 = (uint8_t *) src1;
      pch2 = (uint8_t *) src2;
   }                                                      
   else
   {
      pch1 = (uint8_t *) src2;
      pch2 = (uint8_t *) src1;
   }

   if ((pch1 + n) <= pch2)    /* check for address overlap*/
   {
      for (; (0 != n); n--)
      {
         temp = *pch1;
         *pch1++ = *pch2;
         *pch2++ = temp;
      }
   }
}

/**********************************************************************
 *    Function: Convert_To_Big_Endian
 *
 *  Parameters: *from - pointer to half_word or word to be converted
 *              *to - pointer to destination of the conversion
 *              num_bytes - # of bytes to convert
 *
 *     Returns: None
 *
 * Description: Converts a half_word or word from Little Endian to Big Endian
 *
 **********************************************************************/

void Convert_To_Big_Endian (void *to, const void *from, size_t num_bytes)
{
   #if LITTLE_ENDIAN                       /* If true, do the conversion*/

   char *temp_to = (char *)to;
   const char *temp_from = ((const char *)from) + num_bytes;

   for ( ; 0 != num_bytes ; num_bytes--)
   {
      *(temp_to++) = *(--temp_from);
   }
   #else /*LITTLE_ENDIAN */                  /* Else, temp_to = temp_from*/
   memcpy(to, from, num_bytes);
   #endif /*LITTLE_ENDIAN*/
}

/**********************************************************************
 *    Function: Scale
 *
 *  Parameters: input   - value to be scaled
 *              old_min - minimum value of old range
 *              old_max - maximum value of old range
 *              new_min - minimum value of new scaled range
 *              new_max - maximum value of new scaled range
 *
 *     Returns: Scaled value
 *
 * Description: Scales a value from one range to another.
 *
 **********************************************************************/

int32_t Scale (int32_t input, int32_t old_min, int32_t old_max, int32_t new_min, int32_t new_max)
{
   int32_t old_range = old_max - old_min;

   return(((((input - old_min) * (new_max - new_min)) + (old_range/2))
            / old_range) + new_min);
}
#endif   /*ASSEMBLY_PROJECT_IS*/

/**********************************************************************
 *    Function: Reverse_Bits_In_Byte
 *
 *  Parameters: input - byte to be bit reversed
 *
 *     Returns: byte with reversed bits
 *
 * Description: reverses bits in a byte D7 D6 D5 D4 D3 D2 D1 D0
 *                                      D0 D1 D2 D3 D4 D5 D6 D7
 *
 **********************************************************************/
uint8_t Reverse_Bits_In_Byte (uint8_t byte)
{
   return( (reverse_bits_TBL[byte & 0x0F] << 4) | reverse_bits_TBL[byte >> 4] );
}

/**********************************************************************
 *    Function: SetBits
 *
 *  Parameters: pDest		- destination data pointer that to be set
 *              startBit	- start bit to be set
 *              len			- data length - bits
 *              srcVal 		- source value that to be set
 *
 *     Returns: 0:OK   -1:NG 
 *
 * Description: set the source value to the appointed positon in pDest data.
 *
 **********************************************************************/
int8_t SetBits ( uint8_t *pDest, uint8_t  startBit, uint8_t len, uint32_t srcVal)
{ 
	uint8_t byteID;
	uint8_t bitID;		
	uint8_t rmndrBits;
	uint8_t currByteVal;
	uint8_t srcByteVal;
	uint8_t mask;
	int32_t i;
	int8_t retVal = 0;	/* 0:OK   -1:NG */

	if(len <= 32)
	{
		byteID = startBit/8;
		rmndrBits = 8 - startBit%8;	/* calc remainder bits in current byte */

		if(rmndrBits >= len)
		{
			mask = 0;
			for(i=0; i<len; i++)
			{
				mask = (mask<<1) +1;
			}
			mask = mask<<(rmndrBits-len);
			
			srcByteVal = (uint8_t)srcVal;
			srcByteVal = srcByteVal << (rmndrBits-len);
			srcByteVal = mask & srcByteVal;

			mask = ~mask;
			currByteVal = (pDest[byteID])&mask;	
			
			pDest[byteID] = currByteVal | srcByteVal;
		}
		else
		{
			/***********************************************************************
				    pDest[x]    pDest[x+1]     pDest[x+2]
				 ___________________________________________
				|_____________|______________|______________|
						 _____________________________
						|_____|______________|________| ----- source data
							|        |            |
							|        |            |___________tail part
							|        |
							|        |________________________middle part
							|
							|_________________________________first part
			************************************************************************/
			
			/*----------------------------first part--------------------------------*/
			/* create mask of first part */
			mask = 0;
			for( i=0; i<rmndrBits; i++)
			{
				mask = (mask<<1) +1;
			}

			/* first part */
			srcByteVal = (uint8_t)(srcVal>>(len-rmndrBits));
			srcByteVal = srcByteVal & mask;

			/* clear the destination bits of first part */
			mask = ~mask;
			currByteVal = (pDest[byteID])&mask;	

			/* set the destination bits of first part */
			pDest[byteID++] = currByteVal | srcByteVal;

			/*----------------------------middle part-------------------------------*/
			len = len - rmndrBits;	/* renmender length */
			while(len >= 8)
			{
				srcByteVal = (uint8_t)(srcVal>>(len-8));
				pDest[byteID++] = srcByteVal;
				len = len - 8;
			}			
			/*----------------------------tail part---------------------------------*/

			if((len>0) && (len<8))
			{
				/* get the tail part data */
				srcByteVal = (uint8_t)(srcVal<<(8-len));

				/* create mask of tail part */
				mask = 0;
				for(i=0; i<len; i++)
				{
					mask = (mask<<1) +1;
				}
				mask = mask<<(8-len);

				/* clear the destination bits of tail part */
				mask = ~mask;
				currByteVal = (pDest[byteID] & mask);

				pDest[byteID] = currByteVal | srcByteVal;
				
			}
			else if(len>=8)
			{
				retVal = -1; /* NG */
			}
			else
			{
				/* len == 0, do nothing */
			}
		}

	}
	else
	{
		retVal = -1; /* NG */
	}
   return retVal;
}


