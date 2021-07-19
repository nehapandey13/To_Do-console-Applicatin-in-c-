// To-do Console Application in C++
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// In this application we are goino create 4 options
/*
# 1. Add an item15

# 2. Mark as done
# 3. View Items
# 4. Exit()
*/

int user_input = -1;
//creating a vector that stores the data items
vector<string> data;
//storing items
string item;

// Functions that shows Menu Item:
void showMenu()
{
    cout << "########**MENU**#########" << endl;
    cout << "#   1. Add an item:       #" << endl;
    cout << "#   2. Mark as Done:      #" << endl;
    cout << "#   3. View Items:        #" << endl;
    cout << "#   4. Exit:              #" << endl;
    cout << "###### Coded By NEHA ######" << endl;
}

//function that shows error
char showError()
{
    cout << "Wrong Input" << endl;
    cout << "Press # for Main Menu" << endl;
    char pressBtn;
    cin.ignore();
    cin >> pressBtn;
    return pressBtn;
}
int main()
{
    while (user_input != 4)
    {
        showMenu();
        cout << "Enter Your Choice: " << endl;
        cin >> user_input;
        if (user_input == 1)
        {
            cout << "What is to be done ? \n";
            cin.ignore();
            getline(cin, item);
            data.push_back(item);
            cout << "Added Item --> " << item << endl;
        }
        else if (user_input == 2)
        {
            cout << "What is to be marked as Done ?" << endl;
            cin.ignore();
            getline(cin, item);
            // #if item is present in data list then remove it from list
            // #else print item does not exist in the list
            auto rslt = find(data.begin(), data.end(), item);
            if (rslt != data.end())
            {
                data.erase(rslt);
                cout << "Removed Item--> " << item << endl;
            }
            else
            {
                cout << "Item does not exist in the to-do list" << endl;
            }
        }
        else if (user_input == 3)
        {
            int count = 1;
            cout << "\n\n\n";
            cout << "**List of To-Do-Items**" << endl;
            for (auto items : data)
            {
                cout << count++ << "-> " << items << endl;
            }
            cout << "\n\n\n";
        }
        else if (user_input == 4)
        {
            cout << "Good Bye" << endl;
        }
        else
        {
            char pressBtn = showError();
            while (pressBtn != '#')
            {
                pressBtn = showError();
            }
            continue;
        }
    }
    return 0;
}