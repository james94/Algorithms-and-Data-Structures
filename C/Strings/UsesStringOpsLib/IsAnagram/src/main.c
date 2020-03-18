#include "StringOperations.h"
#include <stdio.h>
#include <string.h>

int main()
{
    // Check Are 2 Strings an Anagram
    // No Duplicates. Expected: Is Anagram
    // char A[] = "decimal";
    // char B[] = "medical";

    // Has Duplicates. Expected: Is Anagram
    char A[] = "verbose";
    char B[] = "observe";

    // Expected: Not Anagram. Doesn't have same letters
    // char A[] = "decimal";
    // char B[] = "delimit";

    // Expected: Not Anagram. Doesn't have same length
    // char A[] = "spiderman";
    // char B[] = "venom";

    char BCopy[8];
    strncpy(BCopy, B, sizeof(B));
    printf("Are 2 Strings an Anagram?:\n%s\n%s\n", A, B);
    printf("Method 1: Check if 2 Strings are Anagram using Brute Force\n");
    IsAnagram1(A, B);

    printf("Method 2: Check if 2 Strings are Anagram using Hash Table\n");
    strncpy(B, BCopy, sizeof(B));
    IsAnagram2(A, B);

    return 0;
}