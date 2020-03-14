#include "StringOperations.h"
#include <stdio.h>

int main()
{
    // Check is string valid
    char *name = "Ani?321";
    printf("Validate String: %s\n", name);

    if(Valid(name))
    {
        printf("Valid String\n");
    }
    else
    {
        printf("Invalid String\n");
    }
    return 0;
}