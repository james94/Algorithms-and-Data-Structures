#include <iostream>

using std::cout;
using std::endl;

int main()
{
    cout << "*********** Pointers Program ***********" << endl;
    // Pointer p points to static data variable a
    int a = 10; // data variable
    int *p; // declare pointer (address) variable
    p = &a; // initialize p pointer with address of a
    cout << "pointer p points to static variable: " << endl;
    cout << "data a variable is " << a << endl;
    cout << "pointer p variable dereferened is " << *p << endl;

    // Pointer dp points to dynamic array in heap memory
    int *dp; // declare pointer variable
    dp = new int[5];
    dp[0] = 11;
    dp[1] = 12;
    dp[2] = 13;

    cout << "pointer dp points to dynamic array in heap:" << endl;
    cout << "ptr dp variable dereferenced at dp[0] is " << dp[0] << endl;
    cout << "ptr dp variable dereferenced at dp[1] is " << dp[1] << endl;
    cout << "ptr dp variable dereferenced at dp[2] is " << dp[2] << endl;
    cout << "ptr dp variable dereferenced at dp[3] is " << dp[3] << endl;

    cout << "reference in C++:" << endl;
    int &r = a;
    r++; // inc data a variable using ref r
    cout << "Incremented data a variable with reference r." << endl;
    cout << "Now data variable a referenced by r is " << r << endl;
    cout << "Data variable a is " << a << endl;
    return 0;
}