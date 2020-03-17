#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Find Length of a String
void FindLength(char *s);

// Change case of String to Upper Case
void ChangeCaseToUpper(char *s);

// Change case of String to Lower Case
void ChangeCaseToLower(char *s);

// Toggle case of String
void ToggleCase(char *s);

// Count Words
int CountWords(char *s);

// Count Vowels
int CountVowels(char *s);

// Count Consonant
int CountConsonants(char *s);

// Check is String Valid
bool Valid(char *s);

// Swap
void swap(char *s1, char *s2);

// Method 1: Reverse a String
void Reverse1(char *s, char *r);

// Method 2: Reverse a String
void Reverse2(char *s);

// Method 1: Compare Strings and Don't Ignore Case. Ex: p|P is different
void Compare1(char *s1, char *s2);

// Method 2: Compare Strings and Ignore Case. Ex: p|P is p
void Compare2(char *s1, char *s2);

// Method 1: use two arrays to check if first array is palindrome
// String is Palindrome if you reverse the string, string remains same
void IsPalindrome1(char *s1, char *s2);

// Method 2: use one array to check if it is a palindrome
// String is Palindrome if both indices from opposite sides reach array 
// center and each element was the same
void IsPalindrome2(char *s);

// Find Duplicate Characters in a String

// Method 1: Compare with Other Letters and Count when Duplicate
void CountDuplicateCharacters(char *s);

// Method 2: Using Hash Table or Counting
void CountDuplicateCharacters2(char *s);

// Method 3: Using Bits

#endif