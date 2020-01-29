#include <iostream>

using std::cout;
using std::endl;

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

// Pass by Reference
void swap3(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    cout << "*********** Parameter Passing Methods Program ***********" << endl;
    cout << "Pass by Value Swap1 Example:" << endl;
    int a, b;
    a = 10;
    b = 20;
    swap1(a, b);
    cout << a << " " << b << endl;

    cout << "Pass by Address Swap2 Example:" << endl;
    int n, m;
    n = 15;
    m = 25;
    swap2(&n, &m);
    cout << n << " " << m << endl;

    cout << "Pass by Reference Swap3 Example:" << endl;
    int c, k;
    c = 30;
    k = 11;
    swap3(c, k);
    cout << c << " " << k << endl;

    return 0;
}