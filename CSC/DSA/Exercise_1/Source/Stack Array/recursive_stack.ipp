#include <iostream>
using namespace std;

// ---------------- RECURSIVE FUNCTIONS ----------------

// Copy the stack recursively
template <typename T>
void RecursiveStack<T>::copyStackRecursive(const RecursiveStack<T>& s) {
    if (s.top == -1) return;
    init(s.maxSize);
    copyStackHelper(s, s.top);
}

template <typename T>
void RecursiveStack<T>::copyStackHelper(const RecursiveStack<T>& s, int index) {
    if (index == -1) {
        return;
    }
    copyStackHelper(s, index - 1);
    push(s.items[index]);
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
void RecursiveStack<T>::printHelper(int index) {
    if (index == -1) {
        return;
    }
    cout << items[index] << " ";
    printHelper(index - 1);
}

// ---------------- NON-RECURSIVE FUNCTIONS ----------------

template <typename T>
void RecursiveStack<T>::init(unsigned int stackSize) {
    items = new T[stackSize];
    top = -1;
    maxSize = stackSize;
}

template <typename T>
void RecursiveStack<T>::release() {
    delete[] items;
    top = -1;
    maxSize = 0;
}

template <typename T>
bool RecursiveStack<T>::isEmpty() {
    return top == -1;
}

template <typename T>
bool RecursiveStack<T>::isFull() {
    return top == maxSize - 1;
}

template <typename T>
void RecursiveStack<T>::push(T newItem) {
    if (isFull()) {
        cout << "Stack is full! Cannot push " << newItem << endl;
        return;
    }
    items[++top] = newItem;
}

template <typename T>
T RecursiveStack<T>::pop() {
    if (isEmpty()) {
        cout << "Stack is empty! Cannot pop!" << endl;
        return T();
    }
    return items[top--];
}

template <typename T>
T RecursiveStack<T>::topValue() {
    if (isEmpty()) {
        cout << "Stack is empty! Cannot get top value!" << endl;
        return T();
    }
    return items[top];
}