#include <iostream>
using namespace std;

template <typename T>
void Queue<T>::init(unsigned int size) {
	front = rear = NULL;
	maxSize = size;
	count = 0;
}

template <typename T>
void Queue<T>::copyQueue(const Queue<T>& q) {
	init(q.maxSize);
	Node<T>* temp = q.front;
	while (temp != NULL) {
		enqueue(temp->data);
		temp = temp->next;
	}
}

template <typename T>
void Queue<T>::release() {
	while (front != NULL) {
		Node<T>* temp = front;
		front = front->next;
		delete temp;
	}
	rear = NULL;
	maxSize = 0;
	count = 0;
}

template <typename T>
bool Queue<T>::isEmpty() {
	return front == NULL;
}

template <typename T>
void Queue<T>::enqueue(T newItem) {
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
T Queue<T>::dequeue() {
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
T Queue<T>::frontValue() {
	if (isEmpty()) {
		cout << "Queue is empty!\n";
		return T();
	}
	return front->data;
}

template <typename T>
void Queue<T>::print() {
	if (isEmpty()) {
		cout << "Queue is empty! Cannot print!\n";
		return;
	}
	Node<T>* temp = front;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}