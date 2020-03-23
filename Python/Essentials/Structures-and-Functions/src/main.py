from dataclasses import dataclass

@dataclass
class Rectangle:
    length: int
    width: int

def initialize(r, l, w):
    r.length = l
    r.width = w

def area(r):
    return r.length*r.width

def change_length(r, l):
    r.length = l

def main():
    print("*********** C-like Structures and Functions Program ***********")
    r = Rectangle(0, 0)
    initialize(r, 10, 5)
    area(r)
    change_length(r, 20)

if __name__ == "__main__":
    main()