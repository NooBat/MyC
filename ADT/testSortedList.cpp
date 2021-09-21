#include "LinkedSortedList.h"


#include<iostream>

using namespace std;

void displayList(LinkedSortedList<string> list) {
    for (int i = 0; i < list.getLength(); i++) {
        cout << list.getEntry(i + 1) << " ";
    }

    cout << endl;
}

void listTester(LinkedSortedList<string>& list)
{
    cout << "isEmpty: returns " << list.isEmpty()
         << "; should be 1 (true)" << endl;

    string items[] = {"one", "two", "three", "four", "five", "one"};
    cout << "Add 6 items to the list: " << endl;
    for (int i = 0; i < 6; i++) {
        list.insertSorted(items[i]);
    } // end for
    displayList(list);
    cout << endl << endl;

    cout << "isEmpty: returns " << list.isEmpty()
         << "; should be 0 (false)" << endl;
    cout << "getLength returns : " << list.getLength()
         << "; should be 6" << endl;
    cout << "Try to add another entry: add(\"ten\")" << endl;
    list.insertSorted("ten");
    displayList(list);

    cout << endl << endl;

    cout << "getPosition(\"ten\"): returns: " << list.getPosition("ten")
         << "; should be 5." << endl;
    cout << "getPosition(\"six\"): returns: " << list.getPosition("six")
         << "; should be -5";
    cout << endl << endl;

    cout << "removeSorted(\"one\"): returns: " << list.removeSorted("one")
         << "; should be 1 (true)." << endl;
    cout << "removeSorted(\"seven\"): returns: " << list.removeSorted("seven")
         << "; should be 0 (false)." << endl;
    displayList(list);

    cout << endl << endl;
}

int main() 
{
    LinkedSortedList<string> aList;

    cout << "Testing link-based sorted list" << endl;

    cout << "The initial list is empty." << endl;

    listTester(aList);

    cout << "All done!";

    return 0;
}