from dataclasses import dataclass

@dataclass
class Rectangle:
    length: int
    width: int

@dataclass
class Test:
    A: list
    n: int

def area(r):
    return r.length*r.width

# Pass by Mutable Object (similar to C/C++ pass by pointer/reference)
def change_length(p, l):
    p.length = l

def fun(t):
    t.A[0] = 10
    t.A[1] = 9

def main():
    print("*********** C-like Structure As Parameter Program ***********")
    # custom classes are mutable
    r = Rectangle(10, 5)

    print("Before Rectangle Mod sides l = {}, w = {}".format(r.length, r.width))
    print("Area of Rectangle r is {}".format(area(r)))

    # Call change_length by a mutable object
    # Custom class is mutable
    change_length(r, 20)
    print("After Rectangle Mod sides l = {}, w = {}".format(r.length, r.width))
    
    # In Python, pass dataclass object to function. Similar in C/C++ pass
    # struct variable to function. In C/C++, we pass struct by value. In
    # Python, we pass the dataclass by mutable. In C/C++, the struct data
    # members don't change upon return from function due to pass by value. 
    # In Python, the dataclass data members do change upon return from function 
    # due to pass by mutable. Pass by mutable is like pass by pointer/reference.
    t1 = Test([2,4,6,8,10],5)
    fun(t1)
    print("t1.A[0] = {}, t1.A[1] = {}".format(t1.A[0], t1.A[1]))

if __name__ == "__main__":
    main()