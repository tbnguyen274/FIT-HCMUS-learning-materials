#include "lib.h"

int main() {
    // Constructors
    Array arr1;
    Array arr2(5);

    // Input
    cout << "Enter 5 elements for arr2: ";
    cin >> arr2;

	// Output
    cout << "arr1 (default): " << arr1 << endl;
    cout << "arr2: " << arr2 << endl;

    // Copy constructor
    Array arr3(arr2);
    cout << "arr3 (copy of arr2): " << arr3 << endl;

    // Concatenation
    Array arr4 = arr2 + arr3;
    cout << "arr4 (arr2 + arr3): " << arr4 << endl;

	// Assignment
    arr1 = arr2;
    cout << "arr1 after assignment from arr2: " << arr1 << endl;

    arr1 += arr4;
    cout << "arr1 after += arr4: " << arr1 << endl;

	// Array indexer
    cout << "arr2[2]: " << arr2[2] << endl;
    arr2[2] = 99;
    cout << "arr2 after modifying index 2: " << arr2 << endl;

	// Type-cast
    int* ptr = arr2;
    cout << "First element using type-cast: " << ptr[0] << endl;

    return 0;
}