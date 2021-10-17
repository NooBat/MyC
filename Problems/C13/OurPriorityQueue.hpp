#ifndef _OUR_PRIORITY_QUEUE
#define _OUR_PRIORITY_QUEUE

#include<queue>
#include<vector>
#include<string>
#include "/Users/danielnguyen/Repo/C++/ADT/PrecondViolatedException.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/PriorityQueueInterface.hpp"

using namespace std;

template<class ItemType, class Comparator>
class OurPriorityQueue : public PriorityQueueInterface<ItemType>
{
private:
    priority_queue<ItemType, vector<ItemType>, Comparator>* aQueue;

public:
    OurPriorityQueue()
    {
        aQueue = new priority_queue<ItemType, vector<ItemType>, Comparator >();
    }

    OurPriorityQueue(bool (*func)(ItemType, ItemType))
    {
        aQueue = new priority_queue<ItemType, vector<ItemType>, decltype(func) >();
    }

    OurPriorityQueue(OurPriorityQueue<ItemType, Comparator>& other)
    {
        vector<ItemType> temp;
        aQueue = new priority_queue<ItemType, vector<ItemType>, Comparator >();

        while (!other.aQueue->empty())
        {
            temp.push_back(other.aQueue->top());

            other.aQueue->pop();
        }

        for (int i = 0; i < temp.size(); i++)
        {
            aQueue->push(temp[i]);
            other.aQueue->push(temp[i]);
        }
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