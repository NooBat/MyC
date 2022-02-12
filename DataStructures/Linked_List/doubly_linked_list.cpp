#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;
};

void InsertAtHead(Node **head_ref, int data) {
    Node *new_node = new Node();
    new_node->data = data;
    new_node->prev = NULL;
    
    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }
    else {
        Node *temp = *head_ref;
        
        new_node->next = temp;

        temp->prev = new_node;

        *head_ref = new_node;

        return;
    }
}

void InsertAtBack(Node **head_ref, int data) {
    Node *new_node = new Node();

    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;

        return;
    }
    Node *temp = *head_ref;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void Print(Node *p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void ReversePrint(Node *p) {
    while (p->next != NULL) {
        p = p->next;
    }
    while (p != NULL) {
        cout << p->data << " ";
        p = p->prev;
    }
    cout << endl;
}

int main() {
    Node *A;
    A = NULL;

    int n;
    cout << "Nhập số liệu: "; 
    cin >> n;

    while(n--) {
        int data;
        cout << "Nhập data: ";
        cin >> data;

        char a;
        cout << "Front(f) or Back(b) or Position(p): ";
        cin.ignore();
        cin >> a;

        if (a == 'b') {
            InsertAtBack(&A, data);
            Print(A);
        }
        else if (a == 'f') {
            InsertAtHead(&A, data);
            Print(A);
        }
        // else {
        //     cout << "Nhập vị trí: ";
        //     int idx;
        //     cin >> idx;
        //     A = push(A, data, idx);
        // }
    }

    cout << "List sau khi đảo lại là: ";
    ReversePrint(A);

    return 0;
}