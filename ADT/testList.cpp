#include "LinkedList.h"
#include "ArrayList.h"

void displayList(ListInterface<string>* listPtr) {
    for (int i = 0; i < listPtr->getLength(); i++) {
        cout << listPtr->getEntry(i) << " ";
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

    cout << "isEmpty: returns " << listPtr->isEmpty()
         << "; should be 0 (false)" << endl;
    cout << "getLength returns : " << listPtr->getLength()
         << "; should be 6" << endl;
    cout << "Try to add another entry: add(\"extra\") returns "
         << listPtr->insert(7, "extra") << endl;

    cout << endl << endl;

    cout << "setEntry(1, \"newOne\")";
    listPtr->setEntry(1, "newOne");
    displayList(listPtr);

    cout << "Clear list";
    listPtr->clear();

    cout << "getEntry(1): returns";
}

int main() {
    ListInterface<string>* listPtr = nullptr;

    char arr[] = {'A', 'L', 'Q'};
    ArrayList<char> test(arr, 3);

    char userChoice;

    cout << "Enter 'A' to test the array-based implementation\n"
         << " or 'L' to test the link-based implementation\n" 
         << " or 'Q' to quit: ";
    cin >> userChoice;

    while (toupper(userChoice) != 'Q' && !test.isEmpty()) {
        if (toupper(userChoice) == 'A') {
            listPtr = new ArrayList<string>();
            test.remove(1);
            cout << "Testing Array-Based List:" << endl;
        }
        else if (toupper(userChoice) == 'L') {
            listPtr = new LinkedList<string>();
            test.remove(2);
            cout << "Testing Link-Based List:" << endl;
        }
        
        try {
            listTester(listPtr);
        }
        catch (PrecondViolatedException& e) {
            cout << e.what() << endl;
        }
        cout << "The initial list is empty" << endl;
        delete listPtr;

        if (test.getEntry(1) == 'A') {
            cout << "Enter 'A' to test the array-based implementation\n";
        }
        else cout << "Enter 'L' to test the link-based implementation\n";
        cout << " or 'Q' to quit: ";
        cin >> userChoice;
    }

}