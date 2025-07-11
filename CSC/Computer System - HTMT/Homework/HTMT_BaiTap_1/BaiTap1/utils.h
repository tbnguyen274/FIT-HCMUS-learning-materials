#ifndef UTILS_H
#define UTILS_H

/*
Bài tập 1.
Sử dụng kỹ thuật xử lý bit viết chương trình thực hiện các yêu cầu sau:

- Nhập vào số nguyên X (4 byte) có dấu hãy "đọc" dãy bit nhị phân của X và xuất ra màn hình.

- Cho mảng 1 chiều A gồm 32 phần tử là các số 0 hoặc 1. Hãy xây dựng số nguyên X 4 byte có các bit
giống với các phần tử mảng A, sau đó xuất X ra màn hình.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string convertIntToBitString(int n);
vector<bool> convertBitStringToArray(string bitString);
vector<bool> convertIntToBitArray(int n);
void printBitArray(vector<bool> arr);
int convertBitArrayToInt(vector<bool> arr);
void readBitFromInt(int n);
void normalizeBitString(string& bitArray);

#endif