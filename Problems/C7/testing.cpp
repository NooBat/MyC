#include "Ex1.h"
#include "Ex1.cpp"
#include<iostream>

using namespace std;

void display(ArrayStack<string>& st) {
    if (st.isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }

    vector<string> v = st.toVector();

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;
}

void stackTester(ArrayStack<string>& st) {
    cout << "isEmpty: returns " << st.isEmpty() 
         << "; should be 1 (true)" << endl;
    display(st);

    cout << endl << endl;

    cout << "Add 6 item to stack: ";
    string pack[] = {"one", "two", "three", "four", "five", "six"};
    for (int i = 0; i < 6; i++) {
        st.push(pack[i]);
    }

    cout << "isEmpty: returns " << st.isEmpty()
         << "; should be 0 (false)" << endl;
    cout << "peek: returns " << st.peek() 
         << "; should be six" << endl;
    display(st);
    cout << endl << endl;

    cout << "push(\"ten\"): returns " << st.push("ten")
         << "; shoud be 1 (true)" << endl;
    cout << "peek: returns " << st.peek()
         << "; should be ten" << endl;
    display(st);
    cout << endl << endl;

    cout << "pop: returns " << st.pop()
         << "; should be 1 (true)" << endl;
    cout << "Pop all item out of stack" << endl;
    while (!st.isEmpty()) {
        st.pop();
    }
    cout << "pop: returns " << st.pop()
         << "; should be 0 (false)" << endl;
}

int main() {
    cout << "Testing ADT array-based stack" << endl;

    ArrayStack<string> aStack;
    try {
        stackTester(aStack);
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    cout << "All done!" << endl;
    
    return 0;
}