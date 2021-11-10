#ifndef _LINKED_QUEUE
#define _LINKED_QUEUE

#include "QueueInterface.hpp"
#include "PrecondViolatedException.hpp"
#include "Node.hpp"
#include<string>
#include<vector>
<<<<<<< HEAD
=======
<<<<<<< HEAD
#include<vector>
=======
>>>>>>> 5786e7ca1abcca13190da876c2bf3b9550f9899f
>>>>>>> tk-obj-c
=======
>>>>>>> tk-obj-c

using namespace std;

template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType>
{
private:
    Node<ItemType>* headPtr;
    Node<ItemType>* tailPtr;

public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue<ItemType>& other);
    virtual ~LinkedQueue();

    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const;
    vector<ItemType> display() const;
    int getNumberOfElements() const;
<<<<<<< HEAD
=======
<<<<<<< HEAD
    vector<ItemType> display() const;
    int getNumberOfElements() const;
=======
>>>>>>> 5786e7ca1abcca13190da876c2bf3b9550f9899f
>>>>>>> tk-obj-c
=======
>>>>>>> tk-obj-c
};

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue()
{
    headPtr = nullptr;
    tailPtr = nullptr;
}

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue<ItemType>& other)
{
    headPtr = nullptr;
    tailPtr = nullptr;
    try
    {
        if (!other.isEmpty())
        {
            Node<ItemType>* currPtr = other.headPtr;
            headPtr = new Node<ItemType>(currPtr->getItem());
            tailPtr = headPtr;
            currPtr = currPtr->getNext();

            while (currPtr)
            {
                Node<ItemType>* newNodePtr = new Node<ItemType>(currPtr->getItem());
                tailPtr->setNext(newNodePtr);
                currPtr = currPtr->getNext();
                tailPtr = tailPtr->getNext();
            }
        }
    }
    catch(bad_alloc& e)
    {
        ~LinkedQueue();
        throw e.what();
    }
}

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
    Node<ItemType>* currPtr = headPtr;

    while (currPtr)
    {
        Node<ItemType>* nextPtr = currPtr->getNext();
        currPtr->setNext(nullptr);
        delete currPtr;

        currPtr = nextPtr;
    }

    headPtr = tailPtr = nullptr;
}

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
    return (headPtr == nullptr);
}

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
    if (!headPtr)
    {
        headPtr = tailPtr = newNodePtr;
    }
    else
    {
        tailPtr->setNext(newNodePtr);
        tailPtr = newNodePtr;
    }

    return true;
}

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
    if (isEmpty()) return false;

    Node<ItemType>* firstNode = headPtr;

    if (headPtr == tailPtr)
    {
        tailPtr = nullptr;
    }
    headPtr = headPtr->getNext();

    firstNode->setNext(nullptr);
    delete firstNode;
    firstNode = nullptr;

    return true;
}

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const
{
    if (this->isEmpty())
    {
        string message = "peekFront() was called with an empty queue";
        throw PrecondViolatedException(message);
    }

    return headPtr->getItem();
}

template<class ItemType>
vector<ItemType> LinkedQueue<ItemType>::display() const
{
    Node<ItemType>* currPtr = headPtr;
    vector<ItemType> result;
    while (currPtr != nullptr)
    {
        result.push_back(currPtr->getItem());
        currPtr = currPtr->getNext();
    }

    return result;
}

template<class ItemType>
int LinkedQueue<ItemType>::getNumberOfElements() const
{
    Node<ItemType>* currPtr = headPtr;
    int numOfItem = 0;

    while (currPtr)
    {
        ++numOfItem;
        currPtr = currPtr->getNext();
    }
}
#endif