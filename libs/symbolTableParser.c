#include "../headers/symbolTableParser.h"



uint64_t rawSTType(const void* symbolTable, uint64_t index){
    uint64_t type;
    if(is32Bit()){
        Elf32_Sym* st = (Elf32_Sym *) symbolTable;
        type = ELF32_ST_TYPE(st[index].st_info);
    }else{
        Elf64_Sym* st = (Elf64_Sym *) symbolTable;
        type = ELF64_ST_TYPE(st[index].st_info);
    }
    return type;       
}

const char* loadSymbolTableString(void* SHT, uint64_t size, const char* sstName){

    for (size_t i = 0; i < size; i++)
    {
        if(strcmp(sstName, sName(SHT, i)) == 0){
            //We found Symbol Table String, let's load it:
            return loadSection(NULL, rawSOffset(SHT, i), rawSSize(SHT, i));
        }
    }
    return NULL;
}

Elf32_Sym* correctEndianness32bitST(Elf32_Sym* entry){
    if(isBigEndian()){
        entry->st_name = be32toh(entry->st_name);
        entry->st_value = be32toh(entry->st_value);
        entry->st_size = be32toh(entry->st_size);
        entry->st_shndx = be16toh(entry->st_shndx);
    }else{
        entry->st_name = le32toh(entry->st_name);
        entry->st_value = le32toh(entry->st_value);
        entry->st_size = le32toh(entry->st_size);
        entry->st_shndx = le16toh(entry->st_shndx);
    }
    return entry;
}

Elf64_Sym* correctEndianness64bitST(Elf64_Sym* entry){
    if(isBigEndian()){
        entry->st_name = be32toh(entry->st_name);
        entry->st_value = be64toh(entry->st_value);
        entry->st_size = be64toh(entry->st_size);
        entry->st_shndx = be16toh(entry->st_shndx);
    }else{
        entry->st_name = le32toh(entry->st_name);
        entry->st_value = le64toh(entry->st_value);
        entry->st_size = le64toh(entry->st_size);
        entry->st_shndx = le16toh(entry->st_shndx);
    }
    return entry;
}

symbolTableInfo parseSymbolTable32bit(const Elf32_Shdr symbolTableHeader){
    symbolTableInfo result = {-1, NULL, NULL};

    /*
    *   Check if we have suitable structure to store the Symbol Table:
    */
    if(symbolTableHeader.sh_entsize != sizeof(Elf32_Sym)){
        errno = EOVERFLOW;
        perror("Error! Unable to parse Symbol Table");
        return result;
    }

    /*
    *   Compute number of entries in Symbol Table:
    */
    uint64_t numberOfEntries = symbolTableHeader.sh_size / symbolTableHeader.sh_entsize;
    result.entriesCount = numberOfEntries;

    /*
    *   Load Symbol Table:
    */
    Elf32_Sym* symbolTable = 
        (Elf32_Sym*) loadSection(NULL, symbolTableHeader.sh_offset, 
                                    numberOfEntries * sizeof(Elf32_Sym));

    /*
    *   Take care of endianness:
    */
    for(uint64_t i = 0; i < numberOfEntries; i++){
        correctEndianness32bitST(symbolTable + i);
    }
    result.tablePointer = symbolTable;
    
    return result;
}

symbolTableInfo parseSymbolTable64bit(const Elf64_Shdr symbolTableHeader){
    symbolTableInfo result = {-1, NULL, NULL};

    /*
    *   Check if we have suitable structure to store the Symbol Table:
    */
    if(symbolTableHeader.sh_entsize != sizeof(Elf64_Sym)){
        errno = EOVERFLOW;
        perror("Error! Unable to parse Symbol Table");
        return result;
    }

    /*
    *   Compute number of entries in Symbol Table:
    */
    uint64_t numberOfEntries = symbolTableHeader.sh_size / symbolTableHeader.sh_entsize;
    result.entriesCount = numberOfEntries;

    /*
    *   Load Symbol Table:
    */
    Elf64_Sym* symbolTable = 
        (Elf64_Sym*) loadSection(NULL, symbolTableHeader.sh_offset, 
                                    numberOfEntries * sizeof(Elf64_Sym));
    
    /*
    *   Take care of endianness:
    */
    for(uint64_t i = 0; i < numberOfEntries; i++){
        correctEndianness64bitST(symbolTable + i);
    }
    result.tablePointer = symbolTable;

    return result;
}

