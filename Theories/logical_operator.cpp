#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "Enter a number: ";
    int value;
    cin >> value;

    if (!value)
        cout << value << " is false." << endl;
    else 
        cout << value << " is true." << endl;
    
    if ((value > 1) && (value < 100))
        cout << value << " is between 1 and 100." << endl;
    else
        cout << value << " is not between 1 and 100." << endl;
    
    if ((value == 1) || (value == 100))
        cout << value << " == 1 or " << value << " == 100." << endl;
    else 
        cout << value << " != 1 or " << value << " != 100." << endl;

    return 0;
}