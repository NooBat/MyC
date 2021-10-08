#ifndef _OUR_QUEUE
#define _OUR_QUEUE

#include<queue>
#include<string>
#include "/Users/danielnguyen/Repo/C++/ADT/PrecondViolatedException.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/QueueInterface.hpp"

using namespace std;

template<class ItemType>
class OurQueue : public QueueInterface<ItemType>
{
private:
    queue<ItemType>* aQueue;

public:
    OurQueue()
    {
        aQueue = new queue<ItemType>();
    }

    ~OurQueue()
    {
        delete aQueue;
        aQueue = nullptr;
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
            string msg = "peekFront() was called with an empty queue.";
            throw PrecondViolatedException(msg);
        }

        return aQueue->front();
    }
};

#endif