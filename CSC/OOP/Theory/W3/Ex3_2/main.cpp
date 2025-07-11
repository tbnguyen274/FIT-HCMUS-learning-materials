#include "lib.h"

int Fraction::count = 0;

int main() {
	Fraction f1;
	f1.print();

	Fraction f2(3, 4);
	f2.print();

	Fraction f3(5);
	f3.print();

	Fraction::printCount();

	Fraction f4("7/8");
	f4.print();

	Fraction f5(f2);
	f5.print();

	f1.printCount();

	return 0;
}