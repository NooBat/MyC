#ifndef _FRONT_LIST
#define _FRONT_LIST

#include "/Users/danielnguyen/Repo/C++/ADT//Users/danielnguyen/Repo/C++/ADT/Node.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/PrecondViolatedException.hpp"

using namespace std;

template<class T>
class FrontList
{
private:
    Node<T>* headPtr;
    int itemCount;

public:
    FrontList();

    virtual bool isEmpty() const;

    virtual int getLength() const;

    virtual bool insert(const T& newEntry);

    virtual bool remove();

    virtual void clear();

    virtual T getEntry() const;
};

template<class T>
FrontList<T>::FrontList()
{
    headPtr = nullptr;
    itemCount = 0;
}

template<class T>
bool FrontList<T>::isEmpty() const
{
    return itemCount == 0;
}

template<class T>
int FrontList<T>::getLength() const
{
    return itemCount;
}

template<class T>
bool FrontList<T>::insert(const T& newEntry)
{
    Node<T>* newNodePtr = new Node<T>(newEntry);

    newNodePtr->setNext(headPtr);

    headPtr = newNodePtr;

    itemCount++;

    return true;
}

template<class T>
bool FrontList<T>::remove()
{
    if (itemCount == 0) return false;
    Node<T>* targetNodePtr = headPtr;

    headPtr = headPtr->getNext();

    targetNodePtr->setNext(nullptr);
    delete targetNodePtr;
    targetNodePtr = nullptr;

    itemCount--;

    return true;
}

template<class T>
void FrontList<T>::clear()
{
    if (headPtr == nullptr) return;

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
T FrontList<T>::getEntry() const
{
    if (itemCount == 0) 
    {
        string message = "getEntry() was called with an empty list.";
        throw PrecondViolatedException(message);
    }
    else return headPtr->getItem();
}

#endif