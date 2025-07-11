#include <iostream>

using namespace std;

class SoNguyenLon {
private:
	char* _arr;
	int _size;
	static int countDigit(const int&);
	static SoNguyenLon* _SNLMax;

public:
	SoNguyenLon();
	SoNguyenLon(const int&);
	SoNguyenLon(const int&, const int&);
	SoNguyenLon(const SoNguyenLon&);
	~SoNguyenLon();

	SoNguyenLon operator-(const SoNguyenLon&);
	friend SoNguyenLon operator-(const int&, const SoNguyenLon&);
	SoNguyenLon operator+(const SoNguyenLon&);
	friend SoNguyenLon operator+(const int&, const SoNguyenLon&);

	bool operator>(const SoNguyenLon&);
	void capNhatSNLMax();
	static SoNguyenLon SNLMax();
	friend ostream& operator<<(ostream&, const SoNguyenLon&);
};

SoNguyenLon::SoNguyenLon() {
	_size = 1;
	_arr = new char[_size];
	_arr[0] = 0;

	capNhatSNLMax();
}

int SoNguyenLon::countDigit(const int& n) {
	int count = 0, temp = n;
	while (temp > 0) {
		temp /= 10;
		count++;
	}
	return count;
}

SoNguyenLon::SoNguyenLon(const int& n) {
	if (n <= 0) {
		_size = 1;
		_arr = new char[_size];
		_arr[0] = 0;
		return;
	}

	_size = countDigit(n);
	_arr = new char[_size];
	int temp = n;

	for (int i = _size - 1; i >= 0; i--) {
		_arr[i] = temp % 10;
		temp /= 10;
	}

	capNhatSNLMax();
}

SoNguyenLon::SoNguyenLon(const int& n, const int& size) {
	if (size < 1 || size > 100 || n < 0) {
		_size = 1;
		_arr = new char[_size];
		_arr[0] = 0;
		return;
	}

	_size = size;
	_arr = new char[_size];

	for (int i = 0; i < _size; i++) {
		_arr[i] = n;
	}

	capNhatSNLMax();
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon& snl) {
	_size = snl._size;
	_arr = new char[_size];

	for (int i = 0; i < _size; i++) {
		_arr[i] = snl._arr[i];
	}

	capNhatSNLMax();
}

SoNguyenLon::~SoNguyenLon() {
	if (_SNLMax == this) {
		_SNLMax = nullptr;
	}
	delete[] _arr;
}

SoNguyenLon SoNguyenLon::operator-(const SoNguyenLon& snl) {
	if (_size < snl._size) {
		return SoNguyenLon(0);
	}

	int size = (_size > snl._size) ? _size : snl._size;
	SoNguyenLon res(0, size);

	int carry = 0;
	int i = _size - 1;
	int j = snl._size - 1;
	
	// Tru tu cuoi ve dau
	while (i >= 0) {
		int sub = _arr[i] - carry;
		if (j >= 0) {
			sub -= snl._arr[j];
		}
		if (sub < 0) {
			sub += 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		res._arr[i] = sub;
		i--;
		j--;
	}

	// Xoa so 0 o dau
	while (res._arr[0] == 0 && res._size > 1) {
		char* temp = new char[res._size - 1];

		for (int i = 0; i < res._size - 1; i++) {
			temp[i] = res._arr[i + 1];
		}

		delete[] res._arr;
		res._arr = temp;
		res._size--;
	}

	return res;
}

SoNguyenLon operator-(const int& n, const SoNguyenLon& snl) {
	return SoNguyenLon(n) - snl;
}

SoNguyenLon SoNguyenLon::operator+(const SoNguyenLon& snl) {
	int size = (_size > snl._size) ? _size : snl._size;
	SoNguyenLon res(0, size);

	int carry = 0;
	int i = _size - 1;
	int j = snl._size - 1;

	// Cong tu cuoi ve dau
	while (i >= 0) {
		int sum = _arr[i] + carry;
		if (j >= 0) {
			sum += snl._arr[j];
		}
		res._arr[i] = sum % 10;
		carry = sum / 10;
		i--;
		j--;
	}

	// Them so 1 o dau neu co carry
	if (carry > 0) {
		char* temp = new char[res._size + 1];
		temp[0] = carry;

		for (int i = 0; i < res._size; i++) {
			temp[i + 1] = res._arr[i];
		}

		delete[] res._arr;
		res._arr = temp;
		res._size++;
	}

	return res;
}

SoNguyenLon operator+(const int& n, const SoNguyenLon& snl) {
	return SoNguyenLon(n) + snl;
}

bool SoNguyenLon::operator>(const SoNguyenLon& snl) {
	if (_size > snl._size) {
		return true;
	}
	else if (_size == snl._size) {
		for (int i = 0; i < _size; i++) {
			if (_arr[i] > snl._arr[i]) {
				return true;
			}
			else if (_arr[i] < snl._arr[i]) {
				return false;
			}
		}
	}
	return false;
}

void SoNguyenLon::capNhatSNLMax() {
	if (_SNLMax == nullptr || *this > *_SNLMax) {
		_SNLMax = this;
	}
}

SoNguyenLon SoNguyenLon::SNLMax() {
	return *_SNLMax;
}

ostream& operator<<(ostream& os, const SoNguyenLon& snl) {
	for (int i = 0; i < snl._size; i++) {
		os << (int)snl._arr[i];
	}
	return os;
}

SoNguyenLon* SoNguyenLon::_SNLMax = nullptr;

int main() {
	SoNguyenLon snl1;
	SoNguyenLon snl2(1234567);
	SoNguyenLon snl3(3, 14);
	SoNguyenLon snl4(9, 20);
	SoNguyenLon snl5 = snl3 - snl2;
	SoNguyenLon snl6 = 45678910 - snl2;
	SoNguyenLon snl7 = snl4 - snl3 + 123456789;

	cout << snl1 << endl << snl2 << endl << snl3 << endl;
	cout << snl4 << endl << snl5 << endl << snl6 << endl;
	cout << snl7 << endl << endl;

	cout << "SoNguyenLon Max:" << endl;
	cout << SoNguyenLon::SNLMax() << endl;
	system("pause");
	return 0;
}