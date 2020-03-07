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
        arr3->A[k++] = arr1->A[i];
    }
    for(; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    // Array struct is written in heap, return arr3 pointer
    return arr3;
}

// Set Operations

// Union
// Copy all elements and duplicates one time between arr1 and arr2 into arr3

// TODO: Union (Unsorted Arrays)
// Combine two unsorted arrays into single array without duplicates
// Store arr1 into arr3. Search if arr2 element is in
// arr1 and if not, store it into arr3. Do this
// procedure with arr2 until array ends
// Time Complexity: O(n^2)
// Steps: m + m*n. Replace m with n: n + n*n. 
// Simplified: n + n^2 = n^2

// Union (Sorted Arrays)
// Apply Merge-like operation to combine two sorted arrays into single
// array without duplicates. Minor change to Merge is if arr1 and arr2
// element we are currently on is the same, copy element only once into
// arr3. Then increment pointer to next element in arr1 and arr2.
// Time Complexity: O(n)
// Steps: O(m+n). Replace m with n, so O(n+n) = O(2n) = O(n)
struct Array* Union(struct Array *arr1, struct Array *arr2)
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
        else if(arr2->A[j] < arr1->A[i])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    // Copy any remaining elements from both arrays into arr3
    for(; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for(; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = 10;

    // Array struct is written in heap, return arr3 pointer
    return arr3;
}

// Intersection
// Copy only duplicates between arr1 and arr2 into arr3

// TODO: Intersection (Unsorted Arrays)
// Take common elements of arr1 and arr2 and store them into arr3
// While copying arr1 elements into arr3, check if they are present
// in arr2, if they are present, then copy them, else don't copy them.
// Time Complexity: O(n^2)
// Steps: O(n*m). Replace m with n to write single letter. O(n*n) = O(n^2).

// Intersection (Sorted Arrays)
// Apply Merge-like operation to combine two sorted arrays into single
// array with only duplicates. Minor change to Merge is if arr1 and arr2
// element we are currently on is different, don't copy element into arr3.
// If arr1 and arr2 element we are on is the same, copy element into arr3.
// Reminder: with Merge we ask is A's element < B, if true, don't copy it to C.
// Time Complexity: O(n)
// Steps: O(m+n). Replace m with n, so O(n+n) = O(2n) = O(n)
struct Array* Intersection(struct Array *arr1, struct Array *arr2)
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
            i++;
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else if(arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;

    // Array struct is written in heap, return arr3 pointer
    return arr3;
}

// Difference: A - B aka arr1 - arr2

// TODO: Difference (Unsorted Arrays)
// A - B means we want all those elements which are in A that are NOT
// in B. So, subtract the common elements between A and B and take only
// those elements that are only in A, not in B at all.
// With each element we look at in A, check is it present in B, if true,
// then don't copy it in C. Else if false, copy it into C.
// Time Complexity: O(n^2)
// Steps: O(n*m). Replace m with n to write single letter. O(n*n) = O(n^2).

// Difference (Sorted Arrays)
// Apply Merge-like operation to copy sorted array A elements into array C
// that are NOT present in array B. Minor change to Merge is if A and B
// element we are currently on is the same, don't copy element into C.
// If A and B element we are on is different, copy A's element into C.
// Reminder: with Merge we ask is A's element < B, if true, copy it to C.
// Time Complexity: O(n)
// Steps: O(m+n). Replace m with n, so O(n+n) = O(2n) = O(n)
struct Array* Difference(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j = 0, k = 0;
    // Create an array pointer in heap of size array
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array)); 

    // Compare elements in arr1 with arr2. Copy smallest element into arr3
    // Keep comparing until one of the arrays ends
    while(i < arr1->length && j < arr2->length)
    {
        // Only elements in arr1 are copied to arr3
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }// second arr2 elements are skipped
        else if(arr2->A[j] < arr1->A[i])
        {
            j++;
        } // if both arr1 and arr2 elements are equal, skip both
        else
        {
            i++;
            j++;
        }
    }
    // Copy any remaining elements from arr1 into arr3
    for(; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    arr3->length = k;
    arr3->size = 10;

    // Array struct is written in heap, return arr3 pointer
    return arr3;
}

// Set Membership Operation
// To know whether an element belongs to a Set or Not
// Like 10 belongs to set A or not, yes it is there, so it belongs to set A
// So, Set Membership is the SAME as searching. I chose to use Binary Search.
// Set uses Binary Search to know whether an element belongs to a Set or Not.
int SetMembership(struct Array arr, int key)
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

// Challenges

// Find Single Missing Element
// Prerequisite: Sort Array if not sorted
// Time Complexity: O(n)
void FindMissingElement(struct Array arr)
{
    int l = arr.A[0];
    int h = arr.A[arr.length-1];
    int diff = l - 0;
    for(int i = 0; i < arr.length; i++)
    {
        // found missing element
        if(arr.A[i] - i != diff)
        {
            printf("%d\n", i+diff);
            break;
        }
    }
}

