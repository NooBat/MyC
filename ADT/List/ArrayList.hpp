#ifndef _ARRAY_LIST
#define _ARRAY_LIST

#include "ListInterface.hpp"
#include "../PrecondViolatedException.hpp"
#include "../../Types_of_Sort/merge_sort.cpp"

using namespace std;

template<class T>
class ArrayList : public ListInterface<T> {
private:
    T* arr;

    int itemCount;
    int maxItem;

    void resize();
public:
    ArrayList();

    ArrayList(T arr[], int n);

    bool isEmpty() const;

    int getLength() const;

    bool insert(int newPosition, const T& newEntry);

    bool remove(int position);

    void clear();

    T getEntry(int position) const;

    void setEntry(int position, const T& newEntry);

    int getPosition(const T& targetEntry) const;

    void sort();
};

template<class T>
ArrayList<T>::ArrayList() {
    arr = new T[10];
    itemCount = 0;
    maxItem = 10;
}

template<class T>
ArrayList<T>::ArrayList(T arr[], int n) {
    itemCount = n;
    maxItem = n + 10;
    
    this->arr = new T[maxItem];

    for (int i = 0; i < n; i++) {
        this->arr[i] = arr[i];
    }
}

template<class T>
void ArrayList<T>::resize() {
    maxItem *= 2;

    T* newArr = new T[maxItem];

    for (int i = 0; i < itemCount; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;

    arr = newArr;

    newArr = nullptr;
}

template<class T>
bool ArrayList<T>::isEmpty() const {
    return itemCount == 0;
}

template<class T>
int ArrayList<T>::getLength() const {
    return itemCount;
}

template<class T>
bool ArrayList<T>::insert(int newPosition, const T& newEntry) {
    bool ableToInsert = (newPosition >= 1 && newPosition <= itemCount + 1) && (itemCount < maxItem);

    if (ableToInsert) {
        for (int pos = itemCount; pos >= newPosition; pos--) {
            arr[pos] = arr[pos - 1];
        }

        arr[newPosition - 1] = newEntry;
        itemCount++;
    }
    else {
        if (itemCount == maxItem) {
            resize();
            ableToInsert = insert(newPosition, newEntry);
        }
    }

    return ableToInsert;
}

template<class T>
bool ArrayList<T>::remove(int position) {
    bool ableToRemove = (position >= 1 && position <= itemCount);

    if (ableToRemove) {
        for (int i = position; i < itemCount; i++) {
            arr[i - 1] = arr[i];
        }

        itemCount--;
    }

    return ableToRemove;
}

template<class T>
void ArrayList<T>::clear() {
    delete[] arr;

    itemCount = 0;
}

template<class T>
T ArrayList<T>::getEntry(int position) const {
    if (position < 1 || position > itemCount) {
        string message = "getEntry() was called with an empty list or ";
        message += "invalid position.";
        throw(PrecondViolatedException(message));
    }

    return arr[position - 1];
}   

template<class T>
void ArrayList<T>::setEntry(int position, const T& newEntry) {
    if (position < 1 || position > itemCount) {
        string message = "setEntry() was called with an empty list or ";
        message += "invalid position.";
        throw(PrecondViolatedException(message));
    }

    arr[position - 1] = newEntry;
}

template<class T>
int ArrayList<T>::getPosition(const T& targetEntry) const {
    int result = -1;

    for (int i = 0; i < itemCount; i++) {
        if (targetEntry == arr[i]) {
            result = i;
            break;
        }
    }

    return result + 1;
}

template<class T>
void ArrayList<T>::sort()
{
    MergeSort<T> sortFunc;

    sortFunc.mergeSort(arr, 0, itemCount - 1);
}
#endif