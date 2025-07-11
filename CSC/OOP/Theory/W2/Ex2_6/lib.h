#ifndef LIB_H
#define LIB_H

#include <iostream>
using namespace std;

class Array {
private:
	int* arr;
	int size;

public:
	void input();
	void output();
	int getSize();
	void setSize(int size);
	int getElement(int index);
	void setElement(int index, int value);
	int find(int value);
	void sort(bool (*compare)(int, int));

	// destructor
	~Array() {
		delete[] arr;
	}
};

bool ascending(int a, int b);
bool descending(int a, int b);

#endif // !LIB_H
