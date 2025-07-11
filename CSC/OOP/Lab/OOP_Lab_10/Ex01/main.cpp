#include <iostream>
#include <cmath>

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
    static double RunTest2(CA* pCA) {
        if (pCA == nullptr) {
            return -1;
        }
        double rs = pCA->getTest();
        return sqrt(rs);
    }
};

class Level2 {
public:
    static double RunTest1() {
        CA* pCA = nullptr;
        double dRS = Level1::RunTest2(pCA);
        if (dRS == -1) {
            return -1;
        }
        return sqrt(dRS);
    }
};

int main() {
    cout << Level2::RunTest1() << endl;
    system("pause");
    return 0;
}