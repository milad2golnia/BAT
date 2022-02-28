#include "../headers/display.h"
/*
*   In some functions, it doesn't matter if we have a 64 bit or 32 bit header because accessed 
*   fields are identical in those functions.
*/


void printELFHeader(void* elfHeader){
    char* magic = magicNumber(elfHeader);
    char* version = elfNVersion(elfHeader);
    char* entryPoint = elfEntry(elfHeader);
    char* flags = elfFlags(elfHeader);

    printf("ELF Header:\n");
    printf(" Magic:\t\t\t\t %s\n", magic);
    printf(" Class:\t\t\t\t %s\n", elfClass(elfHeader));
    printf(" Data:\t\t\t\t %s\n", elfData(elfHeader));
    printf(" Version:\t\t\t %s\n", elfVersion(elfHeader));
    printf(" OS/ABI:\t\t\t %s\n", elfOSABI(elfHeader));
    printf(" ABI Version:\t\t\t %s\n", elfABIVersion(elfHeader));
    printf(" Type:\t\t\t\t %s\n", elfType(elfHeader));
    printf(" Machine:\t\t\t %s\n", elfMachine(elfHeader));
    printf(" Version:\t\t\t %s\n", version);
    printf(" Entry Point Address:\t\t %s\n", entryPoint);
    printf(" Start of program headers:\t %llu (bytes into file)\n", elfPHOff(elfHeader));
    printf(" Start of section headers:\t %llu (bytes into file)\n", elfSHOff(elfHeader));
    printf(" Flags:\t\t\t\t %s\n", flags);
    printf(" Size of this header:\t\t %hu (bytes)\n", elfEHSize(elfHeader));
    printf(" Size of program headers:\t %hu (bytes)\n", elfPHEntSize(elfHeader));
    printf(" Number of program headers:\t %hu\n", elfPHNum(elfHeader));
    printf(" Size of section headers:\t %hu (bytes)\n", elfSHEntSize(elfHeader));
    printf(" Number of section headers:\t %hu\n", elfSHNum(elfHeader));
    printf(" Section header string table index: %hu\n", elfSHStrNdx(elfHeader));

    //Let's free our allocated buffers and prevent memory leak:)
    free(magic);
    free(version);
    free(entryPoint);
    free(flags);
}

void printSectionHeader(uint64_t entryCount, void* sectionHeader){
    
    printf("Section Headers:\n");
    printf(" [NR]  Name\t\t\t Type\t\t Address\t  Offset\t   Size\t\t    EntSize\t     Flags\t Link\t   Info\t\t Align\n");
    for(uint64_t i = 0; i < entryCount; i++){
        char* address = sAddress(sectionHeader, i);
        char* offset = sOffset(sectionHeader, i);
        char* size = sSize(sectionHeader, i);
        char* entSize = sEntSize(sectionHeader, i);
        char* flags = sFlags(sectionHeader, i);

        printf(" [%2llu]  ", i);
        printf("%-26s", sName(sectionHeader, i));
        printf("%-16s", sType(sectionHeader, i));
        printf("%-17s", address);
        printf("%-17s", offset);
        printf("%-17s", size);
        printf("%-17s", entSize);
        printf("%-12s", flags);
        printf("%-10lu", sLink(sectionHeader, i));
        printf("%-14llu", sInfo(sectionHeader, i));
        printf("%-14llu", sAlign(sectionHeader, i));
        printf("\n");

        //Prevent memory leak:
        free(address);
        free(offset);
        free(size);
        free(entSize);
        free(flags);
    }
    printf("%s\n", footer());

}

