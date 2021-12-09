#include "LL/Users/danielnguyen/Repo/C++/ADT/Node.hpp"
#include "LLNode.cpp"

int main()
{
    int arr[] = {4, 42,3, 134,1512, 134,1 };
    int k = 3;
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int)); 
    LLNode::printList(head);
    cout << "\n";
    LLNode* newhead = reverseLinkedList(head);
    LLNode::printList(newhead);

    return 0;
}