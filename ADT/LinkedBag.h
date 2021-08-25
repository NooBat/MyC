#ifndef _LINKED_BAG
#define _LINKED_BAG

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType> {
private:
    int itemCount;
    Node<ItemType>* head_ptr;

    /** Returns a pointer to the node contains given entry or a nullptr
     * @param target The entry needed to be find
     * @returns A pointer to node or nullptr */
    Node<ItemType>* getPointerTo(const ItemType& target) const;
public:
    LinkedBag();

    LinkedBag(const LinkedBag<ItemType>& other);

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
    bool add(const ItemType& newEntry);

    /** Removes one occurrence of a given entry from this bag, if possible.
     * @post If successful, anEntry has been removed from the bag and 
     * the count of items in the bag has decreased by 1.
     * @param anEntry The entry to be removed.
     * @return True if removal was successful, or false if not. */
    bool remove(const ItemType& anEntry);

    /** Removes all entries from this bag.
     * @post Bag contains no items, and the count of items is 0. */
    void clear();

    /** Counts the number of times a given entry appears in bag. 
     * @param anEntry The entry to be counted.
     * @return The number of times anEntry appears in the bag. */
    int getFrequencyOf(const ItemType& target) const;

    /** Tests whether this bag contains a given entry.
     * @param anEntry The entry to locate.
     * @return True if bag contains anEntry, or false otherwise. */
    bool contains(const ItemType& target) const;

    /** Empties and then fills a given vector with all entries that 
     * are in this bag.
     * @return A vector containing all the entries in the bag. */
    vector<ItemType> toVector() const;

    /** Removes and returns the second node of the list
     * @pre Number of items in bag must be larger than 2
     * @returns The second node */
    Node<ItemType>* removeSecond();
};

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& target) const {
    Node<ItemType>* p = head_ptr;

    while (p != nullptr) {
        if (p->getItem() == target) return p;

        p = p->getNext();
    }

    return nullptr;
}

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(): itemCount(0), head_ptr(nullptr) {
    //stubs
}

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& other) {
    itemCount = other.itemCount;

    if (other.head_ptr == NULL) head_ptr = nullptr;
    else {
        Node<ItemType>* temp = other.head_ptr;

        while (temp != NULL) {
            add(temp->getItem());
            temp = temp->getNext();
        }
    }
}

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag() {
    clear();
}

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
    return itemCount;
}

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
    return (itemCount == 0);
}

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry) {
    itemCount++;

    Node<ItemType>* newNode = new Node<ItemType>();

    newNode->setItem(newEntry);
    newNode->setNext(head_ptr);
    head_ptr = newNode;

    return true;
}

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry) {
    Node<ItemType>* curr = getPointerTo(anEntry);

    if (isEmpty()) return false;
    if (curr == nullptr) return false;

    if (curr == head_ptr) {
        head_ptr = curr->getNext();
        delete curr;
        curr = nullptr;

        return true;
    }

    Node<ItemType>* prev = head_ptr;
    Node<ItemType>* next = curr->getNext();

    while (prev->getNext() != curr) {
        prev = prev->getNext();
    }

    prev->setNext(next);
    curr->setNext(nullptr);
    delete curr;

    itemCount--;

    return true;
}

template<class ItemType>
void LinkedBag<ItemType>::clear() {
    Node<ItemType>* curr = head_ptr;

    while (curr != nullptr) {
        Node<ItemType>* next = curr->getNext();

        delete curr;
    
        curr = next;
    }

    head_ptr = nullptr;

    itemCount = 0;
}

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& target) const {
    int count = 0;

    Node<ItemType>* p = head_ptr;

    while (p != nullptr) {
        if (p->getItem() == target) count++;
        p = p->getNext();
    }

    return count;
}

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& target) const {
    return (getPointerTo(target) != nullptr);
}

template<class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const {
    Node<ItemType>* p = head_ptr;

    vector<ItemType> result;

    while (p != nullptr) {
        result.push_back(p->getItem());
        p = p->getNext();
    }

    return result;
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::removeSecond() {
    if (itemCount < 2) return nullptr;

    Node<ItemType>* secondNode = head_ptr->getNext();
    Node<ItemType>* thirdNode = secondNode->getNext();

    head_ptr->setNext(thirdNode);

    secondNode->setNext(nullptr);

    return secondNode;
}
#endif