#include <iostream>

using namespace std;

// int addNums(int, int); //what if we wanted a function that can do ints and floats?? function overloading
// float addNums(float, float); //what about float and an int? we can do that too
// float addNums(float, int);

//but what if we wanted to do it easier and more efficently??? in c++, we have templating.
template <typename T1>
class MyClass
{
    private:
    T1 _id;

    public:
    void setId(T1);
    T1 getId;


};


 
int main(int argc, char* argv[])
{
    MyClass<int> c1;
    MyClass<string> c2;
    MyClass<char> c3;

    c1.setId(42);
    c2.setId("Jeremy:");
    c3.setId('J');

    
}
template <typename T1>
void MyClass<T1>::setId(T1)
{
    _id = id;
}

// template <typename T1>
// // T1 MyClass<T1>::getId()
// // {
//  return _id;
// }
