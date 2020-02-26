#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Static Array Structure
struct Array
{
    int A[10]; // array of fixed size 20
    int size;
    int length; // number of elements inside array
};

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
void Append(struct Array *arr, int x)
{
    if(arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

// Insert new element at index
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

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Transposition - Linear Search
// Move searched element one step forward
// So next time it can be searched faster
int LinearSearch2X(struct Array *arr, int key)
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
int LinearSearch3X(struct Array *arr, int key)
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

int main()
{
    // Static Array
    // Initialize it inside the object, fill elements,
    // size of array, number of elements in array
    struct Array arr = {{2,3,4,5,6},20,5};

    // printf("%d\n", LinearSearch(arr, 4));
    // printf("%d\n", LinearSearch(arr, 6));
    // printf("%d\n", LinearSearch(arr, 15));
    // printf("%d\n", LinearSearch2X(&arr, 6));
    // printf("%d\n", LinearSearch2X(&arr, 5));
    printf("%d\n", LinearSearch3X(&arr, 5));

    Display(arr);
    return 0;
}