#include <iostream>
#include <string>
using namespace std;

int main()
{
    string strString = "Daniel Nguyen";
    cout << strString << endl;
    
    cout << "Enter your full name: ";
    string strName;
    getline(cin, strName);

    cout << "Enter your age: ";
    string strAge;
    getline(cin, strAge);

    cout << "Your name is: " << strName << endl;
    cout << "Your age is: " << strAge << endl;

    cout << "Enter your text: ";
    string strText;
    getline(cin, strText, '_');

    cout << "Your text: " << endl;
    cout << strText << endl;

    return 0;

}