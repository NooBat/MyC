#ifndef _ARRAY_STACK
#define _ARRAY_STACK

#include "/Users/danielnguyen/Repo/C++/ADT/StackInterface.h"
#include<stdexcept>
#include<string>
#include<cstring>

using namespace std;

class EmptyStack : public logic_error {
    string mess;

public:
    virtual ~EmptyStack() throw() {
        return ;
    }
    EmptyStack() : logic_error("") {
        mess = "Stack is empty!";
    }
    const char *what() const throw() {
        return mess.c_str();
    }
};

class MemoryAllocationException : public exception {
private:
    string mess;

public:
    MemoryAllocationException() {
        mess = "Memory failed to allocated!";
    }

    virtual ~MemoryAllocationException() throw() {
        return;
    }

    const char* what() const throw() {
        return mess.c_str();
    }
};

template<class ItemType>
class ArrayStack : public StackInterface<ItemType> {
private:
    ItemType* arr;

    int maxItem;
    int top;

    void doubleSize();

    void halfSize();

public:
    ArrayStack();

    ArrayStack(ItemType arr[], int n);

    ArrayStack(const ArrayStack<ItemType>& aStack);

    bool isEmpty() const;

    bool push(const ItemType& newEntry);

    bool pop();

    ItemType peek() const;

    vector<ItemType> toVector() const;
};



#endif