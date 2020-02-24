#include <stdio.h>

// Fibonacci using Iteration, Recursion, Memoization Recursion

// Iteration approach
// Time Complexity: O(n)
// Space Complexity: O(1)
int fib(int n)
{
    int t0 = 0, t1 = 1, s = 0;

    if(n <= 1)
    {
        return n;
    }

    for(int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

// Recursion approach (Excessive)
// Time Complexity: O(2^n). When a func is calling 2 times by reduce n - 1,
// the time is 2^n.
// Space Complexity: O(n)
int rfib(int n)
{
    if(n <= 1)
    {
        return n;
    }
    return rfib(n - 2) + rfib(n - 1);
}

// Memoization Recursion approach
// When a recursive function calls itself multiple times for the same parameters, we can
// use Memoization to avoid the excessive calls. Memoization uses a static or
// global array to retain the result from a recursive function when we don't know the
// answer. When we do know the answer from a recursive function call, we access our
// Memoization array to get the answer. Thus, we avoid excessive calls.
// Time Complexity: O(n)
// Space Complexity: O(n)
int F[10];
int mrfib(int n)
{
    if(n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if(F[n - 2] == -1)
        {
            F[n - 2] = mrfib(n - 2);
        }
        if(F[n - 1] == -1)
        {
            F[n - 1] = mrfib(n - 1);
        }
        F[n] = F[n - 2] + F[n - 1];
        return F[n - 2] + F[n - 1];
    }
    
}

int main()
{
    int i;
    for(i = 0; i < 10; i++)
    {
        F[i] = -1;
    }
    printf("%d \n", mrfib(5));
    return 0;
}