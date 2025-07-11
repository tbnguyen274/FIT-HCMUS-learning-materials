#include <iostream>
#include <string>

using namespace std;

class PrintConsoleDevice {
private:
	ostream* os;
	PrintConsoleDevice() { os = &cout; }

public:
	void Print(const string& s) {
		*os << s;
	}

	static PrintConsoleDevice GetInstance() {
		static PrintConsoleDevice instance;
		return instance;
	}
};

int main() {
	PrintConsoleDevice print = PrintConsoleDevice::GetInstance();
	print.Print("Su dung in lan 1\n");
	PrintConsoleDevice print2 = PrintConsoleDevice::GetInstance();
	print2.Print("Su dung in lan 2 \n\n");

	system("pause");
	return 0;
}