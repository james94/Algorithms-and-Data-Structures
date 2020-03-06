#include "ArrayOperations.h"

int main()
{
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
    return 0;
}