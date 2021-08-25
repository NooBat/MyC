#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a("69");
    string b("96");
    string c = a + b;
    
    cout << c << endl;

    a += " string";
    cout << a << endl;

    cout << "Enter your name: ";
    string Name;
    getline(cin, Name);
    cout << "\"" << Name << "\"" << " has " << Name.size() << " characters." << endl;
    cout << "\"" << Name << "\"" << " has " << Name.length() << " characters." << endl;

    return 0;
}