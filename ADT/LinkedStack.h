#ifndef _LINKED_STACK
#define _LINKED_STACK

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

class MemoryAllocationException : public exception {
    string mess;
public:
    MemoryAllocationException() {
        mess = "Allocation failed!";
    }

    virtual ~MemoryAllocationException() throw() {
        return;
    }

    const char* what() const throw() {
        return mess.c_str();
    }
};

template<class ItemType>
class LinkedStack : public StackInterface<ItemType> {
private:
    Node<ItemType>* top;

public:
    LinkedStack();

    LinkedStack(const LinkedStack<ItemType>& other);

    virtual ~LinkedStack();

    bool isEmpty() const;

    bool push(const ItemType& newEntry);

    bool pop();

    void clear();

    ItemType peek() const;

    vector<ItemType> toVector() const;
};

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(): top(nullptr) {

}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& other) {
    if (other.top == nullptr) {
        top = nullptr;
        return;
    }

    try {       //if allocation failed
        top = new Node<ItemType>*();
    }
    catch (const bad_alloc& e) {
        cout << "Memory failed to allocate!" << endl;
        top = nullptr;
    }

    Node<ItemType>* newChainPtr = top;
    Node<ItemType>* origChainPtr = other.top;

    newChainPtr->setItem(origChainPtr->getItem());

    while (origChainPtr != nullptr) {
        origChainPtr = origChainPtr->getNext();

        Node<ItemType>* newNodePtr = nullptr;

        try {
            ItemType nextItem = origChainPtr->getItem();
            newNodePtr = new Node<ItemType>*(nextItem);
        }
        catch (UnknownPointer e) {
            throw e.what();
        }
        catch (MemoryAllocationException e) {
            Node<ItemType>* curr = top;

            while (curr != nullptr) {
                Node<ItemType>* next = curr->getNext();

                delete curr;

                curr = next;
            }

            top = nullptr;

            throw e.what();
        }
        
        newChainPtr->setNext(newNodePtr);

        newChainPtr = newChainPtr->getNext();
    }

    newChainPtr->setNext(nullptr);
    newChainPtr = nullptr;
}

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack() {
    clear();
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const {
    return top == nullptr;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry) {
    Node<ItemType>* temp = new Node<ItemType>(newEntry);

    temp->setNext(top);
    top = temp;

    temp = nullptr;
    return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop() {
    if (top == nullptr) return false;

    Node<ItemType>* curr = top;
    top = top->getNext();

    delete curr;
    curr = nullptr;

    return true;
}

template<class ItemType>
void LinkedStack<ItemType>::clear() {
    while (!isEmpty()) {
        this->pop();
    }
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const {
    if (top == nullptr) throw EmptyStack();

    return top->getItem();
}

template<class ItemType>
vector<ItemType> LinkedStack<ItemType>::toVector() const {
    vector<ItemType> result;

    Node<ItemType>* curr = top;

    while (curr != nullptr) {
        result.insert(result.begin(), curr->getItem());
        curr = curr->getNext();
    }

    return result;
}

#endif