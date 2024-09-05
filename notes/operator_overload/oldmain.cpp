#include <iostream>
#include <string>

using namespace std;

class Rectangle
{
private:
    int _side1, _side2;

public:
    // Constructor
    Rectangle(int, int);

    // Operator overloading
    Rectangle operator+(Rectangle&);
    Rectangle operator%(int);

    // Method to print sides
    void printSides();
};

int main(int argc, char* argv[])
{
    Rectangle rect1(2, 3);
    Rectangle rect2(2, 3);

    // Testing overloaded + operator
    Rectangle rect3 = rect1 + rect2;

    // Testing overloaded % operator
    Rectangle rect4 = rect1 % 42;

    // Print sides for each rectangle
    rect1.printSides();
    rect2.printSides();
    rect3.printSides();
    rect4.printSides();

    return 0;
}

// Overloading the + operator
Rectangle Rectangle::operator+(Rectangle& otherRect)
{
    int newSide1 = _side1 + otherRect._side1;
    int newSide2 = _side2 + otherRect._side2;
    return Rectangle(newSide1, newSide2);
}

// Overloading the % operator
Rectangle Rectangle::operator%(int modNum)
{
    int newSide1 = _side1 * modNum;
    int newSide2 = _side2 * modNum;
    return Rectangle(newSide1, newSide2);
}

// Method to print sides
void Rectangle::printSides()
{
    cout << "_side1: " << _side1 << ", _side2: " << _side2 << endl;
}

// Constructor definition
Rectangle::Rectangle(int side1, int side2)
{
    _side1 = side1;
    _side2 = side2;
}