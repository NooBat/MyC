#include<bits/stdc++.h>

using namespace std;

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

class Node
{
public:
    int data;
    Node* next;
    BalanceValue balance;

    Node(int data): data(data), next(nullptr), balance(EH) {}
    ~Node() {}
};

int main()
{  
    Node* head = new Node(2);

    cout << head->balance << endl;
    return 0;
}
