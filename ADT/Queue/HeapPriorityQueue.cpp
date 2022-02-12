#include "HeapPriorityQueue.hpp"

template<class T>
PriorityQueue<T>::PriorityQueue() {
    ArrayMaxHeap<T>();
}

template<class T>
bool PriorityQueue<T>::isEmpty() const {
    return ArrayMaxHeap<T>::isEmpty();
}

template<class T>
bool PriorityQueue<T>::add(const T& newEntry) {
    return ArrayMaxHeap<T>::add(newEntry);
}

template<class T>
bool PriorityQueue<T>::remove() {
    return ArrayMaxHeap<T>::remove();
}

template<class T>
T PriorityQueue<T>::peek() const {
    try {
        return ArrayMaxHeap<T>::peekTop();
    } catch (PrecondViolatedException e) {
        throw PrecondViolatedException("peek() was called with an empty priority queue");
    }
}