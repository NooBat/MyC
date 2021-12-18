#ifndef _HEAP_INTERFACE   
#define _HEAP_INTERFACE

template<class T>
class HeapInterface 
{
public: 
    /** Sees whether this heap is empty. 
     * @return True if the heap is empty, or false otherwise. */
    virtual bool isEmpty() const = 0;

    /** Gets the number of nodes in this heap.
     * @return The number of nodes in this heap. */
    virtual int getNumberOfNodes() const = 0;

    /** Gets the height of this heap.
     * @return The height of the heap. */
    virtual int getHeight() const = 0;

    /** Gets the data that is in the root (top) of this heap. 
     * For a maxheap, the data is the largest value in the heap.
     * For a minheap, the data is the smallest value in the heap.
     * @pre The heap is not empty.
     * @post The root's data has been returned, and the heap is unchanged.
     * @return The data in the root of the heap. */
    virtual T peekTop() const = 0;   

    /** Adds a new node containing the given data to this heap.
     * @param newData The data for the new node.
     * @post The heap contains a new node.
     * @return True if the addition is successful, or false otherwise. */
    virtual bool add(const T& newData) = 0;

    /** Removes the root node from this heap. 
     * @return True if the removal is successful, or false otherwise. */
    virtual bool remove() = 0; 

    /** Removes all nodes from this heap. */
    virtual void clear() = 0;
};

#endif