#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    int num1, num2;
    cin >> num1 >> num2;

    cout << "Maximum: ";

    if (num1 > num2)
    {
        cout << num1 << endl;
    }
    else cout << num2 << endl;
 
    return 0;
}