#ifndef CSTRING_H
#define CSTRING_H

#include "LinkedList.h"

class CString {
private:
	char* _mang;

public:
	CString();
	CString(const char*);
	CString(const CString&);
	~CString();

	CString& operator++();			// prefix
	CString operator++(int);		// postfix
	char& operator[](const int&);
	CString& operator=(const CString&);
	friend ostream& operator<<(ostream&, const CString&);
};

#endif // !CSTRING_H
