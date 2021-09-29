#include "Ex1.hpp"

template<class T>
void SLinkedList<T>::add(T e)   
{
    count++;
    if (head == nullptr)
    {
        head = new Node(e);
        tail = head;
    }
    else 
    {
        Node* newNodePtr = new Node(e);
        tail->next = newNodePtr;
        tail = tail->next;
    }
}

template<class T>
void SLinkedList<T>::add(int index, T e)
{
    if (index < 0 || index >= count) throw out_of_range("Invalid index of element");

    count++;
    Node* currPtr = head;

    for (int i = 0; i < index; i++)
    {
        currPtr = currPtr->next;
    }

    
}