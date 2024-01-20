#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>

/*
main - describes the function
@vol1: calculates the volume of the first sphere
@vol2: calculates the volume of the second sphere
@SA1: calculates the surface area of the first sphere
@SA2: calculates the surface area of the second sphere
return: always 0
*/

using namespace std;

int sphere()
{
	string sphere1, sphere2;
	float radii1, radii2;
	const double pi = 3.14159265358979323846;
	float vol1, vol2, SA1, SA2;

	cout << "Enter the name of the first sphere:\n";
	cin >> sphere1;
	cout << "Enter the name of the second sphere:\n";
	cin >> sphere2;
	cout << "Enter the radius of " << sphere1 << endl;
	cin >> radii1;
	cout << "Enter the radius of " << sphere2 << endl;
	cin >> radii2;

	vol1 = (4 * (pi * (pow(radii1, 3))))/3;
	vol2 = (4 * (pi * (pow(radii2, 3))))/3;

	SA1 = (4 * (pi * (pow(radii1, 2))));
	SA2 = (4 * (pi * (pow(radii2, 2))));

	if (true)
	{
		cout << "The volume of " << sphere1 << " is " << vol1 <<\
			" and it's surface area is " << SA1 << endl;

		cout << "The volume of "<< sphere2 << " is " << vol2 <<\
			" and it's surface area is " << SA2 << endl;

	}
	if (true)

	system("pause");
	return 0;

}
void runagain()
{
	sphere();
	char choice;

	cout << "if you want to run the program again type 'y' else type any key ";
	cin >> choice;
	while (choice == 'y' || choice == 'Y')
	{
		sphere();
		cout << "if you want to run the program again type 'y' else type 'n' ";
		cin >> choice;
		if (choice != 'y' || choice != 'n')
		{
			cout << "enter a valid response";
		}
	}


	
}

int main()
{
	runagain();
	return 0;
}
