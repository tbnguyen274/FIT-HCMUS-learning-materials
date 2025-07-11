#include "lib.h"

Fraction::Fraction() {
	numerator = 0;
	denominator = 1;
	count++;
}

Fraction::Fraction(int num, int denom) {
	numerator = num;
	denominator = denom;
	count++;
}

Fraction::Fraction(int value) {
	numerator = value;
	denominator = 1;
	count++;
}

Fraction::Fraction(const char* s) {
	char* sTemp = new char[strlen(s) + 1];
	strcpy_s(sTemp, strlen(s) + 1, s);

	const char* delim = "/";
	char* token = nullptr;

	char* sCur = strtok_s(sTemp, delim, &token);
	numerator = atoi(sCur);

	sCur = strtok_s(nullptr, delim, &token);
	denominator = atoi(sCur);

	delete[] sTemp;

	count++;
}

Fraction::Fraction(const Fraction& f) {
	numerator = f.numerator;
	denominator = f.denominator;

	count++;
}

Fraction::~Fraction() {
	count--;
}

void Fraction::print() {
	cout << numerator << "/" << denominator << endl;
}

void Fraction::printCount() {
	cout << "Number of fraction objects: " << count << endl;
}