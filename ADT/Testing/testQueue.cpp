#include "../Queue/CircularLinkedQueue.hpp"

using namespace std;

void testQueue(CircularLinkedQueue<string>& q)
{
    cout << "isEmpty: returns " << q.isEmpty() << "; should be 1 (true)" << endl;
    cout << endl << endl;

    string arr[] = {"asdf", "asdfbeg", "greg", "asd", "asdf", "asdfev"};

    int n = int(sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < n; i++)
    {
        q.enqueue(arr[i]);
    }
    cout << "isEmpty: returns " << q.isEmpty() << "; should be 0 (false)" << endl;
    cout << endl << endl;

    cout << "peekFront: returns " << q.peekFront() << "; should be \"asdf\"" << endl;
    cout << "dequeue: returns " << q.dequeue() << "; should be 1 (true)" << endl;
    cout << "peekFront: returns " << q.peekFront() << "; should be \"asdfbeg\"" << endl;
    cout << endl << endl;

    while (!q.isEmpty())
    {
        q.dequeue();
    }
    
    cout << "isEmpty: returns " << q.isEmpty() << "; should be 1 (true)" << endl;
    cout << endl << endl;
}

int main()
{
    CircularLinkedQueue<string> q;
    cout << "Testing circular linked chain queue: ";
    testQueue(q);

    cout << "All done!";

    return 0;
}