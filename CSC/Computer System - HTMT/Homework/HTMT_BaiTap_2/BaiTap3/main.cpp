#include <iostream>
#include <bitset>
#include <cmath>
#include <cstring>

using namespace std;

void dumpFloat(float* p) {
	unsigned int* pInt = (unsigned int*)p;

	unsigned int sign = (*pInt >> 31) & 1;

	// 0xFF = 1111 1111 --> 8 bits
	int EightBits = 0xFF;
	unsigned int exponent = (*pInt >> 23) & EightBits;

	// 0x7FFFFF = 1111 1111 1111 1111 1111 111 --> 23 bits
	int TwentyThreeBits = 0x7FFFFF;
	unsigned int fraction = *pInt & TwentyThreeBits;

	cout << sign << " " << bitset<8>(exponent) << " " << bitset<23>(fraction) << endl;
}

void forceFloat(float* p, char* s) {
	unsigned int sign = 0;
	unsigned int exponent = 0;
	unsigned int fraction = 0;
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
			fraction = (fraction << 1) | bit;
		}
	}

	unsigned int* pInt = (unsigned int*)p;
	*pInt = (sign << 31) | (exponent << 23) | fraction;
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
	float f = (float) 1.3E+20;
	cout << "Binary representation of 1.3E+20: ";
	dumpFloat(&f);
	cout << endl;

	cout << "The smallest float number that is greater than 0 is: 1.4013E-45\n";
	cout << "Its binary representation: ";
	f = (float) 1.4013E-45;
	dumpFloat(&f);
	cout << endl;

	cout << "--- Special float numbers ---\n\n";

	cout << "Positive infinity: ";
	f = INFINITY;
	dumpFloat(&f);

	cout << "Negative infinity: ";
	f = -INFINITY;
	dumpFloat(&f);
	
	cout << "Positive NaN: ";
	f = NAN;
	dumpFloat(&f);

	cout << "Negative NaN: ";
	f = -NAN;
	dumpFloat(&f);

	cout << "X - Positive infinity: ";
	float result = 2.0f - INFINITY;
	dumpFloat(&result);

	cout << "Positive infinity - Positive infinity: ";
	result = INFINITY - INFINITY;
	dumpFloat(&result);

	cout << "X / 0: ";
	float zero = 0.0f;
	result = 2.0f / zero;
	dumpFloat(&result);

	cout << "0 / 0: ";
	result = zero / zero;
	dumpFloat(&result);

	cout << "Infinity / Infinity: ";
	result = INFINITY / INFINITY;
	dumpFloat(&result);

	cout << "Sqrt(X) where X < 0: ";
	result = sqrt(-1.0f);
	dumpFloat(&result);

	return 0;
}