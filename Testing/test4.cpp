#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>
#include<algorithm>

using namespace std;

class ListNode {
public: 
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int val) {
        this->val = val;
        next = nullptr;
    }
};

ListNode* createList(ListNode* head, int arr[], int n) {
    if (n == 0) return nullptr;

    head = new ListNode(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        ListNode* temp = new ListNode(arr[i]);

        temp->next = head;
        head = temp;
    }

    return head;
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* i = head;
        ListNode* j = head->next;
        bool removable = false;
        
        while (i != nullptr && j != nullptr) {
            if (i->val == j->val) {
                j = j->next;
                removable = true;
            }
            else if (i->val != j->val || j == nullptr) {
                ListNode* p = i->next;
                while (p != j) {
                    ListNode* next = p->next;
                    p->next = nullptr;
                    delete p;
                    p = next;
                }
                
                i->next = j;
                i = i->next;
                j = i->next;
            }
        }
        
        return head;
    }
};

void printList(ListNode* p) {
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {  
    ListNode* head = nullptr;

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    head = createList(head, arr, n);

    Solution obj;

    obj.deleteDuplicates(head);

    printList(head);

    return 0;
}
