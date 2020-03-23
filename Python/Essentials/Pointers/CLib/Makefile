# Makefile order does matter for each instruction
# Order is: 
# first go unlinked object files, produce shared object files
# second go compile C source file into object file

# Second take unlinked object files, 
# produce shared object files libadd.so, libdisplay.so
clib.so: add.o display.o
	gcc -shared -o libadd.so add.o
	gcc -shared -o libdisplay.so display.o

# First compile C source files into objects called add.o, display.o
clib.o: add.c display.c
	gcc -c -Wall -Werror -fpic add.c
	gcc -c -Wall -Werror -fpic display.c