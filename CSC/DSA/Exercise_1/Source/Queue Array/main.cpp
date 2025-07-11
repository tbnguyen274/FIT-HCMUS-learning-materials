#include "queue.h"
#include "recursive_queue.h"
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	cout << "------------------ Queue (Array version) ------------------\n";

	Queue<int> q;
	unsigned int choice;
	int item;
	unsigned int size;
	cout << "Enter the size of the Queue: ";
	cin >> size;
	q.init(size);
	cout << "Queue initialized with size " << size << "." << endl;

	do {
		cout << "\n-----------------------------------------------------------\n";
		cout << "0 - Exit\n";
		cout << "1 - Enqueue an item\n";
		cout << "2 - Dequeue an item\n";
		cout << "3 - Get front value\n";
		cout << "4 - Print the queue\n";
		cout << "5 - Copy the queue from a random queue\n";
		cout << "6 - Release and initialize\n";
		cout << "7 - Compare time execution of PRINT using loop and recursive\n";
		cout << "8 - Compare time execution of COPY QUEUE using loop and recursive\n";
		cout << "9 - Compare time execution of DEQUEUE using loop and recursive\n";

		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			if (q.count == q.maxSize) {
				cout << "Warning: Queue is full!\n";
			}
			else {
				cout << "Enter the item to enqueue: ";
				cin >> item;
				q.enqueue(item);
			}
			break;

		case 2:
			if (q.isEmpty()) {
				cout << "Warning: Queue is empty!\n";
			}
			else {
				cout << "Dequeued item: " << q.dequeue() << endl;
			}
			break;

		case 3:
			if (q.isEmpty()) {
				cout << "Warning: Queue is empty!\n";
			}
			else {
				cout << "Front value: " << q.frontValue() << endl;
			}
			break;

		case 4:
			q.print();
			break;

		case 5:
		{
			srand((unsigned int)(time(0)));

			Queue<int> temp;
			int size = rand() % 100 + 1;
			cout << "Random queue size: " << size << endl;
			cout << "Max size: 100.\n";
			temp.init(100);
			for (int i = 0; i < size; i++) {
				temp.enqueue(rand() % 100);
			}
			q.copyQueue(temp);
			temp.release();
			cout << "Queue copied from a random queue." << endl;
			break;
		}

		case 6:
			q.release();
			cout << "Enter the new size of the Queue: ";
			cin >> size;
			q.init(size);
			cout << "Queue initialized with size " << size << "." << endl;
			break;

		case 7:
		{
			Queue<int> q1;
			RecursiveQueue<int> q2;
			int size = 2000;
			q1.init(size);
			q2.init(size);

			for (int i = 0; i < size; i++) {
				q1.enqueue(i);
				q2.enqueue(i);
			}

			auto start1 = std::chrono::high_resolution_clock::now();
			q1.print();
			auto end1 = std::chrono::high_resolution_clock::now();
			auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);

			auto start2 = std::chrono::high_resolution_clock::now();
			q2.printRecursive();
			auto end2 = std::chrono::high_resolution_clock::now();
			auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);

			cout << endl;
			cout << "Time execution for PRINT using loop: " << duration1.count() << " microseconds.\n";
			cout << "Time execution for PRINT using recursive: " << duration2.count() << " microseconds.\n";
			
			q1.release();
			q2.release();
			
			break;
		}

		case 8:
		{
			Queue<int> q1, q2;
			RecursiveQueue<int> q3, q4;

			int size = 2000;
			q1.init(size);
			q3.init(size);

			for (int i = 0; i < size; i++) {
				q1.enqueue(i);
				q3.enqueue(i);
			}

			auto start1 = std::chrono::high_resolution_clock::now();
			q2.copyQueue(q1);
			auto end1 = std::chrono::high_resolution_clock::now();
			auto elapsed1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);

			auto start2 = std::chrono::high_resolution_clock::now();
			q4.copyQueueRecursive(q3);
			auto end2 = std::chrono::high_resolution_clock::now();
			auto elapsed2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);

			cout << endl;
			cout << "Time execution for COPY QUEUE using loop: " << elapsed1.count() << " microseconds.\n";
			cout << "Time execution for COPY QUEUE using recursive: " << elapsed2.count() << " microseconds.\n";

			q1.release();
			q2.release();
			q3.release();
			q4.release();

			break;
		}

		case 9:
		{
			Queue<int> q1;
			RecursiveQueue<int> q2;
			int size = 2000;
			q1.init(size);
			q2.init(size);

			for (int i = 0; i < size; i++) {
				q1.enqueue(i);
				q2.enqueue(i);
			}

			auto start1 = std::chrono::high_resolution_clock::now();
			for (int i = 0; i < size; i++) {
				q1.dequeue();
			}
			auto end1 = std::chrono::high_resolution_clock::now();
			auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);

			auto start2 = std::chrono::high_resolution_clock::now();
			for (int i = 0; i < size; i++) {
				q2.dequeueRecursive();
			}
			auto end2 = std::chrono::high_resolution_clock::now();
			auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);

			cout << endl;
			cout << "Time execution for DEQUEUE using loop: " << duration1.count() << " microseconds.\n";
			cout << "Time execution for DEQUEUE using recursive: " << duration2.count() << " microseconds.\n";

			break;
		}

		case 0:
			break;

		default:
			cout << "Invalid choice\n";
		}
	} while (choice > 0);

	if (!q.isEmpty()) {
		q.release();
	}
	return 0;
}