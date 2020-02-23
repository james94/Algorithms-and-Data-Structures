#include <stdio.h>

// factorial

// Recursion approach
// Time Complexity: O(n)
// Space Complexity: O(n)
int fact(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return fact(n - 1)*n;
    }
    
}

// Iteration approach
// Time Complexity: O(n)
// Space Complexity: O(1)
int IterFact(int n)
{
    int fact = 1;
    for(int i = n; i > 0; i--)
    {
        fact = fact * i;
    }
    return fact;
}

int main()
{
    int in = 5;
    int res = fact(in);
    printf("%d ", res);
    return 0;
}