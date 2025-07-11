#include <iostream>
using namespace std;

template <typename T>
void RecursiveStack<T>::init(unsigned int size) {
	top = NULL;
	maxSize = size;
	count = 0;
}

template <typename T>
bool RecursiveStack<T>::isEmpty() {
	return top == NULL;
}

template <typename T>
void RecursiveStack<T>::push(T newItem) {
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
T RecursiveStack<T>::pop() {
	if (isEmpty()) {
		cout << "Stack is empty!\n";
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
T RecursiveStack<T>::topValue() {
	if (isEmpty()) {
		cout << "Stack is empty\n";
		return T();
	}
	return top->data;
}

// ---------------- RECURSIVE FUNCTIONS ----------------

// Copy the stack recursively
template <typename T>
void RecursiveStack<T>::copyStackRecursive(const RecursiveStack<T>& s) {
	init(s.maxSize);
	copyStackHelper(top, s.top);
}

template <typename T>
void RecursiveStack<T>::copyStackHelper(Node<T>*& top, Node<T>* sTop) {
	if (sTop == NULL) {
		top = NULL;
		return;
	}
	top = new Node<T>;
	top->data = sTop->data;
	count++;
	copyStackHelper(top->next, sTop->next);
}

// Release the stack recursively
template <typename T>
void RecursiveStack<T>::releaseRecursive() {
	releaseHelper(top);
	maxSize = 0;
}

template <typename T>
void RecursiveStack<T>::releaseHelper(Node<T>*& top) {
	if (top == NULL) {
		return;
	}
	releaseHelper(top->next);
	delete top;
	count--;
	top = NULL;
}

// Print the stack recursively
template <typename T>
void RecursiveStack<T>::printRecursive() {
	if (isEmpty()) {
		cout << "Stack is empty! Cannot print!" << endl;
		return;
	}
	printHelper(top);
}

template <typename T>
void RecursiveStack<T>::printHelper(Node<T>* top) {
	if (top == NULL) {
		return;
	}
	cout << top->data << " ";
	printHelper(top->next);
}