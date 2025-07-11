#include "lib.h"

Fraction::Fraction() {
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(int num, int denom) {
	numerator = num;
	denominator = denom;
}

Fraction::Fraction(int value) {
	numerator = value;
	denominator = 1;
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
}

Fraction::Fraction(const Fraction& f) {
	numerator = f.numerator;
	denominator = f.denominator;
}

Fraction::~Fraction() {

}

void Fraction::print() {
	cout << numerator << "/" << denominator << endl;
}