// Find Multiple Missing Elements in a sorted array
// and the sequence of elements maybe starting from 1 onwards
// maybe starting from any other number
// Prerequisite: Sort Array if not sorted
// Time Complexity: O(n)
void FindMissingElements(struct Array arr)
{
    int l = arr.A[0];
    int h = arr.A[arr.length-1];
    int diff = l - 0;
    for(int i = 0; i < arr.length; i++)
    {
        // found missing element(s)
        if(arr.A[i] - i != diff)
        {
            // accesses all elements missing any element, prints them
            // don't have to consider time of the loop since its neglible
            // it is filling up the gaps of missing elements
            while(diff < arr.A[i] - i)
            {
                printf("%d\n", i + diff);
                diff++;
            }
        }
    }
}

// Take an array equal to the max element you have in the sequence that is
// the size. Ex: 12 is largest element in first array, then size of new array
// is 12. The first array will be traversed, each element will be looked up in
// in the Hash Table, then 0 will be changed to 1. We come back to Hash Table
// traverse it to look for the Hash Table's elements that equal 0, those are the
// missing element(s)
// Time Complexity: O(n)
void FindMissingElements2(struct Array arr)
{
    int l = Min(arr);
    int h = Max(arr);
    int *H;
    // Allocate x number of elements for Hash Table based on largest element h in arr
    // h is the size of the Hash Table
    // h+1 so H Hash Table has highest element number from arr as an index
    H = (int *)malloc((h+1)*sizeof(int));
    for(int i = 0; i <= h; i++)
    {
        H[i] = 0;
    }

    // mark each found element in arr in Hash Table with 1 for it exists
    for(int i = 0; i < arr.length; i++)
    {
        H[arr.A[i]]++;
    }

    // find missing element(s)
    for(int i = l; i <= h; i++)
    {
        if(H[i] == 0)
        {
            printf("%d\n", i);
        }
    }
}

// Find Duplicate Elements
// Keep a copy of the last duplicate element, traverse the array
// check if current element equals next element and last duplicate
// does not equal current element, if true, then print duplicate
// and update found duplicate.
// Time Complexity: O(n)
void FindDuplicateElements(struct Array arr)
{
    int lastDuplicate = 0;
    // arr.length-1 since we check the 2nd to last element against the last element
    for(int i = 0; i < arr.length-1; i++)
    {
        if(arr.A[i] == arr.A[i+1] && arr.A[i] != lastDuplicate)
        {
            printf("%d\n", arr.A[i]);
            lastDuplicate = arr.A[i];
        }
    }
}

// Count Duplicate Elements
// Traverse the array, check if current element equals next element if true,
// then set j pointer one ahead of i, loop while next element at j index equals
// current element at index i and increment j. Break from loop, print duplicate
// number is appearing x amount of times. i jumps to the index right before j
// Time Complexity: O(n)
void CountDuplicateElements(struct Array arr)
{
    for(int i = 0; i < arr.length; i++)
    {
        if(arr.A[i] == arr.A[i+1])
        {
            int j = i + 1;
            // loop is neglible toward time since we don't traverse all elements
            // just a part of the array and i jumps to the index right before j 
            while(arr.A[j] == arr.A[i]) j++;
            printf("%d is appearing %d times\n", arr.A[i], j-i);
            i = j - 1;
        }
    }
}

// Find and Count Duplicates using Hash Table
// How much work are we doing?
// Scan through the n elements in array only 1 time
// and while scanning we are marking the elements in the Hash Table
// that is we are incrementing the counts per element.
// incrementing takes constant time since we can lookup element in Hash Table
// Time Complexity: O(n)
void CountDuplicateElements2(struct Array arr)
{
    int h = Max(arr);
    // Hash Table size is based on highest number in arr plus 1, so we
    // include the highest number as an index in our Hash Table
    int *H = (int *)malloc((h+1) * sizeof(int));

    for(int i = 0; i <= h; i++)
    {
        H[i] = 0;
    }

    // Traverse array and increment the counts per element in hash table
    for(int i = 0; i < arr.length; i++)
    {
        H[arr.A[i]]++;
    }

    for(int i = 0; i <= h; i++)
    {
        if(H[i] > 1)
        {
            printf("%d is appearing %d times\n", i, H[i]);
        }
    }
}

// Finding and Counting Duplicate Elements in Unsorted Array

