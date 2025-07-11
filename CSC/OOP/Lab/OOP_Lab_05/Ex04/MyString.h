#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class MyString {
private:
    char* data;

public:
    MyString();
    MyString(const char*);
    MyString(const MyString&);
    ~MyString();

    MyString& operator=(const MyString&);
    MyString operator+(const MyString&);
    friend MyString operator+(const char*, const MyString&);
    friend ostream& operator<<(ostream&, const MyString&);
    vector<MyString> Split(const vector<char>& delimiters, bool removeEmpty) const;
};

#endif // !MYSTRING_H
