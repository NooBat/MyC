#ifndef _LINKED_QUEUE
#define _LINKED_QUEUE

#include "QueueInterface.hpp"
#include "PrecondViolatedException.hpp"
#include "Node.hpp"

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

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
     
}

#endif