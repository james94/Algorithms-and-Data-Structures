#include <stdio.h>
#include <stdlib.h>

// Array as Parameter:

// Pass by Address (Array)
// A[] can only point to arrays
void fun1(int A[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Pass by Address (Pointer)
// *A can point to ints or array of ints
void fun2(int *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Returning by Address (Pointer)
// use pointer to point to array in heap and return that address
int *fun3(int n)
{
    int *p;
    p = (int*)malloc(n*sizeof(int));
    return p;
}

int main()
{
    printf("Array as Parameter:\n");

    printf("Pass by Address (Array) fun1 Example:\n");
    int A[5] = {2,4,6,8,10};
    fun1(A, 5);

    printf("Pass by Address (Pointer) fun2 Example:\n");
    printf("Pointer to int can point to array of ints\n");
    int B[5] = {2,4,6,8,10};
    fun2(B, 5);    

    printf("Pointer to int can point to also just int\n");
    int num = 100;
    fun2(&num, 1);

    printf("Returning by Address (Pointer) fun3 Example:\n");
    int *C;
    C = fun3(5);
    fun2(C, 5);
    return 0;
}