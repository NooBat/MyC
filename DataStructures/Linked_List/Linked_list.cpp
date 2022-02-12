#include<iostream>

using namespace std;
class Node {
    public:
    int data;
    Node *next;
};

void delete_node(Node **head, int idx) {
    Node *temp1 = *head;    //temp1 points to the (n-1)th node
 

    if (idx == 1) {
        *head = temp1->next;
        delete temp1;
        return;
    }
    else {
        for (int i = 0; i < idx - 2; i++) {
            temp1 = temp1->next;    
        }
        Node *temp2 = temp1->next;    //temp2 points to the nth node

        temp1->next = temp2->next;  
        delete temp2;  
        return; 
    }
}
Node *push_back(Node *head, int data) {
    Node *new_node = new Node();
    
    Node *temp;
    temp = head;

    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return head;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

Node *push_front(Node *head, int data) {
    Node *new_node = new Node();
    
    new_node->data = data;
    new_node->next = head;

    head = new_node;
    
    return head;
}

Node *push(Node *head, int data, int idx) {
    if (idx == 1) {
        Node *new_node = new Node();

        new_node->data = data;
        new_node->next = head;

        head = new_node;
    }
    else {
        Node *temp1 = new Node();
    
        temp1->data = data;
        temp1->next = NULL;

        Node *temp2 = head;
        for (int i = 0; i < idx - 2; i++) {
           temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
    }
    
    return head;
}

void print(Node *n) {
    Node *temp = n;
    while (temp != NULL) {
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

    for (int i = 0; i < n; i++) {
        int data;   
        cout << "Nhập data: ";
        cin >> data;

        char a;
        cout << "Front(f) or Back(b) or Position(p): ";
        cin.ignore();
        cin >> a;

        if (a == 'b')
        A = push_back(A, data);
        else if (a == 'f') A = push_front(A, data);
        else {
            cout << "Nhập vị trí: ";
            int idx;
            cin >> idx;
            A = push(A, data, idx);
        }
        print(A);
    }

    int idx;
    cout << "Choose element to delete: ";
    cin >> idx;

    if (idx <= 0) {
        cout << "DONE" << endl;
    }
    else {
        delete_node(&A, idx);
        print(A);
    }

    return 0;
}