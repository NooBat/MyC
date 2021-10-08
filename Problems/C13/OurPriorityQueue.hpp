#ifndef _OUR_PRIORITY_QUEUE
#define _OUR_PRIORITY_QUEUE

#include<queue>
#include<vector>
#include<string>
#include "/Users/danielnguyen/Repo/C++/ADT/PrecondViolatedException.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/PriorityQueueInterface.hpp"

using namespace std;

template<class ItemType>
class OurPriorityQueue : public PriorityQueueInterface<ItemType>
{
private:
    priority_queue<ItemType, vector<ItemType>, greater<ItemType> >* aQueue;

public:
    OurPriorityQueue()
    {
        aQueue = new priority_queue<ItemType, vector<ItemType>, greater<ItemType> >();
    }

    bool isEmpty() const
    {
        return aQueue->empty();
    }

    bool enqueue(const ItemType& newEntry)
    {
        aQueue->push(newEntry);

        return true;
    }

    bool dequeue()
    {
        if (aQueue->empty()) return false;

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

        return aQueue->top();
    }
};

#endif