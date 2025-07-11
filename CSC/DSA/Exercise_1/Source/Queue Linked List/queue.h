#pragma once

template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
struct Queue {
	Node<T>* front;
	Node<T>* rear;

	unsigned int count;
	unsigned int maxSize;

	void init(unsigned int size);
	void copyQueue(const Queue<T>& q);
	void release();

	bool isEmpty();
	void enqueue(T newItem);
	T dequeue();
	T frontValue();

	void print();
};

// Include the implementation file
#include "queue.ipp"