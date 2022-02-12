#ifndef _ARRAY_MIN_HEAP
#define _ARRAY_MIN_HEAP

#include "../HeapInterface.hpp"
#include "../../PrecondViolatedException.hpp"
#include<string>

using namespace std;

template<class T>
class ArrayMinHeap : public HeapInterface<T> {
private:
    static const int ROOT_INDEX = 0;
    static const int DEFAULT_CAPACITY = 21;
    T* items;
    int itemCount;
    int maxItems;

    //Returns the array index of the left child (if it exists).
    int getLeftChildIndex(const int nodeIndex) const;

    //Returns the array index of the right child (if it exists).
    int getRightChildIndex(int nodeIndex) const;

    //Returns the array index of the parent node.
    int getParentIndex(int nodeIndex) const;

    //Tests whether this node is a leaf.
    bool isLeaf(int nodeIndex) const;

    //Converts a semiheap to a heap.
    void heapRebuild(int subTreeRootIndex);

    //Creates a heap from an unordered array.
    void heapCreate();

public:
    ArrayMinHeap();
    ArrayMinHeap(const T someArray[], const int arraySize);
    virtual ~ArrayMinHeap();

    bool isEmpty() const;
    int getNumberOfNodes() const;
    int getHeight() const;
    T peekTop() const;
    bool add(const T& newData);
    bool remove();
    void clear();
};

#endif