#ifndef LINKEDLISH_H
#define LINKEDLISH_H

#include <iostream>

using namespace std;

template <class T>
class LinkedList {
private:
	struct Node {
		T data;
		Node* next;
	};

	Node* head, * tail;
	int size;

	Node* createNode(T data) {
		Node* p = new Node;
		p->data = data;
		p->next = nullptr;
		return p;
	}

public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	LinkedList(const LinkedList& ll) {
		head = nullptr;
		tail = nullptr;
		size = 0;
		Node* cur = ll.head;
		while (cur != nullptr) {
			addTail(cur->data);
			cur = cur->next;
		}
	}

	~LinkedList() {
		Node* cur = head;
		while (cur != nullptr) {
			Node* nextNode = cur->next;
			delete cur;
			cur = nextNode;
		}
	}

	void addTail(T data) {
		Node* p = createNode(data);
		if (head == nullptr) {
			head = p;
			tail = p;
		}
		else {
			tail->next = p;
			tail = p;
		}
		size++;
	}

	T& operator[](int index) const {
		if (index < 0 || index >= size) {
			cout << "Index out of bounds" << endl;
			return head->data;
		}

		if (head == nullptr) {
			cout << "List is empty" << endl;
			return head->data;
		}

		Node* cur = head;
		for (int i = 0; i < index; i++) {
			cur = cur->next;
		}
		return cur->data;
	}

	friend istream& operator>>(istream& is, LinkedList& ll) {
		T data;
		while (is >> data) {
			ll.addTail(data);
		}
		return is;
	}

	friend ostream& operator<<(ostream& os, const LinkedList& ll) {
		Node* cur = ll.head;
		while (cur != nullptr) {
			os << cur->data << " ";
			cur = cur->next;
		}
		return os;
	}
};

#endif // !LINKEDLISH_H
