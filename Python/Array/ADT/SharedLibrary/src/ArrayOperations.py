"""
Typical usage example:

arr = Array()
arr
"""

class Array:
    """
    Summary of class here
    """

    def __init__(self, size_i = None):
        if size_i is None:
            self.size = 10
            self.length = 0
            self.A = []
        else:
            self.size = size_i
            self.length = 0
            self.A = []
    
    def swap(self, x, y):
        temp = self.A[x]
        self.A[x] = self.A[y]
        self.A[y] = temp

    def display(self):
        print("\nElements are")
        for x in self.A:
            print("{}".format(x), end = " ")
        print()

    def append(self, x):
        if self.length < self.size:
            self.A[self.length] = x
            self.length = self.length + 1

    def insert(self, index, x):
        if index >= 0 and index <= self.length:
            # initial value of i is self.length, dec till index
            for i in range(self.length,index,-1):
                self.A[i] = self.A[i-1]
            self.A[index] = x
            self.length = self.length + 1
    
    def delete(self, index):
        if index >= 0 and index < self.length:
            x = self.A[index]
            # initial value of i is index, inc till length-1
            for i in range(index, self.length-1, 1):
                self.A[i] = self.A[i+1]
            self.length = self.length - 1
            return x
        return 0
    
    def linear_search1(self, key):
        for i in range(0, self.length, 1):
            if key == self.A[i]:
                return i
        return -1
    
    def linear_search2(self, key):
        for i in range(0, self.length, 1):
            if key == self.A[i]:
                self.swap(i, i-1)
                return i-1
        return -1

    def linear_search3(self, key):
        for i in range(0, self.length, 1):
            if key == self.A[i]:
                self.swap(i, 0)
                return 0
        return -1
    
    def binary_search(self, key):
        l = 0
        h = self.length - 1

        while l <= h:
            mid = (l + h) / 2
            if key == self.A[mid]:
                return mid
            elif key < self.A[mid]:
                h = mid - 1
            else:
                l = mid + 1
        return -1
    
    def r_bin_search(self, key):
        if l <= h:
            mid = (l + h) / 2
            if key == self.A[mid]:
                return mid
            elif key < self.A[mid]:
                return self.r_bin_search(l, mid-1, key)
            else:
                return self.r_bin_search(mid+1, h, key)
        return -1
    
    def get(self, index):
        if index >= 0 and index < self.length:
            return self.A[index]
        return -1
    
    def set(self, index, x):
        if index >= 0 and index < self.length:
            self.A[index] = x

    def max(self):
        maximum = self.A[0]
        for i in range(0, self.length, 1):
            if self.A[i] > maximum:
                maximum = self.A[i]
        return maximum
    
    def min(self):
        minimum = self.A[0]
        for i in range(0, self.length, 1):
            if self.A[i] < minimum:
                minimum = self.A[i]
        return minimum

    def sum(self):
        result = 0
        for i in range(0, self.length, 1):
            result = result + self.A[i]
        return result

    def r_sum(self, n):
        if n < 0:
            return 0
        else:
            return self.r_sum(n-1) + self.A[n]

    def avg(self):
        return float(self.sum())/self.length

    def reverse1(self):
        arr_b = []
        # Reverse copy list A into arr_B
        i = self.length - 1
        j = 0
        while i >= 0:
            arr_b[j] = self.A[i]
            i -= 1
            j += 1
        
        # Copy arr_b into A
        for i in range(0, self.length, 1):
            self.A[i] = arr_b[i]
        
    def reverse2(self):
        i = 0
        j = self.length - 1
        while i < j:
            self.swap(i, j)
            i += 1
            j -= 1
    
    def left_shift(self, n):
        while n > 0:
            i = 0
            while i+1 < self.length:
                self.A[i] = self.A[i+1]
                i += 1

            self.A[self.length - 1] = 0
            n -= 1
    
    def left_rotate(self, n):
        while n > 0:
            temp = self.A[0]
            i = 0
            while i+1 < self.length:
                self.A[i] = self.A[i+1]
                i += 1

            self.A[self.length - 1] = temp
            n -= 1

    def right_shift(self, n):
        while n > 0:
            i = self.length - 1
            while i-1 >= 0:
                self.A[i] = self.A[i-1]
                i -= 1

            self.A[0] = 0
            n -= 1

    def right_rotate(self, n):
        while n > 0:
            temp = self.A[self.length - 1]
            i = self.length - 1
            while i-1 >= 0:
                self.A[i] = self.A[i-1]
                i -= 1

            self.A[0] = temp
            n -= 1

    def insert_sort(self, x):
        if self.length == self.size:
            return

        i = self.length - 1
        while i >= 0 and self.A[i] > x:
            self.A[i+1] = self.A[i]
            i -= 1

        self.A[i+1] = x
        self.length += 1

    def is_sorted(self):
        for i in range(0, self.length - 1, 1):
            if self.A[i] > self.A[i+1]:
                return False
        return True

    def rearrange(self):
        i = 0
        j = self.length - 1
        while i < j:
            while self.A[i] < 0:
                i += 1
            while self.A[j] >= 0:
                j -= 1
            if i < j:
                self.swap(i, j)
    
    def merge(self, arr2):
        i, j, k = 0, 0, 0
        arr3 = Array(self.length + arr2.length)

        while i < self.length and j < arr2.length:
            if self.A[i] < arr2.A[j]:
                arr3.A[k] = self.A[i]
                k += 1
                i += 1                
            else:
                arr3.A[k] = self.A[j]
                k += 1
                j += 1                
        
        while i < self.length:
            arr3.A[k] = self.A[i]
            k += 1            
            i += 1
        
        while j < arr2.length:
            arr3.A[k] = arr2.A[j]
            k += 1            
            j += 1

        arr3.length = self.length + arr2.length

        return arr3

    def union(self, arr2):
        i, j, k = 0, 0, 0
        arr3 = Array(self.length + arr2.length)

        while i < self.length and j < arr2.length:
            if self.A[i] < arr2.A[j]:
                arr3.A[k] = self.A[i]
                k += 1
                i += 1                
            elif arr2.A[j] < self.A[i]:
                arr3.A[k] = arr2.A[j]
                k += 1
                j += 1                
            else:
                arr3.A[k] = self.A[j]
                k += 1
                i += 1
                j += 1

        while i < self.length:
            arr3.A[k] = self.A[i]
            k += 1            
            i += 1
        
        while j < arr2.length:
            arr3.A[k] = arr2.A[j]
            k += 1            
            j += 1

        arr3.length = k

        return arr3

    def intersection(self, arr2):
        i, j, k = 0, 0, 0
        arr3 = Array(self.length + arr2.length)

        while i < self.length and j < arr2.length:
            if self.A[i] < arr2.A[j]:
                i += 1                
            elif arr2.A[j] < self.A[i]:
                j += 1                
            elif self.A[i] == arr2.A[j]:
                arr3.A[k] = self.A[j]
                k += 1
                i += 1
                j += 1

        arr3.length = k

        return arr3

    def difference(self, arr2):
        i, j, k = 0, 0, 0
        arr3 = Array(self.length + arr2.length)

        while i < self.length and j < arr2.length:
            if self.A[i] < arr2.A[j]:
                arr3.A[k] = self.A[i]
                k += 1
                i += 1 
            elif arr2.A[j] < self.A[i]:
                j += 1                
            else:
                i += 1
                j += 1

        while i < self.length:
            arr3.A[k] = self.A[i]
            k += 1            
            i += 1
        
        arr3.length = k

        return arr3

    def set_membership(self, key):
        l = 0
        h = self.length - 1

        while l <= h:
            mid = (l + h) / 2

            if key == self.A[mid]:
                return mid
            elif key < self.A[mid]:
                h = mid - 1
            else:
                l = mid + 1
        
        return -1