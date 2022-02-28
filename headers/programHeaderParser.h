#ifndef __PROGRAMHEADERPARSER__INCLUDED__
#define __PROGRAMHEADERPARSER__INCLUDED__


#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <endian.h>
#include <string.h>
#include <errno.h>
#include "./elfHeaderParser.h"


extern uint32_t programHeaderNumber;


void* loadSegment(FILE* fd, uint64_t start, uint64_t size);
Elf64_Phdr* correctEndianness64bitPH(Elf64_Phdr* programheader);
Elf32_Phdr* correctEndianness32bitPH(Elf32_Phdr* programHeader);
Elf64_Phdr* parseProgramHeader64Bit(Elf64_Ehdr* elfHeader, FILE* fd);
Elf32_Phdr* parseProgramHeader32Bit(Elf32_Ehdr* elfHeader, FILE* fd);
void* parseProgramHeader(void* rawElfHeader,FILE* fd);


#endif