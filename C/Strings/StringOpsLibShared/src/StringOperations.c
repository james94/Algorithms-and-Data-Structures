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

// Method 1: Compare Strings and Don't Ignore Case. Ex: p|P is different
// s1[] = "Painter"; s2[] = "painting"; p is different. Case does matter.
// ASCII code for P and p are different. It will stop after checking p.
// Since p in s1 is > P in s2, s1 will be greater
void Compare1(char *s1, char *s2)
{
    int i, j;
    for(i = 0, j = 0; s1[i] != '\0' && s2[j] != '\0'; i++, j++)
    {
        if(s1[i] != s2[j])
        {
            break;
        }
    }
    // See if i and j are equal wherever they are pointing
    if(s1[i] == s2[j])
    {
        printf("s1 string is EQUAL to s2 string.\n");
    }
    // or first one is smaller
    else if(s1[i] < s2[j])
    {
        printf("s1 string is SMALLER than s2 string.\n");
    }
    // or first one is greater
    else
    {
        printf("s1 string is GREATER than s2 string.\n");
    }
    
}

// Method 2: Compare Strings and Ignore Case. Ex: p|P is p
// s1[] = "Painter"; s2[] = "painting"; p is same. Case doesn't matter.
// ASCII code for P and p are different, but we will consider p|P just p.
// How to check case? Know the case of an alphabet. Change both strings to
// one case since we want to ignore their cases. Make both strings lower case.
void Compare2(char *s1, char *s2)
{
    // Change string s1 characters to lower case
    ChangeCaseToLower(s1);

    // Change string s2 characters to lower case
    ChangeCaseToLower(s2);

    int i, j;
    for(i = 0, j = 0; s1[i] != '\0' && s2[j] != '\0'; i++, j++)
    {
        if(s1[i] != s2[j])
        {
            break;
        }
    }
    // See if i and j are equal wherever they are pointing
    if(s1[i] == s2[j])
    {
        printf("s1 string is EQUAL to s2 string.\n");
    }
    // or first one is smaller
    else if(s1[i] < s2[j])
    {
        printf("s1 string is SMALLER than s2 string.\n");
    }
    // or first one is greater
    else
    {
        printf("s1 string is GREATER than s2 string.\n");
    }    
}

// Method 1: IsPalindrome1() use two arrays
// String is Palindrome if you reverse the string, string remains same
// Store reverse of 1st array in 2nd array. If both arrays are same,
// then c-string is palindrome
void IsPalindrome1(char *s1, char *s2)
{
    // Store the reverse of s1 array into s2
    Reverse1(s1, s2);

    // Compare s1 to s2, if they are same, string is palindrome
    int i, j;
    for(i = 0, j = 0; s1[i] != '\0' && s2[j] != '\0'; i++, j++)
    {
        if(s1[i] != s2[j])
        {
            break;
        }
    }
    // See if i and j are equal wherever they are pointing
    if(s1[i] == s2[j])
    {
        printf("s1 is a palindrome.\n");
    }
    else
    {
        printf("s1 is not a palindrome.\n");
    }
}

// Method 2: IsPalindrome2() use one array
// Use two indices. 1st index i points at start of array and 2nd index
// j points at end of array. If the element i and j is pointing on is
// the same, move i and j toward center of array until i < j becomes false.
// If the element i and j is pointing on is different, c-string isn't a
// palindrome.
void IsPalindrome2(char *s)
{
    int i, j;
    for(j = 0; s[j] != '\0'; j++)
    {
        
    }
    j = j-1;
    for(i = 0; i < j; i++, j--)
    {
        if(s[i] != s[j])
        {
            break;
        }
    }
    // See if i and j are equal wherever they are pointing
    if(s[i] == s[j])
    {
        printf("s[i] = %c; s[j] = %c;\n", s[i], s[j]);
        printf("s1 is a palindrome.\n");
    }
    else
    {
        printf("s1 is not a palindrome.\n");
    }
}