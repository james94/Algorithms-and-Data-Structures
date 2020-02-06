class Rectangle:
    def __init__(self, l = None, w = None):
        if l is None and w is None:
            self.length = self.width = 1
        else:
            self.length = l
            self.width = w

    def area(self):
        return self.length*self.width

    def perimeter(self):
        return 2*(self.length+self.width)

    def getLength(self):
        return self.length

    def setLength(self, l):
        self.length = l

def main():
    print("************** Converting C to Py Class Program: **************")
    r = Rectangle(10, 5)

    print("Rectangle Area is {}".format(r.area()))
    print("Rectangle Perimeter is {}".format(r.perimeter()))
    r.setLength(20)
    print("Rectangle length is now {}".format(r.getLength()))

if __name__ == "__main__":
    main()