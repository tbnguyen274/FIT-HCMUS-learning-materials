#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Fraction {
private:
	int num;
	int denom;

public:
	Fraction();
	Fraction(int _num, int _denom);
	Fraction operator+(Fraction frac);
	Fraction operator+(int a);
	bool operator==(Fraction frac);
	bool operator==(int a);
	void print() {
		cout << num << "/" << denom << endl;
	}

	int getNum() {
		return num;
	}

	int getDenom() {
		return denom;
	}

	Fraction& operator+=(const Fraction& frac);
	Fraction& operator+=(const int& a);
	Fraction& operator++();	// prefix
	Fraction operator++(int); // postfix

	friend ostream& operator<<(ostream& os, const Fraction& frac) {
		os << frac.num << "/" << frac.denom;
		return os;
	}

	Fraction& operator=(const Fraction& frac) {
		num = frac.num;
		denom = frac.denom;
		return *this;
	}
};

Fraction::Fraction() {
	num = 0;
	denom = 1;
}

Fraction::Fraction(int _num, int _denom) {
	num = _num;
	denom = _denom;
}

Fraction Fraction::operator+(Fraction frac) {
	int resNum = this->num * frac.denom + frac.num * this->denom;
	int resDenom = this->denom * frac.denom;
	return Fraction(resNum, resDenom);
}

Fraction Fraction::operator+(int a) {
	int resNum = this->num + this->denom * a;
	return Fraction(resNum, this->denom);
}

bool Fraction::operator==(Fraction frac) {
	int product1 = this->num * frac.denom;
	int product2 = this->denom * frac.num;
	
	return product1 == product2;
}

bool Fraction::operator==(int a) {
	return this->num == a * this->denom;
}

Fraction operator+(int n, Fraction frac) {
	int resNum = frac.getNum() + frac.getDenom() * n;
	return Fraction(resNum, frac.getDenom());
}

Fraction& Fraction::operator+=(const Fraction& frac) {
	*this = *this + frac;
	return *this;
}

Fraction& Fraction::operator+=(const int& a) {
	*this = *this + a;
	return *this;
}

Fraction& Fraction::operator++() {
	num += denom;
	return *this;
}

Fraction Fraction::operator++(int) {
	Fraction temp = *this;
	num += denom;
	return temp;
}


#include <cstdio>

int main() {
	/*Fraction f1(1, 2);
	Fraction f2(4, 7);
	Fraction f3 (4, 8);
	Fraction f4(10, 5);
	int a = 2;

	Fraction res1 = f1 + f2;
	res1.print();
	Fraction res2 = f1 + a;
	res2.print();
	cout << (f1 == f3) << endl;
	cout << (f4 == a) << endl;

	Fraction res3 = a + f1;
	res3.print();

	f1 += res3;
	f1.print();
	f1 += a;
	f1.print();*/

	FILE* fr = fopen("test.txt", "rb");
	if (fr == NULL) {
		cout << "File not found" << endl;
		return 1;
	}

	// use fread to read the file, no relation to fraction
	char name[50], message[100];
	int year;

	/*while (std::fscanf(fr, "\"%[^\"]\", \"%[^\"]\", %d\n", name, message, &year) == 3) {
		std::printf("Name: %s, Message: %s, Year: %d\n", name, message, year);
	}*/

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), fr) != NULL) {
		int res = sscanf(buffer, "\"%[^\"]\", \"%[^\"]\", %d\n", name, message, &year);
		cout << "Name: " << name << ", Message: " << message << ", Year: " << year << endl;
	}

	fgetc(fr);
	fclose(fr); 

	return 0;
}