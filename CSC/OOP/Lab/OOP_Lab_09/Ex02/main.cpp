#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

class Component {
protected:
	string _name;

public:
	Component(const string& s) {
		_name = s;
	}

	virtual int GetSize() = 0;
	void Print(ostream& os) {
		os << _name << " (" << GetSize() << ")" << endl;
	}
};

class Directory : public Component {
private:
	vector<Component*> _children;

public:
	Directory(const string& s) : Component(s) {}
	void AddChild(Component* c) {
		_children.push_back(c);
	}

	int GetSize() {
		int total = 0;
		for (int i = 0; i < _children.size(); i++) {
			total += _children[i]->GetSize();
		}
		return total;
	}
};

class File : public Component {
private:
	int _size;

public:
	File(const string& s, const int& size) : Component(s) {
		_size = abs(size);
	}

	int GetSize() {
		return _size;
	}
};


int main() {
	Directory* dRoot = new Directory("Dir root");
	Directory* dChild = new Directory("Dir child");
	dChild->AddChild(new File("File 1", 123));
	dChild->AddChild(new File("File 2", 444));
	dRoot->AddChild(dChild);
	dRoot->AddChild(new File("File 3", 7899));

	dRoot->Print(cout);

	cout << endl << endl;
	system("pause");
	return 0;
}