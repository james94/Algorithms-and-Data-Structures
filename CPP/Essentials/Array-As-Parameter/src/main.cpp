#include <iostream>

using std::cout;
using std::endl;

// Array as Parameter:

// Pass by Address (Array)
// A[] can only point to arrays
void fun1(int A[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Pass by Address (Pointer)
// *A can point to ints or array of ints
void fun2(int *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Returning by Address (Pointer)
// use pointer to point to array in heap and return that address
int *fun3(int n)
{
    int *p;
    p = new int[n];
    return p;
}

int main()
{
    cout << "*********** Array As Parameter Program ***********" << endl;

    cout << "Pass by Address (Array) fun1 Example:" << endl;
    int A[5] = {2,4,6,8,10};
    fun1(A, 5);

    cout << "Pass by Address (Pointer) fun2 Example:" << endl;
    cout << "Pointer to int can point to array of ints" << endl;
    int B[5] = {2,4,6,8,10};
    fun2(B, 5);    

    cout << "Pointer to int can point to also just int" << endl;
    int num = 100;
    fun2(&num, 1);

    cout << "Returning by Address (Pointer) fun3 Example:" << endl;
    int *C;
    C = fun3(5);
    fun2(C, 5);
    return 0;
}