#ifndef LIB_H
#define LIB_H

#include <iostream>

using namespace std;

class Fraction {
private:
	int num;
	int denom;
	static int GCD(int a, int b);

public:
	// Constructors
	Fraction();
	Fraction(int _num, int _denom);
	Fraction(const Fraction& frac);

	// Operator overloads
	// Arithmetic
	Fraction operator+(const Fraction& frac);
	Fraction operator+(const int& a);
	Fraction operator-(const Fraction& frac);
	Fraction operator-(const int& a);
	Fraction operator*(const Fraction& frac);
	Fraction operator*(const int& a);
	Fraction operator/(const Fraction& frac);
	Fraction operator/(const int& a);

	// Comparation
	bool operator>(const Fraction& frac);
	bool operator>(const int& a);
	bool operator<(const Fraction& frac);
	bool operator<(const int& a);
	bool operator==(const Fraction& frac);
	bool operator==(const int& a);
	bool operator>=(const Fraction& frac);
	bool operator>=(const int& a);
	bool operator<=(const Fraction& frac);
	bool operator<=(const int& a);
	bool operator!=(const Fraction& frac);
	bool operator!=(const int& a);

	// Assignment
	Fraction& operator=(const Fraction& frac);
	Fraction& operator=(const int& a);
	Fraction& operator+=(const Fraction& frac);
	Fraction& operator+=(const int& a);
	Fraction& operator*=(const Fraction& frac);
	Fraction& operator*=(const int& a);

	// Increment and decrement
	Fraction& operator++();	// pre-increment
	Fraction operator++(int); // post-increment
	Fraction& operator--();	// pre-decrement
	Fraction operator--(int); // post-decrement

	// Type cast
	operator float() const;
	operator int() const;

	// I/O
	friend istream& operator>>(istream& is, Fraction& frac);
	friend ostream& operator<<(ostream& os, const Fraction& frac);

	// Destructor
	~Fraction();

	void reduce();
};

#endif