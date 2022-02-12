#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
};

//Call by reference using a pointer to head node
void Insert(Node **head_ref, int data) {
    Node *new_node = new Node();

    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        //if list is empty then create the new node as head
        *head_ref = new_node;
        return;
    }

    Node *temp = *head_ref;
    
    //Traversing through the list until the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    //Create the new link to the new node
    temp->next = new_node;
    return;
}

void Print(Node *p) {
    if (p != NULL) {
        cout << p->data << " ";
        Print(p->next);
    }
    else return;
}

void Print_back(Node *p) {
    if (p != NULL) {
        Print_back(p->next);
        cout << p->data << " ";
    }
    else return;
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

        Insert(&A, data);

        cout << "List hiện tại: ";
        Print(A);

        cout << endl;
    }

    cout << "List sau khi đảo: ";
    Print_back(A);

    return 0;
}