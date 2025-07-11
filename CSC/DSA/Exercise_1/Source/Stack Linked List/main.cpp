#include "stack.h"
#include "recursive_stack.h"
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 In main.cpp, create a menu to test the stack operators (pop and push) - Run the program with
 normal test cases, when the stack is empty, and when the stack is full - Capture the results and
 include them in the report.
*/

int main() {
	cout << "------------------ Stack (Linked List version) ------------------\n";

	Stack<int> s;
	unsigned int size;
	cout << "Enter the size of the stack: ";
	cin >> size;
	s.init(size);
	cout << "Stack initialized with size " << size << "." << endl;

	unsigned int choice;
	int newItem;

	do {
		cout << "\n-----------------------------------------------------------------\n";
		cout << "0 - Exit\n";
		cout << "1 - Push an item\n";
		cout << "2 - Pop an item\n";
		cout << "3 - Get top value\n";
		cout << "4 - Print the stack\n";
		cout << "5 - Copy the stack from a random stack\n";
		cout << "6 - Release and initialize\n";
		cout << "7 - Compare time execution of PRINT using loop and recursive\n";
		cout << "8 - Compare time execution of COPY STACK using loop and recursive\n";
		cout << "9 - Compare time execution of RELEASE using loop and recursive\n";

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			if (s.count == s.maxSize) {
				cout << "Stack is full!\n";
			}
			else {
				cout << "Enter the item to push: ";
				cin >> newItem;
				s.push(newItem);
			}
			break;

		case 2:
			if (!s.isEmpty()) {
				cout << "Popped item: " << s.pop() << endl;
			}
			else {
				cout << "Stack is empty!\n";
			}
			break;

		case 3:
			if (!s.isEmpty()) {
				cout << "Top value: " << s.topValue() << endl;
			}
			else {
				cout << "Stack is empty!\n";
			}
			break;

		case 4:
			s.print();
			break;

		case 5:
		{
			srand((unsigned int)(time(0)));
			Stack<int> temp;
			int size = rand() % 100 + 1;
			cout << "Random stack size: " << size << endl;
			cout << "Max size: 100.\n";

			temp.init(100);
			for (int i = 0; i < size; i++) {
				temp.push(rand() % 100);
			}
			s.copyStack(temp);
			temp.release();
			cout << "Stack copied from a random stack." << endl;
			break;
		}

		case 6:
			s.release();
			cout << "Enter the new size of the stack: ";
			cin >> size;
			s.init(size);
			cout << "Stack initialized with size " << size << "." << endl;
			break;

		case 7:
		{
			Stack<int> s1;
			RecursiveStack<int> s2;
			int size = 2000;
			s1.init(size);
			s2.init(size);

			for (int i = 0; i < size; i++) {
				s1.push(i);
				s2.push(i);
			}

			auto start1 = std::chrono::high_resolution_clock::now();
			s1.print();
			auto end1 = std::chrono::high_resolution_clock::now();
			auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);

			auto start2 = std::chrono::high_resolution_clock::now();
			s2.printRecursive();
			auto end2 = std::chrono::high_resolution_clock::now();
			auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);

			cout << endl;
			cout << "Time execution for PRINT using loop: " << duration1.count() << " microseconds.\n";
			cout << "Time execution for PRINT using recursive: " << duration2.count() << " microseconds.\n";

			s1.release();
			s2.releaseRecursive();

			break;
		}

		case 8:
		{
			Stack<int> s1, s2;
			RecursiveStack<int> s3, s4;

			int size = 2000;
			s1.init(size);
			s3.init(size);

			for (int i = 0; i < size; i++) {
				s1.push(i);
				s3.push(i);
			}

			auto start1 = std::chrono::high_resolution_clock::now();
			s2.copyStack(s1);
			auto end1 = std::chrono::high_resolution_clock::now();
			auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);

			auto start2 = std::chrono::high_resolution_clock::now();
			s4.copyStackRecursive(s3);
			auto end2 = std::chrono::high_resolution_clock::now();
			auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);

			cout << endl;
			cout << "Time execution for COPY STACK using loop: " << duration1.count() << " microseconds.\n";
			cout << "Time execution for COPY STACK using recursive: " << duration2.count() << " microseconds.\n";

			s1.release();
			s2.release();
			s3.releaseRecursive();
			s4.releaseRecursive();

			break;
		}

		case 9:
		{
			Stack<int> s1;
			RecursiveStack<int> s2;
			int size = 2000;
			s1.init(size);
			s2.init(size);

			for (int i = 0; i < size; i++) {
				s1.push(i);
				s2.push(i);
			}

			auto start1 = std::chrono::high_resolution_clock::now();
			s1.release();
			auto end1 = std::chrono::high_resolution_clock::now();
			auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);

			auto start2 = std::chrono::high_resolution_clock::now();
			s2.releaseRecursive();
			auto end2 = std::chrono::high_resolution_clock::now();
			auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);

			cout << endl;
			cout << "Time execution for RELEASE using loop: " << duration1.count() << " microseconds.\n";
			cout << "Time execution for RELEASE using recursive: " << duration2.count() << " microseconds.\n";

			break;
		}

		case 0:
			break;

		default:
			cout << "Invalid choice\n";
		}
	} while (choice > 0);

	if (!s.isEmpty()) {
		s.release();
	}
	return 0;
}