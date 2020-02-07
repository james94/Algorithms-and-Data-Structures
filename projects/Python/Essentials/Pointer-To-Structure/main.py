import ctypes
from dataclasses import dataclass

# Rectangle Data Class
@dataclass
class Rectangle1:
    length: int
    width: int

# Rectangle usinng ctypes Structure
class Rectangle2(ctypes.Structure):
    _fields_ = [("length", ctypes.c_int),
                ("width", ctypes.c_int)]

def main():
    print("***********C/C++ like Pointer to Structure Program ***********")

    # You will see 2 ways of implementing a pointer to a structure
    # Approach 1: You use list mutable object to act as a pointer to struct
    # Approach 2: Use real C pointers from ctypes to point to structure

    # 1. Utilize mutable objects as low-overhead pointers to point to Py Data Class
    r1 = [Rectangle1(10, 5)]
    p = r1
    p[0].length = 20
    p[0].width = 25

    print("Pointer to Py Data Class Structure using List Mutable Object")
    print("p points to list mutable object of Rectangle structure:")
    print("Area of 1st Rectangle in r1 using p[0] pointer is {}".format(p[0].length*p[0].width))

    # 2. Use real C pointers to point to Py structure using ctypes
    r2 = Rectangle2(0, 0)
    ptr = ctypes.pointer(r2)
    ptr.contents.length = 10
    ptr.contents.width = 5

    print("C Pointer to Py ctypes Structure using ctypes pointer")
    print("Area of Rectangle2 using ctypes pointer is {}".format(ptr.contents.length*ptr.contents.width))


if __name__ == "__main__":
    main()