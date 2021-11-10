#ifndef _SL_PRIORITY_QUEUE
#define _SL_PRIORITY_QUEUE

#include "PriorityQueueInterface.hpp"
#include "LinkedSortedList.hpp"
#include<string>
#include "PrecondViolatedException.hpp"

using namespace std;

template<class ItemType>
class SL_PriorityQueue : public PriorityQueueInterface<ItemType>
{
private:
    LinkedSortedList<ItemType>* sListPtr;
public:
    SL_PriorityQueue();
    SL_PriorityQueue(const SL_PriorityQueue& pq);
    virtual ~SL_PriorityQueue();

    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const;
};

template<class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue()
{
    sListPtr = new LinkedSortedList<ItemType>();
}

template<class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue(const SL_PriorityQueue& pq)
{
    if (pq.sListPtr->getLength() == 0) 
    {
        sListPtr = new LinkedSortedList<ItemType>();
    }
    else
    {
        for (int i = 0; i < pq.sListPtr->getLength(); ++i)
        {
            sListPtr->insertSorted(pq.sListPtr->getEntry(i));
        }
    }
}

template<class ItemType>
SL_PriorityQueue<ItemType>::~SL_PriorityQueue()
{
    sListPtr->clear();
    sListPtr = nullptr;
}

template<class ItemType>
bool SL_PriorityQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    return sListPtr->insertSorted(newEntry);
}

template<class ItemType>
bool SL_PriorityQueue<ItemType>::dequeue() 
{
    return sListPtr->remove(sListPtr->getLength());
}

template<class ItemType>
ItemType SL_PriorityQueue<ItemType>::peekFront() const
{
    if (sListPtr->isEmpty())
    {
        string msg = "peekFront() was called with an empty queue!";
        throw PrecondViolatedException(msg);
    }

    return sListPtr->getEntry(sListPtr->getLength());
}

#endif