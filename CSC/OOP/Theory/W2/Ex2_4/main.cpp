#include "lib.h"

int main() {
	Fraction f1, f2, res;

	f1.input();
	f1.output();
	f2.input();
	f2.output();
	cout << endl;

	int num1 = f1.getNum();
	int denom2 = f2.getDenom();
	cout << "Sum of f1's numerator and f2's denominator: " << num1 + denom2 << endl << endl;

	f1.setNum(10);
	f1.setDenom(8);
	cout << "Set f1 to 10/8\n";
	f1 = f1.reduce();
	cout << "Reduced f1: ";
	f1.output();

	f2 = f2.inverse();
	cout << "Inverse f2: ";
	f2.output();

	res = f1.add(f2);
	cout << "Sum of f1 and f2: ";
	res.output();

	int comp = f1.compare(f2);
	if (comp == 1) {
		cout << "f1 is greater than f2." << endl;
	}
	else if (comp == -1) {
		cout << "f1 is less than f2." << endl;
	}
	else {
		cout << "f1 is equal to f2." << endl;
	}

	return 0;
}