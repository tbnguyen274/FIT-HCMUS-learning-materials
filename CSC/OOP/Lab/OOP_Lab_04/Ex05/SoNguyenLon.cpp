#include "SoNguyenLon.h"

SoNguyenLon::SoNguyenLon() {
	_size = 1;
	_list.AddHead(0);
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
	if (n < 0) {
		_size = 1;
		_list.AddHead(0);
		return;
	}

	_size = countDigit(n);
	int temp = n;
	for (int i = _size - 1; i >= 0; i--) {
		_list.AddHead(temp % 10);
		temp /= 10;
	}
}

SoNguyenLon::SoNguyenLon(const int& n, const int& size) {
	if (size < 1 || size > 100 || n < 0) {
		_size = 1;
		_list.AddHead(0);
		return;
	}

	_size = size;
	for (int i = 0; i < _size; i++) {
		_list.AddHead(n);
	}
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon& snl) {
	_size = snl._size;

	for (int i = 0; i < _size; i++) {
		int digit = snl._list[i];
		_list.AddTail(digit);
	}
}

SoNguyenLon::~SoNguyenLon() {
	// LinkedList tu goi destructor cua no
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
		int sub = _list[i] - carry;
		if (j >= 0) {
			sub -= snl._list[j];
		}
		if (sub < 0) {
			sub += 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		res._list[i] = sub;
		i--;
		j--;
	}

	// Xoa so 0 o dau
	while (res._list[0] == 0 && res._size > 1) {
		res._list.RemoveHead();
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
		int sum = _list[i] + carry;
		if (j >= 0) {
			sum += snl._list[j];
		}
		res._list[i] = sum % 10;
		carry = sum / 10;
		i--;
		j--;
	}

	// Them so 1 o dau neu co nho
	if (carry > 0) {
		res._list.AddHead(carry);
		res._size++;
	}

	return res;
}

SoNguyenLon operator+(const int& n, const SoNguyenLon& snl) {
	return SoNguyenLon(n) + snl;
}

SoNguyenLon SoNguyenLon::operator*(const SoNguyenLon& snl) {
	if (_size == 1 && _list[0] == 0) {
		return SoNguyenLon(0);
	}

	if (snl._size == 1 && snl._list[0] == 0) {
		return SoNguyenLon(0);
	}

	SoNguyenLon res(0, _size + snl._size);

	for (int i = _size - 1; i >= 0; i--) {
		int carry = 0;
		int j = snl._size - 1;
		int k = res._size - 1 - (_size - 1 - i);

		while (j >= 0) {
			int mul = _list[i] * snl._list[j] + carry + res._list[k];
			res._list[k] = mul % 10;
			carry = mul / 10;
			j--;
			k--;
		}

		if (carry > 0) {
			res._list[k] += carry;
		}
	}

	// Xoa so 0 o dau
	while (res._list[0] == 0 && res._size > 1) {
		res._list.RemoveHead();
		res._size--;
	}

	return res;
}

ostream& operator<<(ostream& os, const SoNguyenLon& snl) {
	for (int i = 0; i < snl._size; i++) {
		os << snl._list[i];
	}
	return os;
}