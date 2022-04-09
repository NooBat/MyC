#ifndef _LINKED_LIST
#define _LINKED_LIST

#include<assert.h>
#include<string>
#include "ListInterface.hpp"
#include "../PrecondViolatedException.hpp"
#include "../Node.hpp"

template<class T>
class LinkedList : public ListInterface<T> 
{
private:
    Node<T>* headPtr;
    
    int itemCount;

    Node<T>* getNodeAt(int position) const;

    Node<T>* insertNode(Node<T>* headPtr, const T& newEntry);

    int getPositionRecur(Node<T>* headPtr, const T& targetEntry, int count) const;

    Node<T>* merge(Node<T>* firstHalf, Node<T>* secondHalf);

    Node<T>* mergeSort(int first, int last);

public:
    LinkedList();

    LinkedList(T arr[], int n);

    LinkedList(Node<T>* head);

    LinkedList(ListInterface<T>* aList);

    virtual ~LinkedList();

    bool isEmpty() const;

    int getLength() const;

    bool insert(int newPosition, const T& newEntry);

    bool remove(int position);

    void clear();

    T getEntry(int position) const;

    void setEntry(int position, const T& newEntry);

    int getPosition(const T& targetEntry) const;

    void sort();

    Node<T>* getHead() const;

    int sumOfNode(Node<T>* curr);

    friend void sort(LinkedList<string>& aList);

    friend void sumList(LinkedList<int>& aList);
};

//private methods:

template<class T>
Node<T>* LinkedList<T>::getNodeAt(int position) const {
    assert( (position >= 1) && (position <= itemCount) );

    Node<T>* currPtr = headPtr;  

    for (int skip = 1; skip < position; skip++) {
        currPtr = currPtr->getNext();
    }

    return currPtr;
}

template<class T>
Node<T>* LinkedList<T>::insertNode(Node<T>* headPtr, const T& newEntry) {
    if (headPtr == nullptr) {
        Node<T>* newNodePtr = new Node<T>(newEntry);
        headPtr = newNodePtr;
        newNodePtr = nullptr;
        return headPtr;
    }

    headPtr->setNext(insertNode(headPtr->getNext(), newEntry));

    return headPtr;
}

template<class T>
int LinkedList<T>::getPositionRecur(Node<T>* headPtr, const T& targetEntry, int count) const {
    if (headPtr == nullptr) return -1;
    else if (headPtr->getItem() == targetEntry) return count;

    return getPositionRecur(headPtr->getNext(), targetEntry, count + 1);
}

template<class T>
Node<T>* LinkedList<T>::merge(Node<T>* firstHalf, Node<T>* secondHalf) 
{
    Node<T>* head = nullptr;

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

template<class T>
Node<T>* LinkedList<T>::mergeSort(int first, int last) 
{
    if (first >= last)
    {
        Node<T>* temp = new Node<T>(getEntry(first + 1));
        return temp;
    }

    int mid = first + (last - first) / 2;
    Node<T>* firstHalf = mergeSort(first, mid);

    Node<T>* secondHalf = mergeSort(mid + 1, last);

    return merge(firstHalf, secondHalf);
}

template<class T>
int LinkedList<T>::sumOfNode(Node<T>* currPtr)
{
    if (!currPtr) return 0;

    currPtr->setItem(currPtr->getItem() + sumOfNode(currPtr->getNext()));

    return currPtr->getItem();
}

//public methods:

template<class T>
LinkedList<T>::LinkedList(): headPtr(nullptr), itemCount(0) {

}

template<class T>
LinkedList<T>::LinkedList(T arr[], int n) {
    headPtr = new Node<T>(arr[0]);

    Node<T>* currPtr = headPtr;

    for (int i = 1; i < n; i++) {
        Node<T>* newListPtr = new Node<T>(arr[i]);

        currPtr->setNext(newListPtr);

        currPtr = currPtr->getNext();

        newListPtr = nullptr;
    }

    currPtr->setNext(nullptr);

    currPtr = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(Node<T>* head)
{
    headPtr = head;
}

template<class T>
LinkedList<T>::LinkedList(ListInterface<T>* aList) {
    if (aList->getLength() == 0) {
        headPtr = nullptr;
        return;
    }

    headPtr = nullptr;

    this->itemCount = aList->getLength();

    for (int i = 1; i <= itemCount; i++) {
        headPtr = insertNode(headPtr, aList->getEntry(i));
    }
}

template<class T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<class T>
bool LinkedList<T>::isEmpty() const {
    return itemCount == 0;
}

template<class T>
int LinkedList<T>::getLength() const {
    return itemCount;
}

template<class T>
bool LinkedList<T>::insert(int newPosition, const T& newEntry) {
    if ( newPosition < 1 || newPosition > itemCount + 1 ) return false;

    Node<T>* newNodePtr = new Node<T>(newEntry);

    if (newPosition == 1) {
        newNodePtr->setNext(headPtr);
        headPtr = newNodePtr;
    }
    else {
        Node<T>* prevPtr = getNodeAt(newPosition - 1);

        newNodePtr->setNext(prevPtr->getNext());
        prevPtr->setNext(newNodePtr);

        prevPtr = nullptr;
    }

    itemCount++;

    return true;
}

template<class T>
bool LinkedList<T>::remove(int position) {
    if (position < 1 || position > itemCount) return false;

    Node<T>* currPtr = nullptr;

    if (position == 1) {
        currPtr = headPtr;
        headPtr = headPtr->getNext();
    }
    else {
        Node<T>* prevPtr = getNodeAt(position - 1);
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

template<class T>
void LinkedList<T>::clear() {
    if (headPtr == nullptr) return;

    Node<T>* currPtr = headPtr;

    while (currPtr != nullptr) {
        Node<T>* nextPtr = currPtr->getNext();

        currPtr->setNext(nullptr);
        delete currPtr;

        currPtr = nextPtr;
    }

    itemCount = 0;
    headPtr = nullptr;
}

template<class T>
T LinkedList<T>::getEntry(int position) const {
    if (position < 1 || position > itemCount) {
        string message = "getEntry() was called with an empty list or ";
        message += "invalid position.";
        throw(PrecondViolatedException(message));
    }

    Node<T>* currPtr = getNodeAt(position);

    return currPtr->getItem();
}

template<class T>
void LinkedList<T>::setEntry(int position, const T& newEntry) {
    if (position < 1 || position > itemCount) {
        string message = "setEntry() was called with an empty list or ";
        message += "invalid position.";
        throw(PrecondViolatedException(message));
    }

    Node<T>* currPtr = getNodeAt(position);

    currPtr->setItem(newEntry);

    currPtr = nullptr;
}

template<class T>
int LinkedList<T>::getPosition(const T& targetEntry) const {
    Node<T>* currPtr = headPtr;
    int count = 1;

    return getPositionRecur(currPtr, targetEntry, count);
}

template<class T>
void LinkedList<T>::sort() 
{
    Node<T>* temp = nullptr;
    temp = mergeSort(0, itemCount - 1);
    clear();

    headPtr = temp;
}

template<class T>
Node<T>* LinkedList<T>::getHead() const
{
    return headPtr;
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

void sumList(LinkedList<int>* aList)
{
    int a = aList->sumOfNode(aList->getHead());
}

#endif