#include "ArrayOperations.h"

int main()
{
    // Static Array
    // Initialize it inside the object, fill elements,
    // size of array, number of elements in array
    struct Array arr = {{2,3,4,5,6},20,5};

    //Insert(&arr, 5, 10);
    //Insert(&arr, 0, 10);
    Insert(&arr, 2, 10);
    //Insert(&arr, -2, 10);
    //Insert(&arr, 9, 10);

    Display(arr);
    return 0;
}