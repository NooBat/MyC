#ifndef _ARRAY_QUEUE
#define _ARRAY_QUEUE

#include "QueueInterface.hpp"
#include "PrecondViolatedException.hpp"
#include<string>

using namespace std;

const int MAX_QUEUE = 50;

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType>
{
private:
    ItemType items[MAX_QUEUE];
    int      front;
    int      back;
    int      count;
 
public:
    ArrayQueue();
    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const;
};

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue(): front(0), back(MAX_QUEUE - 1), count(0)
{

}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const 
{
    return count == 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    if (count == MAX_QUEUE) return false;

    back = (back + 1) % MAX_QUEUE;
    items[back] = newEntry;
    count++;
    return true;
}

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue()
{
    if (!count) return false;

    front = (front + 1) % MAX_QUEUE;
    count--;
    return true;
}

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const
{
    if (!count)
    {
        string msg = "peekFront() was called with a empty queue!";
        throw PrecondViolatedException(msg);
    }

    return items[front];
}

#endif