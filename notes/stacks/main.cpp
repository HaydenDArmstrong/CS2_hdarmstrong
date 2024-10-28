#include <iostream>
#include <cmath>

using namespace std;

template <typename T1>
class Stack
{
    private:
        static const int maxArr = 100;
        T1 _stack[maxArr];
        int _stackSize;

    public:
        Stack();
        bool empty();
        int size();
        T1 top();
        void push(T1 value);
        T1 pop();
        bool Full();
};

int main(int argc, char* argv[])
{
    Stack<int> stack; // Example usage
    return 0;
}

// Constructor
template <typename T1>
Stack<T1>::Stack()
{
    _stackSize = -1;
}

template <typename T1>
bool Stack<T1>::Full()
{
    if (_stackSize >= 99) return true;
    return false;
}




// Check if stack is empty
template <typename T1>
bool Stack<T1>::empty()
{
    if (_stackSize <0) return true;
    return false;
}

// Get the size of the stack
template <typename T1>
int Stack<T1>::size()
{
    return _stackSize + 1;
}

// Get the top element
template <typename T1>
T1 Stack<T1>::top()
{
    if (!empty())
        return _stack[_stackSize];
    return NAN;
}

// Push an element onto the stack
template <typename T1>
void Stack<T1>::push(T1 value)
{
    if (_stackSize < maxArr - 1)
        _stack[++_stackSize] = value;
    else
        throw overflow_error("Stack overflow");
}

// Pop an element from the stack
template <typename T1>
T1 Stack<T1>::pop()
{
    if (_stackSize >= 0)
        return _stack[_stackSize--];
    throw out_of_range("Stack is empty");
}