#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node*);
void appendList(Node** head, int inputNumber)
{
    if (head == nullptr) //if there is nothing in the list, make a new node
    {
        head = new Node;
        head->data = inputNumber;
        head->next = nullptr;
    }
}

int main(int argc, char* argv[]) {
   
    
    Node* list1 = new Node;
    unsigned int listSize;

    cout << "How many numbers do you want to input?";
    cin >> listSize;

    for (unsigned int i = 0; i < listSize; i++)
    {
        int newNumber;

        cout << "Enter a number";
        cin >> newNumber;
        appendList(&list1, newNumber);
    }

     // Clean up the allocated memory
    while (head != nullptr) {
        Node* curNode = head; // Don't delete the head; that's what you are iterating
        head = head->next;
        delete curNode; // Advance head then delete the current node
    }

    cout << "Printing List: " << endl;
    printList(list1);
}


void printList(Node* linkedNumList) {
    Node* head = linkedNumList;
    while (head != nullptr) {
        cout << "head->data: " << head->data << endl;
        head = head->next;
    }
}
