from dataclasses import dataclass

# C-like structures in Python using Data Classes (Python 3.7)
# A dataclass is a class containing mainly data
# Resulting object is mutable and allows default values

# dataclass decorator examines class to find fields
# A field is defined as class variable that has type annotation
# Variable annotations are used for type hints
# for ex, variable length is expected to take int values

# Rectangle Data Class
@dataclass
class Rectangle:
    '''Class for keeping track of sides of Rectangle'''
    length: int
    width: int

# Complex Number Data Class
@dataclass
class Complex:
    real: int # a
    img: int # ib, imaginary

# For Student structure C version, we had a char array
# In Python, we change char array to str type shown below

# Student Data Class
@dataclass
class Student:
    roll: int
    name: str
    dept: str
    address: str

@dataclass
class Card:
    face: int
    shape: int
    color: int

if __name__ == "__main__":
    print("*********** C-Like Structures via Data Classes in Python Program ***********")
    # In C Structures we can declare structures and initialize
    # them separately, in Python, we must declare and initialize
    # them on creation
    
    # Declare and Initialize Rectangle 1 Data Class
    r1 = Rectangle(5, 10)

    # Declare and Initialize Rectangle 2 Data Class
    r2 = Rectangle(15, 10)

    # Declare and Initialize Playing Card1
    c1 = Card(1, 0, 0)

    # Declare and Initialize Playing Card2
    c2 = Card(2, 0, 0)

    # Acess and Print Rectangle Data Members
    print("Area of Rectangle1 is {}".format(r1.length*r1.width))
    print("Area of Rectangle2 is {}".format(r2.length*r2.width))

    # Access and Print Card Data Members
    print("Card1 Face is {}".format(c1.face))
    print("Card1 Shape is {}".format(c1.shape))
    print("Card1 Color is {}".format(c1.color))

    print("Card2 Face is {}".format(c2.face))
    print("Card2 Shape is {}".format(c2.shape))
    print("Card2 Color is {}".format(c2.color))