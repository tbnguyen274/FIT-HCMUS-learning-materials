#include <iostream>
#include <bitset>

using namespace std;

void dumpFloat(float* p) {
    unsigned int* pInt = (unsigned int*)p;

    unsigned int sign = (*pInt >> 31) & 1;

	// 0xFF = 1111 1111 --> 8 bits
	int EightBits = 0xFF;
	unsigned int exponent = (*pInt >> 23) & EightBits;

	// 0x7FFFFF = 1111 1111 1111 1111 1111 111 --> 23 bits
	int TwentyThreeBits = 0x7FFFFF;
	unsigned int significand = *pInt & TwentyThreeBits;

    cout << sign << " " << bitset<8>(exponent) << " " << bitset<23>(significand) << endl;
}

int main() {
	cout << "Type 'q' to quit.\n\n";

	while (true) {
		float f;
		cout << "Enter a float number: ";
		cin >> f;
		if (cin.fail()) {
			break;
		}

		dumpFloat(&f);
		cout << endl;
	}

    return 0;
}