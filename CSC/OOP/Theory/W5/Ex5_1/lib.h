#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>

using namespace std;

// ADDRESS
class Address {
private:
	string street, city, state;
public:
	Address();
	Address(const Address& addr);
	Address(const string& street, const string& city, const string& state);
	void display();
	Address& operator=(const Address& addr);
};

// STUDENT
class Student {
private:
	string name;
	int studentID;
	float gpa;
	Address addr;

public:
	Student();
	Student(const Student& student);
	Student(const string&, const int&, const float&, const Address&);
	string getGrade();
	void display();
};

// EXCHANGE STUDENT
class ExchangeStudent : public Student {
private:
	string country;
	int duration;

public:
	ExchangeStudent();
	ExchangeStudent(const ExchangeStudent& student);
	ExchangeStudent(const string&, const int&, const float&, const Address&, const string&, const int&);
	ExchangeStudent(const Student&, const string&, const int&);
	void setDuration(const int&);
	void display();
};

#endif // !LIB_H
