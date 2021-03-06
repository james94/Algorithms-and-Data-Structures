#ifndef ARRAY_H
#define ARRAY_H

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
// struct Array
// {
//     int A[10]; // array of fixed size 20
//     int size;
//     int length; // number of elements inside array
// };
struct Array
{
    int *A; // array of fixed size 20
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

// Iterative Binary Search
int BinarySearch(struct Array arr, int key);

// Recursive Binary Search
int RBinSearch(int a[], int l, int h, int key);

// Get a particular element at index
int Get(struct Array arr, int index);

// Set a particular value at index
void Set(struct Array *arr, int index, int x);

// Max finds maximum out of the array elements
int Max(struct Array arr);

// Min finds minimum element in array
int Min(struct Array arr);

// Sum calculates total of all elements adds them together
int Sum(struct Array arr);

// Recursive Sum
int RSum(struct Array arr, int n);

// Average calculates total sum divided total number of elements
float Avg(struct Array arr);

// 1st Method for Reverse Copy
// Reverse copy from array A to B, then copy B to A
void Reverse1(struct Array *arr);

// 2nd Method for Reverse Copy
// Scan from two ends of an array, swap the elements until 
// scan has reached middle of array
void Reverse2(struct Array *arr);

// Left Shift
// Shift all elements by 1 to left, lose first element
void LeftShift(struct Array *arr, int n);

// Left Rotate
// Similar to left shift, but instead of first element 
// being removed, it is placed at the last element
void LeftRotate(struct Array *arr, int n);

// Right Shift
void RightShift(struct Array *arr, int n);

// Right Rotate
void RightRotate(struct Array *arr, int n);

// Insert new element such that it is inserted in it's sorted position
void InsertSort(struct Array *arr, int x);

// Check whether an array is sorted or not
bool isSorted(struct Array arr);

// Arrange Negative and Positives on separate sides
void Rearrange(struct Array *arr);

// Merge two sorted arrays into one sorted array 
struct Array* Merge(struct Array *arr1, struct Array *arr2);

// Union uses Merge to combine two sorted arrays into single
// array without duplicates
struct Array* Union(struct Array *arr1, struct Array *arr2);

// Intersection uses Merge to combine two sorted arrays into single
// array with only duplicates.
struct Array* Intersection(struct Array *arr1, struct Array *arr2);

// Difference uses Merge to copy sorted array A elements into array C
// that are NOT present in array B. 
struct Array* Difference(struct Array *arr1, struct Array *arr2);

// Set uses Binary Search to know whether an element belongs to a Set or Not.
int SetMembership(struct Array arr, int key);

// Challenges

// Find Single Missing Element
void FindMissingElement(struct Array arr);

// Find Single or Multiple Missing Elements in a sorted array
void FindMissingElements(struct Array arr);

// Find Single or Multiple Missing Elements in a sorted array using Hash Table
void FindMissingElements2(struct Array arr);

// Find Duplicate Elements
void FindDuplicateElements(struct Array arr);

// Count Duplicate Elements
void CountDuplicateElements(struct Array arr);

// Find and Count Duplicates using Hash Table
void CountDuplicateElements2(struct Array arr);

// Find and Count Duplicate Elements in Unsorted Array using Brute Force
void CountDuplicateElementsUA(struct Array arr);

// Find and Count Duplicate Elements in Unsorted Array using Hash Table
void CountDuplicateElementsUA2(struct Array arr);

// Find a Pair with Sum Target (a+b=target) in Unsorted Array using Brute Force
void FindPairSumTarget(struct Array arr, int target);

// Find a Pair with Sum Target (a+b=target) in Unsorted Array using Hash Table 
void FindPairSumTargetHT(struct Array arr, int target);

// Find a Pair with Sum Target (a+b=target) in Sorted Array
void FindPairSumTarget2(struct Array arr, int target);

// Find Max and Min in a Single Scan
void FindMaxMinSingleScan(struct Array arr, int *min, int *max);

#endif