SOURCE = admin.cpp DS_Cycle.cpp DS_Hostel.cpp DS_Transport.cpp header.h
TARGET = main

@: 
	g++ $(SOURCE) -o $(TARGET)