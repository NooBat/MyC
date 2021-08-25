//Tính S = 1 - 1/(1 + 2) + 1/(1 + 2 + 3) + ... + (-1)^(n + 1) * 1/(1 + 2 + 3 + ... + n)
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int i = 1;
    double S = 0;
    int a = 0;

    cout << "Nhap n: ";
    int n;
    cin >> n;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Nhap lai n: "; 
        cin >> n;
    } 
    while (n <= 0)
    {
        cout << "Nhap lai n: ";
        cin >> n;
    }

    while (i <= n)
    {
        a += i;
        S = pow(-1, i + 1) / a;
        i++;   
    }

    switch (n)
    {
        case 1:
            cout << "S = 1\n";
            break;
        case 2:
            cout << "S = 1 - 1/(1 + 2) = " << S << "\n";
            break;
        case 3:
            cout << "S = 1 - 1/(1 + 2) + 1/(1 + 2 + 3) = " << S << "\n";
            break;
        case 4:
            cout << "S = 1 - 1/(1 + 2) + 1/(1 + 2 + 3) - 1/(1 + 2 + 3 + 4) = " << S << "\n";
            break;
    }

    if (n > 4)
    {
        if (pow(-1, n + 1) < 0)
        {
            cout << "S = 1 - 1/(1 + 2) + 1/(1 + 2 + 3) + ... - 1/(1 + 2 + 3 + ... + " << n << ") = " << S << "\n";
        }
        if (pow(-1, n + 1) > 0)
        {
            cout << "S = 1 - 1/(1 + 2) + 1/(1 + 2 + 3) + ... + 1/(1 + 2 + 3 + ... + " << n << ") = " << S << "\n";
        }
    }
    return 0;
}