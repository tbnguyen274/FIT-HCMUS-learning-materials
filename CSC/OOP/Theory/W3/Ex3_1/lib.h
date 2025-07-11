#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Fraction {
private:
	int numerator;
	int denominator;

public:
	Fraction();
	Fraction(int num, int denom);
	Fraction(int value);
	Fraction(const char* s);
	Fraction(const Fraction& f);
	~Fraction();
	void print();
};

#endif