#include "lib.h"

Array::Array() {
	data = nullptr;
	size = 0;
}

Array::Array(int size) {
	this->size = size;
	data = new int[size];

	for (int i = 0; i < size; i++) {
		data[i] = 0;
	}
}

Array::Array(const Array& arr) {
	size = arr.size;
	data = new int[size];

	for (int i = 0; i < size; i++) {
		data[i] = arr.data[i];
	}
}

Array::~Array() {
	delete[] data;
}

Array Array::operator+(const Array& arr) {
	Array result(size + arr.size);

	for (int i = 0; i < size; i++) {
		result.data[i] = data[i];
	}

	for (int i = 0; i < arr.size; i++) {
		result.data[size + i] = arr.data[i];
	}

	return result;
}

Array& Array::operator=(const Array& arr) {
	if (this != &arr) {
		delete[] data;	// Free old memory
		size = arr.size;
		data = new int[size];	// Deep copy

		for (int i = 0; i < size; i++) {
			data[i] = arr.data[i];
		}
	}

	return *this;
}

Array& Array::operator+=(const Array& arr) {
	*this = *this + arr;
	return *this;
}

int& Array::operator[](int index) {
	return data[index];
}

Array::operator int* () {
	return data;
}

istream& operator>>(istream& is, Array& arr) {
	for (int i = 0; i < arr.size; i++) {
		is >> arr.data[i];
	}
	return is;
}

ostream& operator<<(ostream& os, const Array& arr) {
	for (int i = 0; i < arr.size; i++) {
		os << arr.data[i] << " ";
	}
	return os;
}