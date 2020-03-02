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

// Get
// Returns element at particular index
// Time Complexity: O(1)
int Get(struct Array arr, int index)
{
    if(index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

// Set
// Replace value at a particular index
// Time Complexity: O(1)
void Set(struct Array *arr, int index, int x)
{
    if(index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
}

// Max finds maximum element in array
// For unsorted array, must check all elements
// For sorted array, check either first or last element
// Time Complexity: O(n)
int Max(struct Array arr)
{
    int max = arr.A[0];
    for(int i = 0; i < arr.length; i++)
    {
        if(arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

// Min finds minimum element in array
// Time Complexity: O(n)
int Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i = 0; i < arr.length; i++)
    {
        if(arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

// Iterative Sum calculates total of all elements adds them together
// Time Complexity: O(n)
int Sum(struct Array arr)
{
    int sum = 0;
    for(int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

// Recusrive Sum
int RSum(struct Array arr, int n)
{
    if(n < 0)
    {
        return 0;
    }
    else
    {
        return RSum(arr, n-1) + arr.A[n];
    }
}

// Average calculates total sum divided total number of elements
float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

// 1st Method for Reverse Copy
// Reverse copy from array A to B, then copy B to A
// Time Complexity: O(n)
// Copy from array A to B takes n time
// Copy from B to A takes n time
void Reverse1(struct Array *arr)
{
    int *arrB;
    arrB = (int *)malloc(arr->length*sizeof(int));

    // Reverse copy arr->A into arrB
    for(int i = arr->length-1, j = 0; i >= 0; i--, j++)
    {
        arrB[j] = arr->A[i];
    }
    // Copy arrB into arr->A
    for(int i = 0; i < arr->length; i++)
    {
        arr->A[i] = arrB[i];
    }
}

// 2nd Method for Reverse Copy
// Scan from two ends of an array and swap the elements
// until scan has reached middle of array
// Stop when i and j have reached the same place or when i > j
// Time Complexity: O(n)
void Reverse2(struct Array *arr)
{
    for(int i = 0, j = arr->length-1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

// Left Shift
// Shift all elements by n time(s) to left, lose first element, last element becomes 0
// Time Complexity: O(n)
void LeftShift(struct Array *arr, int n)
{
    // number of times to left shift
    while(n > 0)
    {
        // 1 left shift
        // ex: 2,3,4,5,6 = 3,4,5,6,0
        for(int i = 0; i+1 < arr->length; i++)
        {
            arr->A[i] = arr->A[i+1];    
        }
        arr->A[arr->length-1] = 0;
        // decrement
        n--;
    }
}

// Left Rotate
// Similar to left shift, but instead of first element 
// being removed, it is placed at the last element
// Time Complexity: O(n)
// Ex: LED Display boards have text that is scrolling aka rotating
void LeftRotate(struct Array *arr, int n)
{
    // number of times to left rotate
    while(n > 0)
    {
        // 1 left rotate
        // ex: 2,3,4,5,6 = 3,4,5,6,0
        int temp = arr->A[0];
        for(int i = 0; i+1 < arr->length; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->A[arr->length-1] = temp;
        // decrement
        n--;
    }
}

// Right Shift
// Shift all elements by n time(s) to right, lose last element, first element becomes 0
// Time Complexity: O(n)
void RightShift(struct Array *arr, int n)
{
    // number of times to right shift
    while(n > 0)
    {
        // 1 right shift
        // ex: 2,3,4,5,6 = 0,2,3,4,5
        for(int i = arr->length-1; i-1 >= 0; i--)
        {
            arr->A[i] = arr->A[i-1];    
        }
        arr->A[0] = 0;
        // decrement
        n--;
    }
}

// Right Rotate
// Similar to right shift, but instead of last element 
// being removed, it is copied to the first element
void RightRotate(struct Array *arr, int n)
{
    // number of times to right shift
    while(n > 0)
    {
        // 1 right shift
        // ex: 2,3,4,5,6 = 6,2,3,4,5
        int temp = arr->A[arr->length-1];
        for(int i = arr->length-1; i-1 >= 0; i--)
        {
            arr->A[i] = arr->A[i-1];    
        }
        arr->A[0] = temp;
        // decrement
        n--;
    }
}

// Insert in a Sorted Array
// Checking if an Array is Sorted
// Arranging all the elements on left side and right side

// InsertSort
// Insert new element such that it is inserted in it's sorted position
void InsertSort(struct Array *arr, int x)
{
    // stop array insert sort if there is no free space
    if(arr->length == arr->size)
    {
        return;
    }
    int i;
    for(i = arr->length-1; i >= 0 && arr->A[i] > x; i--)
    {
        arr->A[i+1] = arr->A[i];
    }
    arr->A[i+1] = x;
    arr->length++;
}

// isSorted
// Check whether an array is sorted or not
// If every element is smaller than the next number, then array is sorted
// Time Complexity: Best O(1), Worst O(n)
bool isSorted(struct Array arr)
{
    for(int i = 0; i < arr.length-1; i++)
    {
        if(arr.A[i] > arr.A[i+1])
        {
            return false;
        }
    }
    return true;
}

// Rearrange
// Arrange Negative and Positives on separate sides
// We have an array with mixed positive and negative numbers
// We want to bring negative numbers on left hand side and positive
// numbers on right hand side
// Time Complexity: O(n)
void Rearrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length-1;
    while(i < j)
    {
        // increment while A[i] is negative, break when it's positive
        while(arr->A[i] < 0)
        {
            i++;
        } // decrement while A[j] is positive, break when it's negative
        while(arr->A[j] >= 0)
        {
            j--;
        } // if index i is not past index j, swap pos and neg element
        if(i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}

// Merge
// Time Complexity: O(m + n)
// Merge two sorted arrays into one sorted array 
// Compare array A[i] with B[j], whichever is the smaller copy it into C[k]
// Move to next element of input array, move to next element index of res array
// Keep comparing A[i] with B[j] until one of the arrays ends, then in the
// other array copy the remaining elements into the res array
struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j = 0, k = 0;
    // Create an array pointer in heap of size array
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array)); 

    // Compare elements in arr1 with arr2. Copy smallest element into arr3
    // Keep comparing until one of the arrays ends
    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    // Copy any remaining elements from both arrays into arr3
    for(; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i++];
    }
    for(; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j++];
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    // Array struct is written in heap, return arr3 pointer
    return arr3;
}