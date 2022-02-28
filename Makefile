all: clean directory BAT

directory:
	mkdir ./bin

BAT: libraries sources
	gcc ./bin/ehp.o ./bin/bat.o ./bin/d.o  ./bin/deh.o ./bin/shp.o ./bin/dsh.o ./bin/php.o ./bin/dph.o ./bin/cd.o ./bin/stp.o ./bin/dst.o ./bin/cg.o ./bin/rp.o ./bin/dtpc.o ./bin/vd.o -lcapstone -o ./bin/BAT
	ln -s ./bin/BAT ./BAT

libraries:
	echo 'Warning: Library checking is not implemented!'

sources: ./libs/elfHeaderParser.c ./bat.c
	gcc -c ./libs/elfHeaderParser.c -o ./bin/ehp.o
	gcc -c ./libs/display.c -o ./bin/d.o
	gcc -c ./libs/displayELFHeader.c -o ./bin/deh.o
	gcc -c ./libs/sectionHeaderParser.c -o ./bin/shp.o
	gcc -c ./libs/displaySectionHeader.c -o ./bin/dsh.o
	gcc -c ./libs/programHeaderParser.c -o ./bin/php.o
	gcc -c ./libs/displayProgramHeader.c -o ./bin/dph.o
	gcc -c ./libs/codeDisassembler.c -o ./bin/cd.o
	gcc -c ./libs/symbolTableParser.c -o ./bin/stp.o
	gcc -c ./libs/displaySymbolTable.c -o ./bin/dst.o
	gcc -c -D_GNU_SOURCE ./libs/callGraph.c -o ./bin/cg.o
	gcc -c ./libs/relocationParser.c -o ./bin/rp.o
	gcc -c ./libs/dotToPngConverter.c -o ./bin/dtpc.o
	gcc -c ./libs/vulnerabilityDetection.c -o ./bin/vd.o
	gcc -c ./bat.c -o ./bin/bat.o

clean: 
	rm -rf ./bin
	rm ./BAT


bin: directory
 
bat: 
	touch ./BAT