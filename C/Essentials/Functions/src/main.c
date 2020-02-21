#include <stdio.h>
#include <stdlib.h>

// Functions. Pass by Value
int add(int a, int b)
{
    int c;
    c = a+b;
    return c;
}

int main()
{
    printf("Functions:\n");
    printf("Pass By Value Addition Example:\n");
    int x, y, z;
    x = 10;
    y = 5;
    z = add(x, y);
    printf("sum is %d\n", z);
    return 0;
}