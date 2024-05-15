// DS_Transport.cpp
#include <iostream>
#include <string>
#include <cmath>
#include "header.h"

using namespace std;

const int BUS_CAPACITY = 20;

// Structure to represent a regular student
struct RegularStudent
{
    int id;
    string location;
    string classStartTime;
    string classEndTime;
    RegularStudent *nextStudent; // Pointer to the next student in the list
    RegularStudent *connector;   // Pointer to the next student in the transportation list
};

// Structure to represent transportation details
struct Transportation
{
    string location;
    int busCapacity;
    int availableSeats;
    int busDepartureTime;
    RegularStudent *passengerList;
};

// Function prototypes
RegularStudent *createRegularStudent(int id, const string &classStartTime, const string &classEndTime, const string &location);
Transportation *createTransportation(const string &location);
void assignTransportation(RegularStudent *student, Transportation *transport);
void displayTransportationDetails(Transportation *transport);

void bus()
{
    RegularStudent *head = nullptr;
    int id;
    string classStartTime;
    string classEndTime;
    string location;
    int option;
    int countDMD = 0, countMPR = 0, countSVR = 0;

    cout << "Welcome to Student Information System\n";

    // Input loop to gather information about regular students
    while (true)
    {
        cout << "\nEnter Non-Hostel Student Details:\n";

        // Getting input from the user
        cout << "ID: ";
        cin >> id;

        cout << "Class Start Time: ";
        cin >> classStartTime;

        cout << "Class End Time: ";
        cin >> classEndTime;

        cout << "Location (DMD/MPR/SVR): ";
        cin >> location;

        // Counting students based on location
        if (location == "DMD")
            countDMD++;
        else if (location == "MPR")
            countMPR++;
        else if (location == "SVR")
            countSVR++;

        // Creating a new regular student and adding it to the linked list
        RegularStudent *newStudent = createRegularStudent(id, classStartTime, classEndTime, location);

        newStudent->nextStudent = head;
        head = newStudent;

        // Asking the user if they want to add another regular student
        cout << "\nDo you want to add another Regular student? (1/0): ";
        cin >> option;
        if (option == 0)
        {
            break;
        }
    }

    // Displaying the summary of regular students
    cout << "\nSummary of Regular Students:\n";
    cout << "DMD Students: " << countDMD << "\n";
    cout << "MPR Students: " << countMPR << "\n";
    cout << "SVR Students: " << countSVR << "\n";

    // Calculate buses required based on student count and assign buses
    int busesForDMD = ceil(static_cast<double>(countDMD) / static_cast<double>(BUS_CAPACITY));
    int busesForMPR = ceil(static_cast<double>(countMPR) / static_cast<double>(BUS_CAPACITY));
    int busesForSVR = ceil(static_cast<double>(countSVR) / static_cast<double>(BUS_CAPACITY));

    // Create and assign buses
    Transportation *dmdTransport = createTransportation("DMD");
    Transportation *mprTransport = createTransportation("MPR");
    Transportation *svrTransport = createTransportation("SVR");

    for (int i = 0; i < busesForDMD; ++i)
        assignTransportation(head, dmdTransport);

    for (int i = 0; i < busesForMPR; ++i)
        assignTransportation(head, mprTransport);

    for (int i = 0; i < busesForSVR; ++i)
        assignTransportation(head, svrTransport);

    // Display transportation details
    cout << "\nTransportation Details:\n";
    displayTransportationDetails(dmdTransport);
    displayTransportationDetails(mprTransport);
    displayTransportationDetails(svrTransport);

    cout << "\nThank you for using Student Information System.\n";

}

// Function to create a new regular student
RegularStudent *createRegularStudent(int id, const string &classStartTime, const string &classEndTime, const string &location)
{
    RegularStudent *newStudent = new RegularStudent;
    newStudent->id = id;
    newStudent->classStartTime = classStartTime;
    newStudent->classEndTime = classEndTime;
    newStudent->location = location;
    newStudent->nextStudent = nullptr;
    newStudent->connector = nullptr;
    return newStudent;
}

// Function to create a new transportation
Transportation *createTransportation(const string &location)
{
    Transportation *transport = new Transportation;
    transport->location = location;
    transport->busCapacity = BUS_CAPACITY;
    transport->availableSeats = BUS_CAPACITY;
    transport->busDepartureTime = 80; // Bus departs 1 hour and 20 minutes before the class start time
    transport->passengerList = nullptr;
    return transport;
}


// Function to assign transportation to students
void assignTransportation(RegularStudent *student, Transportation *transport)
{
    // Calculate the total number of assigned students for the location
    int assignedStudents = 0;
    RegularStudent *currentStudent = student;
    while (currentStudent != nullptr)
    {
        if (currentStudent->location == transport->location)
        {
            assignedStudents++;
        }
        currentStudent = currentStudent->nextStudent;
    }

    // Assign transportation to students based on the summary
    for (int i = 0; i < assignedStudents && transport->availableSeats > 0; ++i)
    {
        RegularStudent *newPassenger = new RegularStudent(*student); // Create a copy of the student
        newPassenger->connector = transport->passengerList;
        transport->passengerList = newPassenger;
        transport->availableSeats--;

        // Move to the next student
        student = student->nextStudent;
    }
}

// Function to display transportation details
// Function to display transportation details
void displayTransportationDetails(Transportation *transport)
{
    cout << "Transportation for " << transport->location << ":\n";
    
    // Calculate the total number of assigned students for the location
    int assignedStudents = 0;
    RegularStudent *currentPassenger = transport->passengerList;
    while (currentPassenger != nullptr)
    {
        assignedStudents++;
        currentPassenger = currentPassenger->connector;
    }

    cout << "Number of Buses: " << ceil(static_cast<double>(assignedStudents) / static_cast<double>(BUS_CAPACITY))
         << " | Bus Capacity: " << transport->busCapacity
         << " | Assigned Students: " << assignedStudents
         << " | Available Seats: " << transport->availableSeats
         << "\nBus Departure Time: " << transport->busDepartureTime << " minutes before class start\n";
}
//filename: DS_Transport.cpp