#ifndef _ARRAY_LIST
#define _ARRAY_LIST

#include "ListInterface.h"
#include "PrecondViolatedException.h"

using namespace std;

template<class ItemType>
class ArrayList : public ListInterface<ItemType> {
private:
    ItemType* arr;

    int itemCount;
    int maxItem;

    void resize();
public:
    ArrayList();

    ArrayList(ItemType arr[], int n);

    bool isEmpty() const;

    int getLength() const;

    bool insert(int newPosition, const ItemType& newEntry);

    bool remove(int position);

    void clear();

    ItemType getEntry(int position) const;

    void setEntry(int position, const ItemType& newEntry);

    int getPosition(const ItemType& targetEntry) const;
};

template<class ItemType>
ArrayList<ItemType>::ArrayList() {
    arr = new ItemType[10];
    itemCount = 0;
    maxItem = 10;
}

template<class ItemType>
ArrayList<ItemType>::ArrayList(ItemType arr[], int n) {
    itemCount = n;
    maxItem = n + 10;
    
    this->arr = new ItemType[maxItem];

    for (int i = 0; i < n; i++) {
        this->arr[i] = arr[i];
    }
}

template<class ItemType>
void ArrayList<ItemType>::resize() {
    maxItem *= 2;

    ItemType* newArr = new ItemType[maxItem];

    for (int i = 0; i < itemCount; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;

    arr = newArr;

    newArr = nullptr;
}

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
int ArrayList<ItemType>::getLength() const {
    return itemCount;
}

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry) {
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

template<class ItemType>
bool ArrayList<ItemType>::remove(int position) {
    bool ableToRemove = (position >= 1 && position <= itemCount);

    if (ableToRemove) {
        for (int i = position; i < itemCount - 1; i++) {
            arr[i] = arr[i + 1];
        }

        itemCount--;
    }

    return ableToRemove;
}

template<class ItemType>
void ArrayList<ItemType>::clear() {
    delete[] arr;

    itemCount = 0;
}

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const {
    if (position < 1 || position > itemCount) {
        string message = "getEntry() was called with an empty list or ";
        message += "invalid position.";
        throw(PrecondViolatedException(message));
    }

    return arr[position - 1];
}   

template<class ItemType>
void ArrayList<ItemType>::setEntry(int position, const ItemType& newEntry) {
    if (position < 1 || position > itemCount) {
        string message = "setEntry() was called with an empty list or ";
        message += "invalid position.";
        throw(PrecondViolatedException(message));
    }

    arr[position - 1] = newEntry;
}

template<class ItemType>
int ArrayList<ItemType>::getPosition(const ItemType& targetEntry) const {
    int result = -1;

    for (int i = 0; i < itemCount; i++) {
        if (targetEntry == arr[i]) {
            result = i;
            break;
        }
    }

    return result;
}
#endif