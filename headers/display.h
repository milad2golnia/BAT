#ifndef __DISPLAY__INCLUDED__
#define __DISPLAY__INCLUDED__


#include "elfHeaderParser.h"
#include "./displayELFHeader.h"
#include "./displaySectionHeader.h"
#include "./displayProgramHeader.h"
#include "./displaySymbolTable.h"
#include "./codeDisassembler.h"


void printELFHeader(void* elfHeader);
void printSectionHeader(uint64_t entryCount, void* sectionHeader);
void printProgramHeader(uint64_t entryCount, void* sectionHeader);
void printHeaders(void* elfHeader, void* programHeader, void* sectionHeader);

/*
*   Prints a bunch of instructions.
*   Prevent unwanted changes on instructions and output stream because we may need them later.
*/
void printInstructions(const cs_insn* const instrunctionsPointer, size_t count, FILE* output);

/*
*   Pass the disassembled codes to this function and it tries to print them in a style similar
*   to `objdump` program.
*   output argument: if it's NULL, we consider standard output as default.
*/
void printCodes(const assemblyCode* const codeSections, FILE* output);

/*
*   Print the Symbol Table Entries in a style similar to `readelf --syms` output.
*/
void printSymbolTable(const symbolTableInfo* const sti);

#endif