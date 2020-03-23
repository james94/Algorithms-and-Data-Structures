def add(a, b):
    """Add two numbers"""
    c = a+b
    return c

# Define main method that calls other functions
def main():
    print("*********** Functions Program ***********")
    x = 10
    y = 5
    z = add(x, y)
    print("sum is ", z)

# Execute main() function
if __name__ == "__main__":
    main()