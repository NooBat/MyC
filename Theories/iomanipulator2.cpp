#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    int n;
    cout << "Enter n (hexadecimal): ";
    cin >> hex >> n;

    cout << "Octal: " << oct << n << endl;
    cout << "Decimal: " << dec << n << endl;

    return 0;
}