#ifndef HASHTABLEDEMO.H
#define HASHTABLEDEMO .H

class HashTableDemo
{
public:
    float *hashTable;
    int count;
    int tableSize, m, n;
    int collisions, loadFactor;
    HashTableDemo(int n) {}
    void insert(float amount) {}
    void printInfo(); 
    int find(float amount) {}
};

#endif // HASHTABLEDEMO
