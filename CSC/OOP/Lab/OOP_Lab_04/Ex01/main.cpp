#include <iostream>
#include <cstring>

using namespace std;

class CString {
private:
	char* _mang;

public:
	CString();
	CString(const char*);
	~CString();

	char& operator[](const int&);
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
	cout << cs1 << endl;
	cout << "cs1[" << iN << "] = " << cs1[iN] << endl;
	cs1[iN] = 'N';
	cout << cs1 << endl;
	system("pause");
	return 0;
}