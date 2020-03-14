#include "StringOperations.h"
#include <stdio.h>

int main()
{
    // Check is string valid
    char A[] = "python";
    char B[7];
    printf("Will Reverse String: %s\n", A);
    Reverse(A, B);
    printf("Reversed String:\n");
    printf("%s", B);
    return 0;
}