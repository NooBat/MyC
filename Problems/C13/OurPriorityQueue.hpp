#ifndef _OUR_PRIORITY_QUEUE
#define _OUR_PRIORITY_QUEUE

#include<queue>
#include<vector>
#include<string>
#include "/Users/danielnguyen/Repo/C++/ADT/PrecondViolatedException.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/PriorityQueueInterface.hpp"

using namespace std;

template<class T, class Comparator>
class OurPriorityQueue : public PriorityQueueInterface<T>
{
private:
    priority_queue<T, vector<T>, Comparator>* aQueue;

public:
    OurPriorityQueue()
    {
        aQueue = new priority_queue<T, vector<T>, Comparator >();
    }

    OurPriorityQueue(bool (*func)(T, T))
    {
        aQueue = new priority_queue<T, vector<T>, decltype(func) >();
    }

    OurPriorityQueue(OurPriorityQueue<T, Comparator>& other)
    {
        vector<T> temp;
        aQueue = new priority_queue<T, vector<T>, Comparator >();

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

    bool enqueue(const T& newEntry)
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

    T peekFront() const
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