#include "utils.h"

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

vector<bool> convertBitStringToArray(string bitString) {
    vector<bool> result;

    for (int i = 0; i < bitString.length(); i++) {
        result.push_back(bitString[i] - '0');
    }

    return result;
}

string convertBitArrayToString(vector<bool> bitArray) {
    string result = "";

    for (int i = 0; i < bitArray.size(); i++) {
        result += to_string(bitArray[i]);
    }

    return result;
}


int convertBitArrayToInt(vector<bool> arr) {
    int result = 0, n = arr.size();

    for (int i = 0; i < n; i++) {
        result = (result << 1) | arr[i];
    }

    int intSize = sizeof(int) * 8;

    if (arr[0] == 1 && n < intSize) {
        result -= (1 << n);
    }

    return result;
}

bool isIdentical(vector<bool> bitString1, vector<bool> bitString2) {
    if (bitString1.size() != bitString2.size()) {
        return false;
    }

    for (int i = 0; i < bitString1.size(); i++) {
        if (bitString1[i] != bitString2[i]) {
            return false;
        }
    }

    return true;
}

/*
    Overflow if:
    - two positive numbers add up to a negative number
    - two negative numbers add up to a positive number
*/
bool checkOverflow(vector<bool> bitString1, vector<bool> bitString2, vector<bool> result) {
    return (bitString1[0] == bitString2[0] && bitString1[0] != result[0]);
}

bool addBitArray(vector<bool> bitString1, vector<bool> bitString2, vector<bool>& result) {
    int n = bitString1.size();

    if (n != bitString2.size()) {
		result = ZERO;
        return false;
    }

    result.resize(n, 0);
    bool carry = 0;

    for (int i = bitString1.size() - 1; i >= 0; i--) {
        int sum = bitString1[i] + bitString2[i] + carry;
        result[i] = sum % 2;
        carry = sum / 2;
    }

    return !checkOverflow(bitString1, bitString2, result);
}

vector<bool> calcTwoComplement(vector<bool> bitArray) {
    int n = bitArray.size();
    vector<bool> result(n, 0);

    // A = ~A + 1
    for (int i = 0; i < n; i++) {
        result[i] = 1 - bitArray[i];
    }

    vector<bool> one(n, 0);
    one[n - 1] = 1;
    addBitArray(result, one, result);

    return result;
}

bool subtractBitArray(vector<bool> bitString1, vector<bool> bitString2, vector<bool>& result) {
    // Case: A - A = 0
    if (isIdentical(bitString1, bitString2)) {
		result = ZERO;
        return true;
    }

    // Manage overflow with -128
	if (isPositive(bitString1) && bitString2 == MINUS_128) {
        // postive - (-128) = positive + 128 --> overflow
        addBitArray(bitString1, calcTwoComplement(bitString2), result);
        return false;
    }

    return addBitArray(bitString1, calcTwoComplement(bitString2), result);
}

void printBitArray(vector<bool> arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (i % 8 == 0 && i != 0) {
            cout << " ";
        }
        cout << arr[i];
    }
    cout << endl;
}

bool isSameSign(vector<bool> bitString1, vector<bool> bitString2) {
    return bitString1[0] == bitString2[0];
}

// Multiplication

/*
Khởi tạo: A = 0; k = n; Q-1 = 0 (thêm 1 bit = 0 vào cuối Q)
Lặp khi k > 0
{
    Nếu 2 bit cuối của Q0Q-1
    {
        = 10 thì A – M à A
        = 01 thì A + M à A
        = 00, 11 thì A không thay đổi
    }

    Shift right [A, Q, Q-1]
    k = k – 1
}
Kết quả: [A, Q]
*/

