#ifndef _SL_PRIORITY_QUEUE
#define _SL_PRIORITY_QUEUE

#include "PriorityQueueInterface.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/List/LinkedSortedList.hpp"
#include<string>
#include "/Users/danielnguyen/Repo/C++/ADT/PrecondViolatedException.hpp"

using namespace std;

template<class T>
class SL_PriorityQueue : public PriorityQueueInterface<T>
{
private:
    LinkedSortedList<T>* sListPtr;
public:
    SL_PriorityQueue();
    SL_PriorityQueue(const SL_PriorityQueue& pq);
    virtual ~SL_PriorityQueue();

    bool isEmpty() const;
    bool enqueue(const T& newEntry);
    bool dequeue();
    T peekFront() const;
};

template<class T>
SL_PriorityQueue<T>::SL_PriorityQueue()
{
    sListPtr = new LinkedSortedList<T>();
}

template<class T>
SL_PriorityQueue<T>::SL_PriorityQueue(const SL_PriorityQueue& pq)
{
    if (pq.sListPtr->getLength() == 0) 
    {
        sListPtr = new LinkedSortedList<T>();
    }
    else
    {
        for (int i = 0; i < pq.sListPtr->getLength(); ++i)
        {
            sListPtr->insertSorted(pq.sListPtr->getEntry(i));
        }
    }
}

template<class T>
SL_PriorityQueue<T>::~SL_PriorityQueue()
{
    sListPtr->clear();
    sListPtr = nullptr;
}

template<class T>
bool SL_PriorityQueue<T>::enqueue(const T& newEntry)
{
    return sListPtr->insertSorted(newEntry);
}

template<class T>
bool SL_PriorityQueue<T>::dequeue() 
{
    return sListPtr->remove(sListPtr->getLength());
}

template<class T>
T SL_PriorityQueue<T>::peekFront() const
{
    if (sListPtr->isEmpty())
    {
        string msg = "peekFront() was called with an empty queue!";
        throw PrecondViolatedException(msg);
    }

    return sListPtr->getEntry(sListPtr->getLength());
}

#endif