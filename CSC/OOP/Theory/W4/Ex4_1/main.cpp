#include "lib.h"

int main() {
    // Constructors
    Fraction f1;
    Fraction f2(3, 4);
    Fraction f3(f2);

    cout << "Fraction f1 (default): " << f1 << endl;
    cout << "Fraction f2 (3/4): " << f2 << endl;
    cout << "Fraction f3 (copy of f2): " << f3 << endl;

    // Arithmetic
    Fraction f4 = f2 + Fraction(1, 2);
    Fraction f5 = f2 - Fraction(1, 4);
    Fraction f6 = f2 * Fraction(2, 3);
    Fraction f7 = f2 / Fraction(3, 2);

    cout << "f2 + 1/2 = " << f4 << endl;
    cout << "f2 - 1/4 = " << f5 << endl;
    cout << "f2 * 2/3 = " << f6 << endl;
    cout << "f2 / 3/2 = " << f7 << endl;

    // Comparation
    cout << "f2 > f3: " << (f2 > f3) << endl;
    cout << "f2 < f3: " << (f2 < f3) << endl;
    cout << "f2 == f3: " << (f2 == f3) << endl;

	// Assignment
    f1 = f2;
    cout << "After assignment, f1 = " << f1 << endl;

    f1 += Fraction(1, 4);
    cout << "After += 1/4, f1 = " << f1 << endl;

    f1 *= Fraction(3, 2);
    cout << "After *= 3/2, f1 = " << f1 << endl;

    // Increment and decrement
    cout << "Pre-increment ++f1: " << ++f1 << endl;
    cout << "Post-increment f1++: " << f1++ << endl;
    cout << "After post-increment, f1 = " << f1 << endl;

    cout << "Pre-decrement --f1: " << --f1 << endl;
    cout << "Post-decrement f1--: " << f1-- << endl;
    cout << "After post-decrement, f1 = " << f1 << endl;

	// Type cast
	cout << "Float conversion of f2: " << (float)f2 << endl;
	cout << "Integer conversion of f2: " << (int)f2 << endl;

	// I/O
    Fraction f8;
    cout << "Enter a fraction (strict format: numerator/denominator): ";
    cin >> f8;
    cout << "You entered: " << f8 << endl;

    return 0;
}