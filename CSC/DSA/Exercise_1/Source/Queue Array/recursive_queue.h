#pragma once

template <typename T>
struct RecursiveQueue {
	T* items;
	int front;
	int rear;
	unsigned int count;
	unsigned int maxSize;

	void init(unsigned int queueSize);
	void release();
	bool isEmpty();

	void enqueue(T newItem);
	T frontValue();

	void copyQueueRecursive(const RecursiveQueue<T>& q);
	void copyQueueHelper(const RecursiveQueue<T>& q, int index);

	T dequeueRecursive();
	void dequeueHelper(int index);

	void printRecursive();
	void printHelper(int index);
};

// Include the implementation file
#include "recursive_queue.ipp"