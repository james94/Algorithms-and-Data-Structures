#include <cmath>
#include <iostream>

class BasicPointers {

private:
public:
    BasicPointers();

    ~BasicPointers();

    void int_ptr_assign(int *p, int n);

    void int_ref_assign(int &p, int n);

    void displayPtrVal(int *p);

    void displayValToAssign(int v);

    void incPtrOne(int *p);

    void incRefOne(int &ref);
};