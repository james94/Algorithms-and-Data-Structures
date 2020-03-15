#include "StringOperations.h"
#include <stdio.h>

int main()
{
    // Compare Strings
    // char A[] = "radar";
    // char B[6];
    // char A[] = "madam";
    // char B[6];
    char A[] = "spiderman";
    char B[10];
    printf("Is string a palindrome?: %s\n", A);
    printf("Method 1: Check is String a Palindrome Using Two Arrays\n");
    IsPalindrome1(A, B);

    printf("\nMethod 2: Check is String a Palindrome Using One Array\n");
    IsPalindrome2(A);

    return 0;
}