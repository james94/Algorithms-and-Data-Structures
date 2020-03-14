#include "StringOperations.h"
#include <stdio.h>

int main()
{
    // Change to upper case
    // C string s1[] is mutable
    // C string *s1 is immutable
    char *s = "How are you";
    printf("Count Words, Vowels, Consonants for '%s':\n", s);
    printf("Word Count: %d\n", CountWords(s));
    printf("Vowel Count: %d\n", CountVowels(s));
    printf("Consonant Count: %d\n", CountConsonants(s));

    return 0;
}