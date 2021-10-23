#ifndef _LIST_QUEUE
#define _LIST_QUEUE
#include "QueueInterface.hpp"
#include "LinkedList.hpp"
#include "PrecondViolatedException.hpp"

template<class ItemType>
class ListQueue : public QueueInterface<ItemType>
{
private:
    LinkedList<ItemType>* listPtr;

public:
    ListQueue();
    ListQueue(const ListQueue& aQueue);
    virtual ~ListQueue();
    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const;
};



#endif _LIST_QUEUE