#include "LinkedList.hpp"

void LinkedList::add(int value)
{
    if (size == 0)
    {
        head = tail = new Node(value);
    }
    else
    {
        tail->next = new Node(value);

        tail = tail->next;
    }

    size++;
}

string LinkedList::toString()
{
    string result = "[";
    
    Node* currPtr = head;

    while (currPtr)
    {
        result += to_string(currPtr->value) + ", ";
        currPtr = currPtr->next;
    }

    result = result.substr(0, result.length() - 2);

    result += "]";

    return result;
}

void LinkedList::partition(int k)
{
    LinkedList* left = new LinkedList();
    LinkedList* right = new LinkedList();
    LinkedList* mid = new LinkedList();

    Node* currPtr = head;

    while (currPtr)
    {
        if (currPtr->value > k)
        {
            right->add(currPtr->value);
        }
        else if (currPtr->value < k)
        {
            left->add(currPtr->value);
        }
        else {
            mid->add(currPtr->value);
        }

        currPtr = currPtr->next;
    }

    left->tail->next = mid->head;
    mid->tail->next = right->head;

    currPtr = head;

    while (currPtr)
    {
        Node* nextPtr = currPtr->next;

        currPtr->next = nullptr;
        delete currPtr;

        currPtr = nextPtr;
    }

    this->head = left->head;
    this->tail = right->tail;

    left = mid = right = nullptr;
}