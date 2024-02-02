#include "header.h"

using namespace std;

int main(){
	Person Okey, Ken;

	Okey = FillPerson();
	cout << "Enter details for the second person\n";
	Ken = FillPerson();
	
	WhoIsOlder(Okey, Ken);

	system("pause");
	return 0;
};
