#include "LLNode.hpp"

void LLNode::add(LLNode* head, int val)
{
    if (head == nullptr)
    {
        head = new LLNode(val);
    }
    else
    {
        LLNode* curr = head;

        while (curr->next != nullptr)
        {
            curr = curr->next;
        }

        curr->next = new LLNode(val);
    }
}

LLNode::LLNode()
{
    val = 0;
    next = 0;
}

LLNode::LLNode(int val, LLNode* next)
{
    this->val = val;
    this->next = next;
}

int countItem(LLNode* head)
{
    int count = 0;

    LLNode* curr = head;

    while (curr != nullptr)
    {
        count++;
        curr = curr->next;
    }

    return count;
}

void toArray(LLNode* head, int arr[])
{
    LLNode* curr = head;
    int idx = 0;

    while (curr)
    {
        arr[idx++] = curr->val;
        curr = curr->next;
    }
}

void add(LLNode* head, int val)
{
    if (head == nullptr) 
    {
        head = new LLNode(val);
    }
    else
    {
        LLNode* curr = head;

        while (curr->next != nullptr)
        {
            curr = curr->next;
        }

        curr->next = new LLNode(val);
    }
}

LLNode* foldLinkedList(LLNode* head)
{
    int size = countItem(head);

    int *arr = new int[size];

    LLNode* newHead = nullptr;

    toArray(head, arr);

    for (int i = (size - 1) / 2 ; i >= 0; i--)
    {
        if (i == size - 1 - i) add(newHead, arr[i]);
        add(newHead, arr[i] + arr[size - 1 - i]);
    }

    return newHead;
}