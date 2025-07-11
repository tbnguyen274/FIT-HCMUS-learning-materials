#include "utils.h"

int main() {

    // INPUT
    string bitString1, bitString2;
    cout << "Enter BIT ARRAY 1 as a string of 8 bits: ";
    getline(cin, bitString1);
    cout << "Enter BIT ARRAY 2 as a string of 8 bits: ";
    getline(cin, bitString2);

    // NORMALIZE BIT STRING
    normalizeBitString(bitString1);
    normalizeBitString(bitString2);
    cout << endl;

	// CHECK NUMBER OF BITS
	if (bitString1.length() != BIT_LENGTH || bitString2.length() != BIT_LENGTH) {
		cout << "Invalid input! Please enter 8 bits for each bit array." << endl;
		return 1;
	}

    // CONVERT BIT STRING TO ARRAY
    vector<bool> bitArray1 = convertBitStringToArray(bitString1);
    vector<bool> bitArray2 = convertBitStringToArray(bitString2);

    // OUTPUT AS INTEGER
    cout << "Bit array 1 (int): " << convertBitArrayToInt(bitArray1) << endl;
    cout << "Bit array 2 (int): " << convertBitArrayToInt(bitArray2) << endl;
    cout << endl;


    // ADDITION
    cout << setw(20) << setfill('=') << "" << endl;
    cout << "ADDITION" << endl;
    cout << setw(20) << setfill('=') << "" << endl;

    vector<bool> sum;
    bool addition = addBitArray(bitArray1, bitArray2, sum);

    cout << "Sum (bit): ";
    printBitArray(sum);

    cout << "Sum (int): " << convertBitArrayToInt(sum) << endl;

    if (!addition) {
        cout << "Overflow in addition!" << endl;
    }

    cout << endl;


    // SUBTRACTION
    cout << setw(20) << setfill('=') << "" << endl;
    cout << "SUBTRACTION" << endl;
    cout << setw(20) << setfill('=') << "" << endl;

    vector<bool> diff;
    bool subtraction = subtractBitArray(bitArray1, bitArray2, diff);

    cout << "Difference (bit): ";
    printBitArray(diff);

    cout << "Difference (int): " << convertBitArrayToInt(diff) << endl;

    if (!subtraction) {
        cout << "Overflow in subtraction!" << endl;
    }

    cout << endl;
    

    // MULTIPLICATION
    cout << setw(20) << setfill('=') << "" << endl;
    cout << "MULTIPLICATION" << endl;
    cout << setw(20) << setfill('=') << "" << endl;

    vector<bool> multiplication = multiplyBitArray(bitArray1, bitArray2);

    cout << "Multiplication (bit): ";
    printBitArray(multiplication);

    cout << "Multiplication (int): " << convertBitArrayToInt(multiplication) << endl << endl;


    // DIVISION
    cout << setw(20) << setfill('=') << "" << endl;
    cout << "DIVISION" << endl;
    cout << setw(20) << setfill('=') << "" << endl;

    vector<vector<bool>> division = divideBitArray(bitArray1, bitArray2);

    cout << "Quotient (bit): ";
    printBitArray(division[0]);

    cout << "Quotient (int): " << convertBitArrayToInt(division[0]) << endl;

    cout << "Remainder (bit): ";
    printBitArray(division[1]);

    cout << "Remainder (int): " << convertBitArrayToInt(division[1]) << endl;

    return 0;
}