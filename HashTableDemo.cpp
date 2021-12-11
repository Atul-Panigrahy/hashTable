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
    for (int i = 0; i < tableSize; i++)
    {
        hashTable[i] = -1;
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
    loadFactor = (float)count / tableSize;
    int w = (int)amount;
    float f = amount - w;

    int hashcode = (int)((m * w) + (n * f)) % tableSize;

    // implement collision handling using quadratic probing

    /*
        If there is a collision iterating through all
        possible quadratic values
    */
    for (int j = 0; j < tableSize; j++)
    {
        // Computing the new hash value
        int t = (hashcode + j * j) % tableSize;
        if (hashTable[t] == -1)
        {
            /* 
                Break the loop after inserting the value in the hashTable
            */
            hashTable[t] = amount;
            break;
        }
        else
        {
            collisions++;
        }
    }

}

void HashTableDemo::printInfo()
{
    std::cout << "Number of data items loaded: " << count << std::endl;
    std::cout << "Load factor: " << loadFactor << std::endl;
    std::cout << "Number of collisions: " << collisions << std::endl;
}

int HashTableDemo::find(float amount)
{
    int w = (int)amount;
    float f = amount - w;

    int hashcode = (int)((m * w) + (n * f)) % tableSize;

    for (int j = 0; j < tableSize; j++)
    {
        // Computing the new hash value
        int t = (hashcode + j * j) % tableSize;
        if (hashTable[t] == amount)
        {
            return t ;
        }
    }
    
    return -1;
}

HashTableDemo ::~HashTableDemo()
{
    delete[] hashTable;
}