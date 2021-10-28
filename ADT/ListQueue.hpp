#ifndef _LIST_QUEUE
#define _LIST_QUEUE

#include "QueueInterface.hpp"
#include "LinkedList.hpp"
#include "PrecondViolatedException.hpp"
#include<string>

using namespace std;

template<class ItemType>
class ListQueue : public QueueInterface<ItemType>
{
private:
    LinkedList<ItemType>* listPtr;

public:
    ListQueue();
    ListQueue(const ListQueue& aQueue);
    virtual ~ListQueue();
    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const;
};

template<class ItemType>
ListQueue<ItemType>::ListQueue()
{
    listPtr = new LinkedList<ItemType>();
}

template<class ItemType>
ListQueue<ItemType>::ListQueue(const ListQueue& aQueue)
{
    listPtr = new LinkedList<ItemType>(aQueue.listPtr);
}

template<class ItemType>
ListQueue<ItemType>::~ListQueue()
{
    listPtr->clear();
    listPtr = nullptr;
}

template<class ItemType>
bool ListQueue<ItemType>::isEmpty() const
{
    return listPtr->isEmpty();
}

template<class ItemType>
bool ListQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    int lastPosition = listPtr->getLength();
    return listPtr->insert(lastPosition + 1, newEntry);
}

template<class ItemType>
ItemType ListQueue<ItemType>::peekFront() const
{
    if (listPtr->getLength() == 0)
    {
        string message = "peekFront() was called with an empty queue!";
        throw PrecondViolatedException(message);
    }

    return listPtr->getItem(1);
}
#endif