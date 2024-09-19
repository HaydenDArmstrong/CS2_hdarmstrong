#include <iostream>

using namespace std;


//if a function is passed an address, the core variable can be changed. 
//if a function is passed a pointer, 
void something(int);
void something2(int&);
void something3(int*);

int main(int argc, char* argv[])
{
    int num1 = 42;
    int* ptr1 = &num1; //you can make it a pointer like this. HERE, The address of num1 (0x1200 or whatever,) is passed in and then can be altered

    cout << "Inside main: num1: " << num1 << " &num1: " << &num1 << endl;
    something(num1);
    something2(num1);
    //something3(ptr1);

    cout << "Something3(ptr1)" << endl;
    something3(ptr1); //using the seperate function

    cout << "something3(&num1): " << endl;
    something3(&num1); //does the same thing as the first function without an extra needed
    return 0;
}

void something(int n1)
{
    cout << "Inside something: n1: " << n1 << " &n1: " << &n1 << endl;
}

void something2(int& n1)
{
    cout << "Inside something: n1: " << n1 << " &n1: " << &n1 << endl;
}

void something3(int* n1)
{
    cout << "Inside something: n1: " << n1 << " &n1: " << &n1 << endl;
}