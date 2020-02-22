#include <stdio.h>

void funA(int n);
void funB(int n);

int main()
{
    funA(20);
    return 0;
}

/*
Indirect Recursion
funA calls funB
funB calls funA
A cycle is created that performs recursion

Time Complexity: O(n)
Space Complexity: O(n)
*/
void funA(int n)
{
    if(n > 0)
    {
        printf("%d ", n);
        funB(n - 1);
    }
}

void funB(int n)
{
    if(n > 1)
    {
        printf("%d ", n);
        funA(n / 2);
    }
}