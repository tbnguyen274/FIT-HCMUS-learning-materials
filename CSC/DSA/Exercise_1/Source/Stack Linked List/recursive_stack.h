#pragma once
#include "stack.h"


template <typename T>
struct RecursiveStack {
	Node<T>* top;

	unsigned int maxSize;
	unsigned int count;

	void init(unsigned int size);
	bool isEmpty();
	void push(T newItem);
	T pop();
	T topValue();

	void copyStackRecursive(const RecursiveStack<T>& s);
	void copyStackHelper(Node<T>*& top, Node<T>* sTop);

	void releaseRecursive();
	void releaseHelper(Node<T>*& top);

	void printRecursive();
	void printHelper(Node<T>* top);
};

// Include the implementation file
#include "recursive_stack.ipp"

