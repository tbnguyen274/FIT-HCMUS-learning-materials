#ifndef LIB_H
#define LIB_H

#include <iostream>

using namespace std;

class Array {
protected:
	int* data;
	int size;

public:
	// Constructor
	Array();
	Array(int size);

	// Copy constructor
	Array(const Array& arr);

	// Destructor
	~Array();

	// Concatenation
	Array operator+(const Array& arr);

	// Assignment
	Array& operator=(const Array& arr);
	Array& operator+=(const Array& arr);

	// Array indexer
	int& operator[](int index);

	// Get value at index
	int operator[](int index) const;

	// Type-cast
	operator int* ();

	// I/O
	friend istream& operator>>(istream& is, Array& arr);
	friend ostream& operator<<(ostream& os, const Array& arr);
};


class HistogramArray : public Array {
private:
	int* histogram;
	int histSize;

public:
	HistogramArray();
	HistogramArray(const HistogramArray& arr);
	HistogramArray(const Array& arr);
	~HistogramArray();
	HistogramArray& operator=(const HistogramArray& arr);

	int getMaxValue();
	void computeHistogram();
	void displayHistogram();
	int& operator[](int index);

};

#endif