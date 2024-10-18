#include <iostream>

using namespace std;

int factorial(int);
int fib(int);
void reverseString(string&, int, int);
void printStarts(int);

int main(int argc, char* argv[])
{
    // //factorial
    // int numberfact;

    // cout << "Enter a number for factorial: ";
    // cin >> numberfact;

    // cout << numberfact << "! = " << factorial(numberfact) << endl;

    // //fibonacci
    // int n;

    // cout << "Enter a number for fibonacci: ";
    // cin >> n;

    // cout << n << "fib " << fib(n) << endl;

    // string inStr;

    // cout << "enter string to reverse: ";
    // getline(cin, inStr);
    // reverseString(inStr, 0, inStr.length()-1);

    // cout << "reversed: " << inStr << endl;

    int numStars;

    cout << "Enter size of triangle: ";
    cin >> numStars;

    printStarts(numStars);

    return 0;
}

int factorial(int numberfact)
{
    if(numberfact <= 1) //base case
    {
         return 1;
    }
    else //(number > 1) implied
    {
         return numberfact * factorial(numberfact - 1);
    }
}

// int iterFactorial(int numberfact)
// {
//     int total = 1;
//     for(int i = 1; i <=numberfact; i++)
//     {
//         total = total * i;

//     }
// }

int fib(int n)
{
    cout << "Inside fib " << n << endl;
    if(n < 2)
    {
        return 1;
    }
    return fib(n-1) + fib(n-2); //ex fib 7 = (fib6 + fib 5) = 13
}

void reverseString(string&str, int start, int end)
{
    if (start >= end) //if the string is reversed
    {
        return; //break out of void function
    }
    else
    {
        // char tmp = str[start];
        // str[start] = str[end];
        // str[end] = tmp;
        swap(str[start], str [end]);

        if(start == 0)
        {
            str[start] = toupper(str[start]);
            str[end] = tolower(str[end]);
        }
        reverseString(str, start + 1, end -1);
    }
}

void printStarts(int num)
{
    if(num < 1) return;

     printStarts(num-1);

    for (int i = 0; i < num; i++) cout << "*";
    cout << endl;

    //  printStarts(num-1); here instead of beginning causes an upside down triangle, think if i++ vs ++i

}