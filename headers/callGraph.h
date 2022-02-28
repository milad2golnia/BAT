#ifndef __CALLGRAPH__INCLUDED__
#define __CALLGRAPH__INCLUDED__


#include <elf.h>
#include "symbolTableParser.h"
#include "codeDisassembler.h"
#include "displayELFHeader.h"
#include "relocationParser.h"
//For test purpose:
#include "display.h"


/*
*   Providing Dynamic Symbol Table and Relocation Info, it can resolve the addresses of 
*       dynamic functions.
*   @param  sti -   Symbol Table Information.
*   @param  ri  -   Relocation Information.
*   @param  base    -   Base address of relocations.
*   @param  space    -  The space where relocations happen.
*/
void fixDynamicFunctions(symbolTableInfo* sti, relocationInfo* ri, uint64_t base,
                            uint64_t space);

/*
*   This function gets needed information about elf file and tries to draw the the call graph
*       of program in 'dot' format. the result will be write to output file.
*   @param EH   - ELF Header.
*   @param SHT  - Section Header Table.
*   @param code -   Disassembled code of elf file.
*   @param sti  -       Symbol Table Inforation containing both dynamic and static symbol table.
*   @param output   -   The output file which you want to draw graph into it.
*/
void drawCallGraph(void* EH, void* SHT, assemblyCode* code, symbolTableInfo* sti, FILE* output);

/*
*   This function walk through disassembled code and draws the call graph in dot format.
*   @param code -   Disassembled code of elf file.
*   @param functionSymbolTable  - Symbol Table Inforation containing both dynamic and static functions.
*   @param output   -   The output file which you want to draw graph into it.
*   @param pltBase  -   The start address of plt, We use it to determine dynamic calls.
*   @param pltSize  -   The size of plt section, We use it to determine dynamic calls.
*/
void dotDraw(assemblyCode* code, symbolTableInfo* functionSymbolTable, uint64_t pltBase,
                uint64_t pltSize, FILE* output);


#endif