#ifndef _ARRAY_SORTED_LIST
#define _ARRAY_SORTED_LIST

#include "/Users/danielnguyen/Repo/C++/ADT/SortedListInterface.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/PrecondViolatedException.hpp"

template<class ItemType>
class ArraySortedList : public SortedListInterface<ItemType>
{
private:
    ItemType* theList;
    int itemCount;
    int maxItem;
    static const int NUMBER_OF_ITEMS;

    void resize();
    int getPositionRecur(const ItemType& anEntry, int idx = 1) const;

public:
    ArraySortedList();

    ArraySortedList(const ArraySortedList<ItemType>& sList);

    bool isEmpty() const;

    int getLength() const;

    void insertSorted(const ItemType& newEntry);

    bool removeSorted(const ItemType& anEntry);

    int getPosition(const ItemType& anEntry);

    bool remove(int position);

    void clear();

    ItemType getEntry(int position) const;
};

template<class ItemType>
const int ArraySortedList<ItemType>::NUMBER_OF_ITEMS = 50;

template<class ItemType>
void ArraySortedList<ItemType>::resize()
{
    maxItem += 10;

    ItemType* newList = new ItemType[maxItem];

    for (int i = 0; i < itemCount; i++)
    {
        newList[i] = theList[i];
    }

    delete[] theList;

    theList = newList;
    newList = nullptr;
}

template<class ItemType>
int ArraySortedList<ItemType>::getPositionRecur(const ItemType& anEntry, int idx) const
{
    if (idx > itemCount) return 0 - idx;

    if (theList[idx - 1] < anEntry) return getPositionRecur(anEntry, idx + 1);
    else if (theList[idx - 1] == anEntry) return idx;
    return 0 - idx;
}

template<class ItemType>
ArraySortedList<ItemType>::ArraySortedList()
{
    maxItem = NUMBER_OF_ITEMS;
    itemCount = 0;
    theList = new ItemType[maxItem];
}

template<class ItemType>
ArraySortedList<ItemType>::ArraySortedList(const ArraySortedList<ItemType>& sList)
{
    maxItem = sList.maxItem;
    itemCount = sList.itemCount;

    theList = new ItemType[maxItem];

    for (int i = 0; i < itemCount; i++)
    {
        theList[i] = sList.theList[i];
    }
}

template<class ItemType>
bool ArraySortedList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template<class ItemType>
int ArraySortedList<ItemType>::getLength() const
{
    return itemCount;
}

template<class ItemType>
void ArraySortedList<ItemType>::insertSorted(const ItemType& newEntry)
{
    int insertPosition = abs(getPosition(newEntry));

    if (insertPosition > maxItem)
    {
        resize();
    }

    theList[insertPosition - 1] = newEntry;
    itemCount++;
}

template<class ItemType>
bool ArraySortedList<ItemType>::removeSorted(const ItemType& anEntry)
{
    int removePosition = getPosition(anEntry);

    if (removePosition < 0) return false;
    return remove(removePosition);
}

template<class ItemType>
int ArraySortedList<ItemType>::getPosition(const ItemType& anEntry)
{
    return getPositionRecur(anEntry);
}

template<class ItemType>
bool ArraySortedList<ItemType>::remove(int position)
{
    if (position < 1 || position > itemCount) return false;

    for (; position < itemCount; position++)
    {
        theList[position - 1] = theList[position];
    }
    itemCount--;

    return true;
}

template<class ItemType>
void ArraySortedList<ItemType>::clear()
{
    delete[] theList;
    theList = nullptr;
    itemCount = 0;
}

template<class ItemType>
ItemType ArraySortedList<ItemType>::getEntry(int position) const
{
    if (position < 1 || position > itemCount)
    {
        string message = "getEntry() called with an empty list or invalid position.";
        throw PrecondViolatedException(message);
    }

    return theList[position - 1];
}

#endif