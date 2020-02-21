#include <stdio.h>
#include <stdlib.h>

// Pass by Value
void swap1(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// Pass by Address (Pointer)
void swap2(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    printf("Parameter Passing Methods:\n");
    printf("Pass by Value Swap1 Example:\n");
    int a, b;
    a = 10;
    b = 20;
    swap1(a, b);
    printf("%d %d\n", a, b);

    printf("Pass by Address Swap2 Example:\n");
    int n, m;
    n = 15;
    m = 25;
    swap2(&n, &m);
    printf("%d %d\n", n, m);

    return 0;
}