#include <stdio.h>
#include <stdlib.h>
#include "Chains.h"

// retrieves hash code for Insert function
int hash(int key)
{
    return key%10;
}

// Insert Key into Hash Table
void Insert(struct Node *H[], int key)
{
    // Get index from hash function by setting key
    int index = hash(key);

    // Inside an array of chains at a given index,
    // perform an sorted insert with key in a LL
    SortedInsert(&H[index], key);
}

int main()
{
    // Hash table is a structure node array
    // of pointers
    struct Node *HT[10];
    struct Node *temp;
    // int key = 42;
    int key = 41;
    int i;

    for(i=0; i<10; i++)
    {
        HT[i]=NULL;
    }

    // Perform Insert on Hash Table with key 12
    Insert(HT, 12);
    // Perform Insert on Hash Table with same index
    // NOTE: It should insert in that same chain
    Insert(HT, 42);
    Insert(HT, 62);

    // Search for key, we send hash(key) to get index in hash
    // table and also the key to search for in that place
    temp = Search(HT[hash(key)], key);

    // get an error because 41s data is not present, it is NULL
    printf("%d", temp->data);

    return 0;
}