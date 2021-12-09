#ifndef _NODE
#define _NODE

#include<iostream>
#include<string>
#include<stdexcept>

using namespace std;

class UnknownPointer : public exception {
    string mess;

public:
    UnknownPointer() {
        mess = "This pointer points to NULL";
    }

    virtual ~UnknownPointer() throw() {
        return;
    }

    const char* what() const throw() {
        return mess.c_str();
    }
};

template<class T>
class Node {
private:
    T item;
    Node<T>* next;

public: 
    Node();

    Node(const T& anItem);

    Node(const T& anItem, Node<T>* nextNodePtr);
    
    void setItem(const T& anItem);

    void setNext(Node<T>* nextNodePtr);

    T getItem() const;

    Node<T>* getNext() const;
};

template<class T>
Node<T>::Node(): next(NULL) {

}

template<class T>
Node<T>::Node(const T& anItem): item(anItem), next(nullptr) {

}

template<class T>
Node<T>::Node(const T& anItem, Node<T>* nextNodePtr) {
    this->item = anItem;
    this->next = nextNodePtr;
}

template<class T>
void Node<T>::setItem(const T& anItem) {
    this->item = anItem;
}

template<class T>
void Node<T>::setNext(Node<T>* nextNodePtr) {
    this->next = nextNodePtr;
}

template<class T>
T Node<T>::getItem() const {
    try
    {
        Node<T>* nextPtr = this->next;
    }
    catch(exception& e)
    {
        throw e.what();
    }

    return item;
}

template<class T>
Node<T>* Node<T>::getNext() const {
    try
    {
        Node<T>* nextPtr = this->next;
    }
    catch(exception& e)
    {
        throw e.what();
    }
    
    return next;
}

#endif