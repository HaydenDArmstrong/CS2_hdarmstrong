#pragma once
#include <string>

using namespace std;

namespace people
{
    class Person
    {
        private:
        string _name;
        int _age;
        int _height;

        protected:
        Person(string, int, int);
        string getName();
        int getAge();
        int getHeight();

        public:
        Person(string = "", int = 42, int = 42);
    };
}