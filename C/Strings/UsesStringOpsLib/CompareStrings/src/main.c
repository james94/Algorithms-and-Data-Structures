#include "StringOperations.h"
#include <stdio.h>

int main()
{
    // Compare Strings
    char A[] = "Painter";
    char B[] = "painter";
    char C[] = "painting";
    printf("Method 1: Compare Strings and Don't Ignore Case\n");
    printf("1st string: %s\n", A);
    printf("2nd string: %s\n", B);
    Compare1(A, B);

    printf("\nMethod 2: Compare Strings and Ignore Case\n");
    printf("1st string: %s\n", A);
    printf("2nd string: %s\n", B);
    Compare2(A, B);

    printf("\nMethod 1: Compare Strings and Don't Ignore Case\n");
    printf("1st string: %s\n", A);
    printf("2nd string: %s\n", C);
    Compare1(A, C);

    printf("\nMethod 2: Compare Strings and Ignore Case\n");
    printf("1st string: %s\n", A);
    printf("2nd string: %s\n", C);
    Compare2(A, C);
    return 0;
}