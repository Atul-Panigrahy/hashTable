#include <iostream>
#include <windows.h>

using namespace std;

class HashTableDemo
{
public:
    float *hash;
    int i;
    int size, m, n;
    HashTableDemo(int n)
    {
        hash = new float[n];
        i = 0;
        size = n;
        m = 2;
        this->n = 3;
    }
    void insert(float amount)
    {
        int w = (int)amount;
        float f = amount - w;
        hash[(int)((m * w) + (n * f)) % size] = amount;
    }
    int find(float amount)
    {
        int w = (int)amount;
        float f = amount - w;
        if (hash[(int)((m * w) + (n * f)) % size] == amount)
        {
            return (int)((m * w) + (n * f)) % size;
        }
        return -1;
    }
};

int main()
{

    HashTableDemo d(29);
    float amt;
    float eamt;
    int cont;
    for (int i = 0; i < 29; i++)
    {
        cin >> amt;
        d.insert(amt);
    }
    while (true)
    {
        cout << "\nEnter Amount:";
        cin >> eamt;
        if (d.find(eamt) == -1)
        {
            cout << "\nInvalid Data";
        }
        else
        {
            cout << endl
                 << d.find(eamt);
        }
        cout << "\nDo you want to continue\n"
             << "1 for Yes\n2 for No\n";
        cin >> cont;
        if (cont == 2)
        {
            break;
        }
    }

    //halt the program for 10 seconds
    Sleep(10);
    return 0;
}