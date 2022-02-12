#include<iostream>

using namespace std;

int top = -1;

void push(int arr[], int x) {
    if (top == 999) {
        cout << "ERROR: Stack overflow!";
        cout << endl;
        return;
    }
    else {
        arr[++top] = x;
    }
} 

void pop(int arr[]) {
    if (top != -1) {
        top -= 1;
        return;
    }
    else {
        cout << "ERROR: No element to pop!";
        cout << endl;
    }
}

int Top(int arr[]) {
    if (top == -1) {
        return 0;
    }
    return arr[top];
}

bool empty(int arr[]) {
    if (top == -1) {
        return true;
    }
    else return false;
}

int main() {
    int stack[1000];

    int n;
    cout << "Nhập số liệu: ";
    cin >> n;

    while (n--) {
        int data;
        cout << "Nhập data: ";
        cin >> data;

        push(stack, data);
        
        cout << "Stack: ";
        for (int i = top; i >= 0; --i) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}