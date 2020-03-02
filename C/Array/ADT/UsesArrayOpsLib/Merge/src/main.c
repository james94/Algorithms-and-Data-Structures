#include "ArrayOperations.h"

int main()
{
    struct Array arr1 = {{2,6,10,15,25},10,5};
    struct Array arr2 = {{3,4,7,18,20},10,5};
    // Pointer arr3 to array since function Merge will create an array
    struct Array *arr3;
    // Merge arr1 and arr2 into arr3
    arr3 = Merge(&arr1, &arr2);
    // Display Merge result
    Display(*arr3);
    return 0;
}