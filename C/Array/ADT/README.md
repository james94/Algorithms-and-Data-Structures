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

4. [Search(x)](UsesArrayOpsLib/Search/)
    - [LinearSearch](UsesArrayOpsLib/Search/LinearSearch/src/main.c)
    - [BinarySearch](UsesArrayOpsLib/Search/BinarySearch/src/main.c)

5. [Get(x)](UsesArrayOpsLib/GetSetMaxMinSum/src/main.c)

6. [Set(index, x)](UsesArrayOpsLib/GetSetMaxMinSum/src/main.c)

7. [Max(),Min(),Sum()](UsesArrayOpsLib/GetSetMaxMinSum/src/main.c)

8. [Reverse()](UsesArrayOpsLib/ReverseShiftRotate/src/main.c)

9. [Shift(),Rotate()](UsesArrayOpsLib/ReverseShiftRotate/src/main.c)

10. [InsertSort(), isSorted(), Rearrange()](UsesArrayOpsLib/InsertSortRearrange/src/main.c)

11. [Merge(arr1, arr2)](UsesArrayOpsLib/Merge/src/main.c)

12. [Union(arr1, arr2)](UsesArrayOpsLib/UnionIntersectDiffer/src/main.c)

13. [Intersection(arr1, arr2)](UsesArrayOpsLib/UnionIntersectDiffer/src/main.c)

14. [Difference(arr1, arr2)](UsesArrayOpsLib/UnionIntersectDiffer/src/main.c)

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
