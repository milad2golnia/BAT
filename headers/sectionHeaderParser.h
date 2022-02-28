#ifndef __SECTIONHEADERPARSER__INCLUDED__
#define __SECTIONHEADERPARSER__INCLUDED__


#include "./elfHeaderParser.h"


extern uint64_t sectionHeadersNumber;
extern uint32_t sectionHeaderStringIndex;
extern char*    sectionStringTable;


void* loadSection(FILE* fd, uint64_t start, uint64_t size);
Elf32_Shdr* correctEndianness32bitSH(Elf32_Shdr* sectionHeader);
Elf64_Shdr* correctEndianness64bitSH(Elf64_Shdr* sectionHeader);
Elf64_Shdr* parseSectionHeader64Bit(Elf64_Ehdr* elfHeader, FILE* fd);
Elf32_Shdr* parseSectionHeader32Bit(Elf32_Ehdr* elfHeader, FILE* fd);
void* parseSectionHeader(void* rawElfHeader, FILE* fd);
/*
*   New functions added for HW2:
*/
uint64_t rawSSize(void* sectionHeaderTable, uint64_t index);
uint64_t rawSOffset(void* sectionHeaderTable, uint64_t index);
uint64_t rawSAddress(void* sectionStringTable, uint64_t index);

#endif