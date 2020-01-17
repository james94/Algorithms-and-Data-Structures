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

int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1, i;

    if(index < 1 || index > count(p))
    {
        return -1;
    }
    if(index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
    }
    else
    {
        for(i = 0; i < index-1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
    }
    return x;
}

int isSorted(struct Node *p)
{
    int x = INT32_MIN;

    while(p != NULL)
    {
        if(p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next;

    while(q != NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
        
    }
}

int main()
{
    // int A[] = {10,20,3,40,50};

    // 20 is duplicated 3 times, remove keeps 1, 20
    // int A[] = {10,20,20,20,30,40,50};
    // create(A,7);

    // 20 and 40 is duplicated 3 times, remove keeps 1, 20 and 40
    // int A[] = {10,20,20,20,30,40,40,40,50};
    // create(A,9);

    // 10, 20 and 40 is duplicated 3 times, remove keeps 1, 10,20,40
    // int A[] = {10,10,10,20,20,20,30,40,40,40,50};
    // create(A,11);

    // 10 is duplicated 3 times, remove keeps 1, 10
    int A[] = {10,10,10};
    create(A,3);

    RemoveDuplicate(first);

    Display(first);
    printf("\n\n");

    return 0;
}