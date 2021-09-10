#include "Ex1.h"
#include<iostream>

using namespace std;

template<class ItemType>
void ArrayStack<ItemType>::doubleSize() {
    try {
        ItemType* newArr = nullptr;

        if (increment <= 0) newArr = new ItemType[maxItem * 2];
        else newArr = new ItemType[maxItem + increment];

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

template<class ItemType>
void ArrayStack<ItemType>::halfSize() {
    try {
        if (top + 1 >= maxItem / 2) return;

        ItemType* newArr = new ItemType[maxItem / 2];

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

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() {
    maxItem = 6;

    increment = 0;

    arr = new ItemType[6];

    top = -1;
}

template<class ItemType>
ArrayStack<ItemType>::ArrayStack(const int& increment) {
    maxItem = 6;
    
    this->increment = increment;

    arr = new ItemType[6];

    top = -1;
}

template<class ItemType>
ArrayStack<ItemType>::ArrayStack(ItemType arr[], int n) {
    try {
        maxItem = n;

        this->arr = new ItemType[n];

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

template<class ItemType>
ArrayStack<ItemType>::ArrayStack(const ArrayStack<ItemType>& aStack) {
    maxItem = aStack.maxItem;

    top = aStack.top;

    try {
        arr = new ItemType[maxItem];

        for (int i = 0; i < maxItem; i++) {
            arr[i] = aStack.arr[i];
        }
    }
    catch (MemoryAllocationException e) {
        delete arr;

        throw e.what();
    }
}

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const {
    return top == -1;
}

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry) {
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

template<class ItemType>
bool ArrayStack<ItemType>::pop() {
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

template<class ItemType>
int ArrayStack<ItemType>::getMaxItem() const {
    return maxItem;
}

template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const {
    if (top == -1) throw EmptyStack();

    return arr[top];
}

template<class ItemType>
vector<ItemType> ArrayStack<ItemType>::toVector() const {
    vector<ItemType> result;

    for (int i = top; i >= 0; i--) {
        result.push_back(arr[i]);
    }

    return result;
}