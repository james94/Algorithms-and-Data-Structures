#ifndef Chains_h
#define Chains_h
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first=NULL;

void SortedInsert(struct Node **H, int x)
{
    struct Node *t, *q = NULL, *p=*H;

    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(*H == NULL)
    {
        *H = t;
    }
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if(p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

// Linear Search using Iteration
struct Node * Search(struct Node *p, int key)
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

#endif /* Chains_h */