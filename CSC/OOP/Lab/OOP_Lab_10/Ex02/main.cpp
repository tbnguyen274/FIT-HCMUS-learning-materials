#include <iostream>
#include <cmath>
#include <exception>

using namespace std;

class CA {
private:
    double _value;

public:
    CA(const double& v) { _value = v; }
    double getTest() {
        return this->_value;
    }
};

class Level1 {
public:
    static double RunTest3(CA* pCA) {
        if (pCA == nullptr) {
            throw exception("Argument must not be null");
        }
        double rs = pCA->getTest();
        return sqrt(rs);
    }
};

class Level2 {
public:
    static double RunTest2() {
        CA* pCA = nullptr;
        double dRS = Level1::RunTest3(pCA);
        return sqrt(dRS);
    }
};

int main() {
    try {
        cout << Level2::RunTest2() << endl;
    }
    catch (const exception& ex) {
        cout << "Error: " << ex.what() << endl;
    }
    
    system("pause");
    return 0;
}