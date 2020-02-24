#include <stdio.h>

// Taylor Series using Horner's Rule

// Recursion Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
double e(int x, int n)
{
    static double s = 1;
    if(n == 0)
    {
        return s;
    }
    // multiply by s in numerator to avoid int division
    s = 1 + x*s/n;
    return e(x, n-1);
}

// Iterative Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
double eIter(int x, int n)
{
    double s = 1;
    int i;
    double num = 1;
    double den = 1;
    for(i = 1; i <= n; i++)
    {
        num *= x;
        den *= i;
        s += num/den;
    }
    return s;
}

int main()
{
    double res = e(2, 10);
    printf("%lf \n", res);
    return 0;
}