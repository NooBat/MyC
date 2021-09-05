#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include "LinkedBag.h"
#include "ArrayBag.h"
#include "Stack.h"

using namespace std;

bool mergeBags(ArrayBag<string>& newBag, const ArrayBag<string>& bag1, const ArrayBag<string>& bag2) {
    int capacity = bag1.getCurrentSize() + bag2.getCurrentSize();

    vector<string> temp1 = bag1.toVector();
    vector<string> temp2 = bag2.toVector();

    for (int i = 0; i < temp1.size(); i++) {
        newBag.add(temp1[i]);
    }

    for (int i = 0; i < temp2.size(); i++) {
        newBag.add(temp2[i]);
    }

    return true;
}

int sumBag(ArrayBag<int>& bag) {
    int sum = 0;

    vector<int> v;
    bag.toVector();

    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }

    return sum;
}

void displayBag(ArrayBag<string>& bag) {

    cout << "The bag contains " << bag.getCurrentSize() << " items:" << endl;

    vector<string> bagItems;
    bag.toVector();
    int numberOfEntries = (int)bagItems.size(); 
    for (int i = 0; i < numberOfEntries; i++) {
        cout << bagItems[i] << " "; 
    } // end for

    cout << endl << endl;
}       // end displayBag

void bagTester(ArrayBag<string>& bag) {
    cout << "isEmpty: returns " << bag.isEmpty() << "; should be 1 (true)" << endl;
    displayBag(bag);

    string items[] = {"one", "two", "three", "four", "five", "one"}; 
    
    cout << "Add 6 items to the bag: " << endl;
    for (int i = 0; i < 6; i++) {
        bag.add(items[i]); 
    } // end for

    displayBag(bag);

    cout << "isEmpty: returns " << bag.isEmpty() << "; should be 0 (false)" << endl;
    cout << "getCurrentSize: returns " << bag.getCurrentSize() << "; should be 6" << endl;  
    cout << "Try to add another entry: add(\"extra\") returns " << bag.add("extra") << endl;

    cout << endl << endl;

    cout << "Create bag2" << endl;
    ArrayBag<string> bag2;
    cout << "isEmpty: returns " << bag2.isEmpty() << "; should be 1 (true)" << endl;
    cout << endl << endl;

    string items2[] = {"ten", "nine", "eight", "one", "three", "one"};

    cout << "Add 6 items to the bag: " << endl;
    for (int i = 0; i < 6; i++) {
        bag2.add(items2[i]); 
    } // end for

    displayBag(bag2);

    cout << "isEmpty: returns " << bag2.isEmpty() << "; should be 0 (false)" << endl;

    cout << endl << endl;

    ArrayBag<string> newBag = bag.difference(bag2);
    cout << "difference(bag2): returns newBag" << endl;

    displayBag(newBag);

    cout << endl << endl;

    cout << "contains(\"three\"): returns " << bag.contains("three") 
         << "; should be 1 (true)" << endl;
    cout << "contains(\"ten\"): returns " << bag.contains("ten") 
         << "; should be 0 (false)" << endl;  
    cout << "getFrequencyOf(\"one\"): returns " << bag.getFrequencyOf("one") 
         << "; should be 2" << endl;
    cout << "remove(\"one\"): returns " << bag.remove("one")
         << "; should be 1 (true)" << endl;
    cout << "getFrequencyOf(\"one\"): returns " << bag.getFrequencyOf("one") 
         << "; should be 1" << endl;
    cout << "remove(\"one\"): returns " << bag.remove("one")
         << "; should be 1 (true)" << endl;
    cout << "remove(\"one\"): returns " << bag.remove("one")
         << "; should be 0 (false)" << endl;
    cout << endl;

    displayBag(bag);

    cout << "replace(\"two\", \"one\") returns " << bag.replace("two", "one")
         << "; should be 1 (true)" << endl;

    displayBag(bag);

    cout << "After clearing the bag, ";
    bag.clear();

    cout << "isEmpty: returns " << bag.isEmpty()
         << "; should be 1 (true)" << endl;
} // end bagTester

void stackTester(Stack<string>& s1, stack<string>& s2) {
    string items[] = {"one", "two", "three", "four", "five", "six"}; 
    
    cout << "Add 6 items to the bag: " << endl;
    for (int i = 0; i < 6; i++) {
        s1.push(items[i]);
        s2.push(items[i]); 
    } 
    cout << endl << endl;

    cout << "First item of user-defined stack: " << s1.peek() << endl;
    cout << "First item of STL stack: " << s2.top() << endl;
    cout << endl << endl;

    cout << "Pop the user-defined stack: returns " << s1.pop() << endl;
    cout << "Pop the STL stack" << endl;
    s2.pop();
    cout << "First item of user-defined stack: " << s1.peek() << endl;
    cout << "First item of STL stack: " << s2.top() << endl;
    cout << endl << endl;
}

int main() {
    ArrayBag<string> bag;
    Stack<string> stack1;
    stack<string> st;

    cout << "Testing the User-defined stack:" << endl; 
    cout << "The initial stack is empty." << endl; 

    stackTester(stack1, st);

    cout << "All done!" << endl;
    return 0; // end main
    
}