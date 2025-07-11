#include "lib.h"

Employee::Employee(int id, string name, double base, double bonusRate) {
	this->id = id;
	this->name = name;
	this->base = base;
	this->bonusRate = bonusRate;
}

Engineer::Engineer(double base, double overtimeHours, double bonusRate)
	: Employee(0, "", base, bonusRate), overtimeHours(overtimeHours) {
}

void Engineer::describeWork() {
	cout << "I work on technical projects." << endl;
}

string Engineer::getRole() {
	return "Engineer";
}

double Engineer::getSalary() {
	return base + (overtimeHours * bonusRate);
}

Manager::Manager(double base, int teamSize, double bonusRate)
	: Employee(0, "", base, bonusRate), teamSize(teamSize) {
}

void Manager::describeWork() {
	cout << "I manage a team of employees." << endl;
}

string Manager::getRole() {
	return "Manager";
}

double Manager::getSalary() {
	return base + (teamSize * bonusRate);
}

Company::~Company() {
	for (int i = 0; i < empList.size(); ++i) {
		delete empList[i];
	}
}

void Company::addEmployee(Employee* emp) {
	empList.push_back(emp);
}

void Company::describeAll() {
	for (int i = 0; i < empList.size(); ++i) {
		empList[i]->describeWork();
	}
}

void Company::getAllRoles() {
	for (int i = 0; i < empList.size(); ++i) {
		cout << empList[i]->getRole() << endl;
	}
}

double Company::calculateTotalSalary() {
	double total = 0;
	for (int i = 0; i < empList.size(); ++i) {
		total += empList[i]->getSalary();
	}
	return total;
}