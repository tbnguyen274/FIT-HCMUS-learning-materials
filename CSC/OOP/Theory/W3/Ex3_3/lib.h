#ifndef LIB_H
#define LIB_H

#include <iostream>

using namespace std;

class Array {
private:
	int* data;
	int length;

public:
	Array();
	Array(int length);
	Array(int data[], int length);
	Array(const Array& a);
	~Array();
	void print();
};

#endif