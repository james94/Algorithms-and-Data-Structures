#include "ArrayOperations.h"

int main()
{
    // Dynamic or Static Array
    bool dynamic = false;

    if(dynamic)
    {
        // Initialization

        // Dynamic Array
        // This array is preferred since the size is dynamic
        // whatever the required size is, you can take the size
        struct DynArray d_arr;

        // for how many numbers to be inserted into arr
        int n;

        // should know the size of the array
        printf("Enter size of array: ");
        // read input from keyboard using scanf
        scanf("%d", &d_arr.size);
        
        // create array in heap, then make A* point to it 
        d_arr.A = (int *)malloc(d_arr.size*sizeof(int));
        // set length to 0 since there's no elements
        d_arr.length = 0; 

        // Fill few elements in array
        printf("Enter number of numbers: ");
        scanf("%d", &n);

        // take all values from keyboard and store into arr
        printf("Enter all Elements\n");
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &d_arr.A[i]);
        }
        // After inserting all arr elements, set length as n
        d_arr.length = n;

        // Call Display function
        DisplayDynArr(d_arr);
    }
    else 
    {
        // Static Array
        // Initialize it inside the object, fill elements,
        // size of array, number of elements in array
        struct Array s_arr = {{2,3,4,5,6},10,5};

        Display(s_arr);
    }

    return 0;
}