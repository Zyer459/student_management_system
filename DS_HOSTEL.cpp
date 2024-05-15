// student reg// done
// fee// default 1000 million dollars
// room reg// done
// seat reg// done
// food reg// baad

// in out// done 

#include <iostream>
#include <string>
#include "header.h"

using namespace std;

struct Room;
struct HostelStudent;

Room* createRoom(int roomNumber, int totalSeats);
Room* rentRoom(Room* head);
void displayRooms(Room* head);
void checkOut(Room* head);

Room* headRoom = nullptr;
Room* tailRoom = nullptr;
void hostel ();

// Structure for hostel student
struct HostelStudent
{
    int id;
    string checkInDate;
    string checkOutDate;
    int fee;
    HostelStudent* next;
};

// Structure for room
struct Room
{
    int roomNumber;
    int totalSeats;
    HostelStudent** seatStudents; // Array of pointers
    bool* isSeatOccupied;
    Room* nextRoom;
};

// Create a room
Room* createRoom(int roomNumber, int totalSeats)
{
    Room* newRoom = new Room;
    newRoom->roomNumber = roomNumber;
    newRoom->totalSeats = totalSeats;
    newRoom->seatStudents = new HostelStudent*[totalSeats](); // Initialize to nullptr
    newRoom->isSeatOccupied = new bool[totalSeats](); // Initialize to false
    newRoom->nextRoom = nullptr;

    // Link the new room to the list
    if (tailRoom == nullptr)
    {
        headRoom = newRoom;
        tailRoom = newRoom;
    }
    else
    {
        tailRoom->nextRoom = newRoom;
        tailRoom = newRoom;
    }

    return newRoom;
}

// Rent a room function
Room* rentRoom(Room* head)
{
    int roomId;
    cout << "Enter the room number to rent: ";
    cin >> roomId;

    Room* currentRoom = head;

    // Find the requested room
    while (currentRoom != nullptr && currentRoom->roomNumber != roomId)
    {
        currentRoom = currentRoom->nextRoom;
    }

    if (currentRoom == nullptr)
    {
        cout << "Room not found." << endl;
        return head;
    }

    // Check for available seats
    int availableSeatIndex = -1;
    for (int i = 0; i < currentRoom->totalSeats; ++i)
    {
        if (!currentRoom->isSeatOccupied[i])
        {
            availableSeatIndex = i;
            break;
        }
    }

    if (availableSeatIndex == -1)
    {
        cout << "No available seats in the room." << endl;
        return head;
    }

    // Rent the seat to a hostel student
    HostelStudent* newStudent = new HostelStudent;
    cout << "Enter student id: ";
    cin >> newStudent->id;
    cout << "Enter check-in date (dd-mm-yy): ";
    cin >> newStudent->checkInDate;

    currentRoom->seatStudents[availableSeatIndex] = newStudent;
    currentRoom->isSeatOccupied[availableSeatIndex] = true;

    cout << "Student " << newStudent->id << " rented a seat in room " << currentRoom->roomNumber << endl;

    return head;
}

// Display information about available rooms
void displayRooms(Room* head)
{
    Room* currentRoom = head;

    cout << "Available Rooms:" << endl;

    while (currentRoom != nullptr)
    {
        cout << "Room " << currentRoom->roomNumber << ": ";

        for (int i = 0; i < currentRoom->totalSeats; ++i)
        {
            if (!currentRoom->isSeatOccupied[i])
            {
                cout << "Seat " << (i + 1) << " (Available) ";
            }
            else
            {
                cout << "Seat " << (i + 1) << " (Occupied by Student " << currentRoom->seatStudents[i]->id << ") ";
            }
        }

        cout << endl;

        currentRoom = currentRoom->nextRoom;
    }
}

// Check out a student function
void checkOut(Room* head)
{
    int studentId;
    cout << "Enter student id to check out: ";
    cin >> studentId;

    Room* currentRoom = head;

    // Find the room with the student
     while (currentRoom != nullptr)
    {
        for (int i = 0; i < currentRoom->totalSeats; ++i)
        {
            if (currentRoom->isSeatOccupied[i] && currentRoom->seatStudents[i]->id == studentId)
            {
                // Check out the student
                currentRoom->isSeatOccupied[i] = false;

                HostelStudent* studentToCheckOut = currentRoom->seatStudents[i];

                cout << "Enter check-out date (dd-mm-yy) for Student " << studentId << ": ";
                cin >> studentToCheckOut->checkOutDate;

                cout << "Student " << studentId << " checked out from seat in room " << currentRoom->roomNumber << endl;
                delete studentToCheckOut; // Release memory allocated for the student
                currentRoom->seatStudents[i] = nullptr; // Set the pointer to nullptr
                return;
            }
        }

        currentRoom = currentRoom->nextRoom;
    }

    // Student not found
    cout << "Student not found in any room." << endl;
}


void hostel ()
{
    // Create rooms with 4 seats
    headRoom = createRoom(101, 4);
    tailRoom = createRoom(102, 4);

  
    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Display available rooms" << endl;
        cout << "2. Rent a room" << endl;
        cout << "3. Check out a student" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 2:
            rentRoom(headRoom);
            break;
        case 1:
            displayRooms(headRoom);
            break;
        case 3:
            checkOut(headRoom);
            break;
        case 4:
            cout << "Exiting hostel program." << endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
}
//filename: DS_Hostel.cpp