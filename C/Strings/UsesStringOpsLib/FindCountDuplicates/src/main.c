#include "StringOperations.h"
#include <string.h>

int main()
{
    // Find and Count Duplicate Characters in Unsorted C-String
    // Method 1: by comparing with Other Letters
    char A[] = "finding";
    char ACopy[8];
    // Copy A string to ACopy string (overflow safe)
    strncpy(ACopy, A, sizeof(A));
    printf("\nCount Duplicate Chars in Unsorted C-String by Brute Force:\n");
    CountDuplicateCharacters(A);

    // Method 2: Using Hash Table and Counting
    strncpy(A, ACopy, sizeof(A));
    printf("\nCount Duplicate Chars in Unsorted C-String using Hash Table:\n");
    CountDuplicateCharacters2(A);

    // Method 3: Using Bitwise Operations
    strncpy(A, ACopy, sizeof(A));
    printf("\nCount Duplicate Chars in Unsorted C-String using Bits:\n");
    CountDuplicateCharacters3(A);
    return 0;
}