#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
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
        // Try to convert the token to a double
        try
        {
            double number = stod(token);  // Try converting the token to a double
            stack.push(number);           // Push number to stack if successful
        }
        catch (const invalid_argument&)
        {
            // If it's not a number, handle operators
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                if (stack.size() < 2)
                {
                    cerr << "Error: Invalid RPN expression." << endl;
                    return NAN;
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

// Test cases for evaluateRPN
void test()
{
    string test1 = "3 4 + 5 6 - *";
    string test2 = "7 5 + 1 42 / +";
    string test3 = "2 5 + 2 - 8 9 + +";

    cout << test1 << " = " << evaluateRPN(test1) << endl;
    cout << test2 << " = " << evaluateRPN(test2) << endl;
    cout << test3 << " = " << evaluateRPN(test3) << endl;
}

int main(int argc, char* argv[])
{
    if (argc == 3 && string(argv[1]) == "-p")
    {
        string expression = argv[2];
        double result = evaluateRPN(expression);
        cout << expression << " = " << result << endl;
    }
    else
    {
        string expression;
        cout << "Enter an RPN expression: ";
        getline(cin, expression);
        double result = evaluateRPN(expression);
        cout << expression << " = " << result << endl;
    }

    // Run test cases
    test();

    return 0;
}
