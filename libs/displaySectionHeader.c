#include "../headers/displaySectionHeader.h"


char* sName(void* sectionHeaderTable, uint64_t index){
    if(sectionHeaderStringIndex == SHN_UNDEF)
        return NULL;
    if(is32Bit()){
        Elf32_Shdr* headerTable = (Elf32_Shdr *) sectionHeaderTable;
        return &(sectionStringTable[headerTable[index].sh_name]);
    }else{
        Elf64_Shdr* headerTable = (Elf64_Shdr *) sectionHeaderTable;
        return &(sectionStringTable[headerTable[index].sh_name]);
    }
}

const char* sType(void* sectionHeaderTable, uint64_t index){
    uint32_t type = 0;
    if(is32Bit()){
        Elf32_Shdr* headerTable = (Elf32_Shdr *) sectionHeaderTable;   
        type = headerTable[index].sh_type;
    }else{
        Elf64_Shdr* headerTable = (Elf64_Shdr *) sectionHeaderTable;
        type = headerTable[index].sh_type;
    }

    switch (type)
    {
    case SHT_NULL:
        return "NULL";
    case SHT_PROGBITS:
        return "PROGBITS";
    case SHT_SYMTAB:
        return "SYMTAB";
    case SHT_STRTAB:
        return "STARTB";
    case SHT_RELA:
        return "RELA";
    case SHT_HASH:
        return "HASH";
    case SHT_DYNAMIC:
        return "DYNAMIC";
    case SHT_NOTE:
        return "NOTE";
    case SHT_NOBITS:
        return "NOBITS";
    case SHT_REL:
        return "REL";
    case SHT_SHLIB:
        return "SHLIB";
    case SHT_DYNSYM:
        return "DYNSYM";
    case SHT_GNU_HASH:
        return "GNU_HASH";
    case SHT_GNU_versym:
        return "VERSYM";
    case SHT_GNU_verneed:
        return "VERNEED";
    case SHT_INIT_ARRAY:
        return "INIT_ARRAY";
    case SHT_FINI_ARRAY:
        return "FIN_ARRAY";
    case SHT_PREINIT_ARRAY:
        return "PREINIT_ARRAY";
    case SHT_GROUP:
        return "GROUP";
    case SHT_SYMTAB_SHNDX:
        return "SYMTAB_SHNDX";
    case SHT_NUM:
        return "NUM";
    default:
        if(type <= SHT_HIPROC && type >= SHT_LOPROC)
            return "Processor-specific";
        if(type <= SHT_HIUSER && type >= SHT_LOUSER)
            return "Application program-specific";
        return "UNKNOWN(Not developed)";
    }
}

