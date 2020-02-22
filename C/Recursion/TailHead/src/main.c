#include <stdio.h>

// Tail Recursion: print numbers in descending order
// Time Complexity: O(n)
// Space Complexity: O(n)
void tail(int n)
{
    if(n > 0)
    {
        printf("%d", n);
        tail(n - 1);
    }
}

// Head Recursion: print numbers in ascending order
// Time Complexity: O(n)
// Space Complexity: O(n)
void head(int n)
{
    if(n > 0)
    {
        head(n - 1);
        printf("%d", n);
    }
}

int main() 
{
    int x = 3;

    printf("Tail Recursion\n");
    tail(x);

    printf("\n");
    
    printf("Head Recursion\n");
    head(x);

    printf("\n");
    return 0;
}