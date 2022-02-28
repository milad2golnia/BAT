#ifndef __DISPLAYPROGRAMHEADER__INCLUDED__
#define __DISPLAYPROGRAMHEADER__INCLUDED__

#include <elf.h>
#include "./programHeaderParser.h"


const char* pType(void* programHeaderTable, uint32_t index);
char* pOffset(void* programHeaderTable, uint32_t index);
char* pVirtualAddress(void* programHeaderTable, uint32_t index);
char* pPhysicalAddress(void* programHeaderTable, uint32_t index);
char* pFileSize(void* programHeaderTable, uint32_t index);
char* pMemorySize(void* programHeaderTable, uint32_t index);
char* pFlags(void* programHeaderTable, uint32_t index);
char* pAlign(void* programHeaderTable, uint32_t index);
char* loadInterpret(void* programHeaderTable, uint32_t index);


#endif