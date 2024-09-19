#include <iostream>

using namespace std;

void myFunction();

class someClass
{
    static void printHello();
};

int main(int argc, char* argv[])
{
    SomeClass myClass1;
    myClass1.printHello();

    someClass::printHello();

    myFunction();
    myFunction();
    myFunction();
    myFunction();
    //cout << "Inside main: num1:" << num1 << endl; //declared outside the main scope

    return 0;
}

void myFunction()
{
    static int num1 = 42; //holds this number on the stack, lives on AFTER the function terminates
    cout << "inside myFunction: num1: " << num1 << endl;
    num1++;
}

void SomeClass::printHello()
{
    cout << "Hello world"
}