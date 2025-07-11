#include "lib.h"

// Constructors
Fraction::Fraction() {
	num = 0;
	denom = 1;
}

Fraction::Fraction(int _num, int _denom) {
	num = _num;
	denom = _denom;
}

Fraction::Fraction(const Fraction& frac) {
	num = frac.num;
	denom = frac.denom;
}

int Fraction::GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}

void Fraction::reduce() {
	int gcd = GCD(num, denom);
	num /= gcd;
	denom /= gcd;
}

// Operator overloads
// Arithmetic
Fraction Fraction::operator+(const Fraction& frac) {
	int resNum = this->num * frac.denom + frac.num * this->denom;
	int resDenom = this->denom * frac.denom;
	Fraction res(resNum, resDenom);
	res.reduce();
	return res;
}

Fraction Fraction::operator+(const int& a) {
	int resNum = this->num + this->denom * a;
	Fraction res(resNum, this->denom);
	res.reduce();
	return res;
}

Fraction Fraction::operator-(const Fraction& frac) {
	int resNum = this->num * frac.denom - frac.num * this->denom;
	int resDenom = this->denom * frac.denom;
	Fraction res(resNum, resDenom);
	res.reduce();
	return res;
}

Fraction Fraction::operator-(const int& a) {
	int resNum = this->num - this->denom * a;
	Fraction res(resNum, this->denom);
	res.reduce();
	return res;
}

Fraction Fraction::operator*(const Fraction& frac) {
	int resNum = this->num * frac.num;
	int resDenom = this->denom * frac.denom;
	Fraction res(resNum, resDenom);
	res.reduce();
	return res;
}

Fraction Fraction::operator*(const int& a) {
	int resNum = this->num * a;
	Fraction res(resNum, this->denom);
	res.reduce();
	return res;
}

Fraction Fraction::operator/(const Fraction& frac) {
	int resNum = this->num * frac.denom;
	int resDenom = this->denom * frac.num;
	Fraction res(resNum, resDenom);
	res.reduce();
	return res;
}

Fraction Fraction::operator/(const int& a) {
	int resDenom = this->denom * a;
	Fraction res(this->num, resDenom);
	res.reduce();
	return res;
}

// Comparation
bool Fraction::operator>(const Fraction& frac) {
	return this->num * frac.denom > frac.num * this->denom;
}

bool Fraction::operator>(const int& a) {
	return this->num > a * this->denom;
}

bool Fraction::operator<(const Fraction& frac) {
	return this->num * frac.denom < frac.num * this->denom;
}

bool Fraction::operator<(const int& a) {
	return this->num < a * this->denom;
}

bool Fraction::operator==(const Fraction& frac) {
	return this->num * frac.denom == this->denom * frac.num;
}

bool Fraction::operator==(const int& a) {
	return this->num == a * this->denom;
}

bool Fraction::operator>=(const Fraction& frac) {
	return *this > frac || *this == frac;
}

bool Fraction::operator>=(const int& a) {
	return *this > a || *this == a;
}

bool Fraction::operator<=(const Fraction& frac) {
	return *this < frac || *this == frac;
}

bool Fraction::operator<=(const int& a) {
	return *this < a || *this == a;
}

bool Fraction::operator!=(const Fraction& frac) {
	return !(*this == frac);
}

bool Fraction::operator!=(const int& a) {
	return !(*this == a);
}

// Assignment
Fraction& Fraction::operator=(const Fraction& frac) {
	num = frac.num;
	denom = frac.denom;
	return *this;
}

Fraction& Fraction::operator=(const int& a) {
	num = a;
	denom = 1;
	return *this;
}

Fraction& Fraction::operator+=(const Fraction& frac) {
	*this = *this + frac;
	reduce();
	return *this;
}

Fraction& Fraction::operator+=(const int& a) {
	*this = *this + a;
	reduce();
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& frac) {
	*this = *this * frac;
	reduce();
	return *this;
}

Fraction& Fraction::operator*=(const int& a) {
	*this = *this * a;
	reduce();
	return *this;
}

// Increment and decrement
Fraction& Fraction::operator++() {
	num += denom;
	reduce();
	return *this;
}

Fraction Fraction::operator++(int) {
	Fraction temp = *this;
	num += denom;
	reduce();
	return temp;
}

Fraction& Fraction::operator--() {
	num -= denom;
	reduce();
	return *this;
}

Fraction Fraction::operator--(int) {
	Fraction temp = *this;
	num -= denom;
	reduce();
	return temp;
}

// Type cast
Fraction::operator float() const {
	return (float) num / denom;
}

Fraction::operator int() const {
	return num / denom;
}

// I/O
istream& operator>>(istream& is, Fraction& frac) {
	is >> frac.num;
	is.ignore(1);	// Ignore '/'
	is >> frac.denom;
	frac.reduce();

	return is;
}

ostream& operator<<(ostream& os, const Fraction& frac) {
	os << frac.num << "/" << frac.denom;
	return os;
}

// Destructor
Fraction::~Fraction() {

}