#include "StringOperations.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void FindLength(char *s)
{
    int i;
    for(i = 0; s[i] != '\0'; i++)
    {

    }
    printf("Length is %d\n", i);
}

// Change case of String to Upper Case
// 65=A, 97=a; diff=32; Subtract to get Upper Case
void ChangeCaseToUpper(char *s)
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 32;
        }
    }
}

// Change case of String to Lower Case
// 65=A, 97=a; diff=32; Add to get Lower Case
void ChangeCaseToLower(char *s)
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
    }
}

// Toggle case of String
void ToggleCase(char *s)
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        // 65=A && 90=Z is it upper case
        if(s[i] >= 65 && s[i] <= 90)
        {
            s[i] += 32;
        }// 97=a && 122=z is it lower case
        else if(s[i] >= 97 && s[i] <= 122)
        {
            s[i] -= 32;
        }
    }
}