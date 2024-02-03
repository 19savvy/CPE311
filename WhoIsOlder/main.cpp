#include "header.h"

using namespace std;

int main(){
	Person Luffy, Zoro;

	Luffy = FillPerson();
	cout << "Enter details for the second person\n";
	Zoro = FillPerson();
	
	WhoIsOlder(Luffy, Zoro);

	system("pause");
	return (0);
};
