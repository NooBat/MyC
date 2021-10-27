#include<bits/stdc++.h>

using namespace std;

static int a = 2;
void foo()
{
    string a = "ag";
    cout << a;
}

int main()
{  
    int a = 10, b;
    b = a++ + ++a;

    cout << b << " " << a++ << " " << a << ++a;
    return 0;
}
