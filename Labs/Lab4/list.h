#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template <class T1>
class List
{
    private:
        Node<T1> *_head;
        Node<T1> *_tail;
        size_t listSize;

    public:
        List();
        ~List();

        bool empty();
        size_t size();

        void push_front(T1);
        T1 pop_front();
        T1 front();
        void push_back(T1);
        T1 pop_back();
        T1 back();

        bool operator==(const List<T1>&);
        // Have to declare a template for friend functions using a different template variable
        template <class T2>
        friend ostream &operator<<(ostream &, const List<T2> &);
};

// set to nullptr and initialize listSize
template <class T1>
List<T1>::List()
{
    _head = nullptr;
    _tail = nullptr;
    listSize = 0;
}

// iteratively delete the list starting at _head
template <class T1>
List<T1>::~List()
{
    while (_head != nullptr)
    {
        Node<T1>* temp = _head;
        _head = _head->getNext();
        delete temp;
    }
}

// return true if the list is empty, false otherwise.
// Do not just check listSize, should actually check _head and _tail
template <class T1>
bool List<T1>::empty()
{
    if (_head == nullptr && _tail == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// return number of elements in list
template <class T1>
size_t List<T1>::size()
{
    return listSize;
}

// add an element to the beginning of the list, updating _head
template <class T1>
void List<T1>::push_front(T1 data)
{
    Node<T1>* newNode = new Node<T1>();
    newNode->setData(data);
    newNode->setNext(_head);

    if (_head != nullptr) {
        _head->setPrevious(_head);
    }
    else{
        _tail = newNode;
    }

    _head = newNode;
    listSize = listSize + 1;
}

// return the first element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::front()
{
    if (empty()) {
        cout << "List is empty." << endl;
        return 0;
    } else {
        return _head->getData();
    }
}

// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_front()
{
     if (empty()) {
        cout << "List is empty." << endl;
        return 0;
    } else {
        Node<T1>* temp = _head;
        T1 data = temp->getData();
        _head = _head->getNext();

        if (_head != nullptr) {
            _head->setPrev(nullptr);
        } else {
            _tail = nullptr;
        }
        delete temp;
        listSize = listSize - 1;
        return data;
    }
}

// add an element to the end of hte list, updating _tail
template <class T1>
void List<T1>::push_back(T1 data)
{
    Node<T1>* newNode = new Node<T1>();
    newNode->setData(data);
    newNode->setPrev(_tail);

    if (_tail != nullptr) {
        _tail->setNext(newNode);
    } else {
        _head = newNode;
    }
    _tail = newNode;
    listSize = listSize + 1;
}

// return the last element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::back()
{
     if (empty()) {
        cout << "List is empty." << endl;
        return 0;
    } else {
        return _tail->getData();
    }
}

// remove the last element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_back()
{
    if (empty()) {
        cout << "List is empty." << endl;
        return 0;
    } else {
        Node<T1>* temp = _tail;
        T1 data = temp->getData();
        _tail = _tail->getPrev();

        if (_tail != nullptr) {
            _tail->setNext(nullptr);
        } else {
            _head = nullptr;
        }
        delete temp;
        listSize = listSize - 1;
        return data;
    }
}

// overloading <<, should return a space separated stream of all of the elements
template <class T1>
ostream &operator<<(ostream &os, const List<T1> &list)
{
     Node<T1>* current = list._head;
    while (current != nullptr) {
        os << current->getData() << " ";
        current = current->getNext();
    }
    return os;
}

// should iterate through each list to check that they are exactly the same
template <class T1>
bool List<T1>::operator==(const List<T1>& rhs)
{
    if (listSize != rhs.listSize) {
        return false;
    }

    Node<T1>* currentLHS = _head;
    Node<T1>* currentRHS = rhs._head;

    while (currentLHS != nullptr && currentRHS != nullptr) {
        if (currentLHS->getData() != currentRHS->getData()) {
            return false;
        }
        currentLHS = currentLHS->getNext();
        currentRHS = currentRHS->getNext();
    }
    return true;
}