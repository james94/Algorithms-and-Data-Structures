#include <stdio.h>

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
    printf("Area of Rectangle1 is %d\n", r1.length*r1.width);
    printf("Area of Rectangle2 is %d\n", r2.length*r2.width);
    
    // Access Card Data Members
    printf("Card1 Face is %d\n", c1.face);
    printf("Card1 Shape is %d\n", c1.shape);
    printf("Card1 Color is %d\n", c1.color);

    printf("Card2 Face is %d\n", c2.face);
    printf("Card2 Shape is %d\n", c2.shape);
    printf("Card2 Color is %d\n", c2.color);
    return 0;
}