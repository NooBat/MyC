#include "Ex8.hpp"
#include<iostream>
#include<string>

using namespace std;

template<class T>
class StackIsA : public FrontList<T>
{
public:
    StackIsA();

    bool isEmpty() const;

    // bool insert(const T& newEntry);

    bool remove();

    void clear();

    T getEntry() const;
};

template<class T>
StackIsA<T>::StackIsA() : FrontList<T>::FrontList()
{

}

template<class T>
bool StackIsA<T>::isEmpty() const
{
    return FrontList<T>::isEmpty();
}

// template<class T>
// bool StackIsA<T>::insert(const T& newEntry)
// {
//     return FrontList<T>::insert(newEntry);
// }

template<class T>
bool StackIsA<T>::remove()
{
    return FrontList<T>::remove();
}

template<class T>
void StackIsA<T>::clear()
{
    FrontList<T>::clear();
}

template<class T>
T StackIsA<T>::getEntry() const
{
    return FrontList<T>::getEntry();
}

int main()
{
    StackIsA<string>* a = new StackIsA<string>();

    a->insert("new");

    cout << a->getEntry();

    return 0;
}