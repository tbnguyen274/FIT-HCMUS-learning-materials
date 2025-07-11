#include <iostream>
#include <cstring>

using namespace std;

class CString {
private:
	char* _mang;

public:
	CString();
	CString(const char*);
	CString(const CString&);
	~CString();

	char& operator[](const int&);
	CString& operator=(const CString&);
	friend ostream& operator<<(ostream&, const CString&);
};

CString::~CString() {
	if (_mang != nullptr) {
		delete[] _mang;
	}
}

CString::CString() {
	_mang = nullptr;
}

CString::CString(const char* str) {
	int len = strlen(str);
	_mang = new char[len + 1];
	strcpy_s(_mang, len + 1, str);
}

CString::CString(const CString& cs) : CString(cs._mang) {
	cout << "The copy constructor was called." << endl;
}

CString& CString::operator=(const CString& cs) {
	cout << "The operator= was called." << endl;
	if (_mang != nullptr) {
		delete[] _mang;
	}
	int len = strlen(cs._mang) + 1;
	_mang = new char[len];
	strcpy_s(_mang, len, cs._mang);
	return *this;
}

char& CString::operator[](const int& i) {
	int len = strlen(_mang);
	if (i < 0 || i >= len) {
		throw exception("out of range");
	}
	return _mang[i];
}

ostream& operator<<(ostream& os, const CString& cs) {
	os << cs._mang;
	return os;
}

int main() {
	const int iN = 2;
	CString cs1("cs1_content");
	cout << "cs2(cs1)" << endl;
	CString cs2(cs1);
	cs2[iN] = '2';
	cout << "cs3 = cs1" << endl;
	CString cs3 = cs1;
	cs3[iN] = '3';
	cout << cs1 << endl << cs2 << endl << cs3 << endl;
	cout << "cs3 = cs2" << endl;
	cs3 = cs2;
	cout << cs3 << endl;
	system("pause");
	return 0;
}