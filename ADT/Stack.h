#ifndef _STACK
#define _STACK

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
class Stack : public StackInterface<ItemType> {
private:
    Node<ItemType> *top;

public:
    Stack();

    bool isEmpty() const;

    bool push(const ItemType& newEntry);

    bool pop();

    ItemType peek() const;
};

template<class ItemType>
Stack<ItemType>::Stack(): top(nullptr) {

}

template<class ItemType>
bool Stack<ItemType>::isEmpty() const {
    return top == nullptr;
}

template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newEntry) {
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
bool Stack<ItemType>::pop() {
    if (top == nullptr) return false;

    Node<ItemType>* curr = top;
    top = top->getNext();

    delete curr;
    curr = nullptr;

    return true;
}

template<class ItemType>
ItemType Stack<ItemType>::peek() const {
    if (top == nullptr) throw EmptyStack();

    return top->getItem();
}

#endif