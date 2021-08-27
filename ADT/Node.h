#ifndef _NODE
#define _NODE

#include<iostream>

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
    return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
    return next;
}

#endif