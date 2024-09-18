#include <iostream>

using namespace std;

void myFunction();

int main(int argc, char* argv[])
{
    myFunction();
    myFunction();
    myFunction();
    myFunction();
    //cout << "Inside main: num1:" << num1 << endl; //declared outside the main scope

    return 0;
}

void myFunction()
{
    static int num1 = 42; //holds this number on the stack
    num1++;
    cout << "inside myFunction: num1: " << num1 << endl;
}