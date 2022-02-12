#include "ArrayMaxHeap.hpp"

//-----------------------------------------------------------
//          Private Methods
//-----------------------------------------------------------

template<class T>
int ArrayMaxHeap<T>::getLeftChildIndex(const int nodeIndex) const
{
    if (nodeIndex >= 0 && nodeIndex < maxItems) 
    {
        return (2 * nodeIndex) + 1;     
    }
    return -1;        
}

template<class T>
int ArrayMaxHeap<T>::getRightChildIndex(int nodeIndex) const
{
    if (nodeIndex >= 0 && nodeIndex < maxItems) 
    {
        return (2 * nodeIndex) + 2;    
    }
    return -1;
}

template<class T>
int ArrayMaxHeap<T>::getParentIndex(int nodeIndex) const
{
    if (nodeIndex > 0)
    {
        return (nodeIndex - 1) / 2;
    }
    return -1;   
}

template<class T>
bool ArrayMaxHeap<T>::isLeaf(int nodeIndex) const
{
    if (getLeftChildIndex(nodeIndex) < itemCount)
    {
        return true;
    }

    return false;
}

template<class T>
void ArrayMaxHeap<T>::heapRebuild(int subTreeRootIndex)
{
    if (!isLeaf(subTreeRootIndex))
    {
        largerChildIndex = getLeftChildIndex(subTreeRootIndex);

        if (largerChildIndex + 1 < itemCount)
        {
            rightChildIndex = largerChildIndex + 1;
            if (items[rightChildIndex] > items[rightChildIndex])
            {
                largerChildIndex = rightChildIndex;
            }
        }

        if (items[subTreeRootIndex] < items[largerChildIndex])
        {
            swap(items[subTreeRootIndex], items[largerChildIndex]);
            heapRebuild(largerChildIndex);
        }
    }
}

template<class T>
void ArrayMaxHeap<T>::heapCreate()
{
    for (int index = itemCount / 2; index >= 0; --index)
    {
        heapRebuild(index);
    }
}

template<class T>
ArrayMaxHeap<T>::ArrayMaxHeap() : itemCount(0), 
                                  maxItems(DEFAULT_CAPACITY)
{
    items = new T[maxItems];
}

template<class T>
ArrayMaxHeap<T>::ArrayMaxHeap(const T someArray[], const int arraySize) : itemCount(arraySize),
                                                                          maxItems(arraySize * 2)
{
    items = new T[maxItems];

    for (int i = 0; i < arraySize; ++i)
    {
        items[i] = someArray[i];
    }

    heapCreate();
}

template<class T>
ArrayMaxHeap<T>::~ArrayMaxHeap() {
    clear();
}

template<class T>
bool ArrayMaxHeap<T>::isEmpty() const
{
    return itemCount == 0;
}

template<class T>
int ArrayMaxHeap<T>::getNumberOfNodes() const {
    return itemCount;
}

template<class T>
int ArrayMaxHeap<T>::getHeight() const
{
    int height = 0;
    if (itemCount > 0) {
        int currentIndex = itemCount - 1;

        while (getParentIndex(currentIndex) >= 0) {
            height++;
            currentIndex = getParentIndex(currentIndex);
        }
    }

    return height;
}

template<class T>
T ArrayMaxHeap<T>::peekTop() const {
    if (itemCount == 0) {
        string msg = "peekTop() was called with an empty heap";
        throw PrecondViolatedException(msg);
    }

    return items[0];
}

template<class T>
bool ArrayMaxHeap<T>::add(const T& newData) {
    if (itemCount == maxItems) {
        return false;
    } else {
        int newIndex = itemCount;
        bool inPlace = false;
        items[itemCount] = newData;

        while ( (newIndex >= 0) && !inPlace ) {
            int parentIndex = getParentIndex(newIndex);
            if (items[newIndex] > items[parentIndex]) {
                swap(items[newIndex], items[parentIndex]);
                newIndex = parentIndex;
            } else {
                inPlace = true;
            }
        }

        itemCount++;
    }

    return true;
}

template<class T>
bool ArrayMaxHeap<T>::remove() {
    if (!itemCount) {
        return false;
    } else {
        items[0] = items[itemCount - 1];

        itemCount--;

        heapRebuild(0);
    }

    return true;
}

template<class T>
void ArrayMaxHeap<T>::clear() {
    delete[] items;
    items = nullptr;
    itemCount = 0;
 }