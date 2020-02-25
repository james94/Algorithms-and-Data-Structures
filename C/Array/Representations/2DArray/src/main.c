#include <stdio.h>
#include <stdlib.h>

// 2D Array: mostly used for implementing matrices, table data

int main()
{
    // 2D array created in main memory with 3 rows, 4 columns
    int A[3][4] = {{1,2,3,4}, {2,4,6,8}, {1,3,5,7}};

    // Array of pointers that will point to arrays inside heap
    int *B[3];
    // Double pointer that will point to array of pointers inside heap
    // and those pointers in the heap array will each point to their own
    // arrays of ints in heap
    int **C;
    int i, j;

    // for changing row
    for(i = 0; i < 3; i++)
    {
        // Access all elements in the rows
        for(j = 0; j < 4; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    B[0] = (int *)malloc(4*sizeof(int));
    B[1] = (int *)malloc(4*sizeof(int));
    B[2] = (int *)malloc(4*sizeof(int));

    // // for changing row
    // for(i = 0; i < 3; i++)
    // {
    //     // Access all elements in the rows
    //     for(j = 0; j < 4; j++)
    //         printf("%d ", B[i][j]);
    //     printf("\n");
    // }

    C = (int **)malloc(3*sizeof(int *));
    C[0] = (int *)malloc(4*sizeof(int));
    C[1] = (int *)malloc(4*sizeof(int));
    C[2] = (int *)malloc(4*sizeof(int));

    // // for changing row
    // for(i = 0; i < 3; i++)
    // {
    //     // Access all elements in the rows
    //     for(j = 0; j < 4; j++)
    //         printf("%d ", C[i][j]);
    //     printf("\n");
    // }

    return 0;
}