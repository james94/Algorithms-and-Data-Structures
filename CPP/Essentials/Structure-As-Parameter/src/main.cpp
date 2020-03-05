#include <iostream>

using std::cout;
using std::endl;

// Structure as Parameter

// Rectangle Structure
struct Rectangle 
{
    int length;
    int width;
};

// Test Structure
struct Test
{
    int A[5];
    int n;
};

// Pass by Value
int area(struct Rectangle r1)
{
    return r1.length*r1.width;
}

// Pass By Address (Pointer)
void changeLength(struct Rectangle *p, int l)
{
    p->length = l;
}

// Pass by Value (Even when struct has an array)
void fun(struct Test t1)
{
    t1.A[0] = 10;
    t1.A[1] = 9;
}

int main()
{
    cout << "*********** Structure As Parameter Program ***********" << endl;
    struct Rectangle r={10,5};
    cout << "Area of Rectangle r is " << area(r) << endl;

    changeLength(&r, 20);

    struct Test t={{2,4,6,8,10},5};
    cout << "Pass by Value Even if Struct has as Array" << endl;
    fun(t);
    return 0;
}