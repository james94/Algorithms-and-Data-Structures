#include "StringOperations.h"
#include <stdio.h>

int main()
{
    // Check is string valid
    char A[] = "python";
    char B[7];
    printf("Method 1: Reverse String\n");
    printf("Will Reverse String: %s\n", A);
    Reverse1(A, B);
    printf("Reversed String: %s\n", B);

    char C[] = "javascript";
    printf("\nMethod 2: Reverse String\n");
    printf("Will Reverse String: %s\n", C);
    Reverse2(C);
    printf("Reversed String: %s\n", C);
    return 0;
}