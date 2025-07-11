// MSSV: 23120023

#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Point {
private:
	int x;
	int y;

public:
	Point();
	Point(int x, int y);
	Point(const Point& point);
	~Point();

	int getX();
	int getY();
};

class Object {
public:
	Object();
	Object(const Object& object);
	virtual ~Object();

	virtual bool equals(Object o) = 0;

};

class Shape : public Object {
protected:
	string color;
	string painter;

public:
	Shape();
	Shape(string color, string painter);
	Shape(const Shape& shape);
	virtual ~Shape();
	void setColor(string color);
	void setPainter(string painter);
	
	virtual void print() = 0;
};

class Line : public Shape {
private:
	Point start;
	Point end;

public:
	Line();
	Line(string color, string painter, Point start, Point end);
	Line(const Line& line);
	~Line();

	void print() override {
		cout << "Line: " << start.getX() << ", " << start.getY() << " - " << end.getX() << ", " << end.getY() << endl;
		cout << "Color: " << color << ", Painter: " << painter << endl;
	}
};

class Circle : public Shape {
private:
	Point center;
	int radius;

public:
	Circle();
	Circle(string color, string painter, Point center, int radius);
	Circle(const Circle& circle);
	~Circle();

	void print() override {
		cout << "Circle: Center(" << center.getX() << ", " << center.getY() << "), Radius: " << radius << endl;
		cout << "Color: " << color << ", Painter: " << painter << endl;
	}
};



class Rectangle : public Shape {
private:
	Point topLeft;
	Point bottomRight;

public:
	Rectangle();
	Rectangle(string color, string painter, Point tl, Point br);
	Rectangle(const Rectangle& rectangle);
	~Rectangle();

	void print() override {
		cout << "Rectangle: TopLeft(" << topLeft.getX() << ", " << topLeft.getY() << "), BottomRight(" << bottomRight.getX() << ", " << bottomRight.getY() << ")" << endl;
		cout << "Color: " << color << ", Painter: " << painter << endl;
	}

	bool equals(Object o) override {
		if (this == &o) return true;

		Rectangle* r1 = (Rectangle*)&o;
		if (!r1) return false;

		return topLeft.getX() == r1->topLeft.getX() &&
			topLeft.getY() == r1->topLeft.getY() &&
			bottomRight.getX() == r1->bottomRight.getX() &&
			bottomRight.getY() == r1->bottomRight.getY() &&
			color == r1->color &&
			painter == r1->painter;
	}
};

class Image {
private:
	vector<Shape*> shapes;

public:
	Image();
	Image(const Image& image);
	~Image();

	void addShape(Shape* shape) {
		shapes.push_back(shape);
	}

	void print() {
		cout << "Information about all shapes in the image:\n";
		for (int i = 0; i < shapes.size(); i++) {
			shapes[i]->print();
		}
	}
};

