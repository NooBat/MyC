#ifndef _LIST_QUEUE
#define _LIST_QUEUE

#include "QueueInterface.hpp"
#include "../List/LinkedList.hpp"
#include "../PrecondViolatedException.hpp"
#include<string>

using namespace std;

template<class T>
class ListQueue : public QueueInterface<T>
{
private:
    LinkedList<T>* listPtr;

public:
    ListQueue();
    ListQueue(const ListQueue& aQueue);
    virtual ~ListQueue();
    bool isEmpty() const;
    bool enqueue(const T& newEntry);
    bool dequeue();
    T peekFront() const;
};

template<class T>
ListQueue<T>::ListQueue()
{
    listPtr = new LinkedList<T>();
}

template<class T>
ListQueue<T>::ListQueue(const ListQueue& aQueue)
{
    listPtr = new LinkedList<T>(aQueue.listPtr);
}

template<class T>
ListQueue<T>::~ListQueue()
{
    listPtr->clear();
    listPtr = nullptr;
}

template<class T>
bool ListQueue<T>::isEmpty() const
{
    return listPtr->isEmpty();
}

template<class T>
bool ListQueue<T>::enqueue(const T& newEntry)
{
    int lastPosition = listPtr->getLength();
    return listPtr->insert(lastPosition + 1, newEntry);
}

template<class T>
T ListQueue<T>::peekFront() const
{
    if (listPtr->getLength() == 0)
    {
        string message = "peekFront() was called with an empty queue!";
        throw PrecondViolatedException(message);
    }

    return listPtr->getItem(1);
}
#endif