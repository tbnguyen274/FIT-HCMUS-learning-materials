#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
protected:
	int id;
	string name;
	double base;
	double bonusRate;

public:
	Employee(int id, string name, double base, double bonusRate);
	virtual ~Employee() {}

	virtual void describeWork() = 0;
	virtual string getRole() = 0;
	virtual double getSalary() = 0;
};

class Engineer : public Employee {
private:
	double overtimeHours;

public:
	Engineer(double base, double overtimeHours, double bonusRate);
	~Engineer() {}

	void describeWork() override;
	string getRole() override;
	double getSalary() override;
};

class Manager : public Employee {
private:
	int teamSize;

public:
	Manager(double base, int teamSize, double bonusRate);
	~Manager() {}

	void describeWork() override;
	string getRole() override;
	double getSalary() override;
};

class Company {
private:
	vector<Employee*> empList;

public:
	Company() {}
	~Company();

	void addEmployee(Employee* emp);
	void describeAll();
	void getAllRoles();
	double calculateTotalSalary();
};