#include<iostream>

using namespace std;

class A 
{
public:
    A() 
    {
        cout << 1;
    }

    ~A() {
        cout << 2;
    }
};

class B
{
public:
    B() 
    {
        cout << 3;
    }
    
    ~B()
    {
        cout << 4;
    }
};

class C : public A, B 
{
public:
    C()
    {
        cout << 5;
    }

    ~C()
    {
        cout << 6;
    }
};

int main() {
    C c;
    return 0;
}