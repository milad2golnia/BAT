#include "../headers/displaySymbolTable.h"


const char* const stName(const void* symbolTable, uint64_t index, const char* symbolStringTable){
    /*
    *   To extract the name of symbol we need Symbol String Table:
    */
    if(symbolStringTable == NULL){
        errno = ECANCELED;
        perror("Error! Symbol String Table is not loaded, please make sure to call loadSymbolTableString() function");
        return NULL;
    }
    /*
    *   Extract index to Symbol String Table:
    */
    uint64_t nameIndex = 0;
    if(is32Bit()){
        Elf32_Sym* st = (Elf32_Sym *) symbolTable;
        nameIndex = st[index].st_name;
    }else{
        Elf64_Sym* st = (Elf64_Sym *) symbolTable;
        nameIndex = st[index].st_name;
    }
    /*
    *   Return name of symbol:
    */
    return &(symbolStringTable[nameIndex]);
}

const char* stType(const void* symbolTable, uint64_t index){
    uint64_t type;
    if(is32Bit()){
        Elf32_Sym* st = (Elf32_Sym *) symbolTable;
        type = ELF32_ST_TYPE(st[index].st_info);
    }else{
        Elf64_Sym* st = (Elf64_Sym *) symbolTable;
        type = ELF64_ST_TYPE(st[index].st_info);
    }

    if(type == STT_FUNC){
        return "FUNCTION";
    }else
        return "NOT DEVELOPED";        
}

uint16_t stSHTIndex(const void* symbolTable, uint64_t index){
    if(is32Bit()){
        Elf32_Sym* st = (Elf32_Sym *) symbolTable;
        return st[index].st_shndx;
    }else{
        Elf64_Sym* st = (Elf64_Sym *) symbolTable;
        return st[index].st_shndx;
    }
}

char* stValue(const void* symbolTable, uint64_t index){
    char* value = NULL;
    if(is32Bit()){
        Elf32_Sym* st = (Elf32_Sym *) symbolTable;
    
        /*
        *   Allocate necessary information: 
        *   1. 32 bit = 8 hex digits.
        *   2. 0x = 2 byte.
        *   3. NULL Byte = 1
        *   TOTAL = 2 + 8 + 1= 11  
        */
        value = calloc(11, 1);

        sprintf(value, "0x%08x", st[index].st_value);
    }else{
        Elf64_Sym* st = (Elf64_Sym *) symbolTable;
        
        /*
        *   Allocate necessary information:
        *   1. 64 bit = 16 hex digits.
        *   2. 0x = 2 bytes.
        *   3. NULL Byte = 1
        *   TOTAL = 16 + 2 + 1 = 19
        */
        value = calloc(19, 1);

        sprintf(value, "0x%016x", st[index].st_value);
    }
    return value;
}


char* stSize(const void* symbolTable, uint64_t index){
    char* value = NULL;
    if(is32Bit()){
        Elf32_Sym* st = (Elf32_Sym *) symbolTable;
    
        /*
        *   We show st_size in decimal base because we want to adhere `readelf --syms` style:
        *   1. 2^32 = 10 decimal digit.
        *   2. NULL Byte = 1.
        *   TOTAL = 10 + 1 = 11
        */
        value = calloc(11, 1);

        sprintf(value, "%d", st[index].st_size);
    }else{
        Elf64_Sym* st = (Elf64_Sym *) symbolTable;
        
        /*
        *   We show st_size in decimal base because we want to adhere `readelf --syms` style:
        *   1. 2^64 = 20 decimal digit.
        *   2. NULL Byte = 1.
        *   TOTAL = 20 + 1 = 21
        */
        value = calloc(21, 1);

        sprintf(value, "%d", st[index].st_size);
    }
    return value;

}