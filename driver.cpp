#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include "HashTableDemo.h"

using namespace std;

vector<float> readInput();

int main()
{
    int hashTableSize = 29 ;
    HashTableDemo hashObject(hashTableSize);

    float userInput;
    int userChoice;
    vector<float> numbers = readInput();

    /*
        There is some error in reading input file
    */
    if(numbers.size() == 0 )
    {
        return 1 ;
    }


    for (int i = 0; i < numbers.size(); i++)
    {
        hashObject.insert(numbers[i]);
    }

    
    hashObject.printInfo();

    while (true)
    {
        cout << "\nEnter Amount:" << endl ;
        cout << "$" ;
        cin >> userInput;
        if (hashObject.find(userInput) == -1)
        {
            cout << "\nInvalid Data";
        }
        else
        {
            cout << endl << hashObject.find(userInput);
        }
        cout << "\nDo you want to continue\n"
             << "1 for Yes\n2 for No\n";
        cin >> userChoice;
        if (userChoice == 2)
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
            float num_float = stof(tp.substr(1, tp.length() - 1));
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