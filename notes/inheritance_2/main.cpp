#include <iostream>
#include "person.h"

using namespace std;


int main(int argc, char* argv[])
{
    //people::Person* newPerson = new people::Person("Jeremy", 42, 74);
    people::Person newPerson("Jeremy", 42, 74);
    students::Student newStudent(42, "freshman");

    return 0;
}
