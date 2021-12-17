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
//-----------------------------------------------------------
//                  Constructor Section.
//-----------------------------------------------------------

    LinkedIterator(const LinkedList<T>* someList, Node<T>* nodePtr);

//-----------------------------------------------------------
//      Public LinkedIterator Methods Section
//          Common Iterator Operations
//-----------------------------------------------------------

    /** Dereferencing operator overload.
     * @return The item at the position referenced by iterator. */ 
    const T operator*();

    /** Prefix increment operator overload.
     * @return The iterator referencing the next position 
     * in the list. 
     * ! Warning: Out of bound. */
    LinkedIterator<T> operator++();

    /** Equality operator overload.
     * @param LinkedIterator The iterator for comparison.
     * @return True if this iterator references the same list and
     * the same position as rightHandSide, false otherwise. */
    bool operator==(const LinkedIterator<T>& rightHandSide) const;

    /** Inequality operator overload.
     * @param LinkedIterator The iterator for comparison.
     * @return True if this iterator does not reference the same
     * list and the same position as rightHandSide,
     * false otherwise. */
    bool operator!=(const LinkedIterator<T>& rightHandSide) const;

//-----------------------------------------------------------
//          Advanced Iterator Functionality
//-----------------------------------------------------------

    /** Process entries in a collection from begin
     * position to end position using the function function_to_perform.
     * @param begin The iterator to start traverse from.
     * @param end The iterator to stop traverse at.
     * @param function_to_perform The function to perform every time traverse an item. */
    void for_each(LinkedIterator<T> begin, LinkedIterator<T> end, void function_to_perform(T&)) const;

    /** Find the first occurence of the given item in the 
     * list range and return an iterator pointing to it.
     * @param begin The iterator to start iterating from.
     * @param end The iterator to stop iterating at.
     * @param target The item to find in the range.
     * @return The iterator pointing to the targeted item, if not return end. */
    LinkedIterator<T> find(LinkedIterator<T> begin, LinkedIterator<T> end, const T& target) const;

    /** Count the number of occurence of the given item 
     * between begin and end.
     * @post If the item doesn't exist in the range, return 0.
     * @param begin The iterator to start iterating from.
     * @param end The iterator to end iterating from.
     * @param target The item to count in the range.
     * @return The number of occurence of the given item. */
    int count(LinkedIterator<T> begin, LinkedIterator<T> end, const T& target) const;

    /** Move an iterator forward a specific number of steps.
     * @pre The distance between the given iterator and the last one 
     * has to be greater or equal to distanceToAdvance.
     * @post If the distance is greater than distanceToAdvance then the
     * given iterator will be advanced distanceToAdvance steps.
     * @param iterator The iterator to be forwarded. 
     * @param distanceToAdvance The number of steps to be forwarded. 
     * ! Warning: Out of bound. */
    void advance(LinkedIterator<T>& iterator, int distanceToAdvance);

    /** Find the number of steps between begin and end. 
     * @param begin The first iterator to find the distance.
     * @param end The last iterator to find the distance.
     * @return The number of steps between begin and end. */
    int distance(LinkedIterator<T> begin, LinkedIterator<T> end);

    /** Compare entries in collection 1 from begin1 through end1 to
     * those in collection 2 beginning at begin2.
     * @pre The distance from begin2 to the end has to be equal or greater
     * than the distance between begin1 and end1.
     * @param begin1 The given iterator from collection 1 
     * to start iterating from. 
     * @param end1 The given iterator from collection 1 
     * to stop iterating from.
     * @param begin2 The given iterator from collection 2
     * to start iterating from.
     * @return True if all item in the given range is the same, false otherwise. 
     * ! Warning: Out of bound. */  
    bool equal(LinkedIterator<T> begin1, LinkedIterator<T> end1, LinkedIterator<T> begin2);
};

#endif