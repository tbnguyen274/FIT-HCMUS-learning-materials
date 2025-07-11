#include <iostream>
using namespace std;

template <typename T>
void Stack<T>::init(unsigned int size) {
	top = NULL;
	maxSize = size;
}

template <typename T>
void Stack<T>::copyStack(const Stack<T>& s) {
	if (s.top == NULL) {
		return;
	}
	init(s.maxSize);
	Node<T>* temp = s.top;
	while (temp != NULL) {
		push(temp->data);
		temp = temp->next;
	}
}

template <typename T>
void Stack<T>::release() {
	while (top != NULL) {
		Node<T>* temp = top;
		top = top->next;
		delete temp;
	}
	maxSize = 0;
	count = 0;
}

template <typename T>
bool Stack<T>::isEmpty() {
	return top == NULL;
}

template <typename T>
void Stack<T>::push(T newItem) {
	if (count == maxSize) {
		cout << "Stack is full!\n";
		return;
	}
	Node<T>* newNode = new Node<T>;
	newNode->data = newItem;
	newNode->next = top;
	top = newNode;
	count++;
}

template <typename T>
T Stack<T>::pop() {
	if (isEmpty()) {
		cout << "Stack is empty\n";
		return T();
	}
	Node<T>* temp = top;
	T data = top->data;
	top = top->next;
	delete temp;
	count--;

	return data;
}

template <typename T>
T Stack<T>::topValue() {
	if (isEmpty()) {
		cout << "Stack is empty\n";
		return T();
	}
	return top->data;
}

template <typename T>
void Stack<T>::print() {
	if (isEmpty()) {
		cout << "Stack is empty! Cannot print!\n";
		return;
	}
	Node<T>* temp = top;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}