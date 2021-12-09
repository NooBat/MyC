#include "Ex1.hpp"
#include<iostream>

using namespace std;

template<class T>
void ArrayStack<T>::doubleSize() {
    try {
        T* newArr = nullptr;

        if (increment <= 0) newArr = new T[maxItem * 2];
        else newArr = new T[maxItem + increment];

        for (int i = 0; i < maxItem; i++) {
            newArr[i] = arr[i];
        }

        if (increment <= 0) maxItem *= 2;
        else maxItem += increment;

        delete[] arr;

        increment += 2 * increment;
        
        this->arr = newArr;
        newArr = nullptr;
    }
    catch (MemoryAllocationException e) {
        delete[] arr;

        throw e.what();
    }
}

template<class T>
void ArrayStack<T>::halfSize() {
    try {
        if (top + 1 >= maxItem / 2) return;

        T* newArr = new T[maxItem / 2];

        for (int i = 0; i < maxItem / 2; i++) {
            newArr[i] = arr[i];
        }

        maxItem /= 2;

        delete[] arr;

        arr = newArr;
        newArr = nullptr;
    }
    catch (MemoryAllocationException e) {
        delete[] arr;

        throw e.what();
    }
}

template<class T>
ArrayStack<T>::ArrayStack() {
    maxItem = 6;

    increment = 0;

    arr = new T[6];

    top = -1;
}

template<class T>
ArrayStack<T>::ArrayStack(const int& increment) {
    maxItem = 6;
    
    this->increment = increment;

    arr = new T[6];

    top = -1;
}

template<class T>
ArrayStack<T>::ArrayStack(T arr[], int n) {
    try {
        maxItem = n;

        this->arr = new T[n];

        top = n - 1;

        for (int i = 0; i < n; i++) {
            this->arr[i] = arr[i];
        }
    }
    catch (MemoryAllocationException e) {
        delete arr;

        throw e.what();
    }
}

template<class T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& aStack) {
    maxItem = aStack.maxItem;

    top = aStack.top;

    try {
        arr = new T[maxItem];

        for (int i = 0; i < maxItem; i++) {
            arr[i] = aStack.arr[i];
        }
    }
    catch (MemoryAllocationException e) {
        delete arr;

        throw e.what();
    }
}

template<class T>
bool ArrayStack<T>::isEmpty() const {
    return top == -1;
}

template<class T>
bool ArrayStack<T>::push(const T& newEntry) {
    if (top == maxItem - 1) {
        try {
            doubleSize();
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
    }

    top++;

    arr[top] = newEntry;

    return true;
}

template<class T>
bool ArrayStack<T>::pop() {
    if (top == -1) {
        return false;
    }

    top--;
    try {
        halfSize();
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    return true;
}

template<class T>
int ArrayStack<T>::getMaxItem() const {
    return maxItem;
}

template<class T>
T ArrayStack<T>::peek() const {
    if (top == -1) throw EmptyStack();

    return arr[top];
}

template<class T>
vector<T> ArrayStack<T>::toVector() const {
    vector<T> result;

    for (int i = top; i >= 0; i--) {
        result.push_back(arr[i]);
    }

    return result;
}