#include "../headers/callGraph.h"


void fixDynamicFunctions(symbolTableInfo* sti, relocationInfo* ri, uint64_t base,
                            uint64_t space){
    //Find dynamic symbol table:
    for (size_t i = 0; i < 2 && sti->next; i++)
    {
        if(strcmp(sti->symbolTableName, ".dynsym") == 0)
            break;
        sti++;
    }
    
    //Find .plt relocations:
    while(true){
        if(ri->type == relAPLT || ri->type == relPLT)
            break;
        ri++;
    }

    /*
    *   Compute the distance between each relocation.
    */
    uint64_t displacement = space / (ri->entryCount + 1);
    
    for (size_t i = 0; i < ri->entryCount; i++)
    {
        /* printf("%llu\n", rawRISymbolIndex(ri->relEntries, i, ri->type)); */
        //Update address of dynamic functions:
        setSTValue(sti->tablePointer, rawRISymbolIndex(ri->relEntries, i, ri->type), 
            base + (i + 1)*displacement);
    }
    
}

void dotDraw(assemblyCode* code, symbolTableInfo* functionSymbolTable, uint64_t pltBase,
                uint64_t pltSize, FILE* output){
    //DOT Syntax:
    fprintf(output, "digraph{\n");
    
    /*
    *   Seperate Symbol Tables to access them on demand:
    */
    symbolTableInfo staticSymbolTable = {-1, NULL, NULL, NULL, NULL};
    symbolTableInfo dynamicSymbolTable = {-1, NULL, NULL, NULL, NULL};
    if(strcmp(functionSymbolTable->symbolTableName, ".dynsym") == 0){
        dynamicSymbolTable = functionSymbolTable[0];
        if(functionSymbolTable[1].tablePointer)
            staticSymbolTable = functionSymbolTable[1];
    }else{
        staticSymbolTable = functionSymbolTable[0];
        if(functionSymbolTable[1].tablePointer)
            dynamicSymbolTable = functionSymbolTable[1];
    }
    
    /*
    *   To prevent unconditioned loops, I store meet functions inside this string. I'll parse
    *       a function call if and only if it's not added to this list.
    */
    //First we need the size of all function names:
    uint64_t bufferLength = 0;
    for (size_t i = 0; i < staticSymbolTable.entriesCount; i++)
    {
        //NOTE: staticSymbolTable contains name of dynamic symbols too.
        bufferLength += strlen(stName(staticSymbolTable.tablePointer, i, 
                                staticSymbolTable.symbolStringTable)) + 2;
    }
    //Add another byte for NULL Byte:
    char visitedList[bufferLength + 1];
    //Make sure that buffer is all zero initialized:
    memset(visitedList, 0, bufferLength);

    /*
    *   We assume the entry function of the program is always called 'main' which is correct for
    *       c/c++ programs.
    *   I know it's not a correct choice but it satisfies our needs currently:
    */
    uint64_t entryFunction = resolveName("main", staticSymbolTable);

    //Simulate a stack to contain function calls which should be processed later.
    uint64_t drawStack[callInstructionsCount(code)];
    
    int top = 0;
    drawStack[top++] = entryFunction;

    /*
    *   Let's trace call and ret functions.
    *   When there is no more call address inside draw stack, it means we have processed all the code.
    */
    while(top != 0){
        uint64_t nextCall = drawStack[--top];
        //Extract name of this function:
        const char* functionName = resolveValue(nextCall, staticSymbolTable);
        if(functionName == NULL){
            //There is no such function inside the table, usually call to 0 address result in this 
            //  situation which is not one of our function.
            continue;
        }if(nextCall > pltBase && nextCall < pltBase + pltSize){
            continue;
        }else{
            //Check if this function is visited or not:
            char toSearch[strlen(functionName) + 2];
            memset(toSearch, 0, strlen(functionName) + 2);
            sprintf(toSearch, " %s ", functionName);
            if(strstr(visitedList, toSearch))
                continue;
            //If not visited, then add it to visited list and process it:
            sprintf(visitedList, "%s %s ",visitedList, functionName);
        }
        //Find the assemblyCode section which contains this address
        assemblyCode addressContainer = findInstructionByAddress(code, nextCall);
        /*
        *   Store the syscalls and write them to the file at once:
        *   The upper bound for number of syscalls is that we assume every instruction is
        *       a syscall:)
        */
        uint64_t syscallList[addressContainer.numberOfInstructions];
        uint64_t syscallListTop = 0;
        for (size_t i = 0; i < addressContainer.numberOfInstructions; i++)
        {
            if(nextCall <= addressContainer.instructionPointer[i].address){
                if(strcmp(addressContainer.instructionPointer[i].mnemonic, "call") == 0){
                    char* isAnAddress = NULL;
                    uint64_t callAddress = 
                        strtoull(addressContainer.instructionPointer[i].op_str, &isAnAddress, 16);
                    if(*isAnAddress == '\0'){
                        //Valid call address:
                        const char* calledFunction;
                        if(callAddress > pltBase && callAddress < pltBase + pltSize){
                            if(dynamicSymbolTable.tablePointer){
                                calledFunction = resolveValue(callAddress, dynamicSymbolTable);
                            }
                            else 
                                continue;
                        }else{
                            calledFunction = resolveValue(callAddress, staticSymbolTable);
                            //Store this function to be visited:
                            //Prevent saving duplicates on stack:
                            int i = 0;
                            for(; i < top; i++){
                                if(drawStack[i] == top)
                                    break;
                            }
                            if(top == 0 || i == top)
                                drawStack[top++] = callAddress;
                        }
                        //DOT Syntax:
                        fprintf(output, "\t\t\"%s\" -> \"%s\"\n", functionName, calledFunction);
                    }else{
                        //Invalid call address, usually this is call to register which doesn't mind:
                        //printf("Warning: Unsupported call address: %s\n", addressContainer.instructionPointer[i].op_str);
                    }
                }
                if(strcmp(addressContainer.instructionPointer[i].mnemonic, "ret") == 0){
                    break;
                }
                if(strcmp(addressContainer.instructionPointer[i].mnemonic, "int") == 0|| 
                    strcmp(addressContainer.instructionPointer[i].mnemonic, "syscall") == 0){
                    //Search for syscall number in previous statements:
                    for(int j = i -7; j <= i; j++){
                        if(strcasestr(addressContainer.instructionPointer[j].mnemonic, "mov") != NULL &&
                            (strcasestr(addressContainer.instructionPointer[j].op_str, "eax") != NULL||
                            strcasestr(addressContainer.instructionPointer[j].op_str, "rax") != NULL)){
                                //We found the syscall number, now let's find it.
                            uint64_t syscall = strtoll(addressContainer.instructionPointer[j].op_str + 4, NULL, 16);  
                            syscallList[syscallListTop++] = syscall;
                        }
                    }
                }
            }
        }
        //Let's write the syscalls into file:
        fprintf(output, "\t\t\"%s\"[label=\"\\N\\n", functionName);
        for (size_t i = 0; i < syscallListTop; i++)
        {
            fprintf(output, "Syscall %d\\n", syscallList[i]);
        }
        
        fprintf(output, "\"]\n");
        
    }
    

    //DOT Syntax:
    fprintf(output, "}\n");

    //Flush to file:
    fflush(output);
    return;
}

