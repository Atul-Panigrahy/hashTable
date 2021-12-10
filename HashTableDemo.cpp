#include <iostream>
#include "HashTableDemo.h"

HashTableDemo::HashTableDemo(int input_)
{
    tableSize = input_;
    hashTable = new float[tableSize];
    count = 0;
    tableSize = input_;
    m = 2;
    n = 3;
    collisions = 0;
    loadFactor = 0;
}

void HashTableDemo::insert(float amount)
{   
    count++;
    int w = (int)amount;
    float f = amount - w;

    // implement collision handling here
    int hashcode = (int)((m * w) + (n * f)) % tableSize;

    hashTable[hashcode] = amount;
}

void HashTableDemo:: printInfo ()
{
    
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

HashTableDemo ::~HashTableDemo()
{
    delete[] hashTable;
}