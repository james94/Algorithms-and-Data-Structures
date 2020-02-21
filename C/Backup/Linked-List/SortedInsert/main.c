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

// Find min element using Iteration
int min(struct Node *p)
{
    int m = INT32_MAX;
    while(p)
    {
        if(p->data < m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

// Find min element using Recursion
int R1min(struct Node *p)
{
    int x = 0;
    if(p == NULL)
    {
        return INT32_MAX;
    }
    else
    {
        x = R1min(p->next);
        if(x < p->data)
        {
            return x;
        }
        else
        {
            return p->data;
        }
        
    }
    
}

// Linear Search using Iteration
struct Node * LSearch(struct Node *p, int key)
{
    while(p != NULL)
    {
        // is key equal to node data p points to
        if(key == p->data)
        {
            // return address of node p points to
            return p;
        }
        // no, so move to next node
        p = p->next;
    }
    return NULL;
}

// Linear Search using Recursion
struct Node *RLSearch(struct Node *p, int key)
{
    if(p == NULL)
    {
        return NULL;
    }
    if(key == p->data)
    {
        return p;
    }
    return RLSearch(p->next, key);
}

// Linear Search using Move to Head Improvement
struct Node *MtHLSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while(p != NULL)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    // check if index given is invalid before inserting
    if(index < 0 || index > count(p))
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if(index == 0)
    {
        t->next = first;
        first = t;
    }
    else if(index > 0)
    {
        p = first;
        for(i = 0; i < index-1; i++)
        {
            p=p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;

    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(first == NULL)
    {
        first = t;
    }
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    // int A[] = {10,20,30,40,50};
    // create(A,5);

    // Insert in linked list through traversing it
    // SortedInsert(first, 35);

    // Insert at beginning of list
    // SortedInsert(first, 5);

    // Create new list if one doesn't exist
    SortedInsert(first, 55);
    SortedInsert(first, 25);

    Display(first);

    return 0;
}