vector<bool> multiplyBitArray(vector<bool> bitString1, vector<bool> bitString2) {
    int k = BIT_LENGTH;
    vector<bool> A(BIT_LENGTH, 0);
    vector<bool> M = bitString1;
    vector<bool> Q = bitString2;

    // if M = -128, swap M and Q for more convenient calculation
	if (M == MINUS_128) {
        M = bitString2;
        Q = bitString1;
    }

    // Add Q_1 = 0 to the end of Q
    bool Q_1 = 0;
    Q.push_back(Q_1);

    while (k > 0) {
        cout << "Step " << BIT_LENGTH - k + 1 << endl;

        string Q1_Q0 = to_string(Q[Q.size() - 2]) + to_string(Q[Q.size() - 1]);

        if (Q1_Q0 == "10") {
            subtractBitArray(A, M, A);
            cout << "A = A - M" << endl;
        }
        else if (Q1_Q0 == "01") {
            addBitArray(A, M, A);
            cout << "A = A + M" << endl;
        }

        // Shift right  
        Q_1 = Q[Q.size() - 1];
        Q.pop_back();
        int lastBitOfA = A[A.size() - 1];
        Q.insert(Q.begin(), lastBitOfA);

        A.pop_back();
        int firstBitOfA = (A[0] == 1) ? 1 : 0;
        A.insert(A.begin(), firstBitOfA);
        cout << "Shift right" << endl;

        // Display
        cout << setw(7) << setfill(' ') << "A: ";
        printBitArray(A);
        cout << setw(7) << "Q Q_1: ";
        printBitArray(Q);
        cout << "\n-------" << endl;

        k--;
    }

    // Result is [A, Q]
    vector<bool> result = A;
    Q.pop_back(); // Remove Q_1

    for (int i = 0; i < Q.size(); i++) {
        result.push_back(Q[i]);
    }

    // Double check
    if ((isSameSign(bitString1, bitString2) && isNegative(result)) ||   // Case: Pos * Pos = Neg, Neg * Neg = Neg
        (!isSameSign(bitString1, bitString2) && isPositive(result))) {  // Case: Pos * Neg = Pos, Neg * Pos = Pos

        // Reverse the result
        result = calcTwoComplement(result);
    }

    return result;
}

// Division
vector<vector<bool>> divideBitArray(vector<bool> dividend, vector<bool> divisor) {
    if (divisor == ZERO) {
        cout << "Cannot divide by zero!" << endl;
        return { ZERO, ZERO };
    }

    int k = dividend.size();
    vector<bool> Q = dividend;
	vector<bool> M = divisor;

	// Convert to positive
	if (isNegative(Q)) {
		Q = calcTwoComplement(Q);
	}

	if (isNegative(M)) {
		M = calcTwoComplement(M);
	}

	vector<bool> A(k, (isNegative(Q) ? 1 : 0));
	
    while (k > 0) {
        cout << "Step " << dividend.size() - k + 1 << endl;

        // Shift left
        A.erase(A.begin());
        A.push_back(Q[0]);
        Q.erase(Q.begin());
        Q.push_back(0);
        cout << "Shift left" << endl;

		// A = A - M
		subtractBitArray(A, M, A);
		cout << "A = A - M" << endl;
        
		// Restore A or set Q0
        if (A[0] == 1) {
            Q[Q.size() - 1] = 0;
			addBitArray(A, M, A);
            cout << "Restore A" << endl;
        }
        else {
            Q[Q.size() - 1] = 1;
            cout << "Set Q0 = 1" << endl;
        }

        // Display
        cout << "A: ";
        printBitArray(A);
        cout << "Q: ";
        printBitArray(Q);
        cout << "\n-------" << endl;

        k--;
    }

	// Manage sign
    if (!isSameSign(dividend, divisor)) {
        Q = calcTwoComplement(Q);
    }

	if (isNegative(dividend)) {
		A = calcTwoComplement(A);
	}

    // Q is quotient, A is remainder
    return { Q, A };
}

bool isPositive(vector<bool> bitString) {
	return bitString[0] == 0;
}

bool isNegative(vector<bool> bitString) {
	return bitString[0] == 1;
}