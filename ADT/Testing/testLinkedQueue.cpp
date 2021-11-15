#include "/Users/danielnguyen/Repo/C++/ADT/Queue/LinkedQueue.hpp"
#include "/Users/danielnguyen/Repo/C++/ADT/Queue/SL_PriorityQueue.hpp"
#include<iostream>

using namespace std;

void testQueue(LinkedQueue<string>& q)
{
    cout << "The initial queue is empty" << endl;
    cout << "isEmpty returns: " << q.isEmpty() << "; should be 1(true)" << endl;
    cout << endl << endl;

    string arr[] = {"Adam", "Jake", "Amy", "Alan", "Marianne"};

    int n = int(sizeof(arr) / sizeof(arr[0]));

    cout << "Pushing " << n << " people into the queue" << endl;
    for (int i = 0; i < n; i++)
    {
        q.enqueue(arr[i]);
    }

    cout << "First person in queue is: " << q.peekFront() << "; should be Adam" << endl;
    q.dequeue();
    cout << "Dequeued the first person, the next person is: " << q.peekFront() << "; should be Jake" << endl;
    
}

int main()
{
    LinkedQueue<string> q; 

    cout << "Testing linked implementation of queue" << endl;

    testQueue(q);

    cout << "All done" << endl;

    return 0;
}