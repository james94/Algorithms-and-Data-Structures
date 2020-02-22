
#include <stdio.h>

/*
Tree Recursion: print numbers as we traverse the tree

Time Complexity: O(2^n). 
n is the number of calls made in this particular function. 
n is 15 calls were made in this particular function

Space Complexity: O(n). 
n is the height of the tree. 
n is 15 activation records were created in the stack.
*/
void tree(int n)
{
    if(n > 0)
    {
        printf("%d ", n);
        tree(n - 1);
        tree(n - 1);
    }
}

int main()
{
    tree(3);
    return 0;
}