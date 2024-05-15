// DS_Cycle.cpp
#include <iostream>
#include <string>
#include <utility>
#include "header.h"

const int MAX_CYCLES = 50;
int TOP = MAX_CYCLES - 1;

using namespace std;
void pushStudent(string id, const string& out);
void pushStudentIn(const string& id, const string& in);


struct Student
{
    string id;
    string out;
    string in;
    int secOut{};
    int secIn{};
    int total{};
    double cost{}; // Change the data type to double for accurate cost calculation
    Student *next{};
};

Student *top = nullptr;

bool isEmpty()
{
    return TOP == -1;
}

void popCycle()
{
    TOP--;
}

void pushCycle()
{
    TOP++;
}

int pushTime(const string &t)
{
    int time = stoi(t);
    int hours = time / 100;
    int minutes = time - (hours * 100);
    return (hours * 3600) + (minutes * 60);
}

void rentCycle()
{
    string id, out;
    cout << "Student: Can I rent a cycle?" << endl;

    if (isEmpty())
    {
        cout << "No cycles available" << endl;
    }
    else
    {
        cout << "Yes, you can" << endl;
        cout << "Enter ID: ";
        cin.ignore();
        getline(cin, id);
        cout << "Out time (24-hour format, e.g., 1220 for 12:20): ";
        getline(cin, out);
        cout << "Enjoy your ride!! =)" << endl;

        pushStudent(id, out);
        popCycle();
    }
}

void returnCycle()
{
    string basicString, in, id;
    cout << "Staff: Return cycle? (yes/no)" << endl;
    cout << "Student: ";
    cin >> basicString;

    if (basicString == "yes")
    {
        cout << "Enter ID: ";
        cin.ignore();
        getline(cin, id);
        cout << "In time (24-hour format, e.g., 1220 for 12:20): ";
        getline(cin, in);

        pushStudentIn(id, in);
        pushCycle();
    }
    else
    {
        cout << "Continue enjoy your ride!" << endl;
    }
}

void pushStudent(string id, const string& out)
{
    auto *newNode = new Student;
    newNode->id = std::move(id);
    newNode->out = out;
    newNode->secOut = pushTime(out);
    newNode->next = top;
    top = newNode;
}

void pushStudentIn(const string& id, const string& in)
{
    Student *temp = top;

    while (temp != nullptr)
    {
        if (temp->id == id)
        {
            temp->in = in;
            temp->secIn = pushTime(in);
            temp->total = temp->secIn - temp->secOut;
            temp->cost = (temp->total / 60.0) * 0.5; // Corrected the cost calculation
            cout << "Total time for " << temp->id << ": " << temp->total << " seconds" << endl;
            cout << "Cost for " << temp->id << ": tk " << temp->cost << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "No entry found for student: " << id << endl;
}

void cycle()
{
    while (true)
    {
        std::cout << "Cycle Rental System Menu:" << std::endl;
        std::cout << "1. Rent a Cycle" << std::endl;
        std::cout << "2. Return a Cycle" << std::endl;
        std::cout << "3. Exit Cycle Rental System" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                rentCycle();
                break;
            case 2:
                returnCycle();
                break;
            case 3:
                std::cout << "Exiting Cycle Rental System." << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
}
//filename: DS_Cycle.cpp