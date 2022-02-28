#include "../headers/displayELFHeader.h"


uint16_t elfSHStrNdx(void* elfHeader){
    uint16_t sectionHeaderStringIndex = 0;
    if(is32Bit()){
        Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
        sectionHeaderStringIndex = header->e_shstrndx;
    }else{
        Elf64_Ehdr* header = (Elf64_Ehdr *) elfHeader;
        sectionHeaderStringIndex = header->e_shstrndx;
    }
    return sectionHeaderStringIndex;
}

uint16_t elfSHNum(void* elfHeader){
    uint16_t sectionHeaderNumber = 0;
    if(is32Bit()){
        Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
        sectionHeaderNumber = header->e_shnum;
    }else{
        Elf64_Ehdr* header = (Elf64_Ehdr *) elfHeader;
        sectionHeaderNumber = header->e_shnum;
    }
    return sectionHeaderNumber;
}

uint16_t elfSHEntSize(void* elfHeader){
    uint16_t sectionHeaderEntrySize = 0;
    if(is32Bit()){
        Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
        sectionHeaderEntrySize = header->e_shentsize;
    }else{
        Elf64_Ehdr* header = (Elf64_Ehdr *) elfHeader;
        sectionHeaderEntrySize = header->e_shentsize;
    }
    return sectionHeaderEntrySize;
}

uint16_t elfPHNum(void* elfHeader){
    uint16_t programHeaderNumber = 0;
    if(is32Bit()){
        Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
        programHeaderNumber = header->e_phnum;
    }else{
        Elf64_Ehdr* header = (Elf64_Ehdr *) elfHeader;
        programHeaderNumber = header->e_phnum;
    }
    return programHeaderNumber;
}

uint16_t elfPHEntSize(void* elfHeader){
    uint16_t programHeaderEntrySize = 0;
    if(is32Bit()){
        Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
        programHeaderEntrySize = header->e_phentsize;
    }else{
        Elf64_Ehdr* header = (Elf64_Ehdr *) elfHeader;
        programHeaderEntrySize = header->e_phentsize;
    }
    return programHeaderEntrySize;
}

uint16_t elfEHSize(void* elfHeader){
    uint16_t elfHeaderSize = 0;
    if(is32Bit()){
        Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
        elfHeaderSize = header->e_ehsize;
    }else{
        Elf64_Ehdr* header = (Elf64_Ehdr *) elfHeader;
        elfHeaderSize = header->e_ehsize;
    }
    return elfHeaderSize;
}

char* elfFlags(void* elfHeader){
    /*
    *   * Every byte can be represented in two hex digits ==> two byte.
    *   * Hex addresses starts with 0x which occupies two byte.
    *   4 Byte => 8 + 2 byte
    *   
    */
    char* flags = calloc(11, sizeof(char));

    /*
    *Warning: In my system the char* variables are initialized to 0 by default but I should 
    * take care of those which don't do this:
    */
    memset(flags, 0, 11);

    if(is32Bit()){
        Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
        sprintf(flags, "0x%x", header->e_flags);
    }else{
        Elf64_Ehdr* header = (Elf64_Ehdr *) elfHeader;
        sprintf(flags, "0x%x", header->e_flags);
    }
    flags[10] = 0;
    return flags;
}

uint64_t elfSHOff(void* elfHeader){
    uint64_t sectionHeaderOffset = 0;
    if(is32Bit()){
        Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
        sectionHeaderOffset = header->e_shoff;
    }else{
        Elf64_Ehdr* header = (Elf64_Ehdr *) elfHeader;
        sectionHeaderOffset = header->e_shoff;
    }
    return sectionHeaderOffset;
}

uint64_t elfPHOff(void* elfHeader){
    uint64_t programHeaderOffset = 0;
    if(is32Bit()){
        Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
        programHeaderOffset = header->e_phoff;
    }else{
        Elf64_Ehdr* header = (Elf64_Ehdr *) elfHeader;
        programHeaderOffset = header->e_phoff;
    }
    return programHeaderOffset;
}

