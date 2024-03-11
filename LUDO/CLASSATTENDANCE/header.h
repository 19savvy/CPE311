#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <string>

using namespace std;

// Enumerated data type
enum Rating {
    Present,
    Absent,
    Leave,
    Withdrawn
};

// Data structure for Phone
struct Phone {
    int areaCode;
    int exchange;
    int phoneNumber;
};

// Structure for ClassAttendance
struct ClassAttendance {
    string className;
    Phone phone;
    Rating rating;
};
void WriteItOut(const ClassAttendance &attendance);
ClassAttendance SetUpAttendance();
void SetUpAttendance(ClassAttendance &attendance);

#endif
