#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node*);

int main(int argc, char* argv[]) {
    // Allocate memory for nodes
    Node* n1 = new Node;
    Node* n2 = new Node;
    Node* n3 = new Node;

    // Initialize node data and next pointers
    n1->data = 2;
    n1->next = n2;

    n2->data = 42;
    n2->next = n3;

    n3->data = 100;
    n3->next = nullptr;

    printList(n1);

    // Allocate and link a fourth node
    Node* n4 = new Node;
    n4->data = 200;
    n4->next = nullptr;
    n3->next = n4;

    cout << "All 4 list elements:" << endl;
    printList(n1);

    // Remove the last node
    n3->next = nullptr;
    cout << "3 list elements:" << endl;
    printList(n1);

    // Clean up the allocated memory
    Node* head = n1;
    while (head != nullptr) {
        Node* curNode = head; // Don't delete the head; that's what you are iterating
        head = head->next;
        delete curNode; // Advance head then delete the current node
    }

    return 0;
}

void printList(Node* linkedNumList) {
    Node* head = linkedNumList;
    while (head != nullptr) {
        cout << "head->data: " << head->data << endl;
        head = head->next;
    }
}
