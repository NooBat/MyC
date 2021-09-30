#ifndef _LINKED_LIST_NODE
#define _LINKED_LIST_NODE

#include<iostream>
#include<iterator>

using namespace std;

class LLNode
{
private:
    static void add(LLNode*& head, int val);
public:
    int val;
    LLNode* next;
    
    LLNode();
    LLNode(int val, LLNode* next = nullptr);

    template<class BidirIt>
    static LLNode* createWithIterators(BidirIt first, BidirIt last)
    {
        LLNode* head = nullptr;
        while (first != last)
        {
            LLNode::add(head, *first);
            first++;
        }

        return head;
    }
    static void printList(LLNode* head)
    {
        LLNode* curr = head;

        cout << "[";
        while (curr != nullptr)
        {
            cout << curr->val;
            if (curr->next != nullptr)
            {
                cout << ", ";
            }
            curr = curr->next;
        }

        cout << "]" << endl;
    }
};

#endif