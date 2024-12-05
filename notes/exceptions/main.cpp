#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int numerator;
    int denominator;
    char ch;

   try{
    cout << "Enter the numerator/denominator: ";
    cin >> numerator >> ch >> denominator;
    if (denominator == 0){
        throw 0;
    }
    if(ch != '/')
    {
        throw '/';
    }
    throw "string";
   }
   catch(int n)
   {
    cout << "Denominator is Zero... setting denominator to 1" << endl;
    denominator = 1;
   }
   catch(char ch)
   {
    cout << "Did not enter problem seperation symbol (slash)" << endl;
   }
   catch(...)
   {
    cout << "default catch" << endl;
   }
   cout << numerator << "/" << denominator << endl;
    cout << numerator/denominator << endl;
    return 0;
}