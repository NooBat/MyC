#ifndef _OurStack
#define _OurStack

#include "Node.h"
#include "StackInterface.h"
#include<iostream>
#include<cstring>

using namespace std;

class EmptyStack : public exception {
    string mess;

public:
    virtual ~EmptyStack() throw() {
        return ;
    }
    EmptyStack() {
        mess = "Stack is empty!";
    }
    const char *what() const throw() {
        return mess.c_str();
    }
};

template<class ItemType>
class OurStack : public StackInterface<ItemType> {
private:
    Node<ItemType> *top;

public:
    OurStack();

    bool isEmpty() const;

    bool push(const ItemType& newEntry);

    bool pop();

    ItemType peek() const;
};

template<class ItemType>
OurStack<ItemType>::OurStack(): top(nullptr) {

}

template<class ItemType>
bool OurStack<ItemType>::isEmpty() const {
    return top == nullptr;
}

template<class ItemType>
bool OurStack<ItemType>::push(const ItemType& newEntry) {
    if (top == nullptr) {
        Node<ItemType>* temp = new Node<ItemType>(newEntry);
        top = temp;
        temp = nullptr;

        return true;
    }

    Node<ItemType>* temp = new Node<ItemType>(newEntry);

    temp->setNext(top);
    top = temp;

    temp = nullptr;
    return true;
}

template<class ItemType>
bool OurStack<ItemType>::pop() {
    if (top == nullptr) return false;

    Node<ItemType>* curr = top;
    top = top->getNext();

    delete curr;
    curr = nullptr;

    return true;
}

template<class ItemType>
ItemType OurStack<ItemType>::peek() const {
    if (top == nullptr) throw EmptyStack();

    return top->getItem();
}

#endif