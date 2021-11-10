#ifndef _CIRCULAR_LINKED_QUEUE
#define _CIRCULAR_LINKED_QUEUE

#include "QueueInterface.hpp"
#include "Node.hpp"
#include "PrecondViolatedException.hpp"

template<class T>
class CircularLinkedQueue : QueueInterface<T>
{
private:
    Node<T>* backPtr;
public:
    CircularLinkedQueue();
    CircularLinkedQueue(const CircularLinkedQueue<T>& q);
    virtual ~CircularLinkedQueue();

    bool isEmpty() const;
    bool enqueue(const T& newEntry);
    bool dequeue();
    T peekFront() const;
};

template<class T>
CircularLinkedQueue<T>::CircularLinkedQueue() 
{
    backPtr = nullptr;
}

template<class T>
CircularLinkedQueue<T>::CircularLinkedQueue(const CircularLinkedQueue<T>& q)
{
    if (!q.backPtr)
    {
        backPtr = new Node<T>(q.backPtr->getItem());

        Node<T>* newNodePtr = backPtr;
        Node<T>* originalNodePtr = q.backPtr;
        originalNodePtr = originalNodePtr->getNext();

        while (originalNodePtr != q.backPtr)
        {
            newNodePtr->setNext(originalNodePtr->getItem());
            newNodePtr = newNodePtr->getNext();
            originalNodePtr = originalNodePtr->getNext();
        }
        newNodePtr->setNext(backPtr);
    }
}

template<class T>
CircularLinkedQueue<T>::~CircularLinkedQueue()
{
    if (!backPtr) return;
    Node<T>* currPtr = backPtr->getNext();

    while (currPtr != backPtr)
    {
        Node<T>* nextPtr = currPtr->getNext();

        currPtr->setNext(nullptr);
        delete currPtr;

        currPtr = nextPtr;
    }

    currPtr->setNext(nullptr);
    delete currPtr;
    currPtr = backPtr = nullptr;
}

template<class T>
bool CircularLinkedQueue<T>::isEmpty() const
{
    return backPtr == nullptr;
}

template<class T>
bool CircularLinkedQueue<T>::enqueue(const T& newEntry)
{
    Node<T>* newNodePtr = new Node<T>(newEntry);

    if (!backPtr)
    {
        backPtr = newNodePtr;
        newNodePtr->setNext(backPtr);
    }
    else
    {
        Node<T>* nextPtr = backPtr->getNext();
        backPtr->setNext(newNodePtr);
        newNodePtr->setNext(nextPtr);
    }

    return true;
}

template<class T>
bool CircularLinkedQueue<T>::dequeue() 
{
    if (!backPtr) return false;
    if (backPtr->getNext() == backPtr)
    {
        backPtr->setNext(nullptr);
        delete backPtr;
        backPtr = nullptr;
    } 
    else
    {
        Node<T>* currPtr = backPtr;

        while (currPtr->getNext() != backPtr)
        {
            currPtr = currPtr->getNext();
        }
        currPtr->setNext(backPtr->getNext());

        delete backPtr;
        backPtr = currPtr;
    }

    return false;
}

template<class T>
T CircularLinkedQueue<T>::peekFront() const
{
    if (!backPtr)
    {
        string msg = "peekFront() was called with an empty list!";
        throw PrecondViolatedException(msg);
    }

    return backPtr->getItem();
}

#endif