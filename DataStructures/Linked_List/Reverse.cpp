#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

void reverse(Node **head) {
    Node *prev = NULL;    //points to the nth node
    Node *curr = *head;  //points to the (n+1)th node
    Node *next = curr->next;

    while (curr != NULL) {
        curr->next = prev;

        prev = curr;
        curr = next;
        next = next->next;
    }
    *head = prev;
}

void recursive(Node **head,Node *prev, Node *curr) {
    if (curr != NULL) {
        Node *next = (curr)->next;
        (curr)->next = prev;

        recursive(head ,curr, next);
    }
    else {
        *head = prev;
        return;
    }
}

void recur_reverse(Node **head) {
    Node *prev = *head;
    Node *curr = prev->next;
    
    prev->next = NULL;

    recursive(head, prev, curr);
}

void Insert(Node **head, int data) {
    Node *new_node = new Node();

    new_node->data = data;
    new_node->next = NULL;

    Node *temp;
    temp = *head;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }   
    temp->next = new_node;
    return;
}

void Print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node *A;
    A = NULL;

    int n;
    cout << "Nhập số liệu: ";
    cin >> n;

    while (n--) {
        int data;
        cout << "Nhập data: ";
        cin >> data;

        Insert(&A, data);

        cout << "List hiện tại: ";
        Print(A);
    }
    
    cout << "List sau khi đảo lại: ";
    recur_reverse(&A);  //or reverse(&A);
    Print(A);

    return 0;
}