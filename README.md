This project is a final part of one larger project. This is part 2 but the APIs of other parts are kept and you can examine them on your own:

1. Phase 0: Extracting headers of ELF file. APIs are available in this part.
2. Phase 1: Disassemble binary instructions. APIs are available in this part.
3. Phase 2: Detect Vulnerabilities. Apis are available and also a simple test is provided at [bat](./bat.c) file

- [BAT](#bat)
  - [Changes of previous phase](#changes-of-previous-phase)
    - [`./headers/display.h`](#headersdisplayh)
    - [`./headers/codeDisassembler.h`](#headerscodedisassemblerh)
  - [Function Names](#function-names)
  - [Syscall](#syscall)
  - [`WHAT`](#what)
    - [`./bat.c`](#batc)
    - [`./headers/symbolTableParser.h`](#headerssymboltableparserh)
    - [`./headers/displaySymbolTable.h`](#headersdisplaysymboltableh)
    - [`./headers/callGraph.h`](#headerscallgraphh)
    - [`./headers/relocationParser`](#headersrelocationparser)
    - [`./functionPattern.txt`](#functionpatterntxt)
    - [`./syscallPattern.txt`](#syscallpatterntxt)
    - [`./headers/dotToPngConverter.h`](#headersdottopngconverterh)
    - [`./headers/vulnerabilitiesDetection.h`](#headersvulnerabilitiesdetectionh)
  - [Compilation](#compilation)
  - [Run](#run)
    - [Optimization flags](#optimization-flags)
    - [Static Detection of Vulnerabilities](#static-detection-of-vulnerabilities)
    - [Target](#target)

# BAT
We can devide the documentaion of any software into two section:

1. `WHAT`: What's purpose of each section of your code and What's supposed to reach.
2. `HOW`: How your code achieve that goal.

At this documentation I just explain the `WHAT` section! To find out about `HOW` you can read my code because it is **developed neatly** and also **fully commented**.  
Also it is developed in `C` language and I assume you are familiar with it because the course is based on this language partially.

**NOTE:** At the entire of this documentation(BAT), I consider `ce815-001-400210733/HW1/BAT` as current directory `./`.

## Changes of previous phase
Along all the changes, I created a [`tests`][batTests] directory to make the workspace cleaner and also access all my testcases in one place.

You can find all the testcase of my program there.

### `./headers/display.h`

New function `printSymbols` developed to print Symbol Table(ST). This is not part of this assignment but it helped me a lot.


### `./headers/codeDisassembler.h`

I found my code disassembler don't support the '64-bit' architecture just because of my blunder.

I forgot to add machine type for 64 bit when *Mahcine* checking in disassembler.

To support the `64-bit` I just need to modify the following line

```
   if(strcmp(elfMachine(elfHeader), "Intel 80386 (x86)") == 0){
```

to:

```
   if(strcmp(elfMachine(elfHeader), "Intel 80386 (x86)") == 0 ||
        strcmp(elfMachine(elfHeader), "AMD x86-64 architecture") == 0){
```
and that's it! Now my program support 64 bit.

**It's really a minor bug and I hope desperately you ignore it in previous HW:( I it doesn't effect my grade.**

## Function Names

To create *Callgraph*, first off, we need **function names**.  To extract function names I read the content of `.symtab` and `.dynsym` sections.

Using `.symtab` I was unable to connect name of functions to their addresses but for dynamic symbols such as `printf`, I also parsed the `.rel.plt`/`.rela.plt` sections and filled the values inside this symbol table.

## Syscall
To extract the system calls I detect the `int` and `syscall` instructors.

To find out which system call is called, I read the content of `eax`/`rax` register. Also I consider the last 7 instructions to read the content of this register because each syscall will need 7 instructor at most.

NOTE: I was unable to write a code to have so many system calls even when I compile the codes statically. But I developed the processing of syscalls carefully and I hope it works if number of syscalls increases.


## `WHAT`
To find out the `What` section it is enough to know What's inside each file.

All files which are in `./libs` directory have corresponding headers file in `./heaers` directory. Hence to document them, it's enough to document their header files.

### `./bat.c`
This is entry point of BAT which receives a file at argv[1] and opens it. Then it parse ELF Header, Program Header Table (PHT), Section Header Table (SHT) respectively.

After it, we are trying to find the code sections and STs respectively according to the SHT.

By having this information, we draw the call graph in *dot* foramt and then convert it to an image.

The name of *dot* file and *png* file are same as input file unless their extensions which are `.dot` and `.png` respectively.

After all, we try to find the vulnerabilities using *CG* against sequences of functions as syscall which is provided by user. 

NOTE: `argv[2]` always should contain the 
function sequences and `argv[3]` should contains the syscall sequences. Be aware to don't pass them differently.

### `./headers/symbolTableParser.h`
This file parse the *Symbol Table (ST)* from ELF file. Also it has some functions to resolve addresses or names of symbols along some function to filter the *Symbol Type* too.

Some functions to extract some property of symbols developed. We don't need to extract all properties of symbol for drawing a *Call Graph*.

I know there are just 2 ST inside an ELF file but this header can extract more Symbol Tables if there are some. It just considered this way for future usages.

At this moment, We use filtering property to extract those symbols which are associated with a function because in call graph we just need those functions.

### `./headers/displaySymbolTable.h`
This file is used to print the Symbol Tables. This is not part of this assignment but it will help me to debug the program using visualizing ST, because to draw the *Call Graph*, I manipulate the ST.

As mentioned by comments inside this file, the development of this file is not finished and it just satisfies my needs.

### `./headers/callGraph.h`
**This is the main part of this assignment!** This function get needed information and then extract `.rel` or `.rela` sections to resolve addresses of *Dynamic Symbol Table*.

This function assumes the entry ponit of the program is always called `main` which is incorrect in general but for this assignment, it satisfies our needs.

The result will be saved in **dot** format which needs another conversation to make the final image of *Call Graph (CG)*.

This file traverse the extracted *assembly code* by starting from entry point and resolve each call address agains *Symbol Tables (ST)*. 

**NOTE: Currently we just support *Dynamic* and *Executable* ELF files but ignores *Allocatables* and other foramts of ELF files. As matter of fact for *Allocatables* files we should just modify the address of symbols by adding the offset of section to them. This was a tidious work and hence I ignored it.**

### `./headers/relocationParser`
Tries to parse every section which contain `.rel` in their names. Currently we just focus on 4 below sections:

1. `.rel.plt`
2. `.rel.dyn`
3. `.rela.plt`
4. `.rela.dyn`

This header, like some others, is developed partially just to satisfy our needs. Maybe I'll complete it later to make the work finished and publish my own API.

### `./functionPattern.txt`
This file defines the function sequences which are considered as vulnerabilities.

This file should obey below rules to be scanned correctly:

1. Number of sequences should be determined in first line.
2. In rest of lines, each line should contains just one sequence.
3. The number of functions in a sequence should be specified at start of that line.
4. In each sequence, function names should be space seperated.
5. You should write name of functions barely without any parentheses.

NOTE: If you compile your files statically, the name of `C` functions may change. E.g. in `32-bit` static files, the name of `printf` will be changed to `__printf`. **It's your duty to write the exact name of functions, my code is unable to do the magic:)**

### `./syscallPattern.txt`
This file defines the syscall sequences which are considered as vulnerabilities.

The content of this file should follow below rules to be scanned correctly:

1. Number of sequences should be determined in first line.
2. In rest of lines, each line should contains just one sequence.
3. The number of syscalls in a sequence should be specified at start of that line.
4. In each sequence, syscalls should be space-seperated.
5. You should write just syscall numbers without any extra string.

### `./headers/dotToPngConverter.h`
This file convert the resulte *dot* file into a *PNG* image.

Currently this header utilize the `system` function which is not desired and I'll may change it in future.

**NOTE: This file depends on `dot` program and you should install it on you operation system.**

### `./headers/vulnerabilitiesDetection.h`
This file gets your function/syscall sequences and print a warning to STDOUT if each of them detected.

This header is very syntax dependent, so don't try to use for a *CG* which is not produced by my code. Also keep in mind to follow the rules for writing sequences.

## Compilation
The compilation of code is done base on `Makefile` which is available at `./`.

Please note this Makefile is very very superficail because I didn't have time to develop it and I preferred to focus on code of course.

By the way this `Makefile` makes the process of compilation much simpler.  
To compile the code, just run:

```
    $ make
```

If you get any error due to `No such file or directory`, run below commands respectively and regardless of errors:

```
    $ make bin
    $ make bat
    $ make
```

**NOTE:** I'll modify the `Makefile` later to check the existance of files with simple `if` condition but for now I don't have any resources (Time, Energy & ...) to take care of it.

To clean the result of compilation and also clean the directory:

```
    $ make clean
```

## Run

The 4 testcases are provided under [`tests`][batTests] directory which are built as below:

```
    $ gcc -m32 test.c -o 32bitDynamic
    $ gcc -m32 -static -o 32bitStatic
    $ gcc test.c -o 64bitDynamic
    $ gcc -static test.c -o 64bitStatic
```

I tested this program on these testcases and here you can see its results(CGs):

```
    $ ./BAT 32bitDynamic
```

Result for executing previous command:

![An image of BAT execution for 32 bit dynamic program][32bitDynamicCG]

```
    $ ./BAT 64bitDynamic
```

Result for executing previous command:

![An image of BAT execution for 64 bit dynamic program][64bitDynamicCG]

```
    $ ./BAT 32bitStatic
```

Result for executing previous command:

![An image of BAT execution for 32 bit executable program][32bitStaticCG]

```
    $ ./BAT 64bitStatic
```

Result for executing previous command:

![An image of BAT execution for 64 bit executable program][64bitStaticCG]

### Optimization flags
Yes, the `call` and `ret` instructions completely depends on compiler optimization.

By enabling optimization levels, compiler tries to decrease the size of code by reusing the code segments and it achieves reusing of code segments by `call` instructions.

To show this differences, I compiled the given [`test.c`][batTestcase] with `-O3` flage which is one of most optimizer flags in `gcc`. I tested this flag for both `64-bit` and `32-bit` systems:

1. To compile a `32-bit` dynamic program with this optimizer:
    ```
        $ gcc -O3 -m32 ./tests/test.c -o ./tests/O3flag32bitDynamic
    ```
    and then gave it to `./BAT`:
    ```
        $ ./BAT ./tests/O3flag32bitDynamic
    ```
    This result is as below:

    ![An image of BAT execution for 32-bit optimized program][32bitOptimized]

2. To compile a `64-bit` dynamic program with this optimizer:
   
   ```
        $ gcc -O3 ./tests/test.c -o ./tests/O3flag64bitDynamic 
   ```
   
   and then gave it to `./BAT`:

    ```
        $ ./BAT ./tests/O3flag64bitDynamic
    ```

    The result is as below:

    ![An image of BAT execution for 64-bit optimized program][64bitOptimized]

### Static Detection of Vulnerabilities

1. sequence of function checking:
   
   ```
    $ ./BAT tests/64bitDynamic ./functionPattern.txt
   ```
   
   The result is as below:

    ![An image of sequence of function checking][functionSeq]

2. sequence of syscall checking:
   
   ```
    $ ./BAT tests/64bitStatic ./functionPattern.txt ./syscallPattern.txt
   ```
   
   The result is as below:

   ![An image of sequence of syscall checking][syscallSeq]

**NOTE:** As I mentioned before, I was unable to produce a code which includes some syscalls and that's why I tested on a file with just one syscall.

### Target
This program is tested on below target but it should be compatible with other targets too:

```
    $ uname -a
    Linux milad-pc 5.4.159-1-MANJARO #1 SMP PREEMPT Fri Nov 12 20:25:49 UTC 2021 x86_64 GNU/Linux
```

Also the binary file `./BAT` is pushed into `tarasht` account so if you have same architecture, you don't need to compile it again. 

NOTE: At this assignment, you couldn't compile my code on **Non-GNU** operation systems unless you install the needed libraries manually.

[batTestcase]: ./tests/test.c
[batTests]: ./tests
[32bitDynamicCG]: ../resources/32bitDynamic.png
[64bitDynamicCG]: ../resources/64bitDynamic.png
[32bitStaticCG]: ../resources/32bitStatic.png
[64bitStaticCG]: ../resources/64bitStatic.png
[32bitOptimized]: ../resources/O3flag32bitDynamic.png
[64bitOptimized]: ../resources/O3flag64bitDynamic.png
[functionSeq]: ../resources/functionSeq.png
[syscallSeq]: ../resources/syscallSeq.png