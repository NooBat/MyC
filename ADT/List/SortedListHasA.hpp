#ifndef _SORTED_LIST_HAS_A
#define _SORTED_LIST_HAS_A

#include "SortedListInterface.hpp"
#include "LinkedList.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/Node.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/PrecondViolatedException.hpp"

using namespace std;

template<class T>
class SortedListHasA : public SortedListInterface<T>
{
private:
    LinkedList<T>* listPtr;

    Node<T>* copyChain(Node<T>* originListPtr, int position = 1);
    
public:
    SortedListHasA();
    SortedListHasA(const SortedListHasA<T>& sList);
    virtual ~SortedListHasA();

    void insertSorted(const T& newEntry);
    bool removeSorted(const T& anEntry);
    int getPosition(const T& newEntry);

    bool isEmpty() const;
    int getLength() const;
    bool remove(int position);
    void clear();   
    T getEntry(int position) const;
};

template<class T>
Node<T>* SortedListHasA<T>::copyChain(Node<T>* originListPtr, int position)
{
    if (originListPtr == nullptr) return nullptr;

    Node<T>* currPtr = new Node<T>(originListPtr->getItem());
    currPtr->setNext(copyChain(originListPtr->getNext(), position + 1));

    return currPtr;
}



template<class T>
SortedListHasA<T>::SortedListHasA()
{
    listPtr = new LinkedList<T>();
}

template<class T>
SortedListHasA<T>::SortedListHasA(const SortedListHasA<T>& sList)
{
    Node<T>* head = sList.listPtr->getHead();

    listPtr = new LinkedList<T>(copyChain(head));
}

template<class T>
SortedListHasA<T>::~SortedListHasA()
{
    clear();
}

template<class T>
void SortedListHasA<T>::insertSorted(const T& newEntry)
{
    int newPosition = abs(getPosition(newEntry));

    listPtr->insert(newPosition, newEntry);
}

template<class T>
bool SortedListHasA<T>::removeSorted(const T& anEntry)
{
    int position = getPosition(anEntry);

    if (position < 0) return false;
    return listPtr->remove(position);
}

template<class T>
int SortedListHasA<T>::getPosition(const T& newEntry) 
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


template<class T>
bool SortedListHasA<T>::isEmpty() const
{
    return listPtr->isEmpty();
}

template<class T>
int SortedListHasA<T>::getLength() const
{
    return listPtr->getLength();
}

template<class T>
bool SortedListHasA<T>::remove(int position)
{
    return listPtr->remove(position);
}

template<class T>
void SortedListHasA<T>::clear()
{
    listPtr->clear();
    listPtr = nullptr;
}

template<class T>
T SortedListHasA<T>::getEntry(int position) const
{
    return listPtr->getEntry(position);
}

#endif