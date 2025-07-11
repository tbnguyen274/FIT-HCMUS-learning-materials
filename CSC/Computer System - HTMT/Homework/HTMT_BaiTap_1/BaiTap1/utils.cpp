#include "utils.h"

// Convert integer to binary string
string convertIntToBitString(int n) {
    string result = "";

    for (int i = 31; i >= 0; i--) {
        int bit = (n >> i) & 1;
        result += to_string(bit);
    }

    return result;
}

vector<bool> convertIntToBitArray(int n) {
    vector<bool> result;

    for (int i = 31; i >= 0; i--) {
        bool bit = (n >> i) & 1;
        result.push_back(bit);
    }

    return result;
}

vector<bool> convertBitStringToArray(string bitString) {
    vector<bool> result;

    for (int i = 0; i < bitString.length(); i++) {
        result.push_back(bitString[i] - '0');
    }

    return result;
}

int convertBitArrayToInt(vector<bool> arr) {
    int result = 0;

    for (int i = 0; i < arr.size(); i++) {
        result = (result << 1) | arr[i];
    }
    return result;
}

void printBitArray(vector<bool> arr) {
    cout << "Bit array: ";

    for (int i = 0; i < arr.size(); i++) {
        if (i % 8 == 0 && i != 0) {
            cout << " ";
        }
        cout << arr[i];
    }
}

void readBitFromInt(int n) {
    for (int i = 31; i >= 0; i--) {
        int bit = (n >> i) & 1;
        cout << bit;

        if (i % 8 == 0) {
            cout << " ";
        }
    }
    cout << endl;
}

void normalizeBitString(string& bitArray) {
    int n = bitArray.length();

    // remove spaces
    for (int i = 0; i < n; i++) {
        if (bitArray[i] == ' ') {
            bitArray.erase(i, 1);
            n--;
            i--;
        }
    }
}