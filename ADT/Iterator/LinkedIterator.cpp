#include "LinkedIterator.hpp"

template<class T>
LinkedIterator<T>::
LinkedIterator(const LinkedList<T>* someList, 
               Node<T>* nodePtr):
               containerPtr(someList), currentItemPtr(nodePtr)
{

} //end operator*

template<class T>
LinkedIterator<T> LinkedIterator<T>::operator++()
{
    currentItemPtr = currentItemPtr->getNext();
    return *this; 
}

template<class T>
bool LinkedIterator<T>::operator==(const
                                   LinkedIterator<T>& rightHandSide) const 
{
    return ((containerPtr == rightHandSide.containerPtr) && 
            (currentItemPtr == rightHandSide.currentItemPtr));
}

template<class T>
bool LinkedIterator<T>::operator!=(const 
                                   LinkedIterator<T>& rightHandSide) const
{
    return ((containerPtr != rightHandSide.containerPtr) &&
            (currentItemPtr != rightHandSide.currentItemPtr));  
}
