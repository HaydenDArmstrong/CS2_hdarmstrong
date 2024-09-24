#include <iostream>

using namespace std;

// int addNums(int, int); //what if we wanted a function that can do ints and floats?? function overloading
// float addNums(float, float); //what about float and an int? we can do that too
// float addNums(float, int);

//but what if we wanted to do it easier and more efficently??? in c++, we have templating.
template <typename T1, typename T2>
T1 addNums(T1, T2);

class SomeClass
{
    private:
    int _number1;
    public:
    SomeClass(int);
    int getNumber1();
    SomeClass& operator+(SomeClass&);

};
// SomeClass SomeClass::operator+(SomeClass& rightSide)
// {
//     SomeClass tmpClass(this->_number1 + rightSide.getNumber1());

//     return tmpClass;
// };


// int someClass::getNumber1()
// {
//     return _number1;
// };



int main(int argc, char* argv[])
{
    float num1;
    float num2;

    num1 = 42.16;
    num2 = 15;

    cout << num1 << " + " << num2 << " = " << addNums<float,float>(num1,num2) << endl;
    return 0;
}

template <typename T1, typename T2>
T1 addNums(T1 n1, T2 n2) //allows for very type, int, float, etc
{
    T1 sum;
    sum = n1 + n2;
    return sum;
    //return n1 + n2;
}

// int addNums(int n1, int n2)
// {
//     return n1+ n2;
// }

// float addNums(float n1, float n2)
// {
//     return n1+n2;
// }

// float addNUms(float n1, int n2)
// {
//     return n1+n2;
// }