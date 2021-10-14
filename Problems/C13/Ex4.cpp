#include<string>
#include<iostream>
#include "OurQueue.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/LinkedStack.hpp"

using namespace std;

bool isCorrect(const string& entry)
{
    bool result = false;
    if ((int)entry.find("$") == -1) result = false;
    else
    {
        OurQueue<char> aQueue;
        LinkedStack<char> aStack;
        int i = 0;

        while (entry[i] != '$')
        {
            aQueue.enqueue(entry[i]);
            i++;
        }

        i++;

        for (; i < entry.length(); i++)
        {
            aStack.push(entry[i]);
        }

        while (!aQueue.isEmpty() && !aStack.isEmpty())
        {
            char queueFront = aQueue.peekFront();
            char stackTop = aStack.peek();

            aQueue.dequeue();
            aStack.pop();

            if (queueFront != stackTop) break;
        }

        if (!aQueue.isEmpty() || !aStack.isEmpty()) result = false;
        else result = true;
    }

    return result;
}

int main()
{
    string str = "caa$aac";

    cout << isCorrect(str);

    return 0;
}