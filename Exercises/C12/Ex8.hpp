#ifndef _FRONT_LIST
#define _FRONT_LIST

#include "/Users/danielnguyen/Repo/C++/ADT/Node.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/PrecondViolatedException.hpp"

using namespace std;

template<class ItemType>
class FrontList
{
private:
    Node<ItemType>* headPtr;
    int itemCount;

public:
    FrontList();

    virtual bool isEmpty() const;

    virtual int getLength() const;

    virtual bool insert(const ItemType& newEntry);

    virtual bool remove();

    virtual void clear();

    virtual ItemType getEntry() const;
};

template<class ItemType>
FrontList<ItemType>::FrontList()
{
    headPtr = nullptr;
    itemCount = 0;
}

template<class ItemType>
bool FrontList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template<class ItemType>
int FrontList<ItemType>::getLength() const
{
    return itemCount;
}

template<class ItemType>
bool FrontList<ItemType>::insert(const ItemType& newEntry)
{
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

    newNodePtr->setNext(headPtr);

    headPtr = newNodePtr;

    itemCount++;

    return true;
}

template<class ItemType>
bool FrontList<ItemType>::remove()
{
    if (itemCount == 0) return false;
    Node<ItemType>* targetNodePtr = headPtr;

    headPtr = headPtr->getNext();

    targetNodePtr->setNext(nullptr);
    delete targetNodePtr;
    targetNodePtr = nullptr;

    itemCount--;

    return true;
}

template<class ItemType>
void FrontList<ItemType>::clear()
{
    if (headPtr == nullptr) return;

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
ItemType FrontList<ItemType>::getEntry() const
{
    if (itemCount == 0) 
    {
        string message = "getEntry() was called with an empty list.";
        throw PrecondViolatedException(message);
    }
    else return headPtr->getItem();
}

#endif