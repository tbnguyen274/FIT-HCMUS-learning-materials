#include "lib.h"

void Fraction::input() {
	cout << "Enter the numerator: ";
	cin >> this->numerator;
	cout << "Enter the denominator: ";

	do {
		cin >> this->denominator;
		if (this->denominator == 0) {
			cout << "Denominator cannot be zero." << endl;
			cout << "Re-enter the denominator: ";
		}
	} while (this->denominator == 0);

	if (this->denominator < 0) {
		this->numerator *= -1;
		this->denominator *= -1;
	}
}

void Fraction::output() {
	if (this->denominator == 1) {
		cout << this->numerator << endl;
	}
	else if (this->numerator == 0) {
		cout << 0 << endl;
	}
	else {
		cout << this->numerator << "/" << this->denominator << endl;
	}
}

int Fraction::getNum() {
	return this->numerator;
}

void Fraction::setNum(int numerator) {
	this->numerator = numerator;
}

int Fraction::getDenom() {
	return this->denominator;
}

void Fraction::setDenom(int denominator) {
	if (denominator == 0) {
		cout << "Denominator cannot be zero." << endl;
		return;
	}
	this->denominator = denominator;
}

int Fraction::GCD() {
	int a = abs(this->numerator);
	int b = abs(this->denominator);

	while (b != 0) {
		int remainder = a % b;
		a = b;
		b = remainder;
	}

	return a;
}

Fraction Fraction::reduce() {
	Fraction f;

	int gcd = this->GCD();
	f.numerator = this->numerator / gcd;
	f.denominator = this->denominator / gcd;

	return f;
}

Fraction Fraction::inverse() {
	Fraction f;

	if (this->numerator == 0) {
		cout << "Cannot find the inverse of 0." << endl;

		f.numerator = 0;
		f.denominator = 1;

		return f;
	}

	f.numerator = this->denominator;
	f.denominator = this->numerator;

	if (f.denominator < 0) {
		f.numerator *= -1;
		f.denominator *= -1;
	}

	return f;
}

Fraction Fraction::add(Fraction f) {
	Fraction result;

	result.numerator = this->numerator * f.denominator + f.numerator * this->denominator;
	result.denominator = this->denominator * f.denominator;
	result = result.reduce();

	return result;
}

int Fraction::compare(Fraction f) {
	Fraction f1 = this->reduce();
	Fraction f2 = f.reduce();

	int diff = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
	
	if (diff > 0) {
		return 1;
	}
	else if (diff < 0) {
		return -1;
	}
	else {
		return 0;
	}
}