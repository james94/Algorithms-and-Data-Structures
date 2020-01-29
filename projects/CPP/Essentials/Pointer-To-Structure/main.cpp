#include <iostream>

using std::cout;
using std::endl;

struct Rectangle
{
    int length; // height
    int width; // breadth
};

int main()
{
    cout << "*********** Pointer to Structure Program ***********" << endl;
    // Pointer p points to static Rectangle structure r
    // Declare and Initialize r Rectangle
    struct Rectangle r = {10, 5};
    // Declare and Initialize p pointer with address of r
    struct Rectangle *p = &r;
    (*p).length = 20; // Ok: dereference p, then access length data member
    p->width = 25; // Ok: have p point to length data member for access

    cout << "Pointer p points to static structure:" << endl;
    cout << "Area of Static Rectangle r using p pointer is " << p->length*p->width << endl;

    // Pointer dp points to dynamic Rectangle structure in heap
    struct Rectangle *dp;
    dp = new struct Rectangle;
    // Initialize dynamic structure members using pointer dp
    dp->length = 10;
    dp->width = 5;

    cout << "Pointer dp points to dynamic structure in heap:" << endl;
    cout << "Area of Dynamic Rectangle using dp pointer is " << dp->length*dp->width << endl;
    return 0;
}