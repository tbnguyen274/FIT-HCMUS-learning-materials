#pragma once
#include "queue.h"

template <typename T>
struct RecursiveQueue {
	Node<T>* front;
	Node<T>* rear;

	unsigned int count;
	unsigned int maxSize;

	void init(unsigned int size);

	bool isEmpty();
	void enqueue(T newItem);
	T dequeue();
	T frontValue();

	void copyQueueRecursive(const RecursiveQueue<T>& q);
	void copyQueueHelper(Node<T>* node);

	void releaseRecursive();
	void releaseHelper(Node<T>* node);

	void printRecursive();
	void printHelper(Node<T>* node);
};

// Include the implementation file
#include "recursive_queue.ipp"