#include "lib.h"

// COMPONENT
string Component::getName() {
	return name;
}

// FILE
File::File(string name, double size, string type) {
	this->name = name;
	this->size = size;
	this->type = type;
}

File::File(const File& f) {
	this->name = f.name;
	this->size = f.size;
	this->type = f.type;
}

double File::getSize() {
	return size;
}

void File::addComponent(Component* c) {
	cout << "Cannot add component to a file." << endl;
}

// SHORTCUT
Shortcut::Shortcut(string name, Component* target) {
	this->name = name;
	this->target = target;
}

Shortcut::Shortcut(const Shortcut& s) {
	this->name = s.name;
	this->target = s.target;
}

double Shortcut::getSize() {
	return 1;
}

void Shortcut::addComponent(Component* c) {
	cout << "Cannot add component to a shortcut." << endl;
}

// FOLDER
Folder::Folder(string name) {
	this->name = name;
}

Folder::Folder(const Folder& f) {
	this->name = f.name;
	for (int i = 0; i < f.components.size(); i++) {
		components.push_back(f.components[i]);
	}
}

Folder::~Folder() {
	for (int i = 0; i < components.size(); i++) {
		delete components[i];
	}
}

double Folder::getSize() {
	double total = 0;
	for (int i = 0; i < components.size(); i++) {
		total += components[i]->getSize();
	}
	return total;
}

void Folder::addComponent(Component* c) {
	components.push_back(c);
}

// DISK
Disk::Disk(string name, int capacity, int usedSpace) {
	this->name = name;
	this->capacity = capacity;
	this->usedSpace = usedSpace;
}

Disk::Disk(const Disk& d) {
	this->name = d.name;
	this->capacity = d.capacity;
	this->usedSpace = d.usedSpace;
	for (int i = 0; i < d.components.size(); i++) {
		components.push_back(d.components[i]);
	}
}

Disk::~Disk() {
	for (int i = 0; i < components.size(); i++) {
		delete components[i];
	}
}

double Disk::getCapacity() {
	return capacity;
}

double Disk::getFreeSpace() {
	return capacity - usedSpace;
}

double Disk::getSize() {
	return usedSpace;
}

void Disk::addComponent(Component* c) {
	if (usedSpace + c->getSize() <= capacity) {
		components.push_back(c);
		usedSpace += c->getSize();
	}
	else {
		cout << "Not enough space on disk " << name << " to add " << c->getName() << "." << endl;
	}
}

// FILE SYSTEM
FS::FS(const FS& fs) {
	for (int i = 0; i < fs.disks.size(); i++) {
		disks.push_back(fs.disks[i]);
	}
}

FS::~FS() {
	for (int i = 0; i < disks.size(); i++) {
		delete disks[i];
	}
}

void FS::addDisk(Disk* d) {
	disks.push_back(d);
}

void FS::showDisks() {
	if (disks.empty()) {
		cout << "No disks available." << endl;
		return;
	}

	cout << "--- File System Information ---\n\n";
	cout << "Total Disks: " << disks.size() << endl << endl;
	for (int i = 0; i < disks.size(); ++i) {
		cout << "Disk Name: " << disks[i]->getName() << endl;
		cout << "Capacity: " << disks[i]->getCapacity() << " KB" << endl;
		cout << "Used Space: " << disks[i]->getSize() << " KB" << endl;
		cout << "Free Space: " << disks[i]->getFreeSpace() << " KB" << endl;
		cout << endl;
	}
}