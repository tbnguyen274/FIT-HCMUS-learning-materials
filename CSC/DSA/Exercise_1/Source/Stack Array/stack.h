#pragma once

template <typename T>
struct Stack {
	T* items;
	int top;
	unsigned int maxSize;

	void init(unsigned int stackSize);
	void copyStack(const Stack<T>& s);
	void release();

	bool isEmpty();
	bool isFull();
	void push(T newItem);
	T pop();
	T topValue();

	void print();
};

// Include the implementation file
#include "stack.ipp"

