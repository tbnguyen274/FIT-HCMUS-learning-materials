#pragma once

template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
struct Stack {
	Node<T>* top;

	unsigned int count;
	unsigned int maxSize;

	void init(unsigned int size);
	void copyStack(const Stack<T>& s);
	void release();
	bool isEmpty();
	void push(T newItem);
	T pop();
	T topValue();
	void print();
};

// Include the implementation file
#include "stack.ipp"

