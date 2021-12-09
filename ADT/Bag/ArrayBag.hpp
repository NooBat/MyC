#ifndef _ARRAY_BAG
#define _ARRAY_BAG

#include "BagInterface.hpp"
#include<algorithm>

template<class T>
class ArrayBag : public BagInterface<T> {
private:
    static const int DEFAULT_CAPACITY = 50;
    T items[DEFAULT_CAPACITY];   // Array of bag items
    int itemCount;                      // Current count of bag items
    int maxItems;                       // Max capacity of the bag;

    // Returns either the index of the element in the array items that 
    // contains the given target or -1, if the array does not contain 
    // the target.
    int getIndexOf(const T& target) const;

public:
    ArrayBag();

    int getCurrentSize() const;

    bool isEmpty() const;

    bool add(const T& newEntry);

    bool remove(const T& entry);

    void clear();

    int getFrequencyOf(const T& entry) const;

    bool contains(const T& entry) const;

    vector<T> toVector() const;

    bool replace(const T& entry, const T& newEntry);

    ArrayBag<T> Union(const ArrayBag<T>& other) const;

    ArrayBag<T> intersection(const ArrayBag<T>& other) const;

    ArrayBag<T> difference(const ArrayBag<T>& other) const;

    ArrayBag<T> operator= (const ArrayBag<T>& other);
};

template<class T>
int ArrayBag<T>::getIndexOf(const T& target) const {
    if (itemCount == 0) return -1;

    bool found = false;

    for (int i = 0; i < itemCount; i++) {
        if (items[i] == target) {
            return i;
        }
    }

    return -1;
}

template<class T>
ArrayBag<T>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}

template<class T>
int ArrayBag<T>::getCurrentSize() const {
    return itemCount;
}

template<class T>
bool ArrayBag<T>::isEmpty() const {
    return (itemCount == 0);
}

template<class T>
bool ArrayBag<T>::add(const T& newEntry) {
    if (itemCount >= maxItems) return false;

    items[itemCount] = newEntry;

    itemCount++;

    return true;
}

template<class T>
bool ArrayBag<T>::remove(const T& entry) {
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

template<class T>
void ArrayBag<T>::clear() {
    itemCount = 0;
}

template<class T>
int ArrayBag<T>::getFrequencyOf(const T& entry) const {
    if (itemCount == 0) return -1;

    int count = 0;

    for (int i = 0; i < itemCount; i++) {
        if (items[i] == entry) count++; 
    }

    return count;
}

template<class T>
bool ArrayBag<T>::contains(const T& entry) const {
    return getIndexOf(entry) > -1;
}

template<class T>
vector<T> ArrayBag<T>::toVector() const {
    vector<T> result;

    if (getCurrentSize() == 0) {
        return result;
    }

    for (int i = 0; i < itemCount; i++) {
        result.push_back(items[i]);
    }

    return result;
}

template<class T>
bool ArrayBag<T>::replace(const T& entry, const T& newEntry) {
    if (newEntry == entry || getCurrentSize() == 0 || !contains(entry)) {
        return false;
    } 

    int i = getIndexOf(entry);

    items[i] = newEntry;
    
    return true;
}

template<class T>
ArrayBag<T> ArrayBag<T>::Union(const ArrayBag<T>& other) const {
    ArrayBag<T> result;

    vector<T> v1 = this->toVector();
    vector<T> v2 = other.toVector();
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

template<class T>
ArrayBag<T> ArrayBag<T>::intersection(const ArrayBag<T>& other) const {
    ArrayBag<T> result;
    
    vector<T> v1 = this->toVector();
    vector<T> v2 = other.toVector();
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

template<class T>
ArrayBag<T> ArrayBag<T>::difference(const ArrayBag<T>& other) const {
    ArrayBag<T> result;
    
    vector<T> v1 = this->toVector();
    vector<T> v2 = other.toVector();
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

template<class T>
ArrayBag<T> ArrayBag<T>::operator= (const ArrayBag<T>& other) {
    itemCount = other.itemCount;
    maxItems = other.maxItems;

    for (int i = 0; i < itemCount; i++) {
        items[i] = other.items[i];
    }

    return *this;
}
#endif