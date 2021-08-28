#ifndef _DOUBLY_LINKED_BAG
#define _DOUBLY_LINKED_BAG

#include "/Users/danielnguyen/Repo/C++/ADT/Doubly_Node.h"
#include "/Users/danielnguyen/Repo/C++/ADT/BagInterface.h"

using namespace std;

template<class ItemType>
class DoublyLinkedBag : public BagInterface<ItemType> {
private:
    int itemCount;
    DoublyNode<ItemType>* headPtr;

    DoublyNode<ItemType>* getPtrTo(const ItemType& target) const;

public:
    DoublyLinkedBag();

    DoublyLinkedBag(const DoublyLinkedBag<ItemType>& other);

    virtual ~DoublyLinkedBag();

    int getCurrentSize() const;

    bool isEmpty() const;

    bool add(const ItemType& newEntry);

    bool remove(const ItemType& entry);

    void clear();

    int getFrequencyOf(const ItemType& entry) const;

    bool contains(const ItemType& entry) const;

    vector<ItemType> toVector() const;
};

template<class ItemType>
DoublyNode<ItemType>* DoublyLinkedBag<ItemType>::getPtrTo(const ItemType& target) const {
    if (headPtr == nullptr) return nullptr;

    DoublyNode<ItemType>* curr = headPtr;

    while (curr != nullptr) {
        if (curr->getItem() == target) return curr;
        curr = curr->getNext();
    }

    return nullptr;
}

template<class ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag(): itemCount(0), headPtr(nullptr) {

}

template<class ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag(const DoublyLinkedBag<ItemType>& other) {
    if (other.headPtr == nullptr) return;

    itemCount = other.itemCount;

    headPtr = nullptr;

    DoublyNode<ItemType>* curr = other.headPtr;

    while (curr != nullptr) {
        this->add(curr->getItem());
        curr = curr->getNext();
    }
}

template<class ItemType>
DoublyLinkedBag<ItemType>::~DoublyLinkedBag() {
    clear();
}

template<class ItemType>
int DoublyLinkedBag<ItemType>::getCurrentSize() const {
    return itemCount;
}

template<class ItemType>
bool DoublyLinkedBag<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
bool DoublyLinkedBag<ItemType>::add(const ItemType& newEntry) {
    if (headPtr == nullptr) {
        headPtr = new DoublyNode<ItemType>(newEntry);
        itemCount++;
        return true;
    }

    DoublyNode<ItemType>* temp = new DoublyNode<ItemType>(newEntry);

    temp->setNext(headPtr);
    headPtr->setPrevious(temp);

    headPtr = temp;

    itemCount++;
    return true;
}

template<class ItemType>
bool DoublyLinkedBag<ItemType>::remove(const ItemType& entry) {
    DoublyNode<ItemType>* curr = getPtrTo(entry);

    if (curr == nullptr) return false;
    if (curr == headPtr) {
        headPtr = curr->getNext();

        delete curr;
        curr = nullptr;
        itemCount--;

        return true;
    }

    DoublyNode<ItemType>* prev = curr->getPrevious();
    DoublyNode<ItemType>* next = curr->getNext();

    prev->setNext(next);
    next->setPrevious(prev);

    delete curr;
    curr = nullptr;
    itemCount--;

    return true;
}

template<class ItemType>
void DoublyLinkedBag<ItemType>::clear() {
    if (headPtr == nullptr) return;

    DoublyNode<ItemType>* curr = headPtr;
    
    while (curr != nullptr) {
        DoublyNode<ItemType>* next = curr->getNext();

        delete curr;

        curr = next;
    }
    itemCount = 0;
    headPtr = nullptr;
}

template<class ItemType>
int DoublyLinkedBag<ItemType>::getFrequencyOf(const ItemType& entry) const {
    int count = 0;
    if (headPtr == nullptr) return count;

    DoublyNode<ItemType>* curr = headPtr;

    while (curr != nullptr) {
        if (curr->getItem() == entry) count++;
        curr = curr->getNext();
    }

    return count;
}

template<class ItemType>
bool DoublyLinkedBag<ItemType>::contains(const ItemType& entry) const {
    return getPtrTo(entry) != nullptr;
}

template<class ItemType>
vector<ItemType> DoublyLinkedBag<ItemType>::toVector() const {
    vector<ItemType> result;

    if (headPtr == nullptr) return result;

    DoublyNode<ItemType>* curr = headPtr;

    while (curr != nullptr) {
        result.push_back(curr->getItem());
        curr = curr->getNext();
    }

    return result;
}

#endif