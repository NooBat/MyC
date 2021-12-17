#ifndef _LINKED_ITERATOR      
#define _LINKED_ITERATOR

#include<iterator>
#include "../Node.hpp"

template<class T> 
class LinkedList;

template<class T>
class LinkedIterator : public iterator<input_iterator_tag, int>
{
private:
    // ADT associated with iterator
    const LinkedList<ItemType>* containerPtr;

    //Current location in collection
    Node<T>* currentItemPtr;

public:
    LinkedIterator(const LinkedList<T>* someList, Node<T>* nodePtr);

    /** Dereferencing operator overload.
     * @return The item at the position referenced by iterator. **/ 
    const T operator*();
};

#endif