# List as Mutable Object Parameter
    # list is similar to C/C++ array
# Pass by List Mutable Object 
    # (similar to C/C++ pass by array or pointer/ref)
def fun1(A):
    for i in range(len(A)):
        print(A[i], " ")
    print()

# Return List Mutable Object
    # similar to C/C++ return by pointer that points
    # to array in heap and returns array
def fun2(n):
    A = [n]
    return A

def main():
    print("*********** List As Mutable Object Parameter Program ***********")
    print("Pass by List Mutable Object fun1 Example:")
    A = [2,4,6,8,10]
    fun1(A)

    print("Returning List Mutable Object fun2 Example:")
    B = fun2(5)
    fun1(B)

if __name__ == "__main__":
    main()