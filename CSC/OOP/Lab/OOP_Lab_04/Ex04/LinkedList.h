#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

template <class T>
struct Node {
	T info;
	Node* pNext;
};

template <class T>
class LinkedList {
private:
	Node<T>* _pHead, * _pTail;
	int _n;
	static Node<T>* CreateNode(const T&);

public:
	LinkedList();
	~LinkedList();

	Node<T>* AddHead(const T&);
	Node<T>* AddTail(const T&);
	Node<T>* RemoveHead();
	Node<T>* RemoveTail();

	T& operator[](const int&);

	template <class T>
	friend ostream& operator<<(ostream&, const LinkedList<T>&);
};

template <class T>
LinkedList<T>::LinkedList() {
	_pHead = _pTail = nullptr;
	_n = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
	_n = 0;
	Node<T>* node = _pHead;
	while (_pHead != nullptr) {
		_pHead = _pHead->pNext;
		delete node;
		node = _pHead;
	}
}

template <class T>
Node<T>* LinkedList<T>::CreateNode(const T& value) {
	Node<T>* node = new Node<T>{ value, nullptr };
	return node;
}

template <class T>
Node<T>* LinkedList<T>::AddTail(const T& value) {
	Node<T>* node = CreateNode(value);
	if (node == nullptr) {
		return nullptr;
	}
	if (_pHead == nullptr) {
		_pHead = _pTail = node;
	}
	else {
		_pTail->pNext = node;
		_pTail = node;
	}
	_n++;
	return node;
}

template <class T>
Node<T>* LinkedList<T>::AddHead(const T& value) {
	Node<T>* node = CreateNode(value);
	if (node == nullptr) {
		return nullptr;
	}
	if (_pHead == nullptr) {
		_pHead = _pTail = node;
	}
	else {
		node->pNext = _pHead;
		_pHead = node;
	}
	_n++;
	return node;
}

template <class T>
Node<T>* LinkedList<T>::RemoveHead() {
	if (_pHead == nullptr) {
		return nullptr;
	}
	Node<T>* node = _pHead;
	_pHead = _pHead->pNext;
	_n--;
	if (_pHead == nullptr) {
		_pTail = nullptr;
	}
	return node;
}

template <class T>
Node<T>* LinkedList<T>::RemoveTail() {
	if (_pHead == nullptr) {
		return nullptr;
	}
	Node<T>* node = _pHead;
	while (node->pNext != _pTail) {
		node = node->pNext;
	}

	if (node == _pHead) {
		_pHead = _pTail = nullptr;
	}
	else {
		Node<T>* temp = _pTail;
		node->pNext = nullptr;
		_pTail = node;
		delete temp;
	}

	_n--;
	return _pHead;
}

template <class T>
T& LinkedList<T>::operator[](const int& index) {
	if (index < 0 || index >= _n) {
		throw exception("out of range");
	}
	Node<T>* node = _pHead;
	for (int i = 0; i < index; i++) {
		node = node->pNext;
	}
	return node->info;
}

template <class T>
ostream& operator<<(ostream& os, const LinkedList<T>& list) {
	Node<T>* node = list._pHead;
	while (node != nullptr) {
		os << node->info << ", ";
		node = node->pNext;
	}
	return os;
}

#endif
