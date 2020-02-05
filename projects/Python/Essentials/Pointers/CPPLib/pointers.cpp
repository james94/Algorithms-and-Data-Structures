#include "pointers.hpp"

using std::cout;
using std::endl;

BasicPointers::BasicPointers() {}

BasicPointers::~BasicPointers() {}

void BasicPointers::displayPtrVal(int *p)
{
    cout << "pointer p variable is " << p << endl;
    cout << "pointer p variable dereferenced is " << *p << endl;
}

void BasicPointers::displayValToAssign(int v)
{
    cout << "Value to be assigned via pass by pointer or reference is " << v << endl;
}

void BasicPointers::int_ptr_assign(int *p, int n) {
    cout << "Update the variable p points to with n" << endl;
    *p = n;
}

void BasicPointers::int_ref_assign(int &p, int n) {
    cout << "Update the variable p references with n" << endl;
    p = n;
}

void BasicPointers::incPtrOne(int *p) 
{
    cout << "Increment the variable p points to by 1" << endl;
    *p += 1;
}

void BasicPointers::incRefOne(int &ref)
{
    cout << "Increment the variable p references by 1" << endl;
    ref += 1;
}