symbolTableInfo* parseSymbolTable(void* SHT, uint64_t size){
    /*
    *   Currently we are just concerned about .symtab and .dynsym hence we just allocate
    *       two members.
    */
    symbolTableInfo* sti = calloc(2, sizeof(symbolTableInfo));
    symbolTableInfo* iterator = sti;
    symbolTableInfo symbolTable;

    for(uint64_t i = 0; i < size; i++){
        if(strcmp(".symtab", sName(SHT, i)) == 0 || 
            strcmp(".dynsym", sName(SHT, i)) == 0){
            //We found Symbol Table, Let's extract and return it:

            /*
            *   Check ELF class and parse the symbol table respecting it:
            */
            if(is32Bit()){
                Elf32_Shdr* sht = (Elf32_Shdr*) SHT;
                symbolTable = parseSymbolTable32bit(sht[i]);
            }else{
                Elf64_Shdr* sht = (Elf64_Shdr*) SHT;
                symbolTable = parseSymbolTable64bit(sht[i]);
            }

            //Update name of this Symbol Table:
            symbolTable.symbolTableName = sName(SHT, i);

            //Load corresponding Symbol String Table:
            if(strcmp(".symtab", sName(SHT, i)) == 0)
                symbolTable.symbolStringTable = loadSymbolTableString(SHT, size, ".strtab");
            else
                symbolTable.symbolStringTable = loadSymbolTableString(SHT, size, ".dynstr");

            //Update 'next' field:
            symbolTable.next = iterator + 1;

            //Store symbol table:
            (*iterator++) = symbolTable;
        }
    }

    //Indicate end of Symbol Tables:
    (iterator - 1)->next = NULL;
    return sti;
}

Elf32_Sym* filterSymbols32Bit(Elf32_Sym* symbolTable, uint64_t type, uint64_t size, uint64_t* newSize){
    /*
    *   To speed up the process, we first recognize target symbols and store them into stack:
    */
    Elf32_Sym filtered[size];
    int index = 0;

    /*
    *   Do filtering:
    */
    for (size_t i = 0; i < size; i++)
    {
        if(rawSTType(symbolTable, i) == type){
            filtered[index++] = symbolTable[i];
        }
    }

    //Allocate memory for filtered symbols and copy them:
    Elf32_Sym* result = calloc(index, sizeof(Elf32_Sym));
    for (size_t i = 0; i < index; i++)
    {
        result[i] = filtered[i];
    }
    
    /*
    *   Update size of new Symbol Table:
    */
    *newSize = index;
    
    return result;
}

Elf64_Sym* filterSymbols64Bit(Elf64_Sym* symbolTable, uint64_t type, uint64_t size, uint64_t* newSize){
    /*
    *   To speed up the process, we first recognize target symbols and store them into stack:
    */
    Elf64_Sym filtered[size];
    int index = 0;

    /*
    *   Do filtering:
    */
    for (size_t i = 0; i < size; i++)
    {
        if(rawSTType(symbolTable, i) == type){
            filtered[index++] = symbolTable[i];
        }
    }

    //Allocate memory for filtered symbols and copy them:
    Elf64_Sym* result = calloc(index, sizeof(Elf64_Sym));
    for (size_t i = 0; i < index; i++)
    {
        result[i] = filtered[i];
    }

    /*
    *   Update size of new Symbol Table:
    */
    *newSize = index;

    return result;
}

symbolTableInfo filterSymbols(symbolTableInfo original, uint64_t type){
    symbolTableInfo filtered = {-1, NULL, NULL, NULL, NULL};
    filtered.symbolStringTable = original.symbolStringTable;
    filtered.symbolTableName = original.symbolTableName;
    
    if(is32Bit()){
        filtered.tablePointer = filterSymbols32Bit(original.tablePointer, type, 
                                                    original.entriesCount, &(filtered.entriesCount));
    }else{
        filtered.tablePointer = filterSymbols64Bit(original.tablePointer, type, 
                                                    original.entriesCount, &(filtered.entriesCount));
    }
    
    return filtered;
}

uint64_t rawSTValue(const void* symbolTable, uint64_t index){
    if(is32Bit()){
        const Elf32_Sym* st = symbolTable;
        return st[index].st_value;
    }else{
        const Elf64_Sym* st = symbolTable;
        return st[index].st_value;
    }
}

void setSTValue(void* symbolTable, uint64_t index, uint64_t value){
    if(is32Bit()){
        Elf32_Sym* st = symbolTable;
        st[index].st_value = value;
    }else{
        Elf64_Sym* st = symbolTable;
        st[index].st_value = value;
    }
}

uint64_t resolveName(char* name, symbolTableInfo st){
    for (size_t i = 0; i < st.entriesCount; i++)
    {
        if(strcmp(stName(st.tablePointer, i, st.symbolStringTable), name) == 0){
            return rawSTValue(st.tablePointer, i);
        }
    }
    return -1;
}

const char* resolveValue(uint64_t value, symbolTableInfo st){
    for (size_t i = 0; i < st.entriesCount; i++)
    {
        if(rawSTValue(st.tablePointer, i) == value){
            return stName(st.tablePointer, i, st.symbolStringTable);
        }
    }
    return NULL;
}