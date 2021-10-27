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
    regex word("[a-z](\\w)+");

    string a = "Abc203_";

    cout << regex_match(a, word);
    return 0;
}
