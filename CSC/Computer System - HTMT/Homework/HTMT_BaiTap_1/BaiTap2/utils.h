#ifndef UTILS_H
#define UTILS_H

/*
Bài tập 2:
Viết chương trình Nhập vào 2 dãy bit 8 bit (ở dạng bù 2)
Hãy thực hiện các phép tính cộng, trừ,nhân, chia trên 2 dãy bit đã nhập 
(Lưu ý: thực hiện theo thuật toán đã học).
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

//CONSTANTS
const int BIT_LENGTH = 8;
const vector<bool> ZERO(BIT_LENGTH, 0);
const vector<bool> MINUS_128 = { 1, 0, 0, 0, 0, 0, 0, 0 };

//FUNCTIONS
void normalizeBitString(string& bitArray);

vector<bool> convertBitStringToArray(string bitString);

string convertBitArrayToString(vector<bool> bitArray);

int convertBitArrayToInt(vector<bool> arr);

bool isIdentical(vector<bool> bitString1, vector<bool> bitString2);

bool addBitArray(vector<bool> bitString1, vector<bool> bitString2, vector<bool>& result);

vector<bool> calcTwoComplement(vector<bool> bitString);

bool subtractBitArray(vector<bool> bitString1, vector<bool> bitString2, vector<bool>& result);

void printBitArray(vector<bool> arr);

bool isSameSign(vector<bool> bitString1, vector<bool> bitString2);

vector<bool> multiplyBitArray(vector<bool> bitString1, vector<bool> bitString2);

vector<vector<bool>> divideBitArray(vector<bool> dividend, vector<bool> divisor);

bool isPositive(vector<bool> bitString);

bool isNegative(vector<bool> bitString);

#endif