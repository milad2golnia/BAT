#include "../headers/displayProgramHeader.h"


const char* pType(void* programHeaderTable, uint32_t index){
    uint32_t type = 0;
    if(is32Bit()){
        Elf32_Phdr* header = (Elf32_Phdr *) programHeaderTable;
        type = header[index].p_type;
    }else{
        Elf64_Phdr* header = (Elf64_Phdr *) programHeaderTable;
        type = header[index].p_type;
    }
    switch (type)
    {
    case PT_NULL:
        return "NULL";
    case PT_LOAD:
        return "LOAD";
    case PT_DYNAMIC:
        return "DYNAMIC";
    case PT_INTERP:
        return "INTERP";
    case PT_NOTE:
        return "NOTE";
    case PT_SHLIB:
        return "SHLIB";
    case PT_PHDR:
        return "PHDR";
    case PT_GNU_STACK:
        return "GNU_STACK";
    case PT_TLS:
        return "TLS";
    case PT_GNU_EH_FRAME:
        return "GNU_EH_FRAME";
    case PT_GNU_PROPERTY:
        return "GNU_PROPERTY";
    case PT_GNU_RELRO:
        return "GNU_RELRO";
    default:
        if(type <= PT_HIOS && type >= PT_LOOS)
            return "Operation system-specifc";
        if(type <= PT_HIPROC && type >= PT_LOPROC)
            return "Processor specific";
        return "UNKNOWN(Not developed)";
    }
}

