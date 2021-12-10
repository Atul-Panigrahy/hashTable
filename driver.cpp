#include <iostream>
#include <windows.h>
#include "HashTableDemo.h"

using namespace std;

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