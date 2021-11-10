#ifndef _LINKED_SORTED_LIST
#define _LINKED_SORTED_LIST

#include "/Users/danielnguyen/Repo/C++/ADT/SortedListInterface.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/Node.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/PrecondViolatedException.hpp"

#include<string>

using namespace std;

template<class T>
class LinkedSortedList : public SortedListInterface<T>
{
private:
    Node<T>* headPtr;

    int itemCount;

    /** Returns a pointer to a copy of the chain to which origChainPtr points. */
    Node<T>* copyChain(Node<T>* head);

    /** Locates the node that is before the node that should or does
     * contain the given entry.
     * @param anEntry The entry to find.
     * @return Either a pointer to the node before the node that contains
     * or should contain the given entry, or nullptr if no prior node exists. */
    Node<T>* getNodeBefore(const T& anEntry) const;

    /** Locates the node at a given position within the chain. */
    Node<T>* getNodeAt(int position) const;

public:
    LinkedSortedList();

    LinkedSortedList(const LinkedSortedList<T>& aList);

    LinkedSortedList(const SortedListInterface<T>* aList);

    virtual ~LinkedSortedList();

    bool isEmpty() const;

    int getLength() const;

    void insertSorted(const T& newEntry);

    bool removeSorted(const T& anEntry);

    bool remove(int position);

    void clear();

    int getPosition(const T& anEntry);

    T getEntry(int position) const;
};

//private methods
template<class T>
Node<T>* LinkedSortedList<T>::copyChain(Node<T>* head)
{
    if (head == nullptr) {
        itemCount = 0;
        return nullptr;
    }

    Node<T>* copiedChainPtr = new Node<T>(head->getItem());

    copiedChainPtr->setNext(copyChain(head->getNext()));
    itemCount++;

    return copiedChainPtr;
}

template<class T>
Node<T>* LinkedSortedList<T>::getNodeBefore(const T& anEntry) const
{
    Node<T>* currPtr = headPtr;
    Node<T>* prevPtr = nullptr;

    while (currPtr != nullptr && anEntry > currPtr->getItem())
    {
        prevPtr = currPtr;
        currPtr = currPtr->getNext();
    }

    return prevPtr;
}

template<class T>
Node<T>* LinkedSortedList<T>::getNodeAt(int position) const
{
    if (position < 1 || position > itemCount) return nullptr;

    Node<T>* currPtr = headPtr;

    for (int i = 1; i < position; i++)
    {
        currPtr = currPtr->getNext();
    }

    return currPtr;
}


//public methods:

template<class T>
LinkedSortedList<T>::LinkedSortedList(): 
                            headPtr(nullptr), itemCount(0)
{

}

template<class T>
LinkedSortedList<T>::LinkedSortedList(const LinkedSortedList<T>& aList)
{
    headPtr = copyChain(aList.hppeadPtr);
}

template<class T>
LinkedSortedList<T>::LinkedSortedList(const SortedListInterface<T>* aList)
{
    itemCount = 0;
    headPtr = nullptr;

    for (int i = 1; i <= aList->getLength(); i++)
    {
        insertSorted(aList->getEntry(i));
    }
}

template<class T>
LinkedSortedList<T>::~LinkedSortedList()
{
    clear();
}

template<class T>
bool LinkedSortedList<T>::isEmpty() const
{
    return itemCount == 0;
}

template<class T>
int LinkedSortedList<T>::getLength() const
{
    return itemCount;
}

template<class T>
void LinkedSortedList<T>::insertSorted(const T& newEntry)
{
    Node<T>* newNodePtr = new Node<T>(newEntry);
    Node<T>* prevPtr = getNodeBefore(newEntry);

    if (headPtr == nullptr || prevPtr == nullptr)
    {
        newNodePtr->setNext(headPtr);
        headPtr = newNodePtr;
    }
    else
    {
        Node<T>* nextPtr = prevPtr->getNext();

        newNodePtr->setNext(nextPtr);

        prevPtr->setNext(newNodePtr);
    }

    newNodePtr = nullptr;
    itemCount++;
}

template<class T>
bool LinkedSortedList<T>::removeSorted(const T& anEntry)
{
    Node<T>* currPtr = headPtr;
    Node<T>* prevPtr = nullptr;
    
    bool isRemoved = false;

    while (currPtr != nullptr) 
    {
        Node<T>* nextPtr = currPtr->getNext();

        if (currPtr->getItem() == anEntry) 
        {
            if (prevPtr != nullptr) prevPtr->setNext(nextPtr);

            currPtr->setNext(nullptr);
            delete currPtr;

            currPtr = nullptr;
            isRemoved = true;
            break;
        }

        prevPtr = currPtr;
        currPtr = nextPtr;
    }

    if (isRemoved) itemCount--;

    return isRemoved;
}

template<class T>
bool LinkedSortedList<T>::remove(int position)
{
    if (position < 1 || position > itemCount) return false;

    Node<T>* currPtr = nullptr;
    if (position == 1) 
    {
        currPtr = headPtr;

        headPtr = headPtr->getNext();
    }
    else
    {
        Node<T>* prevPtr = getNodeAt(position - 1);
        Node<T>* nextPtr = getNodeAt(position + 1);

        prevPtr->setNext(nextPtr);
    }

    currPtr->setNext(nullptr);
    delete currPtr;
    itemCount--;

    return true;
}

template<class T>
void LinkedSortedList<T>::clear() 
{
    Node<T>* currPtr = headPtr;

    while (currPtr != nullptr)
    {
        Node<T>* nextPtr = currPtr->getNext();

        currPtr->setNext(nullptr);
        delete currPtr;

        currPtr = nextPtr;
    }

    itemCount = 0;
    headPtr = nullptr;
}

template<class T>
int LinkedSortedList<T>::getPosition(const T& anEntry)
{
    int position = 1;

    Node<T>* currPtr = headPtr;
    Node<T>* prevPtr = nullptr;

    while (currPtr != nullptr && currPtr->getItem() < anEntry)
    {
        position++;
        prevPtr = currPtr;
        currPtr = currPtr->getNext();
    }

    if (currPtr == nullptr || currPtr->getItem() > anEntry) return 0 - position;
    return position;
}

template<class T>
T LinkedSortedList<T>::getEntry(int position) const
{
    if (position < 1 || position > itemCount) {
        string message = "getEntry() was called with an empty list or invalid position.";
        throw PrecondViolatedException(message);
    }

    Node<T>* currPtr = getNodeAt(position);

    return currPtr->getItem();
}

#endif