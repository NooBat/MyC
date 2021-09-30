#include "SLL.hpp"
#include "SLL.cpp"
#include<iostream>
#include<assert.h>
#include<string>

using namespace std;

void display(SLinkedList<int>& list)
{
    vector<int> v = list.toVector();

    cout << "[";

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i != v.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main()
{
    SLinkedList<int> list;  

    for (int i = 0; i < 10; i++)
    {
        list.add(i);
    }
    assert(list.removeItem(9));

    display(list);
}