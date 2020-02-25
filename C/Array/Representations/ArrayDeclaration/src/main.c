#include <stdio.h>

int main()
{
    // Initialize multiple arrays
    int B[5] = {1,2,3,4,5};
    // Create array, init 3 elements, the rest are initialized to 0
    int C[10] = {2,4,6};
    // Create array, init elements to 0
    int D[5] = {0};
    // Create array with 6 elements initialized
    int E[] = {1,2,3,4,5,6};

    // Create array, but element values are garbage due to not initializing
    int A[5];

    // print the address of array elements
    // gcc compiler on 64 bit machine makes int 32 bit (4 bytes)
    for(int i = 0; i < 5; i++)
    {
        printf("%u \n", &A[i]);
    }
    return 0;
}