char* elfEntry(void* elfHeader){
    /*
    *   * Every byte can be represented in two hex digits ==> two byte.
    *   * Hex addresses starts with 0x which occupies two byte.
    *   32bit = 4 byte => 2 + 8 byte to represent it in hex.
    *   64bit = 8 byte => 2 + 16 byte to represent it in hex.
    *   
    */ 
    char* entryPoint = NULL;
    if(is32Bit()){
        Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
        entryPoint = calloc(11, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(entryPoint, 0, 11);

        sprintf(entryPoint, "0x%x", header->e_entry);
        entryPoint[10] = 0;
    }else{
        Elf64_Ehdr* header = (Elf64_Ehdr *) elfHeader;
        entryPoint = calloc(19, sizeof(char));

        /*
        *Warning: In my system the char* variables are initialized to 0 by default but I should 
        * take care of those which don't do this:
        */
        memset(entryPoint, 0, 19);

        sprintf(entryPoint, "0x%x", header->e_entry);
        entryPoint[18] = 0;
    }

    return entryPoint;
}

char* elfNVersion(void* elfHeader){
    Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
    char* version = calloc(10, sizeof(char));

    /*
    *Warning: In my system the char* variables are initialized to 0 by default but I should 
    * take care of those which don't do this:
    */
    memset(version, 0, 10);

    sprintf(version, "0x%d", header->e_version);
    version[9] = '\0';
    return version;
}

const char* elfMachine(void* elfHeader){
    Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
    /*
    * You know? I can put all of machines into an array and then check their index just by a
    *   for loop BUT I'll prefer to use elf.h MACROs.
    */
    switch (header->e_machine)
    {
    case EM_NONE:
        return "UNKNOWN(No instruction set)";
    case EM_M32:
        return "AT&T WE 32100";
    case EM_SPARC: 
        return "Sun Microsystems SPARC";
    case EM_386:
        return "Intel 80386 (x86)";
    case EM_68K: 
        return "Motorola 68000 (M68K)";
    case EM_88K:
        return "Motorola 88000(M88K)";
    case EM_IAMCU:
        return "Intel MCU";
    case EM_860:
        return "Intel 80860";
    case EM_MIPS:
        return "MIPS RS3000 (big-endian only)";
    case EM_S370:
        return "IBM System/370";
    case EM_MIPS_RS3_LE:
        return "MIPS RS3000 Little-endian";
    case EM_PARISC: //Wikipedia reference1 is declared it wrongly as 0x0E but it's 0x0F
        return "Hewlett-Packard PA-RISC (HP/PA)";
    case EM_SPARC32PLUS:
        return "SPARC with enhanced instruction set";
    case EM_INTEL80960:
        return "Intel 80960";
    case EM_PPC:
        return "PowerPC";
    case EM_PPC64:
        return "PowerPC(64-bit)";
    case EM_S390:
        return "S390, including S390x (IBM S/390)";
    case EM_SPU:
        return "IBM SPU/SPC";
    case EM_V800:
        return "NEC V800";
    case EM_FR20:
        return "Fujitsu FR20";
    case EM_RH32:
        return "TRW RH32";
    case EM_RCE:
        return "Motorola RCE";
    case EM_ARM: 
        return "Advanced RISC Machine/ARM (up to ARMv7/Aarch32)";
    case EM_FAKE_ALPHA:
        return "Digital Alpha";
    case EM_SH:
        return "SuperH";
    case EM_SPARCV9:
        return "SPARC Version 9";
    case EM_TRICORE:
        return "Siemens TriCore embedded processor";
    case EM_ARC:
        return "Argonaut RISC Core";
    case EM_H8_300:
        return "Hitachi H8/300";
    case EM_H8_300H:
        return "Hitachi H8/300H";
    case EM_H8S:
        return "Hitachi H8S";
    case EM_H8_500:
        return "Hitachi H8/500";
    case EM_IA_64:
        return "IA-64";
    case EM_MIPS_X:
        return "Stanford MIPS X";
    case EM_COLDFIRE:
        return "Motorola ColdFire";
    case EM_68HC12:
        return "Motorola M68HC12";
    case EM_MMA:
        return "Fujitsu MMA Multimedia Accelerator";
    case EM_PCP:
        return "Siemens PCP";
    case EM_NCPU:
        return "Sony nCPU embedded RISC processor";
    case EM_NDR1:
        return "Denso NDR1 microprocessor";
    case EM_STARCORE:
        return "Motorola Star*Core processor";
    case EM_ME16:
        return "Toyota ME16 processor";
    case EM_ST100:
        return "STMicroelectronics ST100 processor";
    case EM_TINYJ:
        return "Advanced Logic Corp. TinyJ embedded processor family";
    case EM_X86_64:
        return "AMD x86-64 architecture";
    case EM_TI_C6000:
        return "TMS320C6000 Family";
    case EM_MCST_ELBRUS:
        return "MCST Elbrus e2k";
    case EM_AARCH64:
        return "ARM 64-bits (ARMv8/Aarch64)";
    case EM_RISCV:
        return "RISC-V";
    case EM_BPF:
        return "Berkeley Packet Filter";
    case EM_WDC:
        return "WDC 65C816";
    default:
        return "UNKNOWN(Maybe RESERVED)";
    }
}

const char* elfType(void* elfHeader){
    Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
    switch (header->e_type)
    {
    case ET_NONE:
        return "NONE (Unkown type)";
        break;
    case ET_REL:
        return "REL (Relocatable file)";
        break;
    case ET_EXEC:
        return "EXEC (Executable file)";
        break;
    case ET_DYN:
        return "DYN (Shared object)";
        break;
    case ET_CORE:
        //I wonder if this is same coredump or not :)
        return "CORE (Core file)";
        break;
    case ET_LOOS:
        return "LOOS (Operation system-specific)";
        break;
    case ET_HIOS:
        return "HIOS (Operation system-specific)";
        break;
    case ET_LOPROC:
        return "LOPROC (Processor-specific)";
        break;
    case ET_HIPROC:
        return "HIPROC (Processor-specific)";
        break;
    default:
        //Check for ranges:
        if(header->e_type > ET_LOOS && header->e_type < ET_HIOS)
            return "OS (Operation system-specific)";
        else if(header->e_type > ET_LOPROC && header->e_type < ET_HIPROC)
            return "PROC (Processor-specific)";
        return "UNKNOWN(Invalid)";
        break;
    }
}

const char* elfABIVersion(void* elfHeader){
    Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
    switch (header->e_ident[EI_ABIVERSION])
    {
    case 0:
        return "0";
        break;
    
    default:
        return "UNKNOWN(OS/ABI dependent)";
        break;
    }
}

const char* elfOSABI(void* elfHeader){
    Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
    switch (header->e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV:
        /*
        * This include ELFOSABI_NONE also
        */
        return "UNIX - System V";
        break;
    case ELFOSABI_HPUX:
        return "HP-UX";
        break;
    case ELFOSABI_NETBSD:
        return "NetBSD";
        break;
    case ELFOSABI_LINUX:
        return "UNIX - GNU";
        break;
    case ELFOSABI_SOLARIS:
        return "Solaris";
        break;
    case ELFOSABI_IRIX:
        return "IRIX";
        break;
    case ELFOSABI_FREEBSD:
        return "FreeBSD";
        break;
    case ELFOSABI_TRU64:
        return "TRU64 UNIX";
        break;
    case ELFOSABI_ARM:
        return "ARM architecture";
        break;
    case ELFOSABI_STANDALONE:
        return "Stand-alone (embedded)";
        break;
    case ELFOSABI_AIX:
        return "AIX";
        break;
    case ELFOSABI_OPENBSD:
        return "OpenBSD";
        break;
    
    /*
    *   Other types such as AROS, Fenix OS , ... which are described in wikipedia reference1
    *   are not implemented by elf.h. If we want to implement them, we should add their value
    *   manually like: #define AROS = 0x0F.
    *   So rest of cases are handled manually:
    */
    case ELFOSABI_GNUHURD:
        return "GNU Hurd";
        break;
    case ELFOSABI_NOVELLMODESTO:
        return "Novell Modesto";
        break;
    case ELFOSABI_OPENVMS:
        return "OpenVMS";
        break;
    case ELFOSABI_NONSTOPKERNEL:
        return "NonStop Kernel";
        break;    
    case ELFOSABI_AROS:
        return "AROS";
        break;
    case ELFOSABI_FENIXOS:
        return "Fenix OS";
        break;
    case ELFOSABI_CLOUDABI:
        return "CloudABI";
        break;
    case ELFOSABI_STRATUSTECHNOLOGIESOPENVOS:
        return "Stratus Technologies OpenVOS";
        break;

    default:
        return "UNKNOWN";
        break;
    }
}

const char* elfVersion(void* elfHeader){
    Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
    switch (header->e_ident[EI_VERSION])
    {
    case EV_CURRENT:
        return "1 (current)";
        break;
    
    default:
        return "UNKNOWN(Invalid)";
        break;
    }
}

const char* elfData(void* elfHeader){
    Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
    switch (header->e_ident[EI_DATA])
    {
    case ELFDATA2LSB:
        return "2's complement, little endian";
        break;
    case ELFDATA2MSB:
        return "2's complement, big endian";
        break;
    default:
        return "UNKNOWN";
        break;
    }
}

const char* elfClass(void* elfHeader){
    Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
    switch (header->e_ident[EI_CLASS]){
    case ELFCLASS32:
        return "ELF32";
        break;
    case ELFCLASS64:
        return "ELF64";
        break;
    default:
        return "UNKNOWN(Invalid)";
        break;
    }
}

char* magicNumber(void* elfHeader){
    char* magic = calloc(48, sizeof(char));
    
    /*
    *Warning: In my system the char* variables are initialized to 0 by default but I should 
    * take care of those which don't do this:
    */
    memset(magic, 0, 48);

    Elf32_Ehdr* header = (Elf32_Ehdr *) elfHeader;
    sprintf(magic, "%02x %02x %02x %02x ", header->e_ident[EI_MAG0],
            header->e_ident[EI_MAG1], header->e_ident[EI_MAG2], header->e_ident[EI_MAG3]);
    sprintf(magic + strlen(magic), "%02x %02x %02x ",
            header->e_ident[EI_CLASS], header->e_ident[EI_DATA], header->e_ident[EI_VERSION]);
    sprintf(magic + strlen(magic), "%02x %02x ",
            header->e_ident[EI_OSABI], header->e_ident[EI_ABIVERSION]);        
    //Rest of work is tedious:) let's do it by a for loop:
    for(int i = 0; i < 7; i++)
        sprintf(magic + strlen(magic), "%02x ", header->e_ident[EI_PAD + i]);
    
    magic[47] = '\0';
    return magic;
}
