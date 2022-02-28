#include "../headers/elfHeaderParser.h"
#include <stdio.h>
#include <stdlib.h>


bool isELF64Bit = false;
bool isELFBigEndian = false;


bool is64Bit(){
    return isELF64Bit;
}

bool is32Bit(){
    return !isELF64Bit;
}

bool isBigEndian(){
    return isELFBigEndian;
}

bool isLittleEndian(){
    return !isELFBigEndian;
}

void* correctEndianness32bit(Elf32_Ehdr* header){
    if(isBigEndian()){
        header->e_type = be16toh(header->e_type);
        header->e_machine = be16toh(header->e_machine);
        header->e_version = be32toh(header->e_version);
        header->e_entry = be32toh(header->e_entry);
        header->e_phoff = be32toh(header->e_phoff);
        header->e_shoff = be32toh(header->e_shoff);
        header->e_flags = be32toh(header->e_flags);
        header->e_ehsize = be16toh(header->e_ehsize);
        header->e_phentsize = be16toh(header->e_phentsize);
        header->e_phnum = be16toh(header->e_phnum);
        header->e_shentsize = be16toh(header->e_shentsize);
        header->e_shnum = be16toh(header->e_shnum);
        header->e_shstrndx = be16toh(header->e_shstrndx);
    }else{
        header->e_type = le16toh(header->e_type);
        header->e_machine = le16toh(header->e_machine);
        header->e_version = le32toh(header->e_version);
        header->e_entry = le32toh(header->e_entry);
        header->e_phoff = le32toh(header->e_phoff);
        header->e_shoff = le32toh(header->e_shoff);
        header->e_flags = le32toh(header->e_flags);
        header->e_ehsize = le16toh(header->e_ehsize);
        header->e_phentsize = le16toh(header->e_phentsize);
        header->e_phnum = le16toh(header->e_phnum);
        header->e_shentsize = le16toh(header->e_shentsize);
        header->e_shnum = le16toh(header->e_shnum);
        header->e_shstrndx = le16toh(header->e_shstrndx);
    }
    return header;
}

void* correctEndianness64bit(Elf64_Ehdr* header){
    if(isBigEndian()){
        header->e_type = be16toh(header->e_type);
        header->e_machine = be16toh(header->e_machine);
        header->e_version = be32toh(header->e_version);
        header->e_entry = be64toh(header->e_entry);
        header->e_phoff = be64toh(header->e_phoff);
        header->e_shoff = be64toh(header->e_shoff);
        header->e_flags = be32toh(header->e_flags);
        header->e_ehsize = be16toh(header->e_ehsize);
        header->e_phentsize = be16toh(header->e_phentsize);
        header->e_phnum = be16toh(header->e_phnum);
        header->e_shentsize = be16toh(header->e_shentsize);
        header->e_shnum = be16toh(header->e_shnum);
        header->e_shstrndx = be16toh(header->e_shstrndx);
    }else{
        header->e_type = le16toh(header->e_type);
        header->e_machine = le16toh(header->e_machine);
        header->e_version = le32toh(header->e_version);
        header->e_entry = le64toh(header->e_entry);
        header->e_phoff = le64toh(header->e_phoff);
        header->e_shoff = le64toh(header->e_shoff);
        header->e_flags = le32toh(header->e_flags);
        header->e_ehsize = le16toh(header->e_ehsize);
        header->e_phentsize = le16toh(header->e_phentsize);
        header->e_phnum = le16toh(header->e_phnum);
        header->e_shentsize = le16toh(header->e_shentsize);
        header->e_shnum = le16toh(header->e_shnum);
        header->e_shstrndx = le16toh(header->e_shstrndx);
    }
    return header;
}

void* parseELFHeader(FILE* fd){
    
    //We assume we have a 32 bit ELF file. #1
    Elf32_Ehdr* header = calloc(1, sizeof(Elf32_Ehdr));
    
    //Read the file:
    fread(header, sizeof(Elf32_Ehdr), 1, fd);

    //Check if the file is an ELF file:
    if(memcmp(header->e_ident, ELFMAG, SELFMAG) != 0){
        errno = 0;
        perror("Error: The given file is not an ELF file, exiting...");
        return NULL;
    }

    //Set endianess of ELF file:
    if(header->e_ident[EI_DATA] == ELFDATA2LSB)
        isELFBigEndian = false;
    else 
        isELFBigEndian = true;

    //Check our assumption. #1
    if(header->e_ident[EI_CLASS] == ELFCLASS64){
        //The given file is a 64 bit elf file and our assumption was wrong
        Elf64_Ehdr* newHeader = calloc(1, sizeof(Elf64_Ehdr));

        //Copy the information which are read already.
        memcpy(newHeader, header, sizeof(Elf32_Ehdr));

        /*
        *   As we know the size of 64 bit header is more than 32 bit one, 
        *   we should copy remaining information:
        */
        //Since we want to move the header sizeof(ELF32_Ehdr) BYTES ahead, we need a byte pointer
        uint8_t* pointer = (uint8_t*) newHeader;
        fread(pointer + sizeof(Elf32_Ehdr), sizeof(Elf64_Ehdr) - sizeof(Elf32_Ehdr), 1, fd);

        isELF64Bit = true;

        //make free the allocated memories which are no more needed:
        free(header);


        correctEndianness64bit(newHeader);
        return newHeader;
    }else isELF64Bit = false;

    correctEndianness32bit(header);
    return header;
}