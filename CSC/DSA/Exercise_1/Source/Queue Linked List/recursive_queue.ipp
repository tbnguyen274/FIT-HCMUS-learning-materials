#include <iostream>
using namespace std;

template <typename T>
void RecursiveQueue<T>::init(unsigned int size) {
	front = rear = NULL;
	maxSize = size;
	count = 0;
}

template <typename T>
bool RecursiveQueue<T>::isEmpty() {
	return front == NULL;
}

template <typename T>
void RecursiveQueue<T>::enqueue(T newItem) {
	if (count == maxSize) {
		cout << "Queue is full!\n";
		return;
	}

	Node<T>* newNode = new Node<T>;
	newNode->data = newItem;
	newNode->next = NULL;
	if (front == NULL) {
		front = rear = newNode;
	}
	else {
		rear->next = newNode;
	}
	rear = newNode;
	count++;
}

template <typename T>
T RecursiveQueue<T>::dequeue() {
	if (isEmpty()) {
		cout << "Queue is empty!\n";
		return T();
	}

	Node<T>* temp = front;
	T data = front->data;
	front = front->next;
	delete temp;

	if (front == NULL) {
		rear = NULL;
	}
	count--;

	return data;
}

template <typename T>
T RecursiveQueue<T>::frontValue() {
	if (isEmpty()) {
		cout << "Queue is empty!\n";
		return T();
	}
	return front->data;
}

// ---------------- RECURSIVE FUNCTIONS ----------------

// Copy the queue recursively
template <typename T>
void RecursiveQueue<T>::copyQueueRecursive(const RecursiveQueue<T>& q) {
	init(q.maxSize);
	copyQueueHelper(q.front);
}

template <typename T>
void RecursiveQueue<T>::copyQueueHelper(Node<T>* node) {
	if (node == NULL) {
		return;
	}
	enqueue(node->data);
	copyQueueHelper(node->next);
}

// Release the queue recursively
template <typename T>
void RecursiveQueue<T>::releaseRecursive() {
	releaseHelper(front);
	rear = NULL;
	maxSize = 0;
	count = 0;
}

template <typename T>
void RecursiveQueue<T>::releaseHelper(Node<T>* node) {
	if (node == NULL) {
		return;
	}
	releaseHelper(node->next);
	delete node;
}

// Print the queue recursively
template <typename T>
void RecursiveQueue<T>::printRecursive() {
	if (isEmpty()) {
		cout << "Queue is empty! Cannot print!" << endl;
		return;
	}
	printHelper(front);
}

template <typename T>
void RecursiveQueue<T>::printHelper(Node<T>* node) {
	if (node == NULL) {
		return;
	}
	cout << node->data << " ";
	printHelper(node->next);
}