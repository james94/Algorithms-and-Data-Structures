#include "StringOperations.h"
#include <string.h>

int main()
{
    // Method 1: Compare with Other Letters and Count when Duplicate
    // Unsorted C-String
    char A[] = "finding";
    char ACopy[8];
    // Copy A string to ACopy string (overflow safe)
    strncpy(ACopy, A, sizeof(A));
    printf("\nCount Duplicate Chars in Unsorted C-String by Brute Force:\n");
    CountDuplicateCharacters(A);

    // Method 2: Using Hash Table or Counting
    // Find and Count Duplicate Characters in Unsorted C-String using Hash Table
    strncpy(A, ACopy, sizeof(A));
    printf("\nCount Duplicate Chars in Unsorted C-String using Hash Table:\n");
    CountDuplicateCharacters2(A);

    return 0;
}