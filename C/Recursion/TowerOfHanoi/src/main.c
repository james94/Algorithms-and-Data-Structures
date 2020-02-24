#include <stdio.h>

// Tower Of Hanoi
// Time Complexity: O(2^n)
// n is number of disks
// A is from, B is using, C is to
// n = 3, calls = 15. 1 + 2 + 2^2 + 2^3 = 2^4 - 1 calls
// n = 2, calls = 7
// 1 + 2 + 2^2 + .. + 2^n = 2^(n+1) - 1
void TOH(int n, int A, int B, int C)
{
    if(n > 0)
    {
        TOH(n-1, A, C, B);
        printf("(%d,%d)\n", A, C);
        TOH(n-1, B, A, C);
    }
}

int main()
{
    // TOH(1, 1, 2, 3);
    // TOH(2, 1, 2, 3);
    // TOH(3, 1, 2, 3);
    TOH(4, 1, 2, 3);
    
    return 0;
}