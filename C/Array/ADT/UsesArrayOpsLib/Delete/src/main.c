#include "ArrayOperations.h"

int main()
{
    // Static Array
    // Initialize it inside the object, fill elements,
    // size of array, number of elements in array
    struct Array arr = {{2,3,4,5,6},20,5};

    // Delete element at index
    //printf("%d\n", Delete(&arr, 4));
    printf("%d\n", Delete(&arr, 0));

    Display(arr);
    return 0;
}