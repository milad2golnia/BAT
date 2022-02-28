#ifndef __SYMBOLTABLE__INCLUDED__
#define __SYMBOLTABLE__INCLUDED__


#include <elf.h>
#include "./sectionHeaderParser.h"
#include "./displaySectionHeader.h"
/*
*   Unfortunately we are forced to accept this cyclic dependency by adding this header here.
*   NOTE: We need this header to resolve the symbol names easier.
*/
#include "displaySymbolTable.h"


/*
*   Structure to keep symbolTable information.
*/
typedef struct symbolTableInfo{
    /*
    *   Represent number of entries in Symbol Table:
    */
    uint64_t entriesCount;

    /*
    *   The String Table which helps to resolve name of symbols in this table.   
    */
    const char* symbolStringTable;

    /*
    *   Contains the name of symbol table, It's usually '.symtab' or '.dynsym'
    */
    char* symbolTableName;

    /*
    *   Points to actual Symbol Table
    */
    void* tablePointer;

    /*
    *   Not used yet, just considered for future needs.
    *   NOTE: Currently, we assume there are just two symbol tables inside ELF file and hence
    *           we can store the symbol tables into an array! that's why we don't
    *           need this field yet.
    *         In another words, this field give us this flexibility to implement too many 
    *           unspecific symbol tables by a linked list instead of an array.
    *   NOTE: It should be filled anyway because this way you can find number of extracted
    *           Symbol Tables.
    *   Points to next Symbol Table:
    */
    struct symbolTableInfo* next;
}symbolTableInfo;


/*
*   Load Symbol String Table into memory and returns its pointer to you.
*   NOTE: This function gets a Section Header Table and if there was a section header
*           with `.strtab`/`.dynstr`, it is considered as Symbol String Table. So this function is just
*           concerned with those sections which are called '.strtab'/'.dynstr'.
*   NOTE: We get the size through argument so we don't need to process all of SHT always! Upper
*           layer(caller) can just pass the '.strtab'/'.dynstr' with size = 1 to make the process fast.
*   @param {const char *} sstName - Name of Symbol String Table you are looking for.
*/
const char* loadSymbolTableString(void* SHT, uint64_t size, const char* sstName);

/*
*   Extract symbol table and returns it.
*   Given a SHT, it looks for a section header with '.symtab'/'dynsym' name. If there was one, it will 
*       read the symbol table and returns the result to you.
*   Warning: The given SHT should contians the corresponding String Table too. E.g. if you
*               want to parse the '.symtab', you should provide 'strtab' too inside SHT.
*   NOTE: We don't do any processing of symbol table! we just returns the content to you.
*           To parse the Symbol Table(ST) please use displaySymbolTable library.
*   NOTE: You should pass the size of SHT too. This give you this flexibility to parse the 
*           Symbol Table directly without any extra search.
*/
symbolTableInfo* parseSymbolTable(void* SHT, uint64_t size);

/*
*   This is an inner function. DON'T Call it directly!
*/
symbolTableInfo parseSymbolTable32bit(const Elf32_Shdr symbolTableHeader);

/*
*   This is an inner function. DON'T Call it directly!
*/
symbolTableInfo parseSymbolTable64bit(const Elf64_Shdr symbolTableHeader);

/*
*   Correct endianness of one Symbol Table Entry for 32-bit classes of ELF:
*/
Elf32_Sym* correctEndianness32bitST(Elf32_Sym* entry);

/*
*   Correct endianness of one Symbol Table Entry for 64-bit classes of ELF:
*/
Elf64_Sym* correctEndianness64bitST(Elf64_Sym* entry);

/*
*   This function get a Symbol Table and returns those symbols which have 'TYPE' equal to
*       given type in a new Symbol Table.
*   NOTE: You should use freeFiltered() function to free the allocated memory by this function.
            Don't free the result neither using freeSymbolTables() function nor by hand.
            Also by freeing the original Symbol Table you may destroy this Symbol Table too, so
            make sure you free the original Symbol Table after freeing this Symbol Table.
*   @param original -   The Symbol Table which you want to process its symbols.
*   @param type     -   The type of symbols which you are look for them.
*/
symbolTableInfo filterSymbols(symbolTableInfo original, uint64_t type);

/*
*   Returns the type of symbol at offset of 'index' from beginning of the table without any 
*       extra interpretation.
*/
uint64_t rawSTType(const void* symbolTable, uint64_t index);

/*
*   Conduct filtering on 32 bit Symbol Table.
*   NOTE: This is an inner function, don't call it directly!
*/
Elf32_Sym* filterSymbols32Bit(Elf32_Sym* symbolTable, uint64_t type, uint64_t size,
                                uint64_t* newSize);

/*
*   Conduct filtering on 64 bit Symbol Table.
*   NOTE: This is an inner function, don't call it directly.
*/
Elf64_Sym* filterSymbols64Bit(Elf64_Sym* symbolTable, uint64_t type, uint64_t size, 
                                uint64_t* newSize);

/*
*   Returns the value of the symbol in given Symbol Table which is located at 'index' offset
*       from beginning of the Symbol Table.
*   @param symbolTable  -   Target Symbol Table.
*   @param index        -   Index of symbol in Symbol Table.
*/
uint64_t rawSTValue(const void* symbolTable, uint64_t index);

/*
*   Update the value of symbol in 'index' offset of Symbol Table.
*   @param symbolTable  -   Target Symbol Table.
*   @param index        -   Index of symbol in Symbol Table.
*   @param value        -   The new value of symbols value.
*/
void setSTValue(void* symbolTable, uint64_t index, uint64_t value);

/*
*   Get a symbol name and a Symbol Table then tries to return the corresponding value of 
*       that symbol.
*   NOTE: You can use this function to reach address of function according their names.
*   @param  name    -   Name of symbol which you look for its value.
*   @param st   -   Symbol Table which contains the definition of this symbol.
*/
uint64_t resolveName(char* name, symbolTableInfo st);

/*
*   Get an value and a Symbol Table then tries to return the corresponding symbol name
*       of that value.
*   NOTE: You can use this function to reach name of functions according to their addresses.
*   @param value  -   Value of symbol which you look for its name.
*   @param st   -   Symbol Table which contains the definition of this symbol.
*/
const char* resolveValue(uint64_t value, symbolTableInfo st);


#endif