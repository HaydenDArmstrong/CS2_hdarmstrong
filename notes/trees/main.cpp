#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char* argv[])
{
    int inputData = 0;
    Tree mytree;

    cout << "Enter numbers, -999 to quit: ";
    while(inputData != -999)
    {
        cin >> inputData;
        if (inputData == -999) break;
        mytree.addNode(inputData);
        cout << "Enter another Number: ";
    
    }
   mytree.inOrder();

   cout <<"what Number to search for: ";
   cin >> inputData;
   cout << boolalpha << mytree.search(inputData);
   cout << endl;


    return 0;
}