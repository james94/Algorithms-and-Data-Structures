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

#endif