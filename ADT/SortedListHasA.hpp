#ifndef _SORTED_LIST_HAS_A
#define _SORTED_LIST_HAS_A

#include "SortedListInterface.hpp"
#include "LinkedList.hpp"
#include "Node.hpp"
#include "PrecondViolatedException.hpp"

using namespace std;

template<class ItemType>
class SortedListHasA : public SortedListInterface<ItemType>
{
private:
    LinkedList<ItemType>* listPtr;

    void copyChain(LinkedList<ItemType>* originListPtr, LinkedList<ItemType>* copiedListPtr, int position = 1);
    
public:
    SortedListHasA();
    SortedListHasA(const SortedListHasA<ItemType>& sList);
    virtual ~SortedListHasA();

    void insertSorted(const ItemType& newEntry);
    bool removeSorted(const ItemType& anEntry);
    int getPosition(const ItemType& newEntry);

    bool isEmpty() const;
    int getLength() const;
    bool remove(int position);
    void clear();   
    ItemType getEntry(int position) const;
};

template<class ItemType>
void SortedListHasA<ItemType>::copyChain(LinkedList<ItemType>* originListPtr, LinkedList<ItemType>* copiedListPtr, int position)
{
    if (position > originListPtr->getLength()) return;

    copyChain(originListPtr, copiedListPtr, position + 1);

    copiedListPtr->insert(1, originListPtr->getEntry(position));
}



template<class ItemType>
SortedListHasA<ItemType>::SortedListHasA()
{
    listPtr = new LinkedList<ItemType>();
}

template<class ItemType>
SortedListHasA<ItemType>::SortedListHasA(const SortedListHasA<ItemType>& sList)
{
    listPtr = new LinkedList<ItemType>(sList.listPtr);

    // for (int i = 1; i <= sList.getLength(); i++)
    // {
    //     listPtr->insert(i, sList.getEntry(i));
    // }
}

template<class ItemType>
SortedListHasA<ItemType>::~SortedListHasA()
{
    clear();
}

template<class ItemType>
void SortedListHasA<ItemType>::insertSorted(const ItemType& newEntry)
{
    int newPosition = abs(getPosition(newEntry));

    listPtr->insert(newPosition, newEntry);
}

template<class ItemType>
bool SortedListHasA<ItemType>::removeSorted(const ItemType& anEntry)
{
    int position = getPosition(anEntry);

    if (position < 0) return false;
    return listPtr->remove(position);
}

template<class ItemType>
int SortedListHasA<ItemType>::getPosition(const ItemType& newEntry) 
{
    int result = 1;

    for (int i = 1; i <= listPtr->getLength(); i++)
    {
        int result;
        if (newEntry < listPtr->getEntry(i)) 
        {
            result = 0 - i;
            break;
        }

        if (newEntry == listPtr->getEntry(i))
        {
            result = i;
            break;
        }
    }

    return result;
}


template<class ItemType>
bool SortedListHasA<ItemType>::isEmpty() const
{
    return listPtr->isEmpty();
}

template<class ItemType>
int SortedListHasA<ItemType>::getLength() const
{
    return listPtr->getLength();
}

template<class ItemType>
bool SortedListHasA<ItemType>::remove(int position)
{
    return listPtr->remove(position);
}

template<class ItemType>
void SortedListHasA<ItemType>::clear()
{
    listPtr->clear();
    listPtr = nullptr;
}

template<class ItemType>
ItemType SortedListHasA<ItemType>::getEntry(int position) const
{
    return listPtr->getEntry(position);
}

#endif