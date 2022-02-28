#ifndef __RELOCATIONPARSER__INCLUDED__
#define __RELOCATIONPARSER__INCLUDED__


#include <elf.h>
#include "displaySectionHeader.h"


/*
*   Possible values for type of relocationInfo
*/
#define relPLT 1
#define relDYN 2
#define relAPLT 3
#define relADYN 4


/*
*   Structure to keep the .rel or .rela section information:
*       This information is used to determine the addresses in .plt section.
*/
typedef struct relocationInfo{
    /*
    *   Number of entries in .rel or .rela sectoin.
    */
    uint64_t entryCount;
    
    /*
    *   Type of relocation Info.
    */
    int type;

    /*
    *   Containing the .rel section contents.
    */ 
    void* relEntries;
}relocationInfo;


/*
*   This is an inner function, don't call it directly.
*/
Elf32_Addr rawRISymbolIndexRela(void* relTable, uint64_t index);

/*
*   This is an inner function, don't call it directly.
*/
Elf32_Addr rawRISymbolIndexRel(void* relTable, uint64_t index);

/*
*   Return The Symbol Table Index associated with entry at 'index' offset of relTable.
*   @param  relTable    -   relocation structure.
*   @param  index       -   index into relTable.
*   @param  type        -   type of relocation structure.
*/
Elf32_Addr rawRISymbolIndex(void* relTable, uint64_t index, uint64_t type);

/*
*   Try to parse the .rel/.rela section at 'index' offset of Section Header Table.
*   NOTE: This is an inner function, Don't call it directly!
*/
relocationInfo parseRELPLT32Bit(Elf32_Shdr* sht, uint64_t index);

/*
*   Tries to parse the .rel/.rela section at 'index' offset of Section Header Table.
*   NOET: This is an inner function, Don't call it directly!
*/
relocationInfo parseRELPLT64Bit(Elf64_Shdr* sht, uint64_t index);

/*
*   Get the Section Header Table and tries to extract .rel.* and .rela.* sections.
*   NOTE: Currently we are just concerned about .rel.plt and .rela.plt sections and hence we 
*           just focus on these both sections to extract them. Other sections such as .rel.dyn 
*           will be ignored at this moment.
*   @param SHT  -   Section Header Tabel.
*/
relocationInfo* parseREL(void* SHT);


#endif