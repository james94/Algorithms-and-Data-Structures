#include "ArrayOperations.h"

int main()
{
    //struct Array arr = {{2,3,4,5,6},10,5};
    // struct Array arr = {{2,3,14,5,6},10,5};
    // struct Array arr = {{2,3,14,25,6},10,5};
    struct Array arr = {{23,3,14,25,6},10,5};

    // Get array value at index 2
    // printf("%d\n", Get(arr,2));
    // printf("%d\n", Get(arr,0));
    printf("Set value at index 0 to be 15\n");
    Set(&arr, 0, 15);

    printf("Get value at index 9 = %d\n", Get(arr,9));
    
    printf("Max array value = %d\n", Max(arr));

    printf("Min array value = %d\n", Min(arr));

    printf("Sum of all array elements = %d\n", Sum(arr));

    printf("Average for this array = %f\n", Avg(arr));
    Display(arr);
    return 0;
}