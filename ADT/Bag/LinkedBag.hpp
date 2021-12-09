#ifndef _LINKED_BAG
#define _LINKED_BAG

#include "BagInterface.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/Node.hpp"

template<class T>
class LinkedBag : public BagInterface<T> {
private:
    int itemCount;
    Node<T>* head_ptr;

    /** Returns a pointer to the node contains given entry or a nullptr
     * @param target The entry needed to be find
     * @returns A pointer to node or nullptr */
    Node<T>* getPointerTo(const T& target) const;
public:
    LinkedBag();

    LinkedBag(const LinkedBag<T>& other);

    virtual ~LinkedBag();

    /** Gets the current number of entries in this bag.
     * @return The integer number of entries currently in the bag. */
    int getCurrentSize() const;

    /** Sees whether this bag is empty.
     * @return True if the bag is empty, or false if not. */
    bool isEmpty() const;

    /** Adds a new entry to this bag.
     * @post If successful, newEntry is stored in the bag and 
     * the count of items in the bag has increased by 1.
     * @param newEntry The object to be added as a new entry. 
     * @return True if addition was successful, or false if not. */
    bool add(const T& newEntry);

    /** Removes one occurrence of a given entry from this bag, if possible.
     * @post If successful, anEntry has been removed from the bag and 
     * the count of items in the bag has decreased by 1.
     * @param anEntry The entry to be removed.
     * @return True if removal was successful, or false if not. */
    bool remove(const T& anEntry);

    /** Removes all entries from this bag.
     * @post Bag contains no items, and the count of items is 0. */
    void clear();

    /** Counts the number of times a given entry appears in bag. 
     * @param anEntry The entry to be counted.
     * @return The number of times anEntry appears in the bag. */
    int getFrequencyOf(const T& target) const;

    /** Tests whether this bag contains a given entry.
     * @param anEntry The entry to locate.
     * @return True if bag contains anEntry, or false otherwise. */
    bool contains(const T& target) const;

    /** Empties and then fills a given vector with all entries that 
     * are in this bag.
     * @return A vector containing all the entries in the bag. */
    vector<T> toVector() const;

    /** Removes and returns the second node of the list
     * @pre Number of items in bag must be larger than 2
     * @returns The second node */
    Node<T>* removeSecond();
};

template<class T>
Node<T>* LinkedBag<T>::getPointerTo(const T& target) const {
    Node<T>* p = head_ptr;

    while (p != nullptr) {
        if (p->getItem() == target) return p;

        p = p->getNext();
    }

    return nullptr;
}

template<class T>
LinkedBag<T>::LinkedBag(): itemCount(0), head_ptr(nullptr) {
    //stubs
}

template<class T>
LinkedBag<T>::LinkedBag(const LinkedBag<T>& other) {
    itemCount = other.itemCount;

    if (other.hppead_ptr == NULL) head_ptr = nullptr;
    else {
        Node<T>* temp = other.hppead_ptr;

        while (temp != NULL) {
            add(temp->getItem());
            temp = temp->getNext();
        }
    }
}

template<class T>
LinkedBag<T>::~LinkedBag() {
    clear();
}

template<class T>
int LinkedBag<T>::getCurrentSize() const {
    return itemCount;
}

template<class T>
bool LinkedBag<T>::isEmpty() const {
    return (itemCount == 0);
}

template<class T>
bool LinkedBag<T>::add(const T& newEntry) {
    itemCount++;

    if (head_ptr == nullptr) {
        head_ptr = new Node<T>(newEntry);
        return true;
    }

    Node<T>* p = head_ptr;

    while (p->getNext() != nullptr) {
        p = p->getNext();
    }

    Node<T>* temp = new Node<T>(newEntry);

    p->setNext(temp);

    return true;
}

template<class T>
bool LinkedBag<T>::remove(const T& anEntry) {
    Node<T>* curr = getPointerTo(anEntry);

    if (isEmpty()) return false;
    if (curr == nullptr) return false;

    if (curr == head_ptr) {
        head_ptr = curr->getNext();
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

    prev->setNext(next);
    curr->setNext(nullptr);
    delete curr;

    itemCount--;

    return true;
}

template<class T>
void LinkedBag<T>::clear() {
    Node<T>* curr = head_ptr;

    while (curr != nullptr) {
        Node<T>* next = curr->getNext();

        delete curr;
    
        curr = next;
    }

    head_ptr = nullptr;

    itemCount = 0;
}

template<class T>
int LinkedBag<T>::getFrequencyOf(const T& target) const {
    int count = 0;

    Node<T>* p = head_ptr;

    while (p != nullptr) {
        if (p->getItem() == target) count++;
        p = p->getNext();
    }

    return count;
}

template<class T>
bool LinkedBag<T>::contains(const T& target) const {
    return (getPointerTo(target) != nullptr);
}

template<class T>
vector<T> LinkedBag<T>::toVector() const {
    Node<T>* p = head_ptr;

    vector<T> result;

    while (p != nullptr) {
        result.push_back(p->getItem());
        p = p->getNext();
    }

    return result;
}

template<class T>
Node<T>* LinkedBag<T>::removeSecond() {
    if (itemCount < 2) return nullptr;

    Node<T>* secondNode = head_ptr->getNext();
    Node<T>* thirdNode = secondNode->getNext();

    head_ptr->setNext(thirdNode);

    secondNode->setNext(nullptr);

    return secondNode;
}
#endif