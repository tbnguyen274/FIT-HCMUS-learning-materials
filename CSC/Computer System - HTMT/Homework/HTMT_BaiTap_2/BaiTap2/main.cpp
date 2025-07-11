#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

void forceFloat(float* p, char* s) {
	unsigned int sign = 0;
	unsigned int exponent = 0;
	unsigned int significand = 0;
	int n = strlen(s);

	for (int i = 0; i < n; i++) {
		unsigned int bit = s[i] - '0';

		// Bit 0: sign bit
		if (i == 0) {
			sign = bit;
		}

		// Bits 1-8: exponent
		else if (i >= 1 && i <= 8) {
			exponent = (exponent << 1) | bit;
		}

		// Bits 9-31: significand
		else {
			significand = (significand << 1) | bit;
		}
	}

	unsigned int* pInt = (unsigned int*)p;
	*pInt = (sign << 31) | (exponent << 23) | significand;
}

void trimSpaces(char* s) {
	int n = strlen(s);
	int j = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] != ' ') {
			s[j++] = s[i];
		}
	}

	s[j] = '\0';
}

int main() {
	float f;
	char* s = new char[100];

	cout << "Type 'q' to quit.\n\n";

	while (true) {
		cout << "Enter binary representation of a floating-point number (32 bits): ";
		cin.getline(s, 50);
		trimSpaces(s);

		if (strcmp(s, "q") == 0) {
			break;
		}

		forceFloat(&f, s);
		cout << "(Single) floating-point number: " << f << endl << endl;
	}

	delete[] s;
	return 0;
}