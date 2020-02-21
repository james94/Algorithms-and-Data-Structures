#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Pointer p points to static data variable a
    int a = 10; // data variable
    int *p; // declare pointer (address) variable
    p = &a; // initialize p pointer with address of a
    printf("pointer p points to static variable: \n");
    printf("data a variable is %d\n", a);
    printf("pointer p variable dereferened is %d\n", *p);

    // Pointer dp points to dynamic array in heap memory
    int *dp; // declare pointer variable
    dp = (int*)malloc(5*sizeof(int)); // C
    dp[0] = 11;
    dp[1] = 12;
    dp[2] = 13;

    printf("pointer dp points to dynamic array in heap: \n");
    printf("ptr dp variable dereferenced at dp[0] is %d\n", dp[0]);
    printf("ptr dp variable dereferenced at dp[1] is %d\n", dp[1]);
    printf("ptr dp variable dereferenced at dp[2] is %d\n", dp[2]);
    printf("ptr dp variable dereferenced at dp[3] is %d\n", dp[3]);
    return 0;
}