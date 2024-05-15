#ifndef HEADER
#define HEADER

struct Room;
struct HostelStudent;
struct RegularStudent;
struct Student;
struct Transportation;

Room* createRoom(int roomNumber, int totalSeats);
Room* rentRoom(Room* head);
//void displayRooms(Room* head);
//void checkOut(Room* head);
//RegularStudent *createRegularStudent(int id, const string &classStartTime, const string &classEndTime, const string &location);
//RegularStudent *createRegularStudent(int id, const string &classStartTime, const string &classEndTime, const string &location);
//Transportation *createTransportation(const string &location, int busCapacity);
//void assignTransportation(RegularStudent *student, Transportation *transport);
//void displayTransportationDetails(Transportation *transport);

/*Room* headRoom = nullptr;
Room* tailRoom = nullptr;*/

//Student *top = nullptr;

// Function prototypes
/*bool isEmpty();
void popCycle();
void pushCycle();
void rentCycle();
void returnCycle();
void pushStudent(string id, string out);
void pushStudentIn(string id, string in);
int pushTime(const string &t);*/

void hostel();
//void non_hostel();
void cycle();
void bus();

#endif