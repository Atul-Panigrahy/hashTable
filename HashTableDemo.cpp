#include<iostream>
#include "HashTableDemo.h"

HashTableDemo::HashTableDemo(int input_)
{
    tableSize = input_ ;
    hashTable = new float[tableSize];
    index = 0;
    tableSize = input_;
    m = 2;
    n = 3;
}

void HashTableDemo::insert(float amount)
{
    int w = (int)amount;
    float f = amount - w;

    // implement collision handling here
    int hashcode = (int)((m * w) + (n * f)) % tableSize ; 


    hashTable[hashcode] = amount;
}

int HashTableDemo::find(float amount)
{
    int w = (int)amount;
    float f = amount - w;
    if (hashTable[(int)((m * w) + (n * f)) % tableSize] == amount)
    {
        return (int)((m * w) + (n * f)) % tableSize;
    }
    return -1;
}
 
HashTableDemo :: ~ HashTableDemo () 
{
    delete[] hashTable ;
}