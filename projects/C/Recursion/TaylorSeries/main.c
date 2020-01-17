#include <stdio.h>

// Taylor Series Recursion
double e(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if(n == 0)
    {
        return 1;
    }
    else
    {
        r = e(x, n-1);
        p = p * x;
        f = f * n;
        return r + p/f;
    }
}

int main()
{
    // increase number n of terms to get more precise value
    double res = e(4, 15);
    printf("%1f\n", res);
    return 0;
}