void drawCallGraph(void* EH, void* SHT, assemblyCode* code, symbolTableInfo* sti, FILE* output){
    if(strcmp(elfType(EH), "EXEC (Executable file)") != 0 && 
            strcmp(elfType(EH), "DYN (Shared object)") != 0){
        errno = ENOEXEC;
        perror("Error! Unsupported elf file detected," 
            "Just Dynamic and Executable files are accepted." "Unable to draw call graph");
        return;
    }

    /*
    *   Read the .rel[a] sections to get the address of functions from dynamic libraries:  
    */
    relocationInfo* rels = parseREL(SHT);
    
    /*
    *   To fix the addresses of dynamic functions we need plt section, let's find it and compute
    *       size of each entry:
    */
    int pltSize = 0;
    uint64_t pltAddress = 0;
    for (size_t i = 0; i < sectionHeadersNumber; i++)
    {
        if(strcmp(sName(SHT, i), ".plt") == 0){
            pltAddress = rawSAddress(SHT, i);
            pltSize = rawSSize(SHT, i);
        }
    }
    
    //Fix address of functions from dynamic libraries:
    fixDynamicFunctions(sti, rels, pltAddress, pltSize);
    
    /*
    *   To draw the call graph we just need the function symbols, so let's filter symbol tables,
    *       We assume we have 2 Symbol Table at most.
    *   NOTE: This speed up the searching symbols through Symbol Table too.
    */
    symbolTableInfo functionSymbols[2];
    for (size_t i = 0; i < 2; i++)
    {
        functionSymbols[i] = filterSymbols(sti[i], STT_FUNC);
        //Just for debug:
        //printSymbolTable(functionSymbols+i);
        if(sti[i].next == NULL)
            break;
    }

    /*
    *   We are ready, let's start drawing call graph:
    */
    dotDraw(code, functionSymbols, pltAddress, pltSize, output);

    return;
}
