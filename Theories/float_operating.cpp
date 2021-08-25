#include <iostream>
using namespace std;

int main()
{

    int x = 9;
    int y = 6;

    cout << "int % int = " << x % y << "\n";
    cout << "int / int = " << x / y << "\n";
    cout << "double / int = " << (1.0 * x) / y << "\n";
    cout << "int / double = " << x / (1.0 * y) << "\n";
    cout << "double / double = " << (1.0 * x) / (1.0 * y) << "\n";
    cout << "double / int = " << static_cast<double>(x) / y << "\n";
    cout << "int / double = " << x / static_cast<double>(y) << "\n";
    cout << "double / double = " << static_cast<double>(x) / static_cast<double>(y) << "\n";

    return 0;
}