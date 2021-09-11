#ifndef _LINKED_LIST
#define _LINKED_LIST

#include<assert.h>
#include "ListInterface.h"
#include "PrecondViolatedException.h"
#include "Node.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType> {
private:
    Node<ItemType>* headPtr;
    
    int itemCount;

    Node<ItemType>* getNodeAt(int position) const;

public:
    LinkedList();

    LinkedList(const LinkedList<ItemType>& aList);

    virtual ~LinkedList();

    bool isEmpty() const;

    int getLength() const;

    bool insert(int newPosition, const ItemType& newEntry);

    bool remove(int position);

    void clear();

    ItemType getEntry(int position) const;

    void setEntry(int position, const ItemType& newEntry);
};

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const {
    assert( (position >= 1) && (position <= itemCount) );

    Node<ItemType>* currPtr = headPtr;  

    for (int skip = 1; skip < position; skip++) {
        currPtr = currPtr->getNext();
    }

    return currPtr;
}

template<class ItemType>
LinkedList<ItemType>::LinkedList(): headPtr(nullptr), itemCount(0) {

}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) {
    if (aList.headPtr == nullptr) {
        headPtr = nullptr;
        return;
    }

    Node<ItemType>* origListPtr = aList.headPtr;
    headPtr = new Node<ItemType>(origListPtr->getItem());

    Node<ItemType>* newListPtr = headPtr;
    this->itemCount = aList.itemCount;

    origListPtr = origListPtr->getNext();

    while (origListPtr != nullptr) {
        Node<ItemType>* temp = new Node<ItemType>(origListPtr->getItem());

        newListPtr->setNext(temp);

        newListPtr = newListPtr->getNext();

        origListPtr = origListPtr->getNext();

        temp = nullptr;
    }

    newListPtr->setNext(nullptr);

    origListPtr = nullptr;

    newListPtr = nullptr;
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList() {
    clear();
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const {
    return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry) {
    if ( newPosition < 1 || newPosition > itemCount + 1 ) return false;

    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

    if (newPosition == 1) {
        newNodePtr->setNext(headPtr);
        headPtr = newNodePtr;
    }
    else {
        Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

        newNodePtr->setNext(prevPtr->getNext());
        prevPtr->setNext(newNodePtr);

        prevPtr = nullptr;
    }

    itemCount++;

    return true;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position) {
    if (position < 1 || position > itemCount) return false;

    Node<ItemType>* currPtr = nullptr;

    if (position == 1) {
        currPtr = headPtr;
        headPtr = headPtr->getNext();
    }
    else {
        Node<ItemType>* prevPtr = getNodeAt(position - 1);
        currPtr = prevPtr->getNext();

        prevPtr->setNext(currPtr->getNext());

        prevPtr = nullptr;
    }

    itemCount--;

    currPtr->setNext(nullptr);

    delete currPtr;

    currPtr = nullptr;

    return true;    
}

template<class ItemType>
void LinkedList<ItemType>::clear() {
    if (headPtr == nullptr) return;

    Node<ItemType>* currPtr = headPtr;

    while (currPtr != nullptr) {
        Node<ItemType>* nextPtr = currPtr->getNext();

        currPtr->setNext(nullptr);
        delete currPtr;

        currPtr = nextPtr;
    }

    headPtr = nullptr;
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {
    if (position < 1 || position > itemCount) {
        string message = "getEntry() was called with an empty list or ";
        message += "invalid position.";
        throw(PrecondViolatedException(message));
    }

    Node<ItemType>* currPtr = getNodeAt(position);

    return currPtr->getItem();
}

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry) {
    if (position < 1 || position > itemCount) {
        string message = "setEntry() was called with an empty list or ";
        message += "invalid position.";
        throw(PrecondViolatedException(message));
    }

    Node<ItemType>* currPtr = getNodeAt(position);

    currPtr->setItem(newEntry);

    currPtr = nullptr;
}
#endif