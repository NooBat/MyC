#include "MVDSimulation.hpp"
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

auto comparator2 = [] (const string& a, const string& b)
{
    return a < b;
};

int main()
{
    OurPriorityQueue<string, decltype(comparator2) > newQueue;

    string arr[] = {"jack", "amber", "hansel"};

    for (int i = 0; i < 3; i++)
    {
        newQueue.enqueue(arr[i]);
    }

    while (!newQueue.isEmpty())
    {
        cout << newQueue.peekFront() << " ";
        newQueue.dequeue();
    }

    return 0;
}