#include <stdio.h>

// Power using Recursion

// slower approach
// Time Complexity: O(n)
// Space Complexity: O(n)
int power(int m, int n)
{
    if(n == 0)
    {
        return 1;
    }
    return power(m, n-1)*m;
}

// more efficient approach
// compute with less multiplications compared to slow approach
// Time Complexity: O(n)
// Space Complexity: O(n)
int FasterPower(int m, int n)
{
    if(n == 0)
    {
        return 1;
    }
    if(n % 2 == 0)
    {
        return FasterPower(m * m, n/2);
    }
    else
    {
        return m * FasterPower(m * m, (n-1)/2);
    }
}

int main()
{
    int r = FasterPower(9, 3);
    printf("%d\n", r);
    return 0;
}