#ifndef _LINKED_SORTED_LIST
#define _LINKED_SORTED_LIST

#include "/Users/danielnguyen/Repo/C++/ADT/SortedListInterface.h"
#include "/Users/danielnguyen/Repo/C++/ADT/Node.h"
#include "/Users/danielnguyen/Repo/C++/ADT/PrecondViolatedException.h"

#include<string>

using namespace std;

template<class ItemType>
class LinkedSortedList : public SortedListInterface<ItemType>
{
private:
    Node<ItemType>* headPtr;

    int itemCount;

    /** Returns a pointer to a copy of the chain to which origChainPtr points. */
    Node<ItemType>* copyChain(Node<ItemType>* head);

    /** Locates the node that is before the node that should or does
     * contain the given entry.
     * @param anEntry The entry to find.
     * @return Either a pointer to the node before the node that contains
     * or should contain the given entry, or nullptr if no prior node exists. */
    Node<ItemType>* getNodeBefore(const ItemType& anEntry) const;

    /** Locates the node at a given position within the chain. */
    Node<ItemType>* getNodeAt(int position) const;

public:
    LinkedSortedList();

    LinkedSortedList(const LinkedSortedList<ItemType>& aList);

    LinkedSortedList(const SortedListInterface<ItemType>* aList);

    virtual ~LinkedSortedList();

    bool isEmpty() const;

    int getLength() const;

    void insertSorted(const ItemType& newEntry);

    bool removeSorted(const ItemType& anEntry);

    bool remove(int position);

    void clear();

    int getPosition(const ItemType& anEntry);

    ItemType getEntry(int position) const;
};

//private methods
template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::copyChain(Node<ItemType>* head)
{
    if (head == nullptr) {
        itemCount = 0;
        return nullptr;
    }

    Node<ItemType>* copiedChainPtr = new Node<ItemType>(head->getItem());

    copiedChainPtr->setNext(copyChain(head->getNext()));
    itemCount++;

    return copiedChainPtr;
}

template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
{
    Node<ItemType>* currPtr = headPtr;
    Node<ItemType>* prevPtr = nullptr;

    while (currPtr != nullptr && anEntry > currPtr->getItem())
    {
        prevPtr = currPtr;
        currPtr = currPtr->getNext();
    }

    return prevPtr;
}

template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::getNodeAt(int position) const
{
    if (position < 1 || position > itemCount) return nullptr;

    Node<ItemType>* currPtr = headPtr;

    for (int i = 1; i < position; i++)
    {
        currPtr = currPtr->getNext();
    }

    return currPtr;
}


//public methods:

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(): 
                            headPtr(nullptr), itemCount(0)
{

}

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& aList)
{
    headPtr = copyChain(aList.headPtr);
}

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const SortedListInterface<ItemType>* aList)
{
    itemCount = 0;
    headPtr = nullptr;

    for (int i = 1; i <= aList->getLength(); i++)
    {
        insertSorted(aList->getEntry(i));
    }
}

template<class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList()
{
    clear();
}

template<class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template<class ItemType>
int LinkedSortedList<ItemType>::getLength() const
{
    return itemCount;
}

template<class ItemType>
void LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry)
{
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
    Node<ItemType>* prevPtr = getNodeBefore(newEntry);

    if (headPtr == nullptr || prevPtr == nullptr)
    {
        newNodePtr->setNext(headPtr);
        headPtr = newNodePtr;
    }
    else
    {
        Node<ItemType>* nextPtr = prevPtr->getNext();

        newNodePtr->setNext(nextPtr);

        prevPtr->setNext(newNodePtr);
    }

    newNodePtr = nullptr;
    itemCount++;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType& anEntry)
{
    Node<ItemType>* currPtr = headPtr;
    Node<ItemType>* prevPtr = nullptr;
    
    bool isRemoved = false;

    while (currPtr != nullptr) 
    {
        Node<ItemType>* nextPtr = currPtr->getNext();

        if (currPtr->getItem() == anEntry) 
        {
            if (prevPtr != nullptr) prevPtr->setNext(nextPtr);

            currPtr->setNext(nullptr);
            delete currPtr;

            headPtr = nextPtr;
            isRemoved = true;
            break;
        }

        prevPtr = currPtr;
        currPtr = nextPtr;
    }

    if (isRemoved) itemCount--;

    return isRemoved;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::remove(int position)
{
    if (position < 1 || position > itemCount) return false;

    Node<ItemType>* currPtr = nullptr;
    if (position == 1) 
    {
        currPtr = headPtr;

        headPtr = headPtr->getNext();
    }
    else
    {
        Node<ItemType>* prevPtr = getNodeAt(position - 1);
        Node<ItemType>* nextPtr = getNodeAt(position + 1);

        prevPtr->setNext(nextPtr);
    }

    currPtr->setNext(nullptr);
    delete currPtr;
    itemCount--;

    return true;
}

template<class ItemType>
void LinkedSortedList<ItemType>::clear() 
{
    Node<ItemType>* currPtr = headPtr;

    while (currPtr != nullptr)
    {
        Node<ItemType>* nextPtr = currPtr->getNext();

        currPtr->setNext(nullptr);
        delete currPtr;

        currPtr = nextPtr;
    }

    itemCount = 0;
    headPtr = nullptr;
}

template<class ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType& anEntry)
{
    int position = 1;

    Node<ItemType>* currPtr = headPtr;
    Node<ItemType>* prevPtr = nullptr;

    while (currPtr != nullptr && currPtr->getItem() < anEntry)
    {
        position++;
        prevPtr = currPtr;
        currPtr = currPtr->getNext();
    }

    if (currPtr == nullptr || currPtr->getItem() > anEntry) return 0 - position;
    return position;
}

template<class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const
{
    if (position < 1 || position > itemCount) {
        string message = "getEntry() was called with an empty list or invalid position.";
        throw PrecondViolatedException(message);
    }

    Node<ItemType>* currPtr = getNodeAt(position);

    return currPtr->getItem();
}

#endif