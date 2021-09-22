#include "Ex4.hpp"
#include "Ex6.hpp"

#include<vector>
#include<iostream>

void display(const DoublyLinkedBag<string>& bag) {
    vector<string> v = bag.toVector();

    if (v.size() == 0) {
         cout << "The bag is empty!\n";
         return;
    }

    for (int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1];

    cout << endl;
}

void bagTester(DoublyLinkedBag<string>& bag) {
    cout << "isEmpty: returns " << bag.isEmpty()
         << "; should be 1 (true)" << endl;
    display(bag);
    cout << endl << endl;

    cout << "add(\"apple\"): returns " << bag.add("apple")
         << "; should be 1 (true)" << endl;
    cout << "Now the bag has: ";
    display(bag);
    cout << endl << endl;

    cout << "Add 6 new items: ";
    string str[] = {"milk", "eggs", "potato", "water", "juice", "Apple"};

    for (int i = 0; i < 6; i++) {
        bag.add(str[i]);
    }
    display(bag);
    cout << endl << endl;

    cout << "contains(\"juice\"): returns " << bag.contains("juice")
         << "; should be 1 (true)" << endl;
    cout << "remove(\"apple\"): returns " << bag.remove("apple") 
         << "; should be 1 (true)" << endl;
    cout << "remove(\"juice\"): returns " << bag.remove("juice")
         << "; should be 1 (true)" << endl;
    cout << "contains(\"juice\"): returns " << bag.contains("juice")
         << "; should be 0 (false)" << endl;
    cout << "remove(\"null\"): returns " << bag.remove("null")
         << "; should be 0 (false)" << endl;
    display(bag);
    cout << endl << endl;

    cout << "Clear bag!" << endl;
    bag.clear();

    cout << "isEmpty: returns " << bag.isEmpty() 
         << "; should be 1 (true)" << endl;
    cout << endl << endl;
}

int main() {
    cout << "Testing Doubly-Linked-ADT: " << endl;

    DoublyLinkedBag<string> bag;

    bagTester(bag);

    cout << "All done!" << endl;

    return 0;
}