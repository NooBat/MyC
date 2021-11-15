#include "/Users/danielnguyen/Repo/C++/ADT/List/LinkedSortedList.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/List/SortedListHasA.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/List/ArrayList.hpp"
#include "/Users/danielnguyen/Repo/C++/Problems/C12/Ex2.hpp"
#include<ctime>


#include<iostream>

using namespace std;

void displayList(const SortedListInterface<string>* listPtr) {
    for (int i = 0; i < listPtr->getLength(); i++) {
        cout << listPtr->getEntry(i + 1) << " ";
    }

    cout << endl;
}

void listTester(SortedListInterface<string>* listPtr)
{
    cout << "isEmpty: returns " << listPtr->isEmpty()
         << "; should be 1 (true)" << endl;

    string items[] = {"one", "two", "three", "four", "five", "one"};
    cout << "Add 6 items to the list: " << endl;
    for (int i = 0; i < 6; i++) {
        listPtr->insertSorted(items[i]);
    } // end for
    displayList(listPtr);
    cout << endl << endl;

    cout << "isEmpty: returns " << listPtr->isEmpty()
         << "; should be 0 (false)" << endl;
    cout << "getLength returns : " << listPtr->getLength()
         << "; should be 6" << endl;
    cout << "Try to add another entry: add(\"ten\")" << endl;
    listPtr->insertSorted("ten");
    displayList(listPtr);

    cout << endl << endl;

    cout << "getPosition(\"ten\"): returns: " << listPtr->getPosition("ten")
         << "; should be 5." << endl;
    cout << "getPosition(\"six\"): returns: " << listPtr->getPosition("six")
         << "; should be -5";
    cout << endl << endl;

    cout << "removeSorted(\"one\"): returns: " << listPtr->removeSorted("one")
         << "; should be 1 (true)." << endl;
    cout << "removeSorted(\"seven\"): returns: " << listPtr->removeSorted("seven")
         << "; should be 0 (false)." << endl;
    displayList(listPtr);

    cout << endl << endl;

    cout << "Clear the list" << endl;
    listPtr->clear();
}

int main() 
{
    SortedListInterface<string>* listPtr = nullptr;

    char userChoice = 'L';
    
    char arr[] = {'A', 'L', 'Q'};
    ArrayList<char> test(arr, 3);

    cout << "Enter 'A' to test the array-based implementation\n"
         << " or 'L' to test the link-based implementation\n" 
         << " or 'Q' to quit: ";
    cin >> userChoice;

    while (toupper(userChoice) != 'Q' && !test.isEmpty()) {
        if (toupper(userChoice) == 'A') {
            listPtr = new ArraySortedList<string>();
            test.remove(test.getPosition('A'));
            cout << "Testing Array-Based Sorted List:" << endl;
        }
        else if (toupper(userChoice) == 'L') {
            listPtr = new LinkedSortedList<string>();
            test.remove(test.getPosition('L'));
            cout << "Testing Link-Based Sorted List:" << endl;
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

    cout << "All done!";

    return 0;
}