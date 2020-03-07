#include "ArrayOperations.h"

int main()
{
    int data1[] = {5,8,3,9,6,2,10,7,-1,4};
    struct Array arr1 = {data1,10,10};
    int min = -1, max = -1;
    Display(arr1);
    printf("\nFind Min and Max in a Single Scan:\n");
    FindMaxMinSingleScan(arr1, &min, &max);
    printf("Min = %d\n", min);
    printf("Max = %d\n", max);

    // Best Compilation: n-1
    int data2[] = {10,9,8,7,2,1};
    struct Array arr2 = {data2,6,6};
    Display(arr2);
    printf("\nFind Min and Max for Best Compilation:\n");    
    FindMaxMinSingleScan(arr2, &min, &max);
    printf("Min = %d\n", min);
    printf("Max = %d\n", max);

    // Worst Compilation: 2(n-1)
    int data3[] = {1,2,3,5,8,9,10};
    struct Array arr3 = {data3,7,7};
    Display(arr3);
    printf("\nFind Min and Max for Worst Compilation:\n");
    FindMaxMinSingleScan(arr3, &min, &max);
    printf("Min = %d\n", min);
    printf("Max = %d\n", max);
    return 0;
}