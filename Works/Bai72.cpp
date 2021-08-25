//Tính S(x, n) = -x + (x^2)/2! - (x^3)/3! + ... + (((-1)^n) * (x^n)/n!)
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int i = 1;
    float S = 0;
    int P = 1;

    cout << "Nhap x: ";
    float x;
    cin >> x;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Nhap lai x: ";
        cin >> x;
    }

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
        P *= i;
        S += pow(-1, i) * (pow(x, i) / P);
        i++;
    }

    switch (n)
    {
        case 1:
            cout << "S = -" << x << "\n";
            break;
        case 2:
            cout << "S = -" << x << " + (" << x << "^2)/2! = " << S << "\n";
            break;
        case 3:
            cout << "S = -" << x << " + (" << x << "^2)/2! - (" << x << "^3)/3! = " << S << "\n";
            break;
        case 4:
            cout << "S = -" << x << " + (" << x << "^2)/2! - (" << x << "^3)/3! + (" << x << "^4)/4! = " << S << "\n";
            break;
    }

    if (n > 4)
    {
        if (pow(-1, n) < 0)
        {
            cout << "S = -" << x << " + (" << x << "^2)/2! - (" << x << "^3)/3! + ... - (" << x << "^" << n << ")/" << n << "! = " << S << "\n";
        }
        if (pow(-1 , n) > 0)
        {
            cout << "S = -" << x << " + (" << x << "^2)/2! - (" << x << "^3)/3! + ... + (" << x << "^" << n << ")/" << n << "! = " << S << "\n";
        }
    }

    return 0;
}