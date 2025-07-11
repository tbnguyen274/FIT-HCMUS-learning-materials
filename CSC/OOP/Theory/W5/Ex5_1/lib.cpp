#include "lib.h"

// ADDRESS
Address::Address() {
	street = "";
	city = "";
	state = "";
}

Address::Address(const Address& addr) {
	this->street = addr.street;
	this->city = addr.city;
	this->state = addr.state;
}

Address::Address(const string& street, const string& city, const string& state) {
	this->street = street;
	this->city = city;
	this->state = state;
}

void Address::display() {
	cout << "Address: " << street << ", " << city << ", " << state << endl;
}

Address& Address::operator=(const Address& addr) {
	street = addr.street;
	city = addr.city;
	state = addr.state;
	return *this;
}

// STUDENT
Student::Student() {
	name = "";
	studentID = 0;
	gpa = 0.0;
	addr = Address();
}

Student::Student(const Student& student) {
	this->name = student.name;
	this->studentID = student.studentID;
	this->gpa = student.gpa;
	this->addr = student.addr;
}

Student::Student(const string& name, const int& studentID, const float& gpa, const Address& addr) {
	this->name = name;
	this->studentID = studentID;
	this->gpa = gpa;
	this->addr = addr;
}

string Student::getGrade() {
	if (gpa >= 3.5) return "A";
	else if (gpa >= 3.0) return "B";
	else if (gpa >= 2.5) return "C";
	else if (gpa >= 2.0) return "D";
	else return "F";
}

void Student::display() {
	cout << "Name: " << name << endl;
	cout << "Student ID: " << studentID << endl;
	cout << "GPA: " << gpa << endl;
	addr.display();
}

// EXCHANGE STUDENT
ExchangeStudent::ExchangeStudent() : Student() {
	country = "";
	duration = 0;
}

ExchangeStudent::ExchangeStudent(const ExchangeStudent& student) : Student(student) {
	this->country = student.country;
	this->duration = student.duration;
}

ExchangeStudent::ExchangeStudent(const string& name, const int& studentID, const float& gpa, const Address& addr, const string& country, const int& duration)
	: Student(name, studentID, gpa, addr) {
	this->country = country;
	this->duration = duration;
}

ExchangeStudent::ExchangeStudent(const Student& student, const string& country, const int& duration)
	: Student(student) {
	this->country = country;
	this->duration = duration;
}

void ExchangeStudent::setDuration(const int& duration) {
	this->duration = duration;
}

void ExchangeStudent::display() {
	Student::display();
	cout << "Country: " << country << endl;
	cout << "Duration: " << duration << " months" << endl;
}