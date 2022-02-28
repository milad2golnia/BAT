#ifndef __ELFHEADERPARSER_INCLUDED__
#define __ELFHEADERPARSER_INCLUDED__


#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <endian.h>


/*
*   Missed OS/ABIs which are missed in elf.h
*/
#define ELFOSABI_GNUHURD                        0x04
#define ELFOSABI_NOVELLMODESTO                  0x0B
#define ELFOSABI_OPENVMS                        0x0D
#define ELFOSABI_NONSTOPKERNEL                  0x0E
#define ELFOSABI_AROS                           0x0F
#define ELFOSABI_FENIXOS                        0x10
#define ELFOSABI_CLOUDABI                       0x11
#define ELFOSABI_STRATUSTECHNOLOGIESOPENVOS     0x12
/*
*   Missed Machines which are (probably) missed in elf.h
*/
#define EM_INTEL80960                           0x13
#define EM_WDC                                  0x101

extern bool isELF64Bit;
extern bool isELFBigEndian;


bool isBigEndian();
bool isLittleEndian();
bool is64Bit();
bool is32Bit();
void* correctEndianness32bit(Elf32_Ehdr* header);
void* correctEndianness64bit(Elf64_Ehdr* header);
void* parseELFHeader(FILE* fd);


#endif