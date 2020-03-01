#include "ArrayOperations.h"

int main()
{
    // sorted array
    // struct Array arr = {{2,3,5,10,15},20,5};

    // modified array to be unsorted
    // struct Array arr = {{2,3,25,10,15},20,5};

    // modified array to have negative and positive numbers
    struct Array arr = {{2,-3,25,10,-15,-7},20,5};

    printf("Insert Element into Array in Sorted Position");
    // InsertSort(&arr, 20);
    // Should be inserted between 10 and 15
    // InsertSort(&arr, 12);
    // Should be inserted between 3 and 5
    // InsertSort(&arr, 4);
    // Should be inserted before 2
    InsertSort(&arr, 1);
    Display(arr);
    printf("\n\n");

    printf("Check is Array Sorted: ");
    // Check is array sorted
    printf("%d \n", isSorted(arr));

    printf("\nRearrange Negative and Positive Numbers");
    // All negative on left side and positive on right side
    Rearrange(&arr);
    Display(arr);
    return 0;
}