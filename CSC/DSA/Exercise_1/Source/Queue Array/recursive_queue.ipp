#include <iostream>
using namespace std;

template  <typename T>
void RecursiveQueue<T>::init(unsigned int queueSize) {
	items = new T[queueSize];
	front = -1;
	rear = -1;
	count = 0;
	maxSize = queueSize;
}

template <typename T>
void RecursiveQueue<T>::release() {
	delete[] items;
	front = -1;
	rear = -1;
	count = 0;
	maxSize = 0;
}

template <typename T>
bool RecursiveQueue<T>::isEmpty() {
	return count == 0;
}

template <typename T>
void RecursiveQueue<T>::enqueue(T newItem) {
	if (count == maxSize) {
		cout << "Queue is full!\n";
		return;
	}
	if (front == -1) {
		front = 0;
	}
	items[++rear] = newItem;
	count++;
}

template <typename T>
T RecursiveQueue<T>::frontValue() {
	if (isEmpty()) {
		cout << "Queue is empty!\n";
		return T();
	}
	return items[front];
}

// ---------------- RECURSIVE FUNCTIONS ----------------

// Copy the queue recursively
template <typename T>
void RecursiveQueue<T>::copyQueueRecursive(const RecursiveQueue<T>& q) {
	if (q.count == 0) {
		return;
	}
	init(q.maxSize);
	copyQueueHelper(q, 0);
}

template <typename T>
void RecursiveQueue<T>::copyQueueHelper(const RecursiveQueue<T>& q, int index) {
	if (index == q.count) {
		return;
	}
	if (front == -1) {
		front = 0;
	}
	items[index] = q.items[index];
	count++;
	rear++;
	copyQueueHelper(q, index + 1);
}

// Dequeue the queue recursively
template <typename T>
T RecursiveQueue<T>::dequeueRecursive() {
	if (isEmpty()) {
		cout << "Queue is empty\n";
		return T();
	}
	T data = items[front];
	dequeueHelper(0);
	if (count == 0) {
		front = -1;
	}
	return data;
}

template <typename T>
void RecursiveQueue<T>::dequeueHelper(int index) {
	if (index == count - 1) {
		count--;
		rear--;
		return;
	}
	items[index] = items[index + 1];
	dequeueHelper(index + 1);
}

// Print the queue recursively
template <typename T>
void RecursiveQueue<T>::printRecursive() {
	if (isEmpty()) {
		cout << "Queue is empty! Cannot print!\n";
		return;
	}
	printHelper(0);
}

template <typename T>
void RecursiveQueue<T>::printHelper(int index) {
	if (index == count) {
		return;
	}
	cout << items[index] << " ";
	printHelper(index + 1);
}