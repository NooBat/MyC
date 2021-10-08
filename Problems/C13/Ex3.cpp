#include<string>
#include<iostream>
#include "OurQueue.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/LinkedStack.hpp"

using namespace std;

bool palindromeRecog(const string& entry)
{
    bool isPalindrome = false;

    OurQueue<char> aQueue;
    LinkedStack<char> aStack;

    for (int i = 0; i < (entry.length() + 1) / 2; i++)
    {
        aQueue.enqueue(entry[i]);
    }

    for (int i = (entry.length() + 1) / 2; i < entry.length(); i++)
    {
        aStack.push(entry[i]);
    }

    while (!aQueue.isEmpty() && !aStack.isEmpty())
    {
        char frontQueue = aQueue.peekFront();
        char topStack = aStack.peek();

        if (frontQueue == topStack) isPalindrome = true;
        else 
        {
            isPalindrome = false;
            break;
        }

        aQueue.dequeue();
        aStack.pop();
    }

    return isPalindrome;
}

int main()
{
    string str = "newwen";

    cout << palindromeRecog(str);

    return 0;
}