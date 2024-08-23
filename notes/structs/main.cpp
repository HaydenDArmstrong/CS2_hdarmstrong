#include <iostream>
#include <string>

using namespace std;

//in c, you cannot put function inside of struct. So highly recommended to not put functions in structures in c++


struct AnotherStruct
{
    int num1;

};

struct Rectangle //structures need to end with a semicolon
{
    float side1;
    float side2;
    float area;
    float perimeter;
    AnotherStruct struct2; //instances of other structures can go into a structure
};

void addThings(Rectangle*, Rectangle*); //prototype function. says need a pointer to rectangle and another pointer to rectangle passed to function

int main(int argc, char* argv[])
{
    int num1;
    int* num1Ptr; 

    num1 = 42;
    num1Ptr = &num1;

    cout << *num1Ptr << endl; //dereference



    Rectangle rect1;
    Rectangle rect2;
    Rectangle rectangles[10];
    Rectangle* ptr1;
    Rectangle* ptrRectangles[10];
    Rectangle* heapRect = new Rectangle; //allocates onto the heap, from the stack. the pointer is stored on the stack and the value is stored on the heap
    Rectangle* heapRect2;

    ptr1 = &rect1;
    ptrRectangles[0] = &rect1;


    rect1.side1 = 42;
    rect1.side2 = 15;

    rect1.area = rect1.side1 * rect1.side2; //area = l times w
    rect1.perimeter = 2*rect1.side1 + 2*rect1.side2; //perimeter =  2*l + 2*w

    cout << "The rectangle with sides "
         << rect1.side1 << " and " << rect1.side2
         << "has an area of " << rect1.area
         << "and a perimeter of " << rect1.perimeter;

         delete heapRect;
         delete heapRect2; ///MUST DELETE WHEN YOU ALLOCATE SOMETHING ON THE HEAP before exiting program

    return 0;
}

//heap allocated things are accessed by an arrow. stack allocated things are accessed by a period (rect1.perimeter for example)

void addThings(Rectangle* ptr1, Rectangle ptr2)
{
    cout << ptr1 -> area + (*ptr2).area << endl; //both of these are the same. the arrow is shorthand
}