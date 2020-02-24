#include <stdio.h>

/*
Combination Formula
Given the set of objects, combination allows us to find
the number of ways we can select the subset of those objects
*/

// Factorial Helper Function
int fact(int n)
{
    if(n == 0)
    {
        return 1;
    }
    return fact(n - 1) * n;
}

// Combination Function given n and r
// Time Complexity: O(n)
int nCr(int n, int r)
{
    int num, den;
    
    num = fact(n);
    den = fact(r) * fact(n - r);

    return num/den;
}

// Combination Function using Pascal's Triangle
int NCR(int n, int r)
{
    if(n == r || r == 0)
    {
        return 1;
    }
    return NCR(n-1, r-1) + NCR(n-1, r);
}

int main()
{
    // printf("%d \n", nCr(5, 1));
    // printf("%d \n", nCr(5, 2));
    // printf("%d \n", nCr(5, 3));
    printf("%d \n", nCr(4, 2));
    return 0;
}