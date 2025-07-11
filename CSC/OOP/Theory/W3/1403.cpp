#include <iostream>

using namespace std;

class Fraction {
private:
    static int count;
public:
    static void displayCount() {
        cout << "Count: " << count << endl;
    }

    Fraction() {
        count++;
    }

    ~Fraction() {
        count--;
    }
};

int Fraction::count = 0;

int main() {
    Fraction f1;
    f1.displayCount();

    Fraction* f2 = new Fraction();
    f1.displayCount();

    delete f2;

    Fraction::displayCount();

    return 0;
}
