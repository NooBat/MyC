#ifndef _STACK_INTERFACE
#define _STACK_INTERFACE

#include<vector>

using namespace std;

template<class T>
class StackInterface {
public:
    /** Sees whether this stack is empty.
     * @return True if the stack is empty, otherwise false. */
    virtual bool isEmpty() const = 0;

    /** Adds newEntry to the top of this stack.
     * @post newEntry will be on top of the stack.
     * @param newEntry item needs to be pushed to the stack.
     * @return True if push was successful, otherwise false. */
    virtual bool push(const T& newEntry) = 0;

    /** Removes the top of this stack.
     * @pre The stack must not be empty.
     * @post If successful, the top of the stack was removed.
     * @return True if pop was successful, otherwise false. */
    virtual bool pop() = 0;

    /** Returns the top of this stack.
     * @pre The stack must not be empty.
     * @return The top item of this stack. */
    virtual T peek() const = 0;

    /** Returns a vector contains every item in the stack from bottom to top 
     * @return A vector contains every item from bottom to top */
    virtual vector<T> toVector() const = 0;
};

#endif