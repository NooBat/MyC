#ifndef _LINKED_LIST
#define _LINKED_LIST

#include<assert.h>
#include<string>
#include "ListInterface.h"
#include "PrecondViolatedException.h"
#include "Node.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType> {
private:
    Node<ItemType>* headPtr;
    
    int itemCount;

    Node<ItemType>* getNodeAt(int position) const;

    Node<ItemType>* insertNode(Node<ItemType>* headPtr, const ItemType& newEntry);

    int getPositionRecur(Node<ItemType>* headPtr, const ItemType& targetEntry, int count) const;

    Node<ItemType>* merge(Node<ItemType>* firstHalf, Node<ItemType>* secondHalf);

    Node<ItemType>* mergeSort(int first, int last);

public:
    LinkedList();

    LinkedList(ItemType arr[], int n);

    LinkedList(ListInterface<ItemType>* aList);

    virtual ~LinkedList();

    bool isEmpty() const;

    int getLength() const;

    bool insert(int newPosition, const ItemType& newEntry);

    bool remove(int position);

    void clear();

    ItemType getEntry(int position) const;

    void setEntry(int position, const ItemType& newEntry);

    int getPosition(const ItemType& targetEntry) const;

    void sort();

    friend void sort(LinkedList<string>& aList);
};

//private methods:

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
Node<ItemType>* LinkedList<ItemType>::insertNode(Node<ItemType>* headPtr, const ItemType& newEntry) {
    if (headPtr == nullptr) {
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
        headPtr = newNodePtr;
        newNodePtr = nullptr;
        return headPtr;
    }

    headPtr->setNext(insertNode(headPtr->getNext(), newEntry));

    return headPtr;
}

template<class ItemType>
int LinkedList<ItemType>::getPositionRecur(Node<ItemType>* headPtr, const ItemType& targetEntry, int count) const {
    if (headPtr == nullptr) return -1;
    else if (headPtr->getItem() == targetEntry) return count;

    return getPositionRecur(headPtr->getNext(), targetEntry, count + 1);
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::merge(Node<ItemType>* firstHalf, Node<ItemType>* secondHalf) 
{
    Node<ItemType>* head = nullptr;

    if (firstHalf == nullptr) 
    {
        return secondHalf;
    }
    else if (secondHalf == nullptr) 
    {
        return firstHalf;
    }

    if (firstHalf->getItem() <= secondHalf->getItem())
    {
        head = firstHalf;
        head->setNext(merge(firstHalf->getNext(), secondHalf));
    }
    else {
        head = secondHalf;
        head->setNext(merge(firstHalf, secondHalf->getNext()));
    }

    return head;
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::mergeSort(int first, int last) 
{
    if (first >= last)
    {
        Node<ItemType>* temp = new Node<ItemType>(getEntry(first + 1));
        return temp;
    }

    int mid = first + (last - first) / 2;
    Node<ItemType>* firstHalf = mergeSort(first, mid);

    Node<ItemType>* secondHalf = mergeSort(mid + 1, last);

    return merge(firstHalf, secondHalf);
}


//public methods:

template<class ItemType>
LinkedList<ItemType>::LinkedList(): headPtr(nullptr), itemCount(0) {

}

template<class ItemType>
LinkedList<ItemType>::LinkedList(ItemType arr[], int n) {
    headPtr = new Node<ItemType>(arr[0]);

    Node<ItemType>* currPtr = headPtr;

    for (int i = 1; i < n; i++) {
        Node<ItemType>* newListPtr = new Node<ItemType>(arr[i]);

        currPtr->setNext(newListPtr);

        currPtr = currPtr->getNext();

        newListPtr = nullptr;
    }

    currPtr->setNext(nullptr);

    currPtr = nullptr;
}

template<class ItemType>
LinkedList<ItemType>::LinkedList(ListInterface<ItemType>* aList) {
    if (aList->getLength() == 0) {
        headPtr = nullptr;
        return;
    }

    headPtr = nullptr;

    this->itemCount = aList->getLength();

    for (int i = 1; i <= aList->getLength(); i++) {
        headPtr = insertNode(headPtr, aList->getEntry(i));
    }
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

    itemCount = 0;
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

template<class ItemType>
int LinkedList<ItemType>::getPosition(const ItemType& targetEntry) const {
    Node<ItemType>* currPtr = headPtr;
    int count = 1;

    return getPositionRecur(currPtr, targetEntry, count);
}

template<class ItemType>
void LinkedList<ItemType>::sort() 
{
    Node<ItemType>* temp = nullptr;
    temp = mergeSort(0, itemCount - 1);
    clear();

    headPtr = temp;
}

void sort(LinkedList<string>& aList)
{
    int maxLetter = aList.getEntry(1).length();
    for (int i = 1; i < aList.getLength(); i++) 
    {
        if (aList.getEntry(i + 1).length() > maxLetter) 
        {
            maxLetter = aList.getEntry(i + 1).length();
        }
    }

    for (int letterIdx = maxLetter - 1; letterIdx >= 0; letterIdx--) 
    {   
        int position = 1;
        LinkedList<string> hash[27];

        for (int idx = 1; idx <= aList.getLength(); idx++) 
        {
            if (aList.getEntry(idx).length() > letterIdx) 
            {
                char letter = aList.getEntry(idx)[letterIdx];

                int listPosition = hash[letter - 'a' + 1].getLength();

                hash[letter - 'a' + 1].insert(listPosition + 1, aList.getEntry(idx));
            }
            else 
            {
                int listPosition = hash[0].getLength();

                hash[0].insert(listPosition + 1, aList.getEntry(idx));
            }
        }

        aList.clear();

        for (int i = 0; i < 27; i++) 
        {
            for (int j = 1; j <= hash[i].getLength(); j++) 
            {
                aList.insert(position, hash[i].getEntry(j));
                position++;
            }
            hash[i].clear();
        }
    }
}
#endif