#include <iostream>
#include <cstring>

using namespace std;

void Reverselt(char* input, char* output) {
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        output[i] = input[length - i - 1];
    }
    output[length] = '\0';
}

int main() {
    const int maxSize = 51;
    char inputString[maxSize];
    char reversedString[maxSize];
    char choice;

    while(1) {
        cout << "Enter a string (up to 50 characters): ";
        cin.getline(inputString, maxSize);
        Reverselt(inputString, reversedString);
        cout << "Reversed string: " << reversedString << std::endl;
        cout << "Do you want to enter another string? (Y/N): ";
        cin >> choice;
		cin.ignore(maxSize, '\n');
		if (!(choice == 'Y' || choice == 'y'))
			break;

    }//while (choice == 'Y' || choice == 'y');

    return 0;

}
