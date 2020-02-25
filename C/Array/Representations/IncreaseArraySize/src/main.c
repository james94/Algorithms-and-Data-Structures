#include <stdio.h>
#include <stdlib.h>

// Increase size of array when it is created inside heap
int main()
{
    // Create pointer p, pointer q
    int *p, *q;
    int i;
    // p point to dynamically allocated array of size 5
    p = (int *)malloc(5*sizeof(int));
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    // q point to dynamically allocated array of size 10
    q = (int *)malloc(10*sizeof(int));

    // Transfer all those array elements from p to q pointer's array
    for(i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }

    // Deallocate (delete) contiguous block of memory (array) p points to
    // If we didn't delete array memory, it would cause memory leak
    free(p);
    // p point to q's array, a dynamic array of larger size
    // compared to the previous dynamic array p pointed to
    // Now p's array size is 10. 
    p = q;
    // Remove q from there
    q = NULL;

    for(i = 0; i < 5; i++)
    {
        printf("%d \n", p[i]);
    }
    return 0;
}