#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include "HashTableDemo.h"

using namespace std;

vector<float> readInput();

int main()
{
    HashTableDemo d(29);
    float amt;
    float eamt;
    int cont;
    vector<float> numbers = readInput();

    for (int i = 0; i < numbers.size(); i++)
    {
        d.insert(numbers[i]);
    }

    d.printInfo();

    while (true)
    {
        cout << "\nEnter Amount:" << endl ;
        cout << "$" ;
        cin >> eamt;
        if (d.find(eamt) == -1)
        {
            cout << "\nInvalid Data";
        }
        else
        {
            cout << endl << d.find(eamt);
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

vector<float> readInput()
{
    fstream newfile;
    vector<float> numbers;
    newfile.open("input.txt", ios::in); //open a file to perform read operation using file object
    if (newfile.is_open())
    {
        //checking whether the file is open
        string tp;
        while (getline(newfile, tp))
        {
            //read data from file object and put it into string.
            //cout << tp << "\n"; //print the data of the string
            float num_float = std::stof(tp.substr(1, tp.length() - 1));
            numbers.push_back(num_float);
        }
        newfile.close(); //close the file object.
    }
    else
    {
        cout << "ERROR: opening input.txt unsuccesful!!" << endl;
    }

    return numbers;
}