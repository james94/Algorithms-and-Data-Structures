#include <stdio.h>

/*
Nested Recursion - recursion inside recursion.

A recursive call is taking a recursive call as a
parameter.

The function is calling itself, so it is recursive.
The parameter itself is also a recursive call. It means
that unless the result of the function being called
in the parameter is obtained, the outer function call 
cannot be made.
*/
int fun(int n)
{
    if(n > 100)
    {
        return n - 10;
    }
    return fun( fun(n + 11) );
}

int main()
{
    int r;
    // for any value n <= 100, the function will add n up to 101, return 91
    r = fun(95);
    
    // for any value n > 100, the function will immediately return r - 10
    // r = fun(125);
    printf("%d\n", r);
    return 0;
}