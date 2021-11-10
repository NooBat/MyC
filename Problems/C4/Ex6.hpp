#ifndef _DOUBLY_LINKED_BAG
#define _DOUBLY_LINKED_BAG

#include "/Users/danielnguyen/Repo/C++/ADT/Doubly_Node.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/BagInterface.hpp"

using namespace std;

template<class T>
class DoublyLinkedBag : public BagInterface<T> {
private:
    int itemCount;
    DoublyNode<T>* headPtr;

    DoublyNode<T>* getPtrTo(const T& target) const;

public:
    DoublyLinkedBag();

    DoublyLinkedBag(const DoublyLinkedBag<T>& other);

    virtual ~DoublyLinkedBag();

    int getCurrentSize() const;

    bool isEmpty() const;

    bool add(const T& newEntry);

    bool remove(const T& entry);

    void clear();

    int getFrequencyOf(const T& entry) const;

    bool contains(const T& entry) const;

    vector<T> toVector() const;
};

template<class T>
DoublyNode<T>* DoublyLinkedBag<T>::getPtrTo(const T& target) const {
    if (headPtr == nullptr) return nullptr;

    DoublyNode<T>* curr = headPtr;

    while (curr != nullptr) {
        if (curr->getItem() == target) return curr;
        curr = curr->getNext();
    }

    return nullptr;
}

template<class T>
DoublyLinkedBag<T>::DoublyLinkedBag(): itemCount(0), headPtr(nullptr) {

}

template<class T>
DoublyLinkedBag<T>::DoublyLinkedBag(const DoublyLinkedBag<T>& other) {
    if (other.hppeadPtr == nullptr) return;

    itemCount = other.itemCount;

    headPtr = nullptr;

    DoublyNode<T>* curr = other.hppeadPtr;

    while (curr != nullptr) {
        this->add(curr->getItem());
        curr = curr->getNext();
    }
}

template<class T>
DoublyLinkedBag<T>::~DoublyLinkedBag() {
    clear();
}

template<class T>
int DoublyLinkedBag<T>::getCurrentSize() const {
    return itemCount;
}

template<class T>
bool DoublyLinkedBag<T>::isEmpty() const {
    return itemCount == 0;
}

template<class T>
bool DoublyLinkedBag<T>::add(const T& newEntry) {
    if (headPtr == nullptr) {
        headPtr = new DoublyNode<T>(newEntry);
        itemCount++;
        return true;
    }

    DoublyNode<T>* temp = new DoublyNode<T>(newEntry);

    temp->setNext(headPtr);
    headPtr->setPrevious(temp);

    headPtr = temp;

    itemCount++;
    return true;
}

template<class T>
bool DoublyLinkedBag<T>::remove(const T& entry) {
    DoublyNode<T>* curr = getPtrTo(entry);

    if (curr == nullptr) return false;
    if (curr == headPtr) {
        headPtr = curr->getNext();

        delete curr;
        curr = nullptr;

        headPtr->setPrevious(nullptr);
        itemCount--;

        return true;
    }

    DoublyNode<T>* prev = curr->getPrevious();
    DoublyNode<T>* next = curr->getNext();

    prev->setNext(next);
    if (next != nullptr) next->setPrevious(prev);

    delete curr;
    curr = nullptr;
    itemCount--;

    return true;
}

template<class T>
void DoublyLinkedBag<T>::clear() {
    if (headPtr == nullptr) return;

    DoublyNode<T>* curr = headPtr;
    
    while (curr != nullptr) {
        DoublyNode<T>* next = curr->getNext();

        delete curr;

        curr = next;
    }
    itemCount = 0;
    headPtr = nullptr;
}

template<class T>
int DoublyLinkedBag<T>::getFrequencyOf(const T& entry) const {
    int count = 0;
    if (headPtr == nullptr) return count;

    DoublyNode<T>* curr = headPtr;

    while (curr != nullptr) {
        if (curr->getItem() == entry) count++;
        curr = curr->getNext();
    }

    return count;
}

template<class T>
bool DoublyLinkedBag<T>::contains(const T& entry) const {
    return getPtrTo(entry) != nullptr;
}

template<class T>
vector<T> DoublyLinkedBag<T>::toVector() const {
    vector<T> result;

    if (headPtr == nullptr) return result;

    DoublyNode<T>* curr = headPtr;

    while (curr != nullptr) {
        result.push_back(curr->getItem());
        curr = curr->getNext();
    }

    return result;
}

#endif