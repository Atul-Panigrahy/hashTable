#ifndef HASHTABLEDEMO_H
#define HASHTABLEDEMO_H

class HashTableDemo
{
public:
    float *hashTable;
    int count;
    int tableSize, m, n;
    int collisions;
    float loadFactor;
    HashTableDemo(int n) ;
    void insert(float amount) ; 
    void printInfo() ;
    int find(float amount) ; 
    ~HashTableDemo() ;
};

#endif // HASHTABLEDEMO_H

