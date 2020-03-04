#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstdlib>
#include <cstdbool>

class Array
{
private:
    int *_A; // array of fixed size 20
    int _size;
    int _length; // number of elements inside array

    // Helper swap for LinearSearch2X, LinearSearch3X
    void swap(int *x, int *y);

public:
    Array();
    Array(int size);
    ~Array();

    // Display all elements in static array
    void Display();

    // Insert new element at the end of array
    void Append(int x);

    // Insert new element at index
    void Insert(int index, int x);

    // Delete element from array
    int Delete(int index);

    // Linear Search for element in array
    int LinearSearch(int key);

    // Transposition Linear Search: Moves searched element one step
    // forward, so next time it can be searched faster
    int LinearSearch2(int key);

    // Move to Front Linear Search: Swaps searched element with first
    // element, so next time it will be found in constant time
    int LinearSearch3(int key);

    // Binary Search for element in array by dividing total num of 
    // elements by 2 until one element is left, either found or not

    // Iterative Binary Search
    int BinarySearch(int key);

    // Recursive Binary Search
    int RBinSearch(int l, int h, int key);

    // Get a particular element at index
    int Get(int index);

    // Set a particular value at index
    void Set(int index, int x);

    // Max finds maximum out of the array elements
    int Max();

    // Min finds minimum element in array
    int Min();

    // Sum calculates total of all elements adds them together
    int Sum();

    // Recursive Sum
    int RSum(int n);

    // Average calculates total sum divided total number of elements
    float Avg();

    // 1st Method for Reverse Copy
    // Reverse copy from array A to B, then copy B to A
    void Reverse1();

    // 2nd Method for Reverse Copy
    // Scan from two ends of an array, swap the elements until 
    // scan has reached middle of array
    void Reverse2();

    // Left Shift
    // Shift all elements by 1 to left, lose first element
    void LeftShift(int n);

    // Left Rotate
    // Similar to left shift, but instead of first element 
    // being removed, it is placed at the last element
    void LeftRotate(int n);

    // Right Shift
    void RightShift(int n);

    // Right Rotate
    void RightRotate(int n);

    // Insert new element such that it is inserted in it's sorted position
    void InsertSort(int x);

    // Check whether an array is sorted or not
    bool isSorted();

    // Arrange Negative and Positives on separate sides
    void Rearrange();

    // Merge two sorted arrays into one sorted array 
    Array* Merge(Array arr2);

    // Union uses Merge to combine two sorted arrays into single
    // array without duplicates
    Array* Union(Array arr2);

    // Intersection uses Merge to combine two sorted arrays into single
    // array with only duplicates.
    Array* Intersection(Array arr2);

    // Difference uses Merge to copy sorted array A elements into array C
    // that are NOT present in array B. 
    Array* Difference(Array arr2);

    // Set uses Binary Search to know whether an element belongs to a Set or Not.
    int SetMembership(int key);

};

#endif