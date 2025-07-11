/*
Ho va ten: Nguyen Thai Bao
MSSV: 23120023
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>

using namespace std;

class ListDHTT {

public:
	class DongHoTT {
	private:
		int _m;
		int _s;
		int _ms;
		void chuanHoa();

	public:

		DongHoTT();
		DongHoTT(int, int, int);
		DongHoTT(const char*);
		DongHoTT(int, int);
		DongHoTT(int);
		~DongHoTT();

		DongHoTT& operator++() {
			_s++;
			chuanHoa();
			return *this;
		}

		DongHoTT operator++(int) {
			DongHoTT temp;
			temp._m = _m;
			temp._ms = _ms;
			temp._s = _s;

			_s++;
			chuanHoa();

			return temp;
		}

		friend ostream& operator<< (ostream& os, const DongHoTT& dhtt) {
			os << setw(3) << setfill('0') << dhtt._m << ":";
			os << setw(2) << setfill('0') << dhtt._s << ":";
			os << setw(3) << setfill('0') << dhtt._ms;

			return os;
		}

		DongHoTT operator+(const DongHoTT& dhtt) {
			DongHoTT res;
			res._m = _m + dhtt._m;
			res._s = _s + dhtt._s;
			res._ms = _ms + dhtt._ms;

			res.chuanHoa();
			return res;
		}

		friend DongHoTT operator+(const int& x, const DongHoTT& dhtt) {
			return DongHoTT(x) + dhtt;
		}

		bool operator>(const DongHoTT& dhtt) {
			if (_m > dhtt._m) {
				return true;
			}
			else if (_m == dhtt._m) {
				if (_s > dhtt._s) {
					return true;
				}
				else if (_s == dhtt._s) {
					if (_ms > dhtt._ms) {
						return true;
					}
				}
			}

			return false;
		}

		friend bool funcCountIf(const DongHoTT&);	

	};

	
	
private:
	struct Node {
		DongHoTT data;
		Node* pNext;
	};
	Node* _pHead, *_pTail;
	int _n;
	static Node* createNode(DongHoTT data) {
		Node* x = new Node{ data, nullptr };
		return x;
	}

public:
	ListDHTT() {
		_pHead = _pTail = nullptr;
		_n = 0;
	}

	~ListDHTT() {
		Node* p = _pHead;
		while (p != NULL) {
			Node* temp = p;
			p = p->pNext;
			delete temp;
		}
	}

	void addTail(const char* str) {
		DongHoTT dhtt(str);
		Node* node = createNode(dhtt);
		if (_pHead == NULL) {
			_pHead = node;
			_pTail = _pHead;
		}
		else {
			_pTail->pNext = node;
			_pTail = node;
		}
		_n++;
	}

	void AddTail(const DongHoTT& dhtt) {
		Node* node = createNode(dhtt);
		if (_pHead == NULL) {
			_pHead = node;
			_pTail = _pHead;
		}
		else {
			_pTail->pNext = node;
			_pTail = node;
		}
		_n++;
	}

	friend ostream& operator<< (ostream& os, const ListDHTT& list) {
		Node* cur = list._pHead;
		while (cur != NULL) {
			cout << cur->data << endl;
			cur = cur->pNext;
		}

		return os;
	}

	class Iterator {
	public:
		/*using value_type = DongHoTT;
		using pointer = DongHoTT*;
		using reference = DongHoTT&;
		using difference_type = std::ptrdiff_t;
		using iterator_category = std::forward_iterator_tag;*/

		using value_type = DongHoTT;
		using pointer = DongHoTT*;
		using reference = DongHoTT&;
		using difference_type = std::ptrdiff_t;
		using iterator_category = std::forward_iterator_tag;
	private:
		Node* cur;
		Iterator(Node* p) : cur(p) {}
		friend class ListDHTT;
	public:
		Iterator() : cur(nullptr) {}
		Iterator& operator++() {
			if (cur != nullptr) {
				cur = cur->pNext;
			}
			return *this;
		}
		bool operator==(const Iterator& other) const {
			return cur == other.cur;
		}
		bool operator!=(const Iterator& other) const {
			return !(*this == other);
		}
		const DongHoTT& operator*() const {
			return cur->data;
		}
	};

	// Iterator access
	Iterator begin() {
		return Iterator(_pHead);
	}

	Iterator end() {
		return Iterator(nullptr);
	}


};

void ListDHTT::DongHoTT::chuanHoa() {
	_m = (_m >= 0) ? _m : -_m;
	_s = (_s >= 0) ? _s : -_s;
	_ms = (_ms >= 0) ? _ms : -_ms;

	while (_ms >= 1000) {
		_s += 1;
		_ms -= 1000;
	}

	while (_s >= 60) {
		_m += 1;
		_s -= 60;
	}
}

ListDHTT::DongHoTT::DongHoTT() {
	_m = 0;
	_s = 0;
	_ms = 0;
}

ListDHTT::DongHoTT::DongHoTT(int m, int s, int ms) {
	_m = m;
	_s = s;
	_ms = ms;
	chuanHoa();	
}

ListDHTT::DongHoTT::DongHoTT(const char* s) {
	int len = strlen(s);
	char* temp = new char[len + 1];
	strcpy_s(temp, len + 1, s);

	char* context;
	char* token = strtok_s(temp, ":", &context);

	if (token != NULL) {
		_m = atoi(token);
	}

	token = strtok_s(nullptr, ":", &context);
	if (token != NULL) {
		_s = atoi(token);
	}

	token = strtok_s(nullptr, ":", &context);
	if (token != NULL) {
		_ms = atoi(token);
	}
	
	chuanHoa();
}



ListDHTT::DongHoTT::DongHoTT(int s, int ms) {
	_m = 0;
	_s = s;
	_ms = ms;
	chuanHoa();
}

ListDHTT::DongHoTT::DongHoTT(int ms) {
	_m = 0;
	_s = 0;
	_ms = ms;
	chuanHoa();
}

ListDHTT::DongHoTT::~DongHoTT() {}

bool funcCountIf(const ListDHTT::DongHoTT& dhtt) {
	if (dhtt._m >= 60) {
		return true;
	}
	return false;
}



int main() {
	ListDHTT list;
	ListDHTT::DongHoTT dhtt1(20, 70, -2076), dhtt2("13:31:94"), dhtt3(200, 8060), dhtt4(40001);

	cout << "dhtt1: " << dhtt1 << endl;
	cout << "dhtt2: " << dhtt2 << endl;
	cout << "dhtt3: " << dhtt3 << endl;
	cout << "dhtt4: " << dhtt4 << endl;

	list.AddTail("1:2:3");
	list.AddTail(dhtt1);
	list.AddTail(dhtt2);
	list.AddTail(dhtt3);
	list.AddTail(dhtt4);
	cout << "List:\n" << list << endl;

	list.AddTail(10000 + ++dhtt1 + dhtt2++);
	list.AddTail(10000 + dhtt1++ + dhtt2++);
	cout << "dhtt1: " << dhtt1 << endl;
	cout << "dhtt2: " << dhtt2 << endl;
	cout << "List:\n" << list << endl;

	int nCI = std::count_if(list.begin(), list.end(), funcCountIf);
	cout << "So DHTT co phut >= 60: " << nCI << endl;

	ListDHTT::DongHoTT dhttMax = *list.begin();
	std::for_each(list.begin(), list.end(), [&dhttMax](ListDHTT::DongHoTT dhtt) {
		if (dhtt > dhttMax) {
			dhttMax = dhtt;
		}
	});
	cout << "DHTT lon nhat: " << dhttMax << endl;

	system("pause");
	return 0;
}