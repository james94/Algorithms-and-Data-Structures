#include "ArrayOperations.h"

int main()
{
    struct Array arr1 = {{2,3,4,5,6},10,5};
    struct Array arr2 = arr1;
    struct Array arr3 = arr1;
    struct Array arr4 = arr1;
    struct Array arr5 = arr1;
    struct Array arr6 = arr1;

    // Reverse array by copying from array A to B, then copy B to A
    printf("Method 1 for Reversing Array");
    Reverse1(&arr1);
    Display(arr1);
    printf("\n\n");

    // Reverse array by scanning from two ends of an array, swap the 
    // elements until scan has reached middle of array
    printf("Method 2 for Reversing Array");    
    Reverse2(&arr2);
    Display(arr2);
    printf("\n\n");

    // Left Shift all elements by 1 time. lose first element, last 
    // element becomes 0
    printf("Left Shift All Elements by 2 times");
    LeftShift(&arr3, 2);
    Display(arr3);
    printf("\n\n");

    // Left Rotate all elements by 1 time. copy first element, last 
    // element becomes first element's value
    printf("Left Rotate All Elements by 2 times");
    LeftRotate(&arr4, 2);
    Display(arr4);
    printf("\n\n");

    // Right Shift all elements by 1 time. lose last element, first 
    // element becomes 0
    printf("Right Shift All Elements by 1 time");
    RightShift(&arr5, 1);
    Display(arr5);
    printf("\n\n");

    // Right Rotate all elements by 1 time. copy last element, first 
    // element becomes last element's value
    printf("Right Rotate All Elements by 1 time");
    RightRotate(&arr6, 1);
    Display(arr6);
    printf("\n\n");
    return 0;
}