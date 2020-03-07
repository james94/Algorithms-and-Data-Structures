# Array ADT Quiz

## Question 1

Suppose you are given an array s[1...n] and a procedure `reverse(s,i,j)`, which reverse the order of elements in between position i and j (both inclusive).

What does the following sequence do, where 1 <= k <= n:

~~~cpp
reverse(s,1,k);
reverse(s,k+1,n);
reverse(s,1,n);
~~~

- rotates s left by k position
- leaves s unchanged
- reverse all elements of s
- none of the above

<!--
Answer = rotates s left by k position

arr = {2,3,4,5,6,7,8}
      {4,3,2,5,6,7,8}
      {4,3,2,8,7,6,5}
      {5,6,7,8,2,3,4}

Notice what happens to s after the sequence is it is rotated left by k position. We take out 2, shift all elements to the left and 
insert 2 at the back. Do the same process for
3 and 4, resulting in {5,6,7,8,2,3,4}. So, if
you perform left rotate k=3 times, we get the 
above result.
-->

## Question 2

A program p reads in `500 integers` in the range `(0,100)` representing the scores of `500 students`. It prints the frequency of each score above `50`, what would be the best way for p to store the frequencies?

- an array of 50 numbers
- an array of 100 numbers
- an array of 500 numbers
- a dynamically allocated array of 550 numbers

<!--
Answer = an array of 50 numbers

Ex: A = {10,12,....,3}
          0  1     99

Store the frequency of each score above 50. Frequency means each element will be the number of students who scored > 50. Ex, 10 students scored 51, 12 students scored 52, etc. So, we need to allocate room for 50 elements in the array since we need to store the number of students who scored 51, then the students who scored 52 up to the number of students who scored 100. 
-->

## Question 3

Let `a` be an array containing `n` integers in increasing order. The following algorithm determines whether there are two distinct numbers in the array whose difference is a specified number `s < 0`.

What should the condition be for `E`?

~~~cpp
i = 0; j = 1;
while(j < n) {
    if(E) j++;
    else if(a[j]-a[i] == s) break;
    else i++;
}
if(j < n) printf("yes");
~~~

- `a[j]-a[i]>s`

- `a[j]-a[i]<s`

- `a[i]-a[j]<s`

- `a[i]-a[j]>s`

<!--
Answer: E = `a[j]-a[i]<s`

Ex:
a = {2,4,8,9,13,16,19,23,25};
     0,1,2,3, 4, 5, 6, 7, 8
     i j

is a[i] - a[j] == s? False, so to keep
checking for the two numbers in the array
whose difference is specified number s,
move j. When a[i]-a[j] < s, then j++.
s = 10

if the differene is < s, then move j.
if the difference is > s, then move i.
-->

## Question 4

What is the time taken to find any element from an Array of elements, which is neither maximum nor minimum?

- O(1)
- O(n)
- O(n2)
- O(logn)

<!--
Answer = O(1)

Ex:

a = {8,7,5,12,9,3,4}
     |      |   |
    any    max  min

Let's say we know the max and min element.
Our job is to find any element that is
neither max nor min. There are elements left
where we can pick any one.  

It takes constant time to choose an element out of 3 elements that is neither min or max.
You don't have to scan the whole array.
Time Complexity: O(1)
-->

## Question 5

What is the time taken to find the second largest element in an Array?

- O(n)
- O(nlogn)
- O(n2)
- O(n2logn)

<!--
Answer = O(n)

Ex:

a = {7,12,15,6,4,13,9,5}

1st time, you scan whole array for largest
element. You find it is 15, mark it with -1.
2nd time, you can scan whole array for second
largest element, you find it is 13.
Each scan of entire array is n time.
Time Complexity: O(n)
-->