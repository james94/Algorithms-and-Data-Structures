#include <iostream>

using std::cout;
using std::endl;

int main()
{
    cout << "*********** Array Basics Program ***********" << endl;
    // Declare Array
    int A[5];

    // Declare and Initialize Array
    int B[5] = {2,4,6,8,10};

    // Access and Print Array Elements
    for(int i = 0; i < 5; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}