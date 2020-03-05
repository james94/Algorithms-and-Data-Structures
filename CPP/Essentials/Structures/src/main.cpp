#include <iostream>

using std::cout;
using std::endl;

// Structure: collection of data members related under one name

// Rectangle Structure
struct Rectangle
{
    int length; // alias height
    int width; // alias breadth
};

// Complex Number Structure
struct Complex
{
    int real; // a
    int img; // ib, imaginary
};

// Student Structure
struct Student
{
    int roll;
    char name[25];
    char dept[10];
    char address[10]; 
};

// Playing Cards Structure
struct Card
{
    int face; // 1=A, 2, ..., 10, 11=J, 12=Q, 13=K
    int shape; // 0=club, 1=spade, 3=diamond, 4=heart
    int color; //0=black, 1=red
};

int main()
{
    cout << "*********** Structures Program ***********" << endl;
    // Rectangle1 Declaration
    struct Rectangle r1;
    // Rectangle2 Declaration and Initialization
    struct Rectangle r2 = {15, 10};
    // Initialize rectangle 1 data members
    r1.length = 5;
    r1.width = 10;

    // Playing Card1 Declaration
    struct Card c1;
    // Playing Card2 Declaration and Initialization
    struct Card c2 = {2,0,0};
    // Initialize card 1 data members
    c1.face = 1;
    c1.shape = 0;
    c1.color = 0;

    // Access Rectangle Data Members
    cout << "Area of Rectangle1 is " << r1.length*r1.width << endl;
    cout << "Area of Rectangle2 is " << r2.length*r2.width << endl;   
    
    // Access Card Data Members
    cout << "Card1 Face is " << c1.face << endl;
    cout << "Card1 Shape is " << c1.shape << endl;
    cout << "Card1 Color is " << c1.color << endl;

    cout << "Card2 Face is " << c2.face << endl;
    cout << "Card2 Shape is " << c2.shape << endl;
    cout << "Card2 Color is " << c2.color << endl;
    return 0;
}