#include "../headers/sectionHeaderParser.h"
#include "../headers/programHeaderParser.h"


uint32_t programHeaderNumber = 0;
uint64_t sectionHeadersNumber = 0;
uint32_t sectionHeaderStringIndex = 0;
char* sectionStringTable = NULL;


/*
*   Returns `Sectio Size` field at specified index of SHT:
*/
uint64_t rawSSize(void* sectionHeaderTable, uint64_t index){
    if(is32Bit()){
        Elf32_Shdr* headerTable = (Elf32_Shdr *) sectionHeaderTable;
        return headerTable[index].sh_size;
    }else{
        Elf64_Shdr* headerTable = (Elf64_Shdr *) sectionHeaderTable;
        return headerTable[index].sh_size;
    }
}

/*
*   Returns `Section Offset` field at specified index of SHT:
*/
uint64_t rawSOffset(void* sectionHeaderTable, uint64_t index){
    if(is32Bit()){
        Elf32_Shdr* headerTable = (Elf32_Shdr *) sectionHeaderTable;
        return headerTable[index].sh_offset;
    }else{
        Elf64_Shdr* headerTable = (Elf64_Shdr *) sectionHeaderTable;
        return headerTable[index].sh_offset;
    }
}

/*
*   Returns `Section Address` field at specified index of SHT:
*/
uint64_t rawSAddress(void* sectionHeaderTable, uint64_t index){
    if(is32Bit()){
        Elf32_Shdr* headerTable = (Elf32_Shdr *) sectionHeaderTable;
        return headerTable[index].sh_addr;
    }else{
        Elf64_Shdr* headerTable = (Elf64_Shdr *) sectionHeaderTable;
        return headerTable[index].sh_addr;
    }
}

/*
*   Load a section from given file into memory and returns its address to you.
*   *NOTE: This function doesn't handle endinness and the upper layer (caller) should 
*           take care of it on its own.
*   We have two mode for this function:
*       1. Initialization: if you pass 'start' & 'size' as 0 then we initialize the inner
*           file descriptor. You can initialize it just once!
*       2. Usage: It's obvious your requested 'size' shouldn't be 0 because if your pass 0 
*           as your 'size', you mean read 0 bytes and we return Null to you. otherwise we read
*           'size' bytes from 'start' offset of file and then return the address of data to you.
*/
void* loadSection(FILE* fd, uint64_t start, uint64_t size){
    static FILE* elfFile = NULL;
    if(size == 0 && start == 0 && elfFile == NULL)
        elfFile = fd;
    if(size){
        char* section = calloc(size, 1);
        fseek(elfFile, start, SEEK_SET);
        fread(section, size, 1, elfFile);
        return section;
    }
    return NULL;
}

Elf64_Shdr* correctEndianness64bitSH(Elf64_Shdr* sectionHeader){
    if(isBigEndian()){
        sectionHeader->sh_name = be32toh(sectionHeader->sh_name);
        sectionHeader->sh_type = be32toh(sectionHeader->sh_type);
        sectionHeader->sh_flags = be64toh(sectionHeader->sh_flags);
        sectionHeader->sh_addr = be64toh(sectionHeader->sh_addr);
        sectionHeader->sh_offset = be64toh(sectionHeader->sh_offset);
        sectionHeader->sh_size = be64toh(sectionHeader->sh_size);
        sectionHeader->sh_link = be32toh(sectionHeader->sh_link);
        sectionHeader->sh_info = be32toh(sectionHeader->sh_info);
        sectionHeader->sh_addralign = be64toh(sectionHeader->sh_addralign);
        sectionHeader->sh_entsize = be64toh(sectionHeader->sh_entsize);
    }else{
        sectionHeader->sh_name = le32toh(sectionHeader->sh_name);
        sectionHeader->sh_type = le32toh(sectionHeader->sh_type);
        sectionHeader->sh_flags = le64toh(sectionHeader->sh_flags);
        sectionHeader->sh_addr = le64toh(sectionHeader->sh_addr);
        sectionHeader->sh_offset = le64toh(sectionHeader->sh_offset);
        sectionHeader->sh_size = le64toh(sectionHeader->sh_size);
        sectionHeader->sh_link = le32toh(sectionHeader->sh_link);
        sectionHeader->sh_info = le32toh(sectionHeader->sh_info);
        sectionHeader->sh_addralign = le64toh(sectionHeader->sh_addralign);
        sectionHeader->sh_entsize = le64toh(sectionHeader->sh_entsize);
    }
    return sectionHeader;
}

