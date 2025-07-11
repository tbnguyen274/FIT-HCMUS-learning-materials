#ifndef LIB_H
#define LIB_H

#include <iostream>

using namespace std;

class Array {
private:
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

	// Type-cast
	operator int* ();

	// I/O
	friend istream& operator>>(istream& is, Array& arr);
	friend ostream& operator<<(ostream& os, const Array& arr);
};

#endif