#ifndef _LINKED_STACK
#define _LINKED_STACK

#include "Node.hpp"
#include "StackInterface.hpp"
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

template<class T>
class LinkedStack : public StackInterface<T> {
private:
    Node<T>* top;

public:
    LinkedStack();

    LinkedStack(const LinkedStack<T>& other);

    virtual ~LinkedStack();

    bool isEmpty() const;

    bool push(const T& newEntry);

    bool pop();

    void clear();

    T peek() const;

    vector<T> toVector() const;
};

template<class T>
LinkedStack<T>::LinkedStack(): top(nullptr) {

}

template<class T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& other) {
    if (other.top == nullptr) {
        top = nullptr;
        return;
    }

    try {       //if allocation failed
        top = new Node<T>*();
    }
    catch (const bad_alloc& e) {
        cout << "Memory failed to allocate!" << endl;
        top = nullptr;
    }

    Node<T>* newChainPtr = top;
    Node<T>* origChainPtr = other.top;

    newChainPtr->setItem(origChainPtr->getItem());

    while (origChainPtr != nullptr) {
        origChainPtr = origChainPtr->getNext();

        Node<T>* newNodePtr = nullptr;

        try {
            T nextItem = origChainPtr->getItem();
            newNodePtr = new Node<T>*(nextItem);
        }
        catch (UnknownPointer e) {
            throw e.what();
        }
        catch (MemoryAllocationException e) {
            Node<T>* curr = top;

            while (curr != nullptr) {
                Node<T>* next = curr->getNext();

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

template<class T>
LinkedStack<T>::~LinkedStack() {
    clear();
}

template<class T>
bool LinkedStack<T>::isEmpty() const {
    return top == nullptr;
}

template<class T>
bool LinkedStack<T>::push(const T& newEntry) {
    Node<T>* temp = new Node<T>(newEntry);

    temp->setNext(top);
    top = temp;

    temp = nullptr;
    return true;
}

template<class T>
bool LinkedStack<T>::pop() {
    if (top == nullptr) return false;

    Node<T>* curr = top;
    top = top->getNext();

    delete curr;
    curr = nullptr;

    return true;
}

template<class T>
void LinkedStack<T>::clear() {
    while (!isEmpty()) {
        this->pop();
    }
}

template<class T>
T LinkedStack<T>::peek() const {
    if (top == nullptr) throw EmptyStack();

    return top->getItem();
}

template<class T>
vector<T> LinkedStack<T>::toVector() const {
    vector<T> result;

    Node<T>* curr = top;

    while (curr != nullptr) {
        result.insert(result.begin(), curr->getItem());
        curr = curr->getNext();
    }

    return result;
}

#endif