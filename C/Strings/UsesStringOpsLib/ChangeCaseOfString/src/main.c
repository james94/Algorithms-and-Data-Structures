#include "StringOperations.h"
#include <stdio.h>

int main()
{
    // Change to upper case
    // C string s1[] is mutable
    // C string *s1 is immutable
    char s1[] = "welcome";
    printf("Initial s1: %s\n", s1);
    ChangeCaseToUpper(s1);
    printf("Upper: %s\n", s1);

    char s2[] = "WELCOME";
    printf("Initial s2: %s\n", s2);
    ChangeCaseToLower(s2);
    printf("Lower: %s\n", s2);

    char s3[] = "wElCome";
    printf("Initial s3: %s\n", s3);
    ToggleCase(s3);
    printf("Toggle: %s\n", s3);

    return 0;
}