# Makefile order does matter for each instruction
# Order is: 
# first go unlinked object files, produce shared object files
# second go compile C++ source file into object file

# Second take unlinked object files, 
# produce shared object files libpointers.so
cpplib.so: pointers.o
	g++ -shared -Wl,-soname,libpointers.so -o libpointers.so pointers.o

# First compile C++ source files into objects called pointers.o
cpplib.o: pointers.cpp
	g++ -c -Wall -Werror -fPIC pointers.cpp -o pointers.o

