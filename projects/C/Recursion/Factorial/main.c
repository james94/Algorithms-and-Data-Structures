#include <stdio.h>

// factorial

// Recursion approach
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
    int res = IterFact(in);
    printf("%d\n", res);
    return 0;
}