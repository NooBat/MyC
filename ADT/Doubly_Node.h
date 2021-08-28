#ifndef _DOUBLY_NODE
#define _DOUBLY_NODE

#include<iostream>

using namespace std;

template<class ItemType>
class DoublyNode {
private:
    ItemType item;
    DoublyNode<ItemType>* next;
    DoublyNode<ItemType>* prev;

public:
    DoublyNode();

    DoublyNode(const ItemType& item);

    DoublyNode(const ItemType& item, DoublyNode<ItemType>* next, 
               DoublyNode<ItemType>* previous);

    void setItem(const ItemType& item);

    void setNext(DoublyNode<ItemType>* next);

    void setPrevious(DoublyNode<ItemType>* previous);

    ItemType getItem() const;

    DoublyNode<ItemType>* getNext() const;

    DoublyNode<ItemType>* getPrevious() const;
};

template<class ItemType>
DoublyNode<ItemType>::DoublyNode(): next(nullptr), prev(nullptr) {

}

template<class ItemType>
DoublyNode<ItemType>::DoublyNode(const ItemType& item): item(item), next(nullptr), prev(nullptr) {

}

template<class ItemType>
DoublyNode<ItemType>::DoublyNode(const ItemType& item, 
                      DoublyNode<ItemType>* next, 
                      DoublyNode<ItemType>* previous) 
{
    this->setItem(item);
    this->setNext(next);
    this->setPrevious(previous);
}

template<class ItemType>
void DoublyNode<ItemType>::setItem(const ItemType& item) {
    this->item = item;
}

template<class ItemType>
void DoublyNode<ItemType>::setNext(DoublyNode<ItemType>* next) {
    this->next = next;
}

template<class ItemType>
void DoublyNode<ItemType>::setPrevious(DoublyNode<ItemType>* previous) {
    this->prev = previous;
}

template<class ItemType>
ItemType DoublyNode<ItemType>::getItem() const {
    return this->item;
}

template<class ItemType>
DoublyNode<ItemType>* DoublyNode<ItemType>::getNext() const {
    return this->next;
}

template<class ItemType>
DoublyNode<ItemType>* DoublyNode<ItemType>::getPrevious() const {
    return this->prev;
}
#endif