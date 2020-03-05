#include "ArrayOperations.h"

using std::cout;
using std::cin;

int main()
{
    Array *arr1;
    int ch, sz;
    int x, index;

    cout << "Enter Size of Array ";
    cin >> sz;
    // Dynamically allocate object array in the heap
    // pointer arr1 points to heap object
    arr1 = new Array(sz);

    do
    {
        cout << "\n\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "enter your choice ";
        cin >> ch;

        switch(ch)
        {
            case 1: cout << "Enter an element and index ";
                cin >> x >> index;
                arr1->Insert(index, x);
                break;
            case 2: cout << "Enter index ";
                cin >> index;
                x = arr1->Delete(index);
                cout << "Deleted Element is " << x << "\n";
                break;
            case 3: cout << "Enter element to search ";
                cin >> x;
                index = arr1->LinearSearch(x);
                cout << "Element index " << index << "\n";
                break;
            case 4: cout << "Sum is " << arr1->Sum() << "\n";
                break;
            case 5: arr1->Display();
        }
    }while(ch < 6);
    return 0;
}