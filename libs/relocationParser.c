#include "../headers/relocationParser.h"


relocationInfo parseRELPLT32Bit(Elf32_Shdr* sht, uint64_t index){
    relocationInfo result = {-1, -1, NULL};
    
    //Compute number of entries in this relocatable section:
    result.entryCount = sht[index].sh_size / sht[index].sh_entsize;
    
    //Load this section into memory:
    result.relEntries = loadSection(NULL, sht[index].sh_offset, sht[index].sh_size);

    if(strcmp(sName(sht, index), ".rel.plt") == 0)
        result.type = relPLT;
    else if(strcmp(sName(sht, index), ".rela.plt") == 0)
        result.type = relAPLT;
    else if(strcmp(sName(sht, index), ".rel.dyn") == 0)
        result.type = relDYN;
    else if(strcmp(sName(sht, index), ".rela.dyn") == 0)
        result.type = relADYN;
    return result;
}

relocationInfo parseRELPLT64Bit(Elf64_Shdr* sht, uint64_t index){
    relocationInfo result = {-1, -1, NULL};
    
    //Compute number of entries in this relocatable section:
    result.entryCount = sht[index].sh_size / sht[index].sh_entsize;
    
    //Load this section into memory:
    result.relEntries = loadSection(NULL, sht[index].sh_offset, sht[index].sh_size);

    if(strcmp(sName(sht, index), ".rel.plt") == 0)
        result.type = relPLT;
    else if(strcmp(sName(sht, index), ".rela.plt") == 0)
        result.type = relAPLT;
    else if(strcmp(sName(sht, index), ".rel.dyn") == 0)
        result.type = relDYN;
    else if(strcmp(sName(sht, index), ".rela.dyn") == 0)
        result.type = relADYN;
    return result;
}

relocationInfo* parseREL(void* SHT){
    /*
    *   We assume there are at most 4 relocatable sections in ELF File.
    *   The element with entryCount = -1 indicates end of these sections.
    */
    relocationInfo* relocatables = calloc(5, sizeof(relocationInfo));
    int index = 0;

    for (size_t i = 0; i < sectionHeadersNumber; i++)
    {
        if(strcmp(sType(SHT, i), "RELA") == 0 ||
            strcmp(sType(SHT, i), "REL") == 0){
            if(is32Bit()){
                relocatables[index++] = parseRELPLT32Bit(SHT, i);
            }else{
                relocatables[index++] = parseRELPLT64Bit(SHT, i);
            }
        }
    }

    //Mark end of relocatable sections.
    relocatables[index].entryCount = -1;
    
    return relocatables;
}

Elf32_Addr rawRISymbolIndexRela(void* relTable, uint64_t index){
    if(is32Bit()){
        Elf32_Rela* relocationTable = relTable;
        return ELF32_R_SYM(relocationTable[index].r_info);
    }else{
        Elf64_Rela* relocationTable = relTable;
        return ELF64_R_SYM(relocationTable[index].r_info);
    }
}

Elf32_Addr rawRISymbolIndexRel(void* relTable, uint64_t index){
    if(is32Bit()){
        Elf32_Rel* relocationTable = relTable;
        return ELF32_R_SYM(relocationTable[index].r_info);
    }else{
        Elf64_Rel* relocationTable = relTable;
        return ELF64_R_SYM(relocationTable[index].r_info);
    }
}

Elf32_Addr rawRISymbolIndex(void* relTable, uint64_t index, uint64_t type){
    if(type == relAPLT || type == relADYN)
        return rawRISymbolIndexRela(relTable, index);
    else
        return rawRISymbolIndexRel(relTable, index);
}