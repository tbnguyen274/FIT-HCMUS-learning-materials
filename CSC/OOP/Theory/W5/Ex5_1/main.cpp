#include "lib.h"

int main() {
	// Address
	Address addr1("123 Main St", "Los Angeles", "CA");
	Address addr2("456 Elm St", "New York", "NY");

	// Student
	Student student1("Alice", 101, 3.8f, addr1);
	string grade1 = student1.getGrade();
	student1.display();
	cout << "Grade: " << grade1 << endl;
	cout << endl;

	// Exchange Student
	ExchangeStudent student2("Liam", 202, 3.9f, addr2, "Germany", 6);
	string grade2 = student2.getGrade();
	student2.setDuration(9);
	student2.display();
	cout << "Grade: " << grade2 << endl;
}