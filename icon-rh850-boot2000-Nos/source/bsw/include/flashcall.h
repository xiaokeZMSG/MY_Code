

#ifndef FLASHCALL_H_
#define FLASHCALL_H_

//#include "typedefs.h"
#include "Fls_Cfg.h"
//typedef   unsigned long   uintptr_t;
//typedef void (*flashCbType)( void );
extern void Flash_Init( void );
extern uint32_t Flash_Lock(const FlashType *fPtr, uint32_t op, uintptr_t from, uint32_t size);
extern uint32_t Flash_Erase( const FlashType *fPtr, uintptr_t dest, uint32_t size, flashCbType cb) ;
//uint32_t Flash_Program(const struct Flash *fPtr, uintptr_t to, uintptr_t from,uint32_t size, flashCbType sb);
extern uint32_t Flash_ProgramPageStart( const FlashType *fPtr, uint32_t *to, uint32_t * from, uint32_t * size, flashCbType cb,bool ignoreFail); 
extern uint32_t Flash_CheckStatus( const FlashType *fPtr, uint32_t *to, uint32_t size );
//uint32_t Flash_SectorAligned( const struct Flash *fPtr, uintptr_t addr );


#endif 
