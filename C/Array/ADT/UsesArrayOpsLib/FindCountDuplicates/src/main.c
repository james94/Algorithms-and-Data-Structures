#include "ArrayOperations.h"

// Needed for memcpy
#include <string.h>

int main()
{
    // Sorted Array
    int numbers1[] = {3,6,8,8,10,12,15,15,15,20};
    struct Array arr1 = {numbers1, 20, 10};
    Display(arr1);
    printf("\nFind Duplicate Elements in Sorted Array:\n");
    FindDuplicateElements(arr1);

    Display(arr1);
    printf("\nCount Duplicate Elements in Sorted Array:\n");
    CountDuplicateElements(arr1);

    printf("\nCount Duplicate Elements in Sorted Array using Hash Table:\n");
    CountDuplicateElements2(arr1);

    // Unsorted Array
    int numbers2[] = {8,3,6,4,6,5,6,8,2,7};
    struct Array arr2 = {numbers2, 10, 10};
    // memcpy: *dest array, *src array, n bytes copied
    int numbers2Copy[arr2.length];
    memcpy(numbers2Copy, arr2.A, arr2.length*sizeof(int));
    Display(arr2);
    printf("\nCount Duplicate Elements in Unsorted Array via Brute Force:\n");
    CountDuplicateElementsUA(arr2);

    arr2.A = numbers2Copy;
    Display(arr2);
    printf("\nCount Duplicate Elements in Unsorted Array via Hash Table:\n");
    CountDuplicateElementsUA2(arr2);
    return 0;
}