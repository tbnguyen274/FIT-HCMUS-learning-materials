#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Formatter {
private:
    // string separator;

public:
    // Formatter() : separator(".") {}
    static string format(const int& money, const string& separator=".", const string& currency="d") {
        string s = to_string(money);
        string res = "";
        int count = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            res += s[i];
            if (count < 2) {                
                count++;
            }
            else if (i != 0) {
                res += separator;
                count = 0;
            }
        }
        
        string rev = "";
        for (int i = 0; i < res.size(); i++) {
            rev += res[res.size() - i - 1];
        }

        if (currency == "$") {
            rev = "$ " + rev;
        }
        else rev += " d";

        return rev;
    }
};

class Project {
protected:
    string _name;

public:
    Project() : _name("") {}
    virtual int grantMoney() = 0;
    virtual void print() = 0;
    virtual ~Project() {}
};

class Idea : public Project {
private:
    int _months;
    const int FUND = 20000000;
    
public:
    Idea() {
        _months = 0;
    }

    Idea(const string& name, const int& months) : _months(months) {
        _name = name;
    }

    ~Idea() {}

    int grantMoney() {
        return _months * FUND;
    }

    void print() {
        cout << "Ý tưởng: " << _name << ". Phát triển: " << _months << " tháng. Kinh phí: " << Formatter::format(grantMoney());
    }
};

class Mvp : public Project {
private:
    int _mktMonths;
    int _opsMonths;
    const int FUND = 15000000;

public:
    Mvp() : _mktMonths(0), _opsMonths(0) {}

    Mvp(const string& name, const int& ops, const int& mkt) : _mktMonths(mkt), _opsMonths(ops) {
        _name = name;
    }

    ~Mvp() {}

    int grantMoney() {
        return (_mktMonths + _opsMonths) * FUND;
    }

    void print() {
        cout << "Sản phẩm: " << _name;
        cout << ". Vận hành: " << _opsMonths << " tháng. Marketing: " << _mktMonths << " tháng. ";
        cout << "Kinh phí: " << Formatter::format(grantMoney());
    }
};

int main()
{
    cout << "Chương trình hỗ trợ Hackathon của AlphaTech tháng 6/2023" << endl;
    vector<Project*> projects = { // Bỏ qua tiềm ẩn rò rỉ vùng nhớ
        new Idea("SuperTech", 6),
        new Mvp("FutureCar", 6, 3),
        new Idea("VirtualHouse", 7),
        new Idea("NightVision", 4),
        new Mvp("SmartKey", 4, 5)
    };
    cout << "Số dự án: " << projects.size() << endl;
    int sum = 0;
    for(int i = 0; i < projects.size(); i++) {
        sum += projects[i]->grantMoney();
        cout << i + 1 << ".";
        projects[i]->print();
        cout << endl;
    }
    cout << "Tổng tiền tài trợ: " << sum;
    return 0;
}
