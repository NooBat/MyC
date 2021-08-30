#ifndef _SET
#define _SET

#include "/Users/danielnguyen/Repo/C++/ADT/BagInterface.h"
#include "/Users/danielnguyen/Repo/C++/ADT/Node.h"
#include<iostream>

using namespace std;

template<class ItemType>
class Set : public BagInterface<ItemType> {
private:
    int itemCount;
    Node<ItemType>* head_ptr;

    Node<ItemType>* getPointerTo(const ItemType& target);
public:
    Set();

    Set(const Set<ItemType>& other);

    virtual ~Set();

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
Node<ItemType>* Set<ItemType>::getPointerTo(const ItemType& target) {
    if (!contains(target)) return nullptr;

    Node<ItemType>* p = head_ptr;

    while (p != nullptr) {
        if (p->getItem() == target) return p;
        p = p->next;
    }

    return nullptr;
}

template<class ItemType>
Set<ItemType>::Set(): itemCount(0), head_ptr(nullptr) {

}

template<class ItemType>
Set<ItemType>::Set(const Set<ItemType>& other) {
    itemCount = other.itemCount;

    if (other.head_ptr == nullptr) head_ptr = nullptr;
    else {
        Node<ItemType>* temp = other.head_ptr;

        while (temp != nullptr) {
            add(temp->getItem());
            temp = temp->getNext();
        }
    }
}

template<class ItemType>
Set<ItemType>::~Set() {
    clear();
}

template<class ItemType>
int Set<ItemType>::getCurrentSize() const {
    return this->itemCount;
}

template<class ItemType>
bool Set<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
bool Set<ItemType>::add(const ItemType& newEntry) {
    if (contains(newEntry)) return false;
    if (head_ptr == nullptr) {
        head_ptr = new Node<ItemType>(newEntry);
        return true;
    }
    Node<ItemType>* temp = new Node<ItemType>(newEntry);

    temp->next = head_ptr;

    head_ptr = temp;

    itemCount++;

    return true;
}

template<class ItemType>
bool Set<ItemType>::remove(const ItemType& entry) {
    if (!contains(entry)) return false;
    if (isEmpty()) return false;

    Node<ItemType>* curr = getPointerTo(entry);

    if (curr == nullptr) return false;

    if (curr == head_ptr) {
        head_ptr = head_ptr->getNext();

        delete curr;
        curr = nullptr;
        itemCount--;

        return true;
    }

    Node<ItemType>* prev = head_ptr;
    Node<ItemType>* next = curr->getNext();
    while (prev->getNext() != curr) {
        prev = prev->getNext();
    }

    delete curr;
    curr = nullptr;

    prev->setNext(next);
    itemCount--;

    return true;
}

template<class ItemType>
void Set<ItemType>::clear() {
    if (head_ptr == nullptr) return;

    itemCount = 0;

    Node<ItemType>* p = head_ptr;

    while (p != nullptr) {
        Node<ItemType>* next = p->getNext();

        delete p;

        p = next;
    }

    head_ptr = nullptr;
}

template<class ItemType>
int Set<ItemType>::getFrequencyOf(const ItemType& entry) const {
    int count = 0;

    Node<ItemType>* p = head_ptr;

    while (p != nullptr) {
        if (p->getItem() == entry) count++;
    }

    return count;
}

template<class ItemType> 
bool Set<ItemType>::contains(const ItemType& entry) const {
    if (head_ptr == nullptr) return false;

    Node<ItemType>* p = head_ptr;

    while (p != nullptr) {
        if (p->getItem() == entry) return true;
        p = p->getNext();
    }

    return false;
}

template<class ItemType>
vector<ItemType> Set<ItemType>::toVector() const {
    vector<ItemType> result;

    if (head_ptr == nullptr) return result;

    Node<ItemType>* p = head_ptr;

    while (p != nullptr) {
        result.push_back(p->getItem());
        p = p->getNext();
    }

    return result;
}
#endif