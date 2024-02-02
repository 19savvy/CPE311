#include "header.h"

using namespace std;


Person FillPerson(){
	Person person;
	char FirstName[25], LastName[25];

	cout << "Enter First Name: ";
	cin >> FirstName;
	cout << "Enter Last Name: ";
	cin >> LastName;
	strcpy_s(person.Name, sizeof(person.Name), FirstName);
	strcat_s(person.Name, sizeof(person.Name), " ");
	strcat_s(person.Name, sizeof(person.Name), LastName);
	cout << "Enter Birthday details in this format: dd/mm/yyy\n";
	cout << "Enter Birth day: ";
	cin >> person.BirthDay.day;
	cout << "Enter Birth month: ";
	cin >> person.BirthDay.month;
	cout << "Enter Birth year: ";
	cin >> person.BirthDay.year;

	return(person);
};

void WritePerson(Person person){
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	string selectedMonth;

	if (person.BirthDay.month >= 1 && person.BirthDay.month <= 12){
		selectedMonth = months[person.BirthDay.month - 1];
	}
	else{
		cerr << "Enter valid birth month\n";
	};
	cout << "Name: " << person.Name << endl;
	cout << "Birthday: " << person.BirthDay.day << " " << selectedMonth << " " << person.BirthDay.year << endl;
};

void WhoIsOlder(const Person &person1, const Person &person2){
	if (person1.BirthDay.year < person2.BirthDay.year) {
        cout << person1.Name << " is older than " << person2.Name << endl;
    } else if (person1.BirthDay.year > person2.BirthDay.year) {
        cout << person2.Name << " is older than " << person1.Name << endl;
    } else {
        // Birth years are the same, compare birth months
        if (person1.BirthDay.month < person2.BirthDay.month) {
            cout << person1.Name << " is older than " << person2.Name << endl;
        } else if (person1.BirthDay.month > person2.BirthDay.month) {
            cout << person2.Name << " is older than " << person1.Name << endl;
        } else {
            // Birth months are the same, compare birth days
            if (person1.BirthDay.day < person2.BirthDay.day) {
                cout << person1.Name << " is older than " << person2.Name << endl;
            } else if (person1.BirthDay.day > person2.BirthDay.day) {
                cout << person2.Name << " is older than " << person1.Name << endl;
            } else {
                cout << person1.Name << " and " << person2.Name << " are the same age." << endl;
            }
        }
    }

	WritePerson(person1);
	WritePerson(person2);
};
