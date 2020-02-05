#!/bin/bash
g++ -c -fPIC pointers.cpp -o pointers.o
g++ -shared -Wl,-soname,libpointers.so -o libpointers.so pointers.o

# genreflex pointers.hpp --rootmap=libpointers.rootmap --rootmap-lib=libpointers.so
# g++ -fPIC -rdynamic -O2 -shared -I$REFLEXHOME/include pointers.cpp -o libpointers.so -L$REFLEXHOME/lib -lReflex