Elf32_Shdr* correctEndianness32bitSH(Elf32_Shdr* sectionHeader){
    if(isBigEndian()){
        sectionHeader->sh_name = be32toh(sectionHeader->sh_name);
        sectionHeader->sh_type = be32toh(sectionHeader->sh_type);
        sectionHeader->sh_flags = be32toh(sectionHeader->sh_flags);
        sectionHeader->sh_addr = be32toh(sectionHeader->sh_addr);
        sectionHeader->sh_offset = be32toh(sectionHeader->sh_offset);
        sectionHeader->sh_size = be32toh(sectionHeader->sh_size);
        sectionHeader->sh_link = be32toh(sectionHeader->sh_link);
        sectionHeader->sh_info = be32toh(sectionHeader->sh_info);
        sectionHeader->sh_addralign = be32toh(sectionHeader->sh_addralign);
        sectionHeader->sh_entsize = be32toh(sectionHeader->sh_entsize);
    }else{
        sectionHeader->sh_name = le32toh(sectionHeader->sh_name);
        sectionHeader->sh_type = le32toh(sectionHeader->sh_type);
        sectionHeader->sh_flags = le32toh(sectionHeader->sh_flags);
        sectionHeader->sh_addr = le32toh(sectionHeader->sh_addr);
        sectionHeader->sh_offset = le32toh(sectionHeader->sh_offset);
        sectionHeader->sh_size = le32toh(sectionHeader->sh_size);
        sectionHeader->sh_link = le32toh(sectionHeader->sh_link);
        sectionHeader->sh_info = le32toh(sectionHeader->sh_info);
        sectionHeader->sh_addralign = le32toh(sectionHeader->sh_addralign);
        sectionHeader->sh_entsize = le32toh(sectionHeader->sh_entsize);
    }
    return sectionHeader;
}

Elf64_Shdr* parseSectionHeader64Bit(Elf64_Ehdr* elfHeader, FILE* fd){
    //Check size of entries
    if(elfHeader->e_shentsize != sizeof(Elf64_Shdr)){
        errno = 0;
        perror("Error: Wrong size of section header! No structure to hold the section header.");
        return NULL;
    }

    //Jump to section table in elf file:
    fseek(fd, elfHeader->e_shoff, SEEK_SET);

    /*
    *   We should pre-fetch the first entry of section table because some of information 
    *       such as sh_size, sh_link, sh_info are placed there and they can effect how we should
    *       process the section header table.
    *   * Read first entry of section header table:
    */
    Elf64_Shdr* firstEntry = calloc(1, sizeof(Elf64_Shdr));
    fread(firstEntry, sizeof(Elf64_Shdr), 1, fd);

    //Take care of alignment:
    correctEndianness64bitSH(firstEntry);

    //Get number of entries in section header table.
    if(elfHeader->e_shnum == 0){
        //Number of entries is stored in sh_shize of first entry:
        sectionHeadersNumber = firstEntry->sh_size;
    }else
        sectionHeadersNumber = elfHeader->e_shnum;

    //Get Real index of Section header string index table:
    if(elfHeader->e_shstrndx == SHN_UNDEF){
        errno = 0;
        perror("Warning: section names are not provided! Continue parsing SHT without names...");
    }else if(elfHeader->e_shstrndx == SHN_XINDEX){
        //The real value of e_shstrndx is sotred in sh_link of first entry.
        sectionHeaderStringIndex = firstEntry->sh_link;
    }else
        sectionHeaderStringIndex = elfHeader->e_shstrndx;

    //Check for real value of program header number:
    if(elfHeader->e_phnum == PN_XNUM)
        //The real value of e_phnum is sotred in sh_info of first entry.
        programHeaderNumber = firstEntry->sh_info;
    else
        programHeaderNumber = elfHeader->e_phnum;

    //Allocate space for section headers table.
    Elf64_Shdr* sectionHeaderTable = calloc(sectionHeadersNumber, elfHeader->e_shentsize);

    /*
    *   We have read the initial entry already, so we copy it into table:
    */
    memcpy(&sectionHeaderTable[0], firstEntry, sizeof(Elf64_Shdr));
    
    //Prevent memory leak:
    free(firstEntry);

    /*
    *   Read section headers one by one and process them:
    *       1. Start from 1 because we have read already the first entry in the section header.
    */
    for(long long int i = 1; i < sectionHeadersNumber; i++){
        fread(&(sectionHeaderTable[i]), sizeof(Elf64_Shdr), 1, fd);
        //Take care of endianness:
        correctEndianness64bitSH(&(sectionHeaderTable[i]));
    }

    /*
    *   Load Section String Table into the memory:
    */
    if(sectionHeaderStringIndex != SHN_UNDEF){
        Elf64_Shdr sectionHeaderStringTable = sectionHeaderTable[sectionHeaderStringIndex];
        //Jump to section string table in elf file:
        fseek(fd, sectionHeaderStringTable.sh_offset, SEEK_SET);
        sectionStringTable = calloc(1, sectionHeaderStringTable.sh_size);
        fread(sectionStringTable, sectionHeaderStringTable.sh_size, 1, fd);
    }

    return sectionHeaderTable;
}

