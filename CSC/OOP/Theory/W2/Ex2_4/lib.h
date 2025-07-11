#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <cmath>
using namespace std;

class Fraction {
private:
	int numerator;
	int denominator;

public:
	void input();
	void output();
	int getNum();
	void setNum(int numerator);
	int getDenom();
	void setDenom(int denominator);
	int GCD();
	Fraction reduce();
	Fraction inverse();
	Fraction add(Fraction f);
	int compare(Fraction f);
};

#endif // !LIB_H
