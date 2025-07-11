#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string name;
	double math, physics, chem;

public:
	void inputScore(double& score);
	void input();
	void output();
	string getName();
	void setName(string name);
	double getMath();
	void setMath(double math);
	double getPhysics();
	void setPhysics(double physics);
	double getChem();
	void setChem(double chem);
	double calulateGPA();
	char grade();
};

#endif // !LIB_H