Elf32_Shdr* parseSectionHeader32Bit(Elf32_Ehdr* elfHeader, FILE* fd){
    //Check size of entries
    if(elfHeader->e_shentsize != sizeof(Elf32_Shdr)){
        errno = 0;
        perror("Error: Wrong size of section header! No structure to hold the section header.");
        return NULL;
    }

    //Jump to section table in elf file:
    fseek(fd, elfHeader->e_shoff, SEEK_SET);

    /*
    *   We should pre-fetch the first entry of section table because some of information 
    *       such as sh_size, sh_link, sh_info are placed there and they can effect how we should
    *       process the section header table.
    *   * Read first entry of section header table:
    */
    Elf32_Shdr* firstEntry = calloc(1, sizeof(Elf32_Shdr));
    fread(firstEntry, sizeof(Elf32_Shdr), 1, fd);

    //Take care of alignment:
    correctEndianness32bitSH(firstEntry);

    //Get number of entries in section header table.
    if(elfHeader->e_shnum == 0){
        //Number of entries is stored in sh_size of first entry.
        sectionHeadersNumber = firstEntry->sh_size;
    }else
        sectionHeadersNumber = elfHeader->e_shnum;

    //Get Real index of Section header string index table
    if(elfHeader->e_shstrndx == SHN_UNDEF){
        errno = 0;
        perror("Warning: section names are not provided! Continue parsing SHT without names...");
    }else if(elfHeader->e_shstrndx == SHN_XINDEX){
        //The real value of e_shstrndx is sotred in sh_link of first entry.
        sectionHeaderStringIndex = firstEntry->sh_link;
    }else
        sectionHeaderStringIndex = elfHeader->e_shstrndx;

    //Check for real value of program header number:
    if(elfHeader->e_phnum == PN_XNUM)
        //The real value of e_phnum is sotred in sh_info of first entry.
        programHeaderNumber = firstEntry->sh_info;
    else
        programHeaderNumber = elfHeader->e_phnum;

    //Allocate space for section headers table.
    Elf32_Shdr* sectionHeaderTable = calloc(sectionHeadersNumber, elfHeader->e_shentsize);

    /*
    *   We have read the initial entry already, so we copy it into table:
    */
    memcpy(&sectionHeaderTable[0], firstEntry, sizeof(Elf32_Shdr));
    
    //Prevent memory leak:
    free(firstEntry);

    /*
    *   Read section headers one by one and process them:
    *       1. Start from 1 because we have read already the first entry in the section header.
    */
    for(long long int i = 1; i < sectionHeadersNumber; i++){
        fread(&(sectionHeaderTable[i]), sizeof(Elf32_Shdr), 1, fd);
        //Take care of endianness:
        correctEndianness32bitSH(&(sectionHeaderTable[i]));
    }

    /*
    *   Load Section String Table into the memory:
    */
    if(sectionHeaderStringIndex != SHN_UNDEF){
        Elf32_Shdr sectionHeaderStringTable = sectionHeaderTable[sectionHeaderStringIndex];
        //Jump to section string table in elf file:
        fseek(fd, sectionHeaderStringTable.sh_offset, SEEK_SET);
        sectionStringTable = calloc(1, sectionHeaderStringTable.sh_size);
        fread(sectionStringTable, sectionHeaderStringTable.sh_size, 1, fd);
    }
    return sectionHeaderTable;
}

void* parseSectionHeader(void* rawElfHeader, FILE* fd){
    /*
    *   Initialize section loader.
    */
    loadSection(fd, 0, 0);

    if(is32Bit()){
        Elf32_Ehdr* elfHeader = (Elf32_Ehdr *) rawElfHeader;
        if(elfHeader->e_shoff == 0){
            errno = 0;
            perror("Warning: No section header is provided!");
            return NULL;
        }
        Elf32_Shdr* sectionHeader = parseSectionHeader32Bit(elfHeader, fd);
        return sectionHeader;
    }else{
        Elf64_Ehdr* elfHeader = (Elf64_Ehdr *) rawElfHeader;
        if(elfHeader->e_shoff == 0){
            errno = 0;
            perror("Warning: No section header is provided!");
            return NULL;
        }
        Elf64_Shdr* sectionHeader = parseSectionHeader64Bit(elfHeader, fd);
        return sectionHeader;
    }
}