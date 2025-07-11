#pragma once

template <typename T>
struct Queue {
	T* items;

	int front;
	int rear;
	unsigned int count;
	unsigned int maxSize;

	void init(unsigned int queueSize);
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