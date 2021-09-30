#include "/Users/danielnguyen/Repo/C++/Lab/SinglyLinkedList/SLL.hpp"

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
    if (index < 0 || index > count) throw out_of_range("Invalid index");

    count++;

    if (index == 0)
    {
        Node* newNodePtr = new Node(e);

        newNodePtr->next = head;

        head = newNodePtr;
    }
    else if (index == count)
    {
        Node* newNodePtr = new Node(e);

        tail->next = newNodePtr;

        tail = newNodePtr;
    }
    else 
    {
        Node* prevPtr = nullptr;
        Node* currPtr = head;

        for (int i = 0; i < index; i++)
        {
            prevPtr = currPtr;
            currPtr = currPtr->next;
        }

        Node* newNodePtr = new Node(e);

        prevPtr->next = newNodePtr;
        newNodePtr->next = currPtr;
    }
}

template<class T>
int SLinkedList<T>::size() 
{
    return count;
}

template<class T>
void SLinkedList<T>::clear()
{
    Node* currPtr = head;  

    while (currPtr != nullptr)
    {
        Node* nextPtr = currPtr->next;

        currPtr->next = nullptr;
        delete currPtr;

        currPtr = nextPtr;
    }

    head = nullptr;
    tail = nullptr;
    count = 0;
}

template<class T>
bool SLinkedList<T>::empty()
{
    return count == 0;
}

template<class T>
T SLinkedList<T>::get(int index)
{
    if (index < 0 || index >= count) throw out_of_range("Invalid index");

    Node* currPtr = head;

    for (int i = 0; i < index; i++)
    {
        currPtr = currPtr->next;
    }

    return currPtr->data;
}

template<class T>
void SLinkedList<T>::set(int index, T e)
{
    if (index < 0 || index >= count) throw out_of_range("Invalid index");

    Node* currPtr = head;

    for (int i = 0; i < index; i++)
    {
        currPtr = currPtr->next;
    }

    currPtr->data = e;
}

template<class T>
int SLinkedList<T>::indexOf(T item)
{
    int result = -1;

    Node* currPtr = head;
    for (int i = 0; i < count; i++)
    {
        if (currPtr->data == item) 
        {
            result = i;
            break;
        }
        currPtr = currPtr->next;
    }

    return result;
}

template<class T>
bool SLinkedList<T>::contains(T item)
{
    bool result = false;

    Node* currPtr = head;
    for (int i = 0; i < count; i++)
    {
        if (currPtr->data == item) 
        {
            result = true;
            break;
        }
        currPtr = currPtr->next;
    }

    return result;
}

template<class T>
T SLinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= count) throw out_of_range("Invalid index");

    count--;
    T item;
    Node* currPtr = head;
    if (count == 1)
    {
        head = nullptr;
        tail = nullptr;
    }
    else if (index == 0)
    {
        head = head->next;
    }
    else if (index == count - 1)
    {
        while (currPtr->next != tail)
        {
            currPtr = currPtr->next;
        }

        tail = currPtr;
        currPtr = currPtr->next;
        tail->next = nullptr;
    }
    else 
    {
        Node* prevPtr = nullptr;
        for (int i = 0; i < index; i++)
        {
            prevPtr = currPtr;
            currPtr = currPtr->next;
        }

        Node* nextPtr = currPtr->next;

        prevPtr->next = nextPtr;
    }

    item = currPtr->data;
    currPtr->next = nullptr;
    delete currPtr;

    return item;
}

template<class T>
bool SLinkedList<T>::removeItem(T item)
{
    bool isAbleRemove = false;
    Node* currPtr = nullptr;
    
    if (head == tail)
    {
        currPtr = head;
        head = nullptr;
        tail = nullptr;
    }
    else if (head->data == item)
    {
        currPtr = head;
        head = head->next;
    }
    else if (tail->data == item)
    {
        currPtr = head;
        while (currPtr->next != tail)
        {
            currPtr = currPtr->next;
        }

        tail = currPtr;
        currPtr = currPtr->next;
        tail->next = nullptr;
    }
    else 
    {
        currPtr = head;
        Node* prevPtr = nullptr;

        while (currPtr != tail)
        {
            if (currPtr->data == item)
            {
                break;
            }
            prevPtr = currPtr;
            currPtr = currPtr->next;
        }

        prevPtr->next = currPtr->next;
    }

    if (currPtr != nullptr) 
    {
        currPtr->next = nullptr;
        delete currPtr;
        count--;
        isAbleRemove = true;
        currPtr = nullptr;
    }

    return isAbleRemove;
}

template<class T>
vector<T> SLinkedList<T>::toVector()
{
    vector<T> result;
    for (int i = 0; i < count; i++)
    {
        result.push_back(get(i));
    }

    return result;
}