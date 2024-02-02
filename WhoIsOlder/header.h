#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>

struct Date {
	int month, day, year;
};

struct Person {
	char Name[50];
	Date BirthDay;
};

Person FillPerson();
void WritePerson(Person person);
void WhoIsOlder(const Person &person1, const Person &person2);

#endif /* _HEADER_H_ */
