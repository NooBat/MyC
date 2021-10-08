#ifndef _OUR_PRIORITY_QUEUE
#define _OUR_PRIORITY_QUEUE

#include<queue>
#include<string>
#include "/Users/danielnguyen/Repo/C++/ADT/PrecondViolatedException.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/PriorityQueueInterface.hpp"

using namespace std;

template<class ItemType>
class OurPriorityQueue : public PriorityQueueInterface<ItemType>
{
private:
    priority_queue<ItemType>* aQueue;

public:
    OurPriorityQueue()
    {
        aQueue = new priority_queue<ItemType>();
    }

    bool isEmpty() const
    {
        return aQueue->empty();
    }

    bool add(const ItemType& newEntry)
    {
        aQueue->push(newEntry);

        return true;
    }

    bool remove()
    {
        if (aQueue->empty) return false;

        aQueue->pop();
        return true;
    }

    ItemType peekFront() const
    {
        if (aQueue->empty()) 
        {
            string msg = "peekFront() was called with an empty priority queue.";
            throw PrecondViolatedException(msg);
        }

        return aQueue->front();
    }
};

#endif