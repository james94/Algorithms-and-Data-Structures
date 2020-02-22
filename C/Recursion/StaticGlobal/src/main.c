#include <stdio.h>

// Static vs Global Recursion Approaches
// Static and Global variables are created in code section one time
// Time Complexity: O(n)
// Space Complexity: O(n)

// global variable
// int x = 0;
int fun(int n)
{
    // static variable
    static int x = 0;
    if(n > 0)
    {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}

int main()
{
    // 5 times, 5 will be added, so it is 25
    int r;
    r = fun(5);
    printf("%d\n", r);

    // 5 times, 10 will be added, so it is 50
    r = fun(5);
    printf("%d\n", r);    
    return 0;
}