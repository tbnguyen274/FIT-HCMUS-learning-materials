// 23120023

#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Officer {
protected:
	string id;
	string name;
	string dob;
	string address;
	double salaryCoef;
	string startDate;
	double basicSalary;
	double salary;

public:
	Officer();
	Officer(string id, string name, string dob, string address, double salaryCoef, string startDate);
	Officer(const Officer& officer);
	virtual ~Officer();

	void setId(string id);
	void setName(string name);
	void setDob(string dob);
	void setAddress(string address);
	void setSalaryCoef(double salaryCoef);
	void setStartDate(string startDate);

	virtual double calcSalary() = 0;
	double getSalaryCoef();
};

class Manager : public Officer {
private:
	vector<Officer*> managedOfficers;
public:
	Manager();
	Manager(string id, string name, string dob, string address, double salaryCoef, string startDate);
	Manager(const Manager& manager);
	~Manager();

	double calcSalary() override {
		salary = basicSalary * salaryCoef;
	}

	void addOfficer(Officer* officer) {
		managedOfficers.push_back(officer);
	}

	int getManagedOfficersCount() {
		return managedOfficers.size();
	}
};

class Programmer : public Officer {
private:
	double overtime;
public:
	Programmer();
	Programmer(string id, string name, string dob, string address, double salaryCoef, string startDate);
	Programmer(const Programmer& programmer);
	~Programmer();
	double calcSalary() override {
		salary = basicSalary * salaryCoef + overtime;
	}
};

class Designer : public Officer {
private:
	double bonus;

public:
	Designer();
	Designer(string id, string name, string dob, string address, double salaryCoef, string startDate);
	Designer(const Designer& designer);
	~Designer();
	double calcSalary() override {
		salary = basicSalary * salaryCoef + bonus;
	}
};

class Tester : public Officer {
private:
	int errorCount;

public:
	Tester();
	Tester(string id, string name, string dob, string address, double salaryCoef, string startDate);
	Tester(const Tester& tester);
	~Tester();
	double calcSalary() override {
		salary = basicSalary * salaryCoef + errorCount * 200000;
	}
};

class Company {
private:
	vector<Officer*> officers;

public:
	Company();
	~Company();

	// a
	void addOfficer(Officer* officer) {
		officers.push_back(officer);
	}

	// b
	double calcTotalSalary() {
		double total = 0;
		for (int i = 0; i < officers.size(); i++) {
			total += officers[i]->calcSalary();
		}
		return total;
	}
	
};

#endif // !LIB_H
