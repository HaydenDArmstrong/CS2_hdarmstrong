#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <cassert> 
#include "stack.h"

using namespace std;

// Evaluate an RPN expression
double evaluateRPN(string expression)
{
    Stack stack;
    stringstream ss(expression);
    string token;

    while (ss >> token)
    {
        try
        {
            double number = stod(token);
            stack.push(number);
        }
        catch (const invalid_argument &)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                if (stack.size() < 2)
                {
                    cerr << "Error: Invalid RPN expression." << endl;
                    return NAN   ;
                }
                double b = stack.pop();
                double a = stack.pop();

                if (token == "+")
                    stack.push(a + b);
                else if (token == "-")
                    stack.push(a - b);
                else if (token == "*")
                    stack.push(a * b);
                else if (token == "/")
                {
                    if (b == 0)
                    {
                        cerr << "Error: Division by zero." << endl;
                        return NAN;
                    }
                    stack.push(a / b);
                }
            }
            else
            {
                cerr << "Error: Invalid token '" << token << "' in RPN expression." << endl;
                return NAN;
            }
        }
    }

    if (stack.size() != 1)
    {
        cerr << "Error: Invalid RPN expression." << endl;
        return NAN;
    }

    return stack.pop();
}

// Test cases for evaluateRPN using assertions
void test()
{
    // Test 1: Standard RPN expression
    string test1 = "3 4 + ";
    assert(abs(evaluateRPN(test1)) == 7);

    string test2 = "10 5 / 2 -";
    assert(abs(evaluateRPN(test2)) == 0);

    string test3 = "2 3 + 5 *";
    assert(abs(evaluateRPN(test3)) == 25);

    // // Test 4: Division by zero
     string test4 = "5 0 /";
     assert(std::isnan(evaluateRPN(test4)));

    // // Test 5: Invalid token
     string test5 = "5 2 @";
     assert(std::isnan(evaluateRPN(test5)));

    cout << "All test cases passed." << endl;
}

int main(int argc, char *argv[])
{

    if(argc >= 2 && (string)argv[1] == "test")
    {
        test();
        return 0;
    }
   
        string expression;
        cout << "Enter an RPN expression: ";
        getline(cin, expression);
        double result = evaluateRPN(expression);
        cout << expression << " = " << result << endl;
    

    return 0;
}
