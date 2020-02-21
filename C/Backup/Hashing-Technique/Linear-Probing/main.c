#include <stdio.h>
#define SIZE 10

// needs index for using hash function
int hash(int key)
{
    return key%SIZE;
}

// find next free space for inserting key using linear probing
int probe(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    //increment until next free space found
    while(H[(index+i)%SIZE]!=0)
    {
        i++;
    }
    // returns new free index where key value can be inserted
    return (index+i)%SIZE;
}

// Insert Key into Hash Table
// takes array as hash table and key
void Insert(int H[], int key)
{
    int index = hash(key);

    // check whether index is free or not
    // if hash function of index is not equal to 0,
    // then it is already occupied
    if(H[index]!=0)
    {
        index = probe(H, key);
    }
    // at that place, we will insert an element at a hash table
     H[index] = key;
}

// search for key in hash table using linear probing
int Search(int H[], int key)
{
    // get index from hash function, pass key
    int index = hash(key);

    // as it is linear probing, it should check whether
    // value is present or not
    int i=0;

    // checks for key value, breaks out of loop if key is found
    // otherwise breaks out of loop if key is not found
    while(H[(index+i)%SIZE]!=key && H[(index+i)%SIZE]!=0)
    {
        i++;
    }
    // checks if key in hash table was not found, return -1
    if(H[(index+i)%SIZE] == 0)
    {
        // returns -1 as index if key not found
        return -1;
    }
    // returns index of the key found
    return (index+i)%SIZE;
}

int main()
{
    int HT[10] = {0};

    // Insert keys into hash table using linear probing
    Insert(HT, 12);
    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 26);

    printf("\nKey found at %d\n", Search(HT, 26));

    printf("\nKey found at %d\n", Search(HT, 37));

    return 0;
}