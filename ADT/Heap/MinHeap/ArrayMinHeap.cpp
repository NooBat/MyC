#include "ArrayMinHeap.hpp"

template<class T>
int ArrayMinHeap<T>::getLeftChildIndex(const int nodeIndex) const {
    if (nodeIndex < 0 || nodeIndex >= maxItems) return -1;
    return nodeIndex * 2 + 1;
}

template<class T>
int ArrayMinHeap<T>::getRightChildIndex(int nodeIndex) const {
    if (nodeIndex < 0 || nodeIndex >= maxItems) return -1;
    return nodeIndex * 2 + 2;
}

template<class T>
int ArrayMinHeap<T>::getParentIndex(int nodeIndex) const {
    if (nodeIndex < 0) return -1;
    return (nodeIndex - 1) / 2;
}

template<class T>
bool ArrayMinHeap<T>::isLeaf(int nodeIndex) const {
    if (getLeftChildIndex(nodeIndex) < itemCount) {
        return false;
    }

    return true;
}

template<class T>
void ArrayMinHeap<T>::heapRebuild(int subTreeRootIndex) {
    if (!isLeaf(subTreeRootIndex)) {
        int smallerChildIndex = getLeftChildIndex(subTreeRootIndex);
        
        if (smallerChildIndex + 1 < itemCount) {
            int rightChildIndex = smallerChildIndex + 1;
            if (items[rightChildIndex] < items[smallerChildIndex]) {
                smallerChildIndex = rightChildIndex;
            }
        }

        if (items[subTreeRootIndex] > items[smallerChildIndex]) {
            swap(items[subTreeRootIndex], items[smallerChildIndex]);
            heapRebuild(smallerChildIndex);
        }
    }
}

template<class T>
void ArrayMinHeap<T>::heapCreate() {
    for (int i = itemCount / 2; i >= 0; i--) {
        heapRebuild(i);
    }
}

template<class T>
ArrayMinHeap<T>::ArrayMinHeap() {
    itemCount = 0;
    maxItems = DEFAULT_CAPACITY;
    items = new T[maxItems];
}

template<class T>
ArrayMinHeap<T>::ArrayMinHeap(const T someArray[], const int arraySize) {
    itemCount = arraySize;
    maxItems = itemCount * 2;
    items = new T[maxItems];

    for (int i = 0; i < arraySize; i++) {
        items[i] = someArray[i];
    }

    heapCreate();
}

template<class T>
ArrayMinHeap<T>::~ArrayMinHeap() {
    clear();
}

template<class T>
bool ArrayMinHeap<T>::isEmpty() const {
    return itemCount == 0;
}

template<class T>
int ArrayMinHeap<T>::getNumberOfNodes() const {
    return itemCount;
}

template<class T>
int ArrayMinHeap<T>::getHeight() const {
    int height = 0;
    int lastIndex = itemCount - 1;

    while (lastIndex >= 0) {
        lastIndex = getParentIndex(lastIndex);
        height++;
    }

    return height;
}

template<class T>
T ArrayMinHeap<T>::peekTop() const {
    if (itemCount == 0) {
        string msg = "peekTop was called with an empty heap.";
        throw PrecondViolatedException(msg);
    }

    return items[0];
}

template<class T>
bool ArrayMinHeap<T>::add(const T& newData) {
    if (itemCount == maxItems) {
        return false;
    } else {
        int newIndex = itemCount;
        bool inPlace = false;
        items[itemCount] = newData;

        while ( (newIndex >= 0) && !inPlace) {
            int parentIndex = getParentIndex(newIndex);

            if (items[parentIndex] > items[newIndex]) {
                swap(items[parentIndex], items[newIndex]);
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
bool ArrayMinHeap<T>::remove() {
    if (itemCount == 0) {
        return false;
    } else {
        itemCount--;
        items[0] = items[itemCount];

        heapRebuild(0);
    }

    return true;
}

template<class T>
void ArrayMinHeap<T>::clear() {
    itemCount = 0;

    delete[] items;
    items = nullptr;
}
