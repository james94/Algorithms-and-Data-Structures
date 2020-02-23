#include <stdio.h>

// Sum of N Natural Numbers

// Recursion approach
// Time Complexity: O(n)
// Space Complexity: O(n)
int Rsum(int n)
{
    if(n == 0)
    {
        return 0;
    }
    return Rsum(n-1)+n;
}

// Iteration approach
// Time Complexity: O(n)
// Space Complexity: O(1)
int Isum(int n)
{
    int s = 0;
    int i;
    for(i = 1; i <= n; i++)
    {
        s = s + i;
    }
    return s;
}

// Direct Formula approach
// Time Complexity: O(1)
// Space Complexity: O(1)
int DFsum(int n)
{
    return n*(n+1)/2;
}

int main()
{
    int r;
    r = Rsum(5);
    printf("%d ", r);
    return 0;
}