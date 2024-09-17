#include <iostream>

using namespace std;

class BaseClass
{
    private:
    int a;
    public:
    BaseClass(int);
    void printA();
};

class DerivedClass : public BaseClass // derived class is derived from Baseclass
{
    public:
    DerivedClass(int);
    void printA();
};

int main (int argc, char *argv[])
{
    DerivedClass myInstance(42);

    myInstance.printA();
    return 0;
}

BaseClass::BaseClass(int A)
{
    a = A;
}

void BaseClass::printA()
{
    cout << "a: " << a << endl;
}

DerivedClass::DerivedClass(int newA) : BaseClass(newA)
{
    cout << "inside DerivedClass constructor" << endl;
}

void DerivedClass::printA()
{
    cout << "Inside DerivedClass: a: " << endl;
    this->printA();
}