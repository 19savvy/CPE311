#include <iostream>
using namespace std;

void DataInput(char* name, float& basic_salary, float& allowance, float& tax) {
    cout << "Enter name: ";
    cin.getline(name, 100);

    cout << "Enter basic salary: $";
    cin >> basic_salary;

    cout << "Enter allowance: $";
    cin >> allowance;

    tax = 0.1 * basic_salary;
}

float CalcPay(float basic_salary, float allowance, float tax) {
    float gross_pay = basic_salary + allowance;
    float net_pay = gross_pay - tax;
    return net_pay;
}

void DisplayPay(const char* name, float basic_salary, float allowance, float tax, float net_pay) {
    cout << "\nStaff Details:\n";
    cout << "Name: " << name << endl;
    cout << "Basic Salary: $" << basic_salary << endl;
    cout << "Allowance: $" << allowance << endl;
    cout << "Tax Amount: $" << tax << endl;
    cout << "Gross Pay: $" << basic_salary + allowance << endl;
    cout << "Net Pay: $" << net_pay << endl;
}

int main() {
    char name[100];
    float basic_salary, allowance, tax, net_pay;

    DataInput(name, basic_salary, allowance, tax);
    net_pay = CalcPay(basic_salary, allowance, tax);
    DisplayPay(name, basic_salary, allowance, tax, net_pay);
	system("pause");

    return 0;
}
