#include "LinkedIterator.hpp"

//-----------------------------------------------------------
//                  Constructor Section.
//-----------------------------------------------------------

template<class T>
LinkedIterator<T>::
LinkedIterator(const LinkedList<T>* someList, 
               Node<T>* nodePtr):
               containerPtr(someList), currentItemPtr(nodePtr)
{

} //end operator*

//-----------------------------------------------------------
//      Public LinkedIterator Methods Section
//          Common Iterator Operations
//-----------------------------------------------------------

template<class T>
const T LinkedIterator<T>::operator*()  
{
    return this->currentItemPtr->getItem();
}

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

//-----------------------------------------------------------
//          Advanced Iterator Functionality
//-----------------------------------------------------------

template<class T>
void LinkedIterator<T>::for_each(LinkedIterator<T> begin, LinkedIterator<T> end, void function_to_perform(T&)) const 
{
    for (; begin != end; ++begin)
    {
        function_to_perform(*begin);
    }
}

template<class T>
LinkedIterator<T> LinkedIterator<T>::find(LinkedIterator<T> begin, LinkedIterator<T> end, const T& target) const 
{
    for (; begin != end; ++begin)
    {
        if (*begin == target) return begin;           
    }

    return end;
}

template<class T> 
int LinkedIterator<T>::count(LinkedIterator<T> begin, LinkedIterator<T> end, const T& target) const
{
    int result = 0;

    for (; begin != end; ++begin)
    {
        if (*begin == target) result++;
    }

    return result; 
}

template<class T> 
void LinkedIterator<T>::advance(LinkedIterator<T>& iterator, int distanceToAdvance)
{
    for (int i = 0; i < distanceToAdvance; ++i)
    {
        iterator++;
        if (!iterator.currentItemPtr) 
        {
            throw std::out_of_range("The iterator is out of range.");
        }
    }
}

template<class T>
int LinkedIterator<T>::distance(LinkedIterator<T> begin, LinkedIterator<T> end)
{
    int distance = 0;

    for (; begin != end; ++begin)
    {
        distance++;
    }

    return distance; 
}

template<class T>
bool LinkedIterator<T>::equal(LinkedIterator<T> begin1, LinkedIterator<T> end1, LinkedIterator<T> begin2) 
{
    for (; begin1 != end1; ++begin1, ++begin2)
    {
        if (!begin2.currentItemPtr || 
            *begin1 != *begin2) 
        return false;
    }

    return true;     
}