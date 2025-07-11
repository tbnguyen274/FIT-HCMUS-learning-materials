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

int Array::operator[](int index) const {
	return data[index];
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

// HISTOGRAM_ARRAY
HistogramArray::HistogramArray() {
	histogram = nullptr;
	histSize = 0;
}

HistogramArray::HistogramArray(const HistogramArray& arr) : Array(arr) {
	histSize = arr.histSize;
	histogram = new int[histSize];
	for (int i = 0; i < histSize; i++) {
		histogram[i] = arr.histogram[i];
	}
}

HistogramArray::HistogramArray(const Array& arr) : Array(arr) {
	histogram = nullptr;
	histSize = 0;

	computeHistogram();
}

HistogramArray::~HistogramArray() {
	delete[] histogram;
}

HistogramArray& HistogramArray::operator=(const HistogramArray& arr) {
	if (this != &arr) {
		Array::operator=(arr); // Call base class assignment operator
		delete[] histogram; // Free old memory

		histSize = arr.histSize;
		histogram = new int[histSize];
		for (int i = 0; i < histSize; i++) {
			histogram[i] = arr.histogram[i];
		}
	}
	return *this;
}

int HistogramArray::getMaxValue() {
	if (size == 0) {
		return 0;
	}
	int maxValue = data[0];
	for (int i = 1; i < size; i++) {
		if (data[i] > maxValue) {
			maxValue = data[i];
		}
	}
	return maxValue;
}

void HistogramArray::computeHistogram() {
	if (histogram) {
		delete[] histogram;
	}
	histSize = getMaxValue() + 1;
	histogram = new int[histSize];
	
	for (int i = 0; i < histSize; i++) {
		histogram[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		if (data[i] >= 0 && data[i] < histSize) {
			histogram[data[i]]++;
		}
	}
}

void HistogramArray::displayHistogram() {
	cout << "Histogram: " << endl;
	for (int i = 0; i < histSize; i++) {
		cout << i << " ";
	}
	cout << endl;

	for (int i = 0; i < histSize; i++) {
		cout << histogram[i] << " ";
	}
	cout << endl;
}

// recompute histogram when a value is changed
int& HistogramArray::operator[](int index) {
	if (index >= 0 && index < size) {
		computeHistogram();
	}
	return Array::operator[](index);
}