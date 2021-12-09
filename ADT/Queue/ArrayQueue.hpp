#ifndef _ARRAY_QUEUE
#define _ARRAY_QUEUE

#include "QueueInterface.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/PrecondViolatedException.hpp"

const int MAX_QUEUE = 50;

template<class T>
class ArrayQueue : public QueueInterface<T>
{
private:
    T   items[MAX_QUEUE];
    int front;
    int back;
    int count;

public:
    ArrayQueue();

    bool isEmpty() const;
    bool enqueue(const T& newEntry);
    bool dequeue();
    T peekFront() const;
    int getNumberOfElements() const;
};

template<class T>
ArrayQueue<T>::ArrayQueue(): front(0), count(0), back(MAX_QUEUE - 1)
{

}

template<class T>
bool ArrayQueue<T>::isEmpty() const
{
    return count == 0;
}

template<class T>
bool ArrayQueue<T>::enqueue(const T& newEntry)
{
    if (count == MAX_QUEUE) return false;

    count++;
    back = (back + 1) % MAX_QUEUE;
    items[back] = newEntry;

    return true;
}

template<class T>
bool ArrayQueue<T>::dequeue()
{
    if (!count) return false;

    count--;
    front = (front + 1) % MAX_QUEUE;
    return true;
}

template<class T>
T ArrayQueue<T>::peekFront() const
{
    if (!count)
    {
        string msg = "peekFront() was called with an empty queue!";
        throw PrecondViolatedException(msg);
    }
    return items[front];
}

template<class T>
int ArrayQueue<T>::getNumberOfElements() const
{
    return count;
}

#endif