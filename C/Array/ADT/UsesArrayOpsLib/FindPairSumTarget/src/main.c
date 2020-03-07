#include "ArrayOperations.h"

int main()
{
    int data1[] = {6,3,8,10,16,7,5,2,9,14};
    struct Array arr1 = {data1,10,10};
    int target = 10;
    Display(arr1);
    printf("\nFind a Pair with Sum Target in Unsorted Array using Brute Force:\n");
    FindPairSumTarget(arr1, target);

    Display(arr1);
    printf("\nFind a Pair with Sum Target in Unsorted Array using Hash Table:\n");
    FindPairSumTargetHT(arr1, target);

    int data2[] = {1,3,4,5,6,8,9,10,12,14};
    struct Array arr2 = {data2,10,10};
    Display(arr2);
    printf("\nFind a Pair with Sum Target in Sorted Array using 2 Indices i, j:\n");
    FindPairSumTarget2(arr2, target);
    return 0;
}