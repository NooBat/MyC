#include "LLNode.hpp"
#include "LLNode.cpp"

int main()
{
    int arr[] = {9, 5, 7, 5, 0};
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int)); 
    LLNode::printList(head);
    cout << "\n";
    LLNode* newhead = foldLinkedList(head);
    LLNode::printList(newhead);

    return 0;
}