void printProgramHeader(uint64_t entryCount, void* programHeader){

    printf("Program Headers:\n");
    printf(" Type\t      Offset\t\t VirtAddr\t    PhyAddr\t       FileSize\t\t  MemSize\t     Flags Align\n");
    for(uint32_t i = 0; i < entryCount; i++){
        char* offset = pOffset(programHeader, i);
        char* vAddr = pVirtualAddress(programHeader, i);
        char* pAddr = pPhysicalAddress(programHeader, i);
        char* fileSize = pFileSize(programHeader, i);
        char* memSize = pMemorySize(programHeader, i);
        char* flags = pFlags(programHeader, i);
        char* align = pAlign(programHeader, i);

        printf(" %-13s", pType(programHeader, i));
        printf("0x%-17s", offset);
        printf("0x%-17s", vAddr);
        printf("0x%-17s", pAddr);
        printf("0x%-17s", fileSize);
        printf("0x%-17s", memSize);
        printf("%-6s", flags);
        printf("0x%s", align);
        printf("\n");
        
        //Print interpreter if it is provided.
        if(strcmp("INTERP", pType(programHeader, i)) == 0){
            char* interpreterName = loadInterpret(programHeader, i);
            printf("    [Requesting program interpretr: %s]\n", interpreterName);
            free(interpreterName);
        }

        //Prevent memory leak:
        free(offset);
        free(vAddr);
        free(pAddr);
        free(fileSize);
        free(memSize);
        free(flags);
        free(align);
    }
}

void printHeaders(void* elfHeader, void* programHeader, void* sectionHeader){
    if(elfHeader){
        printELFHeader(elfHeader);
    }
    if(sectionHeader){
        printSectionHeader(sectionHeadersNumber, sectionHeader);
    }
    if(programHeader){
        printProgramHeader(programHeaderNumber ,programHeader);
    }
}

void printInstructions(const cs_insn* const instructionsPointer, size_t count, FILE* output){
    for(size_t i = 0; i < count; i++){
        fprintf(output, "\t0x%x: \t", instructionsPointer[i].address);
        
        //26 is obtained according to `objdump`
        char bytesSequence[26] = {0};
        for(size_t j = 0; j < instructionsPointer[i].size; j++){
            sprintf(bytesSequence + strlen(bytesSequence), "%02x ", instructionsPointer[i].bytes[j]);
        }
        fprintf(output, "\t%-28s\t %-13s %s\n", bytesSequence, instructionsPointer[i].mnemonic,
                    instructionsPointer[i].op_str);
    }
    return;
}

void printCodes(const assemblyCode* const codeSections, FILE* output){
    if(output == NULL)
        output = stdout;
    
    //Number of code sections is stored in first entry:
    int numberOfSections = codeSections->numberOfSections;

    //Loop through all code sections and print them:
    for (size_t i = 0; i < numberOfSections; i++)
    {
        fprintf(output, "Disassembly of section %s:\n\n", codeSections[i].label);
        fprintf(output, "%s <%s>:\n", codeSections[i].address, codeSections[i].label);
        printInstructions(codeSections[i].instructionPointer, 
                            codeSections[i].numberOfInstructions, output);
        fprintf(output, "\n");
    }
    return;
}

void printSymbolTable(const symbolTableInfo* const sti){
    const void* const symbolTable = sti->tablePointer;
    uint64_t entryCount = sti->entriesCount;
    const char* symbolStringTable = sti->symbolStringTable;
    const char* const symbolTableName = sti->symbolTableName;

    printf("Symbol table '%s' contains %d entries\n",symbolTableName, entryCount);
    printf("%8s %18s %8s %-16s %-14s %-14s %-5s %s\n", 
                "Num:", "Value", "Size", "Type", "Bind", "Vis", "Ndx", "Name");

    for (size_t i = 0; i < entryCount; i++)
    {
        char* value = stValue(symbolTable, i);
        char* size = stSize(symbolTable, i);

        printf("%8d ", i);
        printf("%18s ", value);
        printf("%8s ", size);
        printf("%-16s ", stType(symbolTable, i));
        printf("%-14s ", "NOT DEVELOPED");
        printf("%-14s ", "NOT DEVELOPED");
        printf("%5d ", stSHTIndex(symbolTable, i));
        printf("%s\n", stName(symbolTable, i, symbolStringTable));

        //Prevent memory leak:
        free(value);
        free(size);
    }
    
}