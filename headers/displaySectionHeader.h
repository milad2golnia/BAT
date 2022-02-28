#ifndef __DISPLAYSECTIONHEADER__INCLUDED__
#define __DISPLAYSECTIONHEADER__INCLUDED__

#include <elf.h>
#include "./sectionHeaderParser.h"


/*
*   Missed flags in elf.h:
*/
#define SHF_AMD64_LARGE 0x80000000


char* sName(void* sectionHeaderTable, uint64_t index);
const char* sType(void* sectionHeaderTable, uint64_t index);
char* sAddress(void* sectionHeaderTable, uint64_t index);
char* sOffset(void* sectionHeaderTable, uint64_t index);
char* sSize(void* sectionHeaderTable, uint64_t index);
char* sEntSize(void* sectionHeaderTable, uint64_t index);
char* sFlags(void* sectionHeaderTable, uint64_t index);
uint32_t sLink(void* sectionHeaderTable, uint64_t index);
uint64_t sInfo(void* sectionHeaderTable, uint64_t index);
uint64_t sAlign(void* sectionHeaderTable, uint64_t index);
const char* footer();


#endif