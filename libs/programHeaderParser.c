#include "../headers/programHeaderParser.h"


/*
*   Load a segment from given file into memory and returns its address to you.
*   *NOTE: This function doesn't handle endinness and the upper layer (caller) should 
*           take care of it on its own.
*   We have two mode for this function:
*       1. Initialization: if you pass 'start' & 'size' as 0 then we initialize the inner
*           file pointer.
*       2. Usage: It's obvious your requested 'size' shouldn't be 0 because if your pass 0 
*           as your 'size', you mean read 0 bytes and we return Null to you. otherwise we read
*           'size' bytes from 'start' of file and then return the address of data to you.
*/
void* loadSegment(FILE* fd, uint64_t start, uint64_t size){
    static FILE* elfFile = NULL;
    if(size == 0 && start == 0)
        elfFile = fd;
    if(size){
        char* segment = calloc(size, 1);
        fseek(elfFile, start, SEEK_SET);
        fread(segment, size, 1, elfFile);
        return segment;
    }
    return NULL;
}

Elf32_Phdr* correctEndianness32bitPH(Elf32_Phdr* programHeader){
    if(isBigEndian()){
        programHeader->p_type = be32toh(programHeader->p_type);
        programHeader->p_offset = be32toh(programHeader->p_offset);
        programHeader->p_vaddr = be32toh(programHeader->p_vaddr);
        programHeader->p_paddr = be32toh(programHeader->p_paddr);
        programHeader->p_filesz = be32toh(programHeader->p_filesz);
        programHeader->p_memsz = be32toh(programHeader->p_memsz);
        programHeader->p_flags = be32toh(programHeader->p_flags);
        programHeader->p_align = be32toh(programHeader->p_align);
    }else{
        programHeader->p_type = le32toh(programHeader->p_type);
        programHeader->p_offset = le32toh(programHeader->p_offset);
        programHeader->p_vaddr = le32toh(programHeader->p_vaddr);
        programHeader->p_paddr = le32toh(programHeader->p_paddr);
        programHeader->p_filesz = le32toh(programHeader->p_filesz);
        programHeader->p_memsz = le32toh(programHeader->p_memsz);
        programHeader->p_flags = le32toh(programHeader->p_flags);
        programHeader->p_align = le32toh(programHeader->p_align);
    }
    return programHeader;
}

Elf64_Phdr* correctEndianness64bitPH(Elf64_Phdr* programHeader){
    if(isBigEndian()){
        programHeader->p_type = be32toh(programHeader->p_type);
        programHeader->p_offset = be32toh(programHeader->p_offset);
        programHeader->p_vaddr = be64toh(programHeader->p_vaddr);
        programHeader->p_paddr = be64toh(programHeader->p_paddr);
        programHeader->p_filesz = be64toh(programHeader->p_filesz);
        programHeader->p_memsz = be64toh(programHeader->p_memsz);
        programHeader->p_flags = be64toh(programHeader->p_flags);
        programHeader->p_align = be64toh(programHeader->p_align);
    }else{
        programHeader->p_type = le32toh(programHeader->p_type);
        programHeader->p_offset = le32toh(programHeader->p_offset);
        programHeader->p_vaddr = le64toh(programHeader->p_vaddr);
        programHeader->p_paddr = le64toh(programHeader->p_paddr);
        programHeader->p_filesz = le64toh(programHeader->p_filesz);
        programHeader->p_memsz = le64toh(programHeader->p_memsz);
        programHeader->p_flags = le64toh(programHeader->p_flags);
        programHeader->p_align = le64toh(programHeader->p_align);
    }
    return programHeader;
}

Elf64_Phdr* parseProgramHeader64Bit(Elf64_Ehdr* elfHeader, FILE* fd){
    if(elfHeader->e_phentsize != sizeof(Elf64_Phdr)){
        errno = 0;
        perror("Error: Wrong size of Program Header! No structure to hold the section header");
        return NULL;
    }

    if(programHeaderNumber == 0){
        errno = 0;
        perror("Error: Size of Program Header Table is not provided. Make sure you first parse SHT by calling parseSectionHeader() function!");
        return NULL;
    }

    //Jump to the Program Header Table in file:
    fseek(fd, elfHeader->e_phoff, SEEK_SET);

    Elf64_Phdr* programHeaderTable = calloc(programHeaderNumber, elfHeader->e_phentsize);

    for(uint32_t i = 0; i < programHeaderNumber; i++){
        fread(&programHeaderTable[i], sizeof(Elf64_Phdr), 1, fd);
        correctEndianness64bitPH(&programHeaderTable[i]);
    }

    return programHeaderTable;

}

Elf32_Phdr* parseProgramHeader32Bit(Elf32_Ehdr* elfHeader, FILE* fd){

    if(elfHeader->e_phentsize != sizeof(Elf32_Phdr)){
        errno = 0;
        perror("Error: Wrong size of Program Header! No structure to hold the section header");
        return NULL;
    }

    if(programHeaderNumber == 0){
        errno = 0;
        perror("Error: Size of Program Header Table is not provided. Make sure you first parse SHT by calling parseSectionHeader() function!");
        return NULL;
    }

    //Jump to the Program Header Table in file:
    fseek(fd, elfHeader->e_phoff, SEEK_SET);

    Elf32_Phdr* programHeaderTable = calloc(programHeaderNumber, elfHeader->e_phentsize);

    for(uint32_t i = 0; i < programHeaderNumber; i++){
        fread(&(programHeaderTable[i]), sizeof(Elf32_Phdr), 1, fd);
        correctEndianness32bitPH(&(programHeaderTable[i]));
    }

    return programHeaderTable;
}

void* parseProgramHeader(void* rawElfHeader, FILE* fd){

    //Initialize segment loader:
    loadSegment(fd, 0, 0);

    if(is32Bit()){
        Elf32_Ehdr* header = (Elf32_Ehdr *) rawElfHeader;
        if(header->e_phoff == 0 || header->e_phnum == 0){
            errno = 0;
            perror("Warning: No prgram header is provided!");
            return NULL;
        }
        Elf32_Phdr* programHeaderTable = parseProgramHeader32Bit(header, fd);
        return programHeaderTable;
    }else{
        Elf64_Ehdr* header = (Elf64_Ehdr *) rawElfHeader;
        if(header->e_phoff == 0 || header->e_phnum == 0){
            errno = 0;
            perror("Warning: No prgram header is provided!");
            return NULL;
        }
        Elf64_Phdr* programHeaderTable = parseProgramHeader64Bit(header, fd);
        return programHeaderTable;
    }
}