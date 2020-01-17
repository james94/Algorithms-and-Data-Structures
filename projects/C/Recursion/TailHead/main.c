#include <stdio.h>

void fun(int n)
{
    if(n > 0)
    {
        fun(n - 1);
         // if newline isn't used, won't print to screen while debugging
        printf("%d \n", n);
    }
}

int main() 
{
    int x = 3;

    fun(x);
    // printf("Hello\n");
    return 0;
}