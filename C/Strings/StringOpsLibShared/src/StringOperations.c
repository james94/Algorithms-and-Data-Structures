#include "StringOperations.h"

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

// Count Words
int CountWords(char *s)
{
    // increment word count as long as there is a space that separates 
    // words and that the previous character is not a space for whitespace
    int word = 1;
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == ' '  && s[i-1] != ' ')
        {
            word++;
        }
    }
    return word;
}

// Count Vowels
int CountVowels(char *s)
{
    int vowel = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            vowel++;
        }
    }
    return vowel;
}

// Count Consonants
int CountConsonants(char *s)
{
    int consonant = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
        // is it a vowel
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {

        }
        // else is it a consonant 
        else if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            consonant++;
        }
    }
    return consonant;
}

// Check is String Valid
bool Valid(char *s)
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        // check is character invalid not A-Z, a-z, 0-9?
        if(!(s[i] >= 65 && s[i] <= 90) &&
           !(s[i] >= 97 && s[i] <= 122) &&
           !(s[i] >= 48 && s[i] <= 57))
           {
               return false;
           }
    }
    return true;
}

// Swap
void swap(char *s1, char *s2)
{
    char t = *s1;
    *s1 = *s2;
    *s2 = t;
}

// Method 1: Reverse a String
void Reverse1(char *s, char *r)
{
    int i, j;
    // get lenght of string s
    for(i = 0; s[i] != '\0'; i++)
    {
    }
    i = i-1; // go to 2nd to last char before '\0'
    // store reverse s string into r string
    for(j = 0; i >= 0; i--, j++)
    {
        r[j] = s[i];
    }
    r[j] = '\0';
}

// Method 2: Reverse a String
void Reverse2(char *s)
{
    int i, j;
    for(j = 0; s[j] != '\0'; j++)
    {
    }
    
    j = j-1;
    for(i = 0; i < j; i++, j--)
    {
        swap(&s[i], &s[j]);
    }
}

