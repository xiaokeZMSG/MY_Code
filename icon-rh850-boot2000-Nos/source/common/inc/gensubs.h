/*
 * Copyright (c) 20109-2020, SAIC  Team
 * file: gensubs.h
 *
 * Change Logs:
 * Date           Author          VER  Notes
 * 2020-02-25    maguangdong      0.1  First edition
 */

#ifndef  __GENSUBS_H__
#define  __GENSUBS_H__ 
#include "r_typedefs.h" 
//#include "FreeRTOS.h"
/*********************************************************************/
/* File level pragmas                                                */
/*********************************************************************/

/*********************************************************************/
/* Constant and Macro Definitions using #define                      */
/*********************************************************************/
#ifndef min
#define min(x,y) ((x) > (y) ? (y) : (x))
#endif    

#ifndef max
#define max(x,y) ((x) < (y) ? (y) : (x))
#endif   

#define size_t uint32_t
/*********************************************************************/
/* Function Prototypes for Private Functions with File Level Scope   */
/*********************************************************************/
extern const uint8_t bits[];
extern const uint8_t not_bits[];
//extern void Assign_Bit( void *addr, uint32_t bitnum, uint32_t num_bits, int32_t Set_or_Clear, int32_t RangeCheck);
extern void Assign_Bit( void *addr, uint32_t bitnum, uint32_t num_bits, bool Set_or_Clear, bool RangeCheck);

void *CS_Write(void *dest, const void *source, size_t count, uint16_t *checksum);
extern int32_t Limit_Check (int32_t value, int32_t min, int32_t max);
extern int32_t Scale (int32_t input, int32_t old_min, int32_t old_max, int32_t new_min, int32_t new_max);
extern int32_t Wrap_Check  (int32_t value, int32_t min, int32_t max);
extern int32_t Is_BCD(uint8_t Potential_BCD_Value);
extern uint8_t Hex_To_BCD (uint8_t HexValue);
extern uint16_t Hex_To_WBCD (uint8_t HexValue);
extern uint16_t WHEX_To_WBCD(uint16_t HexValue);
extern uint8_t BCD_To_Hex (uint8_t BCD_Value);
extern uint8_t WBCD_To_Hex (uint16_t WBCD_value);
extern uint16_t WBCD_To_WHEX (uint16_t WBCD_value);
extern uint8_t BCD_increment(uint8_t BCD_value);
extern uint8_t BCD_decrement(uint8_t BCD_value);
extern int32_t memcmpch(void *src, uint8_t ch, size_t n);
extern void memexch(void *src1, void *src2, size_t n);
extern void Convert_To_Big_Endian (void *to, const void *from, size_t num_bytes);
extern uint8_t Reverse_Bits_In_Byte(uint8_t byte);        

/*********************************************************************/
/* Enumerations and Structures and Typedefs                          */
/*********************************************************************/
                                                                       
/*********************************************************************/
/* Global and Const Variable Defining Definitions / Initializations  */
/*********************************************************************/
                                                                       
/*********************************************************************/
/* Static Variables and Const Variables With File Level Scope        */
/*********************************************************************/
                                                                       
/*********************************************************************/
/* ROM Const Variables With File Level Scope                         */
/*********************************************************************/
                                                                       
/*********************************************************************/
/* Function Definitions                                              */
/*********************************************************************/

/**********************************************************************
 * Function      : Set_Bit/Set_Bit_Subr
 * Description   : to set a bit given an address and a bit offset - used to implement a packed array of booleans
 * Parameters    : addr: address of object in which to set the bit
                 : bit: the bit offset, counted from the lowest address, MSB
 * Returns       : 
 * Description   : 
 *********************************************************************/
#define Set_Bit(addr, bitnum)       Assign_Bit((addr), (bitnum),0x7e,1,0)
#define Set_Bit_Subr(addr, bitnum) Assign_Bit((addr), (bitnum),0x7e,1,0)
int8_t SetBits ( uint8_t *pDest, uint8_t  startBit, uint8_t len, uint32_t srcVal);
/**********************************************************************
 * Function      : Clear_Bit/Clear_Bit_Subr
 * Description   : to clear a bit given an address and a bit offset - used to implement a packed array of booleans
 * Parameters    : addr: address of object in which to set the bit
                 : bit: the bit offset, counted from the lowest address, MSB
 * Returns       : 
 * Description   : 
 *********************************************************************/
#define Clear_Bit(addr, bitnum)       Assign_Bit((addr), (bitnum),0x7e,0,0)
#define Clear_Bit_Subr(addr, bitnum) Assign_Bit((addr), (bitnum),0x7e,0,0)

/**********************************************************************
 * Function      : Set_Bit_RNGE_Check
 * Description   : to clear a bit given an address and a bit offset - used to implement a packed array of booleans
 * Parameters    : addr: address of object in which to set the bit
                 : bit: the bit offset, counted from the lowest address, MSB
                 : limit: size of bit array
 * Returns       : 
 * Description   : 
 *********************************************************************/
#define Set_Bit_RNGE_Check(addr,bitnum,num_bits) Assign_Bit((addr), (bitnum), (num_bits),1,1)

/**********************************************************************
 * Function      : Clear_Bit_RNGE_Check
 * Description   : to clear a bit given an address and a bit offset - used to implement a packed array of booleans
 * Parameters    : addr: address of object in which to set the bit
                 : bit: the bit offset, counted from the lowest address, MSB
                 : limit: size of bit array
 * Returns       : 
 * Description   : 
 *********************************************************************/
#define Clear_Bit_RNGE_Check(addr, bitnum, num_bits) Assign_Bit((addr), (bitnum), (num_bits),0,1)

/**********************************************************************
 * Purpose:
 *   to Toogle a bit given an address and a bit offset - used to implement
 *   a packed array of booleans
 *
 * Parameters:
 *   addr: address of object in which to set the bit
 *   bit: the bit offset, counted from the lowest address, MSB
 **********************************************************************/
#define Toggle_Bit(addr, bitnum) \
  (*(((char *)(addr)) + ((bitnum) >> 3)) ^= (1 << (7 - ((bitnum) & 0x07))))


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
#define Read_Bit(addr, bitnum) Read_Bit_Subr((addr), (bitnum))

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
extern int32_t Read_Bit_Subr( void *addr, uint32_t bitnum );

/**********************************************************************
 * Purpose: To find the first active bit from an array
 *
 * Parameters:
 *    array - the address of the array
 *    bit_size - the size of the array in bits (not bytes)
 *    consume_bit - if true bit is cleared
 *
 * return: -1 if no bit is set, otherwise the offset, in bits, from the MSB
 *         of the lowest addressed byte in the array
 *          CLEARS the BIT
 **********************************************************************/
//extern int32_t Find_First_Set_Bit(void *addr, size_t bit_size, int32_t consume_bit);
extern int32_t Find_First_Set_Bit(void *addr, size_t bit_size, bool consume_bit);


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
//extern int32_t Find_Next_Bit_with_Wrap(void *addr, size_t bit_size, int32_t starting_bit, int32_t up);
extern int32_t Find_Next_Bit_with_Wrap(void *addr, size_t bit_size, int32_t current_bit, bool up);


/**********************************************************************
 * Function      : CS_Write_Byte
 * Description   : writes 1 byte to checksum variable
 * Parameters    : dest     adddress of checksummed variable to update
                 : value    data byte to write
                 : checksum address of checksum 
 * Returns       : 
 * Description   : 
 *********************************************************************/
#define CS_Write_Byte(dest, value, checksum) CS_Write((dest), &(value), 1, (checksum))



#endif
