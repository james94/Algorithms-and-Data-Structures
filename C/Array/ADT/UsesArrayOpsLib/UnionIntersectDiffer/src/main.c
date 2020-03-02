#include "ArrayOperations.h"

int main()
{
    struct Array arr1 = {{2,6,10,15,25},10,5};
    struct Array arr2 = {{3,6,7,15,20},10,5};
    // Pointer arr3 to array since function Union will create an array
    struct Array *arr3, *arr4, *arr5;
    printf("Union of arr1 and arr2 stored into arr3:");
    // Store result of Union of arr1 and arr2 into arr3
    arr3 = Union(&arr1, &arr2);
    // Display Union result
    Display(*arr3);
    printf("\n\n");

    printf("Intersection of arr1 and arr2 stored into arr4:");
    // Store result of Intersect of arr1 and arr2 into arr4
    arr4 = Intersection(&arr1, &arr2);
    // Display Intersect result
    Display(*arr4);
    printf("\n\n");

    printf("Difference of arr1 and arr2 stored into arr5:");
    // Store result of Difference of arr1 and arr2 into arr4
    arr5 = Difference(&arr1, &arr2);
    // Display Difference result
    Display(*arr5);
    printf("\n\n");

    printf("Set Membership finds if 15 is in Set arr1:\n");
    // Store result of Difference of arr1 and arr2 into arr4
    printf("15 is at arr1 index %d\n", SetMembership(arr1, 15));
    return 0;
}