char* pOffset(void* programHeaderTable, uint32_t index){

    /*
    *   * Every byte can be represented in two hex digits ==> two byte.
    *   32bit = 4 byte => 8 byte to represent it in hex.
    *   64bit = 8 byte => 16 byte to represent it in hex.
    *   
    */ 
    char* offset = NULL;
    if(is32Bit()){
        Elf32_Phdr* header = (Elf32_Phdr *) programHeaderTable;

        offset = calloc(9, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(offset, 0, 9);

        sprintf(offset, "%08x", header[index].p_offset);
        offset[8] = 0;
    }else{
        Elf64_Phdr* header = (Elf64_Phdr *) programHeaderTable;

        offset = calloc(17, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(offset, 0, 17);
        
        sprintf(offset, "%016x", header[index].p_offset);
        offset[16] = 0;
    }

    return offset;
}

char* pVirtualAddress(void* programHeaderTable, uint32_t index){
    /*
    *   * Every byte can be represented in two hex digits ==> two byte.
    *   32bit = 4 byte => 8 byte to represent it in hex.
    *   64bit = 8 byte => 16 byte to represent it in hex.
    *   
    */ 
    char* vAddr = NULL;
    if(is32Bit()){
        Elf32_Phdr* header = (Elf32_Phdr *) programHeaderTable;

        vAddr = calloc(9, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(vAddr, 0, 9);

        sprintf(vAddr, "%08x", header[index].p_vaddr);
        vAddr[8] = 0;
    }else{
        Elf64_Phdr* header = (Elf64_Phdr *) programHeaderTable;

        vAddr = calloc(17, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(vAddr, 0, 17);
        
        sprintf(vAddr, "%016x", header[index].p_vaddr);
        vAddr[16] = 0;
    }

    return vAddr;
}

char* pPhysicalAddress(void* programHeaderTable, uint32_t index){
    /*
    *   * Every byte can be represented in two hex digits ==> two byte.
    *   32bit = 4 byte => 8 byte to represent it in hex.
    *   64bit = 8 byte => 16 byte to represent it in hex.
    *   
    */ 
    char* pAddr = NULL;
    if(is32Bit()){
        Elf32_Phdr* header = (Elf32_Phdr *) programHeaderTable;

        pAddr = calloc(9, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(pAddr, 0, 9);

        sprintf(pAddr, "%08x", header[index].p_paddr);
        pAddr[8] = 0;
    }else{
        Elf64_Phdr* header = (Elf64_Phdr *) programHeaderTable;

        pAddr = calloc(17, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(pAddr, 0, 17);
        
        sprintf(pAddr, "%016x", header[index].p_paddr);
        pAddr[16] = 0;
    }

    return pAddr;
}

char* pFileSize(void* programHeaderTable, uint32_t index){
    /*
    *   * Every byte can be represented in two hex digits ==> two byte.
    *   32bit = 4 byte => 8 byte to represent it in hex.
    *   64bit = 8 byte => 16 byte to represent it in hex.
    *   
    */ 
    char* fs = NULL;
    if(is32Bit()){
        Elf32_Phdr* header = (Elf32_Phdr *) programHeaderTable;

        fs = calloc(9, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(fs, 0, 9);

        sprintf(fs, "%08x", header[index].p_filesz);
        fs[8] = 0;
    }else{
        Elf64_Phdr* header = (Elf64_Phdr *) programHeaderTable;

        fs = calloc(17, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(fs, 0, 17);
        
        sprintf(fs, "%016x", header[index].p_filesz);
        fs[16] = 0;
    }

    return fs;
}

char* pMemorySize(void* programHeaderTable, uint32_t index){
    /*
    *   * Every byte can be represented in two hex digits ==> two byte.
    *   32bit = 4 byte => 8 byte to represent it in hex.
    *   64bit = 8 byte => 16 byte to represent it in hex.
    *   
    */ 
    char* ms = NULL;
    if(is32Bit()){
        Elf32_Phdr* header = (Elf32_Phdr *) programHeaderTable;

        ms = calloc(9, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(ms, 0, 9);

        sprintf(ms, "%08x", header[index].p_memsz);
        ms[8] = 0;
    }else{
        Elf64_Phdr* header = (Elf64_Phdr *) programHeaderTable;

        ms = calloc(17, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(ms, 0, 17);
        
        sprintf(ms, "%016x", header[index].p_memsz);
        ms[16] = 0;
    }

    return ms;
}

char* pFlags(void* programHeaderTable, uint32_t index){
    char* flagNames = calloc(4, sizeof(char));

    /*
    *Warning: In my system the char* variables are initialized to 0 by default but I should 
    * take care of those which don't do this:
    */
    memset(flagNames, 0, 4);

    uint32_t flags = 0;
    if(is32Bit()){
        Elf32_Phdr* header = (Elf32_Phdr *) programHeaderTable;
        flags = header[index].p_flags;
    }else{
        Elf64_Phdr* header = (Elf64_Phdr *) programHeaderTable;
        flags = header[index].p_flags;
    }

    if(flags & PF_R)
        sprintf(flagNames, "%s%c", flagNames, 'R');
    if(flags & PF_W)
        sprintf(flagNames, "%s%c", flagNames, 'W');
    if(flags & PF_X)
        sprintf(flagNames, "%s%c", flagNames, 'E');

    flagNames[3] = 0;
    return flagNames;
}

char* pAlign(void* programHeaderTable, uint32_t index){
    /*
    *   * Every byte can be represented in two hex digits ==> two byte.
    *   32bit = 4 byte => 8 byte to represent it in hex.
    *   64bit = 8 byte => 16 byte to represent it in hex.
    *   
    */ 
    char* alignment = NULL;
    if(is32Bit()){
        Elf32_Phdr* header = (Elf32_Phdr *) programHeaderTable;

        alignment = calloc(9, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(alignment, 0, 9);

        sprintf(alignment, "%x", header[index].p_align);
        alignment[8] = 0;
    }else{
        Elf64_Phdr* header = (Elf64_Phdr *) programHeaderTable;

        alignment = calloc(17, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(alignment, 0, 17);
        
        sprintf(alignment, "%x", header[index].p_align);
        alignment[16] = 0;
    }

    return alignment;
}


char* loadInterpret(void* programHeaderTable, uint32_t index){
    if(is32Bit()){
        Elf32_Phdr* header = (Elf32_Phdr *) programHeaderTable;
        return loadSegment(NULL, header[index].p_offset, header[index].p_filesz);
    }else{
        Elf64_Phdr* header = (Elf64_Phdr *) programHeaderTable;
        return loadSegment(NULL, header[index].p_offset, header[index].p_filesz);
    }
}