#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "ListInterface.h"
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
LinkedList<ItemType>::LinkedList(): headPtr(nullptr), itemCount(0) {

}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) {
    if (aList.headPtr == nullptr) {
        headPtr = nullptr;
        return;
    }

    Node<ItemType>* origListNode = aList.headPtr;
    headPtr = new Node<ItemType>(origListNode->getItem());

    Node<ItemType>* newListNode = headPtr;
    this->itemCount = aList.itemCount;

    origListNode = origListNode->getNext();

    while (origListNode != nullptr) {
        Node<ItemType>* temp = new Node<ItemType>(origListNode->getItem());

        newListNode->setNext(temp);

        newListNode = newListNode->getNext();

        origListNode = origListNode->getNext();

        temp = nullptr;
    }

    newListNode->setNext(nullptr);

    origListNode = nullptr;

    newListNode = nullptr;
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
    if (newPosition < 1 || newPosition > itemCount + 1) return false;

    Node<ItemType>* newNode = new Node<ItemType>(newEntry);

    if (newPosition == 1) {
        newNode->setNext(headPtr);
        headPtr = newNode;
    }
    else {
        Node<ItemType>* curr = headPtr;
        Node<ItemType>* prev = nullptr;

        for (int i = 0; i < newPosition; i++) {
            prev = curr;
            curr = curr->getNext();
        }

        prev->setNext(newNode);
        newNode->setNext(curr);

        prev = nullptr;
        curr = nullptr;
    }

    return true;
}

#endif