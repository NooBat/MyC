#ifndef _SET
#define _SET

#include "/Users/danielnguyen/Repo/C++/ADT/BagInterface.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/Node.hpp"
#include<iostream>

using namespace std;

template<class T>
class Set : public BagInterface<T> {
private:
    int itemCount;
    Node<T>* head_ptr;

    Node<T>* getPointerTo(const T& target);
public:
    Set();

    Set(const Set<T>& other);

    virtual ~Set();

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
Node<T>* Set<T>::getPointerTo(const T& target) {
    if (!contains(target)) return nullptr;

    Node<T>* p = head_ptr;

    while (p != nullptr) {
        if (p->getItem() == target) return p;
        p = p->next;
    }

    return nullptr;
}

template<class T>
Set<T>::Set(): itemCount(0), head_ptr(nullptr) {

}

template<class T>
Set<T>::Set(const Set<T>& other) {
    itemCount = other.itemCount;

    if (other.hppead_ptr == nullptr) head_ptr = nullptr;
    else {
        Node<T>* temp = other.hppead_ptr;

        while (temp != nullptr) {
            add(temp->getItem());
            temp = temp->getNext();
        }
    }
}

template<class T>
Set<T>::~Set() {
    clear();
}

template<class T>
int Set<T>::getCurrentSize() const {
    return this->itemCount;
}

template<class T>
bool Set<T>::isEmpty() const {
    return itemCount == 0;
}

template<class T>
bool Set<T>::add(const T& newEntry) {
    if (contains(newEntry)) return false;
    if (head_ptr == nullptr) {
        head_ptr = new Node<T>(newEntry);
        return true;
    }
    Node<T>* temp = new Node<T>(newEntry);

    temp->next = head_ptr;

    head_ptr = temp;

    itemCount++;

    return true;
}

template<class T>
bool Set<T>::remove(const T& entry) {
    if (!contains(entry)) return false;
    if (isEmpty()) return false;

    Node<T>* curr = getPointerTo(entry);

    if (curr == nullptr) return false;

    if (curr == head_ptr) {
        head_ptr = head_ptr->getNext();

        delete curr;
        curr = nullptr;
        itemCount--;

        return true;
    }

    Node<T>* prev = head_ptr;
    Node<T>* next = curr->getNext();
    while (prev->getNext() != curr) {
        prev = prev->getNext();
    }

    delete curr;
    curr = nullptr;

    prev->setNext(next);
    itemCount--;

    return true;
}

template<class T>
void Set<T>::clear() {
    if (head_ptr == nullptr) return;

    itemCount = 0;

    Node<T>* p = head_ptr;

    while (p != nullptr) {
        Node<T>* next = p->getNext();

        delete p;

        p = next;
    }

    head_ptr = nullptr;
}

template<class T>
int Set<T>::getFrequencyOf(const T& entry) const {
    int count = 0;

    Node<T>* p = head_ptr;

    while (p != nullptr) {
        if (p->getItem() == entry) count++;
    }

    return count;
}

template<class T> 
bool Set<T>::contains(const T& entry) const {
    if (head_ptr == nullptr) return false;

    Node<T>* p = head_ptr;

    while (p != nullptr) {
        if (p->getItem() == entry) return true;
        p = p->getNext();
    }

    return false;
}

template<class T>
vector<T> Set<T>::toVector() const {
    vector<T> result;

    if (head_ptr == nullptr) return result;

    Node<T>* p = head_ptr;

    while (p != nullptr) {
        result.push_back(p->getItem());
        p = p->getNext();
    }

    return result;
}
#endif