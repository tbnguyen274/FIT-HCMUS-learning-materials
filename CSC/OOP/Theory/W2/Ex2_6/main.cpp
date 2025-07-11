#include "lib.h"

int main() {
	Array arr;
	arr.input();
	arr.output();

	cout << "Size: " << arr.getSize() << endl;
	cout << "Element at index 2: " << arr.getElement(2) << endl;
	cout << "Element at index 5: " << arr.getElement(5) << endl << endl;

	arr.setSize(10);
	cout << "Update size to 10" << endl;
	arr.output();
	cout << endl;

	cout << "Element at index 5: " << arr.getElement(5) << endl;
	arr.setElement(5, 5);
	arr.setElement(100, 100);
	cout << "Set element at index 5 to 5 and at index 100 to 100" << endl;
	arr.output();
	cout << endl;

	cout << "Find 5: " << arr.find(5) << endl;
	cout << "Find 1000: " << arr.find(1000) << endl;
	cout << endl;

	arr.sort(ascending);
	cout << "Sort in ascending order" << endl;
	arr.output();
	arr.sort(descending);
	cout << "Sort in descending order" << endl;
	arr.output();
	return 0;
}