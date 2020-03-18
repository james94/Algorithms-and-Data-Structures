#include "StringOperations.h"

int FindLength(char *s)
{
    int i;
    for(i = 0; s[i] != '\0'; i++)
    {

    }
    // printf("Length is %d\n", i);
    return i;
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

// Find Duplicate Characters in a String

// Method 1: Compare with Other Letters
// Find and Count Duplicate Characters in Unsorted C-String using Brute Force
// Deals with lower case letters
void CountDuplicateCharacters(char *s)
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        int count = 1;
        if(s[i] != -1)
        {
            for(int j = i+1; s[j] != '\0'; j++)
            {
                if(s[i] == s[j])
                {
                    count++;
                    s[j] = -1;
                }
            }
            if(count > 1)
            {
                printf("%c is appearing %d times\n", s[i], count);
            }
        }
    }
}

// Method 2: Using Hash Table or Counting
// Find and Count Duplicate Characters in Unsorted C-String using Hash Table
// Deals with lower case letters
void CountDuplicateCharacters2(char *s)
{
    // Create Hash Table of 26, that many letters in alphabet
    int H[26] = {0}, i;

    // Increment character index with 1 in hash table
    // 97 = 'a', if s[i] = 'a', then s[i]-97 = 0, index in table
    for(i = 0; s[i] != '\0'; i++)
    {
        H[s[i]-97] += 1;
    }

    for(i = 0; i < 26; i++)
    {
        if(H[i] > 1)
        {
            printf("%c is appearing %d times\n", i+97, H[i]);
        }
    }
}

// Method 3: Using Bitwise Operations
// Find and Count Duplicate Characters in Unsorted C-String using Bits
// Deals with lower case letters
void CountDuplicateCharacters3(char *s)
{
    int32_t H = 0;
    int32_t x = 0;
    
    for(int32_t i = 0; s[i] != '\0'; i++)
    {
        x = 1;
        x = x << s[i]-97;

        if((x & H) > 0)
        {
            printf("%c is a Duplicate\n", s[i]);
        }
        else
        {
            H = x | H;
        }
        
    }
}

// Method 1:  Check if 2 Strings are Anagram using Brute Force
// Compare 1st String letter with 2nd String letter, if equal,
// mark it, so we don't check that particular element in 2nd String
// Finish traversing 1st String, if all elements in 2nd String marked
// with -1, it's an Anagram. Brute Force also deals with duplicates.
// Time Complexity: O(n^2)
void IsAnagram1(char *s1, char *s2)
{
    // Are they equal length
    int s1_length = FindLength(s1);
    int s2_length = FindLength(s2);
    if(s1_length != s2_length)
    {
        printf("Not Anagram\n");
        return;
    }

    int i, j;
    for(i = 0; s1[i] != '\0'; i++)
    {
        for(j = 0; s2[i] != '\0'; j++)
        {
            // Found match, Mark visited letter in s2
            if(s1[i] == s2[j])
            {
                s2[j] = -1;
                break; // go to outer loop, next letter s1
            }
        }
    }

    for(i = 0; s2[i] != '\0'; i++)
    {
        if(s2[i] != -1)
        {
            printf("Not Anagram\n");
            break;
        }
    }

    if(s1[i] == '\0')
    {
        printf("It's an Anagram\n");
    }
}

// Method 2: Check if 2 Strings are Anagram using Hash Table
// For 1st String, increment in Hash Table, For 2nd String, decrement
// in Hash Table. If Hash Table element is negative, not an Anagram.
// If we've reached end of 2nd String, then it's an Anagram.
// Hash Table good at dealing with duplicates
// Time Complexity: O(n)
void IsAnagram2(char *s1, char *s2)
{
    int i, H[26] = {0};

    // Are they equal length
    int s1_length = FindLength(s1);
    int s2_length = FindLength(s2);
    if(s1_length != s2_length)
    {
        printf("Not Anagram\n");
        return;
    }

    for(i = 0; s1[i] != '\0'; i++)
    {
        H[s1[i]-97] += 1;
    }

    for(i = 0; s2[i] != '\0'; i++)
    {
        H[s2[i]-97] -= 1;
        if(H[s2[i]-97] < 0)
        {
            printf("Not Anagram\n");
            break;
        }
    }

    if(s2[i] == '\0')
    {
        printf("It's an Anagram\n");
    }
}