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
    int getPosition(const ItemType& newEntry) const;

    bool isEmpty() const;
    int getLength() const;
    bool remove(int position);
    void clear();   
    ItemType getEntry(int position) const;
};

template<class ItemType>
void SortedListHasA<ItemType>::copyChain(LinkedList<ItemType>* originListPtr, LinkedList<ItemType>* copiedListPtr, int position)
{
    if (position >= originListPtr->getLength()) return;

    copyChain(originListPtr, copiedListPtr, position + 1);

    copiedListPtr->insert(1, originListPtr->getItem(position));
}



template<class ItemType>
SortedListHasA<ItemType>::SortedListHasA()
{
    listPtr = new LinkedList<ItemType>();
}

template<class ItemType>
SortedListHasA<ItemType>::SortedListHasA(const SortedListHasA<ItemType>& sList)
{
    listPtr = new LinkedList<ItemType>();

    copyChain(sList, listPtr);
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
int SortedListHasA<ItemType>::getPosition(const ItemType& newEntry) const 
{

}

#endif