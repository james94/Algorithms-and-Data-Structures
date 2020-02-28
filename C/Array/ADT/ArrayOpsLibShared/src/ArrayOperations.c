#include "ArrayOperations.h"

// Display all elements in dynamic array
void DisplayDynArr(struct DynArray arr)
{
    printf("\nElements are\n");
    for(int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

// Display all elements in static array
void Display(struct Array arr)
{
    printf("\nElements are\n");
    for(int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

// Insert new element at the end of array
// Time Complexity: O(1). 
// Work: f(n) = 2; f(n) = 2n^0; O(n^0) = O(1).
void Append(struct Array *arr, int x)
{
    if(arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

// Insert new element at index
// Time Complexity: Best O(1); Worst O(n) 
void Insert(struct Array *arr, int index, int x)
{
    int i;
    if(index >= 0 && index <= arr->length)
    {
        for(i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

// Delete element from array
// Time Complexity: Best O(1), Worst O(n)
int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;

    // check whether extra index is valid or not
    if(index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        // stop at length-1 since shifting elements
        for(i = index; i < arr->length-1; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        // returns element value deleted
        return x;
    }
    return 0;
}

// Linear Search for element in array
// Time Complexity: 
// Successful: Best - O(1), Worst - O(n), Avg - O(n)
// Unsuccessful: O(n)
int LinearSearch(struct Array arr, int key)
{
    for(int i = 0; i < arr.length; i++)
    {
        if(key == arr.A[i])
        {
            return i;
        }
    }
    return -1;
}

// Helper function for LinearSearch2, LinearSearch3
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Transposition - Linear Search
// Move searched element one step forward
// So next time it can be searched faster
int LinearSearch2(struct Array *arr, int key)
{
    for(int i = 0; i < arr->length; i++)
    {
        if(key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i-1]);
            // return searched element that swapped one step forward
            return i-1;
        }
    }
    return -1;
}

// Move to Front - Linear Search
// Swap searched element with first element
// So next time if you search for same element, it will be found in constant time
int LinearSearch3(struct Array *arr, int key)
{
    for(int i = 0; i < arr->length; i++)
    {
        if(key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return 0;
        }
    }
    return -1;
}

// Binary Search
// Time Complexity: Best O(1); Worst O(logn)
// Whether it is iterative or recursive,
// The number of compilations depends on height of a tree
// The number of compilations are at most logn
// Procedure: Keep dividing total num of elements by
// 2 until one element is left, either found or not

// Iterative Binary Search
int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;

    while(l <= h)
    {
        mid = (l + h) / 2;
        
        if(key == arr.A[mid])
        {
            return mid;
        }
        // key is on left side
        else if(key < arr.A[mid])
        {
            h = mid - 1;
        } // key is on right side
        else
        {
            l = mid + 1;
        }
    }
    // returns -1 when key element not found
    return -1;
}

// Recursive Binary Search
int RBinSearch(int a[], int l, int h, int key)
{
    int mid;

    if(l <= h)
    {
        mid = (l + h) / 2;
        if(key == a[mid])
        {
            return mid;
        }
        // key is on left side
        else if(key < a[mid])
        {
            return RBinSearch(a, l, mid-1, key);
        } // key is on right side
        else
        {
            return RBinSearch(a, mid+1, h, key);
        }
    }
    return -1;
}