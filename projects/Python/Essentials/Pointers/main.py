
# 3 Ways to Simulate C-like Pointers in Python

# 1. Utilize mutable objects as low-overhead pointers
# 2. Create custom Python objects for ease of use
# 3. Unlock real C pointers with ctypes module
# 4. Unlock real C++ pointers with cppyy module

print("*********** Simulating Pointers in Python Program ***********")
print("Method 1: Utilize mutable objects as low-overhead pointers **")
# 1. Utilize mutable objects as low-overhead pointers

# Note: this only simulates pointer behavior and doesn't directly
# map to true pointers in C/C++. These operations are more expensive too.

# dp points to list mutable object accessible by a
# lists in Py are dynamic since items can be inserted/deleted from anywhere
# create list mutable object accessible by a
a = [10] # first element denotes number of patients visits 
a.append(11) # second element denotes monthly charges
print("a len is {}".format(len(a)))
dp = a # initialize dp with address of a's list mutable object
print("Before:")
print("id(a) is {}".format(id(a)))
print("id(dp) is {}".format(id(dp)))
print("id(a[0]) is {}".format(id(a[0])))
print("id(dp[0]) is {}".format(id(dp[0])))
print("a[0] is {}".format(a[0]))
print("dp[0] is {}".format(dp[0]))
print("is id of dp and a equal? {}".format(dp is a))
print("is id of dp[0] and a[0] equal? {}".format(dp[0] is a[0]))

dp[0] += 1
print("After:")
print("id(a) is {}".format(id(a)))
print("id(dp) is {}".format(id(dp)))
print("id(a[0]) is {}".format(id(a[0])))
print("id(dp[0]) is {}".format(id(dp[0])))
print("a[0] is {}".format(a[0]))
print("dp[0] is {}".format(dp[0]))
print("is id of dp and a equal? {}".format(dp is a))
print("is id of dp[0] and a[0] equal? {}".format(dp[0] is a[0]))

dp[0] += 1
print("After:")
print("id(a) is {}".format(id(a)))
print("id(dp) is {}".format(id(dp)))
print("id(a[0]) is {}".format(id(a[0])))
print("id(dp[0]) is {}".format(id(dp[0])))
print("a[0] is {}".format(a[0]))
print("dp[0] is {}".format(dp[0]))
print("is id of dp and a equal? {}".format(dp is a))
print("is id of dp[0] and a[0] equal? {}".format(dp[0] is a[0]))

# use dict mutable object to mimic pointers in Python
# for ex, there was an application where we want to track interesting events 
cp = {"patient_visits": 0}
def inc_patient_visits():
    cp["patient_visits"] += 1

# The counter pointer (cp) is used to track number of function calls
print("Before a patient's visit")
print("cp[\"patient_visits\"] is {}".format(cp["patient_visits"]))
inc_patient_visits()
print("After a patient's visit")
print("cp[\"patient_visits\"] is {}".format(cp["patient_visits"]))


print("Method 2: Create custom Python objects for ease of use ******")
# 2. Create custom Python objects for ease of use
# dict is a way to emulate pointers, but sometimes the key can be tedious
# Suppose you wanted to track metrics for monitoring your medical
# practice, create a class is a way to abstract the dict details
class Metrics(object):
    def __init__(self):
        self._metrics = {
            "patient_visits": 0,
            "monthly_charges": 0,
        }
    # Use property decorator to access dict key values as if they were attributes
    @property
    def patient_visits:
        return self._metrics["patient_visits"]

    @property
    def monthly_charges:
        return self._metrics["monthly_charges"]

    def inc_patient_visits:
        self._metrics["patient_visits"] += 1
    
    def inc_monthly_charges:
        self._metrics["monthly_charges"] += 1

# Since we are able to access these names as attributes means
# you abstracted these values in the dict

# You now can use the Metrics class to modify values in metrics dict
# as if you're modifying a pointer
metrics = Metrics()
print("Emulate Pointers with Dict inside Custom Class")
print("Metrics for Monitoring Medical Practice")
print("Before a patient's visit")
print("Patient Visits is {}".format(metrics.patient_visits))
# Access patient_vists and call inc_patient_visits in various parts
# of application and simulate pointers
metrics.inc_patient_visits
metrics.inc_patient_visits
print("After 2 patient's visit")
print("Patients Visits is {}".format(metrics.patient_visits))


