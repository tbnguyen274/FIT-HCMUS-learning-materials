#include "lib.h"

void Student::inputScore(double& score) {
	do {
		cin >> score;
		if (score < 0 || score > 10) {
			cout << "Score must be between 0 and 10." << endl;
			cout << "Re-enter the score: ";
		}
	} while (score < 0 || score > 10);
}

void Student::input() {
	cout << "Enter student's name: ";
	getline(cin, this->name);

	cout << "Enter math score: ";
	this->inputScore(this->math);

	cout << "Enter physics score: ";
	this->inputScore(this->physics);

	cout << "Enter chemistry score: ";
	this->inputScore(this->chem);

	cout << endl;
}

void Student::output() {
	cout << "Name: " << this->name << endl;
	cout << "Math: " << this->math << endl;
	cout << "Physics: " << this->physics << endl;
	cout << "Chemistry: " << this->chem << endl;
}

string Student::getName() {
	return this->name;
}

void Student::setName(string name) {
	if (name == "") {
		cout << "Name cannot be empty." << endl;
		return;
	}
	this->name = name;
}

double Student::getMath() {
	return this->math;
}

void Student::setMath(double math) {
	if (math < 0 || math > 10) {
		cout << "Math score must be between 0 and 10." << endl;
		return;
	}

	this->math = math;
}

double Student::getPhysics() {
	return this->physics;
}

void Student::setPhysics(double physics) {
	if (physics < 0 || physics > 10) {
		cout << "Physics score must be between 0 and 10." << endl;
		return;
	}

	this->physics = physics;
}

double Student::getChem() {
	return this->chem;
}

void Student::setChem(double chem) {
	if (chem < 0 || chem > 10) {
		cout << "Chemistry score must be between 0 and 10." << endl;
		return;
	}

	this->chem = chem;
}

double Student::calulateGPA() {
	return (this->math + this->physics + this->chem) / 3;
}

char Student::grade() {
	double gpa = this->calulateGPA();

	if (gpa >= 9) {
		return 'A';
	}
	else if (gpa >= 7) {
		return 'B';
	}
	else if (gpa >= 5) {
		return 'C';
	}
	else {
		return 'D';
	}
}