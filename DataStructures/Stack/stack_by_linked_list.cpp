#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
};

void push(Node **top, int data) {
    Node *new_node = new Node();
    
    new_node->data = data;
    new_node->next = *top;

    *top = new_node;
}

void pop(Node **top) {
    if (*top == NULL) {
        cout << "ERROR: No element to pop!";
        return;
    }
    Node *temp = *top;

    *top = temp->next;
    
    delete temp;

}

int Top(Node *top) {
    return (top->data);
}

bool IsEmpty(Node *top) {
    if (top == NULL) return true;
    else return false;
}

void print(Node *p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    Node *stack;
    stack = NULL;

    int n;
    cout << "Nhập số liệu: ";
    cin >> n;

    while (n--) {
        int data;
        cout << "Nhập data: ";
        cin >> data;

        push(&stack, data);
        print(stack);
    }

    int t;
    cout << "Nhập số lần cần pop: ";
    cin >> t;

    while (t--) {
        pop(&stack);
        print(stack);
    }

    cout << "Phần tử nằm trên stack: ";
    cout << Top(stack) << endl;

    return 0;
}