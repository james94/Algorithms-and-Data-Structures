#include "ArrayOperations.h"

using std::cout;

Array::Array()
{
    _size = 10;
    _length = 0;
    _A = new int[_size];
}

Array::Array(int size)
{
    _size = size;
    _length = 0;
    _A = new int[_size];
}

Array::~Array()
{
    delete []_A;
}

// Display all elements in static array
void Array::Display()
{
    cout << "\nElements are\n";
    for(int i = 0; i < _length; i++)
    {
        cout << _A[i] << " ";
    }
}

// Insert new element at the end of array
// Time Complexity: O(1). 
// Work: f(n) = 2; f(n) = 2n^0; O(n^0) = O(1).
void Array::Append(int x)
{
    if(_length < _size)
    {
        _A[_length++] = x;
    }
}

// Insert new element at index
// Time Complexity: Best O(1); Worst O(n) 
void Array::Insert(int index, int x)
{
    int i;
    if(index >= 0 && index <= _length)
    {
        for(i = _length; i > index; i--)
        {
            _A[i] = _A[i-1];
        }
        _A[index] = x;
        _length++;
    }
}

// Delete element from array
// Time Complexity: Best O(1), Worst O(n)
int Array::Delete(int index)
{
    int x = 0;
    int i;

    // check whether extra index is valid or not
    if(index >= 0 && index < _length)
    {
        x = _A[index];
        // stop at length-1 since shifting elements
        for(i = index; i < _length-1; i++)
        {
            _A[i] = _A[i+1];
        }
        _length--;
        // returns element value deleted
        return x;
    }
    return 0;
}

// Linear Search for element in array
// Time Complexity: 
// Successful: Best - O(1), Worst - O(n), Avg - O(n)
// Unsuccessful: O(n)
int Array::LinearSearch(int key)
{
    for(int i = 0; i < _length; i++)
    {
        if(key == _A[i])
        {
            return i;
        }
    }
    return -1;
}

// Helper function for LinearSearch2, LinearSearch3
void Array::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Transposition - Linear Search
// Move searched element one step forward
// So next time it can be searched faster
int Array::LinearSearch2(int key)
{
    for(int i = 0; i < _length; i++)
    {
        if(key == _A[i])
        {
            swap(&_A[i], &_A[i-1]);
            // return searched element that swapped one step forward
            return i-1;
        }
    }
    return -1;
}

