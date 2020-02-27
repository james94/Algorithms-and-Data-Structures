#include "ArrayOperations.h"

int main()
{
    // Static Array
    // Initialize it inside the object, fill elements,
    // size of array, number of elements in array
    struct Array arr = {{2,3,4,5,6},20,5};

    // printf("%d\n", LinearSearch(arr, 4));
    // printf("%d\n", LinearSearch(arr, 6));
    // printf("%d\n", LinearSearch(arr, 15));
    // printf("%d\n", LinearSearch2(&arr, 6));
    // printf("%d\n", LinearSearch2(&arr, 5));
    printf("%d\n", LinearSearch3(&arr, 5));

    Display(arr);
    return 0;
}