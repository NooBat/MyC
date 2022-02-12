#ifndef _HEAP_PRIORITY_QUEUE
#define _HEAP_PRIORITY_QUEUE

#include "../Heap/ArrayMaxHeap.hpp"
#include "../Heap/ArrayMaxHeap.cpp"
#include "PriorityQueueInterface.hpp"

template<class T>
class PriorityQueue : public PriorityQueueInterface<T>,
                      private ArrayMaxHeap<T> {
public:
    PriorityQueue();
    bool isEmpty() const;
    bool add(const T& newEntry);
    bool remove();

    T peek() const;
};

#endif