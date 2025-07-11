#include "utils.h"

int main() {

	cout << "0. Exit" << endl;
    cout << "1. Read binary of an integer" << endl;
    cout << "2. Convert binary array to integer" << endl;
    cout << endl;

    int choice;
    cout << "Enter your choice: ";

    do {
        cin >> choice;
        if (choice < 0 || choice > 2) {
            cout << "Invalid choice! Please enter again: ";
        }
    } while (choice < 0 || choice > 2);

	cout << endl;

	while (choice != 0) {
        switch (choice) {
        case 1:
            int n;
            cout << "Enter an integer: ";
            cin >> n;
			cout << "Bit array: ";
            readBitFromInt(n);
            break;

        case 2:
            string bitArray;
            cout << "Enter 32-bit array as a string: ";
            cin.ignore();
            getline(cin, bitArray);

            // Normalize bit string
            normalizeBitString(bitArray);

			// Check number of bits
            if (bitArray.length() != 32) {
				cout << "Invalid input! Please enter 32 bits." << endl;
				break;
            }

            vector<bool> bitArrayVector = convertBitStringToArray(bitArray);
            int result = convertBitArrayToInt(bitArrayVector);

			cout << "Integer: " << result << endl;
            break;

        }

		cout << "\nEnter your choice: ";
		cin >> choice;
		cout << endl;
	}

	cout << "Exited!" << endl;

    return 0;
}