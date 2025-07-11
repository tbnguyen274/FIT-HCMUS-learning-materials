#include "lib.h"

void Array::input() {
	cout << "Enter the size of the array: ";
	cin >> this->size;
	this->arr = new int[this->size];

	cout << "Enter the elements of the array (separated by space): ";
	for (int i = 0; i < this->size; i++) {
		cin >> this->arr[i];
	}
}

void Array::output() {
	for (int i = 0; i < this->size; i++) {
		cout << this->arr[i] << " ";
	}
	cout << endl;
}

int Array::getSize() {
	return this->size;
}

void Array::setSize(int size) {
	if (size == this->size) {
		return;
	}

	// use a temporary array to store the old elements
	int* temp = new int[size];
	int minSize = this->size < size ? this->size : size;

	for (int i = 0; i < minSize; i++) {
		temp[i] = this->arr[i];
	}

	// delete the old array and update the size
	delete[] this->arr;
	this->size = size;
	this->arr = new int[this->size];

	// restore the old elements
	for (int i = 0; i < minSize; i++) {
		this->arr[i] = temp[i];
	}

	for (int i = minSize; i < this->size; i++) {
		this->arr[i] = 0;
	}

	delete[] temp;
}

int Array::getElement(int index) {
	if (index < 0 || index >= this->size) {
		cout << "Index out of range." << endl;
		return -1;
	}

	return this->arr[index];
}

void Array::setElement(int index, int value) {
	if (index < 0 || index >= this->size) {
		cout << "Index out of range." << endl;
		return;
	}

	this->arr[index] = value;
}

int Array::find(int value) {
	for (int i = 0; i < this->size; i++) {
		if (this->arr[i] == value) {
			return i;
		}
	}

	return -1;
}

void Array::sort(bool (*compare)(int, int)) {
	for (int i = 1; i < this->size; i++) {
		int key = this->arr[i];
		int j = i - 1;

		while (j >= 0 && !compare(this->arr[j], key)) {
			this->arr[j + 1] = this->arr[j];
			j--;
		}

		this->arr[j + 1] = key;
	}
}

bool ascending(int a, int b) {
	return a <= b;
}

bool descending(int a, int b) {
	return a >= b;
}