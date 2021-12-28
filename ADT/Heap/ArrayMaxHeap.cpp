#include "ArrayMaxHeap.hpp"

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
    
}