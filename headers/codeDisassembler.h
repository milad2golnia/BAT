#ifndef __CODEDISASSEMBLER__INCLUDED__
#define __CODEDISASSEMBLER__INCLUDED__


#include <capstone/capstone.h>
//We need below library to extract the code sections:
#include "sectionHeaderParser.h"
//We need below library to extract some sections information such as flags, name and etc:
#include "displaySectionHeader.h"
//We need below library to extract the architecture type:
#include "displayELFHeader.h"


/*
*   Contains all disassembled code sections.
*   We are disassembling code sections and hence we call it 'assemblyCode'
*/
typedef struct assemblyCode
{
    /*
    *   Determines how many code sections we have disassembled.
    *   It is valid just in first entry of the list. In other entries, it doesn't have any
    *       special meaning and might be valid or invalid.
    *   This is useful when we want to return an array of 'assemblyCode's
    */
    int numberOfSections;

    /*
    *   Address of this section
    */
    char* address;
    
    /*
    *   A lable or name for current disassembled codes.
    *   Usually it contains the section name but it may differ.
    */
    char* label;

    /*
    *   Determines number of instructions in each entry/section.
    */
    size_t numberOfInstructions;

    /*
    *   Points to instructions of this entry/section.
    */
    cs_insn* instructionPointer;
} assemblyCode;

/*
*   Utilize capstone library to disassemble the binary executable machine instructions.
*   Prevent the underlying functions to change the loaded section by defining types as const:
*       We do so because upper layer may need the content yet and we don't like to double load 
*       this section.
*/
assemblyCode capstonize(const uint8_t* const binaryInstructions, uint64_t length, uint64_t addr ,cs_arch architecture, cs_mode mode);

/*
*   We need elfHeader to recognize the architecture and SHT to recognize code sections.
*   NOTE: Make sure you call freeDisassembledCode code after calling this function.
*/ 
assemblyCode* disassembleCode(void* elfHeader, void* sectionHeaderTable);

/*
*   Search through disassembled codes to find the given address.
*   @param code -   The all disassembled codes.
*   @param address  -   The address you are looking for it.
*   @return The assembly section which contains the given address.
*/
assemblyCode findInstructionByAddress(assemblyCode* code, uint64_t address);

/*
*   Release allocated memories for disassembling the binary code which are pointed 
*   by passed parameter.
*/
void freeDisassembledCode(assemblyCode** disassembledCodeAddress);

/*
*   Estimate numebr of call instructions:
*/
uint64_t callInstructionsCount(assemblyCode* code);

#endif