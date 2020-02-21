#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Node
{
    int data;
    struct Node *next;
} *first=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void RDisplay(struct Node *p)
{
    if(p != NULL)
    {
        printf("%d \n", p->data);
        RDisplay(p->next);
        // following printf prints in reverse order
        // printf("%d ", p->data);
    }
}

int count(struct Node *p)
{
    int c = 0;
    while(p)
    {
        c++;
        p = p->next;
    }
    return c;
}

int Rcount(struct Node *p)
{
    if(p != NULL)
    {
        return Rcount(p->next)+1;
    }
    else
    {
        return 0;
    }
}

int sum(struct Node *p)
{
    int s = 0;
    while(p != NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

int Rsum(struct Node *p)
{
    if(p == NULL)
    {
        return 0;
    }
    else
    {
        return Rsum(p->next) + p->data;
    }
}

int IterMax(struct Node *p)
{
    int max = INT32_MIN;
    while(p)
    {
        if(p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

// Find max element using Recursion v1
int R1max(struct Node *p)
{
    int x = 0;
    if(p == NULL)
    {
        return INT32_MIN;
    }
    else
    {
        x = R1max(p->next);
        if(x > p->data)
        {
            return x;
        }
        else
        {
            return p->data;
        }
    }
}

// Find max element using Recursion v2
int R2max(struct Node *p)
{
    int x = 0;
    if(p == NULL)
    {
        return INT32_MIN;
    }
    x = R2max(p->next);
    return x > p->data ? x : p->data;
}

int main()
{
    int A[] = {3,5,7,10,15,8,12,20};
    create(A,8);

    printf("Length is %d\n\n", Rcount(first));

    printf("Max is %d\n\n", R2max(first));

    return 0;
}