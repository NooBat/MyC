#include "LinkedList.h"
#include "ArrayList.h"
#include<iostream>

void displayList(ListInterface<string>* listPtr) {
    for (int i = 0; i < listPtr->getLength(); i++) {
        cout << listPtr->getEntry(i + 1) << " ";
    }

    cout << endl;
}

void listTester(ListInterface<string>* listPtr) {
    cout << "isEmpty: returns " << listPtr->isEmpty()
         << "; should be 1 (true)" << endl;

    string items[] = {"one", "two", "three", "four", "five", "one"};
    cout << "Add 6 items to the list: " << endl;
    for (int i = 0; i < 6; i++) {
        listPtr->insert(i + 1, items[i]);
    } // end for
    displayList(listPtr);
    cout << endl << endl;

    cout << "isEmpty: returns " << listPtr->isEmpty()
         << "; should be 0 (false)" << endl;
    cout << "getLength returns : " << listPtr->getLength()
         << "; should be 6" << endl;
    cout << "Try to add another entry: add(\"extra\") returns "
         << listPtr->insert(7, "extra") << endl;

    cout << endl << endl;

    LinkedList<string> aList(listPtr);

    displayList(&aList);

    cout << "Sort the list" << endl;
    sort(aList);
    displayList(&aList);
    cout << endl << endl;

    cout << "Clear list";
    listPtr->clear();
    cout << endl << endl;
}

int main() {
    ListInterface<string>* listPtr = nullptr;

    char arr[] = {'A', 'L', 'Q'};
    ArrayList<char> test(arr, 3);

    char userChoice = 'L';

    // cout << "Enter 'A' to test the array-based implementation\n"
    //      << " or 'L' to test the link-based implementation\n" 
    //      << " or 'Q' to quit: ";
    // cin >> userChoice;

    while (toupper(userChoice) != 'Q' && !test.isEmpty()) {
        if (toupper(userChoice) == 'A') {
            listPtr = new ArrayList<string>();
            test.remove(test.getPosition('A'));
            cout << "Testing Array-Based List:" << endl;
        }
        else if (toupper(userChoice) == 'L') {
            listPtr = new LinkedList<string>();
            test.remove(test.getPosition('L'));
            cout << "Testing Link-Based List:" << endl;
        }

        cout << "The initial list is empty" << endl;    
        try {
            listTester(listPtr);
        }
        catch (PrecondViolatedException& e) {
            cout << e.what() << endl;
            break;
        }
        delete listPtr;

        if (test.getEntry(1) == 'A') {
            cout << "Enter 'A' to test the array-based implementation\n";
        }
        else if (test.getEntry(1) == 'L') cout << "Enter 'L' to test the link-based implementation\n";
        else break;

        cout << " or 'Q' to quit: ";
        cin >> userChoice;
    }

    cout << "All done!" << endl;

    return 0;
}