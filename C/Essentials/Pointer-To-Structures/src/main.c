#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
    int length; // height
    int width; // breadth
};

int main()
{
    // Pointer p points to static Rectangle structure r
    // Declare and Initialize r Rectangle
    struct Rectangle r = {10, 5};
    // Declare and Initialize p pointer with address of r
    struct Rectangle *p = &r;
    (*p).length = 20; // Ok: dereference p, then access length data member
    p->width = 25; // Ok: have p point to length data member for access

    printf("Pointer p points to static structure: \n");
    printf("Area of Static Rectangle r using p pointer is %d\n", p->length*p->width);

    // Pointer dp points to dynamic Rectangle structure in heap
    struct Rectangle *dp;
    dp = (struct Rectangle*)malloc(sizeof(struct Rectangle));
    // Initialize dynamic structure members using pointer dp
    dp->length = 10;
    dp->width = 5;

    printf("Pointer dp points to dynamic structure in heap: \n");
    printf("Area of Dynamic Rectangle using dp pointer is %d\n", dp->length*dp->width);
    return 0;
}