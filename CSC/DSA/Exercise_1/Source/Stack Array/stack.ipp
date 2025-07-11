#include <iostream>
using namespace std;

template <typename t>
void Stack<t>::init(unsigned int stackSize) {
	items = new t[stackSize];
	top = -1;
	maxSize = stackSize;
}

template <typename T>
void Stack<T>::copyStack(const Stack<T>& s) {
	if (s.top == -1) {
		return;
	}
	init(s.maxSize);
	top = s.top;
	for (int i = 0; i <= top; i++) {
		items[i] = s.items[i];
	}
}

template <typename T>
void Stack<T>::release() {
	delete[] items;
	top = -1;
	maxSize = 0;
}

template <typename T>
bool Stack<T>::isEmpty() {
	return top == -1;
}

template <typename T>
bool Stack<T>::isFull() {
	return top == maxSize - 1;
}

template <typename T>
void Stack<T>::push(T newItem) {
	if (isFull()) {
		cout << "Stack is full! Cannot push " << newItem << endl;
		return;
	}
	items[++top] = newItem;
}

template <typename T>
T Stack<T>::pop() {
	if (isEmpty()) {
		cout << "Stack is empty! Cannot pop!" << endl;
		return T();
	}
	return items[top--];
}

template <typename T>
T Stack<T>::topValue() {
	if (isEmpty()) {
		cout << "Stack is empty! Cannot get top value!" << endl;
		return T();
	}
	return items[top];
}

template <typename T>
void Stack<T>::print() {
	if (isEmpty()) {
		cout << "Stack is empty! Cannot print!" << endl;
		return;
	}
	for (int i = top; i >= 0; i--) {
		cout << items[i] << " ";
	}
	cout << endl;
}