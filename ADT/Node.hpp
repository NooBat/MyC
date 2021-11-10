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

template<class ItemType>
class Node {
private:
    ItemType item;
    Node<ItemType>* next;

public: 
    Node();

    Node(const ItemType& anItem);

    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    
    void setItem(const ItemType& anItem);

    void setNext(Node<ItemType>* nextNodePtr);

    ItemType getItem() const;

    Node<ItemType>* getNext() const;
};

template<class ItemType>
Node<ItemType>::Node(): next(NULL) {

}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem): item(anItem), next(nullptr) {

}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) {
    this->item = anItem;
    this->next = nextNodePtr;
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {
    this->item = anItem;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
    this->next = nextNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const {
    try
    {
        Node<ItemType>* nextPtr = this->next;
    }
    catch(exception& e)
    {
        throw e.what();
    }

    return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
    try
    {
        Node<ItemType>* nextPtr = this->next;
    }
    catch(exception& e)
    {
        throw e.what();
    }
    
    return next;
}

#endif