// Find and Count Duplicate Elements in Unsorted Array using Brute Force
// To find a duplicate element, start with the count at 1 and an element at 
// index i, then compare it with the rest of the elements and when a 
// duplicate appears, set index j to one ahead of index i, then increment 
// count and mark that duplicate with -1, so we don't check it for duplicate 
// elements. When index j reaches end of array, check is count > 1, if true,
// print duplicate element d appears d times
// Time Complexity: O(n^2)
void CountDuplicateElementsUA(struct Array arr)
{
    for(int i = 0; i < arr.length-1; i++)
    {
        int count = 1;
        if(arr.A[i] != -1)
        {
            for(int j = i+1; j < arr.length; j++)
            {
                if(arr.A[i] == arr.A[j])
                {
                    count++;
                    arr.A[j] = -1;
                }
            }
            if(count > 1)
            {
                printf("%d is appearing %d times\n", arr.A[i], count);
            }
        }
    }
}

// Find and Count Duplicate Elements in Unsorted Array using Hash Table
// The size of the Hash Table array should be equal to the largest element in our
// input array. If the largest element is 8, we want to make sure our last index
// of our Hash Table is 8, so the Hash Table size is 8+1 = 9 for 0...8 indices.
// Scan through the input array and for each element, increment the count in the
// Hash Table. Next, we scan through the Hash Table, wherever the value is > 0,
// an element is present there and if value is > 1, then a duplicate is there
void CountDuplicateElementsUA2(struct Array arr)
{
    // Find, count and display duplicate elements
    int l = Min(arr);
    int h = Max(arr);
    // Hash Table size equals the largest element in arr plus 1, so we include the
    // largest element as an index in our Hash Table
    int *H = (int *)malloc((h+1)*sizeof(int));

    for(int i = 0; i <= h; i++)
    {
        H[i] = 0;
    }

    // Traverse array and increment the counts per element in Hash Table
    for(int i = 0; i < arr.length; i++)
    {
        H[arr.A[i]]++;
    }

    for(int i = 0; i <= h; i++)
    {
        if(H[i] > 1)
        {
            printf("%d is appearing %d times\n", i, H[i]);
        }
    }
}

// Find a Pair with Sum Target (a+b=target) in Unsorted Array using Brute Force
// Time Complexity: O(n^2)
// n-1 + n-2 + ... + 3 + 2 + 1 = n(n-1)/2 = O(n^2)
// Start with element at index i, check is there another element
// at index j = i+1 that when summed is equal to the target.
// If false, keep incrementing j until a match is found or 
// reached end of array, then increment i and check j again.
// Repeat this sequence until either a match is found or not.
// If match found, print it.
void FindPairSumTarget(struct Array arr, int target)
{
    for(int i = 0; i < arr.length-1; i++)
    {
        for(int j = i+1; j < arr.length; j++)
        {
            if(arr.A[i] + arr.A[j] == target)
            {
                printf("%d + %d = %d\n", arr.A[i], arr.A[j], target);
                break;
            }
        }
    }
}

// Find a Pair with Sum Target (a+b=target) in Unsorted Array using Hash Table 
// Time Complexity: O(n)
// Traverse all elements in array arr, lookup target - element[i]
// in Hash Table to see if it doesn not equal 0, if true, then we found
// our second element that sums with element[i] to equal our target.
// Then print the pair sum to the screen.
// This algorithm is faster than brute force. If you want to save time,
// then the space taken will be more and vise versa.
void FindPairSumTargetHT(struct Array arr, int target)
{
    int h = Max(arr);
    int *H = (int *)malloc((h+1)*sizeof(int));
    for(int i = 0; i < arr.length; i++)
    {
        if(H[target-arr.A[i]] != 0)
        {
            printf("%d + %d = %d\n", arr.A[i], target-arr.A[i], target);
        }
        H[arr.A[i]]++;
    }
}

// Find a Pair with Sum Target (a+b=target) in Sorted Array
// Time Complexity: O(n)
// Start index i at first element and index j at last element.
// check is sum of i's element and j's element equal to target,
// if true, then print and increment i, decrement j. If false,
// check is sum < target, if true, then increment i.
// else decrement j.
void FindPairSumTarget2(struct Array arr, int target)
{
    int i = 0, j = arr.length - 1;
    while(i < j)
    {
        if(arr.A[i] + arr.A[j] == target)
        {
            printf("%d + %d = %d\n", arr.A[i], arr.A[j], target);
            i++;
            j--;
        }
        else if(arr.A[i] + arr.A[j] < target)
        {
            i++;
        }
        else
        {
            j--;
        }
        
    }
}

// Find Max and Min in a Single Scan
// Time Complexity: O(n)
// Best Compilation = n-1; 10,9,8,7,2,1
// Worst Compilation = 2(n-1); 1,2,3,5,8,9,10
// Traverse the array, check is current element < minimum, if true
// update minimum. if false, check is current element > maximum,
// if true update maximum, else continue traversing array until end.
void FindMaxMinSingleScan(struct Array arr, int *min, int *max)
{
    *min = arr.A[0];
    *max = arr.A[0];

    for(int i = 1; i < arr.length; i++)
    {
        if(arr.A[i] < *min)
        {
            *min = arr.A[i];
        }
        else if(arr.A[i] > *max)
        {
            *max = arr.A[i];
        }
    }
}