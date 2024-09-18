#include <iostream>
#include <string>

using namespace std;

class ClassA
{
    public:
        // Constructor
        ClassA() {
            cout << "Constructor called!" << endl;
        }

        // Member function to print the address of the current object
        void printAddress() const {
            cout << "Address of this object: " << this << endl;
        }
};

int main (int argc, char* argv[])
{
    ClassA newclass; // Create an object of ClassA
    newclass.printAddress(); // Call member function to print the address
    return 0;
}
