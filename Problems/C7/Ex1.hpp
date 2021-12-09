#ifndef _ARRAY_STACK
#define _ARRAY_STACK

#include "/Users/danielnguyen/Repo/C++/ADT/StackInterface.hpp"
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

template<class T>
class ArrayStack : public StackInterface<T> {
private:
    T* arr;

    int increment;
    int maxItem;
    int top;

    void doubleSize();

    void halfSize();

public:
    ArrayStack();

    ArrayStack(const int& increment);

    ArrayStack(T arr[], int n);

    ArrayStack(const ArrayStack<T>& aStack);

    bool isEmpty() const;

    bool push(const T& newEntry);

    bool pop();

    int getMaxItem() const;

    T peek() const;

    vector<T> toVector() const;
};

#endif