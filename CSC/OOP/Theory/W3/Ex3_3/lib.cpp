#include "lib.h"

Array::Array() {
	data = nullptr;
	length = 0;
}

Array::Array(int length) {
	this->length = length;
	data = new int[length];

	for (int i = 0; i < length; i++) {
		data[i] = 0;
	}
}

Array::Array(int data[], int length) {
	this->length = length;
	this->data = new int[length];

	for (int i = 0; i < length; i++) {
		this->data[i] = data[i];
	}
}

Array::Array(const Array& a) {
	length = a.length;
	data = new int[length];

	for (int i = 0; i < length; i++) {
		data[i] = a.data[i];
	}
}

Array::~Array() {
	delete[] data;
}

void Array::print() {
	for (int i = 0; i < length; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}