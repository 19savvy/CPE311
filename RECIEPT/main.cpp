#include "Header.h"

using namespace std;

void FillShoppingInfo(Person* personptr)
{
	cout << "Enter shop name: ";
	cin.getline(personptr->shopInfo.ShopName, sizeof(personptr->shopInfo.ShopName));
	cout << "Enter shop address: ";
	cin.getline(personptr->shopInfo.Address, sizeof(personptr->shopInfo.Address));
	cout << "Enter customer name: ";
	cin.getline(personptr->customerInfo.CustomerName, sizeof(personptr->customerInfo.CustomerName));
	cout << "Enter customer phone number: ";
	cin.getline(personptr->customerInfo.PhoneNumber, sizeof(personptr->customerInfo.PhoneNumber));
	cout << "Enter product name: ";
	cin.getline(personptr->productInfo.ProductName, sizeof(personptr->productInfo.ProductName));
	cout << "Enter unit price: ";
	cin >> personptr->productInfo.UnitPrice;
	cin.ignore();
	cout << "Enter quantity: ";
	cin >> personptr->productInfo.Quantity;
	personptr->productInfo.TotalPrice = personptr->productInfo.UnitPrice * personptr->productInfo.Quantity;


}
void WriteReceipt (Person* person)
{
	ofstream outputFile("reciept.txt");
	if (outputFile.is_open()) {
		outputFile << "******************************************************\n"; 
        outputFile << left << setw(20) <<"   " << setw(15) << person->shopInfo.ShopName << setw(15) << "     \n";
        outputFile << left << setw(10) <<"   " << setw(30) << person->shopInfo.Address << setw(10) << "     \n";
        outputFile << left << setw(20) <<"Customer" << setw(20) << person->customerInfo.CustomerName << setw(10) << "    \n";
        outputFile << "Phone Number       " << person->customerInfo.PhoneNumber <<
			"\n";
		outputFile << "Your Order \n";
		outputFile << left << setw(20) << "Product Name" << setw(15) << "Unit Price" << setw(15) << "Quantity Ordered\n";
        outputFile << left << setw(20) << person->productInfo.ProductName << setw(15)  << person->productInfo.UnitPrice << setw(15) << person->productInfo.Quantity << endl;
        outputFile << "       Total Price " << person->productInfo.TotalPrice << "\n";
		outputFile << left << setw(20) << "       " << setw(25) << "Thanks for your patronage\n";
		outputFile << "******************************************************\n"; 

        std::cout << "Receipt has been written to 'receipt.txt'\n";

        outputFile.close();
    } else {
        cerr << "Unable to open the file.\n";
    }
}

int main(void)
{
	Person myPerson;
	FillShoppingInfo(&myPerson);
	WriteReceipt(&myPerson);
	
	system("pause");
	return 0;
}

