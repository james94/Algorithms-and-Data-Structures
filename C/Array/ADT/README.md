# Array: ADT

## C Programs

**Data**

1. Array Space

2. Size

3. Length (Num. of Elements)

**Operations**

1. [Display()](UsesArrayOpsLib/Display/src/main.c)

2. [Insert(index, x)](UsesArrayOpsLib/Insert/src/main.c)

3. [Delete(index)](UsesArrayOpsLib/Delete/src/main.c)

4. [Search(x)](UsesArrayOpsLib/Search/src/main.c)

5. [Get(x)](UsesArrayOpsLib/Get/src/main.c)

6. [Set(index, x)](UsesArrayOpsLib/Set/src/main.c)

7. [Max()/Min()](UsesArrayOpsLib/MaxMin/src/main.c)

8. [Reverse()](UsesArrayOpsLib/Reverse/src/main.c)

9. [Shift()/Rotate()](UsesArrayOpsLib/ShiftRotate/src/main.c)

<!--
Shell and Perl Code to help with redundant work:
mkdir -p Insert/src/ && touch Insert/src/main.c
cp Display/*.sh Insert/
cp Display/*.txt Insert/

perl -pi -e 's/DisplayArray/Insert/g' Insert/CMakeLists.txt
-->

## Build Array Operations Shared Library

~~~bash
cd ArrayOpsLibShared
# Build C shared library using CMake
./compile.sh

# Display Shared Library Dependencies
./info.sh
~~~

## Optional: Install Array Operations Shared Library

~~~bash
# Installs C shared library into /usr/lib, 
# makes it available system wide
./install.sh
~~~

## Use Array Operations Shared Library

For example, to demo Display operation code example, run the following command:

~~~bash
cd UsesArrayOpsLib/Display
./compile.sh
./run.sh
~~~
