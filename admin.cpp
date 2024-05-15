#include <bits/stdc++.h>
#include <string>
#include "header.h"

using namespace std;

void executeOption(int choice);


int main ()
{
    while (true)
    {
        int choice;
        cout << "1. Hostel Management" << endl << "2. Non-Hostel" << endl;
        cout << "3. Cycle Rental System" << endl << "0. Exit" << endl;
        cout << "Choose action: ";
        cin >> choice;
        if (choice == 0)
        {
            cout << "Exiting student management system" << endl;
            return 0;
        }
        executeOption(choice);
    }
    return 0;
}

void executeOption(int choice)
{
    switch (choice)
    {
    case 1:
        hostel();
        break;
    case 2:
        bus();
        break;
    case 3:
        cycle();
        break;
    default:
        cout << "Invalid choice, try again" << endl;
    }
}

//to compile the files--->g++ admin.cpp DS_Cycle.cpp DS_Hostel.cpp DS_Transport.cpp header.h -o admin