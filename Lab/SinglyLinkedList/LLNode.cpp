#include "LLNode.hpp"
#include<stack>

void LLNode::add(LLNode*& head, int val)
{
    if (head == nullptr)
    {
        LLNode* newNodePtr = new LLNode(val);
        head = newNodePtr;
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

void add(LLNode*& head, int val)
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
        else add(newHead, arr[i] + arr[size - 1 - i]);
    }

    return newHead;
}

LLNode* replaceFirstGreater(LLNode* head)
{
    LLNode* curr = head;
    LLNode* newHead = nullptr;
    stack<int> result;
    stack<int> st;

    while (curr)
    {
        st.push(curr->val);
        curr = curr->next;
    }

    if (!st.empty())
    {
        int temp = st.top();
        int next = st.top();
        st.pop();
        result.push(0);

        while (!st.empty())
        {
            if (next < st.top())
            {
                if (temp == st.top())
                {
                    result.push(0);
                }
                else if (temp > st.top())
                {
                    result.push(temp);
                }
                else
                {
                    temp = st.top();
                    result.push(0);
                }
            }
            else if (next == st.top())
            {
                result.push(0);
            }
            else 
            {
                result.push(next);
                temp = next;
            }

            next = st.top();
            st.pop();
        }
    }

    while (!result.empty())
    {
        add(newHead, result.top());
        result.pop();
    }

    return newHead;
}

LLNode* rotateLinkedList(LLNode* head, int k)
{
    int size = countItem(head);

    LLNode* newHead = nullptr;

    if (size == 0) return newHead;

    int* arr = new int[size];

    toArray(head, arr);

    k = k % size;

    int sizeL = size - k;

    for (int i = 0; i < sizeL / 2; i++)
    {
        swap(arr[i], arr[sizeL - 1 - i]);
    }

    for (int i = 0; i < (size - sizeL) / 2; i++)
    {
        swap(arr[i + sizeL], arr[size - 1]);
    }

    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[size - 1 - i]);
    }

    for (int i = 0; i < size; i++)
    {
        add(newHead, arr[i]);
    }

    return newHead;
}

LLNode* reverseLinkedList(LLNode* head)
{
    if (head == nullptr) return nullptr;

    LLNode* newHead = nullptr;

    int size = countItem(head);

    int* arr = new int[size];

    toArray(head, arr);

    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[size - 1 - i]);
    }

    for (int i = 0; i < size; i++)
    {
        add(newHead, arr[i]);
    }

    return newHead;
}