char* sAddress(void* sectionHeaderTable, uint64_t index){
    /*
    *   * Every byte can be represented in two hex digits ==> two byte.
    *   32bit = 4 byte => 8 byte to represent it in hex.
    *   64bit = 8 byte => 16 byte to represent it in hex.
    *   
    */ 
    char* address = NULL;
    if(is32Bit()){
        address = calloc(9, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(address, 0, 9);

        Elf32_Shdr* headerTable = (Elf32_Shdr *) sectionHeaderTable;
        sprintf(address, "%08x", headerTable[index].sh_addr);

        address[8] = 0;
    }else{
        address = calloc(17, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(address, 0, 17);

        Elf64_Shdr* headerTable = (Elf64_Shdr *) sectionHeaderTable;
        sprintf(address, "%016x", headerTable[index].sh_addr);

        address[16] = 0;
    }

    return address;
}

char* sOffset(void* sectionHeaderTable, uint64_t index){
    /*
    *   * Every byte can be represented in two hex digits ==> two byte.
    *   32bit = 4 byte => 8 byte to represent it in hex.
    *   64bit = 8 byte => 16 byte to represent it in hex.
    *   
    */ 
    char* offset = NULL;
    if(is32Bit()){
        offset = calloc(9, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(offset, 0, 9);

        Elf32_Shdr* headerTable = (Elf32_Shdr *) sectionHeaderTable;
        sprintf(offset, "%08x", headerTable[index].sh_offset);

        offset[8] = 0;
    }else{
        offset = calloc(17, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(offset, 0, 17);

        Elf64_Shdr* headerTable = (Elf64_Shdr *) sectionHeaderTable;
        sprintf(offset, "%016x", headerTable[index].sh_offset);

        offset[16] = 0;
    }

    return offset;
}

char* sSize(void* sectionHeaderTable, uint64_t index){
    /*
    *   * Every byte can be represented in two hex digits ==> two byte.
    *   32bit = 4 byte => 8 byte to represent it in hex.
    *   64bit = 8 byte => 16 byte to represent it in hex.
    *   
    */ 
    char* size = NULL;
    if(is32Bit()){
        size = calloc(9, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(size, 0, 9);

        Elf32_Shdr* headerTable = (Elf32_Shdr *) sectionHeaderTable;
        sprintf(size, "%08x", headerTable[index].sh_size);

        size[8] = 0;
    }else{
        size = calloc(17, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(size, 0, 17);

        Elf64_Shdr* headerTable = (Elf64_Shdr *) sectionHeaderTable;
        sprintf(size, "%016x", headerTable[index].sh_size);

        size[16] = 0;
    }

    return size;
}

char* sEntSize(void* sectionHeaderTable, uint64_t index){
    /*
    *   * Every byte can be represented in two hex digits ==> two byte.
    *   32bit = 4 byte => 8 byte to represent it in hex.
    *   64bit = 8 byte => 16 byte to represent it in hex.
    *   
    */ 
    char* entSize = NULL;
    if(is32Bit()){
        entSize = calloc(9, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(entSize, 0, 9);

        Elf32_Shdr* headerTable = (Elf32_Shdr *) sectionHeaderTable;
        sprintf(entSize, "%08x", headerTable[index].sh_entsize);

        entSize[8] = 0;
    }else{
        entSize = calloc(17, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(entSize, 0, 17);

        Elf64_Shdr* headerTable = (Elf64_Shdr *) sectionHeaderTable;
        sprintf(entSize, "%016x", headerTable[index].sh_entsize);

        entSize[16] = 0;
    }

    return entSize;
}

char* sFlags(void* sectionHeaderTable, uint64_t index){
    char* flagNames = calloc(16, sizeof(char));
    uint64_t flags = 0;
    if(is32Bit()){
        Elf32_Shdr* headerTable = (Elf32_Shdr *) sectionHeaderTable;   
        flags = headerTable[index].sh_flags;
    }else{
        Elf64_Shdr* headerTable = (Elf64_Shdr *) sectionHeaderTable;
        flags = headerTable[index].sh_flags;
    }

    /*
    *Warning: In my system the char* variables are initialized to 0 by default but I should 
    * take care of those which don't do this:
    */
    memset(flagNames, 0, 16);

    uint64_t flagCopy = flags;
    if(flags & SHF_WRITE){
        sprintf(flagNames, "%s%c", flagNames, 'W');
        flagCopy = flagCopy ^ SHF_WRITE;
    }
    if(flags & SHF_ALLOC){
        sprintf(flagNames, "%s%c", flagNames, 'A');
        flagCopy = flagCopy ^ SHF_ALLOC;
    }
    if(flags & SHF_EXECINSTR){
        sprintf(flagNames, "%s%c", flagNames, 'X');
        flagCopy = flagCopy ^ SHF_EXECINSTR;
    }
    if(flags & SHF_MERGE){
        sprintf(flagNames, "%s%c", flagNames, 'M');
        flagCopy = flagCopy ^ SHF_MERGE;
    }
    if(flags & SHF_STRINGS){
        sprintf(flagNames, "%s%c", flagNames, 'S');
        flagCopy = flagCopy ^ SHF_STRINGS;
    }
    if(flags & SHF_INFO_LINK){
        sprintf(flagNames, "%s%c", flagNames, 'I');
        flagCopy = flagCopy ^ SHF_INFO_LINK;
    }
    if(flags & SHF_LINK_ORDER){
        sprintf(flagNames, "%s%c", flagNames, 'L');
        flagCopy = flagCopy ^ SHF_LINK_ORDER;
    }
    if(flags & SHF_GROUP){
        sprintf(flagNames, "%s%c", flagNames, 'G');
        flagCopy = flagCopy ^ SHF_GROUP;
    }
    if(flags & SHF_TLS){
        sprintf(flagNames, "%s%c", flagNames, 'T');
        flagCopy = flagCopy ^ SHF_TLS;
    }
    if(flags & SHF_EXCLUDE){
        sprintf(flagNames, "%s%c", flagNames, 'E');
        flagCopy = flagCopy ^ SHF_EXCLUDE;
    }
    if(flags & SHF_OS_NONCONFORMING){
        sprintf(flagNames, "%s%c", flagNames, 'O');
        flagCopy = flagCopy ^ SHF_OS_NONCONFORMING;
    }
    if(flags & SHF_MASKOS){
        sprintf(flagNames, "%s%c", flagNames, 'o');
        flagCopy = flagCopy ^ PF_MASKOS;
    }
    if(flags & SHF_MASKPROC){
        sprintf(flagNames, "%s%c", flagNames, 'p');
        flagCopy = flagCopy ^ SHF_MASKPROC;
    }
    if(flags & SHF_AMD64_LARGE){
        sprintf(flagNames, "%s%c", flagNames, 'l');
        flagCopy = flagCopy ^ SHF_AMD64_LARGE;
    }

    /*
    *   If we have any one bit in flagCopy, it means we have an unknown flag.
    */
    if(flagCopy != 0){
        sprintf(flagNames, "%s%c", flagNames, 'x');
        flagCopy = flagCopy ^ flagCopy;
    }

    flagNames[15] = 0;
    return flagNames;
}

const char* footer(){
    return "Key to Flags:\n  W (write), A (alloc), X (execute), M (merge), S (strings), l (large)\n  I (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)\n  O (extra OS processing required) o (OS specific), p (processor specific)";
}

uint32_t sLink(void* sectionHeaderTable, uint64_t index){
    uint32_t link = 0;
    if(is32Bit()){
        Elf32_Shdr* headerTable = (Elf32_Shdr *) sectionHeaderTable;   
        link = headerTable[index].sh_link;
    }else{
        Elf64_Shdr* headerTable = (Elf64_Shdr *) sectionHeaderTable;
        link = headerTable[index].sh_link;
    }
    return link;
}

uint64_t sInfo(void* sectionHeaderTable, uint64_t index){
    uint64_t info = 0;
    if(is32Bit()){
        Elf32_Shdr* headerTable = (Elf32_Shdr *) sectionHeaderTable;   
        info = headerTable[index].sh_info;
    }else{
        Elf64_Shdr* headerTable = (Elf64_Shdr *) sectionHeaderTable;
        info = headerTable[index].sh_info;
    }
    return info;
}

uint64_t sAlign(void* sectionHeaderTable, uint64_t index){
    uint64_t align = 0;
    if(is32Bit()){
        Elf32_Shdr* headerTable = (Elf32_Shdr *) sectionHeaderTable;   
        align = headerTable[index].sh_addralign;
    }else{
        Elf64_Shdr* headerTable = (Elf64_Shdr *) sectionHeaderTable;
        align = headerTable[index].sh_addralign;
    }
    return align;
}