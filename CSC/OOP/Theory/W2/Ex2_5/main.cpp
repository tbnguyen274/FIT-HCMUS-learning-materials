#include "lib.h"

int main() {
	Student s1, s2;

	// Student 1
	s1.input();
	s1.output();
	cout << "GPA: " << s1.calulateGPA() << endl;
	cout << "Grade: " << s1.grade() << endl;
	cout << endl;

	// Student 2
	s2.setName("Nguyen Thai Bao");
	s2.setMath(10);
	s2.setPhysics(9.3);
	s2.setChem(8.72);
	
	double chem;
	cout << "Enter updated chemistry score: ";
	cin >> chem;
	s2.setChem(chem);
	cout << endl;
	
	cout << "Name: " << s2.getName() << endl;
	cout << "Math: " << s2.getMath() << endl;
	cout << "Physics: " << s2.getPhysics() << endl;
	cout << "Chemistry: " << s2.getChem() << endl;
	cout << "GPA: " << s2.calulateGPA() << endl;
	cout << "Grade: " << s2.grade() << endl;
	return 0;
}