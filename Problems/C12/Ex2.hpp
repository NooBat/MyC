#ifndef _ARRAY_SORTED_LIST
#define _ARRAY_SORTED_LIST

#include "/Users/danielnguyen/Repo/C++/ADT/SortedListInterface.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/PrecondViolatedException.hpp"

template<class T>
class ArraySortedList : public SortedListInterface<T>
{
private:
    T* theList;
    int itemCount;
    int maxItem;
    static const int NUMBER_OF_ITEMS;

    void resize();
    int getPositionRecur(const T& anEntry, int idx = 1) const;

public:
    ArraySortedList();

    ArraySortedList(const ArraySortedList<T>& sList);

    bool isEmpty() const;

    int getLength() const;

    void insertSorted(const T& newEntry);

    bool removeSorted(const T& anEntry);

    int getPosition(const T& anEntry);

    bool remove(int position);

    void clear();

    T getEntry(int position) const;
};

template<class T>
const int ArraySortedList<T>::NUMBER_OF_ITEMS = 50;

template<class T>
void ArraySortedList<T>::resize()
{
    maxItem += 10;

    T* newList = new T[maxItem];

    for (int i = 0; i < itemCount; i++)
    {
        newList[i] = theList[i];
    }

    delete[] theList;

    theList = newList;
    newList = nullptr;
}

template<class T>
int ArraySortedList<T>::getPositionRecur(const T& anEntry, int idx) const
{
    if (idx > itemCount) return 0 - idx;

    if (theList[idx - 1] < anEntry) return getPositionRecur(anEntry, idx + 1);
    else if (theList[idx - 1] == anEntry) return idx;
    return 0 - idx;
}

template<class T>
ArraySortedList<T>::ArraySortedList()
{
    maxItem = NUMBER_OF_ITEMS;
    itemCount = 0;
    theList = new T[maxItem];
}

template<class T>
ArraySortedList<T>::ArraySortedList(const ArraySortedList<T>& sList)
{
    maxItem = sList.maxItem;
    itemCount = sList.itemCount;

    theList = new T[maxItem];

    for (int i = 0; i < itemCount; i++)
    {
        theList[i] = sList.theList[i];
    }
}

template<class T>
bool ArraySortedList<T>::isEmpty() const
{
    return itemCount == 0;
}

template<class T>
int ArraySortedList<T>::getLength() const
{
    return itemCount;
}

template<class T>
void ArraySortedList<T>::insertSorted(const T& newEntry)
{
    int insertPosition = abs(getPosition(newEntry));

    if (insertPosition > maxItem)
    {
        resize();
    }

    theList[insertPosition - 1] = newEntry;
    itemCount++;
}

template<class T>
bool ArraySortedList<T>::removeSorted(const T& anEntry)
{
    int removePosition = getPosition(anEntry);

    if (removePosition < 0) return false;
    return remove(removePosition);
}

template<class T>
int ArraySortedList<T>::getPosition(const T& anEntry)
{
    return getPositionRecur(anEntry);
}

template<class T>
bool ArraySortedList<T>::remove(int position)
{
    if (position < 1 || position > itemCount) return false;

    for (; position < itemCount; position++)
    {
        theList[position - 1] = theList[position];
    }
    itemCount--;

    return true;
}

template<class T>
void ArraySortedList<T>::clear()
{
    delete[] theList;
    theList = nullptr;
    itemCount = 0;
}

template<class T>
T ArraySortedList<T>::getEntry(int position) const
{
    if (position < 1 || position > itemCount)
    {
        string message = "getEntry() called with an empty list or invalid position.";
        throw PrecondViolatedException(message);
    }

    return theList[position - 1];
}

#endif