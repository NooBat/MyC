#include<iostream>
#include<stack>
#include<string>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
};

Node *InsertAtFront(Node *head, int data) {
    Node *new_node = new Node();

    new_node->data = data;
    new_node->next = head;

    head = new_node;

    return head;
}

Node *InsertAtBack(Node *head, int data) {
    Node *new_node = new Node();

    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return head;
    }
    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;

    return head;
}

//function to reverse a linked list using stack
Node *reverse_list(Node *head1) {
    stack<Node *> s;

    Node *temp = head1;
    while (temp != NULL) {
        s.push(temp);
        temp = temp->next;
    }   //implementing stack of pointer to nodes

    temp = s.top();
    Node *head2 = temp;
    s.pop();

    while(!s.empty()) {
        temp->next = s.top();
        temp = s.top();
        s.pop();
    }
    temp->next = NULL;

    return head2;
}

void print_list(Node *p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void reverse(char C[], int n) {
    stack<char> temp;
    for (int i = 0; i < n; i++) {
        temp.push(C[i]);
    }   //implementing stack of characters

    for (int i = 0; i < n; i++) {
        C[i] = temp.top();
        temp.pop();
    }
}

void print(char C[], int n) {
    for (int i = 0; i < n; i++) {
        cout << C[i];
    }
    cout << endl;
}

int main() {
    //reverse string using stack
    string s;

    cout << "Nhập chuỗi: ";
    getline(cin, s);

    char C[s.length()];

    for (int i = 0; i < s.length(); i++) {
        C[i] = s[i];
    }

    reverse(C, strlen(C));

    cout << "Chuỗi sau khi đảo: ";
    print (C, strlen(C));

    //Reverse linked list using stack
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
        cout << "Front(f) or Back(b): ";
        cin.ignore();
        cin >> a;

        if (a == 'b') A = InsertAtBack(A, data);
        else A = InsertAtFront(A, data);

        cout << "List hiện tại: ";
        print_list(A);
    }

    A = reverse_list(A);

    cout << "List sau khi đảo: ";
    print_list(A);

    return 0;
}