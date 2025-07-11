#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Component {
protected:
	string name;

public:
	virtual ~Component() {}
	string getName();
	virtual double getSize() = 0;
	virtual void addComponent(Component* c) = 0;
};

class File : public Component {
private:
	double size;	// Unit: KB
	string type;	// "binary" or "text"

public:
	File(string name, double size, string type);
	File(const File& f);
	~File() {}
	double getSize();
	void addComponent(Component* c);
};

class Shortcut : public Component {
private:
	Component* target;	// pointer to the target file/folder

public:
	Shortcut(string name, Component* target);
	Shortcut(const Shortcut& s);
	~Shortcut() {}
	double getSize();
	void addComponent(Component* c);
};

class Folder : public Component {
private:
	vector<Component*> components;

public:
	Folder(string name);
	Folder(const Folder& f);
	~Folder();
	double getSize();
	void addComponent(Component* c);
};

class Disk : public Component {
private:
	double capacity;	// Unit: KB
	double usedSpace;
	vector<Component*> components;

public:
	Disk(string name, int capacity, int usedSpace = 0);
	Disk(const Disk& d);
	~Disk();
	double getCapacity();
	// b.
	double getFreeSpace();
	double getSize();
	void addComponent(Component* c);
};

class FS {
private:
	vector<Disk*> disks;

public:
	FS() {}
	FS(const FS& fs);
	~FS();
	void addDisk(Disk* d);
	void showDisks();
};