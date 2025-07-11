#include <iostream>

using namespace std;

class MangSoNguyen {
private:
	int* arr;
	int size;

public:
	MangSoNguyen();
	MangSoNguyen(const int&);
	MangSoNguyen(int[], const int&);
	MangSoNguyen(const MangSoNguyen&);
	~MangSoNguyen();
	void Xuat();
};

MangSoNguyen::MangSoNguyen() {
	arr = nullptr;
	size = 0;
}

MangSoNguyen::MangSoNguyen(const int& n) {
	size = n;
	arr = new int[size];

	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

MangSoNguyen::MangSoNguyen(int a[], const int& n) {
	size = n;
	arr = new int[size];

	for (int i = 0; i < size; i++) {
		arr[i] = a[i];
	}
}

MangSoNguyen::MangSoNguyen(const MangSoNguyen& msn) {
	size = msn.size;
	arr = new int[size];

	for (int i = 0; i < size; i++) {
		arr[i] = msn.arr[i];
	}
}

MangSoNguyen::~MangSoNguyen() {
	delete[] arr;
}

void MangSoNguyen::Xuat() {
	cout << "MangSoNguyen(" << size << ") = {";

	for (int i = 0; i < size; i++) {
		cout << arr[i];

		if (i < size - 1) {
			cout << " ";
		}
	}
	cout << "}" << endl;
}

void main() {
	MangSoNguyen msn1;
	msn1.Xuat();

	MangSoNguyen msn2(5);
	msn2.Xuat();

	int arr[10];
	for (int i = 0; i < 8; i++) {
		arr[i] = i * i;
	}

	MangSoNguyen msn3(arr, 8);
	msn3.Xuat();

	MangSoNguyen msn4(msn3);
	msn4.Xuat();
}