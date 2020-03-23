# Pass by Immutable Object (similar to C/C++ pass by value)
def swapImOb(x, y):
    temp = x
    x = y
    y = temp

# Pass by Mutable Object (similar to C/C++ pass by pointer/reference)
def swapMuOb(x, y):
    temp = x[0]
    x[0] = y[0]
    y[0] = temp

def main():
    print("*********** Parameter Passing Methods Program ***********")
    # Call swap by an Immutable Object
    # Int is immutable
    a = 3
    b = 10
    print("Before Call swapImOb by Immutable Object")
    print("a = {}; b = {}".format(a, b))
    swapImOb(a, b)
    print("After Call swapImOb by Immutable Object")
    print("a = {}; b = {}".format(a, b))

    # Call swap by a Mutable Object
    # List is mutable
    m = [5]
    n = [20]
    print("Before Call swapMuOb by Mutable Object")
    print("m = {}; n = {}".format(m, n))
    swapMuOb(m, n)
    print("After Call swapMuOb by Mmutable Object")
    print("m = {}; n = {}".format(m, n))

if __name__ == "__main__":
    main()