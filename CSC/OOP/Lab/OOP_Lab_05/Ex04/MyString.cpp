#include "MyString.h"

MyString::MyString() {
    data = nullptr;
}

MyString::MyString(const char* str) {
    if (str) {
        data = new char[strlen(str) + 1];
        strcpy_s(data, strlen(str) + 1, str);
    }
    else {
        data = nullptr;
    }
}

MyString::MyString(const MyString& ms) {
    if (ms.data) {
        int len = strlen(ms.data);
        data = new char[len + 1];
        strcpy_s(data, len + 1, ms.data);
    }
    else {
        data = nullptr;
    }
}

MyString::~MyString() {
    delete[] data;
}

MyString& MyString::operator=(const MyString& ms) {
    if (this != &ms) {
        delete[] data;
        if (ms.data) {
            int len = strlen(ms.data);
            data = new char[len + 1];
            strcpy_s(data, len + 1, ms.data);
        }
        else {
            data = nullptr;
        }
    }
    return *this;
}

MyString MyString::operator+(const MyString& ms) {
    if (!data) {
        return ms;
    }
    if (!ms.data) {
        return *this;
    }

    int len1 = strlen(data);
    int len2 = strlen(ms.data);
    char* combined = new char[len1 + len2 + 1];
    strcpy_s(combined, len1 + 1, data);
    strcat_s(combined, len1 + len2 + 1, ms.data);

    int count = 0;
    for (int i = 0; i < len1 + len2; ++i) {
        if (combined[i] < 'a' || combined[i] > 'z') {
			// dua cac ky tu khong phai la chu cai len dau
            char temp = combined[i];
			for (int j = i - 1; j >= count; j--) {
                combined[j + 1] = combined[j];
            }
            combined[count++] = temp;
        }
    }

    MyString result(combined);
    delete[] combined;
    return result;
}

MyString operator+(const char* str, const MyString& ms) {
    MyString temp(str);
    return temp + ms;
}

ostream& operator<<(ostream& os, const MyString& ms) {
    if (ms.data) {
        os << ms.data;
    }

    return os;
}

vector<MyString> MyString::Split(const vector<char>& delims, bool removeEmpty) const {
    vector<MyString> result;
    if (data == nullptr) {
        return result;
    }

    int start = 0, end = 0;
    int len = strlen(data);

    while (end <= len) {
        if (end == len || find(delims.begin(), delims.end(), data[end]) != delims.end()) {
            if (end > start || !removeEmpty) {
                char* token = new char[end - start + 1];
                strncpy_s(token, end - start + 1, data + start, end - start);
                token[end - start] = '\0';
                result.emplace_back(token);
                delete[] token;
            }
            start = end + 1;
        }
        ++end;
    }

    return result;
}