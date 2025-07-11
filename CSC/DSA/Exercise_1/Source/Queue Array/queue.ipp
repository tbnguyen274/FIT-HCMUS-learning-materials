#include <iostream>
using namespace std;

template  <typename T>
void Queue<T>::init(unsigned int queueSize) {
	items = new T[queueSize];
	front = -1;
	rear = -1;
	count = 0;
	maxSize = queueSize;
}

template <typename T>
void Queue<T>::copyQueue(const Queue<T>& q) {
	if (q.count == 0) {
		return;
	}

	init(q.maxSize);
	front = q.front;
	rear = q.rear;
	count = q.count;
	for (unsigned int i = 0; i < count; i++) {
		items[i] = q.items[i];
	}
}

template <typename T>
void Queue<T>::release() {
	delete[] items;
	front = -1;
	rear = -1;
	count = 0;
	maxSize = 0;
}

template <typename T>
bool Queue<T>::isEmpty() {
	return count == 0;
}

template <typename T>
void Queue<T>::enqueue(T newItem) {
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
T Queue<T>::dequeue() {
	if (isEmpty()) {
		cout << "Queue is empty!\n";
		return T();
	}
	T data = items[front];
	for (unsigned int i = 0; i < count - 1; i++) {
		items[i] = items[i + 1];
	}
	count--;
	rear--;
	if (count == 0) {
		front = -1;
	}
	return data;
}

template <typename T>
T Queue<T>::frontValue() {
	if (isEmpty()) {
		cout << "Queue is empty!\n";
		return T();
	}
	return items[front];
}

template <typename T>
void Queue<T>::print() {
	if (isEmpty()) {
		cout << "Queue is empty! Cannot print!\n";
		return;
	}
	for (unsigned int i = 0; i < count; i++) {
		cout << items[i] << " ";
	}
}