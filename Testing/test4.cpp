#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>
#include<algorithm>

using namespace std;
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
int main() {  
    char a = 'a';


    cout << sizeof(a) << endl;
    cout << sizeof(a - '0') << endl;
    // cout << obj.reverse(a);

    return 0;
}