print("Method 3: Unlock real C pointers with ctypes module ***********")
# 3. Unlock real pointers with ctypes module
# Access C-style pointers with CPython
# You would use this if you needed to make a function call to
# a C library that requires a pointer
import ctypes
# To use these C libraries, first we compile them into a shared object each
# Load shared object files libdisplay.so, libadd.so into Python
display_lib = ctypes.CDLL("./CLib/libdisplay.so")
add_lib = ctypes.CDLL("./CLib/libadd.so")
c_display = display_lib.display
c_addOne = add_lib.addOne
# Before calling function, specify the function signature
# to help Python ensure the user passes the right type to function
# Function signature is a pointer to an integer
c_display.argtypes = [ctypes.POINTER(ctypes.c_int)]
c_addOne.argtypes = [ctypes.POINTER(ctypes.c_int)]

# Note: As you run the remaining code, you will see the memory address, the C-style 
# pointer points to is different than the address of the Python ctypes reference ref_x. 
# I believe this occurs since when Python calls the C function, ref_x is passed into C, 
# new memory is allocated for this integer in C program separate from Python. The pointer 
# in the C function's parameter points to this new memory location specific to the C program. 
# The code in the C function is run, then we exit when the task is finished and leave the 
# C program entering back into Python program. The C integer variable and it's value is retained
# by Python's reference ref_x

# Create C-style integer x with a value of 10.
x = ctypes.c_int(10)
print("id of x is {}".format(hex(id(x))))
# with ctypes, we use byref to pass a variable by reference to these functions
ref_x = ctypes.byref(x)
print("id of x byref is {}".format(hex(id(ref_x))))
# passing ref_x by reference, passes the reference to the original variable x, 
# thus modifications will be reflected in original variable x

# Display original x variable
c_display(ref_x)
# Increment x by one
c_addOne(ref_x)
# Display x variable's modified value
c_display(ref_x)

# 4. Unlock real C++ pointers with cppyy module
print("Method 4: Unlock real C++ pointers with cppyy module ***********")
import cppyy

# Call C++ Functions directly using cppyy
# C++ Assign Value using Pointer
cppyy.cppdef("""
void int_ptr_assign(int *p, int n) {
    *p = n;
}
""")

# C++ Assign Value using Reference
cppyy.cppdef("""
void int_ref_assign(int &p, int n) {
    p = n;
}
""")

# C++ Display Function
cppyy.cppdef("""
void display(int *p) {
    std::cout << "pointer p variable is " << p << std::endl;
    std::cout << "pointer p variable dereferenced is " << *p << std::endl;
}
""")

# C++ AddOne Function
cppyy.cppdef("""
void incPtrOne(int *p) {
    *p += 1;
}
""")

# Call on C++ Display using Pass By Reference
p = ctypes.c_int(0)
ref_p = ctypes.byref(p)
cppyy.gbl.int_ptr_assign(ref_p, 42)
cppyy.gbl.int_ref_assign(p, 50)

cppyy.gbl.display(ref_p)

# Call on C++ AddOne using Pass By Reference
cppyy.gbl.incPtrOne(ref_p)

# Check if p reference value changed
cppyy.gbl.display(ref_p)

# Define basic pointers class and methods using cppyy
cppyy.include('CPPLib/pointers.hpp')
# explicit loading of reflection library prevents use in (large scale) productiono
cppyy.load_reflection_info("CPPLib/libpointers.so")
cppyy.load_library("libpointers")
from cppyy.gbl import BasicPointers
# Do need to pass in at least c_int to C++ pointer
f = ctypes.c_int(0)
# To be consistent with ctypes c functions, I will pass by ref to C++ pointer
ref_f = ctypes.byref(f)
n = 20
# Create instance of C++ pointers class 
cpp_ptr = BasicPointers()
# display initial data of f variable before dereferenced pointer p updates it with n
cpp_ptr.displayPtrVal(ref_f)
# display value n that will be assigned to c_int f using pass by pointer or reference
cpp_ptr.displayValToAssign(n)
# Assign Value n to reference f (address of f) using Pointer
cpp_ptr.int_ptr_assign(ref_f, n)
# display data of f variable after dereferenced pointer p updates it with n
cpp_ptr.displayPtrVal(ref_f)

# add 1 to data variable f using pointer p, which points to f
cpp_ptr.incPtrOne(ref_f)
# display data variable f after pointer p increments f
cpp_ptr.displayPtrVal(ref_f)
# increment data variable f using pass by reference
cpp_ptr.incRefOne(f)
# display data variable f after reference increments f
cpp_ptr.displayPtrVal(ref_f)

