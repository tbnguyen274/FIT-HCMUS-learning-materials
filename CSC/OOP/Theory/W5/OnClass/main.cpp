#include <iostream>
#include <string>

using namespace std;

// Base class
class Student
{
protected:
	string name;
	int id;
	float gpa;
public:
	Student(string name, int id, float gpa);
	string getGrade(); // A, B, C, D
};
Student::Student(string name, int id, float gpa) {
	this->name = name;
	this->id = id;
	this->gpa = gpa;
}

string Student::getGrade() {
	if (gpa >= 3.5) return "A";
	else if (gpa >= 3.0) return "B";
	else if (gpa >= 2.5) return "C";
	else if (gpa >= 2.0) return "D";
	else return "F";
}

// Derived class
class ExchangeStudent : public Student
{
private:
	string country;
	int duration; // months
public:
	ExchangeStudent(string name, int id,

		float gpa, string country, int duration);

	void setDuration(int duration);
};
ExchangeStudent::ExchangeStudent(string name,
	int id, float gpa, string country, int duration) :
	Student(name, id, gpa) {
	this->country = country;
	this->duration = duration;
}

void ExchangeStudent::setDuration(int duration) {
	this->duration = duration;
}

int main()
{
	// use Student
	Student student1("Alice", 101, 3.8);
	string grade1 = student1.getGrade();
	// use ExchangeStudent
	ExchangeStudent student2("Liam", 202, 3.9, "Germany", 6);
	string grade2 = student2.getGrade();
	cout << "Grade of student1: " << grade1 << endl;
	cout << "Grade of student2: " << grade2 << endl;
	student2.setDuration(9);
}