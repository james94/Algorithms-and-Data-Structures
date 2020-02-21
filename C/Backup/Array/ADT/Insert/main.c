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

int main()
{
    // Static Array
    // Initialize it inside the object, fill elements,
    // size of array, number of elements in array
    struct Array arr = {{2,3,4,5,6},20,5};

    //Insert(&s_arr, 5, 10);
    //Insert(&s_arr, 0, 10);
    //Insert(&s_arr, 2, 10);
    //Insert(&s_arr, -2, 10);
    Insert(&arr, 9, 10);

    Display(arr);
    return 0;
}