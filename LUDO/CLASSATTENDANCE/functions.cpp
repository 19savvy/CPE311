#include "header.h"

void SetUpAttendance(ClassAttendance &attendance) {
    cout << "Enter class name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, attendance.className);

    cout << "Enter area code, exchange, and phone number (separated by spaces): ";
    cin >> attendance.phone.areaCode >> attendance.phone.exchange >> attendance.phone.phoneNumber;

    cout << "Enter rating (0 for Present, 1 for Absent, 2 for Leave, 3 for Withdrawn): ";
    int ratingInput;
    cin >> ratingInput;
    attendance.rating = static_cast<Rating>(ratingInput);
}

// Overloaded function to set up attendance with default punctual student information
ClassAttendance SetUpAttendance() {
    ClassAttendance attendance;
    attendance.className = "Punctual Student's Class";
    attendance.phone.areaCode = 123;
    attendance.phone.exchange = 456;
    attendance.phone.phoneNumber = 7890;
    attendance.rating = Present;
    return attendance;
}

// Function to write out the structure information
void WriteItOut(const ClassAttendance &attendance) {
    cout << "Class Name: " << attendance.className << endl;
    cout << "Phone: " << attendance.phone.areaCode << "-" << attendance.phone.exchange << "-" << attendance.phone.phoneNumber << endl;
    cout << "Rating: ";
    switch (attendance.rating) {
        case Present:
            cout << "Present";
            break;
        case Absent:
            cout << "Absent";
            break;
        case Leave:
            cout << "Leave";
            break;
        case Withdrawn:
            cout << "Withdrawn";
            break;
    }
    cout << endl << endl;
}
