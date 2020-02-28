#include "ArrayOperations.h"

int main()
{
    struct Array arr = {{2,3,4,5,6},20,5};

    // Use Iterative Binary Search
    // printf("Iterative Binary Search\n");
    // printf("%d\n", BinarySearch(arr,2));
    // printf("%d\n", BinarySearch(arr,5));
    // printf("%d\n", BinarySearch(arr,10));
    //printf("%d\n", BinarySearch(arr,15));

    // Use Recursive Binary Search
    printf("Recursive Binary Search\n");
    printf("%d\n", RBinSearch(arr.A, 0, arr.length, 2));
    //printf("%d\n", RBinSearch(arr.A, 0, arr.length, 5));
    // printf("%d\n", RBinSearch(arr.A, 0, arr.length, 9));
    Display(arr);
    return 0;
}