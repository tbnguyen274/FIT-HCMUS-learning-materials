#include <iostream>
#include <cstdio>

using namespace std;

// Check convert float -> int -> float
bool isSameFloat(float f) {
	int i = (int)f;
	float f2 = (float)i;
	return f == f2;
}

// Check convert int -> float -> int
bool isSameInt(int i) {
	float f = (float)i;
	int i2 = (int)f;
	return i == i2;
}

// Check if (x + y) + z == x + (y + z)
bool canCombineFloatSum(float x, float y, float z) {
	float result1 = (x + y) + z;
	float result2 = x + (y + z);

	cout << "(x + y) + z = " << result1 << endl;
	cout << "x + (y + z) = " << result2 << endl;

	return result1 == result2;
}


int main() {
	float f = 1.234f;
	int i = 7;

	// 1
	cout << "1.\n";
	float testFloatValues[] = { 5.0f, 5.8f, -3.4f, 1000000.0f, -2147493648.0f, -2147483648.0f, 2147473647.0f, 2147483647.0f };
	int size1 = sizeof(testFloatValues) / sizeof(testFloatValues[0]);

	for (int i = 0; i < size1; i++) {
		f = testFloatValues[i];
		cout << "isSameFloat(" << f << ") = " << (isSameFloat(f) ? "true" : "false") << endl;
	}
	cout << endl;

	// 2
	cout << "2.\n";
	int testIntValues[] = { 1, -10, 100, -1000,-16777217, -16777216, 16777216, 16777217, 2147483647 };
	int size2 = sizeof(testIntValues) / sizeof(testIntValues[0]);

	for (int j = 0; j < size2; j++) {
		i = testIntValues[j];
		cout << "isSameInt(" << i << ") = " << (isSameInt(i) ? "true" : "false") << endl;
	}
	cout << endl;

	// 3
	cout << "3. \n";
	float x = 1e-10f;
	float y = 1.0f;
	float z = -1.0f;

	cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

	if (canCombineFloatSum(x, y, z)) {
		cout << "They are equal.\n";
	}
	else {
		cout << "They are not equal.\n";
	}
	cout << endl;

	x = 1e10f;
	y = 1.0f;
	z = -1.e10f;

	cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

	if (canCombineFloatSum(x, y, z)) {
		cout << "They are equal.\n";
	}
	else {
		cout << "They are not equal.\n";
	}
	cout << endl;

	// 4
	cout << "4. \n";
	i = 7;
	f = 1.234f;
	cout << "Before: i = " << i << ", f = " << f << endl;
	i = (int)(3.14159 * f);
	cout << "After: i = " << i << endl;
	cout << endl;

	// 5
	cout << "5. \n";
	cout << "Before: i = " << i << ", f = " << f << endl;
	f = f + (float)i;
	cout << "After: f = " << f << endl;
	cout << endl;

	cout << "--- From 6. to 9. i = 7, f = 1.234 ---\n\n";
	i = 7;
	f = 1.234f;

	// 6
	cout << "6. \n";
	cout << "i == (int)((float)i): ";
	if (i == (int)((float)i)) { printf("true"); }
	else { printf("false"); }
	cout << endl << endl;

	// 7
	cout << "7. \n";
	cout << "i == (int)((double)i): ";
	if (i == (int)((double)i)) { printf("true"); }
	else { printf("false"); }
	cout << endl << endl;

	// 8
	cout << "8. \n";
	cout << "f == (float)((int)f): ";
	if (f == (float)((int)f)) { printf("true"); }
	else { printf("false"); }
	cout << endl << endl;

	// 9
	cout << "9. \n";
	cout << "f == (double)((int)f): ";
	if (f == (double)((int)f)) { printf("true"); }
	else { printf("false"); }

	return 0;
}