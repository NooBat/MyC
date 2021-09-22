#ifndef _ARRAY_BAG
#define _ARRAY_BAG

#include "BagInterface.hpp"
#include<algorithm>

template<class ItemType>
class ArrayBag : public BagInterface<ItemType> {
private:
    static const int DEFAULT_CAPACITY = 50;
    ItemType items[DEFAULT_CAPACITY];   // Array of bag items
    int itemCount;                      // Current count of bag items
    int maxItems;                       // Max capacity of the bag;

    // Returns either the index of the element in the array items that 
    // contains the given target or -1, if the array does not contain 
    // the target.
    int getIndexOf(const ItemType& target) const;

public:
    ArrayBag();

    int getCurrentSize() const;

    bool isEmpty() const;

    bool add(const ItemType& newEntry);

    bool remove(const ItemType& entry);

    void clear();

    int getFrequencyOf(const ItemType& entry) const;

    bool contains(const ItemType& entry) const;

    vector<ItemType> toVector() const;

    bool replace(const ItemType& entry, const ItemType& newEntry);

    ArrayBag<ItemType> Union(const ArrayBag<ItemType>& other) const;

    ArrayBag<ItemType> intersection(const ArrayBag<ItemType>& other) const;

    ArrayBag<ItemType> difference(const ArrayBag<ItemType>& other) const;

    ArrayBag<ItemType> operator= (const ArrayBag<ItemType>& other);
};

template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const {
    if (itemCount == 0) return -1;

    bool found = false;

    for (int i = 0; i < itemCount; i++) {
        if (items[i] == target) {
            return i;
        }
    }

    return -1;
}

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const {
    return itemCount;
}

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const {
    return (itemCount == 0);
}

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry) {
    if (itemCount >= maxItems) return false;

    items[itemCount] = newEntry;

    itemCount++;

    return true;
}

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& entry) {
    if (itemCount == 0) return false;

    int i;

    i = getIndexOf(entry);

    if (i == -1) return false;

    for (; i < itemCount; i++) {
        items[i] = items[i + 1];
    }

    itemCount--;

    return true;
}

template<class ItemType>
void ArrayBag<ItemType>::clear() {
    itemCount = 0;
}

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& entry) const {
    if (itemCount == 0) return -1;

    int count = 0;

    for (int i = 0; i < itemCount; i++) {
        if (items[i] == entry) count++; 
    }

    return count;
}

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& entry) const {
    return getIndexOf(entry) > -1;
}

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const {
    vector<ItemType> result;

    if (getCurrentSize() == 0) {
        return result;
    }

    for (int i = 0; i < itemCount; i++) {
        result.push_back(items[i]);
    }

    return result;
}

template<class ItemType>
bool ArrayBag<ItemType>::replace(const ItemType& entry, const ItemType& newEntry) {
    if (newEntry == entry || getCurrentSize() == 0 || !contains(entry)) {
        return false;
    } 

    int i = getIndexOf(entry);

    items[i] = newEntry;
    
    return true;
}

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::Union(const ArrayBag<ItemType>& other) const {
    ArrayBag<ItemType> result;

    vector<ItemType> v1 = this->toVector();
    vector<ItemType> v2 = other.toVector();
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            result.add(v1[i]);
            i++;
        }
        else if (v1[i] > v2[j]) {
            result.add(v2[j]);
            j++;
        }
        else {
            result.add(v1[i]);
            result.add(v2[j]);
            i++;
            j++;
        }
    }

    while (i < v1.size()) {
        result.add(v1[i]);
        i++;
    }

    while (j < v2.size()) {
        result.add(v2[j]);
        j++;
    }

    return result;
}

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::intersection(const ArrayBag<ItemType>& other) const {
    ArrayBag<ItemType> result;
    
    vector<ItemType> v1 = this->toVector();
    vector<ItemType> v2 = other.toVector();
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) i++;
        else if (v1[i] > v2[j]) j++;
        else {
            result.add(v1[i]);
            i++;
            j++;
        }
    }

    return result;
}

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::difference(const ArrayBag<ItemType>& other) const {
    ArrayBag<ItemType> result;
    
    vector<ItemType> v1 = this->toVector();
    vector<ItemType> v2 = other.toVector();
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            result.add(v1[i]);
            i++;
        }
        else if (v1[i] > v2[j]) {
            result.add(v2[j]);
            j++;
        }
        else {
            i++;
            j++;
        }
    }

    return result;
}

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::operator= (const ArrayBag<ItemType>& other) {
    itemCount = other.itemCount;
    maxItems = other.maxItems;

    for (int i = 0; i < itemCount; i++) {
        items[i] = other.items[i];
    }

    return *this;
}
#endif