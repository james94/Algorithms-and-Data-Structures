# Strings

## Overview

### Character Set/ASCII Codes

The set of characters supported by a programming language like C/C++ or any other language. The set of characters supported a language is supported by any computer system. Computer system works in binary number system, so everything in computers is numbers.

How do we make them support characters?

They don't support characters. To make them work on characters, we define some set of numbers as characters. For every character, we define some numeric value, so we get some numeric codes.

For the English alphabet, for every character, there are some codes defined and those are standard codes. Every electronic machine follows that same set of codes and those codes are called American Standard Code for Information Interchange (**ASCII**). These codes are given by the American National Standards Institute (ANSI) and also it is ISO Standard.

**ASCII Codes**:

~~~cpp
A - 65      a - 97      0 - 48
B - 66      b - 98      1 - 49
C - 67      c - 99      2 - 50
.           .           .
.           .           .
.           .           .
Z - 90      z - 122     9 - 57
( , ) ? + - *...
{Enter} - 10
{Space} - 13
{Esc} - 27
~~~

For every character on the keyboard that forms a character set and for every symbol on the keyboard, there is an ASCII code.

ASCII codes range from [0, 127]. To represent any one symbol 7 bits are sufficient,  they are binnary bits. While allocating the memory in main memory (RAM), 7 bits are not allocated, minimum 1 byte is allocated. That's why a character is stored in 1 byte in computer memory.

For other national languages like Chinese, Japanese, Hindi, the codes are defined and those are ISO standard codes and those codes are called **Unicodes**.

**Unicodes** are for all the languages. So, ASCII codes become the subset of Unicode. Unicodes takes 2 bytes (16 bits) of memory. So because it is supporting all national languages and this 16 bits can be represented in the form of hexadecimal codes. So, hex codes are represented in 4 bits. These are represented in 4 x 4 bits hexadecimals.

**Unicodes**:

~~~cpp
CO35
CO3A
~~~

### Character Array

A character array is an array of characters. What is actually stored in the memory for a character is a number. For example, `'A'` is stored in char variable temp, what is stored in memory is `65` NOT `'A'`.

~~~cpp
// Single Character Initialized
char temp = 'A';
// Print character
printf("%c", temp);

// Character Array by characters
char x[5] = {'A','B','C','D','E'};
// Character Array by numeric codes
char y[5] = {65,66,67,68,69};
~~~

### String

In C/C++, String is an array of characters with the end point marked with a null character `'\0'`. Null character is known as a String delimiter, End of String char, NULL char or String Terminator.

But in other languages like Java, Strings will not have a slash zero. To know how many characters are in the string is known with the help of length.

**C/C++ String**:

~~~cpp
// String name John terminated by 0
char name1[10] = {'J','o','h','n','\0'};
char name2[] = {'J','o','h','n','\0'};
// C compiler takes care of the '\0'
char name3[] = "John";
// Char pointer, string is auto created in heap
char *name4 ="John";

// Display String
printf("%s", name1);

// Read 1 word String, can't deal with spaces
scanf("%s", name1);

// Read entire String
gets(name);
~~~

## Operations

1. [FindLength()](UsesStringOpsLib/FindLength/src/main.c)

2. [ChangeCaseToUpper()](UsesStringOpsLib/ChangeCaseOfString/src/main.c)

3. [ChangeCaseToLower()](UsesStringOpsLib/ChangeCaseOfString/src/main.c)

4. [ToggleCase()](UsesStringOpsLib/ChangeCaseOfString/src/main.c)
