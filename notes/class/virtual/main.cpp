#include <iostream>

using namespace std;

class Animal
{
    protected: //only a derived class can access Animals constructor
    Animal();

    public:
    virtual void speak();
};

class Bird : public Animal //derived class of Animal
{
    public:
    Bird();
     void speak();
};

class Dog : public Animal
{
    public:
    Dog();
     void speak();
};

int main(int argc, char* argv[])
{
    Dog myDog;
    Bird myBird; //make an instance

    myBird.speak(); //run a function through the instance
    myDog.speak();

    return 0;
}

Dog::Dog()
{
    cout << "inside dog constructor"<< endl;
}

void Dog::speak()
{
    cout << "bark" << endl;
}

Animal::Animal()
{
    cout << "Inside Animal Constructor" << endl;
}
void Animal::speak()
{
    cout << "Animal says lkjfdsajfdsalkjfdsalk" << endl;
}

Bird::Bird()
{
    cout << "Inside Bird Constructor" << endl;
}
void Bird::speak()
{
    cout << "Bird says tweet" << endl;
}
// class BaseClass
// {
//     private:
//     int a;
//     public:
//     BaseClass(int);
//     void printA();
// };

// class DerivedClass : public BaseClass // derived class is derived from Baseclass
// {
//     public:
//     DerivedClass(int);
//     void printA();
// };

// int main (int argc, char *argv[])
// {
//     DerivedClass myInstance(42);

//     myInstance.printA();
//     return 0;
// }

// BaseClass::BaseClass(int A)
// {
//     a = A;
// }

// void BaseClass::printA()
// {
//     cout << "a: " << a << endl;
// }

// DerivedClass::DerivedClass(int newA) : BaseClass(newA)
// {
//     cout << "inside DerivedClass constructor" << endl;
// }

// void DerivedClass::printA()
// {
//     cout << "Inside DerivedClass: a: " << endl;
//     this->printA();
// }