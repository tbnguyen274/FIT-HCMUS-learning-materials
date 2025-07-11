#include <iostream>
#include <cmath>
#include <exception>
#include <string>
#include <sstream>
#include <cstring>

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

class MyException : public exception {
private:
    string _errorDescription;
    int _errorCode;

public:
    MyException(const int& errCode, const string& errDes) : exception(BuildErrorMessage(errCode, errDes)) {
        _errorCode = errCode;
        _errorDescription = errDes;
    }

    const string& GetErrorDescription() {
        return _errorDescription;
    }

    const int& GetErrorCode() {
        return _errorCode;
    }

private:
    static const char* BuildErrorMessage(const int& errCode, const string& errDes) {
        ostringstream oss;
        oss << "Error Code: " << errCode;
        oss << " - Description: " << errDes;
        int len = strlen(oss.str().c_str());
        char* temp = new char[len + 1];
        strcpy_s(temp, len + 1, oss.str().c_str());
        return temp;
    }
};

class Level1 {
public:
    static double RunTest4(CA* pCA) {
        if (pCA == nullptr) {
            throw MyException(123, "Argument must not be null");
        }

        double rs = pCA->getTest();
        return sqrt(rs);
    }
};

class Level2 {
public:
    static double RunTest3() {
        CA* pCA = nullptr;
        double dRS = Level1::RunTest4(pCA);
        return sqrt(dRS);
    }

    static void RunErr() {
        throw exception("Common error");
    }
};

int main() {
    for (int i = 0; i < 2; i++) {
        cout << "******************************" << endl;
        try {
            if (i == 0) {
                cout << Level2::RunTest3() << endl;
            }
            else {
                Level2::RunErr();
            }
        }
        catch (const MyException& me) {
            cout << "custom error: " << me.what() << endl;
        }
        catch (const exception& ex) {
            cout << "common error: " << ex.what() << endl;
        }
    }

    system("pause");
    return 0;
}