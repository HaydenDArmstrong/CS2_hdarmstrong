#include "person.h"

people::Person::Person(string name, int age, int height)
{
    _name = name;
    _age = age;
    _height = height;
}
string people::Person::getName()
{
    return _name;
}
int people::Person::getAge()
{
    return _age;
}
int people::Person::getHeight()
{
    return _height;
}