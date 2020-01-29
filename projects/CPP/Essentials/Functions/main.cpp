#include <iostream>

using std::cout;
using std::endl;

// Functions. Pass by Value
int add(int a, int b)
{
    int c;
    c = a+b;
    return c;
}

int main()
{
    cout << "*********** Functions Program ***********" << endl;
    cout << "Pass By Value Addition Example:" << endl;
    int x, y, z;
    x = 10;
    y = 5;
    z = add(x, y);
    cout << "sum is " << z << endl;
    return 0;
}