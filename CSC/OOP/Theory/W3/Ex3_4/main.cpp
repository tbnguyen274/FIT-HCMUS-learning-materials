#include <iostream>

using namespace std;

template <class T>
class Array {
private:
	T* data;
	int length;

public:
	Array() {
		data = nullptr;
		length = 0;
	}

	Array(int length) {
		this->length = length;
		data = new T[length];

		for (int i = 0; i < length; i++) {
			data[i] = 0;
		}
	}

	Array(T data[], int length) {
		this->length = length;
		this->data = new T[length];

		for (int i = 0; i < length; i++) {
			this->data[i] = data[i];
		}
	}

	Array(const Array& a) {
		length = a.length;
		data = new T[length];

		for (int i = 0; i < length; i++) {
			data[i] = a.data[i];
		}
	}

	~Array() {
		delete[] data;
	}

	void print() {
		for (int i = 0; i < length; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	int data[] = { 1, 2, 3, 4, 5 };

	Array<int> a1;
	Array<int> a2(5);
	Array<int> a3(data, 5);
	Array<int> a4(a3);

	a1.print();
	a2.print();
	a3.print();
	a4.print();

	double data2[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

	Array<double> a5;
	Array<double> a6(5);
	Array<double> a7(data2, 5);
	Array<double> a8(a7);

	a5.print();
	a6.print();
	a7.print();
	a8.print();

	char data3[] = { 'a', 'b', 'c', 'd', 'e' };

	Array<char> a9;
	Array<char> a10(5);
	Array<char> a11(data3, 5);
	Array<char> a12(a11);

	a9.print();
	a10.print();
	a11.print();
	a12.print();

	return 0;
}
