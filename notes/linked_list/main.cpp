#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void printList(Node*);

int main(int argc, char* argv[])
{
    Node n1;
    Node n2;
    Node n3;


    n1.data = 2;
    n1.next = &n2;

    n2.data = 42;
    n2.next = &n3;

    n3.data = 100;
    n3.next = nullptr;

    // cout << "n1.data:" << n1.data << endl;
    // cout << "n2.data:" << n2.data << endl;
    // cout << "n3.data:" << n3.data << endl;

    // cout << "head->data:" << head->data << endl;
    // head = head->next;
    // cout << "head->data:" << head->data << endl;
    // head = head->next;
    // cout << "head->data:" << head->data << endl;
    // head = head->next;
    // cout << "head->data:" << head->data << endl;
    // head = head->next;
    printList(&n1);

    return 0;
}

void printList(Node* linkedNumList)
{
    Node* head = linkedNumList;
    while(head != nullptr)
    {
        cout << "head->data:" << head->data << endl;
        head = head->next;
    }
}