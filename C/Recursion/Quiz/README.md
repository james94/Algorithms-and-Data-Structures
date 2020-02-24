# Recursion Quiz

## Question 1

Consider the following C function

~~~cpp
int f(int n)
{
    static int i = 1;
    if(n >= 5)
    {
        return n;
    }
    n = n + i;
    i++;
    return f(n);
}
~~~

The value returned by f(1) is:

<!--
Step by step solution
f(1): i = 1, n is not >= 5, n = 1+1 = 2

f(2): i = 2, n is not >= 5, n = 2+2 = 4

f(3): i = 3, n is >= 5, n = 4+3 = 7
so, return 7

Answer = 7
-->

## Question 2

Consider the following C program

~~~cpp
void foo(int n, int sum)
{
    int k = 0, j = 0;
    if(n == 0)
    {
        return;
    }
    k = n % 10;
    j = n/10;
    sum = sum + k;
    foo(j, sum);
    printf("%d", k);
}

int main()
{
    int a = 2048, sum = 0;
    foo(a, sum);
    printf("%d\n", sum);
}
~~~

What does the above program print?

<!--
Step by step solution
main: a = n = 2048, sum = 0

foo(2048, 0): k = 8, j = 204, sum = 8
   j=204
10 | 2048
    -2040
r = 8

foo(204, 8): k = 4, j = 20, sum = 12 
   j=20
10 | 204
    -200
r = 4

foo(20, 12): k = 0, j = 2, sum = 12
   j=2
10 | 20
    -20
r = 0

foo(2, 12): k = 2, j = 0, sum = 14
   j=0
10 | 2
    -0
r = 2

foo(0, 14): n is 0 so return

Output: 2, 0, 4, 8

main: sum = 0 cause of pass by value

Output: 2, 0, 4, 8, 0
-->

## Question 3

What is the return value of f(p, p), if the value of p is initialised to 5 before the call? Note the first parameter is passed by reference, whereas the second parameter is passed by value.

~~~cpp
int f(int &x, int c)
{
    c = c - 1;
    if(c == 0)
    {
        return 1;
    }
    x = x + 1;
    return f(x, c) * x;
}
~~~

Note:
~~~cpp
// p is set to 5 before the call
p = 5

// what is the return value?
f(5,5)
~~~

<!--
Step by step solution
Sequence Order 1 - 11

1. call f(5,5)
11. upon return f(5,5) = 6561
So, answer = 6561

x is pass by ref, c is pass by value
2. f(5,5): c = 4, c is not 0, x = 6, f(6,4)*x
10. upon return f(6,4) = 729
so f(6,4)*9 = 729*9 = 6561
return 6561

3. f(6,4): c = 3, c is not 0, x = 7, f(7,3)*x
9. upon return f(7,3) = 81
so f(7,3)*9 = 81*9 = 729
return 729

4. f(7,3): c = 2, c is not 0, x = 8, f(8,2)*x
8. upon return f(8,2) = 9
so f(8,2)*9 = 9*9 = 81
return 81


5. f(8,2): c = 1, c is not 0, x = 9, f(9,1)*x
7. upon return f(9,1) = 1
so f(9,1)*9= 1*9 = 9
return 9

6. f(9,1): c = 0, c is 0, so return 1

-->

## Question 4

Consider the following C function

~~~cpp
int fun(int n)
{
    int x = 1, k;
    if(n == 1) {
        return x;
    }
    for(k = 1; k < n; ++k) {
        x = x + fun(k) * fun(n-k);
    }
    return x;
}
~~~

The return value of `fun(5)` is

<!--
Step by step solution

coming later
-->

## Question 5

What will be the output of the following C program?

~~~cpp
void count(int n)
{
    static int d = 1;
    printf("%d",n);
    printf("%d",d);
    d++;
    if(n > 1) count(n-1);
    printf("%d", d);
}

void main()
{
    count(3);
}
~~~

<!--
Step by step solution

coming later
-->