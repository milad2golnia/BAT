#include "../headers/codeDisassembler.h"


void freeDisassembledCode(assemblyCode** disassembledCodeAddress){
    assemblyCode* disassembledCode = *disassembledCodeAddress;

    //Number of code sections is available at `numberOfSections` field of first entry:
    int numberOfCodeSections = disassembledCode->numberOfSections;

    //Loop through all entries and release code sections one by one:
    for(size_t i = 0; i < numberOfCodeSections; i++){
        //Release allocated memory for storing address of this section:
        free(disassembledCode[i].address);
        //Release memory of assembly instructions.
        cs_free(disassembledCode[i].instructionPointer, disassembledCode[i].numberOfInstructions);
    }

    //Prevent upper layer to use this memory:
    disassembledCodeAddress = NULL;
    return;
}

assemblyCode findInstructionByAddress(assemblyCode* code, uint64_t address){
    int numberOfCodeSections = code->numberOfSections;
    for (size_t i = 0; i < numberOfCodeSections; i++)
    {
        if(address >= strtoull(code[i].address, NULL, 16) && 
            address < code[i].instructionPointer[code[i].numberOfInstructions - 1].address){
                return code[i];
            }
    }
}

assemblyCode capstonize(const uint8_t* const binaryInstructions, uint64_t length, uint64_t addr,
                            cs_arch architecture, cs_mode mode){
    csh handle;
    cs_insn* insn;
    size_t count;
    assemblyCode disassemblleCode;
    disassemblleCode.instructionPointer = NULL;
    disassemblleCode.numberOfInstructions = 0;
    disassemblleCode.numberOfSections = -1;

    if(cs_open(architecture, mode, &handle) != CS_ERR_OK){
        //I hope the cs_open() is set errno correctly
        perror("Capstone is Unable to update handler");
        return disassemblleCode;
    }

    count = 
        cs_disasm(handle, binaryInstructions, length, addr, 0, &insn);
    
    /*
    *   We are done with API. 
    *   Let's close it.
    */
    cs_close(&handle);

    disassemblleCode.instructionPointer = insn;
    disassemblleCode.numberOfInstructions = count;
    //Other fields should be filled by uppper layer(caller).
    
    return disassemblleCode;
}

assemblyCode* disassembleCode(void* elfHeader, void* sectionHeaderTable){
    /*
    *   We need to do 2 job before proceed disassembling:
    *   1. Find sections which contains executable codes.
    *   2. Find type of architecture.
    *   3. Find mode.
    */

   /*
   *    Find type of architecture:
   */
   cs_arch architecture;
   if(strcmp(elfMachine(elfHeader), "Intel 80386 (x86)") == 0 ||
        strcmp(elfMachine(elfHeader), "AMD x86-64 architecture") == 0){
       architecture = CS_ARCH_X86;
   }else{
       //As Miss Eskandari stated we just take care of X86 for simplicity:
       errno = ENOEXEC;
       perror("Unsupported architecture detected! Unable to disassemble the code"); 
       return NULL;
   }

    /*
    *   Recognize mode:
    */
   cs_mode mode;
   if(strcmp(elfClass(elfHeader), "ELF32") == 0){
       mode = CS_MODE_32;
   }else if(strcmp(elfClass(elfHeader), "ELF64") == 0){
       mode = CS_MODE_64;
   }else{
       errno = ENOEXEC;
       perror("Unsupported mode detected! Unable to disassemble the code");
       return NULL;
   }

    if(isBigEndian())
        mode += CS_MODE_BIG_ENDIAN;
    else
        mode += CS_MODE_LITTLE_ENDIAN;

   /*
   *    Find code sections:
   */
   int* codeSections = NULL;
   int codeSectionCount = 0;
   /*
   *    We don't know the number of code sections but I want to disassemble them all by looping 
   *        through them once.
   *    Allocating memory from stack is cheep and easy to do, so I'll Allocate a maximum space
   *        on stack and first store disassembled code on stack then after understanding their number, I'll
   *        allocate enough dynamic memory and store them.
   *    You can do all of this jobs using dynamic memories and without utilizing stack but it
   *        Gives you lower performance
   */
   assemblyCode temporaryDisassembledCodeSections[sectionHeadersNumber];
   int index = 0;
   for (uint64_t i = 0; i < sectionHeadersNumber; i++)
   {
        char* sectionFlags = sFlags(sectionHeaderTable, i);
        const char* sectionType = sType(sectionHeaderTable, i);
        if(strchr(sectionFlags, 'X') && strcmp(sectionType, "PROGBITS") == 0){
            /*
            *   Extract needed information from section header:
            */
            char* label = sName(sectionHeaderTable, i);
            uint64_t offset = rawSOffset(sectionHeaderTable, i);
            uint64_t size = rawSSize(sectionHeaderTable, i);
            uint64_t address = rawSAddress(sectionHeaderTable, i);
            char* sectionAddress = sAddress(sectionHeaderTable, i);

            /*
            *   Load section from file to memory:
            */
            void* binaryCodes = loadSection(NULL, offset, size);
            
            codeSectionCount++;
            temporaryDisassembledCodeSections[index++] = 
                capstonize(binaryCodes, size, address, architecture, mode);
    
            //Fill other remaining fields:
            temporaryDisassembledCodeSections[index - 1].label = label;
            temporaryDisassembledCodeSections[index - 1].address = sectionAddress;
            
            /*
            *   Prevent memory leak:
            */
            //We don't need content of this section anymore:
            free(binaryCodes);
        }

        /*
        *   Prevent memory leak:
        */
        free(sectionFlags);
   }

    //Fix `numberOfSections` at first entry:
    temporaryDisassembledCodeSections[0].numberOfSections = codeSectionCount;

    assemblyCode* disassembledCodes = calloc(codeSectionCount, sizeof(assemblyCode));
    //Move result from stack to dynamic memory:
    for(int i = 0; i < codeSectionCount; i++){
        disassembledCodes[i] = temporaryDisassembledCodeSections[i];
    }

   return disassembledCodes;
}

uint64_t callInstructionsCount(assemblyCode* code){
    uint64_t result = 0;
    int numberOfCodeSections = code->numberOfSections;
    for (size_t i = 0; i < numberOfCodeSections; i++)
    {
        result += code[i].numberOfInstructions;
    }
    return result;
}