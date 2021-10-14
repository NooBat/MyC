#include "OurPriorityQueue.hpp"
#include<iostream>

using namespace std;

void testPriorityQueue(OurPriorityQueue<int>& aQueue)
{
    int arr[] = {3, 1, 0, 43};

    int size = int(sizeof(arr) / sizeof(int));

    for (int i = 0; i < size; i++)
    {
        aQueue.enqueue(arr[i]);
    }

    OurPriorityQueue<int> newQueue(aQueue);

    while (!newQueue.isEmpty())
    {
        cout << newQueue.peekFront() << " ";
        newQueue.dequeue();
    }
    cout << endl << endl;

    cout << "aQueue should not be empty: " << aQueue.isEmpty() << "; should be 0 (false)" << endl;
}

int main()
{
    OurPriorityQueue<int> aQueue;

    cout << "Testing Priority Queue: " << endl;
    cout << "Initial Priority Queue is empty." << endl;
    testPriorityQueue(aQueue);

    cout << "All done";

    return 0;
}