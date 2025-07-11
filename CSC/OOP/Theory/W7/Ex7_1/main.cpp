#include "lib.h"

int main() {
	Company company;

	Engineer* eng1 = new Engineer(50000, 10, 100);
	Engineer* eng2 = new Engineer(60000, 20, 150);
	Manager* mng1 = new Manager(80000, 5, 200);
	Manager* mng2 = new Manager(90000, 10, 250);

	company.addEmployee(eng1);
	company.addEmployee(eng2);
	company.addEmployee(mng1);
	company.addEmployee(mng2);

	// Describe work for all employees
	cout << "Ask each employee to describe their work:" << endl;
	company.describeAll();

	// Get all roles
	cout << "\nIdentify the role of each employee:" << endl;
	company.getAllRoles();

	// Calculate total salary
	double totalSalary = company.calculateTotalSalary();
	cout << "\nCalculate the total employees' salary: " << totalSalary << endl;

	return 0;
}