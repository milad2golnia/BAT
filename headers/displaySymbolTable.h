#ifndef __DISPLAYSYMBOLTABLE__INCLUDED__
#define __DISPLAYSYMBOLTABLE__INCLUDED__

/*
*           =======>        UNDER DEVELOPMENT       <======
* NOTE: This header is not developed fully! It's under development and at the moment
*       it just interprets least needed information.
* We complete it if we need to display Symbol Table (ST) otherwise we postpone its development
*   till after SSS course.
*/


#include <elf.h>
#include "./symbolTableParser.h"


/*
*   Returns name of symbol at index-th entry of symbol table
*/
const char* const stName(const void* symbolTable, uint64_t index, const char* symbolStringTable); 

/*
*   Returns type of symbol at index-th entry of symbol table.
*   NOTE: We developed this function for extracting CALL-GRAPH and hence at the moment we
*           are just concerned with FUNCTION types.
*/
const char* stType(const void* symbolTable, uint64_t index);

/*
*   Returns index of corresponding section header associated with 
*       index-th symbol at Symbol Table.
*/
uint16_t stSHTIndex(const void* symbolTable, uint64_t index);

/*
*   Returns the value of symbol at index-th entry of Symbol Table.
*/
char* stValue(const void* symbolTable, uint64_t index);

/*
*   Returns the size of symbol at index-th entry of Symbol Table.
*/
char* stSize(const void* symbolTable, uint64_t index);

#endif