// Move to Front - Linear Search
// Swap searched element with first element
// So next time if you search for same element, it will be found in constant time
int Array::LinearSearch3(int key)
{
    for(int i = 0; i < _length; i++)
    {
        if(key == _A[i])
        {
            swap(&_A[i], &_A[0]);
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
int Array::BinarySearch(int key)
{
    int l, mid, h;
    l = 0;
    h = _length - 1;

    while(l <= h)
    {
        mid = (l + h) / 2;
        
        if(key == _A[mid])
        {
            return mid;
        }
        // key is on left side
        else if(key < _A[mid])
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
int Array::RBinSearch(int l, int h, int key)
{
    int mid;

    if(l <= h)
    {
        mid = (l + h) / 2;
        if(key == _A[mid])
        {
            return mid;
        }
        // key is on left side
        else if(key < _A[mid])
        {
            return RBinSearch(l, mid-1, key);
        } // key is on right side
        else
        {
            return RBinSearch(mid+1, h, key);
        }
    }
    return -1;
}

// Get
// Returns element at particular index
// Time Complexity: O(1)
int Array::Get(int index)
{
    if(index >= 0 && index < _length)
    {
        return _A[index];
    }
    return -1;
}

// Set
// Replace value at a particular index
// Time Complexity: O(1)
void Array::Set(int index, int x)
{
    if(index >= 0 && index < _length)
    {
        _A[index] = x;
    }
}

// Max finds maximum element in array
// For unsorted array, must check all elements
// For sorted array, check either first or last element
// Time Complexity: O(n)
int Array::Max()
{
    int max = _A[0];
    for(int i = 0; i < _length; i++)
    {
        if(_A[i] > max)
        {
            max = _A[i];
        }
    }
    return max;
}

// Min finds minimum element in array
// Time Complexity: O(n)
int Array::Min()
{
    int min = _A[0];
    for(int i = 0; i < _length; i++)
    {
        if(_A[i] < min)
        {
            min = _A[i];
        }
    }
    return min;
}

// Iterative Sum calculates total of all elements adds them together
// Time Complexity: O(n)
int Array::Sum()
{
    int sum = 0;
    for(int i = 0; i < _length; i++)
    {
        sum += _A[i];
    }
    return sum;
}

// Recusrive Sum
int Array::RSum(int n)
{
    if(n < 0)
    {
        return 0;
    }
    else
    {
        return RSum(n-1) + _A[n];
    }
}

// Average calculates total sum divided total number of elements
float Array::Avg()
{
    return (float)Sum()/_length;
}

// 1st Method for Reverse Copy
// Reverse copy from array A to B, then copy B to A
// Time Complexity: O(n)
// Copy from array A to B takes n time
// Copy from B to A takes n time
void Array::Reverse1()
{
    int *arrB;
    arrB = new int[_length];

    // Reverse copy arr->A into arrB
    for(int i = _length-1, j = 0; i >= 0; i--, j++)
    {
        arrB[j] = _A[i];
    }
    // Copy arrB into arr->A
    for(int i = 0; i < _length; i++)
    {
        _A[i] = arrB[i];
    }
}

// 2nd Method for Reverse Copy
// Scan from two ends of an array and swap the elements
// until scan has reached middle of array
// Stop when i and j have reached the same place or when i > j
// Time Complexity: O(n)
void Array::Reverse2()
{
    for(int i = 0, j = _length-1; i < j; i++, j--)
    {
        swap(&_A[i], &_A[j]);
    }
}

// Left Shift
// Shift all elements by n time(s) to left, lose first element, last element becomes 0
// Time Complexity: O(n)
void Array::LeftShift(int n)
{
    // number of times to left shift
    while(n > 0)
    {
        // 1 left shift
        // ex: 2,3,4,5,6 = 3,4,5,6,0
        for(int i = 0; i+1 < _length; i++)
        {
            _A[i] = _A[i+1];    
        }
        _A[_length-1] = 0;
        // decrement
        n--;
    }
}

// Left Rotate
// Similar to left shift, but instead of first element 
// being removed, it is placed at the last element
// Time Complexity: O(n)
// Ex: LED Display boards have text that is scrolling aka rotating
void Array::LeftRotate(int n)
{
    // number of times to left rotate
    while(n > 0)
    {
        // 1 left rotate
        // ex: 2,3,4,5,6 = 3,4,5,6,0
        int temp = _A[0];
        for(int i = 0; i+1 < _length; i++)
        {
            _A[i] = _A[i+1];
        }
        _A[_length-1] = temp;
        // decrement
        n--;
    }
}

// Right Shift
// Shift all elements by n time(s) to right, lose last element, first element becomes 0
// Time Complexity: O(n)
void Array::RightShift(int n)
{
    // number of times to right shift
    while(n > 0)
    {
        // 1 right shift
        // ex: 2,3,4,5,6 = 0,2,3,4,5
        for(int i = _length-1; i-1 >= 0; i--)
        {
            _A[i] = _A[i-1];    
        }
        _A[0] = 0;
        // decrement
        n--;
    }
}

// Right Rotate
// Similar to right shift, but instead of last element 
// being removed, it is copied to the first element
void Array::RightRotate(int n)
{
    // number of times to right shift
    while(n > 0)
    {
        // 1 right shift
        // ex: 2,3,4,5,6 = 6,2,3,4,5
        int temp = _A[_length-1];
        for(int i = _length-1; i-1 >= 0; i--)
        {
            _A[i] = _A[i-1];    
        }
        _A[0] = temp;
        // decrement
        n--;
    }
}

// Insert in a Sorted Array
// Checking if an Array is Sorted
// Arranging all the elements on left side and right side

// InsertSort
// Insert new element such that it is inserted in it's sorted position
void Array::InsertSort(int x)
{
    // stop array insert sort if there is no free space
    if(_length == _size)
    {
        return;
    }
    int i;
    for(i = _length-1; i >= 0 && _A[i] > x; i--)
    {
        _A[i+1] = _A[i];
    }
    _A[i+1] = x;
    _length++;
}

// isSorted
// Check whether an array is sorted or not
// If every element is smaller than the next number, then array is sorted
// Time Complexity: Best O(1), Worst O(n)
bool Array::isSorted()
{
    for(int i = 0; i < _length-1; i++)
    {
        if(_A[i] > _A[i+1])
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
void Array::Rearrange()
{
    int i = 0;
    int j = _length-1;
    while(i < j)
    {
        // increment while A[i] is negative, break when it's positive
        while(_A[i] < 0)
        {
            i++;
        } // decrement while A[j] is positive, break when it's negative
        while(_A[j] >= 0)
        {
            j--;
        } // if index i is not past index j, swap pos and neg element
        if(i < j)
        {
            swap(&_A[i], &_A[j]);
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
Array* Array::Merge(Array arr2)
{
    int i = 0, j = 0, k = 0;
    // Create an array pointer in heap of size array
    Array *arr3 = new Array(_length + arr2._length);

    // Compare elements in arr1 with arr2. Copy smallest element into arr3
    // Keep comparing until one of the arrays ends
    while(i < _length && j < arr2._length)
    {
        if(_A[i] < arr2._A[j])
        {
            arr3->_A[k++] = _A[i++];
        }
        else
        {
            arr3->_A[k++] = arr2._A[j++];
        }
    }
    // Copy any remaining elements from both arrays into arr3
    for(; i < _length; i++)
    {
        arr3->_A[k++] = _A[i];
    }
    for(; j < arr2._length; j++)
    {
        arr3->_A[k++] = arr2._A[j];
    }
    arr3->_length = _length + arr2._length;

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
Array* Array::Union(Array arr2)
{
    int i = 0, j = 0, k = 0;
    // Create an array pointer in heap of size array
    Array *arr3 = new Array(_length + arr2._length);

    // Compare elements in arr1 with arr2. Copy smallest element into arr3
    // Keep comparing until one of the arrays ends
    while(i < _length && j < arr2._length)
    {
        if(_A[i] < arr2._A[j])
        {
            arr3->_A[k++] = _A[i++];
        }
        else if(arr2._A[j] < _A[i])
        {
            arr3->_A[k++] = arr2._A[j++];
        }
        else
        {
            arr3->_A[k++] = _A[i++];
            j++;
        }
    }
    // Copy any remaining elements from both arrays into arr3
    for(; i < _length; i++)
    {
        arr3->_A[k++] = _A[i];
    }
    for(; j < arr2._length; j++)
    {
        arr3->_A[k++] = arr2._A[j];
    }
    arr3->_length = k;

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
Array* Array::Intersection(Array arr2)
{
    int i = 0, j = 0, k = 0;
    // Create an array pointer in heap of size array 
    Array *arr3 = new Array(_length + arr2._length);

    // Compare elements in arr1 with arr2. Copy smallest element into arr3
    // Keep comparing until one of the arrays ends
    while(i < _length && j < arr2._length)
    {
        if(_A[i] < arr2._A[j])
        {
            i++;
        }
        else if(arr2._A[j] < _A[i])
        {
            j++;
        }
        else if(_A[i] == arr2._A[j])
        {
            arr3->_A[k++] = _A[i++];
            j++;
        }
    }

    arr3->_length = k;

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
Array* Array::Difference(Array arr2)
{
    int i = 0, j = 0, k = 0;
    // Create an array pointer in heap of size array
    Array *arr3 = new Array(_length + arr2._length);

    // Compare elements in arr1 with arr2. Copy smallest element into arr3
    // Keep comparing until one of the arrays ends
    while(i < _length && j < arr2._length)
    {
        // Only elements in arr1 are copied to arr3
        if(_A[i] < arr2._A[j])
        {
            arr3->_A[k++] = _A[i++];
        }// second arr2 elements are skipped
        else if(arr2._A[j] < _A[i])
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
    for(; i < _length; i++)
    {
        arr3->_A[k++] = _A[i];
    }

    arr3->_length = k;

    // Array struct is written in heap, return arr3 pointer
    return arr3;
}

// Set Membership Operation
// To know whether an element belongs to a Set or Not
// Like 10 belongs to set A or not, yes it is there, so it belongs to set A
// So, Set Membership is the SAME as searching. I chose to use Binary Search.
// Set uses Binary Search to know whether an element belongs to a Set or Not.
int Array::SetMembership(int key)
{
    int l, mid, h;
    l = 0;
    h = _length - 1;

    while(l <= h)
    {
        mid = (l + h) / 2;
        
        if(key == _A[mid])
        {
            return mid;
        }
        // key is on left side
        else if(key < _A[mid])
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