#include <iostream>

using std::cout;
using std::endl;

class Rectangle
{
    private:
        int length;
        int width;
    public:
        Rectangle();
        Rectangle(int l, int w);
        int area();
        int perimeter();
        int getLength();
        void setLength(int l);
        ~Rectangle();
};

Rectangle::Rectangle()
{
    length = width = 1;
}

Rectangle::Rectangle(int l, int w)
{
    length = l;
    width = w;
}

int Rectangle::area()
{
    return length*width;
}

int Rectangle::perimeter()
{
    return 2*(length + width);
}

int Rectangle::getLength()
{
    return length;
}
void Rectangle::setLength(int l)
{
    length = l;
}

Rectangle::~Rectangle()
{

}

int main()
{
    cout << "************** Converting C to C++ Class Program: **************" << endl;
    Rectangle r(10, 5);
    cout << "Rectangle Area is " << r.area() << endl;
    cout << "Rectangle Perimeter is " << r.perimeter() << endl;
    r.setLength(20);
    cout << "Rectangle length is now " << r.getLength() << endl;
    return 0;
}