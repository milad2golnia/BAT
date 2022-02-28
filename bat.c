#include "./headers/elfHeaderParser.h"
#include "./headers/display.h"
#include "./headers/sectionHeaderParser.h"
#include "./headers/programHeaderParser.h"
#include "./headers/codeDisassembler.h"
#include "./headers/symbolTableParser.h"
#include "./headers/callGraph.h"
#include "./headers/dotToPngConverter.h"
#include "./headers/vulnerabilityDetection.h"


int main(int argc, char* argv[]){
    FILE* fd = fopen(argv[1], "r");

    if(fd == NULL){
        perror("Unable to open the input file");
        return -1;
    }

    //Read the ELF header:
    void* rawHeader = parseELFHeader(fd);

    if(rawHeader == NULL){
        errno = EBADF; //This is not a suitable error but it is the best I can find:/
        perror("Input file is not in elf format");
        return -2;
    }

    //Read the section header
    void* rawSectionHeader = parseSectionHeader(rawHeader, fd);

    //Read the program header, we don't need it at this phase but let's load it anyway:)
    void* rawProgramHeader = parseProgramHeader(rawHeader, fd);

    //Extract codes sections and translate them to assembly:
    assemblyCode* disassembledCode = disassembleCode(rawHeader, rawSectionHeader);

    //Get Symbol Tables:
    symbolTableInfo* sti = parseSymbolTable(rawSectionHeader, sectionHeadersNumber);

    //Print first Symbol Table:
    //printSymbolTable(sti);
    //Print second Symbol Table:
    //printSymbolTable(sti + 1);

    //Print assembly codes to stdout too:
    //printCodes(disassembledCode, NULL);

    /*
    *   Create intermediate file for storing 'dot' graph:
    */
    char* dotFileName = calloc(strlen(argv[1]) + 5, 1);
    sprintf(dotFileName, "%s.dot", argv[1]);
    FILE* dotFile = fopen(dotFileName, "w+");

    drawCallGraph(rawHeader, rawSectionHeader, disassembledCode, sti, dotFile);
    
    /*
    *   Create Image file for storing 'png' graph:
    */
    char* imageFileName = calloc(strlen(argv[1]) + 5, 1);
    sprintf(imageFileName, "%s.png", argv[1]);
     
    //Convert DOT format into image file:
    convertDotToPng(dotFileName, imageFileName);

    //Prevent memory leak by releasing allocated memory for disassembling instructions:
    freeDisassembledCode(&disassembledCode);
    
    //Check for function sequence vulnerabilities.
    if(argc > 2){
        FILE* functionChainVulnerabilities = fopen(argv[2], "r");
        if(functionChainVulnerabilities == NULL){
            printf("Error: Given function sequence file is not available!\n");
        }else
            sequenceFunctionCheck(dotFile, functionChainVulnerabilities);
    }

    //Check for syscall sequence vulnerabilities.
    if(argc > 3){
        FILE* syscallChainVulnerabilities = fopen(argv[3], "r");
        if(syscallChainVulnerabilities == NULL){
            printf("Error: Given syscall sequence file is not available!\n");
        }else
            sequenceSyscallCheck(dotFile, syscallChainVulnerabilities);
    }
    
    return 0;
}