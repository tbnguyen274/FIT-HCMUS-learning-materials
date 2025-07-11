#include <iostream>

class Prototype {
public:
    virtual Prototype* clone() = 0;
    virtual void show() = 0;
};

class ConcretePrototype : public Prototype {
private:
    int x;
public:
    ConcretePrototype() : x(0) {}
    ConcretePrototype(int a) : x(a) {}

    Prototype* clone() override {
        return new ConcretePrototype(*this);
    }
    void show() override {
        std::cout << "Cloned object!\n";
    }
};

int main() {
    ConcretePrototype original;
    Prototype* copy = original.clone();
    copy->show();
    delete copy;
}
