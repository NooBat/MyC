#ifndef _DOUBLY_NODE
#define _DOUBLY_NODE

#include<iostream>

using namespace std;

template<class T>
class DoublyNode {
private:
    T item;
    DoublyNode<T>* next;
    DoublyNode<T>* prev;

public:
    DoublyNode();

    DoublyNode(const T& item);

    DoublyNode(const T& item, DoublyNode<T>* next, 
               DoublyNode<T>* previous);

    void setItem(const T& item);

    void setNext(DoublyNode<T>* next);

    void setPrevious(DoublyNode<T>* previous);

    T getItem() const;

    DoublyNode<T>* getNext() const;

    DoublyNode<T>* getPrevious() const;
};

template<class T>
DoublyNode<T>::DoublyNode(): next(nullptr), prev(nullptr) {

}

template<class T>
DoublyNode<T>::DoublyNode(const T& item): item(item), next(nullptr), prev(nullptr) {

}

template<class T>
DoublyNode<T>::DoublyNode(const T& item, 
                      DoublyNode<T>* next, 
                      DoublyNode<T>* previous) 
{
    this->setItem(item);
    this->setNext(next);
    this->setPrevious(previous);
}

template<class T>
void DoublyNode<T>::setItem(const T& item) {
    this->item = item;
}

template<class T>
void DoublyNode<T>::setNext(DoublyNode<T>* next) {
    this->next = next;
}

template<class T>
void DoublyNode<T>::setPrevious(DoublyNode<T>* previous) {
    this->prev = previous;
}

template<class T>
T DoublyNode<T>::getItem() const {
    return this->item;
}

template<class T>
DoublyNode<T>* DoublyNode<T>::getNext() const {
    return this->next;
}

template<class T>
DoublyNode<T>* DoublyNode<T>::getPrevious() const {
    return this->prev;
}
#endif