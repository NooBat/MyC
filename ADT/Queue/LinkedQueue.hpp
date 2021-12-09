#ifndef _LINKED_QUEUE
#define _LINKED_QUEUE

#include "QueueInterface.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/PrecondViolatedException.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/Node.hpp"
#include<string>
#include<vector>
#include<vector>

using namespace std;

template<class T>
class LinkedQueue : public QueueInterface<T>
{
private:
    Node<T>* headPtr;
    Node<T>* tailPtr;

public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue<T>& other);
    virtual ~LinkedQueue();

    bool isEmpty() const;
    bool enqueue(const T& newEntry);
    bool dequeue();
    T peekFront() const;
    vector<T> display() const;
    int getNumberOfElements() const;
    vector<T> display() const;
    int getNumberOfElements() const;
};

template<class T>
LinkedQueue<T>::LinkedQueue()
{
    headPtr = nullptr;
    tailPtr = nullptr;
}

template<class T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& other)
{
    headPtr = nullptr;
    tailPtr = nullptr;
    try
    {
        if (!other.isEmpty())
        {
            Node<T>* currPtr = other.headPtr;
            headPtr = new Node<T>(currPtr->getItem());
            tailPtr = headPtr;
            currPtr = currPtr->getNext();

            while (currPtr)
            {
                Node<T>* newNodePtr = new Node<T>(currPtr->getItem());
                tailPtr->setNext(newNodePtr);
                currPtr = currPtr->getNext();
                tailPtr = tailPtr->getNext();
            }
        }
    }
    catch(bad_alloc& e)
    {
        ~LinkedQueue();
        throw e.what();
    }
}

template<class T>
LinkedQueue<T>::~LinkedQueue()
{
    Node<T>* currPtr = headPtr;

    while (currPtr)
    {
        Node<T>* nextPtr = currPtr->getNext();
        currPtr->setNext(nullptr);
        delete currPtr;

        currPtr = nextPtr;
    }

    headPtr = tailPtr = nullptr;
}

template<class T>
bool LinkedQueue<T>::isEmpty() const
{
    return (headPtr == nullptr);
}

template<class T>
bool LinkedQueue<T>::enqueue(const T& newEntry)
{
    Node<T>* newNodePtr = new Node<T>(newEntry);
    if (!headPtr)
    {
        headPtr = tailPtr = newNodePtr;
    }
    else
    {
        tailPtr->setNext(newNodePtr);
        tailPtr = newNodePtr;
    }

    return true;
}

template<class T>
bool LinkedQueue<T>::dequeue()
{
    if (isEmpty()) return false;

    Node<T>* firstNode = headPtr;

    if (headPtr == tailPtr)
    {
        tailPtr = nullptr;
    }
    headPtr = headPtr->getNext();

    firstNode->setNext(nullptr);
    delete firstNode;
    firstNode = nullptr;

    return true;
}

template<class T>
T LinkedQueue<T>::peekFront() const
{
    if (this->isEmpty())
    {
        string message = "peekFront() was called with an empty queue";
        throw PrecondViolatedException(message);
    }

    return headPtr->getItem();
}

template<class T>
vector<T> LinkedQueue<T>::display() const
{
    Node<T>* currPtr = headPtr;
    vector<T> result;
    while (currPtr != nullptr)
    {
        result.push_back(currPtr->getItem());
        currPtr = currPtr->getNext();
    }

    return result;
}

template<class T>
int LinkedQueue<T>::getNumberOfElements() const
{
    Node<T>* currPtr = headPtr;
    int numOfItem = 0;

    while (currPtr)
    {
        ++numOfItem;
        currPtr = currPtr->getNext();
    }
}
#endif