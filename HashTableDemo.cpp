#include <iostream>
#include "HashTableDemo.h"

HashTableDemo::HashTableDemo(int input_)
{
    tableSize = input_;
    hashTable = new float[tableSize];

   /*
    initialize the hashTable array to -1 
    indicates no key is present at that __has_include_next
    */
    for(int i=0;i<tableSize;i++)
    {
        hashTable[i] = -1 ;
    }
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

    int hashcode = (int)((m * w) + (n * f)) % tableSize;

    // implement collision handling here
    
    hashTable[hashcode] = amount;
}

void HashTableDemo:: printInfo ()
{
    std::cout << "Number of data items loaded: " << count << std::endl ;
    std::cout << "Load factor: " << loadFactor << std::endl ;
    std::cout << "Number of collisions: " << collisions << std::endl ;
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