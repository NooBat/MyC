//Tính S(x, n) = -1 + (x^2)/2! - (x^4)/4! + ... + (((-1)^(n + 1) * (x^2n)/2n!)
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int i = 1;
    float S = -1;
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

    while (i <= n)
    {
        P = P * i * (i + 1);
        S += pow(-1, i + 1) * (pow(x, 2 * i) / P);
        i += 2;
    }

    switch (n)
    {
        case 0:
            cout << "S = -1" << "\n";
            break;
        case 1:
            cout << "S = -1 + (" << x << "^2)/2! = " << S << "\n";
            break;
        case 2:
            cout << "S = -1 + (" << x << "^2)/2! - (" << x << "^4)/4! = " << S << "\n";
            break;
        case 3:
            cout << "S = -1 + (" << x << "^2)/2! - (" << x << "^4)/4! + (" << x << "^6)/6! = " << S << "\n";
            break;
    }

    if (n > 4)
    {
        if (pow(-1, n + 1) < 0)
        {
            cout << "S = -1 + (" << x << "^2)/2! - (" << x << "^4)/4! + ... - (" << x << "^" << 2 * n << ")/" << 2 * n << "! = " << S << "\n";
        }
        if (pow(-1 , n + 1) > 0)
        {
            cout << "S = -1 + (" << x << "^2)/2! - (" << x << "^4)/4! + ... + (" << x << "^" << 2 * n << ")/" << 2 * n << "! = " << S << "\n";
        }
    }

    return 0;
}