#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Dynamic Array Structure
struct DynArray
{
    int *A; // array pointer for storing the numbers into heap array
    int size;
    int length; // number of elements inside array
};

// Static Array Structure
struct Array
{
    int A[10]; // array of fixed size 20
    int size;
    int length; // number of elements inside array
};

// Display all elements in dynamic array
void DisplayDynArr(struct DynArray arr);

// Display all elements in static array
void Display(struct Array arr);

// Insert new element at the end of array
void Append(struct Array *arr, int x);

// Insert new element at index
void Insert(struct Array *arr, int index, int x);

// Delete element from array
int Delete(struct Array *arr, int index);

// Linear Search for element in array
int LinearSearch(struct Array arr, int key);

// Helper swap for LinearSearch2X, LinearSearch3X
void swap(int *x, int *y);

// Transposition Linear Search: Moves searched element one step
// forward, so next time it can be searched faster
int LinearSearch2(struct Array *arr, int key);

// Move to Front Linear Search: Swaps searched element with first
// element, so next time it will be found in constant time
int LinearSearch3(struct Array *arr, int key);

// Binary Search for element in array by dividing total num of 
// elements by 2 until one element is left, either found or not