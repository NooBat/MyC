#include "Ex8.hpp"
#include<iostream>
#include<string>

using namespace std;

template<class ItemType>
class StackIsA : public FrontList<ItemType>
{
public:
    StackIsA();

    bool isEmpty() const;

    // bool insert(const ItemType& newEntry);

    bool remove();

    void clear();

    ItemType getEntry() const;
};

template<class ItemType>
StackIsA<ItemType>::StackIsA() : FrontList<ItemType>::FrontList()
{

}

template<class ItemType>
bool StackIsA<ItemType>::isEmpty() const
{
    return FrontList<ItemType>::isEmpty();
}

// template<class ItemType>
// bool StackIsA<ItemType>::insert(const ItemType& newEntry)
// {
//     return FrontList<ItemType>::insert(newEntry);
// }

template<class ItemType>
bool StackIsA<ItemType>::remove()
{
    return FrontList<ItemType>::remove();
}

template<class ItemType>
void StackIsA<ItemType>::clear()
{
    FrontList<ItemType>::clear();
}

template<class ItemType>
ItemType StackIsA<ItemType>::getEntry() const
{
    return FrontList<ItemType>::getEntry();
}

int main()
{
    StackIsA<string> a;

    a.insert("new");

    cout << a.getEntry();

    return 0;
}