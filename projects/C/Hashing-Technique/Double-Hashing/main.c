#include <stdio.h>
#define SIZE 10

// needs index for using hash function
int hash1(int key)
{
    return key%SIZE;
}

// needs key and nearest prime number to 10, which is 7
int hash2(int key)
{
    return 7 - (key%7);
}

// find next free space for inserting key using double hashing
int doubleHashing(int H[], int key)
{
    int index = hash1(key);
    int i = 0;
    //increment until next free space found
    while(H[(index+(i*hash2(key)))%SIZE]!=0)
    {
        i++;
    }
    // returns new free index where key value can be inserted
    return (index+(i*hash2(key)))%SIZE;
}

// Insert Key into Hash Table
// takes array as hash table and key
void Insert(int H[], int key)
{
    int index = hash1(key);

    // check whether index is free or not
    // if hash function of index is not equal to 0,
    // then it is already occupied
    if(H[index]!=0)
    {
        index = doubleHashing(H, key);
    }
    // at that place, we will insert an element at a hash table
     H[index] = key;
}

// search for key in hash table using quadratic probing
int Search(int H[], int key)
{
    // get index from hash function, pass key
    int index = hash1(key);

    // as it is quadratic probing, it should check whether
    // value is present or not
    int i=0;

    // checks for key value, breaks out of loop if key is found
    // otherwise breaks out of loop if key is not found

    while(H[(index+(i*hash2(key)))%SIZE]!=key && H[(index+(i*hash2(key)))%SIZE]!=0)
    {
        i++;
    }
    // checks if key in hash table was not found, return -1
    if(H[(index+(i*hash2(key)))%SIZE] == 0)
    {
        // returns -1 as index if key not found
        return -1;
    }
    // returns index of the key found
    return (index+(i*hash2(key)))%SIZE;
}

int main()
{
    int HT[10] = {0};

    // Insert keys into hash table using quadratic probing
    Insert(HT, 5); // index = 2, index+0
    Insert(HT, 25); // index = 2, index+1 since collision
    Insert(HT, 15); // index = 2, index+4 since collision
    Insert(HT, 35); // index = 6, index+1 since collision
    Insert(HT, 95);

    printf("\nKey found at %d\n", Search(HT, 25));

    printf("\nKey found at %d\n", Search(HT, 45));

    return 0;
}