#include "header.h"

int main() {
    // Create two ClassAttendance variables
    ClassAttendance student1, student2;

    // Call the version of SetUpAttendance with user input
    SetUpAttendance(student1);

    // Call the version of SetUpAttendance with default punctual student information
    student2 = SetUpAttendance();

    // Call WriteItOut twice
    WriteItOut(student1);
    WriteItOut(student2);
	system("pause");

    return 0;
}
