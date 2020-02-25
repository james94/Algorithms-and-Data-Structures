# Arrays Representation Quiz

## Question 1

Let A be a two-dimensional array declared as follows:

~~~cpp
A: array[1....10][1....15] of integer
~~~

Assuming that each integer takes one memory location. The array is stored in row-major order and the first element of the array is stored at location 100, what is the address of the element A[i][j]?

<!--
Answer = 15i + j + 84
-->

## Question 2

What is the output of the following C code? Assume that the address of x is 2000 (in decimal) and an integer requires four bytes of memory.

~~~cpp
int main()
{
    unsigned int x[4][3] = {{1,2,3}, {4,5,6},{7,8,9},{10,11,12}};
    printf("%u,%u,%u", x+3, *(x+3),*(x+2)+3);
}
~~~

<!-- 
answer = 2036, 2036, 2036
-->

## Question 3

If A and B are two Matrices, for multiplying A x B which of the following representations will be efficient?

<!-- 
answer = Independent of Representation
-->

## Question 4

If a 3D Array is declared in C language as follows

~~~cpp
?X[?][?][?]
~~~

Find data type and dimensions of Array if compiler
performs the following intermediate operations for finding Address of any location `X[i][j][k]`.

~~~cpp
t0=I * 1024

t1=j * 32

t2=k * 4

t3=t0+t1

t4=t3+t2

t5=X[t4]
~~~

Note: Assume int takes 2 bytes float takes 4 bytes

<!--
Answer = float X[12][32][8]
-->
