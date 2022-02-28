#ifndef __DISPLAYELFHEADER__INCLUDED__
#define __DISPLAYELFHEADER__INCLUDED__


#include "./elfHeaderParser.h"


uint16_t elfSHStrNdx(void* elfHeader);
uint16_t elfSHNum(void* elfHeader);
uint16_t elfSHEntSize(void* elfHeader);
uint16_t elfPHNum(void* elfHeader);
uint16_t elfPHEntSize(void* elfHeader);
uint16_t elfEHSize(void* elfHeader);
char* elfFlags(void* elfHeader);
uint64_t elfSHOff(void* elfHeader);
uint64_t elfPHOff(void* elfHeader);
char* elfEntry(void* elfHeader);
char* elfNVersion(void* elfHeader);
const char* elfMachine(void* elfHeader);
const char* elfType(void* elfHeader);
const char* elfABIVersion(void* elfHeader);
const char* elfOSABI(void* elfHeader);
const char* elfVersion(void* elfHeader);
const char* elfData(void* elfHeader);
const char* elfClass(void* elfHeader);
char* magicNumber(void* elfHeader);


#endif