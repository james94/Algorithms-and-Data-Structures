#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Static Array of size 5 created inside Stack
    // In C, size of array must be decided at compile
    // Memory for array will be allocated at runtime
    // In C++, size of array can be decided at runtime
    // In C++, use keyboard to enter size of array,
    // In C++, this array will be created inside stack
    int A[5] = {2,4,6,8,10};
    int *p;
    int i;

    // p points to address of contiguous block of memory (array)
    // dynamically allocated for 5 int spaces in heap
    p = (int *)malloc(5*sizeof(int));
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    // output stack array contents
    for(i = 0; i < 5; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    // output heap array contents via pointer
    for(i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }
    return 0;
}